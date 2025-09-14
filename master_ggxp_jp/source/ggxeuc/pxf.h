#ifndef pxf
#define pxf

#include <types.h>

typedef struct {
  u_long tex;
  int tbw;
  int tw;
  int th;
  int vramsize;
  int palid;
  int paltex;
  u_char *src;
  u_short mode;
  u_short sizex;
  u_short sizey;
  u_short used;
  int vram;
  int wvramsize;
  int vrampage;
} PXF_BUF;

extern int pxf_pal_work[32];
extern u_long PxfVRAM[393126];
extern u_int PxfPaletteBuf[512];
extern u_int PxfPaletteBuf2[512];
extern short vramsorted[1280];
extern char *CurrentPalette;
extern u_long NextPalTex;
extern int VramTop;
extern int PXF_PalID;
extern int VramPage;
extern PXF_BUF pxf_work[1280];

extern void PXF_PalReset();
extern void PXF_Init();
extern u_char * read_clut32(u_char *out, u_char *in, int num);
extern u_char * read_clut16(u_char *out, u_char *in, int num);
extern void read_pix8(u_char *out, u_char *in, int mode, int xy);
extern void PXF_Uncompress(u_char *out, u_char *in);
extern int vram_sort(int num);
extern void PXF_Transfer();
extern u_long PXF_SendTexture(int id);
extern u_long PXF_SetTexture(int id);
extern void PXF_GetSize(int id, int *x, int *y);
extern void PXF_Entry(u_char *src, u_int id, int palid, int paltex);
extern int PXF_SendPalette(u_char *src, int dst);
extern void PXF_WhiteSet();
extern void PXF_Free(int id, int pal);
extern void PXF_PaletteClear();
extern void PXF_SpriteClear();
extern void PXF_SysSpriteClear();
extern int PXF_GetSysSprite();
extern int PXF_GetFreePalette();
extern int PXF_GetFreePaletteNum(int num);
extern int PXF_GetFreePaletteEnd();
extern void SetCurrentPalette(char *src);
extern int IST_Load(int *texadr, int sprid, int palid);
extern void PXF_SetPaletteMain();
extern void PXF_SetPalette(u_short *src, int id, int num);
extern void PXF_SetNextPalette(int dst);

#endif
