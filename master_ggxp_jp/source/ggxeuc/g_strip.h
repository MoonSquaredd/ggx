#ifndef g_strip
#define g_strip

#include <types.h>

typedef struct {
  float x;
  float y;
  float z;
  u_int col;
} NLVERTEX00;

typedef struct {
  float x;
  float y;
  float z;
  float w;
  float u;
  float v;
  u_int col;
  u_int ofs;
} NLVERTEX03;

typedef struct {
  int sprno;
  float x;
  float y;
  float z;
  float zm_x;
  float zm_y;
  float u0;
  float v0;
  float u1;
  float v1;
  int ang;
  float trnsl;
  short listType;
  short attr;
  int base_color;
  int offset_color;
  int sizex;
  int sizey;
  int unknown;
  long tex;
} NL_SPR_ARG;

typedef struct {
  int sprno;
  float x;
  float y;
  float z;
  float zm_x;
  float zm_y;
  int u0;
  int v0;
  int u1;
  int v1;
  int trnsl;
  int attr;
} G_SPR_ARGXYWH;

extern int gStripDebug;
extern NLVERTEX03 *Vertex03Work;

extern NLVERTEX03 gStripBuffer_BG[4];

extern u_int Gcol;
extern u_int Gcolsv;
extern int OffsetOn;
extern float gfadeval;

extern void g_strip_init();
extern void gStripSetPalTb(char *tb);
extern void gCurrentColorSet(float val);
extern void gCurrentColorSetARGB(u_int argb);
extern void gCurrentColorSetARGBFade(u_int argb, float val);
extern void gCurrentColorClear();
extern void gFadeValSet(float val);
extern void gColPop();
extern void gColPush(u_int color);
extern void gSetObjColorOffset(u_int val);
extern u_int gCurrentColorGet();
extern void DrawStripSubS(int sprno);
extern void DrawStripSub5(int sprno);
extern void gSpriteDraw(NL_SPR_ARG *sprite);
extern void gSpriteDrawUVSph(NL SPR_ARG *sprite);
extern void gSpriteDrawUV(NL_SPR_ARG *sprite);
extern void gSpriteDrawWH(G_SPR_ARGXYWH *sprite);
extern void gSpriteDrawUVAngle(NL_SPR_ARG *sprite, float *core, u_short angle);
extern void gStripDrawTop(float *v, short *sz, int id, int dirflag);
extern void gSpriteDraw_NaomiLibVersion(NL_SPR_ARG *sprite);
extern void gSpriteDrawPS(NL_SPR_ARG *sprite);
extern void gSpriteDraw_Angle(NL_SPR_ARG *sprite, int cx, int cy, int angle);
extern void gWaveStripDraw(NL_SPR_ARG *sprite, int sz);
extern void gStripDraw_BG(NL_SPR_ARG *sprite);
extern void gStripDraw_BGFast(NL_SPR_ARG *sprite);
extern void gStripDraw_BGFastSkipY(NL_SPR_ARG *sprite);
extern void gStripDraw_BGFastSkipY_TRS(NL_SPR_ARG *sprite);
extern void gStripDraw_BGFastSkipY_OPQ(NL_SPR_ARG *sprite);
extern void gStripDraw_BGFastReverse(NL_SPR_ARG *sprite);
extern void gStripDraw_Set_z_transl(float z, float trnsl);
extern void gStripDraw_Init();
extern void gStripSetPalette(int no);
extern u_int gStripGetFadeColor(u_int color);
extern void JY_CradDraw(NL_SPR_ARG *sprite, int acttimer); //intentional typo
extern void StripDebug(int sw);

#endif
