#ifndef memacc
#define memacc

extern int AutoSaveMode;
extern int AutoSaveCursor;
extern int AutoSaveFormat;
extern int AutoLoadMode;
extern int AutoLoadCursor;

extern int type_buf;

extern void slot_display(int slot);
extern void slot_display_ex(int slot, char *str, int size);
extern void vm_error(int no, int flg, int slot);
extern int save_err_mes(char *str);
extern int save_format_mes(char *str);
extern int save_err_mes_ex(char *str);
extern int load_err_mes_ex(char *str);
extern int MemAccess_AutoSave(int mode);
extern void AutoSaveInit();
extern void AutoSaveMain();
extern void AutoLoadInit();
extern int load_err_mes(char *str);
extern int AutoLoadMain();
extern int vm_get_freeblock(int port);

#endif
