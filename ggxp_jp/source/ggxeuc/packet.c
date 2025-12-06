// Last Revision: 6/Dec/2025

#include <stdlib.h>
#include <types.h>

#include "packet.h"

#include "../sce/includes/libdma.h"

DMA_HANDLE dma_f_ = {0};
DMA_HANDLE dma_1_ = {0};
DMA_HANDLE dma_2_ = {0};
DMA_HANDLE dma_e_ = {0};
DMA_HANDLE *handle_list[4] = {0};

DMA_HANDLE *dma_f = dma_f_;
DMA_HANDLE *dma_1 = dma_1_;
DMA_HANDLE *dma_2 = dma_2_;
DMA_HANDLE *dma_e = dma_e_;

void PacketInit(void) {
    sceDmaChan *dc;

    dc = sceDmaGetChan(2);
    dc->chcr &= 0xffffffbf;

    dma_f->dma_chan = dc;
    dma_f = dma_2;

    dma_1->dma_chan = dc;
    dma_1 = dma_e;

    dma_f->dma_chan = dc;
    dma_1->dma_chan = dc;

    dma_f->data[0] = malloc(0x20000);
    dma_1->data[1] = malloc(0x10000);
    dma_2->data[1] = malloc(0x80000);
    dma_e->data[0] = malloc(0x10000);

    dma_f->data[1] = malloc(0x20000);
    dma_1->data[0] = malloc(0x10000);
    dma_2->data[0] = malloc(0x80000);
    dma_e->data[1] = malloc(0x10000);

    dma_f->page = 0;
    dma_1->page = 0;
    dma_2->page = 0;
    dma_e->page = 0;

    handle_list = {dma_f, dma_1, dma_2, dma_e};
    return;
}

void packetLastCheck(DMA_HANDLE *h) {
    if (h->tagptr != NULL) {
        *h->tagptr += (u_long)((u_int)((int)h->ptr + (-8 - (int)h->tagptr)) >> 4);
        h->tagptr = NULL;    
    }
    return;
}

u_long * PacketDmaTagCnt(int id) {
    DMA_HANDLE *p;

    p = handle_list[id];

    packetLastCheck(p);
    if ((p->ptr & 0xf) != 0) {
        p->ptr++;    
    }
    *p->ptr = 0x10000000;
    p->ptr++;
    *p->ptr = 0;
    p->ptr++;
    p->tagptr = p->ptr;
    return p->ptr;
}

u_long * PacketDmaTagRef(int id, void *adr, int size) { // Unused
    DMA_HANDLE *p;

    p = handle_list[id];

    packetLastCheck(p);
    if ((p->ptr & 0xf) != 0) {
        p->ptr++;    
    }
    if (size < 0) {
        size += 0xf;    
    }
    *p->ptr = (u_long)(size >> 4) | 0x20000000 | (u_long)adr << 0x20;
    p->ptr++;
    *p->ptr = 0;
    p->ptr++;
    return p->ptr;
}

u_long * PacketDmaTagRefs(int id, void *adr, int size) {
    DMA_HANDLE *p;

    p = handle_list[id];

    packetLastCheck(p);
    if ((p->ptr & 0xf) != 0) {
        p->ptr++;    
    }
    if (size < 0) {
        size += 0xf;    
    }
    *p->ptr = (u_long)(size >> 4) | 0x40000000 | (u_long)adr << 0x20;
    p->ptr++;
    *p->ptr = 0;
    p->ptr++;
    return p->ptr;
}

u_long * PacketDmaTagEnd(int id, int size) {
    DMA_HANDLE *p;

    p = handle_list[id];

    packetLastCheck(p);
    if ((p->ptr & 0xf) != 0) {
        p->ptr++;    
    }
    if (size < 0) {
        size += 0xf;    
    }
    *p->ptr = (u_long)(size >> 4) | 0x70000000;
    p->ptr++;
    *p->ptr = 0;
    p->ptr++;
    return p->ptr;
}

u_long * PacketGifTag(int id, u_long tag, u_long taglist) {
    DMA_HANDLE *p;

    p = handle_list[id];

    *p->ptr = tag;
    p->ptr++;
    *p->ptr = taglist;
    p->ptr++;
    return p->ptr;
}

