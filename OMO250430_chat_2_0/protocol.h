#ifndef PROTOCOL_H
#define PROTOCOL_H

#pragma once

typedef struct head
{
    int bussinessType;
    int bussinessLength;
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


#endif // PROTOCOL_H
