#ifndef text
#define text

#include <types.h>

struct text_color {
  int r;
  int g;
  int b;
};

extern u_short font_data[0];

extern void TextRead();
extern void TextOpen(int len);
extern void TextColor(int rgb);
extern void TextPutC(u_int x, u_int y, u_char c);
extern void TextPutS(u_int x, u_int y, u_char *str);
extern void TextPutD(u_int x, u_int y, long data, u_int num);
extern void TextPutX(u_int x, u_int y, u_long data, u_int num);

#endif
