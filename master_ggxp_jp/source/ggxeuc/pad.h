#ifndef pad
#define pad

#include <types.h>

typedef struct {
  u_short small;
  u_short large;
} PAD_ACT;

typedef struct {
  int data;
  int trg;
  int offtrg;
  int repeat;
  int count;
  int old;
  int oldtrg;
  u_char r3h;
  u_char r3v;
  u_char l3h;
  u_char l3v;
} PAD;

extern PAD_ACT pad_actuator[2];
extern PAD pads[2];
extern PAD pad;
extern u_short pad_read_buf[2][16];

extern void PadReadInit();
extern void PadReadMain();
extern void PadInitActuator(int pad);
extern void PadSetActuator(int pad, int sel, int time);

#endif
