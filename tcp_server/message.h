#ifndef MESSAGE_H
#define MESSAGE_H

#define MESSAGE_SIZE 256

typedef enum {
    REQ_CLOSE_CONNECTION = 0,
    GET_TEM_HUM,
    GET_DISTANCE,
    GET_SYSTEM_INFO,
    REQ_SMG_SHOW_TEM,
    REQ_STOP_SMG_TEM,
    REQ_SMG_SHOW_DISTANCE,
    REQ_STOP_SMG_DISTANCE,
    REQ_UP,
    REQ_DOWN,
    REQ_LEFT,
    
    REQ_RIGHT,
    REQ_STOP,
    REQ_AUTO_TRACK,
    REQ_STOP_TRACK,
    REQ_AUTO_OBSTACLE_AVOIDANCE,
    REQ_STOP_OBSTACLE_AVOIDANCE,
    REQ_AUTO_TRACK_AVOIDANCE,
    REQ_STOP_TRACK_AVOIDANCE
} request_type;

typedef enum {
    RES_TEM_HUM = 1,
    RES_DISTANCE,
    RES_SYSTEM_INFO,
    RES_ERROR
} response_type;

struct msg_response {
    int msg_type;
    char msg[MESSAGE_SIZE - 5];
};

#endif //MESSAGE_H