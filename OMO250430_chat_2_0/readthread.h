#ifndef READTHREAD_H
#define READTHREAD_H

#include <QObject>
#include <QThread>
#include "protocol.h"
#include <unistd.h>
#include <QDebug>


class ReadThread:public QThread
{
    Q_OBJECT

public:
    static ReadThread *readThread;
    static ReadThread *getInstance();

    void run();
    char *getUserId();
    void setSocketFd(int value);

private:
    ReadThread();
    int socketFd;
    //protocol
    HEAD head;
    LOGINBACK back;
    CHATMSG chatmsg;
    char buf[200];

signals:
    //CHATMSG *chatmsg
    void Send2UI(CHATMSG *chatmsg);
    void Send2SigninWidget(int flag);

};

#endif // READTHREAD_H