u_long * PacketPackRegWithTag(int id, u_long reg, u_long data) {
    DMA_HANDLE *p;
    
    p = handle_list[id];
    *p->ptr = 0x1000000000000001;
    p->ptr++;
    *p->ptr = 0xe;
    p->ptr++;
    *p->ptr = data;
    p->ptr++;
    *p->ptr = reg;
    p->ptr++;
    return p->ptr;
}

u_long * PacketPackReg(int id, u_long reg, u_long data) {
    DMA_HANDLE *p;

    p = handle_list[id];
    *p->ptr = data;
    p->ptr++;
    *p->ptr = reg;
    p->ptr++;
    return p->ptr;
}

u_long * PacketPackRegsWithTag(int id, u_long *reglist, int num) {
    DMA_HANDLE *p;

    p = handle_list[id];
    *p->ptr = num | 0x100000000000000;
    p->ptr++;
    *p->ptr = 0xe;
    p->ptr++;
    for (int i = num; i != 0; i--) {
        *p->ptr = reglist[1];
        p->ptr++:
        *p->ptr = *reglist;
        p->ptr++;    
        reglist += 2;
    }
    return p->ptr;
}

u_long * PacketCopy(int id, u_long *data, int size) {
    DMA_HANDLE *p;
    
    if (size < 0) {
        size += 7;    
    }
    size >>= 3;
    p = handle_list[id];
    for (int i = size; i != 0; i--) {
        *p->ptr = *data;
        p->ptr++;
        data++;
    }
    return p->ptr;
}

u_long * PacketPointerGet(int id) {
    return handle_list[id]->ptr;
}

void PacketPointerSet(int id, u_long ptr) {
    handle_list[id]->ptr = ptr;
    return;
}

void PacketBegin(void) {
    dma_f->ptr = dma_f->data[dma_f->page];
    dma_1->ptr = dma_1->data[dma_1->page];
    dma_2->ptr = dma_2->data[dma_2->page];
    dma_e->ptr = dma_e->data[dma_e->page];
    dma_f->tagptr = NULL;
    dma_1->tagptr = NULL;
    dma_2->tagptr = NULL;
    dma_e->tagptr = NULL;
    return;
}

void PacketSendIt(u_long *adr) { // Unused
    sceDmaChan *dc;
    
    sceGsSyncPath(0,0);
    dc = sceDmaGetChan(2);
    sceDmaSync(dc,0,0);
    FlushCache(0);
    sceDmaSend(dc,adr);
    sceGsSyncPath(0,0);
    return;
}

void PacketSendNow(int id) {
    DMA_HANDLE *p;

    p = handle_list[id];
    if (p->ptr != p->data[p->page]) {
        PacketDmaTagEnd(id,0x10);
        PacketGifTag(id,0x8000,0);
        sceDmaSync(p->dma_chan,0,0);
        FlushCache(0);
        sceDmaSend(p->dma_chan,p->data[p->page]);
        p->page ^= 1;
        p->tagptr = NULL;
        p->ptr = p->data[p->page];
    }
    return;
}

void PacketEnd(int wait) {
    DMA_HANDLE *p;

    for (int i = 0; i < 3; i++) {
        p = handle_list[i];
        if (p->ptr != p->data[p->page]) {
            PacketDmaTagEnd(i,0x10);
            PacketGifTag(i,0x8000,0);
            sceDmaSync(p->dma_chan,0,0);
            FlushCache(0);
            sceDmaSend(p->dma_chan,p->data[p->page]);
            
            if (wait != 0) {
                sceDmaSync(p->dma_chan,0,0);            
            }
            p->page ^= 1;
            p->tagptr = NULL;
            p->ptr = p->data[p->page];
        }    
    }
    return;
}

void PacketDmaSpr(void *spr) { // Unused
    sceDmaChan *dc;

    dc = sceDmaGetChan(2);
    sceDmaSync(dc,0,0);
    FlushCache(0);
    sceDmaSend(dc,spr | 0x80000000);
    return;
}
