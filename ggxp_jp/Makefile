CC = gcc
CFLAGS = -Iinclude -g

OBJS = 	build/main.o \
       	build/graph.o \
       	build/packet.o \
		build/sprite.o \
		build/job.o \
		build/text.o \
		build/meter.o \
		build/random.o \
		build/pad.o \
		build/sin.o \
		build/file.o \
		build/opening.o \
		build/title.o \
		build/stgsel.o \
		build/vs.o \
		build/survival.o \
		build/memacc.o \
		build/g_strip.o \
		build/pxf.o \
		build/fade.o \
		build/screen.o \
		build/gcl.o \
		build/dcfont.o \
		build/allinit.o \
		build/game.o \
		build/objwork.o \
		build/player.o \
		build/polydraw.o \
		build/credit.o \
		build/score.o \
		build/nameentr.o \
		build/act.o \
		build/gcalc.o \
		build/diagram.o \
		build/fight.o \
		build/vsctrl.o \
		build/g_grasub.o \
		build/mainctrl.o \
		build/bg.o \
		build/bgsub.o \
		build/effect.o \
		build/replay.o \
		build/profile.o \
		build/actchk.o \
		build/actsub.o \
		build/actsub2.o \
		build/guardp.o \
		build/playdat.o \
		build/key.o \
		build/cpu.o \
		build/tension.o \
		build/colli.o \
		build/throw.o \
		build/plcolchk.o \
		build/object.o \
		build/cmn_act.o \
		build/eff_act.o \
		build/poly_eff.o \
		build/cockpit.o \
		build/g_grasys.o \
		build/g_graph.o \
		build/afterimg.o \
		build/chase.o \
		build/sobj_act.o \
		build/training.o \
		build/opt_main.o \
		build/opt_cfg.o \
		build/opt_ajst.o \
		build/opt_rec.o \
		build/opt_vm.o \
		build/opt_snd.o \
		build/opt_pass.o \
		build/ampack.o \
		build/winner.o \
		build/ending.o \
		build/finish.o \
		build/select.o \
		build/cp_obj.o \
		build/cp_act.o \
		build/skillref.o \
		build/an_act.o build/ane_act.o \
		build/ax_act.o build/axe_act.o \
		build/bk_act.o build/bke_act.o \
		build/ch_act.o build/che_act.o \
		build/dz_act.o build/dze_act.o \
		build/fa_act.o build/fae_act.o \
		build/jm_act.o build/jme_act.o \
		build/jy_act.o build/jye_act.o \
		build/ky_act.o build/kye_act.o \
		build/ml_act.o build/mle_act.o \
		build/my_act.o build/mye_act.o \
		build/po_act.o build/poe_act.o \
		build/sl_act.o build/sle_act.o \
		build/ts_act.o build/tse_act.o \
		build/ve_act.o build/vee_act.o \
		build/zt_act.o build/zte_act.o \
		build/kr_act.o build/kre_act.o \
		build/js_act.o build/jse_act.o \
		build/cmn_se.o \
		build/sound.o \
		build/soundnew.o \
		build/memory.o \
		build/nllib.o \
		build/system.o \
		build/vibrate.o \
		build/gallery.o \
		build/boss.o \
		build/story.o
		
#unlikely command
SCE_OBJS = 	build/sce/graphdev.o \
			build/sce/libdma.o \
			build/sce/devvu0.o \
			build/sce/devgif.o \
			build/sce/devvif0.o \
			build/sce/libpad.o \
			build/sce/eecdvd.o \
			build/sce/libmc.o \
			build/sce/klib.o \
			build/sce/glue.o \
			build/sce/cache.o \
			build/sce/thread.o \
			build/sce/tty.o \
			build/sce/kprintf.o \
			build/sce/sifcmd.o \
			build/sce/sifrpc.o \
			build/sce/filestub.o \
			build/sce/eeloadfile.o \
			build/sce/iopreset.o \
			build/sce/diei.o \
			build/sce/initsys.o \
			build/sce/libosd.o \
			build/sce/exit.o \
			build/sce/tlbfunc.o \
			build/sce/tlbtrap.o

LIBS = -lm

SLPM_645.25: $(OBJS) 
	$(CC) $(OBJS) $(SCE_OBJS) -T linker_file.ld $(LIBS) -o $@

build/%.o: source/ggxeuc/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

build/sce%.o: sce/%.c 
	$(CC) -c $< -o $@
