// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

#include "fade.h"

// .sdata
int FadeOutStatus = 0;

// .sbss
float fadeval;                      //Current frame fade opacity
int fade_bg_id;
int FadeSpeed;
int FadeEndCommand;
int FadeCockpitFlag;
int fade_endflag;

// Executes a fade-out
void FadeoutExecute(void) {
    if (FadeOutStatus != 0) {
        gFadeValSet(fadeval);
        return;
    }
    fadeval = 1.0;
    gFadeValSet(1.0);
    return;
}

// Initialize fade values
void FadeInit(void) {
    FadeEndCommand = 1;
    fadeval = 1.0;
    FadeSpeed = 60;
    fade_bg_id = 0;
    fade_endflag = 1;
    FadeCockpitFlag = 0;
    FadeOutStatus = 0;
    FadeoutExecute();
    return;
}
