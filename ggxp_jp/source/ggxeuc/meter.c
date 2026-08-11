// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

#include "meter.h"

// .data
int meter_color[256] = {0};

// .sdata
int meter_index = 0;

void MeterInit(void) {
    REG_RCNT0_MODE = 0x83;          //Clock=HBLANK, TimerEnable=true
    return;
}

void MeterReset(void) {
    meter_color[0] = 0xff0000;
    REG_RCNT0_COUNT = 0;
    meter_index = 0;
    return;
}
