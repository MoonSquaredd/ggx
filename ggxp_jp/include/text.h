// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

// Definitions for text.c

#ifndef GGX_TEXT
#define GGX_TEXT

// SCE includes
#include <graphdev.h>

// GGX includes
#include "packet.h"

typedef struct {
    int size;
    int format;
    int dbp;
    short int w;
    short int h;
    u_long data;
} TEX_HEADER;

void TextRead(void);                //Reads font data into vram

#endif
