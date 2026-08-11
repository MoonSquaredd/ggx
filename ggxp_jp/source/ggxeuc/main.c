// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

// C includes
#include <stdio.h>
#include <stdarg.h>

// SCE includes
#include <eekernel.h>
#include <eeregs.h>
#include <sifdev.h>
#include <libcdvd.h>

// GGX includes
#include "graph.h"
#include "job.h"
#include "text.h"
#include "meter.h"
#include "pad.h"
#include "file.h"
#include "fade.h"
#include "game.h"
#include "js_act.h"
#include "memory.h"
#include "system.h"

#define CDROM
#define REPLACE

#ifdef CDROM
    #define IOPRP "cdrom0:\\"IOP_IMAGE_FILE";1" //IOP_IMAGE_FILE = IOPRP250.IMG
#else
    #define IOPRP "host0:/usr/local/sce/iop/modules/"IOP_IMAGE_file
#endif

void debugf(char*,...);

// .data
int se_req_temp[20] = {0};          //unused?
int se_num_temp[20][20] = {0};      //unused?

// .sdata
int se_max_temp = 0;                //unused?

int main (int argc, char **argv) {

    se_max_temp = 0;
    for (int i = 0; i < 20; i++) {
        se_req_temp[i] = 0;
        for (int j = 19; j >= 0; j--) {
            se_num_temp[i][j] = 0;
        }
    }
    
    #ifdef REPLACE
    #ifdef CDROM
        sceSifInitRpc(0);
        sceCdInit(SCECdINIT);
        sceCdMmode(SCECdCD);
    #else
        sceSifInitRpc(0);
    #endif
        debugf("%s\n",IOP_IMAGE_FILE);
        while (!sceSifRebootIop(IOPRP));
        while (!sceSifSyncIop());
    #endif
    sceSifInitRpc(0);
    #ifdef CDROM
        sceCdInit(SCECdINIT);
        sceCdMmode(SCECdCD);
    #endif
    sceFsReset();
    debugf("CD Init Over\n");
    FileIRXLoad("SIO2MAN.IRX");
    FileIRXLoad("MCMAN.IRX");
    FileIRXLoad("MCSERV.IRX");
    FileIRXLoad("PADMAN.IRX");
    FileIRXLoad("LIBSD.IRX");
    FileIRXLoad("SNDRV.IRX");
    debugf("IRX Init Over\n");
    GraphInit();
    TextRead();
    PadReadInit();
    FileInit();
    FadeInit();
    MemoryInit();
    MeterInit();
    JobInit();
    TotalCounter = 0;
    JSTokorotenFlag = 0;
    heap_alloc();
    debugf("Initialize Over\n");
    while (!sceGsSyncV(0));
    do {
        for (int i = 18; i >= 0; i--) {
            for (int j = 19; j >= 0; j--) {
                se_num_temp[i+1] = se_num_temp[i];
            }
            se_req_temp[i+1] = se_req_temp[i];
        }
        for (int i = 19; i >= 0; i--) {
            se_num_temp[0][i] = 0;
        }
        se_req_temp[0] = 0;
        GS_runtime_preset();
        MeterReset();
        GraphBegin();
        //PadReadMain();
        //soft_reset_check();
        //SnDrvMain();
        //SpriteInit();
        //TextColor(0xffffff);
        //TextPutD(40,5,JobMode,4);
        //MeterColorChange(0xff);
        //CreditExecute();
        //JobMain();
        //SpriteDisplay();
        //FadeExecute();
        //SongContExe();
        //FileReadMain();
        //MemoryMain();
        //MeterColorChange(0xffffff);
        GraphEnd();
        TotalCounter += 1;
    } while (true);
}

void debugf(char *format, ...) {
    #ifdef DEBUG
        va_list args;
        va_start(args,format);
        vprintf(format,args);
        va_end(args);
    #endif
    return;
}

void fdebugf(FILE *stream, char *format) {
    #ifdef DEBUG
        //unrecoverable code
    #endif
    return;
}
