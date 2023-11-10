/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "selfset.h"


void setup_scr_menu(lv_ui *ui){

	//Write codes menu
	ui->menu = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->menu, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_menu_main_main_default
	static lv_style_t style_menu_main_main_default;
	if (style_menu_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menu_main_main_default);
	else
		lv_style_init(&style_menu_main_main_default);
	lv_style_set_bg_color(&style_menu_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_opa(&style_menu_main_main_default, 0);
	lv_obj_add_style(ui->menu, &style_menu_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_cont_1
	ui->menu_cont_1 = lv_obj_create(ui->menu);
	lv_obj_set_pos(ui->menu_cont_1, 0, 0);
	lv_obj_set_size(ui->menu_cont_1, 320, 480);
	lv_obj_set_scrollbar_mode(ui->menu_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_menu_cont_1_main_main_default
	static lv_style_t style_menu_cont_1_main_main_default;
	if (style_menu_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menu_cont_1_main_main_default);
	else
		lv_style_init(&style_menu_cont_1_main_main_default);
	lv_style_set_radius(&style_menu_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_menu_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_menu_cont_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_menu_cont_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_menu_cont_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_menu_cont_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_menu_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_menu_cont_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_menu_cont_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_menu_cont_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_menu_cont_1_main_main_default, 0);
	lv_style_set_border_color(&style_menu_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_menu_cont_1_main_main_default, 2);
	lv_style_set_border_opa(&style_menu_cont_1_main_main_default, 0);
	lv_style_set_pad_left(&style_menu_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_menu_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_menu_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_menu_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->menu_cont_1, &style_menu_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_btn_5
	ui->menu_btn_5 = lv_btn_create(ui->menu_cont_1);
	lv_obj_set_pos(ui->menu_btn_5, 30, 140);
	lv_obj_set_size(ui->menu_btn_5, 100, 100);
	lv_obj_set_scrollbar_mode(ui->menu_btn_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_menu_btn_5_main_main_default
	static lv_style_t style_menu_btn_5_main_main_default;
	if (style_menu_btn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menu_btn_5_main_main_default);
	else
		lv_style_init(&style_menu_btn_5_main_main_default);
	lv_style_set_radius(&style_menu_btn_5_main_main_default, 50);
	lv_style_set_bg_color(&style_menu_btn_5_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_menu_btn_5_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_dir(&style_menu_btn_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_menu_btn_5_main_main_default, 255);
	lv_style_set_shadow_width(&style_menu_btn_5_main_main_default, 0);
	lv_style_set_shadow_color(&style_menu_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_menu_btn_5_main_main_default, 255);
	lv_style_set_shadow_spread(&style_menu_btn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_menu_btn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_menu_btn_5_main_main_default, 0);
	lv_style_set_border_color(&style_menu_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_menu_btn_5_main_main_default, 0);
	lv_style_set_border_opa(&style_menu_btn_5_main_main_default, 255);
	lv_style_set_text_color(&style_menu_btn_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_menu_btn_5_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_menu_btn_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->menu_btn_5, &style_menu_btn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->menu_btn_5_label = lv_label_create(ui->menu_btn_5);
	lv_label_set_text(ui->menu_btn_5_label, "TYPE");
	lv_obj_set_style_pad_all(ui->menu_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->menu_btn_5_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes menu_btn_6
	ui->menu_btn_6 = lv_btn_create(ui->menu_cont_1);
	lv_obj_set_pos(ui->menu_btn_6, 30, 300);
	lv_obj_set_size(ui->menu_btn_6, 100, 100);
	lv_obj_set_scrollbar_mode(ui->menu_btn_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_menu_btn_6_main_main_default
	static lv_style_t style_menu_btn_6_main_main_default;
	if (style_menu_btn_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menu_btn_6_main_main_default);
	else
		lv_style_init(&style_menu_btn_6_main_main_default);
	lv_style_set_radius(&style_menu_btn_6_main_main_default, 50);
	lv_style_set_bg_color(&style_menu_btn_6_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_menu_btn_6_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_dir(&style_menu_btn_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_menu_btn_6_main_main_default, 255);
	lv_style_set_shadow_width(&style_menu_btn_6_main_main_default, 0);
	lv_style_set_shadow_color(&style_menu_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_menu_btn_6_main_main_default, 255);
	lv_style_set_shadow_spread(&style_menu_btn_6_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_menu_btn_6_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_menu_btn_6_main_main_default, 0);
	lv_style_set_border_color(&style_menu_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_menu_btn_6_main_main_default, 0);
	lv_style_set_border_opa(&style_menu_btn_6_main_main_default, 255);
	lv_style_set_text_color(&style_menu_btn_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_menu_btn_6_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_menu_btn_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->menu_btn_6, &style_menu_btn_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->menu_btn_6_label = lv_label_create(ui->menu_btn_6);
	lv_label_set_text(ui->menu_btn_6_label, "OTHERS");
	lv_obj_set_style_pad_all(ui->menu_btn_6, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->menu_btn_6_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes menu_btn_7
	ui->menu_btn_7 = lv_btn_create(ui->menu_cont_1);
	lv_obj_set_pos(ui->menu_btn_7, 190, 300);
	lv_obj_set_size(ui->menu_btn_7, 100, 100);
	lv_obj_set_scrollbar_mode(ui->menu_btn_7, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_menu_btn_7_main_main_default
	static lv_style_t style_menu_btn_7_main_main_default;
	if (style_menu_btn_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menu_btn_7_main_main_default);
	else
		lv_style_init(&style_menu_btn_7_main_main_default);
	lv_style_set_radius(&style_menu_btn_7_main_main_default, 50);
	lv_style_set_bg_color(&style_menu_btn_7_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_menu_btn_7_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_dir(&style_menu_btn_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_menu_btn_7_main_main_default, 255);
	lv_style_set_shadow_width(&style_menu_btn_7_main_main_default, 0);
	lv_style_set_shadow_color(&style_menu_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_menu_btn_7_main_main_default, 255);
	lv_style_set_shadow_spread(&style_menu_btn_7_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_menu_btn_7_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_menu_btn_7_main_main_default, 0);
	lv_style_set_border_color(&style_menu_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_menu_btn_7_main_main_default, 0);
	lv_style_set_border_opa(&style_menu_btn_7_main_main_default, 255);
	lv_style_set_text_color(&style_menu_btn_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_menu_btn_7_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_menu_btn_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->menu_btn_7, &style_menu_btn_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->menu_btn_7_label = lv_label_create(ui->menu_btn_7);
	lv_label_set_text(ui->menu_btn_7_label, "WIFI");
	lv_obj_set_style_pad_all(ui->menu_btn_7, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->menu_btn_7_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes menu_btn_8
	ui->menu_btn_8 = lv_btn_create(ui->menu_cont_1);
	lv_obj_set_pos(ui->menu_btn_8, 190, 140);
	lv_obj_set_size(ui->menu_btn_8, 100, 100);
	lv_obj_set_scrollbar_mode(ui->menu_btn_8, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_menu_btn_8_main_main_default
	static lv_style_t style_menu_btn_8_main_main_default;
	if (style_menu_btn_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menu_btn_8_main_main_default);
	else
		lv_style_init(&style_menu_btn_8_main_main_default);
	lv_style_set_radius(&style_menu_btn_8_main_main_default, 50);
	lv_style_set_bg_color(&style_menu_btn_8_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_menu_btn_8_main_main_default, lv_color_make(0x97, 0xe7, 0xff));
	lv_style_set_bg_grad_dir(&style_menu_btn_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_menu_btn_8_main_main_default, 255);
	lv_style_set_shadow_width(&style_menu_btn_8_main_main_default, 0);
	lv_style_set_shadow_color(&style_menu_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_menu_btn_8_main_main_default, 255);
	lv_style_set_shadow_spread(&style_menu_btn_8_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_menu_btn_8_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_menu_btn_8_main_main_default, 0);
	lv_style_set_border_color(&style_menu_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_menu_btn_8_main_main_default, 0);
	lv_style_set_border_opa(&style_menu_btn_8_main_main_default, 255);
	lv_style_set_text_color(&style_menu_btn_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_menu_btn_8_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_menu_btn_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->menu_btn_8, &style_menu_btn_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->menu_btn_8_label = lv_label_create(ui->menu_btn_8);
	lv_label_set_text(ui->menu_btn_8_label, "SET");
	lv_obj_set_style_pad_all(ui->menu_btn_8, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->menu_btn_8_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes menu_btn_9
	ui->menu_btn_9 = lv_btn_create(ui->menu_cont_1);
	lv_obj_set_pos(ui->menu_btn_9, 259, 423);
	lv_obj_set_size(ui->menu_btn_9, 56, 51);
	lv_obj_set_scrollbar_mode(ui->menu_btn_9, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_menu_btn_9_main_main_default
	static lv_style_t style_menu_btn_9_main_main_default;
	if (style_menu_btn_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menu_btn_9_main_main_default);
	else
		lv_style_init(&style_menu_btn_9_main_main_default);
	lv_style_set_radius(&style_menu_btn_9_main_main_default, 5);
	lv_style_set_bg_color(&style_menu_btn_9_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_menu_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_menu_btn_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_menu_btn_9_main_main_default, 255);
	lv_style_set_shadow_width(&style_menu_btn_9_main_main_default, 0);
	lv_style_set_shadow_color(&style_menu_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_menu_btn_9_main_main_default, 255);
	lv_style_set_shadow_spread(&style_menu_btn_9_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_menu_btn_9_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_menu_btn_9_main_main_default, 0);
	lv_style_set_border_color(&style_menu_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_menu_btn_9_main_main_default, 0);
	lv_style_set_border_opa(&style_menu_btn_9_main_main_default, 255);
	lv_style_set_text_color(&style_menu_btn_9_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_menu_btn_9_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_menu_btn_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->menu_btn_9, &style_menu_btn_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->menu_btn_9_label = lv_label_create(ui->menu_btn_9);
	lv_label_set_text(ui->menu_btn_9_label, "DEL");
	lv_obj_set_style_pad_all(ui->menu_btn_9, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->menu_btn_9_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes menu_label_1
	ui->menu_label_1 = lv_label_create(ui->menu_cont_1);
	lv_obj_set_pos(ui->menu_label_1, 2, 5);
	lv_obj_set_size(ui->menu_label_1, 310, 35);
	lv_obj_set_scrollbar_mode(ui->menu_label_1, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->menu_label_1, "Label");
	lv_label_set_text_fmt(ui->menu_label_1,"M1:%d M2:%d DR:%d ",M1labe,M2labe,DRlabe);
	lv_label_set_long_mode(ui->menu_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_menu_label_1_main_main_default
	static lv_style_t style_menu_label_1_main_main_default;
	if (style_menu_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menu_label_1_main_main_default);
	else
		lv_style_init(&style_menu_label_1_main_main_default);
	lv_style_set_radius(&style_menu_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_menu_label_1_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_bg_grad_color(&style_menu_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_menu_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_menu_label_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_menu_label_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_menu_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_menu_label_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_menu_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_menu_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_menu_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_menu_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_menu_label_1_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_menu_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_menu_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_menu_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_menu_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_menu_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_menu_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_menu_label_1_main_main_default, 0);
	lv_obj_add_style(ui->menu_label_1, &style_menu_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_menu(ui);
}