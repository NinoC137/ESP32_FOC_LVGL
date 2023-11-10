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


void setup_scr_MAIN(lv_ui *ui){

	//Write codes MAIN
	ui->MAIN = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->MAIN, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_main_main_main_default
	static lv_style_t style_main_main_main_default;
	if (style_main_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_main_main_default);
	else
		lv_style_init(&style_main_main_main_default);
	lv_style_set_bg_color(&style_main_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_main_main_main_default, 0);
	lv_obj_add_style(ui->MAIN, &style_main_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MAIN_cont_1
	ui->MAIN_cont_1 = lv_obj_create(ui->MAIN);
	lv_obj_set_pos(ui->MAIN_cont_1, 0, 0);
	lv_obj_set_size(ui->MAIN_cont_1, 320, 480);
	lv_obj_set_scrollbar_mode(ui->MAIN_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_main_cont_1_main_main_default
	static lv_style_t style_main_cont_1_main_main_default;
	if (style_main_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_cont_1_main_main_default);
	else
		lv_style_init(&style_main_cont_1_main_main_default);
	lv_style_set_radius(&style_main_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_main_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_main_cont_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_main_cont_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_main_cont_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_main_cont_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_main_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_main_cont_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_main_cont_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_main_cont_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_main_cont_1_main_main_default, 0);
	lv_style_set_border_color(&style_main_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_main_cont_1_main_main_default, 2);
	lv_style_set_border_opa(&style_main_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_main_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_main_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_main_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_main_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->MAIN_cont_1, &style_main_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes MAIN_btn_1
	ui->MAIN_btn_1 = lv_btn_create(ui->MAIN_cont_1);
	lv_obj_set_pos(ui->MAIN_btn_1, 29, 166);
	lv_obj_set_size(ui->MAIN_btn_1, 253, 171);
	lv_obj_set_scrollbar_mode(ui->MAIN_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_main_btn_1_main_main_default
	static lv_style_t style_main_btn_1_main_main_default;
	if (style_main_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_btn_1_main_main_default);
	else
		lv_style_init(&style_main_btn_1_main_main_default);
	lv_style_set_radius(&style_main_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_main_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_main_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_main_btn_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_main_btn_1_main_main_default, 0);
	lv_style_set_shadow_width(&style_main_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_main_btn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_shadow_opa(&style_main_btn_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_main_btn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_main_btn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_main_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_main_btn_1_main_main_default, lv_color_make(0xdc, 0xdc, 0xdc));
	lv_style_set_border_width(&style_main_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_main_btn_1_main_main_default, 95);
	lv_style_set_text_color(&style_main_btn_1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_text_font(&style_main_btn_1_main_main_default, &lv_font_montserratMedium_24);
	lv_style_set_text_align(&style_main_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->MAIN_btn_1, &style_main_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->MAIN_btn_1_label = lv_label_create(ui->MAIN_btn_1);
	lv_label_set_text(ui->MAIN_btn_1_label, "signin");
	lv_obj_set_style_pad_all(ui->MAIN_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->MAIN_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes MAIN_label_1
	ui->MAIN_label_1 = lv_label_create(ui->MAIN_cont_1);
	lv_obj_set_pos(ui->MAIN_label_1, 69, 164);
	lv_obj_set_size(ui->MAIN_label_1, 181, 51);
	lv_obj_set_scrollbar_mode(ui->MAIN_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->MAIN_label_1, "DengsFoc");
	lv_label_set_long_mode(ui->MAIN_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_main_label_1_main_main_default
	static lv_style_t style_main_label_1_main_main_default;
	if (style_main_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_label_1_main_main_default);
	else
		lv_style_init(&style_main_label_1_main_main_default);
	lv_style_set_radius(&style_main_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_main_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_main_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_main_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_main_label_1_main_main_default, 0);
	lv_style_set_shadow_width(&style_main_label_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_main_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_main_label_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_main_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_main_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_main_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_main_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_main_label_1_main_main_default, &lv_font_montserratMedium_26);
	lv_style_set_text_letter_space(&style_main_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_main_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_main_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_main_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_main_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_main_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_main_label_1_main_main_default, 0);
	lv_obj_add_style(ui->MAIN_label_1, &style_main_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_MAIN(ui);
}