#ifndef job
#define job

extern void(*jobfunc[])();

extern int JobMode;
extern int SubJob;
extern int SubJobCount;

extern void JobInit();
extern void JobNext();
extern void JobChange(int job);
extern void JobMain();

#endif
