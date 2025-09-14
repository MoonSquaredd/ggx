#ifndef sprite
#define sprite

#include <types.h>
#include "g_strip.h"

typedef struct {
  float key;
  u_short index;
  u_short size;
  int id;
} SPR_INDEX;

extern SPR_INDEX spr_index[1200];
extern u_short spr_buf[16000];

extern int spr_count;
extern int spr_ptr;
extern long SpriteAlpha;

extern int nlnDispNum;
extern u_long * wrp;

extern u_int RGBConv(u_int rgb);
extern u_int RGBConvG(u_int rgb);
extern u_int RGBConvOfs(u_int rgb, u_int rgb2);
extern u_int RGBConv2(u_int rgb);
extern int CheckSpriteBuffer(int size);
extern u_long UVConv(float u, float v);
extern u_long UVConvP(float *uv);
extern int XYCheck(float x, float y);
extern void SpriteInit();
extern void sprite_trans_set(SPR_INDEX *p);
extern void SpriteDisplay();
extern void nlDispStripTrnsl(int num, NLVERTEX00 *vt);
extern void nlDispStrip(int num, NLVERTEX00 *vt);
extern void nlcDispStripTrnsl(int num, NLVERTEX00 *vt);
extern void nl1DispStripTrnsl(float z);
extern void nl2DispStripTrnsl(int num, NLVERTEX00 *vt);
extern void nl3DispStripTrnsl();
extern void nlcDispStrip(int num, NLVERTEX00 *vt);
extern void nlcDispFanTrnsl(int num, NLVERTEX00 *vt);
extern void nlcDispFan(int num, NLVERTEX00 *vt);
extern void nlDispStripSetPalette(int d);
extern void nlDispStripTexOfsTrnsl(int num, NLVERTEX03 *vt, int spr);
extern void nlsDispStripTexOfsTrnsl(int num, NLVERTEX03 *vt, int spr);
extern void nlDispStripTexTrnsl(int num, NLVERTEX03 *vt, int spr);
extern void nlsDispStripTexTrnsl(int num, NLVERTEX03 *vt, int spr);
extern void nlDispStripTexTrnslBG(NLVERTEX03 *vt, int spr);
extern void nlsDispStripTexTrnslBG(NLVERTEX03 *vt, int spr);
extern void nlDispStripTexOfs(int num, NLVERTEX03 *vt, int spr);
extern void nlsDispStripTexOfs(int num, NLVERTEX03 *vt, int spr);
extern void nlDispStripTex(int num, NLVERTEX03 *vt, int spr);
extern void nlDispStripTexBG(NLVERTEX03 *vt, int spr);
extern void nlsDispStripTex(int num, NLVERTEX03 *vt, int spr);
extern void nlsDispStripTexBG(NLVERTEX03 *vt, int spr);
extern void nlSprPut(NL_SPR_ARG *spr);
extern void nlsSprPut(NL_SPR_ARG *spr);
extern void SetBlendingMode(short mode);
extern void nlSetPaletteData(int id, u_short *tb, int num);
extern void nlSetBackColor(int c1, int c2, int c3);
extern void nlObjPutSetFadeColor(float r, float g, float b);
extern void nlFreeCommonTextureAll();
extern void nlFreePaletteAll();
extern u_long XYConv(float x, float y);
extern u_long XYConvP(float *p);

#endif
