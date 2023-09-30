#include "services.h"

pthread_t track_trd = INVALID_THREAD;
pthread_t avoidance_trd = INVALID_THREAD;
pthread_t smg_tem_trd = INVALID_THREAD;
pthread_t smg_distance_trd = INVALID_THREAD;
pthread_t track_avoidance_trd = INVALID_THREAD;

void services_init() {
    distance_init();
    car_init();
    duoji_init();
    track_init();
    smg_init();
}

void run() {
    while (TRUE) {
        handle_request(getRequest());
    }
}

void services_cleanup() {
    smg_cleanup();
    go_stop();
    distance_cleanup();
    car_cleanup();
    duoji_cleanup();
    track_cleanup();
}

void handle_request(int request) {
    static char msg[MESSAGE_SIZE];
    memset(msg, 0, sizeof msg);
    int errno;
    switch(request) {
    case REQ_CLOSE_CONNECTION:
        socket_close();
        break;
    case GET_TEM_HUM:
        if (!get_dht11_data(msg)) {
            printf("获取温湿度数据失败！msg:%s\n", msg);
        } else if (sendResponse(RES_TEM_HUM, msg) == -1) {
            printf("发送温湿度数据失败！msg:%s\n", msg);
        }
        break;
    case GET_DISTANCE:
        //distance_init();
        if (!get_distance_data(msg)) {
            printf("获取距离数据失败！msg:%s\n", msg);
        } else if (sendResponse(RES_DISTANCE, msg) == -1) {
            printf("发送距离数据失败！\n");
        }
        //distance_cleanup();
        break;
    case GET_SYSTEM_INFO:
        getSystemInfo(msg);
        if (sendResponse(RES_SYSTEM_INFO, msg) == -1) {
                printf("发送系统信息失败！\n");
        }
        break;

    case REQ_SMG_SHOW_TEM:
        if (smg_tem_trd != INVALID_THREAD) {
            printf("重复创建线程\n");
            break;
        }
        if (pthread_create(&smg_tem_trd, NULL, smg_show_tem, NULL)) {
            printf("显示温度线程创建失败！\n");
            if (sendResponse(RES_ERROR, "显示温度线程创建失败！\n") == -1) {
                printf("发送错误信息失败！\n");
            }
        }
        break;
    case REQ_STOP_SMG_TEM:
        if (smg_tem_trd == INVALID_THREAD) {
            printf("invalid thread\n");
            break;
        }
        errno = pthread_cancel(smg_tem_trd);
        if (pthread_join(smg_tem_trd, NULL) != 0) {
            printf("等待线程失败\n");
            break;
        }

        smg_clean();
        if (errno) {
            printf("显示温度线程停止失败！errno:%d, %s\n", errno, strerror(errno));
            if (sendResponse(RES_ERROR, "显示温度线程停止失败！\n") == -1) {
                printf("发送错误信息失败！\n");
            }
        }
        smg_tem_trd = INVALID_THREAD;
        break;

    case REQ_SMG_SHOW_DISTANCE:
        if (smg_distance_trd != INVALID_THREAD) {
            printf("重复创建线程\n");
            break;
        }
        if (pthread_create(&smg_distance_trd, NULL, smg_show_distance, NULL)) {
            printf("显示距离线程创建失败！\n");
            if (sendResponse(RES_ERROR, "显示距离线程创建失败！\n") == -1) {
                printf("发送错误信息失败！\n");
            }
        }
        break;
    case REQ_STOP_SMG_DISTANCE:
        if (smg_distance_trd == INVALID_THREAD) {
            printf("invalid thread\n");
            break;
        }
        errno = pthread_cancel(smg_distance_trd);
        if (pthread_join(smg_distance_trd, NULL) != 0) {
            printf("等待线程失败\n");
            break;
        }

        smg_clean();
        if (errno) {
            printf("显示距离线程停止失败！errno:%d, %s\n", errno, strerror(errno));
            if (sendResponse(RES_ERROR, "显示距离线程停止失败！\n") == -1) {
                printf("发送错误信息失败！\n");
            }
        }
        smg_distance_trd = INVALID_THREAD;
        break;

    case REQ_UP:
        go_up();
        break;
    case REQ_DOWN:
        go_back();
        break;
    case REQ_LEFT:
        rotate_left();
        break;
    case REQ_RIGHT:
        rotate_right();
        break;
    case REQ_STOP:
        go_stop();
        break;

    case REQ_AUTO_TRACK:
        if (track_trd != INVALID_THREAD) {
            printf("重复创建线程\n");
            break;
        }
        if (pthread_create(&track_trd, NULL, auto_track, NULL)) {
            printf("自动寻迹线程创建失败！\n");
            if (sendResponse(RES_ERROR, "自动寻迹线程创建失败！\n") == -1) {
                printf("发送错误信息失败！\n");
            }
        }
        break;
    case REQ_STOP_TRACK:
        if (track_trd == INVALID_THREAD) {
            printf("invalid thread\n");
            break;
        }
        errno = pthread_cancel(track_trd);
        if (pthread_join(track_trd, NULL) != 0) {
            printf("等待线程失败\n");
            break;
        }
        
        go_stop();
        if (errno) {
            printf("自动寻迹线程停止失败！errno:%d, %s\n", errno, strerror(errno));
            if (sendResponse(RES_ERROR, "自动寻迹线程停止失败！\n") == -1) {
                printf("发送错误信息失败！\n");
            }
        }
        track_trd = INVALID_THREAD;
        break;
    case REQ_AUTO_OBSTACLE_AVOIDANCE:
        if (avoidance_trd != INVALID_THREAD) {
            printf("重复创建线程\n");
            break;
        }
        if (pthread_create(&avoidance_trd, NULL, avoidance_run, NULL)) {
            printf("自动避障线程创建失败！\n");
            if (sendResponse(RES_ERROR, "自动避障线程创建失败！\n") == -1) {
                printf("发送错误信息失败！\n");
            }
        }
        printf("%lu", avoidance_trd);
        break;
    case REQ_STOP_OBSTACLE_AVOIDANCE:
        if (avoidance_trd == INVALID_THREAD) {
            printf("invalid thread: avoidance trd\n");
            break;
        }
        errno = pthread_cancel(avoidance_trd);
        if (pthread_join(avoidance_trd, NULL) != 0) {
            printf("等待线程失败\n");
            break;
        }
        go_stop();

        if (errno) {
            printf("自动避障线程停止失败！errno:%d, %s\n", errno, strerror(errno));
            printf("%lu", avoidance_trd);
            if (sendResponse(RES_ERROR, "自动避障线程停止失败！\n") == -1) {
                printf("自动避障线程停止失败！\n");
            }
        }
        avoidance_trd = INVALID_THREAD;
        break;
    case REQ_AUTO_TRACK_AVOIDANCE:
        if (track_avoidance_trd != INVALID_THREAD) {
            printf("重复创建线程 track_avoidance_trd\n");
            break;
        }
        if (pthread_create(&track_avoidance_trd, NULL, track_avoidance, NULL)) {
            printf("带避障的自动寻迹线程创建失败！\n");
            if (sendResponse(RES_ERROR, "带避障的自动寻迹线程创建失败！\n") == -1) {
                printf("发送错误信息失败！\n");
            }
        }
        break;
    case REQ_STOP_TRACK_AVOIDANCE:
        if (track_avoidance_trd == INVALID_THREAD) {
            printf("invalid thread: track_avoidance_trd\n");
            break;
        }
        cancel_track_avoidance();
        errno = pthread_cancel(track_avoidance_trd);
        if (pthread_join(track_avoidance_trd, NULL) != 0) {
            printf("等待线程失败\n");
            break;
        }
        go_stop();

        if (errno) {
            printf("带避障的自动寻迹线程停止失败！errno:%d, %s\n", errno, strerror(errno));
            printf("%lu", track_avoidance_trd);
            if (sendResponse(RES_ERROR, "带避障的自动寻迹线程停止失败！\n") == -1) {
                printf("带避障的自动寻迹线程停止失败！\n");
            }
        }
        track_avoidance_trd = INVALID_THREAD;
        break;
    }
    

}