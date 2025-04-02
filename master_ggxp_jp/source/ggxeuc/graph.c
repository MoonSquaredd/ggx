#include <stdio.h>
#include "types.h"

void GraphBegin();
void GraphEnd();
void grp_except_store_image(void*,int,int,int,int,int,int,int);
void dma_notify_channel_set(int);
void dma_chcr_tte_set(int,int);
u_long * PacketDmaTagCnt(int); // in packet.c
u_long * PacketPackRegsWithTag(int,u_long*,int);
u_long * PacketPackRegWithTag(int,u_long,u_long);
void PacketInit();
void PacketBegin();
void PacketSendNow(int);
u_long * PacketGifTag(int,u_long,u_long);
void PacketPointerSet(int,u_long*);
void PacketEnd(int);

u_long back_color = 0;
int frame = 0;
sceGsDispEnv disp = {0};
sceGsDrawEnv1 draw = {0};

struct {
  int x;
  int y;
  int sizex;
  int sizey;
} dispoffset;

void BackColor(u_int rgb)
{
  back_color = (u_long)rgb;
  return;
}

void GraphConv(void)
{
  
}

void GraphInit(void)
{
  sceDmaEnv env;
}

void MakeFullBuffer(void)
{
  
}

void MakeFrameBuffer(void)
{
  return;
}

void GraphBegin(void)
{
  
}

void GraphEnd(void)
{
  
}

void GS_runtime_preset(void)
{
  
}

void GraphSetOffset(int x, int y)
{
  
}

void dbg_frame_save(void)
{
  char file_name[256];
}

void grp_except_store_image(void *distance_address, int source_format, int source_address, int source_bw, int source_x, int source_y, int source_w, int source_h)
{
  sceGsStoreImage sp;
}

void dma_notify_channel_set(int channel)
{
  sceDmaEnv dma_env;
}

void dma_chcr_tte_set(int channel, int flag)
{
  
}
