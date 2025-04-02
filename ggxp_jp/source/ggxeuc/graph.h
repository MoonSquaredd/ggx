// Last Revision: 5/Dec/2025

#ifndef GRAPH
#define GRAPH

#include <types.h>

extern u_long back_color;

void BackColor(u_int);
void GraphConv(void);
void GraphInit(void);
void MakeFullBuffer(void);
void GraphBegin(void);
void GraphEnd(void);
void GS_runtime_preset(void);
void GraphSetOffset(int,int);
void dbg_frame_save(void);
void grp_except_store_image(void *,int,int,int,int,int,int,int);
void dma_notify_channel_set(int);
void dma_chcr_tte_set(int,int);

#endif
