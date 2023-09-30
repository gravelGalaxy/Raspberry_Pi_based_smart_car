#include "tcpserver.h"

int sockfd = INVALID_SOCKET;
int listenfd;

/**
* 监听listenfd
*/
int tcpserver_init(int port) {
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    if (listenfd < 0) {
        printf("socket error\n");
        return 0;
    }

    struct sockaddr_in svraddr;
    svraddr.sin_family = AF_INET;
    svraddr.sin_port = htons(port);
    svraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listenfd, (struct sockaddr*)&svraddr, sizeof(struct sockaddr)) < 0) {
        printf("bind error!\n");
        return 0;
    }

    if (listen(listenfd, 20) < 0) {
        printf("listen error\n");
        return 0;
    }

    return 1;
}

void socket_close() {
    if(sockfd != INVALID_SOCKET) {
        close(sockfd);
        sockfd = INVALID_SOCKET;
        printf("连接已关闭。\n");
    } else {
        printf("客户端连接已失效。");
    }
}

void tcpserver_close() {
    socket_close();
    close(listenfd);
}

/**
* 连接sockfd
*/
int get_connection() {
    struct sockaddr_in cliaddr = {};
    socklen_t cli_len = sizeof(cliaddr);

    sockfd = accept(listenfd, (struct sockaddr*)&cliaddr, &cli_len);
    
    if (sockfd < 0) {
        printf("accept error!\n");
        return -1;
    } else {
        printf("new connection\n");
        return 0;
    }
}

/**
* 获取请求request_type
*/
int getRequest() {
    char buff[128] = {};
    if (sockfd == INVALID_SOCKET) {
        if (get_connection() == -1) {
            printf("连接失败！");
            sleep(1);
            return -1;
        }
    }
    
    int data_size = recv(sockfd, buff, 127, 0);
    if (data_size <= 0) {
        printf("client will unlink\n");
        return REQ_CLOSE_CONNECTION;
    }

    printf("request: %s \n", buff);
    return atoi(buff);
}

/**
* 发送回应msg_response
*/
int sendResponse(int msg_type, char *msg) {
    struct msg_response res;
    res.msg_type = msg_type;
    memcpy(&res.msg, msg, strlen(msg));
    printf("resmsg:%s\n", res.msg);
    char send_buff[MESSAGE_SIZE];
    
    sprintf(send_buff, "%d:%s", res.msg_type, res.msg);
    printf("send_buff: %s\n", send_buff);
    return send(sockfd, send_buff, MESSAGE_SIZE, 0);
}
