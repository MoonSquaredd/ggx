#ifndef survival
#define survival

#include <types.h>
#include "objwork.h"

typedef struct {
  u_int survival_totaltime;
  u_int survival_exp;
  int survival_nextexp;
  short survival_level;
  u_short boss_flg;
  char boss_cnt;
  char battle;
  char allclear;
  char dummy;
  short fullcolor_on;
  short rejene;
  u_int survival_sectiontime[10];
  short res_level;
  short res_stage;
} SURVIVAL_EXTRA;

typedef struct {
  int ply;
  int win;
  short hitpoint;
  char time_cnt;
  char hoimi;
  char enetb[16];
  int index;
  int oldhp;
  SURVIVAL_EXTRA sv_ext;
} SURVIVAL_INFOMATION;

typedef struct {
  short fwalk_speed;
  short bwalk_speed;
  short fdash_speed;
  short bdash_speed;
  short fjump_speed;
  short bjump_speed;
  short fdash_accel;
  short fdash_resist;
  short sdash_height;
  short sfdash_time;
  short sbdash_time;
  short sfdash_time_noattack;
  short sbdash_tiem_noattack; //intentional typo
  short fwalk_tensionup;
  short fjump_tentionup;
  short fdash_tensionup;
  short sfdash_tensionup;
  short konp;
  short add_damage;
  short throw_damage;
} CHARACTER_ORIGINAL_STATUS;

extern SURVIVAL_INFOMATION sv_info;
extern CHARACTER_ORIGINAL_STATUS sv_status[12];

extern int sv_levelflag;

extern void init_survival(int ply);
extern void end_survival();
extern void sv_hoimi_set();
extern void sv_hoimi();
extern int InitSurvivalBattle();
extern int get_rarecolor(int id);
extern int chk_complete2();
extern void sv_set_newcolor(int id, int color);
extern int chk_select_color(int id, int color);
extern int get_select_color(int id);
extern int sv_ending_chk(int flg);
extern void init_enemytb();
extern int get_maxchara();
extern void chk_survival_stat();
extern void chk_survivallevel();
extern void sv_set_sectiontime();
extern int sv_damage_hosei(CHARACTER_WORK *offset, int damage);
extern int chk_iai();
extern int chk_nikudan();
extern int add_exp_combo(int combo);
extern int add_exp_damage(int damage);
extern void sv_levelup(int lvl);
extern void sv_save_enemystatus(int side);
extern void sv_set_enemy_status(int side);
extern void sv_levelup_info(int sw);
extern void sv_levelup_info2(int num);
extern void SvResultInit();
extern void SvResultMain();
extern void result_disp(int flg);
extern void result_title(int time);
extern void result_player(int time);
extern void result_level(int time);
extern void result_stage(int time);
extern void result_time(int time);
extern void time_convert(char *buf, u_int time, int id);
extern void sv_timehosei();
extern void result_bg_mask();
extern void sv_result_init();
extern void set_clearflg_sv();
extern void sv_save_result();
extern void sv_IntIrqMain();
extern void SvBossInit();

#endif
