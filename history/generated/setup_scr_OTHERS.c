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

void setup_scr_OTHERS(lv_ui *ui){

	//Write codes OTHERS
	ui->OTHERS = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->OTHERS, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_others_main_main_default
	static lv_style_t style_others_main_main_default;
	if (style_others_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_others_main_main_default);
	else
		lv_style_init(&style_others_main_main_default);
	lv_style_set_bg_color(&style_others_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_others_main_main_default, 0);
	lv_obj_add_style(ui->OTHERS, &style_others_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes OTHERS_tabview_1
	ui->OTHERS_tabview_1 = lv_tabview_create(ui->OTHERS, LV_DIR_TOP, 50);
	lv_obj_set_pos(ui->OTHERS_tabview_1, 15, 83);
	lv_obj_set_size(ui->OTHERS_tabview_1, 291, 327);

	//MPU
	ui->OTHERS_tabview_1_MPU = lv_tabview_add_tab(ui->OTHERS_tabview_1,"MPU");
	lv_obj_t * OTHERS_tabview_1_MPU_label = lv_label_create(ui->OTHERS_tabview_1_MPU);
	lv_label_set_text(OTHERS_tabview_1_MPU_label, "MPU");

	//APR
	ui->OTHERS_tabview_1_APR = lv_tabview_add_tab(ui->OTHERS_tabview_1,"APR");
	lv_obj_t * OTHERS_tabview_1_APR_label = lv_label_create(ui->OTHERS_tabview_1_APR);
	lv_label_set_text(OTHERS_tabview_1_APR_label, "Air Pressure");

	//MEN
	ui->OTHERS_tabview_1_MEN = lv_tabview_add_tab(ui->OTHERS_tabview_1,"MEN");
	lv_obj_t * OTHERS_tabview_1_MEN_label = lv_label_create(ui->OTHERS_tabview_1_MEN);
	lv_label_set_text(OTHERS_tabview_1_MEN_label, "Menory");

	//OTHER
	ui->OTHERS_tabview_1_OTHER = lv_tabview_add_tab(ui->OTHERS_tabview_1,"OTHER");
	lv_obj_t * OTHERS_tabview_1_OTHER_label = lv_label_create(ui->OTHERS_tabview_1_OTHER);
	lv_label_set_text(OTHERS_tabview_1_OTHER_label, "Others");


	//Write style state: LV_STATE_DEFAULT for style_others_tabview_1_main_main_default
	static lv_style_t style_others_tabview_1_main_main_default;
	if (style_others_tabview_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_others_tabview_1_main_main_default);
	else
		lv_style_init(&style_others_tabview_1_main_main_default);
	lv_style_set_radius(&style_others_tabview_1_main_main_default, 0);
	lv_style_set_bg_color(&style_others_tabview_1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_others_tabview_1_main_main_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_others_tabview_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_others_tabview_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_others_tabview_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_others_tabview_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_others_tabview_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_others_tabview_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_others_tabview_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_others_tabview_1_main_main_default, 0);
	lv_style_set_border_color(&style_others_tabview_1_main_main_default, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_others_tabview_1_main_main_default, 0);
	lv_style_set_border_opa(&style_others_tabview_1_main_main_default, 100);
	lv_style_set_text_color(&style_others_tabview_1_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_others_tabview_1_main_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_letter_space(&style_others_tabview_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_others_tabview_1_main_main_default, 16);
	lv_obj_add_style(ui->OTHERS_tabview_1, &style_others_tabview_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_others_tabview_1_extra_btnm_main_default
	static lv_style_t style_others_tabview_1_extra_btnm_main_default;
	if (style_others_tabview_1_extra_btnm_main_default.prop_cnt > 1)
		lv_style_reset(&style_others_tabview_1_extra_btnm_main_default);
	else
		lv_style_init(&style_others_tabview_1_extra_btnm_main_default);
	lv_style_set_radius(&style_others_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_bg_color(&style_others_tabview_1_extra_btnm_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_others_tabview_1_extra_btnm_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_others_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_others_tabview_1_extra_btnm_main_default, 255);
	lv_style_set_border_color(&style_others_tabview_1_extra_btnm_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_others_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_border_opa(&style_others_tabview_1_extra_btnm_main_default, 100);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->OTHERS_tabview_1), &style_others_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_others_tabview_1_extra_btnm_items_default
	static lv_style_t style_others_tabview_1_extra_btnm_items_default;
	if (style_others_tabview_1_extra_btnm_items_default.prop_cnt > 1)
		lv_style_reset(&style_others_tabview_1_extra_btnm_items_default);
	else
		lv_style_init(&style_others_tabview_1_extra_btnm_items_default);
	lv_style_set_text_color(&style_others_tabview_1_extra_btnm_items_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_others_tabview_1_extra_btnm_items_default, &lv_font_montserratMedium_12);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->OTHERS_tabview_1), &style_others_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_others_tabview_1_extra_btnm_items_checked
	static lv_style_t style_others_tabview_1_extra_btnm_items_checked;
	if (style_others_tabview_1_extra_btnm_items_checked.prop_cnt > 1)
		lv_style_reset(&style_others_tabview_1_extra_btnm_items_checked);
	else
		lv_style_init(&style_others_tabview_1_extra_btnm_items_checked);
	lv_style_set_radius(&style_others_tabview_1_extra_btnm_items_checked, 0);
	lv_style_set_bg_color(&style_others_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_others_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_others_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_others_tabview_1_extra_btnm_items_checked, 60);
	lv_style_set_border_color(&style_others_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_others_tabview_1_extra_btnm_items_checked, 4);
	lv_style_set_border_opa(&style_others_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_side(&style_others_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_text_color(&style_others_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_text_font(&style_others_tabview_1_extra_btnm_items_checked, &lv_font_montserratMedium_12);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->OTHERS_tabview_1), &style_others_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

	//Write codes OTHERS_btn_1
	ui->OTHERS_btn_1 = lv_btn_create(ui->OTHERS);
	lv_obj_set_pos(ui->OTHERS_btn_1, 266, -7);
	lv_obj_set_size(ui->OTHERS_btn_1, 50, 50);
	lv_obj_set_scrollbar_mode(ui->OTHERS_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_others_btn_1_main_main_default
	static lv_style_t style_others_btn_1_main_main_default;
	if (style_others_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_others_btn_1_main_main_default);
	else
		lv_style_init(&style_others_btn_1_main_main_default);
	lv_style_set_radius(&style_others_btn_1_main_main_default, 5);
	lv_style_set_bg_color(&style_others_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_others_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_others_btn_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_others_btn_1_main_main_default, 0);
	lv_style_set_shadow_width(&style_others_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_others_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_others_btn_1_main_main_default, 0);
	lv_style_set_shadow_spread(&style_others_btn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_others_btn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_others_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_others_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_others_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_others_btn_1_main_main_default, 0);
	lv_style_set_text_color(&style_others_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_others_btn_1_main_main_default, &lv_font_montserratMedium_36);
	lv_style_set_text_align(&style_others_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->OTHERS_btn_1, &style_others_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->OTHERS_btn_1_label = lv_label_create(ui->OTHERS_btn_1);
	lv_label_set_text(ui->OTHERS_btn_1_label, "X");
	lv_obj_set_style_pad_all(ui->OTHERS_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->OTHERS_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes OTHERS_label_1
	ui->OTHERS_label_1 = lv_label_create(ui->OTHERS);
	lv_obj_set_pos(ui->OTHERS_label_1, 0, 0);
	lv_obj_set_size(ui->OTHERS_label_1, 260, 35);
	lv_obj_set_scrollbar_mode(ui->OTHERS_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->OTHERS_label_1, "Label");
	lv_label_set_long_mode(ui->OTHERS_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_others_label_1_main_main_default
	static lv_style_t style_others_label_1_main_main_default;
	if (style_others_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_others_label_1_main_main_default);
	else
		lv_style_init(&style_others_label_1_main_main_default);
	lv_style_set_radius(&style_others_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_others_label_1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_others_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_others_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_others_label_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_others_label_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_others_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_others_label_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_others_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_others_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_others_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_others_label_1_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_others_label_1_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_others_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_others_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_others_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_others_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_others_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_others_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_others_label_1_main_main_default, 0);
	lv_obj_add_style(ui->OTHERS_label_1, &style_others_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_OTHERS(ui);
}