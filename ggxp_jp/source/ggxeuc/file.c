// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 10/Aug/2026

#include "file.h"

void debugf(char*,...);

// Loads modules
void FileIRXLoad(char *fname) {
    char buf[60];

    memcpy(buf,"cdrom:\\",9);
    strcat(buf,fname);
    strcat(buf,";1");
    debugf("Module Load %s\n",buf);
    if (sceSifLoadModule(buf,0,0) < 0) {
        debugf("Module Load Error\n");
    }
    return;
}
