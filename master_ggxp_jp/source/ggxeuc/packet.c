#include <string.h>
#include <types.h>

DMA_HANDLE dma_f_ = {0};
DMA_HANDLE dma_1_ = {0};
DMA_HANDLE dma_2_ = {0};
DMA_HANDLE dma_e_ = {0};
DMA_HANDLE *handle_list[4] = {0};

DMA_HANDLE *dma_f = dma_f_;
DMA_HANDLE *dma_1 = dma_1_;
DMA_HANDLE *dma_2 = dma_2_;
DMA_HANDLE *dma_e = dma_e_;

void PacketInit(void)
{
  
}

void packetLastCheck(DMA_HANDLE *h)
{
  
}

u_long * PacketDmaTagCnt(int id)
{
  DMA_HANDLE *p;
}

u_long * PacketDmaTagRef(int id, void *adr, int size)
{
  DMA_HANDLE *p;
}

u_long * PacketDmaTagRefs(int id, void *adr, int size)
{
  DMA_HANDLE *p;
}

u_long * PacketDmaTagEnd(int id, int size)
{
  DMA_HANDLE *p;
}

u_long * PacketGifTag(int id, u_long tag, u_long taglist)
{
  
}

u_long * PacketPackRegWithTag(int id, u_long reg, u_long data)
{
  
}

u_long * PacketPackReg(int id, u_long reg, u_long data)
{
  
}

u_long * PacketPackRegsWithTag(int id, u_long *reglist, int num)
{
  
}

u_long * PacketCopy(int id, u_long *data, int size)
{
  
}

u_long * PacketPointerGet(int id)
{
  return handle_list[id]->ptr;
}

void PacketPointerSet(int id, u_long *ptr)
{
  handle_list[id]->ptr = ptr;
  return;
}

void PacketBegin(void)
{
  
}

void PacketSendIt(u_long *adr)
{
  
}

void PacketSendNow(int id)
{
  
}

void PacketEnd(int wait)
{
  
}

void PacketDmaSpr(void *spr)
{
  
}
