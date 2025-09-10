#ifndef stgsel
#define stgsel

extern char *StgSelFile;

extern void StgSelLoad();
extern void StgSelFree();
extern void StgSelInit();
extern void DrawBG(int id, int x, int y, float z);
extern void DrawIconSub(int id, int x, int y, int flag);
extern void DrawIcon(int y3);
extern void DispChar_st(float x, float y, float z, float t, char c);
extern void strloop(int fms);
extern void StgSelMain();
extern void StgSelDC();

#endif
