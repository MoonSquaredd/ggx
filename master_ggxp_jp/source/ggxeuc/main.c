#include <stdio.h>
#include <stdarg.h>
#include "types.h"

extern TotalCounter;
extern JSTokorotenFlag;

void debugf(char*,...);
void GraphInit(); // in graph.c
void GS_runtime_preset();
void GraphBegin();
void GraphEnd();
void SpriteInit(); // in sprite.c
void SpriteDisplay();
void JobInit(); // in job.c
void JobMain();
void TextRead(); // in text.c
void TextColor(int);
void TextPutD(u_int,u_int,long,u_int);
void MeterInit(); // in meter.c
void MeterReset();
int MeterColorChange(int);
void PadReadInit(); // in pad.c
void PadReadMain();
void FileIRXLoad(char*); // in file.c
void FileInit();
void FileReadMain();
void FadeInit(); // in fade.c
void FadeExecute();
void soft_reset_check(); // in allinit.c
int CreditExecute(); // in credit.c
int SongContExe(); // in sound.c
void SnDrvMain(); // in soundnew.c
void MemoryInit(); // in memory.c
void heap_alloc(); // in system.c

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
