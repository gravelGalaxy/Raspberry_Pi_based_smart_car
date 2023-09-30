#include "raspiserver.h"

void cleanup() {
    tcpserver_close();
    services_cleanup();
    exit(0);
}

int main() {
    if (wiringPiSetupGpio() < 0) {
        perror("初始化失败！");
        exit(1);
    }
    services_init();
    signal(SIGINT, cleanup);
    if (tcpserver_init(8888) == 0) {
        printf("服务器出错，将要退出\n");
        cleanup();
        exit(1);
    }
    run();
    return 0;
}