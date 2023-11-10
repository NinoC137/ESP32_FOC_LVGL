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
	lv_obj_t *btn_1;
	bool btn_1_del;
	lv_obj_t *btn_1_img_1;
	lv_obj_t *btn_1_sw_1;
	lv_obj_t *btn_1_speed;
	lv_obj_t *btn_1_data;
	lv_obj_t *btn_1_label_1;
	lv_obj_t *btn_1_label_6;
	lv_obj_t *btn_1_label_7;
	lv_obj_t *btn_1_label_8;
	lv_obj_t *btn_1_label_9;
	lv_obj_t *btn_1_label_10;
	lv_obj_t *btn_1_img_2;
	lv_obj_t *btn_1_img_3;
	lv_obj_t *btn_1_temperate;
	lv_obj_t *btn_1_arc_1;
	lv_obj_t *btn_1_WIFISet;
	lv_obj_t *btn_1_WIFISet_label;
	lv_obj_t *btn_1_label_11;
	lv_obj_t *btn_1_label_12;
	lv_obj_t *btn_1_label_13;
	lv_obj_t *btn_1_label_14;
	lv_obj_t *btn_1_label_15;
	lv_obj_t *btn_1_label_16;
	lv_obj_t *btn_1_label_17;
	lv_obj_t *btn_1_label_19;
	lv_obj_t *btn_1_label_20;
	lv_obj_t *btn_1_label_21;
	lv_obj_t *btn_1_label_22;
	lv_obj_t *btn_1_label_23;
	lv_obj_t *btn_1_label_24;
	lv_obj_t *btn_1_img_4;
	lv_obj_t *screen_1;
	bool screen_1_del;
	lv_obj_t *screen_1_Back;
	lv_obj_t *screen_1_Back_label;
	lv_obj_t *screen_1_WIFIPWD;
	lv_obj_t *screen_1_label_1;
	lv_obj_t *screen_1_label_2;
	lv_obj_t *screen_1_WIFI_Confrim;
	lv_obj_t *screen_1_WIFI_Confrim_label;
	lv_obj_t *screen_1_WIFIID;
	lv_obj_t *screen_1_WIFIState;
	lv_obj_t *screen_1_label_5;
	lv_obj_t *screen_1_ipAddress;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_btn_1(lv_ui *ui);
void setup_scr_screen_1(lv_ui *ui);
LV_IMG_DECLARE(_backgroud_alpha_320x240);
LV_IMG_DECLARE(_button_alpha_100x100);
LV_IMG_DECLARE(_shouye_alpha_320x240);

#ifdef __cplusplus
}
#endif
#endif