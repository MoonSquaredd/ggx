// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

#include "g_strip.h"

// .sbss
unsigned int Gcol;
float gfadeval;

void gCurrentColorSet(float val) {
    int i;
    
    i = (gfadeval * val * 255.0);
    Gcol = i << 16 | i << 8 | i;
    return;
}

void gFadeValSet(float val) {
    gfadeval = val;
    gCurrentColorSet(1.0);
    return;
}
