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
  int x;
  int y;
  int sizex;
  int sizey;
  u_long reg[8] = {0x50,0xa0000000a1180,0x51,0,0x52,0x1c000000280,0x53,2};

  if (dispoffset.x < 0) {
    sizex = dispoffset.x + 640;
    x = -dispoffset.x;
  }
  else
  {
    x = 0;
    sizex = 640;
  }

  if (dispoffset.y < 0) {
    sizey = dispoffset.y + 448;
    y = -dispoffset.y;
  }
  else
  {
    y = 0;
    sizey = 448;
  }

  reg[5] = (long)sizex | (long)sizey << 0x20;
  reg[3] = (long)x | (long)y << 0x10;

  PacketDmaTagCnt(3);
  PacketPackRegsWithTag(3,reg,4);
  PacketPackRegWithTag(3,66,0x8000000064);
  return;
}

void GraphInit(void)
{
  sceDmaEnv env;

  sceDevVif0Reset();
  sceDevVu0Reset();
  sceGsResetPath();
  sceDmaReset(1);
  sceDevGifPutImtMode(0);
  PacketInit();

  sceDmaGetEnv(&env);
  env.notify = 2;
  sceDmaPutEnv(&env);

  sceGsResetGraph(0,1,2,0);
  sceGsSetDefDispEnv(&disp,0,640,448,0,0);
  sceGsSetDefDrawEnv(&draw,0,640,224,0,0);

  BackColor(0);

  PacketBegin();
  PacketDmaTagCnt(0);
  PacketPackRegWithTag(0,0x4c,(u_long)draw.frame1);
  PacketPackRegWithTag(0,0x4e,(u_long)draw.zbuf1);
  PacketPackRegWithTag(0,0x18,(u_long)draw.xyoffset1);
  PacketPackRegWithTag(0,0x40,(u_long)draw.scissor1);
  PacketPackRegWithTag(0,0x1a,(u_long)draw.prmodecont);
  PacketPackRegWithTag(0,8,0);
  PacketPackRegWithTag(0,0x46,(u_long)draw.colclamp);
  PacketPackRegWithTag(0,0x45,(u_long)draw.dthe);
  PacketPackRegWithTag(0,0x47,(u_long)draw.test1);
  PacketPackRegWithTag(0,0x42,0x44);
  PacketPackRegWithTag(0,0x49,0);
  PacketPackRegWithTag(0,0x3b,0x8000000000);
  PacketPackRegWithTag(0,0x4a,0);

  PacketSendNow(0);
  GraphBegin();
  GraphEnd();
  
  FlushCache(0);
  sceGsPutDispEnv(&disp);
  frame = 0;
  return;
}

void MakeFullBuffer(void)
{
  u_long *ptr;

  PacketDmaTagCnt(0);
  PacketPackRegWithTag(0,0x4c,0xa008c);
  PacketPackRegWithTag(0,0x40,0x1bf0000027f0000);
  PacketPackRegWithTag(0,0x42,0x80000000a8);
  ptr = PacketGifTag(0,0x4400000000000001,0x5510);
  *ptr = 326;
  ptr[1] = back_color;
  ptr[2] = 0x79006c00;
  ptr[3] = 0x95009400;
  PacketPointerSet(0,ptr+4);
  return;
}

void MakeFrameBuffer(void)
{
  return;
}

void GraphBegin(void)
{
  PacketBegin();
  MakeFullBuffer();
  PacketEnd(1);
  PacketBegin();
  return;
}

void GraphEnd(void)
{
  PacketEnd(1);
  sceGsSyncPath(0,0);
  sceGsSyncV(0);
  PacketBegin();
  GraphConv();
  PacketEnd(1);
  sceGsSyncPath(0,0);
  frame += 1;
  return;
}

void GS_runtime_preset(void)
{
  
}

void GraphSetOffset(int x, int y)
{
  
}
// functions below are unused, possibly arcade leftovers
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
