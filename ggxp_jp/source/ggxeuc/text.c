// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 10/Aug/2026

#include "text.h"

//Reads font data into vram
void TextRead(void) {
    int tbw;
    TEX_HEADER *h;
    u_short *p;
    u_long reglist[8];

    PacketBegin();
    p = (u_short *)&font_data;
    PacketDmaTagCnt(3);
    h = (TEX_HEADER *)p;
    while (h->size != 0) {
        tbw = p[6];
        if (tbw <= 0) {
            tbw = h->w + 63;
        }
        tbw >>= 6;
        if (tbw == 0) {
            tbw = 1;
        }
        reglist[0] = GSBITBLTBUF;
        reglist[1] = ((long)*(p+4) + 0x500) << 32 | tbw << 48 | (long)*(p+2) << 56;
        reglist[2] = GSTRXPOS;
        reglist[3] = 0;
        reglist[4] = GSTRXREG;
        reglist[5] = (long)p[6] | (long)p[7] << 32;
        reglist[6] = GSTRXDIR;
        reglist[7] = GSGIF2VRAM;
        PacketPackRegsWithTag(3,reglist,4);
        if (*p >= 0) {
            PacketGifTag(3, (long)((*p-16) >> 4) | 0x800000000008000,0);
        } else {
            PacketGifTag(3, (long)((*p-1) >> 4) | 0x800000000008000,0);
        }
        PacketCopy(3,(u_long *)(p+8),*p);
        p = p + (*(int *)p / 2);
        h = (TEX_HEADER *)p;
    }
    PacketEnd(1);
    return;
}
