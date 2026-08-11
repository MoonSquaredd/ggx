// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

// Definitions for packet.c

#ifndef GGX_PACKET
#define GGX_PACKET

// C includes
#include <stdlib.h>
#include <stddef.h>

// SCE includes
#include <eekernel.h>
#include <libdma.h>

typedef struct {
    u_long *data[2];
    u_long *ptr;
    u_long *tagptr;
    u_int page;
    sceDmaChan *dma_chan;
    u_int dummy;
} DMA_HANDLE;

void PacketInit(void);              //Initialize DMA packet handlers
void packetLastCheck(DMA_HANDLE*);
u_long * PacketDmaTagCnt(int);
u_long * PacketDmaTagEnd(int,int);
u_long * PacketGifTag(int,u_long,u_long);
u_long * PacketPackRegWithTag(int,u_long,u_long);
u_long * PacketPackRegsWithTag(int,u_long*,int);
u_long * PacketCopy(int,u_long*,int); //Copies size bytes from data to a DMA packet in quadwords
void PacketPointerSet(int,u_long*); //Sets the DMA packet pointer
void PacketBegin(void);             //Starts a new DMA packet on all handlers
void PacketSendNow(int);            //Sends a DMA packet immediately
void PacketEnd(int);                //Ends all DMA packets

#endif
