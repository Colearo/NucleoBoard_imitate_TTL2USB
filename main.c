#include "mbed.h"

//------------------------------------
// Hyperterminal configuration
// 38400 bauds, 8-bit data, no parity
//------------------------------------

Serial pc(USBTX, USBRX); // tx, rx
Serial device(PA_11, PA_12);  // tx, rx

int main() {
    device.baud(38400);
    pc.baud(38400);
    while(1) {
        if(pc.readable()) {
            device.putc(pc.getc());
        }
        if(device.readable()) {
            pc.putc(device.getc());
        }
    }
}
