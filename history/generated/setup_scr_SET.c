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


void setup_scr_SET(lv_ui *ui){

	//Write codes SET
	ui->SET = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->SET, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_set_main_main_default
	static lv_style_t style_set_main_main_default;
	if (style_set_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_set_main_main_default);
	else
		lv_style_init(&style_set_main_main_default);
	lv_style_set_bg_color(&style_set_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_set_main_main_default, 0);
	lv_obj_add_style(ui->SET, &style_set_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes SET_cont_1
	ui->SET_cont_1 = lv_obj_create(ui->SET);
	lv_obj_set_pos(ui->SET_cont_1, 0, 0);
	lv_obj_set_size(ui->SET_cont_1, 320, 480);
	lv_obj_set_scrollbar_mode(ui->SET_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_set_cont_1_main_main_default
	static lv_style_t style_set_cont_1_main_main_default;
	if (style_set_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_set_cont_1_main_main_default);
	else
		lv_style_init(&style_set_cont_1_main_main_default);
	lv_style_set_radius(&style_set_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_set_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_set_cont_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_set_cont_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_set_cont_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_set_cont_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_set_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_set_cont_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_set_cont_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_set_cont_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_set_cont_1_main_main_default, 0);
	lv_style_set_border_color(&style_set_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_set_cont_1_main_main_default, 2);
	lv_style_set_border_opa(&style_set_cont_1_main_main_default, 0);
	lv_style_set_pad_left(&style_set_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_set_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_set_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_set_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->SET_cont_1, &style_set_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes SET_SM1
	ui->SET_SM1 = lv_btn_create(ui->SET_cont_1);
	lv_obj_set_pos(ui->SET_SM1, 60, 150);
	lv_obj_set_size(ui->SET_SM1, 120, 120);
	lv_obj_set_scrollbar_mode(ui->SET_SM1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_set_sm1_main_main_default
	static lv_style_t style_set_sm1_main_main_default;
	if (style_set_sm1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_set_sm1_main_main_default);
	else
		lv_style_init(&style_set_sm1_main_main_default);
	lv_style_set_radius(&style_set_sm1_main_main_default, 60);
	lv_style_set_bg_color(&style_set_sm1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_set_sm1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_dir(&style_set_sm1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_set_sm1_main_main_default, 255);
	lv_style_set_shadow_width(&style_set_sm1_main_main_default, 0);
	lv_style_set_shadow_color(&style_set_sm1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_set_sm1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_set_sm1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_set_sm1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_set_sm1_main_main_default, 0);
	lv_style_set_border_color(&style_set_sm1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_set_sm1_main_main_default, 0);
	lv_style_set_border_opa(&style_set_sm1_main_main_default, 255);
	lv_style_set_text_color(&style_set_sm1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_set_sm1_main_main_default, &lv_font_montserratMedium_36);
	lv_style_set_text_align(&style_set_sm1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SET_SM1, &style_set_sm1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SET_SM1_label = lv_label_create(ui->SET_SM1);
	lv_label_set_text(ui->SET_SM1_label, "M1");
	lv_obj_set_style_pad_all(ui->SET_SM1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SET_SM1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SET_SM2
	ui->SET_SM2 = lv_btn_create(ui->SET_cont_1);
	lv_obj_set_pos(ui->SET_SM2, 155, 275);
	lv_obj_set_size(ui->SET_SM2, 80, 80);
	lv_obj_set_scrollbar_mode(ui->SET_SM2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_set_sm2_main_main_default
	static lv_style_t style_set_sm2_main_main_default;
	if (style_set_sm2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_set_sm2_main_main_default);
	else
		lv_style_init(&style_set_sm2_main_main_default);
	lv_style_set_radius(&style_set_sm2_main_main_default, 40);
	lv_style_set_bg_color(&style_set_sm2_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_set_sm2_main_main_default, lv_color_make(0x97, 0xe7, 0xff));
	lv_style_set_bg_grad_dir(&style_set_sm2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_set_sm2_main_main_default, 255);
	lv_style_set_shadow_width(&style_set_sm2_main_main_default, 0);
	lv_style_set_shadow_color(&style_set_sm2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_set_sm2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_set_sm2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_set_sm2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_set_sm2_main_main_default, 0);
	lv_style_set_border_color(&style_set_sm2_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_set_sm2_main_main_default, 0);
	lv_style_set_border_opa(&style_set_sm2_main_main_default, 255);
	lv_style_set_text_color(&style_set_sm2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_set_sm2_main_main_default, &lv_font_montserratMedium_24);
	lv_style_set_text_align(&style_set_sm2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SET_SM2, &style_set_sm2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SET_SM2_label = lv_label_create(ui->SET_SM2);
	lv_label_set_text(ui->SET_SM2_label, "M2");
	lv_obj_set_style_pad_all(ui->SET_SM2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SET_SM2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SET_btn_3
	ui->SET_btn_3 = lv_btn_create(ui->SET_cont_1);
	lv_obj_set_pos(ui->SET_btn_3, 264, -8);
	lv_obj_set_size(ui->SET_btn_3, 50, 50);
	lv_obj_set_scrollbar_mode(ui->SET_btn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_set_btn_3_main_main_default
	static lv_style_t style_set_btn_3_main_main_default;
	if (style_set_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_set_btn_3_main_main_default);
	else
		lv_style_init(&style_set_btn_3_main_main_default);
	lv_style_set_radius(&style_set_btn_3_main_main_default, 5);
	lv_style_set_bg_color(&style_set_btn_3_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_set_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_set_btn_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_set_btn_3_main_main_default, 0);
	lv_style_set_shadow_width(&style_set_btn_3_main_main_default, 0);
	lv_style_set_shadow_color(&style_set_btn_3_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_shadow_opa(&style_set_btn_3_main_main_default, 0);
	lv_style_set_shadow_spread(&style_set_btn_3_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_set_btn_3_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_set_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_set_btn_3_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_set_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_set_btn_3_main_main_default, 0);
	lv_style_set_text_color(&style_set_btn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_set_btn_3_main_main_default, &lv_font_montserratMedium_36);
	lv_style_set_text_align(&style_set_btn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SET_btn_3, &style_set_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SET_btn_3_label = lv_label_create(ui->SET_btn_3);
	lv_label_set_text(ui->SET_btn_3_label, "X");
	lv_obj_set_style_pad_all(ui->SET_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SET_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SET_label_1
	ui->SET_label_1 = lv_label_create(ui->SET_cont_1);
	lv_obj_set_pos(ui->SET_label_1, -2, -1);
	lv_obj_set_size(ui->SET_label_1, 260, 35);
	lv_obj_set_scrollbar_mode(ui->SET_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->SET_label_1, "Label");
	lv_label_set_long_mode(ui->SET_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_set_label_1_main_main_default
	static lv_style_t style_set_label_1_main_main_default;
	if (style_set_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_set_label_1_main_main_default);
	else
		lv_style_init(&style_set_label_1_main_main_default);
	lv_style_set_radius(&style_set_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_set_label_1_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_bg_grad_color(&style_set_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_set_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_set_label_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_set_label_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_set_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_set_label_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_set_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_set_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_set_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_set_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_set_label_1_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_set_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_set_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_set_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_set_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_set_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_set_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_set_label_1_main_main_default, 0);
	lv_obj_add_style(ui->SET_label_1, &style_set_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_SET(ui);
}