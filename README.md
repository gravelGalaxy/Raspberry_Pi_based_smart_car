# 树莓派智能小车(服务器)

##### 燕山大学&职坐标校内生产实习项目

#### 环境依赖

wiringPi

#### 编译

```bash
make
```

#### 运行

```bash
./bin/raspi_server
```

#### 请求类型

对应的客户端应该按照以下指令（枚举）给服务器发送信息

```c++
    REQ_CLOSE_CONNECTION = 0,          //关闭连接
    GET_TEM_HUM,                       //获取温湿度数据
    GET_DISTANCE,                      //获取距离数据
    GET_SYSTEM_INFO,                   //获取树莓派CPU、内存、磁盘信息
    REQ_SMG_SHOW_TEM,                  //将温度显示到数码管上
    REQ_STOP_SMG_TEM,                  //停止将温度显示到数码管
    REQ_SMG_SHOW_DISTANCE,             //将距离显示到数码管上
    REQ_STOP_SMG_DISTANCE,             //停止将距离显示到数码管
    REQ_UP,                            //小车前进
    REQ_DOWN,                          //小车后退
    REQ_LEFT,                          //小车左转
    REQ_RIGHT,                         //小车右转
    REQ_STOP,                          //小车停止
    REQ_AUTO_TRACK,                    //自动寻迹
    REQ_STOP_TRACK,                    //停止寻迹
    REQ_AUTO_OBSTACLE_AVOIDANCE,       //自动避障
    REQ_STOP_OBSTACLE_AVOIDANCE,       //停止自动避障
    REQ_AUTO_TRACK_AVOIDANCE,          //带障碍检测的自动寻迹
    REQ_STOP_TRACK_AVOIDANCE           //停止带障碍检测的自动寻迹
```

