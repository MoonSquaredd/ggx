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

void MeterInit(void) {
    REG_RCNT0_MODE = 0x83;          //Clock=HBLANK, TimerEnable=true
    return;
}
