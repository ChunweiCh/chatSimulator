#include <iostream>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <map>
#include <string.h>
#include "protocol.h"

using namespace std;

map<int, int> onlineUser;
//代码只有一套 多个客户端同用
void* pthread_function1(void* arg)
{
	HEAD head = { 0 };
	USER user = { 0 };
	CHATMSG msg = { 0 };
	LOGINBACK back = { 0 };
	char resBuf[200] = { 0 };

	int fd = *((int*)arg);
	while (1)
	{
		//read(客户端A的fd)
		// 登录请求-> 登录成功,保存进map
		// 如果是聊天的请求-> 通过账号找客户端B的fd
		//通过账号找客户端B的FD
		//write(客户端B的fd)

		ssize_t res = read(fd, resBuf, sizeof(HEAD));
		if (res > 0)
		{
			res = 0;
			memcpy(&head, resBuf, sizeof(HEAD));

			bzero(resBuf, sizeof(resBuf)); //登录业务
			if (head.bussinessType == 1)
			{
				
		/*		while (res < head.bussinessLength)
				{
					res += read(fd, resBuf, head.bussinessLength);
				}*/
				res = read(fd, resBuf, head.bussinessLength);
				memcpy(&user, resBuf, head.bussinessLength);
				cout << "user.name = " << user.name << endl;
				cout << "user.pass = " << user.pass << endl;

					//默认 登录成功	
				onlineUser[user.name] = fd;
				cout << "onlineUser.size = " << onlineUser.size() << endl;

				//返回结果给客户端
				bzero(&head, sizeof(head));
				back.flag = 1;
				sprintf(back.message, "%s", "登录成功");

				head.bussinessType = 2;
				head.bussinessLength = sizeof(LOGINBACK);

				memcpy(resBuf,&head,sizeof(head));
				memcpy(resBuf + sizeof(head), &back, sizeof(back));

				res = write(fd, resBuf, sizeof(head) + sizeof(back));
				cout << "服务器发送登录返回 res = " << res << endl;


			}
				
			else if (head.bussinessType == 3) //聊天业务
			{
				res = read(fd, resBuf, head.bussinessLength);
				memcpy(&msg, resBuf, head.bussinessLength);
				cout << "msg.sendId = " << msg.sendId << endl;
				cout << "msg.recvId = " << msg.recvId<<endl;
				cout << "msg.context = " << msg.content<<endl;

				bzero(&head, sizeof(head));
				bzero(resBuf, sizeof(resBuf));

				head.bussinessType = 4;
				head.bussinessLength = sizeof(msg);

				memcpy(resBuf, &head, sizeof(head));
				memcpy(resBuf + sizeof(head), &msg, sizeof(msg));

				//判断用户是否在线，也就是onlineUser 是否存在这个key
				//如果不在线要先保存聊天记录，等用户上线后再发
				
				//发送给发送者
				res = write(onlineUser[msg.sendId], resBuf, sizeof(head)+sizeof(msg));
				cout << "服务器发送登录返回 res = " << res << endl;
				//发送给接收者
				res = write(onlineUser[msg.recvId], resBuf, sizeof(head) + sizeof(msg));
				cout << "服务器发送登录返回 res = " << res << endl;


			}
		}


		

	}

	return NULL;
}

int main()
{
	int res = 0;
	struct sockaddr_in addr;
	char resBuf[100] = { 0 };
	int len = 0;
	int acceptFd = 0;


	int socketFd = socket(AF_INET, SOCK_STREAM, 0);

	if (socketFd < 0)
	{
		perror("socket error");
	}
	else
	{
		cout << "服务器网络初始化成功 socketFd = " << socketFd << endl;

		//网络协议族(ipv4/ipv6:政府或者军事机构)
		addr.sin_family = AF_INET;
		//网络端口
		addr.sin_port = htons(10001);
		//服务器网络IP地址写服务器自己IP
		//INADDR_ANY由系统默认提供
		addr.sin_addr.s_addr = INADDR_ANY;

		//綁定
		len = sizeof(addr);
		if (bind(socketFd, (struct sockaddr*)(&addr), len) == -1)
		{
			perror("bind error");
			return -1;
		}
		//设置 网络通道可以监听多少个客户端
		//后期会进行优化,客户端的数量额可以继续提高，这里10就不需要管
		if (listen(socketFd, 10) == -1)
		{
			perror("listen error");
			return -1;
		}
		cout << "服务器网络搭建成功" << endl;

		//网络要24小时全开启
		while (1)
		{
			//accept阻塞式函数
			//acceptFd 代表连接成功的客户端
			acceptFd = accept(socketFd, NULL, NULL);

			cout << "有客户端连接访问  accept = " << acceptFd << endl;
			//单独的进程为客户端服务

			pthread_t thread1;
			pthread_create(&thread1, NULL, pthread_function1, &acceptFd);
			/*pid_t pid = fork();
			if (pid == 0)
			{
				while (1)
				{
					res = read(acceptFd, resBuf, sizeof(resBuf));

					cout << "服务器收到 acceptFd = " << acceptFd << " res = " << res << " resBuf = " << resBuf << endl;
				}
			}*/

			//一条线程负责读，一条线程负责写



		}


	}




	return 0;
}

