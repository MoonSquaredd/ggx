// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

#include "memory.h"

void debugf(char*,...);

// .data
MC_WORK mc = {0};

void MemorySlotClear(int slot) {
    mc.slot[slot].type = 0;
    mc.slot[slot].free = 0;
    mc.slot[slot].exist = -1;
    return;
}

void MemoryInit(void) {
    int ret;

    mc.dir[0] = '/';
    mc.dir[1] = 0;
    mc.request = 0;
    mc.mode = 0;
    mc.command 0;
    mc.now_port = 0;
    MemorySlotClear(0);
    MemorySlotClear(1);
    ret = sceMcInit();
    if (ret > -1) {
        return;
    }
    if (ret == -101) {
        debugf("Initialize Failed\n");
        return;
    }
    if (ret == -120) {
        debugf("mcserv.irx Version is Old\n");
        return;
    }
    if (ret == -121) {
        debugf("mcman.irx Version is Old\n");
        return;
    }
    debugf("sceMcInit Error %d\n");
    return;
}
