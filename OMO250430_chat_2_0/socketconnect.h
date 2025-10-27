#ifndef SOCKETCONNECT_H
#define SOCKETCONNECT_H
#include <QObject>
#include <QWidget>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <QTcpSocket>
#include <netinet/in.h>
#include <QDebug>
#include <arpa/inet.h>
class SocketConnect :public QObject
{

public:
    static SocketConnect *sc;
    static SocketConnect *getInstance();

    void CreateConnect();
    void Close();
    int getSocketFd() const;
    void setSocketFd(int value);


private:
    SocketConnect();
    struct sockaddr_in s_addr;
    int socketFd;
    int len;
};

#endif // SOCKETCONNECT_H
