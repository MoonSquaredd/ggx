// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

// Definitions for system.c

#ifndef GGX_SYSTEM
#define GGX_SYSTEM

// C includes
#include <stddef.h>
#include <stdlib.h>

void heap_alloc(void);
void * mmalloc(int,char*);          //malloc wrapper

#endif
