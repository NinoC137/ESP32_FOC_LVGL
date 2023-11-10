/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *MAIN;
	bool MAIN_del;
	lv_obj_t *MAIN_cont_1;
	lv_obj_t *MAIN_btn_1;
	lv_obj_t *MAIN_btn_1_label;
	lv_obj_t *MAIN_label_1;
	lv_obj_t *menu;
	bool menu_del;
	lv_obj_t *menu_cont_1;
	lv_obj_t *menu_btn_5;
	lv_obj_t *menu_btn_5_label;
	lv_obj_t *menu_btn_6;
	lv_obj_t *menu_btn_6_label;
	lv_obj_t *menu_btn_7;
	lv_obj_t *menu_btn_7_label;
	lv_obj_t *menu_btn_8;
	lv_obj_t *menu_btn_8_label;
	lv_obj_t *menu_btn_9;
	lv_obj_t *menu_btn_9_label;
	lv_obj_t *menu_label_1;
	lv_obj_t *TYPE;
	bool TYPE_del;
	lv_obj_t *TYPE_cont_1;
	lv_obj_t *TYPE_RM1;
	lv_obj_t *TYPE_RM1_label;
	lv_obj_t *TYPE_RDRV;
	lv_obj_t *TYPE_RDRV_label;
	lv_obj_t *TYPE_RM1M2;
	lv_obj_t *TYPE_RM1M2_label;
	lv_obj_t *TYPE_RM2;
	lv_obj_t *TYPE_RM2_label;
	lv_obj_t *TYPE_btn_1;
	lv_obj_t *TYPE_btn_1_label;
	lv_obj_t *TYPE_TM1;
	lv_obj_t *TYPE_btn_2;
	lv_obj_t *TYPE_btn_2_label;
	lv_obj_t *TYPE_label_1;
	lv_obj_t *TYPE_M1TAR;
	lv_obj_t *TYPE_M1IA;
	lv_obj_t *TYPE_M1V;
	lv_obj_t *TYPE_M1POSI;
	lv_obj_t *TYPE_M1TAD;
	lv_obj_t *TYPE_M1ID;
	lv_obj_t *TYPE_M1VD;
	lv_obj_t *TYPE_M1PD;
	lv_obj_t *TYPE_TM2;
	lv_obj_t *TYPE_btn_3;
	lv_obj_t *TYPE_btn_3_label;
	lv_obj_t *TYPE_label_10;
	lv_obj_t *TYPE_label_9;
	lv_obj_t *TYPE_label_8;
	lv_obj_t *TYPE_label_7;
	lv_obj_t *TYPE_label_6;
	lv_obj_t *TYPE_M2TAD;
	lv_obj_t *TYPE_M2ID;
	lv_obj_t *TYPE_M2VD;
	lv_obj_t *TYPE_M2PD;
	lv_obj_t *TYPE_TM1M2;
	lv_obj_t *TYPE_btn_4;
	lv_obj_t *TYPE_btn_4_label;
	lv_obj_t *TYPE_label_19;
	lv_obj_t *TYPE_label_18;
	lv_obj_t *TYPE_label_17;
	lv_obj_t *TYPE_label_16;
	lv_obj_t *TYPE_label_15;
	lv_obj_t *TYPE_label_14;
	lv_obj_t *TYPE_label_13;
	lv_obj_t *TYPE_label_12;
	lv_obj_t *TYPE_label_11;
	lv_obj_t *TYPE_label_20;
	lv_obj_t *TYPE_label_21;
	lv_obj_t *TYPE_label_22;
	lv_obj_t *TYPE_label_23;
	lv_obj_t *TYPE_label_24;
	lv_obj_t *TYPE_label_26;
	lv_obj_t *TYPE_label_27;
	lv_obj_t *TYPE_label_28;
	lv_obj_t *TYPE_label_29;
	lv_obj_t *TYPE_TDRV;
	lv_obj_t *TYPE_btn_5;
	lv_obj_t *TYPE_btn_5_label;
	lv_obj_t *TYPE_TDR;
	lv_obj_t *TYPE_label_37;
	lv_obj_t *TYPE_label_36;
	lv_obj_t *TYPE_label_35;
	lv_obj_t *TYPE_label_34;
	lv_obj_t *TYPE_label_33;
	lv_obj_t *TYPE_label_32;
	lv_obj_t *TYPE_label_31;
	lv_obj_t *TYPE_label_30;
	lv_obj_t *OTHERS;
	bool OTHERS_del;
	lv_obj_t *OTHERS_tabview_1;
	lv_obj_t *OTHERS_tabview_1_MPU;
	lv_obj_t *OTHERS_tabview_1_APR;
	lv_obj_t *OTHERS_tabview_1_MEN;
	lv_obj_t *OTHERS_tabview_1_OTHER;
	lv_obj_t *OTHERS_btn_1;
	lv_obj_t *OTHERS_btn_1_label;
	lv_obj_t *OTHERS_label_1;
	lv_obj_t *SET;
	bool SET_del;
	lv_obj_t *SET_cont_1;
	lv_obj_t *SET_SM1;
	lv_obj_t *SET_SM1_label;
	lv_obj_t *SET_SM2;
	lv_obj_t *SET_SM2_label;
	lv_obj_t *SET_btn_3;
	lv_obj_t *SET_btn_3_label;
	lv_obj_t *SET_label_1;
	lv_obj_t *WIFI;
	bool WIFI_del;
	lv_obj_t *WIFI_btn_1;
	lv_obj_t *WIFI_btn_1_label;
	lv_obj_t *WIFI_label_1;
	lv_obj_t *WIFI_name;
	lv_obj_t *WIFI_label_2;
	lv_obj_t *WIFI_passward;
	lv_obj_t *WIFI_btn_2;
	lv_obj_t *WIFI_btn_2_label;
	lv_obj_t *SEM1;
	bool SEM1_del;
	lv_obj_t *SEM1_cont_2;
	lv_obj_t *SEM1_win_1;
	lv_obj_t *SEM1_cont_1;
	lv_obj_t *SEM1_BTN0;
	lv_obj_t *SEM1_BTN0_label;
	lv_obj_t *SEM1_btn_3;
	lv_obj_t *SEM1_btn_3_label;
	lv_obj_t *SEM1_btn_4;
	lv_obj_t *SEM1_btn_4_label;
	lv_obj_t *SEM1_btn_5;
	lv_obj_t *SEM1_btn_5_label;
	lv_obj_t *SEM1_btn_6;
	lv_obj_t *SEM1_btn_6_label;
	lv_obj_t *SEM1_btn_7;
	lv_obj_t *SEM1_btn_7_label;
	lv_obj_t *SEM1_btn_8;
	lv_obj_t *SEM1_btn_8_label;
	lv_obj_t *SEM1_btn_9;
	lv_obj_t *SEM1_btn_9_label;
	lv_obj_t *SEM1_btn_10;
	lv_obj_t *SEM1_btn_10_label;
	lv_obj_t *SEM1_btn_11;
	lv_obj_t *SEM1_btn_11_label;
	lv_obj_t *SEM1_btn_12;
	lv_obj_t *SEM1_btn_12_label;
	lv_obj_t *SEM1_btn_13;
	lv_obj_t *SEM1_btn_13_label;
	lv_obj_t *SEM1_btn_14;
	lv_obj_t *SEM1_btn_14_label;
	lv_obj_t *SEM1_btn_15;
	lv_obj_t *SEM1_btn_15_label;
	lv_obj_t *SEM1_btn_16;
	lv_obj_t *SEM1_btn_16_label;
	lv_obj_t *SEM1_para;
	lv_obj_t *SEM1_btn_1;
	lv_obj_t *SEM1_btn_1_label;
	lv_obj_t *SEM1_option;
	lv_obj_t *SEM1_motsel;
	lv_obj_t *SEM1_label_1;
	lv_obj_t *SEM1_label_2;
	lv_obj_t *SEM1_btn_17;
	lv_obj_t *SEM1_btn_17_label;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_MAIN(lv_ui *ui);
void setup_scr_menu(lv_ui *ui);
void setup_scr_TYPE(lv_ui *ui);
void setup_scr_OTHERS(lv_ui *ui);
void setup_scr_SET(lv_ui *ui);
void setup_scr_WIFI(lv_ui *ui);
void setup_scr_SEM1(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif