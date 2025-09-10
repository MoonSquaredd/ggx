#ifndef title
#define title

typedef struct {
  char *head;
  int xp;
  int yp;
} WORKTYPE;

extern int IDTransTb[19];

extern int Loop;
extern int Flag;
extern int emess;

extern int Ranking_ScrollOffset;
extern int diagramnum;

extern void DiagramMakeSortTable();
extern void DispDiagram(unsigned char alfa, int x, int y);
extern void RankBGDrawSub();
extern void RankDrawSub(int idno, int x, int y);
extern void RankDraw(int type, int basey);
extern void RankingInit();
extern int RankingScroll();
extern void RankingMain();
extern int vschk(int pos);
extern void select_disp(int pos, WORKTYPE *wt);
extern void chk_kakusicmd(int flg);
extern void TitleInit();
extern void TitleLoad();
extern void TitleClose();
extern int ModeSelect(int type);
extern void SkipTitle();
extern void KariEndInit();
extern void TitleMain();

#endif
