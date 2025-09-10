#ifndef opening
#define opening

#include <types.h>
#include "sprite.h"

typedef struct {
  int id;
  void *proc;
  float data1;
  int data2;
  void *data3;
  u_short time;
  u_short end;
} FIGHT_CONTROL; //typedef might be done somewhere else

extern void (*bgdrawfunctb[])(int);
extern void (*opfunc[])(int);

extern char *OpeningFile;

extern NL_SPR_ARG *opsp;
extern int opcancelflag;
extern int Seen7mode;
extern int Seen9Flag;
extern FIGHT_CONTROL *seen9;
extern int colno;
extern int backcol;
extern int *OpBgWorkY;
extern int *OpBgWorkX;
extern int *OpBgWork;
extern int xecount;

extern void RegistSpr(int id, int no);
extern int Opening_Seen1(int count);
extern int Opening_Seen2(int fms);
extern void Opening_Seen4(int fms);
extern int Opening_Seen3(int fms);
extern void Opening_Seen7_5(int fms);
extern int Opening_Seen5(int fms);
extern void Opening_Seen7Sub();
extern void Opening_Seen7Anime(int count);
extern void ScrlString();
extern int Opening_Seen7(int count);
extern int Opening_Seen9Sub(int fms);
extern int Opening_Seen9(int count);
extern int Opening_Seen10_00(int count);
extern int Opening_Seen10_01(int count);
extern int Opening_Seen11(int count);
extern int Opening_Seen12(int count);
extern int Opening_Seen13(int count);
extern int Opening_Seen14(int count);
extern int Opening_Seen15(int count);
extern void XEffectExe();
extern int Opening_Seen16(int count);
extern void Opening_Draw();
extern void OpeningInit();
extern int OpeningEnd(int count);
extern void Opening_BlankFunc();
extern int Opening_Wait1(int count);
extern int Opening_Flash(int count);
extern void OpeningMain();
extern void OpeningBgVertInit(int col);
extern void OpeningBgRUInit(int col);
extern void OpeningBgSideDraw(int dir, int fade);
extern void OpeningBgDrawRU(int fade);
extern void OpeningBgDrawLU(int fade);
extern void OpeningBGSideR(int fade);
extern void OpeningBGSideL(int fade);

#endif
