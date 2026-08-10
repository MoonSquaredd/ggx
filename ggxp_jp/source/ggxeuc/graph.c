// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 10/Aug/2026

#include "graph.h"

// .data
sceGsDispEnv disp = {0};
sceGsDrawEnv1 draw = {0};
struct {
    int x = 0;
    int y = 0;
    int sizex = 0;
    int sizey = 0;
} dispoffset;

// .sdata
u_long back_color = 0;              //Framebuffer's background color
int frame = 0;                      //Current rendered frame

//Sets the framebuffer background color
void BackColor(u_int rgb) {
    back_color = (u_long)rgb;
    return;
}

void GraphConv(void) {
    u_long x;
    long y;
    int sizex;
    int sizey;
    u_long reg[8];

    reg[0] = GSBITBLTBUF;
    reg[1] = 0xa0000000a1180;
    reg[2] = GSTRXPOS;
    reg[4] = GSTRXREG;
    reg[6] = GSTRXDIR;
    reg[7] = GSVRAM2VRAM;
    
    if (dispoffset.x < 0) {
        sizex = dispoffset.x + 640;
        x = (u_long)-dispoffset.x;
    } else {
        sizex = 640;
        x = 0;
    }

    if (dispoffset.y < 0) {
        sizey = dispoffset.y + 448;
        y = (long)-dispoffset.y;
    } else {
        sizey = 448;
        y = 0;
    }

    reg[5] = (long)sizex | (long)sizey << 32;
    reg[3] = x | y << 16;
    PacketDmaTagCnt(3);
    PacketPackRegsWithTag(3,reg,4);
    PacketPackRegWithTag(3,GSALPHA_1,0x8000000064);
    return;
}

//Initialize GS/Graphics
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
    PacketPackRegWithTag(0,GSFRAME_1,(u_long)draw.frame1);
    PacketPackRegWithTag(0,GSZBUF_1,(u_long)draw.zbuf1);
    PacketPackRegWithTag(0,GSXYOFFSET_1,(u_long)draw.xyoffset1);
    PacketPackRegWithTag(0,GSSCISSOR_1,(u_long)draw.scissor1);
    PacketPackRegWithTag(0,GSPRMODECONT,(u_long)draw.prmodecont);
    PacketPackRegWithTag(0,GSCLAMP_1,0);
    PacketPackRegWithTag(0,GSCOLCLAMP,(u_long)draw.colclamp);
    PacketPackRegWithTag(0,GSDTHE,(u_long)draw.dthe);
    PacketPackRegWithTag(0,GSTEST_1,(u_long)draw.test1);
    PacketPackRegWithTag(0,GSALPHA_1,0x44);
    PacketPackRegWithTag(0,GSPABE,0);
    PacketPackRegWithTag(0,GSTEXA,0x8000000000);
    PacketPackRegWithTag(0,GSFBA_1,0);
    PacketSendNow(0);
    GraphBegin();
    GraphEnd();
    FlushCache(0);
    sceGsPutDispEnv(&disp);
    frame = 0;
    return;
}

//Creates the framebuffer
void MakeFullBuffer(void) {
    u_long *ptr;

    PacketDmaTagCnt(0);
    PacketPackRegWithTag(0,GSFRAME_1,0xa008c);
    PacketPackRegWithTag(0,GSSCISSOR_1,0x1bf0000027f0000);
    PacketPackRegWithTag(0,GSALPHA_1,0x80000000a8);
    ptr = PacketGifTag(0,0x4400000000000001,0x5510);
    *ptr = 0x146;
    ptr[1] = back_color;
    ptr[2] = 0x79006c00;
    ptr[3] = 0x95009400;
    PacketPointerSet(0,ptr+4);
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
    frame += 1;
    return;
}
