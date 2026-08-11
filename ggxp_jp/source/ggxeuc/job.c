// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

#include "job.h"

// .sdata
int JobMode = 0;

void JobInit(void) {
    JobMode = JOB_ALLINIT_I;
    return;
}
