// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

#include "system.h"

void debugf(char*,...);

// malloc wrapper
void * mmalloc(int size, char *name) {
    void *adr;

    adr = malloc(size);
    if (adr == NULL) {
        debugf("Malloc Size Overflow %s\n",name);
    } else {
        debugf("Malloc Enable(%s) %x-%x\n",name,adr,(int)adr+size);
    }
    return adr;
}
