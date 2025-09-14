#ifndef fade
#define fade

extern FadeOutStatus;

extern float fadeval;
extern int fade_bg_id;
extern int FadeSpeed;
extern int FadeEndCommand;
extern int FadeCockpitFlag;
extern int fade_endflag;

extern void FadeExecute();
extern void FadeoutExecute();
extern void Rq_Fadein();
extern void Rq_Fadeout();
extern void FadeInit();
extern int IsFadeEnd();
extern int GetFadeFlag();
extern void SetFadeSpeed(int frame);
extern void SetFadeFlag();
extern void SetFadeVal(int val);
extern int GetFadeVal();
extern void SetFadeEndCommand(int val);
extern void SetFadeCockpitFlag(int val);
extern int GetFadeCockpitFlag();

#endif fade
