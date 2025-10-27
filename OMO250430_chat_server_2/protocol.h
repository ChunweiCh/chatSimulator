#pragma once

//pragma once 就是 ifndef防止重复编译的意思
//protocol是头文件的意思

typedef struct head
{
	int bussinessType;//业务类型
	int bussinessLength;//请求
}HEAD;


typedef struct user
{
	int name;
	char pass[20];
}USER;


typedef struct chatmsg
{
	int sendId;
	int recvId;

	char content[150];

}CHATMSG;

//返回体
typedef struct loginBack
{
	int flag;//登录结果
	char message[20];//信息
}LOGINBACK;


//定长包头+不定长包体
/*
定长包头作用: 是所有业务共同的属性，为了告知给接收数据的那一端

*/






