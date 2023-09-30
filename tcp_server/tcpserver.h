/**
* 建立和关闭tcp连接、发送和接收消息
*/
#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "stdio.h"
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include "message.h"

#define INVALID_SOCKET -1

int tcpserver_init(int port);
int get_connection();
void tcpserver_close();
void socket_close();

int sendResponse(int msg_type, char *msg);
int getRequest();

#endif //TCPSERVER_H