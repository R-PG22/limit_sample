#include <mbed.h>

CAN can(PB_12, PB_13, 1e6);
CANMessage msg;
constexpr can_id = 4;
// BufferedSerial pc(USBTX, USBRX, 115200);

int16_t pwm[4] = {0};

int main(){
    pwm[0] = -10000;
    while(1){
        can.read(msg);
        if(msg.data[0] == 1){
            pwm[0] = 0;
        }

        CANMessage msg(can_id, (const u_int8_t *)pwm, 8);
        can.write(msg);
    }
}