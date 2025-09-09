#ifndef meter
#define meter

extern int meter_color[256];
extern int meter_time[256];

extern int meter_index;

extern void MeterInit();
extern void MeterReset();
extern int MeterColorChange(int col);
extern void MeterDraw();

#endif
