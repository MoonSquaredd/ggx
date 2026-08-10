// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 10/Aug/2026

#include "packet.h"

// .data
DMA_HANDLE dma_f_ = {0};
DMA_HANDLE dma_1_ = {0};
DMA_HANDLE dma_2_ = {0};
DMA_HANDLE dma_e_ = {0};
DMA_HANDLE *handle_list[4] = {0};

// .sdata
DMA_HANDLE *dma_f = &dma_f_;
DMA_HANDLE *dma_1 = &dma_1_;
DMA_HANDLE *dma_2 = &dma_2_;
DMA_HANDLE *dma_e = &dma_e_;

//Initialize DMA handlers
void PacketInit(void) {
    sceDmaChan *dc;

    dc = sceDmaGetChan(DMACGIF);
    dc->chcr = dc->chcr & 0xffffffbf;
    dma_f->dma_chan = dc;
    dma_1->dma_chan = dc;
    dma_2->dma_chan = dc;
    dma_e->dma_chan = dc;
    dma_f->data[0] = malloc(0x20000);
    dma_1->data[0] = malloc(0x10000);
    dma_2->data[0] = malloc(0x80000);
    dma_e->data[0] = malloc(0x10000);
    dma_f->data[1] = malloc(0x20000);
    dma_1->data[1] = malloc(0x10000);
    dma_2->data[1] = malloc(0x80000);
    dma_e->data[1] = malloc(0x10000);
    handle_list[0] = dma_f;
    handle_list[1] = dma_1;
    handle_list[2] = dma_2;
    handle_list[3] = dma_e;
    handle_list[0]->page = 0;
    handle_list[1]->page = 0;
    handle_list[2]->page = 0;
    handle_list[3]->page = 0;
    return;
}

void packetLastCheck(DMA_HANDLE *h) {
    if (h->tagptr != NULL) {
        *h->tagptr = *h->tagptr + (u_long)((int)h->ptr + (-8 - (int)h->tagptr) >> 4);
        h->tagptr = NULL;
    }
    return;
}

u_long * PacketDmaTagCnt(int id) {
    DMA_HANDLE *p;

    p = handle_list[id];
    packetLastCheck(p);
    if (((int)p->ptr & 0xf) != 0) {
        p->ptr += 1;
    }
    *p->ptr = 0x10000000;
    p->ptr[1] = 0;
    p->tagptr = p->ptr;
    p->ptr += 2;
    return p->ptr;
}

u_long * PacketDmaTagEnd(int id, int size) {
    DMA_HANDLE *h;

    h = handle_list[id];
    packetLastCheck(h);
    if (((int)h->ptr & 0xf) != 0) {
        h->ptr += 1;
    }
    if (size > -1) {
        *h->ptr = (u_long)(size >> 4) | 0x70000000;
    } else {
        *h->ptr = (u_long)((size+15) >> 4) | 0x70000000;
    }
    h->ptr += 1;
    *h->ptr = 0;
    h->ptr += 1;
    return h->ptr;
}

u_long * PacketGifTag(int id, u_long tag, u_long taglist) {
    DMA_HANDLE *p;

    p = handle_list[id];
    *p->ptr = tag;
    p->ptr[1] = taglist;
    p->ptr += 2;
    return p->ptr;
}

u_long * PacketPackRegWithTag(int id, u_long reg, u_long data) {
    DMA_HANDLE *p;

    p = handle_list[id];
    *p->ptr = 0x1000000000000001;
    p->ptr[1] = 0xE;
    p->ptr[2] = data;
    p->ptr[3] = reg;
    p->ptr += 4;
    return p->ptr;
}

u_long * PacketPackRegsWithTag(int id, u_long *reglist, int num) {
    DMA_HANDLE *p;

    p = handle_list[id];
    *p->ptr = num | 0x1000000000000000;
    p->ptr[1] = 0xE;
    p->ptr += 2;
    for (int i = 0; i < num; i++) {
        *p->ptr = reglist[1];
        p->ptr[1] = *reglist;
        reglist += 2;
        p->ptr += 2;
    }
    return p->ptr;
}

//Sets the DMA packet pointer
void PacketPointerSet(int id, u_long *ptr) {
    handle_list[id]->ptr = ptr;
    return;
}

//Starts a new DMA packet on all handlers
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

//Sends a DMA packet immediately
void PacketSendNow(int id) {
    DMA_HANDLE *p;

    p = handle_list[p];
    if (p->ptr != p->data[p->page]) {
        PacketDmaTagEnd(id,16);
        PacketGifTag(id,GIFEOP,0);
        sceDmaSync(p->dma_chan,0,0);
        FlushCache(0);
        sceDmaSend(p->dma_chan,p->data[p->page]);
        p->page = p->page^1;
        p->ptr = p->data[p->page];
        p->tagptr = NULL;
    }
    return;
}

//Ends all DMA packets
void PacketEnd(int wait) {
    DMA_HANDLE *p;
    int id;

    for (int id = 0; id < 4; i++) {
        p = handle_list[id];
        if (p->ptr != p->data[p->page]) {
            PacketDmaTagEnd(id,16);
            PacketGifTag(id,GIFEOP,0);
            sceDmaSync(p->dma_chan,0,0);
            FlushCache(0);
            sceDmaSend(p->dma_chan,p->data[p->page]);
            if (wait != 0) {
                sceDmaSync(p->dma_chan,0,0);
            }
            p->page = p->page^1;
            p->ptr = p->data[p->page];
            p->tagptr = NULL;
        }
    }
    return;
}
