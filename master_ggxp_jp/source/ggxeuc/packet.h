#ifndef packet
#define packet

#include <types.h>
#include "libdma.h"

typedef struct {
  u_long *[2] data;
  u_long * ptr;
  u_long * tagptr;
  u_int page;
  sceDmaChan * dma_chan;
  u_int dummy;
} DMA_HANDLE;

extern DMA_HANDLE dma_f_;
extern DMA_HANDLE dma_1_;
extern DMA_HANDLE dma_2_;
extern DMA_HANDLE dma_3_;
extern DMA_HANDLE *handle_list[4];

extern DMA_HANDLE *dma_f;
extern DMA_HANDLE *dma_1;
extern DMA_HANDLE *dma_2;
extern DMA_HANDLE *dma_3;

extern void PacketInit();
extern void packetLastCheck(DMA_HANDLE *h);
extern u_long * PacketDmaTagCnt(int id);
extern u_long * PacketDmaTagRef(int id, void *adr, int size);
extern u_long * PacketDmaTagRefs(int id, void *adr, int size);
extern u_long * PacketDmaTagEnd(int id, int size);
extern u_long * PacketGifTag(int id, u_long tag, u_long taglist);
extern u_long * PacketPackRegWithTag(int id, u_long reg, u_long data);
extern u_long * PacketPackReg(int id, u_long reg, u_long data);
extern u_long * PacketPackRegsWithTag(int id, u_long *reglist, int num);
extern u_long * PacketCopy(int id, u_long *data, int size);
extern u_long * PacketPointerGet(int id);
extern void PacketPointerSet(int id, u_long *ptr);
extern void PacketBegin();
extern void PacketSendIt(u_long *adr);
extern void PacketSendNow(int id);
extern void PacketEnd(int wait);
extern void PacketDmaSpr(void *spr);

#endif
