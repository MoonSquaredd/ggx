#ifndef file
#define file

#include <types.h>

typedef struct {
  int id;
  void *buf;
  u_char *unc_src;
  u_char *unc_dst;
  int unc_size;
} FILE_STR;

extern int seekpos[0][2];
extern FILE_STR FileBuf[10];
extern int FileSelected[7];
extern char *FileSelectedAddr[7];

extern int FileBufPointR;
extern int FileBufPointW;
extern int FileStatus;
extern int comp_enable;
extern int ReadTime;
extern int CdDataTop;

extern void FileReset();
extern void FileInit();
extern void MakeFileTable();
extern int GetFileTop(int fid);
extern int GetFileSize(int fid);
extern void FileRead(int fid, void *adr);
extern void FileReload(int id);
extern char * FileReadMem(int fid);
extern void FileUncompress();
extern void FileReadMain();
extern int FileReadCheck();
extern void FileIRXLoad(char *fname);
extern char * FileReadSelect(int fid, int chan);

#endif
