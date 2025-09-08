#ifndef graph
#define graph

#include <types.h>
#include "graphdev.h"

extern u_long back_color;
extern int frame;

extern sceGsDispEnv disp;
extern sceGsDrawEnv1 draw;

struct dispoffset
{
  int x;
  int y;
  int sizex;
  int sizey;
};

extern void BackColor(u_int rgb);
extern void GraphConv();
extern void GraphInit();
extern void MakeFullBuffer();
extern void MakeFrameBuffer();
extern void GraphBegin();
extern void GraphEnd();
extern void GS_runtime_preset();
extern void GraphSetOffset(int x, int y);
extern void dbg_frame_save();
extern void grp_except_store_image(void *distance_address, int source_format, int source_address, int source_bw, int source_x, int source_y, int source_w, int source_h);
extern void dma_notify_channel_set(int channel);
extern void dma_chcr_tte_set(int channel, int flag);

#endif
