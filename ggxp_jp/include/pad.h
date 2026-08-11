// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

// Definitions for pad.c

#ifndef GGX_PAD
#define GGX_PAD

// SCE includes
#include <libpad.h>

// GGX includes
#include "game.h"

typedef struct {
    u_short small;
    u_short large;
} PAD_ACT;

void PadReadInit(void);             //Initialize gamepads

#endif
