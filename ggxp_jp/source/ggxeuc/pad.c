// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

#include "pad.h"

void debugf(char*,...);

// .data
u_short pad_read_buf[2][16] = {0};

// .sdata
PAD_ACT pad_actuator[2] = {0};

// Initialize gamepads
void PadReadInit() {
    if (scePadInit(0) < 1) {
        debugf("Pad Init Fatal Error");
    }
    scePadPortOpen(0,0,&pad_read_buf[0]);
    scePadPortOpen(1,0,&pad_read_buf[1]);
    Pause = 1;
    pad_actuator[0].small = 0;
    pad_actuator[0].large = 0;
    pad_actuator[1].small = 0;
    pad_actuator[2].large = 0;
    return;
}
