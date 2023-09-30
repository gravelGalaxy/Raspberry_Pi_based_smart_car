#include "../include/tem.h"
const char *ERROR1 = "校验和出错 ";
const char *ERROR2 = "dth11无响应 ";
//复位函数(启动)
void dht11_reset(){
    pinMode(wenshi,OUTPUT);
    delay(10);
    digitalWrite(wenshi,1);
    delayMicroseconds(10);
    digitalWrite(wenshi,0);
    delay(18);
    digitalWrite(wenshi,1);
    delayMicroseconds(30);
    pinMode(wenshi,INPUT);
    delayMicroseconds(50);
}
//读取一个位
char read_bit(){
    while(!dht11_scan());
    delayMicroseconds(40);
    int timeout = 1000;
    if(dht11_scan()){
        while (dht11_scan() && timeout-- > 0);
        if (timeout <= 0) printf("timeout!");
        return 1;
    }else{
        return 0;
    }
}

//读取一个字节
unsigned char read_byte(){
    unsigned char data = 0;
    for (int i = 0;i < 8;i++){
        data <<= 1;
        data |= read_bit();
    }
    return data;
}

//扫描高低电平
int dht11_scan(){
    return digitalRead(wenshi);
}

//读取40位数据
unsigned char dht11_read_data(unsigned char *buff){
    //char i = 0;
    dht11_reset();
    if(!dht11_scan()){
        while(!dht11_scan());
        while(dht11_scan());
        for(int i = 0;i < 5;i++){
            buff[i] = read_byte();
        }

        unsigned char checksum = buff[0] + buff[1] + buff[2] + buff[3];
        for (int i = 0; i < 4; i++) printf("buff[%d] = %d\n", i, buff[i]);
        if(checksum != buff[4]){
            return 0;
        }else{
            return 1;
        }

    }
    return 2;
}

void uCharConvertToString(unsigned char* array, int length, char* result) {
    for (int i = 0; i < length; i++) {
        unsigned int decimal = (unsigned int)array[i]; // 将十六进制数转化为十进制数
        sprintf(result + (i * 2), "%02u", decimal); // 使用%02u将十进制数格式化为两位宽度的字符串
    }
}

bool get_dht11_data(char *res) {
    unsigned char data[DATASIZE] = {};
    switch(dht11_read_data(data)) {
        case 0:
            sprintf(res, "%s", ERROR1);
            return false;
        case 1:
            printf("温度=%d,湿度=%d\n",data[0],data[2]);
            sprintf(res, "%d,%d ", data[0], data[2]);
            return true;
        case 2:
            sprintf(res, "%s", ERROR2);
            return false;
    }
    return false;
}
