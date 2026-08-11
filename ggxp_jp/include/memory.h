// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

// Definitions for memory.c

#ifndef GGX_MEMORY
#define GGX_MEMORY

// SCE includes
#include <libmc.h>

typedef struct {
    char name[24];
    char *data;
    int size;
} MC_FILE;

typedef struct {
    int type;
    int free;
    int exist;
} MC_ONE;

typedef struct {
    int execmode;
    int mode;
    int command;
    int now_port;
    int retry;
    int fd;
    int request;
    int req_port;
    char fname[24];
    char *buf;
    char *out_buf;
    int list;
    MC_FILE file[3];
    int totalsize;
    char dir[24];
    MC_ONE slot[2];
} MC_WORK;

void MemorySlotClear(int);          //Clear memory slot
void MemoryInit(void);              //Initialize memory cards

#endif
