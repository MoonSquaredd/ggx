// Last Revision: 5/Dec/2025

#include <types.h>

#include "graph.h"
#include "packet.h"

#include "../sce/includes/devvif0.h"
#include "../sce/includes/ddevvu0.h"
#include "../sce/includes/graphdev.h"
#include "../sce/includes/libdma.h"
#include "../sce/includes/devgif.h"
#include "../sce/includes/filestub.h"

u_long back_color = 0;
int frame = 0;

sceGsDispEnv disp = {0};
sceGsDrawEnv1 draw = {0};
struct dispoffset = {
    int x = 0;
    int y = 0;
    int sizex = 0;
    int sizey = 0;
};

void BackColor(u_int rgb) {
    back_color = (u_long)rgb;
    return;
}

void GraphConv(void) {
    long y;
    int sizey;
    int sizex;
    u_long x;
    u_long reg[8];

    reg[0] = 0x50;
    reg[1] = 0xa0000000a1180;
    reg[2] = 0x51;
    reg[3] = 0;             // y     | x
    reg[4] = 0x52;
    reg[5] = 0x1c000000280; // sizey | sizex
    reg[6] = 0x53;
    reg[7] = 2;

    if (dispoffset.x < 0) {
        sizex = dispoffset.x + 640;
        x = (u_long)-dispoffset.x;    
    } else {
        x = 0;
        sizex = 640;    
    }
    sizey = 448;
    if (dispoffset.y < 0) {
        sizey = dispoffset.y + 448;
        y = (long)-dispoffset.y;
    } else {
        y = 0;    
    }

    reg[5] = sizex | sizey << 0x20;
    reg[3] = x | y << 0x10;
    
    PacketDmaTagCnt(3);
    PacketPackRegsWithTag(3,reg,4);
    PacketPackRegWithTag(3,0x42,0x8000000064);
    return;
}

void GraphInit(void) {
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
    PacketPackRegWithTag(0,0x8,0);
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

void MakeFullBuffer(void) {
    u_long *ptr;
    
    PacketDmaTagCnt(0);
    PacketPackRegWithTag(0,0x4c,0xa008c);
    PacketPackRegWithTag(0,0x40,0x1bf0000027f0000);
    PacketPackRegWithTag(0,0x42,0x80000000a8);
    
    ptr = PacketGifTag(0,0x4400000000000001,0x5510);

    ptr[0] = 0x146;
    ptr[1] = back_color;
    ptr[2] = 0x79006c00;
    ptr[3] = 0x95009400;

    PacketPointerSet(0,ptr+4);
    return;
}

void MakeFrameBuffer(void) {
    return;
}

void GraphBegin(void) {
    PacketBegin();
    MakeFullBuffer();
    PacketEnd(1);
    PacketBegin();
    return;
}

void GraphEnd(void) {
    PacketEnd(1);
    sceGsSyncPath(0,0);
    sceGsSyncV(0);
    PacketBegin();
    GraphConv();
    PacketEnd(1);
    sceGsSyncPath(0,0);
    frame++;
    return;
}

void GS_runtime_preset(void) {
    REG_GS_PMODE = 0x7f27;
    REG_GS_DISPFB1 = 0x1400;
    REG_GS_DISPFB2 = 0x1400;
    REG_GS_DISPLAY1 = ((disp.display.DX & 0xfff) + 636) | dispoffset.sizey << 0x2c | dispoffset.sizex << 0x20 | 0x1800000 | ((disp.display.DX >> 0xc & 0x7ff) + 0x32) << 0xc;
    REG_GS_DISPLAY2 = ((disp.display.DX & 0xfff) + 636) | dispoffset.sizey << 0x2c | dispoffset.sizex << 0x20 | 0x1800000 | ((disp.display.DX >> 0xc & 0x7ff) + 0x33) << 0xc;
    REG_GS_EXTWRITE = 0;
    return;
}

void GraphSetOffset(int x, int y) {
    if (x < 0){x = -x;}
    if (y < 0){y = -y;}

    dispoffset.sizey = 447 - y;
    dispoffset.x = x;
    dispoffset.sizex = (640 - x) * 4 - 1;
    dispoffset.y = y;
    
    if (x > 0) {
        disp.display.DX = disp.display.DX & 0xfffff000 | (x & 0x3ff) << 2;    
    } else {
        disp.display.DX &= 0xfffff000;    
    }
    if (y > 0) {
        disp.display.DY = disp.display.DY & 0xff800fff | (y & 0x7ff) << 0xc;    
    } else {
        disp.display.DY &= 0xff800fff;    
    }
    return;
}

void dbg_frame_save(void) { //Debug function, not used. Most likely a screenshot button
    char file_name[256];
    
    sceGsSyncPath(0,0);
    sceGsSyncV(0);
    grp_except_store_image((void *)0x3000000,0,0,640,0,0,640,448);
    sprintf(file_name,"host0:test%08d.raw",0);
    FILE *f = sceOpen(file_name,0x202);
    sceWrite(f,0x3000000,0x118000);
    sceClose(f);
    return;
}

void grp_except_store_image(void *distance_address, int source_format, int source_address, int source_bw, int source_x, int source_y, int source_w, int source_h) {
    sceGsStoreImage sp;
    int sa = 0;
    int sbw = 0;
    int sh = 0;
    int i = 0;

    if (source_h > 0) {
        sh = source_h;        
        do { // potential for loop
            if (sh > 64) {
                sh = 64;            
            }
            sbw = source_bw + 63;
            if (source_bw >= 0) {
                sbw = source_bw;            
            }
            sa = source_address + 0xff;
            if (source_address >= 0) {
                sa = source_address;            
            }
            sceGsSetDefStoreImage(&sp,(sa << 8) >> 16,(sbw << 10) >> 16,(short)source_format,(short)source_x,(short)source_y,(short)source_w,(short)sh);
            i += 64;

            source_address = source_bw * 256 + source_address;
            FlushCache(0); //from klib.s equivalent to syscall 0x64
            sceGsExecStoreImage(&sp,distance_address);
            distance_address += (void *)(source_w * 256);
            sh = source_h - i;      
        } while (i < source_h);
    }
    
    dma_notify_channel_set(1);
    dma_chcr_tte_set(1,1);
    return;
}

void dma_notify_channel_set(int channel) {
    sceDmaEnv dma_env;

    sceDmaGetEnv(&dma_env);

    dma_env.notify = (u_short)(1 << (channel & 0x1f));

    sceDmaPutEnv(&dma_env);
    return;
}

void dma_chcr_tte_set(int channel, int flag) {
    u_int *dmac = (u_int *)sceDmaGetChan(channel);
    *dmac = *dmac & 0xffffffbf | (u_int)(flag == 1) << 6;
    return;
}
