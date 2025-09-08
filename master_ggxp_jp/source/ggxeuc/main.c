#include <stdio.h>
#include <stdarg.h>
#include <types.h>

#include "graph.h"
#include "sprite.h"
#include "job.h"
#include "text.h"
#include "meter.h"
#include "pad.h"
#include "file.h"
#include "fade.h"
#include "allinit.h"
#include "credit.h"
#include "sound.h"
#include "soundnew.h"
#include "memory.h"
#include "system.h"

#include "sifrpc.h"
#include "eecdvd.h"
#include "iopreset.h"
#include "filestub.h"
#include "graphdev.h"

extern TotalCounter;
extern JSTokorotenFlag;

void debugf(char*,...);

int se_max_temp = 0;
int se_req_temp[20] = {0};
int se_num_temp[20][20] = {0};

int main(int argc, char **argv)
{
  se_max_temp = 0;
  for (int i = 0; i < 20; i++) {
    se_req_temp[i] = 0;
    for (int j = 19; j >= 0; j--) {
      se_num_temp[i][j] = 0;
    }
  }
  sceSifInitRpc(0);
  sceCdInit(0);
  sceCdMmode(1);

  debugf("%s\n", "IOPRP250.IMG");
  do; while (!sceSifRebootIop("cdrom0:\\IOPRP250.IMG;1"));
  do; while (!sceSifSyncIop());
  sceSifInitRpc(0);
  sceCdInit(0);
  sceCdMmode(1);
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
  do; while (!sceGsSyncV(0));
  do {
    for (int i = 18; i >= 0; i--) {
      for (int j = 19; j >= 0; j--) {
        se_num_temp[i+1] = se_num_temp[i];
      }
      se_req_temp[i+1] = se_req_temp[i];
    }
    for (int i = 19; i >= 0; i--) {
      se_num_temp[i] = 0;
    }
    GS_runtime_preset();

    MeterReset();

    GraphBegin();
    PadReadMain();
    soft_reset_check();
    SnDrvMain();
    SpriteInit();
    TextColor(0xffffff);





    TextPutD(40,5,(long)JobMode,4);

    MeterColorChange(0xff);
    CreditExecute();

    JobMain();


    SpriteDisplay();

    FadeExecute();

    SongContExe();

    FileReadMain();

    MemoryMain();

    MeterColorChange(0xffffff);

    GraphEnd();

    TotalCounter += 1;
  } while (true);
}

void debugf(char *format, ...)
{
  return;
}

void fdebugf(FILE *stream, char *format, ...)
{
  return;
}
