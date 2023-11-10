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


void setup_scr_TYPE(lv_ui *ui){

	//Write codes TYPE
	ui->TYPE = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->TYPE, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_main_main_default
	static lv_style_t style_type_main_main_default;
	if (style_type_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_main_main_default);
	else
		lv_style_init(&style_type_main_main_default);
	lv_style_set_bg_color(&style_type_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_type_main_main_default, 0);
	lv_obj_add_style(ui->TYPE, &style_type_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_cont_1
	ui->TYPE_cont_1 = lv_obj_create(ui->TYPE);
	lv_obj_set_pos(ui->TYPE_cont_1, 0, 0);
	lv_obj_set_size(ui->TYPE_cont_1, 320, 480);
	lv_obj_set_scrollbar_mode(ui->TYPE_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_cont_1_main_main_default
	static lv_style_t style_type_cont_1_main_main_default;
	if (style_type_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_cont_1_main_main_default);
	else
		lv_style_init(&style_type_cont_1_main_main_default);
	lv_style_set_radius(&style_type_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_type_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_type_cont_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_type_cont_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_cont_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_cont_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_cont_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_cont_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_cont_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_cont_1_main_main_default, 0);
	lv_style_set_border_color(&style_type_cont_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_type_cont_1_main_main_default, 2);
	lv_style_set_border_opa(&style_type_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_type_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_type_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_type_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_type_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_cont_1, &style_type_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_RM1
	ui->TYPE_RM1 = lv_btn_create(ui->TYPE_cont_1);
	lv_obj_set_pos(ui->TYPE_RM1, 68, 107);
	lv_obj_set_size(ui->TYPE_RM1, 100, 100);
	lv_obj_set_scrollbar_mode(ui->TYPE_RM1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_rm1_main_main_default
	static lv_style_t style_type_rm1_main_main_default;
	if (style_type_rm1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_rm1_main_main_default);
	else
		lv_style_init(&style_type_rm1_main_main_default);
	lv_style_set_radius(&style_type_rm1_main_main_default, 50);
	lv_style_set_bg_color(&style_type_rm1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_rm1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_dir(&style_type_rm1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_rm1_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_rm1_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_rm1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_rm1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_rm1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_rm1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_rm1_main_main_default, 0);
	lv_style_set_border_color(&style_type_rm1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_type_rm1_main_main_default, 0);
	lv_style_set_border_opa(&style_type_rm1_main_main_default, 255);
	lv_style_set_text_color(&style_type_rm1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_type_rm1_main_main_default, &lv_font_montserratMedium_36);
	lv_style_set_text_align(&style_type_rm1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->TYPE_RM1, &style_type_rm1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->TYPE_RM1_label = lv_label_create(ui->TYPE_RM1);
	lv_label_set_text(ui->TYPE_RM1_label, "M1");
	lv_obj_set_style_pad_all(ui->TYPE_RM1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->TYPE_RM1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes TYPE_RDRV
	ui->TYPE_RDRV = lv_btn_create(ui->TYPE_cont_1);
	lv_obj_set_pos(ui->TYPE_RDRV, 157, 300);
	lv_obj_set_size(ui->TYPE_RDRV, 100, 100);
	lv_obj_set_scrollbar_mode(ui->TYPE_RDRV, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_rdrv_main_main_default
	static lv_style_t style_type_rdrv_main_main_default;
	if (style_type_rdrv_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_rdrv_main_main_default);
	else
		lv_style_init(&style_type_rdrv_main_main_default);
	lv_style_set_radius(&style_type_rdrv_main_main_default, 50);
	lv_style_set_bg_color(&style_type_rdrv_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_rdrv_main_main_default, lv_color_make(0x97, 0xe7, 0xff));
	lv_style_set_bg_grad_dir(&style_type_rdrv_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_rdrv_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_rdrv_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_rdrv_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_rdrv_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_rdrv_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_rdrv_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_rdrv_main_main_default, 0);
	lv_style_set_border_color(&style_type_rdrv_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_type_rdrv_main_main_default, 0);
	lv_style_set_border_opa(&style_type_rdrv_main_main_default, 255);
	lv_style_set_text_color(&style_type_rdrv_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_type_rdrv_main_main_default, &lv_font_montserratMedium_24);
	lv_style_set_text_align(&style_type_rdrv_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->TYPE_RDRV, &style_type_rdrv_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->TYPE_RDRV_label = lv_label_create(ui->TYPE_RDRV);
	lv_label_set_text(ui->TYPE_RDRV_label, "DRV");
	lv_obj_set_style_pad_all(ui->TYPE_RDRV, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->TYPE_RDRV_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes TYPE_RM1M2
	ui->TYPE_RM1M2 = lv_btn_create(ui->TYPE_cont_1);
	lv_obj_set_pos(ui->TYPE_RM1M2, 30, 240);
	lv_obj_set_size(ui->TYPE_RM1M2, 100, 100);
	lv_obj_set_scrollbar_mode(ui->TYPE_RM1M2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_rm1m2_main_main_default
	static lv_style_t style_type_rm1m2_main_main_default;
	if (style_type_rm1m2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_rm1m2_main_main_default);
	else
		lv_style_init(&style_type_rm1m2_main_main_default);
	lv_style_set_radius(&style_type_rm1m2_main_main_default, 50);
	lv_style_set_bg_color(&style_type_rm1m2_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_rm1m2_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_dir(&style_type_rm1m2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_rm1m2_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_rm1m2_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_rm1m2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_rm1m2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_rm1m2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_rm1m2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_rm1m2_main_main_default, 0);
	lv_style_set_border_color(&style_type_rm1m2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_type_rm1m2_main_main_default, 0);
	lv_style_set_border_opa(&style_type_rm1m2_main_main_default, 255);
	lv_style_set_text_color(&style_type_rm1m2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_type_rm1m2_main_main_default, &lv_font_montserratMedium_24);
	lv_style_set_text_align(&style_type_rm1m2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->TYPE_RM1M2, &style_type_rm1m2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->TYPE_RM1M2_label = lv_label_create(ui->TYPE_RM1M2);
	lv_label_set_text(ui->TYPE_RM1M2_label, "M1M2");
	lv_obj_set_style_pad_all(ui->TYPE_RM1M2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->TYPE_RM1M2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes TYPE_RM2
	ui->TYPE_RM2 = lv_btn_create(ui->TYPE_cont_1);
	lv_obj_set_pos(ui->TYPE_RM2, 190, 150);
	lv_obj_set_size(ui->TYPE_RM2, 100, 100);
	lv_obj_set_scrollbar_mode(ui->TYPE_RM2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_rm2_main_main_default
	static lv_style_t style_type_rm2_main_main_default;
	if (style_type_rm2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_rm2_main_main_default);
	else
		lv_style_init(&style_type_rm2_main_main_default);
	lv_style_set_radius(&style_type_rm2_main_main_default, 50);
	lv_style_set_bg_color(&style_type_rm2_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_rm2_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_dir(&style_type_rm2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_rm2_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_rm2_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_rm2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_rm2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_rm2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_rm2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_rm2_main_main_default, 0);
	lv_style_set_border_color(&style_type_rm2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_type_rm2_main_main_default, 0);
	lv_style_set_border_opa(&style_type_rm2_main_main_default, 255);
	lv_style_set_text_color(&style_type_rm2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_type_rm2_main_main_default, &lv_font_montserratMedium_31);
	lv_style_set_text_align(&style_type_rm2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->TYPE_RM2, &style_type_rm2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->TYPE_RM2_label = lv_label_create(ui->TYPE_RM2);
	lv_label_set_text(ui->TYPE_RM2_label, "M2");
	lv_obj_set_style_pad_all(ui->TYPE_RM2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->TYPE_RM2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes TYPE_btn_1
	ui->TYPE_btn_1 = lv_btn_create(ui->TYPE_cont_1);
	lv_obj_set_pos(ui->TYPE_btn_1, 267, -7);
	lv_obj_set_size(ui->TYPE_btn_1, 56, 57);
	lv_obj_set_scrollbar_mode(ui->TYPE_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_btn_1_main_main_default
	static lv_style_t style_type_btn_1_main_main_default;
	if (style_type_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_btn_1_main_main_default);
	else
		lv_style_init(&style_type_btn_1_main_main_default);
	lv_style_set_radius(&style_type_btn_1_main_main_default, 25);
	lv_style_set_bg_color(&style_type_btn_1_main_main_default, lv_color_make(0xfe, 0xfe, 0xfe));
	lv_style_set_bg_grad_color(&style_type_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_btn_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_btn_1_main_main_default, 0);
	lv_style_set_shadow_width(&style_type_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_btn_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_btn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_btn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_type_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_type_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_type_btn_1_main_main_default, 255);
	lv_style_set_text_color(&style_type_btn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_type_btn_1_main_main_default, &lv_font_montserratMedium_36);
	lv_style_set_text_align(&style_type_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->TYPE_btn_1, &style_type_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->TYPE_btn_1_label = lv_label_create(ui->TYPE_btn_1);
	lv_label_set_text(ui->TYPE_btn_1_label, "X");
	lv_obj_set_style_pad_all(ui->TYPE_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->TYPE_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes TYPE_TM1
	ui->TYPE_TM1 = lv_obj_create(ui->TYPE);
	lv_obj_set_pos(ui->TYPE_TM1, -305, 100);
	lv_obj_set_size(ui->TYPE_TM1, 300, 310);
	lv_obj_set_scrollbar_mode(ui->TYPE_TM1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_tm1_main_main_default
	static lv_style_t style_type_tm1_main_main_default;
	if (style_type_tm1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_tm1_main_main_default);
	else
		lv_style_init(&style_type_tm1_main_main_default);
	lv_style_set_radius(&style_type_tm1_main_main_default, 0);
	lv_style_set_bg_color(&style_type_tm1_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_bg_grad_color(&style_type_tm1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_type_tm1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_tm1_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_tm1_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_tm1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_tm1_main_main_default, 0);
	lv_style_set_shadow_spread(&style_type_tm1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_tm1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_tm1_main_main_default, 0);
	lv_style_set_border_color(&style_type_tm1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_type_tm1_main_main_default, 2);
	lv_style_set_border_opa(&style_type_tm1_main_main_default, 0);
	lv_style_set_pad_left(&style_type_tm1_main_main_default, 0);
	lv_style_set_pad_right(&style_type_tm1_main_main_default, 0);
	lv_style_set_pad_top(&style_type_tm1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_type_tm1_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_TM1, &style_type_tm1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_btn_2
	ui->TYPE_btn_2 = lv_btn_create(ui->TYPE_TM1);
	lv_obj_set_pos(ui->TYPE_btn_2, 261, 1);
	lv_obj_set_size(ui->TYPE_btn_2, 43, 42);
	lv_obj_set_scrollbar_mode(ui->TYPE_btn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_btn_2_main_main_default
	static lv_style_t style_type_btn_2_main_main_default;
	if (style_type_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_btn_2_main_main_default);
	else
		lv_style_init(&style_type_btn_2_main_main_default);
	lv_style_set_radius(&style_type_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_type_btn_2_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_bg_grad_color(&style_type_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_btn_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_btn_2_main_main_default, 0);
	lv_style_set_shadow_width(&style_type_btn_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_btn_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_btn_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_btn_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_type_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_type_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_type_btn_2_main_main_default, 255);
	lv_style_set_text_color(&style_type_btn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_type_btn_2_main_main_default, &lv_font_montserratMedium_36);
	lv_style_set_text_align(&style_type_btn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->TYPE_btn_2, &style_type_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->TYPE_btn_2_label = lv_label_create(ui->TYPE_btn_2);
	lv_label_set_text(ui->TYPE_btn_2_label, "X");
	lv_obj_set_style_pad_all(ui->TYPE_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->TYPE_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes TYPE_label_1
	ui->TYPE_label_1 = lv_label_create(ui->TYPE_TM1);
	lv_obj_set_pos(ui->TYPE_label_1, 22, 69);
	lv_obj_set_size(ui->TYPE_label_1, 260, 28);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_1, "M1");
	lv_label_set_long_mode(ui->TYPE_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_1_main_main_default
	static lv_style_t style_type_label_1_main_main_default;
	if (style_type_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_1_main_main_default);
	else
		lv_style_init(&style_type_label_1_main_main_default);
	lv_style_set_radius(&style_type_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_1_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_1_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_1_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_1, &style_type_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_M1TAR
	ui->TYPE_M1TAR = lv_label_create(ui->TYPE_TM1);
	lv_obj_set_pos(ui->TYPE_M1TAR, 22, 97);
	lv_obj_set_size(ui->TYPE_M1TAR, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_M1TAR, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_M1TAR, "TARGET");
	lv_label_set_long_mode(ui->TYPE_M1TAR, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_m1tar_main_main_default
	static lv_style_t style_type_m1tar_main_main_default;
	if (style_type_m1tar_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_m1tar_main_main_default);
	else
		lv_style_init(&style_type_m1tar_main_main_default);
	lv_style_set_radius(&style_type_m1tar_main_main_default, 0);
	lv_style_set_bg_color(&style_type_m1tar_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_m1tar_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_m1tar_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_m1tar_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_m1tar_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_m1tar_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_m1tar_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_m1tar_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_m1tar_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_m1tar_main_main_default, 0);
	lv_style_set_text_color(&style_type_m1tar_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_m1tar_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_m1tar_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_m1tar_main_main_default, 0);
	lv_style_set_text_align(&style_type_m1tar_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_m1tar_main_main_default, 0);
	lv_style_set_pad_right(&style_type_m1tar_main_main_default, 0);
	lv_style_set_pad_top(&style_type_m1tar_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_m1tar_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_M1TAR, &style_type_m1tar_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_M1IA
	ui->TYPE_M1IA = lv_label_create(ui->TYPE_TM1);
	lv_obj_set_pos(ui->TYPE_M1IA, 22, 127);
	lv_obj_set_size(ui->TYPE_M1IA, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_M1IA, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_M1IA, "I(A)");
	lv_label_set_long_mode(ui->TYPE_M1IA, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_m1ia_main_main_default
	static lv_style_t style_type_m1ia_main_main_default;
	if (style_type_m1ia_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_m1ia_main_main_default);
	else
		lv_style_init(&style_type_m1ia_main_main_default);
	lv_style_set_radius(&style_type_m1ia_main_main_default, 0);
	lv_style_set_bg_color(&style_type_m1ia_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_m1ia_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_m1ia_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_m1ia_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_m1ia_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_m1ia_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_m1ia_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_m1ia_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_m1ia_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_m1ia_main_main_default, 0);
	lv_style_set_text_color(&style_type_m1ia_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_m1ia_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_m1ia_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_m1ia_main_main_default, 0);
	lv_style_set_text_align(&style_type_m1ia_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_m1ia_main_main_default, 0);
	lv_style_set_pad_right(&style_type_m1ia_main_main_default, 0);
	lv_style_set_pad_top(&style_type_m1ia_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_m1ia_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_M1IA, &style_type_m1ia_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_M1V
	ui->TYPE_M1V = lv_label_create(ui->TYPE_TM1);
	lv_obj_set_pos(ui->TYPE_M1V, 22, 156);
	lv_obj_set_size(ui->TYPE_M1V, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_M1V, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_M1V, "V");
	lv_label_set_long_mode(ui->TYPE_M1V, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_m1v_main_main_default
	static lv_style_t style_type_m1v_main_main_default;
	if (style_type_m1v_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_m1v_main_main_default);
	else
		lv_style_init(&style_type_m1v_main_main_default);
	lv_style_set_radius(&style_type_m1v_main_main_default, 0);
	lv_style_set_bg_color(&style_type_m1v_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_m1v_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_m1v_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_m1v_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_m1v_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_m1v_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_m1v_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_m1v_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_m1v_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_m1v_main_main_default, 0);
	lv_style_set_text_color(&style_type_m1v_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_m1v_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_m1v_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_m1v_main_main_default, 0);
	lv_style_set_text_align(&style_type_m1v_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_m1v_main_main_default, 0);
	lv_style_set_pad_right(&style_type_m1v_main_main_default, 0);
	lv_style_set_pad_top(&style_type_m1v_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_m1v_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_M1V, &style_type_m1v_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_M1POSI
	ui->TYPE_M1POSI = lv_label_create(ui->TYPE_TM1);
	lv_obj_set_pos(ui->TYPE_M1POSI, 22, 183);
	lv_obj_set_size(ui->TYPE_M1POSI, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_M1POSI, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_M1POSI, "POSITION");
	lv_label_set_long_mode(ui->TYPE_M1POSI, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_m1posi_main_main_default
	static lv_style_t style_type_m1posi_main_main_default;
	if (style_type_m1posi_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_m1posi_main_main_default);
	else
		lv_style_init(&style_type_m1posi_main_main_default);
	lv_style_set_radius(&style_type_m1posi_main_main_default, 0);
	lv_style_set_bg_color(&style_type_m1posi_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_m1posi_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_m1posi_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_m1posi_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_m1posi_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_m1posi_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_m1posi_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_m1posi_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_m1posi_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_m1posi_main_main_default, 0);
	lv_style_set_text_color(&style_type_m1posi_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_m1posi_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_m1posi_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_m1posi_main_main_default, 0);
	lv_style_set_text_align(&style_type_m1posi_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_m1posi_main_main_default, 0);
	lv_style_set_pad_right(&style_type_m1posi_main_main_default, 0);
	lv_style_set_pad_top(&style_type_m1posi_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_m1posi_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_M1POSI, &style_type_m1posi_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_M1TAD
	ui->TYPE_M1TAD = lv_label_create(ui->TYPE_TM1);
	lv_obj_set_pos(ui->TYPE_M1TAD, 152, 96);
	lv_obj_set_size(ui->TYPE_M1TAD, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_M1TAD, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_M1TAD, "Label");
	lv_label_set_long_mode(ui->TYPE_M1TAD, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_m1tad_main_main_default
	static lv_style_t style_type_m1tad_main_main_default;
	if (style_type_m1tad_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_m1tad_main_main_default);
	else
		lv_style_init(&style_type_m1tad_main_main_default);
	lv_style_set_radius(&style_type_m1tad_main_main_default, 0);
	lv_style_set_bg_color(&style_type_m1tad_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_m1tad_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_m1tad_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_m1tad_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_m1tad_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_m1tad_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_m1tad_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_m1tad_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_m1tad_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_m1tad_main_main_default, 0);
	lv_style_set_text_color(&style_type_m1tad_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_m1tad_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_m1tad_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_m1tad_main_main_default, 0);
	lv_style_set_text_align(&style_type_m1tad_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_m1tad_main_main_default, 0);
	lv_style_set_pad_right(&style_type_m1tad_main_main_default, 0);
	lv_style_set_pad_top(&style_type_m1tad_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_m1tad_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_M1TAD, &style_type_m1tad_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_M1ID
	ui->TYPE_M1ID = lv_label_create(ui->TYPE_TM1);
	lv_obj_set_pos(ui->TYPE_M1ID, 152, 127);
	lv_obj_set_size(ui->TYPE_M1ID, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_M1ID, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_M1ID, "Label");
	lv_label_set_long_mode(ui->TYPE_M1ID, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_m1id_main_main_default
	static lv_style_t style_type_m1id_main_main_default;
	if (style_type_m1id_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_m1id_main_main_default);
	else
		lv_style_init(&style_type_m1id_main_main_default);
	lv_style_set_radius(&style_type_m1id_main_main_default, 0);
	lv_style_set_bg_color(&style_type_m1id_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_m1id_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_m1id_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_m1id_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_m1id_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_m1id_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_m1id_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_m1id_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_m1id_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_m1id_main_main_default, 0);
	lv_style_set_text_color(&style_type_m1id_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_m1id_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_m1id_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_m1id_main_main_default, 0);
	lv_style_set_text_align(&style_type_m1id_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_m1id_main_main_default, 0);
	lv_style_set_pad_right(&style_type_m1id_main_main_default, 0);
	lv_style_set_pad_top(&style_type_m1id_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_m1id_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_M1ID, &style_type_m1id_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_M1VD
	ui->TYPE_M1VD = lv_label_create(ui->TYPE_TM1);
	lv_obj_set_pos(ui->TYPE_M1VD, 152, 155);
	lv_obj_set_size(ui->TYPE_M1VD, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_M1VD, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_M1VD, "Label");
	lv_label_set_long_mode(ui->TYPE_M1VD, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_m1vd_main_main_default
	static lv_style_t style_type_m1vd_main_main_default;
	if (style_type_m1vd_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_m1vd_main_main_default);
	else
		lv_style_init(&style_type_m1vd_main_main_default);
	lv_style_set_radius(&style_type_m1vd_main_main_default, 0);
	lv_style_set_bg_color(&style_type_m1vd_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_m1vd_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_m1vd_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_m1vd_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_m1vd_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_m1vd_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_m1vd_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_m1vd_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_m1vd_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_m1vd_main_main_default, 0);
	lv_style_set_text_color(&style_type_m1vd_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_m1vd_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_m1vd_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_m1vd_main_main_default, 0);
	lv_style_set_text_align(&style_type_m1vd_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_m1vd_main_main_default, 0);
	lv_style_set_pad_right(&style_type_m1vd_main_main_default, 0);
	lv_style_set_pad_top(&style_type_m1vd_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_m1vd_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_M1VD, &style_type_m1vd_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_M1PD
	ui->TYPE_M1PD = lv_label_create(ui->TYPE_TM1);
	lv_obj_set_pos(ui->TYPE_M1PD, 152, 183);
	lv_obj_set_size(ui->TYPE_M1PD, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_M1PD, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_M1PD, "Label");
	lv_label_set_long_mode(ui->TYPE_M1PD, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_m1pd_main_main_default
	static lv_style_t style_type_m1pd_main_main_default;
	if (style_type_m1pd_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_m1pd_main_main_default);
	else
		lv_style_init(&style_type_m1pd_main_main_default);
	lv_style_set_radius(&style_type_m1pd_main_main_default, 0);
	lv_style_set_bg_color(&style_type_m1pd_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_m1pd_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_m1pd_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_m1pd_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_m1pd_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_m1pd_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_m1pd_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_m1pd_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_m1pd_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_m1pd_main_main_default, 0);
	lv_style_set_text_color(&style_type_m1pd_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_m1pd_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_m1pd_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_m1pd_main_main_default, 0);
	lv_style_set_text_align(&style_type_m1pd_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_m1pd_main_main_default, 0);
	lv_style_set_pad_right(&style_type_m1pd_main_main_default, 0);
	lv_style_set_pad_top(&style_type_m1pd_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_m1pd_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_M1PD, &style_type_m1pd_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_TM2
	ui->TYPE_TM2 = lv_obj_create(ui->TYPE);
	lv_obj_set_pos(ui->TYPE_TM2, 320, 100);
	lv_obj_set_size(ui->TYPE_TM2, 300, 310);
	lv_obj_set_scrollbar_mode(ui->TYPE_TM2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_tm2_main_main_default
	static lv_style_t style_type_tm2_main_main_default;
	if (style_type_tm2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_tm2_main_main_default);
	else
		lv_style_init(&style_type_tm2_main_main_default);
	lv_style_set_radius(&style_type_tm2_main_main_default, 0);
	lv_style_set_bg_color(&style_type_tm2_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_bg_grad_color(&style_type_tm2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_type_tm2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_tm2_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_tm2_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_tm2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_tm2_main_main_default, 0);
	lv_style_set_shadow_spread(&style_type_tm2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_tm2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_tm2_main_main_default, 0);
	lv_style_set_border_color(&style_type_tm2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_type_tm2_main_main_default, 2);
	lv_style_set_border_opa(&style_type_tm2_main_main_default, 0);
	lv_style_set_pad_left(&style_type_tm2_main_main_default, 0);
	lv_style_set_pad_right(&style_type_tm2_main_main_default, 0);
	lv_style_set_pad_top(&style_type_tm2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_type_tm2_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_TM2, &style_type_tm2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_btn_3
	ui->TYPE_btn_3 = lv_btn_create(ui->TYPE_TM2);
	lv_obj_set_pos(ui->TYPE_btn_3, 261, 1);
	lv_obj_set_size(ui->TYPE_btn_3, 43, 42);
	lv_obj_set_scrollbar_mode(ui->TYPE_btn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_btn_3_main_main_default
	static lv_style_t style_type_btn_3_main_main_default;
	if (style_type_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_btn_3_main_main_default);
	else
		lv_style_init(&style_type_btn_3_main_main_default);
	lv_style_set_radius(&style_type_btn_3_main_main_default, 5);
	lv_style_set_bg_color(&style_type_btn_3_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_bg_grad_color(&style_type_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_btn_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_btn_3_main_main_default, 0);
	lv_style_set_shadow_width(&style_type_btn_3_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_btn_3_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_btn_3_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_btn_3_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_type_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_type_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_type_btn_3_main_main_default, 255);
	lv_style_set_text_color(&style_type_btn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_type_btn_3_main_main_default, &lv_font_montserratMedium_36);
	lv_style_set_text_align(&style_type_btn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->TYPE_btn_3, &style_type_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->TYPE_btn_3_label = lv_label_create(ui->TYPE_btn_3);
	lv_label_set_text(ui->TYPE_btn_3_label, "X");
	lv_obj_set_style_pad_all(ui->TYPE_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->TYPE_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes TYPE_label_10
	ui->TYPE_label_10 = lv_label_create(ui->TYPE_TM2);
	lv_obj_set_pos(ui->TYPE_label_10, 22, 69);
	lv_obj_set_size(ui->TYPE_label_10, 260, 28);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_10, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_10, "M2");
	lv_label_set_long_mode(ui->TYPE_label_10, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_10_main_main_default
	static lv_style_t style_type_label_10_main_main_default;
	if (style_type_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_10_main_main_default);
	else
		lv_style_init(&style_type_label_10_main_main_default);
	lv_style_set_radius(&style_type_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_10_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_10_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_10_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_10_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_10_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_10_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_10_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_10_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_10_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_10_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_10_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_10_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_10_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_10_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_10_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_10, &style_type_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_9
	ui->TYPE_label_9 = lv_label_create(ui->TYPE_TM2);
	lv_obj_set_pos(ui->TYPE_label_9, 22, 97);
	lv_obj_set_size(ui->TYPE_label_9, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_9, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_9, "TARGET");
	lv_label_set_long_mode(ui->TYPE_label_9, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_9_main_main_default
	static lv_style_t style_type_label_9_main_main_default;
	if (style_type_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_9_main_main_default);
	else
		lv_style_init(&style_type_label_9_main_main_default);
	lv_style_set_radius(&style_type_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_9_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_9_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_9_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_9_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_9_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_9_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_9_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_9_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_9_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_9_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_9_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_9_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_9, &style_type_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_8
	ui->TYPE_label_8 = lv_label_create(ui->TYPE_TM2);
	lv_obj_set_pos(ui->TYPE_label_8, 22, 127);
	lv_obj_set_size(ui->TYPE_label_8, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_8, "I(A)");
	lv_label_set_long_mode(ui->TYPE_label_8, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_8_main_main_default
	static lv_style_t style_type_label_8_main_main_default;
	if (style_type_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_8_main_main_default);
	else
		lv_style_init(&style_type_label_8_main_main_default);
	lv_style_set_radius(&style_type_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_8_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_8_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_8_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_8_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_8_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_8_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_8_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_8_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_8_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_8_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_8_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_8_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_8, &style_type_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_7
	ui->TYPE_label_7 = lv_label_create(ui->TYPE_TM2);
	lv_obj_set_pos(ui->TYPE_label_7, 22, 156);
	lv_obj_set_size(ui->TYPE_label_7, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_7, "V");
	lv_label_set_long_mode(ui->TYPE_label_7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_7_main_main_default
	static lv_style_t style_type_label_7_main_main_default;
	if (style_type_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_7_main_main_default);
	else
		lv_style_init(&style_type_label_7_main_main_default);
	lv_style_set_radius(&style_type_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_7_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_7_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_7_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_7_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_7_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_7_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_7_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_7_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_7_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_7_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_7_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_7_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_7, &style_type_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_6
	ui->TYPE_label_6 = lv_label_create(ui->TYPE_TM2);
	lv_obj_set_pos(ui->TYPE_label_6, 22, 183);
	lv_obj_set_size(ui->TYPE_label_6, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_6, "POSITION");
	lv_label_set_long_mode(ui->TYPE_label_6, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_6_main_main_default
	static lv_style_t style_type_label_6_main_main_default;
	if (style_type_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_6_main_main_default);
	else
		lv_style_init(&style_type_label_6_main_main_default);
	lv_style_set_radius(&style_type_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_6_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_6_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_6_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_6_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_6_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_6_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_6_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_6_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_6_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_6_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_6_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_6_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_6, &style_type_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_M2TAD
	ui->TYPE_M2TAD = lv_label_create(ui->TYPE_TM2);
	lv_obj_set_pos(ui->TYPE_M2TAD, 152, 96);
	lv_obj_set_size(ui->TYPE_M2TAD, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_M2TAD, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_M2TAD, "Label");
	lv_label_set_long_mode(ui->TYPE_M2TAD, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_m2tad_main_main_default
	static lv_style_t style_type_m2tad_main_main_default;
	if (style_type_m2tad_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_m2tad_main_main_default);
	else
		lv_style_init(&style_type_m2tad_main_main_default);
	lv_style_set_radius(&style_type_m2tad_main_main_default, 0);
	lv_style_set_bg_color(&style_type_m2tad_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_m2tad_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_m2tad_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_m2tad_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_m2tad_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_m2tad_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_m2tad_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_m2tad_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_m2tad_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_m2tad_main_main_default, 0);
	lv_style_set_text_color(&style_type_m2tad_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_m2tad_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_m2tad_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_m2tad_main_main_default, 0);
	lv_style_set_text_align(&style_type_m2tad_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_m2tad_main_main_default, 0);
	lv_style_set_pad_right(&style_type_m2tad_main_main_default, 0);
	lv_style_set_pad_top(&style_type_m2tad_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_m2tad_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_M2TAD, &style_type_m2tad_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_M2ID
	ui->TYPE_M2ID = lv_label_create(ui->TYPE_TM2);
	lv_obj_set_pos(ui->TYPE_M2ID, 152, 127);
	lv_obj_set_size(ui->TYPE_M2ID, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_M2ID, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_M2ID, "Label");
	lv_label_set_long_mode(ui->TYPE_M2ID, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_m2id_main_main_default
	static lv_style_t style_type_m2id_main_main_default;
	if (style_type_m2id_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_m2id_main_main_default);
	else
		lv_style_init(&style_type_m2id_main_main_default);
	lv_style_set_radius(&style_type_m2id_main_main_default, 0);
	lv_style_set_bg_color(&style_type_m2id_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_m2id_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_m2id_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_m2id_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_m2id_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_m2id_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_m2id_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_m2id_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_m2id_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_m2id_main_main_default, 0);
	lv_style_set_text_color(&style_type_m2id_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_m2id_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_m2id_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_m2id_main_main_default, 0);
	lv_style_set_text_align(&style_type_m2id_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_m2id_main_main_default, 0);
	lv_style_set_pad_right(&style_type_m2id_main_main_default, 0);
	lv_style_set_pad_top(&style_type_m2id_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_m2id_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_M2ID, &style_type_m2id_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_M2VD
	ui->TYPE_M2VD = lv_label_create(ui->TYPE_TM2);
	lv_obj_set_pos(ui->TYPE_M2VD, 152, 155);
	lv_obj_set_size(ui->TYPE_M2VD, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_M2VD, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_M2VD, "Label");
	lv_label_set_long_mode(ui->TYPE_M2VD, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_m2vd_main_main_default
	static lv_style_t style_type_m2vd_main_main_default;
	if (style_type_m2vd_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_m2vd_main_main_default);
	else
		lv_style_init(&style_type_m2vd_main_main_default);
	lv_style_set_radius(&style_type_m2vd_main_main_default, 0);
	lv_style_set_bg_color(&style_type_m2vd_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_m2vd_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_m2vd_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_m2vd_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_m2vd_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_m2vd_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_m2vd_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_m2vd_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_m2vd_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_m2vd_main_main_default, 0);
	lv_style_set_text_color(&style_type_m2vd_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_m2vd_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_m2vd_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_m2vd_main_main_default, 0);
	lv_style_set_text_align(&style_type_m2vd_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_m2vd_main_main_default, 0);
	lv_style_set_pad_right(&style_type_m2vd_main_main_default, 0);
	lv_style_set_pad_top(&style_type_m2vd_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_m2vd_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_M2VD, &style_type_m2vd_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_M2PD
	ui->TYPE_M2PD = lv_label_create(ui->TYPE_TM2);
	lv_obj_set_pos(ui->TYPE_M2PD, 152, 183);
	lv_obj_set_size(ui->TYPE_M2PD, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_M2PD, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_M2PD, "Label");
	lv_label_set_long_mode(ui->TYPE_M2PD, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_m2pd_main_main_default
	static lv_style_t style_type_m2pd_main_main_default;
	if (style_type_m2pd_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_m2pd_main_main_default);
	else
		lv_style_init(&style_type_m2pd_main_main_default);
	lv_style_set_radius(&style_type_m2pd_main_main_default, 0);
	lv_style_set_bg_color(&style_type_m2pd_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_m2pd_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_m2pd_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_m2pd_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_m2pd_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_m2pd_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_m2pd_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_m2pd_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_m2pd_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_m2pd_main_main_default, 0);
	lv_style_set_text_color(&style_type_m2pd_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_m2pd_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_m2pd_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_m2pd_main_main_default, 0);
	lv_style_set_text_align(&style_type_m2pd_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_m2pd_main_main_default, 0);
	lv_style_set_pad_right(&style_type_m2pd_main_main_default, 0);
	lv_style_set_pad_top(&style_type_m2pd_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_m2pd_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_M2PD, &style_type_m2pd_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_TM1M2
	ui->TYPE_TM1M2 = lv_obj_create(ui->TYPE);
	lv_obj_set_pos(ui->TYPE_TM1M2, -307, 40);
	lv_obj_set_size(ui->TYPE_TM1M2, 302, 400);
	lv_obj_set_scrollbar_mode(ui->TYPE_TM1M2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_tm1m2_main_main_default
	static lv_style_t style_type_tm1m2_main_main_default;
	if (style_type_tm1m2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_tm1m2_main_main_default);
	else
		lv_style_init(&style_type_tm1m2_main_main_default);
	lv_style_set_radius(&style_type_tm1m2_main_main_default, 0);
	lv_style_set_bg_color(&style_type_tm1m2_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_bg_grad_color(&style_type_tm1m2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_type_tm1m2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_tm1m2_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_tm1m2_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_tm1m2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_tm1m2_main_main_default, 0);
	lv_style_set_shadow_spread(&style_type_tm1m2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_tm1m2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_tm1m2_main_main_default, 0);
	lv_style_set_border_color(&style_type_tm1m2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_type_tm1m2_main_main_default, 2);
	lv_style_set_border_opa(&style_type_tm1m2_main_main_default, 0);
	lv_style_set_pad_left(&style_type_tm1m2_main_main_default, 0);
	lv_style_set_pad_right(&style_type_tm1m2_main_main_default, 0);
	lv_style_set_pad_top(&style_type_tm1m2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_type_tm1m2_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_TM1M2, &style_type_tm1m2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_btn_4
	ui->TYPE_btn_4 = lv_btn_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_btn_4, 261, 1);
	lv_obj_set_size(ui->TYPE_btn_4, 43, 42);
	lv_obj_set_scrollbar_mode(ui->TYPE_btn_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_btn_4_main_main_default
	static lv_style_t style_type_btn_4_main_main_default;
	if (style_type_btn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_btn_4_main_main_default);
	else
		lv_style_init(&style_type_btn_4_main_main_default);
	lv_style_set_radius(&style_type_btn_4_main_main_default, 5);
	lv_style_set_bg_color(&style_type_btn_4_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_bg_grad_color(&style_type_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_btn_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_btn_4_main_main_default, 0);
	lv_style_set_shadow_width(&style_type_btn_4_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_btn_4_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_btn_4_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_btn_4_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_btn_4_main_main_default, 0);
	lv_style_set_border_color(&style_type_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_type_btn_4_main_main_default, 0);
	lv_style_set_border_opa(&style_type_btn_4_main_main_default, 255);
	lv_style_set_text_color(&style_type_btn_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_type_btn_4_main_main_default, &lv_font_montserratMedium_36);
	lv_style_set_text_align(&style_type_btn_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->TYPE_btn_4, &style_type_btn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->TYPE_btn_4_label = lv_label_create(ui->TYPE_btn_4);
	lv_label_set_text(ui->TYPE_btn_4_label, "X");
	lv_obj_set_style_pad_all(ui->TYPE_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->TYPE_btn_4_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes TYPE_label_19
	ui->TYPE_label_19 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_19, 22, 59);
	lv_obj_set_size(ui->TYPE_label_19, 260, 28);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_19, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_19, "M1");
	lv_label_set_long_mode(ui->TYPE_label_19, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_19_main_main_default
	static lv_style_t style_type_label_19_main_main_default;
	if (style_type_label_19_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_19_main_main_default);
	else
		lv_style_init(&style_type_label_19_main_main_default);
	lv_style_set_radius(&style_type_label_19_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_19_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_19_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_19_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_19_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_19_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_19_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_19_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_19_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_19_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_19_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_19_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_19_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_19_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_19_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_19_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_19_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_19_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_19_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_19_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_19, &style_type_label_19_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_18
	ui->TYPE_label_18 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_18, 22, 87);
	lv_obj_set_size(ui->TYPE_label_18, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_18, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_18, "TARGET");
	lv_label_set_long_mode(ui->TYPE_label_18, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_18_main_main_default
	static lv_style_t style_type_label_18_main_main_default;
	if (style_type_label_18_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_18_main_main_default);
	else
		lv_style_init(&style_type_label_18_main_main_default);
	lv_style_set_radius(&style_type_label_18_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_18_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_18_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_18_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_18_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_18_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_18_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_18_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_18_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_18_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_18_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_18_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_18_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_18_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_18_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_18_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_18_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_18_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_18_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_18_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_18, &style_type_label_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_17
	ui->TYPE_label_17 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_17, 22, 117);
	lv_obj_set_size(ui->TYPE_label_17, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_17, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_17, "I(A)");
	lv_label_set_long_mode(ui->TYPE_label_17, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_17_main_main_default
	static lv_style_t style_type_label_17_main_main_default;
	if (style_type_label_17_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_17_main_main_default);
	else
		lv_style_init(&style_type_label_17_main_main_default);
	lv_style_set_radius(&style_type_label_17_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_17_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_17_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_17_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_17_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_17_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_17_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_17_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_17_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_17_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_17_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_17_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_17_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_17_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_17_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_17_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_17_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_17_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_17_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_17_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_17, &style_type_label_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_16
	ui->TYPE_label_16 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_16, 22, 147);
	lv_obj_set_size(ui->TYPE_label_16, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_16, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_16, "V");
	lv_label_set_long_mode(ui->TYPE_label_16, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_16_main_main_default
	static lv_style_t style_type_label_16_main_main_default;
	if (style_type_label_16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_16_main_main_default);
	else
		lv_style_init(&style_type_label_16_main_main_default);
	lv_style_set_radius(&style_type_label_16_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_16_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_16_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_16_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_16_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_16_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_16_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_16_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_16_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_16_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_16_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_16_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_16_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_16_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_16_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_16_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_16_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_16_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_16_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_16_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_16, &style_type_label_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_15
	ui->TYPE_label_15 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_15, 22, 177);
	lv_obj_set_size(ui->TYPE_label_15, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_15, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_15, "POSITION");
	lv_label_set_long_mode(ui->TYPE_label_15, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_15_main_main_default
	static lv_style_t style_type_label_15_main_main_default;
	if (style_type_label_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_15_main_main_default);
	else
		lv_style_init(&style_type_label_15_main_main_default);
	lv_style_set_radius(&style_type_label_15_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_15_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_15_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_15_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_15_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_15_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_15_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_15_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_15_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_15_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_15_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_15_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_15_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_15_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_15_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_15_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_15_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_15_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_15_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_15_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_15, &style_type_label_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_14
	ui->TYPE_label_14 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_14, 152, 87);
	lv_obj_set_size(ui->TYPE_label_14, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_14, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_14, "Label");
	lv_label_set_long_mode(ui->TYPE_label_14, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_14_main_main_default
	static lv_style_t style_type_label_14_main_main_default;
	if (style_type_label_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_14_main_main_default);
	else
		lv_style_init(&style_type_label_14_main_main_default);
	lv_style_set_radius(&style_type_label_14_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_14_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_14_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_14_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_14_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_14_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_14_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_14_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_14_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_14_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_14_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_14_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_14_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_14_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_14_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_14_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_14_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_14_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_14_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_14_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_14, &style_type_label_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_13
	ui->TYPE_label_13 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_13, 152, 117);
	lv_obj_set_size(ui->TYPE_label_13, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_13, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_13, "Label");
	lv_label_set_long_mode(ui->TYPE_label_13, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_13_main_main_default
	static lv_style_t style_type_label_13_main_main_default;
	if (style_type_label_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_13_main_main_default);
	else
		lv_style_init(&style_type_label_13_main_main_default);
	lv_style_set_radius(&style_type_label_13_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_13_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_13_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_13_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_13_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_13_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_13_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_13_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_13_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_13_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_13_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_13_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_13_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_13_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_13_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_13_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_13_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_13_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_13_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_13_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_13, &style_type_label_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_12
	ui->TYPE_label_12 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_12, 152, 147);
	lv_obj_set_size(ui->TYPE_label_12, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_12, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_12, "Label");
	lv_label_set_long_mode(ui->TYPE_label_12, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_12_main_main_default
	static lv_style_t style_type_label_12_main_main_default;
	if (style_type_label_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_12_main_main_default);
	else
		lv_style_init(&style_type_label_12_main_main_default);
	lv_style_set_radius(&style_type_label_12_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_12_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_12_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_12_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_12_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_12_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_12_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_12_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_12_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_12_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_12_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_12_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_12_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_12_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_12_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_12_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_12_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_12_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_12, &style_type_label_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_11
	ui->TYPE_label_11 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_11, 152, 177);
	lv_obj_set_size(ui->TYPE_label_11, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_11, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_11, "Label");
	lv_label_set_long_mode(ui->TYPE_label_11, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_11_main_main_default
	static lv_style_t style_type_label_11_main_main_default;
	if (style_type_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_11_main_main_default);
	else
		lv_style_init(&style_type_label_11_main_main_default);
	lv_style_set_radius(&style_type_label_11_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_11_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_11_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_11_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_11_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_11_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_11_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_11_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_11_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_11_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_11_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_11_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_11_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_11_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_11_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_11_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_11, &style_type_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_20
	ui->TYPE_label_20 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_20, 22, 208);
	lv_obj_set_size(ui->TYPE_label_20, 260, 28);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_20, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_20, "M2");
	lv_label_set_long_mode(ui->TYPE_label_20, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_20_main_main_default
	static lv_style_t style_type_label_20_main_main_default;
	if (style_type_label_20_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_20_main_main_default);
	else
		lv_style_init(&style_type_label_20_main_main_default);
	lv_style_set_radius(&style_type_label_20_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_20_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_20_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_20_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_20_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_20_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_20_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_20_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_20_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_20_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_20_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_20_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_20_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_20_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_20_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_20_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_20_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_20_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_20_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_20_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_20, &style_type_label_20_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_21
	ui->TYPE_label_21 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_21, 22, 235);
	lv_obj_set_size(ui->TYPE_label_21, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_21, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_21, "TARGET");
	lv_label_set_long_mode(ui->TYPE_label_21, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_21_main_main_default
	static lv_style_t style_type_label_21_main_main_default;
	if (style_type_label_21_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_21_main_main_default);
	else
		lv_style_init(&style_type_label_21_main_main_default);
	lv_style_set_radius(&style_type_label_21_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_21_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_21_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_21_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_21_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_21_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_21_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_21_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_21_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_21_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_21_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_21_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_21_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_21_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_21_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_21_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_21_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_21_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_21_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_21_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_21, &style_type_label_21_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_22
	ui->TYPE_label_22 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_22, 22, 266);
	lv_obj_set_size(ui->TYPE_label_22, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_22, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_22, "I(A)");
	lv_label_set_long_mode(ui->TYPE_label_22, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_22_main_main_default
	static lv_style_t style_type_label_22_main_main_default;
	if (style_type_label_22_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_22_main_main_default);
	else
		lv_style_init(&style_type_label_22_main_main_default);
	lv_style_set_radius(&style_type_label_22_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_22_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_22_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_22_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_22_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_22_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_22_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_22_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_22_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_22_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_22_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_22_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_22_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_22_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_22_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_22_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_22_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_22_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_22_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_22_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_22, &style_type_label_22_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_23
	ui->TYPE_label_23 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_23, 22, 297);
	lv_obj_set_size(ui->TYPE_label_23, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_23, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_23, "V");
	lv_label_set_long_mode(ui->TYPE_label_23, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_23_main_main_default
	static lv_style_t style_type_label_23_main_main_default;
	if (style_type_label_23_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_23_main_main_default);
	else
		lv_style_init(&style_type_label_23_main_main_default);
	lv_style_set_radius(&style_type_label_23_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_23_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_23_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_23_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_23_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_23_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_23_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_23_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_23_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_23_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_23_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_23_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_23_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_23_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_23_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_23_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_23_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_23_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_23_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_23_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_23, &style_type_label_23_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_24
	ui->TYPE_label_24 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_24, 22, 328);
	lv_obj_set_size(ui->TYPE_label_24, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_24, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_24, "POSITION");
	lv_label_set_long_mode(ui->TYPE_label_24, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_24_main_main_default
	static lv_style_t style_type_label_24_main_main_default;
	if (style_type_label_24_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_24_main_main_default);
	else
		lv_style_init(&style_type_label_24_main_main_default);
	lv_style_set_radius(&style_type_label_24_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_24_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_24_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_24_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_24_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_24_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_24_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_24_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_24_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_24_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_24_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_24_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_24_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_24_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_24_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_24_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_24_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_24_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_24_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_24_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_24, &style_type_label_24_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_26
	ui->TYPE_label_26 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_26, 152, 235);
	lv_obj_set_size(ui->TYPE_label_26, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_26, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_26, "Label");
	lv_label_set_long_mode(ui->TYPE_label_26, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_26_main_main_default
	static lv_style_t style_type_label_26_main_main_default;
	if (style_type_label_26_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_26_main_main_default);
	else
		lv_style_init(&style_type_label_26_main_main_default);
	lv_style_set_radius(&style_type_label_26_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_26_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_26_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_26_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_26_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_26_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_26_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_26_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_26_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_26_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_26_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_26_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_26_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_26_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_26_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_26_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_26_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_26_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_26_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_26_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_26, &style_type_label_26_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_27
	ui->TYPE_label_27 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_27, 152, 266);
	lv_obj_set_size(ui->TYPE_label_27, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_27, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_27, "Label");
	lv_label_set_long_mode(ui->TYPE_label_27, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_27_main_main_default
	static lv_style_t style_type_label_27_main_main_default;
	if (style_type_label_27_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_27_main_main_default);
	else
		lv_style_init(&style_type_label_27_main_main_default);
	lv_style_set_radius(&style_type_label_27_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_27_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_27_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_27_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_27_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_27_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_27_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_27_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_27_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_27_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_27_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_27_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_27_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_27_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_27_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_27_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_27_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_27_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_27_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_27_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_27, &style_type_label_27_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_28
	ui->TYPE_label_28 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_28, 152, 297);
	lv_obj_set_size(ui->TYPE_label_28, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_28, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_28, "Label");
	lv_label_set_long_mode(ui->TYPE_label_28, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_28_main_main_default
	static lv_style_t style_type_label_28_main_main_default;
	if (style_type_label_28_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_28_main_main_default);
	else
		lv_style_init(&style_type_label_28_main_main_default);
	lv_style_set_radius(&style_type_label_28_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_28_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_28_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_28_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_28_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_28_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_28_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_28_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_28_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_28_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_28_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_28_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_28_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_28_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_28_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_28_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_28_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_28_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_28_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_28_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_28, &style_type_label_28_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_29
	ui->TYPE_label_29 = lv_label_create(ui->TYPE_TM1M2);
	lv_obj_set_pos(ui->TYPE_label_29, 152, 328);
	lv_obj_set_size(ui->TYPE_label_29, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_29, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_29, "Label");
	lv_label_set_long_mode(ui->TYPE_label_29, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_29_main_main_default
	static lv_style_t style_type_label_29_main_main_default;
	if (style_type_label_29_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_29_main_main_default);
	else
		lv_style_init(&style_type_label_29_main_main_default);
	lv_style_set_radius(&style_type_label_29_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_29_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_29_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_29_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_29_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_29_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_29_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_29_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_29_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_29_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_29_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_29_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_29_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_29_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_29_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_29_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_29_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_29_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_29_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_29_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_29, &style_type_label_29_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_TDRV
	ui->TYPE_TDRV = lv_obj_create(ui->TYPE);
	lv_obj_set_pos(ui->TYPE_TDRV, 320, 100);
	lv_obj_set_size(ui->TYPE_TDRV, 300, 310);
	lv_obj_set_scrollbar_mode(ui->TYPE_TDRV, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_tdrv_main_main_default
	static lv_style_t style_type_tdrv_main_main_default;
	if (style_type_tdrv_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_tdrv_main_main_default);
	else
		lv_style_init(&style_type_tdrv_main_main_default);
	lv_style_set_radius(&style_type_tdrv_main_main_default, 0);
	lv_style_set_bg_color(&style_type_tdrv_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_bg_grad_color(&style_type_tdrv_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_type_tdrv_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_tdrv_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_tdrv_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_tdrv_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_tdrv_main_main_default, 0);
	lv_style_set_shadow_spread(&style_type_tdrv_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_tdrv_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_tdrv_main_main_default, 0);
	lv_style_set_border_color(&style_type_tdrv_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_type_tdrv_main_main_default, 2);
	lv_style_set_border_opa(&style_type_tdrv_main_main_default, 0);
	lv_style_set_pad_left(&style_type_tdrv_main_main_default, 0);
	lv_style_set_pad_right(&style_type_tdrv_main_main_default, 0);
	lv_style_set_pad_top(&style_type_tdrv_main_main_default, 0);
	lv_style_set_pad_bottom(&style_type_tdrv_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_TDRV, &style_type_tdrv_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_btn_5
	ui->TYPE_btn_5 = lv_btn_create(ui->TYPE_TDRV);
	lv_obj_set_pos(ui->TYPE_btn_5, 261, 1);
	lv_obj_set_size(ui->TYPE_btn_5, 43, 42);
	lv_obj_set_scrollbar_mode(ui->TYPE_btn_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_type_btn_5_main_main_default
	static lv_style_t style_type_btn_5_main_main_default;
	if (style_type_btn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_btn_5_main_main_default);
	else
		lv_style_init(&style_type_btn_5_main_main_default);
	lv_style_set_radius(&style_type_btn_5_main_main_default, 5);
	lv_style_set_bg_color(&style_type_btn_5_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_bg_grad_color(&style_type_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_btn_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_btn_5_main_main_default, 0);
	lv_style_set_shadow_width(&style_type_btn_5_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_btn_5_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_btn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_btn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_btn_5_main_main_default, 0);
	lv_style_set_border_color(&style_type_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_type_btn_5_main_main_default, 0);
	lv_style_set_border_opa(&style_type_btn_5_main_main_default, 255);
	lv_style_set_text_color(&style_type_btn_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_type_btn_5_main_main_default, &lv_font_montserratMedium_36);
	lv_style_set_text_align(&style_type_btn_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->TYPE_btn_5, &style_type_btn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->TYPE_btn_5_label = lv_label_create(ui->TYPE_btn_5);
	lv_label_set_text(ui->TYPE_btn_5_label, "X");
	lv_obj_set_style_pad_all(ui->TYPE_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->TYPE_btn_5_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes TYPE_TDR
	ui->TYPE_TDR = lv_label_create(ui->TYPE_TDRV);
	lv_obj_set_pos(ui->TYPE_TDR, 22, 69);
	lv_obj_set_size(ui->TYPE_TDR, 260, 28);
	lv_obj_set_scrollbar_mode(ui->TYPE_TDR, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_TDR, "DRV");
	lv_label_set_long_mode(ui->TYPE_TDR, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_tdr_main_main_default
	static lv_style_t style_type_tdr_main_main_default;
	if (style_type_tdr_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_tdr_main_main_default);
	else
		lv_style_init(&style_type_tdr_main_main_default);
	lv_style_set_radius(&style_type_tdr_main_main_default, 0);
	lv_style_set_bg_color(&style_type_tdr_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_tdr_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_tdr_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_tdr_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_tdr_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_tdr_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_tdr_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_tdr_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_tdr_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_tdr_main_main_default, 0);
	lv_style_set_text_color(&style_type_tdr_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_tdr_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_tdr_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_tdr_main_main_default, 0);
	lv_style_set_text_align(&style_type_tdr_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_tdr_main_main_default, 0);
	lv_style_set_pad_right(&style_type_tdr_main_main_default, 0);
	lv_style_set_pad_top(&style_type_tdr_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_tdr_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_TDR, &style_type_tdr_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_37
	ui->TYPE_label_37 = lv_label_create(ui->TYPE_TDRV);
	lv_obj_set_pos(ui->TYPE_label_37, 22, 97);
	lv_obj_set_size(ui->TYPE_label_37, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_37, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_37, "TARGET");
	lv_label_set_long_mode(ui->TYPE_label_37, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_37_main_main_default
	static lv_style_t style_type_label_37_main_main_default;
	if (style_type_label_37_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_37_main_main_default);
	else
		lv_style_init(&style_type_label_37_main_main_default);
	lv_style_set_radius(&style_type_label_37_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_37_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_37_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_37_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_37_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_37_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_37_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_37_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_37_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_37_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_37_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_37_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_37_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_37_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_37_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_37_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_37_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_37_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_37_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_37_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_37, &style_type_label_37_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_36
	ui->TYPE_label_36 = lv_label_create(ui->TYPE_TDRV);
	lv_obj_set_pos(ui->TYPE_label_36, 22, 127);
	lv_obj_set_size(ui->TYPE_label_36, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_36, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_36, "I(A)");
	lv_label_set_long_mode(ui->TYPE_label_36, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_36_main_main_default
	static lv_style_t style_type_label_36_main_main_default;
	if (style_type_label_36_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_36_main_main_default);
	else
		lv_style_init(&style_type_label_36_main_main_default);
	lv_style_set_radius(&style_type_label_36_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_36_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_36_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_36_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_36_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_36_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_36_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_36_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_36_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_36_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_36_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_36_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_36_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_36_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_36_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_36_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_36_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_36_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_36_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_36_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_36, &style_type_label_36_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_35
	ui->TYPE_label_35 = lv_label_create(ui->TYPE_TDRV);
	lv_obj_set_pos(ui->TYPE_label_35, 22, 156);
	lv_obj_set_size(ui->TYPE_label_35, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_35, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_35, "V");
	lv_label_set_long_mode(ui->TYPE_label_35, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_35_main_main_default
	static lv_style_t style_type_label_35_main_main_default;
	if (style_type_label_35_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_35_main_main_default);
	else
		lv_style_init(&style_type_label_35_main_main_default);
	lv_style_set_radius(&style_type_label_35_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_35_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_35_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_35_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_35_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_35_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_35_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_35_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_35_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_35_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_35_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_35_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_35_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_35_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_35_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_35_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_35_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_35_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_35_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_35_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_35, &style_type_label_35_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_34
	ui->TYPE_label_34 = lv_label_create(ui->TYPE_TDRV);
	lv_obj_set_pos(ui->TYPE_label_34, 22, 183);
	lv_obj_set_size(ui->TYPE_label_34, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_34, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_34, "POSITION");
	lv_label_set_long_mode(ui->TYPE_label_34, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_34_main_main_default
	static lv_style_t style_type_label_34_main_main_default;
	if (style_type_label_34_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_34_main_main_default);
	else
		lv_style_init(&style_type_label_34_main_main_default);
	lv_style_set_radius(&style_type_label_34_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_34_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_34_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_34_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_34_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_34_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_34_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_34_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_34_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_34_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_34_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_34_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_34_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_34_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_34_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_34_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_34_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_34_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_34_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_34_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_34, &style_type_label_34_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_33
	ui->TYPE_label_33 = lv_label_create(ui->TYPE_TDRV);
	lv_obj_set_pos(ui->TYPE_label_33, 152, 96);
	lv_obj_set_size(ui->TYPE_label_33, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_33, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_33, "Label");
	lv_label_set_long_mode(ui->TYPE_label_33, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_33_main_main_default
	static lv_style_t style_type_label_33_main_main_default;
	if (style_type_label_33_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_33_main_main_default);
	else
		lv_style_init(&style_type_label_33_main_main_default);
	lv_style_set_radius(&style_type_label_33_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_33_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_33_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_33_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_33_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_33_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_33_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_33_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_33_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_33_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_33_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_33_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_33_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_33_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_33_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_33_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_33_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_33_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_33_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_33_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_33, &style_type_label_33_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_32
	ui->TYPE_label_32 = lv_label_create(ui->TYPE_TDRV);
	lv_obj_set_pos(ui->TYPE_label_32, 152, 127);
	lv_obj_set_size(ui->TYPE_label_32, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_32, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_32, "Label");
	lv_label_set_long_mode(ui->TYPE_label_32, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_32_main_main_default
	static lv_style_t style_type_label_32_main_main_default;
	if (style_type_label_32_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_32_main_main_default);
	else
		lv_style_init(&style_type_label_32_main_main_default);
	lv_style_set_radius(&style_type_label_32_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_32_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_32_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_32_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_32_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_32_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_32_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_32_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_32_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_32_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_32_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_32_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_32_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_32_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_32_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_32_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_32_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_32_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_32_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_32_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_32, &style_type_label_32_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_31
	ui->TYPE_label_31 = lv_label_create(ui->TYPE_TDRV);
	lv_obj_set_pos(ui->TYPE_label_31, 152, 155);
	lv_obj_set_size(ui->TYPE_label_31, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_31, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_31, "Label");
	lv_label_set_long_mode(ui->TYPE_label_31, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_31_main_main_default
	static lv_style_t style_type_label_31_main_main_default;
	if (style_type_label_31_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_31_main_main_default);
	else
		lv_style_init(&style_type_label_31_main_main_default);
	lv_style_set_radius(&style_type_label_31_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_31_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_31_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_31_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_31_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_31_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_31_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_31_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_31_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_31_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_31_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_31_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_31_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_31_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_31_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_31_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_31_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_31_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_31_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_31_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_31, &style_type_label_31_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes TYPE_label_30
	ui->TYPE_label_30 = lv_label_create(ui->TYPE_TDRV);
	lv_obj_set_pos(ui->TYPE_label_30, 152, 183);
	lv_obj_set_size(ui->TYPE_label_30, 130, 31);
	lv_obj_set_scrollbar_mode(ui->TYPE_label_30, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->TYPE_label_30, "Label");
	lv_label_set_long_mode(ui->TYPE_label_30, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_type_label_30_main_main_default
	static lv_style_t style_type_label_30_main_main_default;
	if (style_type_label_30_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_type_label_30_main_main_default);
	else
		lv_style_init(&style_type_label_30_main_main_default);
	lv_style_set_radius(&style_type_label_30_main_main_default, 0);
	lv_style_set_bg_color(&style_type_label_30_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_type_label_30_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_type_label_30_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_type_label_30_main_main_default, 255);
	lv_style_set_shadow_width(&style_type_label_30_main_main_default, 0);
	lv_style_set_shadow_color(&style_type_label_30_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_type_label_30_main_main_default, 255);
	lv_style_set_shadow_spread(&style_type_label_30_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_type_label_30_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_type_label_30_main_main_default, 0);
	lv_style_set_text_color(&style_type_label_30_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_type_label_30_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_type_label_30_main_main_default, 2);
	lv_style_set_text_line_space(&style_type_label_30_main_main_default, 0);
	lv_style_set_text_align(&style_type_label_30_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_type_label_30_main_main_default, 0);
	lv_style_set_pad_right(&style_type_label_30_main_main_default, 0);
	lv_style_set_pad_top(&style_type_label_30_main_main_default, 8);
	lv_style_set_pad_bottom(&style_type_label_30_main_main_default, 0);
	lv_obj_add_style(ui->TYPE_label_30, &style_type_label_30_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_TYPE(ui);
}