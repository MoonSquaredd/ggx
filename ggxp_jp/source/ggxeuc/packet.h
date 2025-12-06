// Last Revision: 6/Dec/2025

#ifndef PACKET
#define PACKET

#include <types.h>

#include "../sce/includes/libdma.h"

typedef struct {
    u_long *data[2];
    u_long *ptr;
    u_long *tagptr;
    u_int page;
    sceDmaChan *dma_chan;
    u_int dummy;
} DMA_HANDLE;

void PacketInit(void);
void packetLastCheck(DMA_HANDLE*);
u_long * PacketDmaTagCnt(int);
u_long * PacketDmaTagRef(int,void*,int);
u_long * PacketDmaTagRefs(int,void*,int);
u_long * PacketDmaTagEnd(int, int);
u_long * PacketGifTag(int,u_long,u_long);
u_long * PacketPackRegWithTag(int,u_long,u_long);
u_long * PacketPackReg(int,u_long,u_long);
u_long * PacketPackRegsWithTag(int,u_long*,int);
u_long * PacketCopy(int,u_long*,int);
u_long * PacketPointerGet(int);
void PacketPointerSet(int,u_long);
void PacketBegin(void);
void PacketSendIt(u_long*);
void PacketSendNow(int);
void PacketEnd(int);
void PacketDmaSpr(void*);

#endif
