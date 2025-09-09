#ifndef sin
#define sin

#include <types.h>

extern int SinTable[0xffff];

extern void SinMake();
extern int Sin(u_short r);
extern int Cos(u_short r);
extern float nlSin(u_short r);
extern float G_Sin(u_short r);
extern float nlCos(u_short r);
extern float G_Cos(u_short r);
extern int Sqrt(u_long src);
extern float nlSqrt(float src);
extern int nlArcTan2(int x, int y);

#endif
