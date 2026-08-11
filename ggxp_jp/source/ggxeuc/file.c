// **********************************************************
// *                                                        *
// * Guilty Gear X Plus Decompilation for the PlayStation 2 *
// * SLPM-64525                                             *
// **********************************************************
// Decompilation made by lovenus
// Thanks to all the Guilty Gear modding community <3
//
// Last Revision: 11/Aug/2026

#include "file.h"

void debugf(char*,...);

// .data
int FileSelected[7] = {0};
char *FileSelectedAddr[7] = {0};

// .sdata
int FileBufPointR = 0;              //File read pointer
int FileBufPointW = 0;              //File write pointer
int FileStatus = 0;
int comp_enable = 0;

// Initialize file variables
void FileInit(void) {
    comp_enable = -1;
    FileBufPointR = 0;
    FileBufPointW = 0;
    FileStatus = 0;
    FileSelectedAddr[0] = mmalloc(0x870000,"PLAYER1");
    FileSelectedAddr[1] = mmalloc(0x870000,"PLAYER2");
    FileSelectedAddr[2] = mmalloc(0x282000,"BG");
    FileSelectedAddr[3] = mmalloc( 0xbe000,"VOICE1");
    FileSelectedAddr[4] = mmalloc( 0xbe000,"VOICE2");
    FileSelectedAddr[5] = mmalloc(  0xc800,"SKILLREF1");
    FileSelectedAddr[6] = mmalloc(  0xc800,"SKILLREF2");
    for (int i = 0; i < 7; i++) {
        FileSelected[i] = -1;
        debugf("FileMalloc %x\n",FileSelectedAddr[i]);
    }
    return;
}

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
