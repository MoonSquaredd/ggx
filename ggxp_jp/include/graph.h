// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

// Definitions for graph.c

#ifndef GGX_GRAPH
#define GGX_GRAPH

// SCE includes
#include <eekernel.h>
#include <graphdev.h>
#include <libdma.h>

// GGX includes
#include "packet.h"

void BackColor(u_int);              //Sets the framebuffer background color
void GraphConv(void);
void GraphInit(void);               //Initialize GS/Graphics
void MakeFullBuffer(void);          //Creates the framebuffer
void GraphBegin(void);              //Prepares the next frame
void GraphEnd(void);                //Renders the next frame
void GS_runtime_preset(void);

#endif
