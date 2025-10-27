#include "socketconnect.h"


//lazy man singleton
SocketConnect * SocketConnect::sc = nullptr;
SocketConnect * SocketConnect::getInstance()
{
    if(SocketConnect::sc == nullptr)
    {
        SocketConnect::sc = new SocketConnect();

    }
    return SocketConnect::sc;
}
//hungry man Singleton
/*
SocketConnect * SocketConnect::sc = new SocketConnect();
SocketConnect * SocketConnect::getInstance()
{

    return SocketConnect::sc;
}

*/


void SocketConnect::CreateConnect()
{
    if(this->socketFd <0)
    {
        qDebug() << "socket error";
        return;
    }
    else
    {
        qDebug() << "client network init sucessful! socketFd = " << socketFd << endl;
        //netWork family
        s_addr.sin_family = AF_INET;
        s_addr.sin_port = htons(10001);
        s_addr.sin_addr.s_addr = inet_addr("192.168.189.128");

        len = sizeof(s_addr);
        if(::connect(socketFd,(struct sockaddr*)&s_addr,len) == -1)
        {
            perror("connect error");
        }

    }
}

void SocketConnect::Close()
{
    if(socketFd == -1)
    {
        perror("socket error");
    }
    else
    {
        close(socketFd);
    }
}

int SocketConnect::getSocketFd() const
{
    return socketFd;
}

void SocketConnect::setSocketFd(int value)
{
    socketFd = value;
}

SocketConnect::SocketConnect()
{
    this->socketFd = socket(AF_INET,SOCK_STREAM,0);
    this->len = 0;

}
