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
static lv_obj_t * g_kb_WIFI;
static void kb_WIFI_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *kb = lv_event_get_target(e);
	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}
static void ta_WIFI_event_cb(lv_event_t *e)
{

	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *ta = lv_event_get_target(e);
	lv_obj_t *kb = lv_event_get_user_data(e);
	if (code == LV_EVENT_FOCUSED)
	{
		lv_keyboard_set_textarea(kb, ta);
		lv_obj_move_foreground(kb);
		lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
	if (code == LV_EVENT_CANCEL)
	{
		lv_keyboard_set_textarea(kb, NULL);
		lv_obj_move_background(kb);
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}

void setup_scr_WIFI(lv_ui *ui){

	//Write codes WIFI
	ui->WIFI = lv_obj_create(NULL);

	//Create keyboard on WIFI
	g_kb_WIFI = lv_keyboard_create(ui->WIFI);
	lv_obj_add_event_cb(g_kb_WIFI, kb_WIFI_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb_WIFI, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_scrollbar_mode(ui->WIFI, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_wifi_main_main_default
	static lv_style_t style_wifi_main_main_default;
	if (style_wifi_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_main_main_default);
	else
		lv_style_init(&style_wifi_main_main_default);
	lv_style_set_bg_color(&style_wifi_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_wifi_main_main_default, 0);
	lv_obj_add_style(ui->WIFI, &style_wifi_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes WIFI_btn_1
	ui->WIFI_btn_1 = lv_btn_create(ui->WIFI);
	lv_obj_set_pos(ui->WIFI_btn_1, 279, 1);
	lv_obj_set_size(ui->WIFI_btn_1, 37, 49);
	lv_obj_set_scrollbar_mode(ui->WIFI_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_wifi_btn_1_main_main_default
	static lv_style_t style_wifi_btn_1_main_main_default;
	if (style_wifi_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_btn_1_main_main_default);
	else
		lv_style_init(&style_wifi_btn_1_main_main_default);
	lv_style_set_radius(&style_wifi_btn_1_main_main_default, 5);
	lv_style_set_bg_color(&style_wifi_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_wifi_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_btn_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_btn_1_main_main_default, 0);
	lv_style_set_shadow_width(&style_wifi_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_wifi_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_btn_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_wifi_btn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_btn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_wifi_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_wifi_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_wifi_btn_1_main_main_default, 255);
	lv_style_set_text_color(&style_wifi_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_wifi_btn_1_main_main_default, &lv_font_montserratMedium_36);
	lv_style_set_text_align(&style_wifi_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->WIFI_btn_1, &style_wifi_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->WIFI_btn_1_label = lv_label_create(ui->WIFI_btn_1);
	lv_label_set_text(ui->WIFI_btn_1_label, "X");
	lv_obj_set_style_pad_all(ui->WIFI_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->WIFI_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes WIFI_label_1
	ui->WIFI_label_1 = lv_label_create(ui->WIFI);
	lv_obj_set_pos(ui->WIFI_label_1, 41, 115);
	lv_obj_set_size(ui->WIFI_label_1, 100, 32);
	lv_obj_set_scrollbar_mode(ui->WIFI_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->WIFI_label_1, "name");
	lv_label_set_long_mode(ui->WIFI_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_wifi_label_1_main_main_default
	static lv_style_t style_wifi_label_1_main_main_default;
	if (style_wifi_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_label_1_main_main_default);
	else
		lv_style_init(&style_wifi_label_1_main_main_default);
	lv_style_set_radius(&style_wifi_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_wifi_label_1_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_wifi_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_label_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_wifi_label_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_wifi_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_label_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_wifi_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_wifi_label_1_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_wifi_label_1_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_wifi_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_wifi_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_wifi_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_wifi_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_wifi_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_wifi_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_wifi_label_1_main_main_default, 0);
	lv_obj_add_style(ui->WIFI_label_1, &style_wifi_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes WIFI_name
	ui->WIFI_name = lv_textarea_create(ui->WIFI);
	lv_obj_set_pos(ui->WIFI_name, 151, 114);
	lv_obj_set_size(ui->WIFI_name, 144, 33);
	lv_obj_set_scrollbar_mode(ui->WIFI_name, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_wifi_name_main_main_default
	static lv_style_t style_wifi_name_main_main_default;
	if (style_wifi_name_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_name_main_main_default);
	else
		lv_style_init(&style_wifi_name_main_main_default);
	lv_style_set_radius(&style_wifi_name_main_main_default, 4);
	lv_style_set_bg_color(&style_wifi_name_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_wifi_name_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_wifi_name_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_name_main_main_default, 255);
	lv_style_set_shadow_width(&style_wifi_name_main_main_default, 0);
	lv_style_set_shadow_color(&style_wifi_name_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_name_main_main_default, 255);
	lv_style_set_shadow_spread(&style_wifi_name_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_name_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_name_main_main_default, 0);
	lv_style_set_border_color(&style_wifi_name_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_wifi_name_main_main_default, 2);
	lv_style_set_border_opa(&style_wifi_name_main_main_default, 255);
	lv_style_set_text_color(&style_wifi_name_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_wifi_name_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_wifi_name_main_main_default, 2);
	lv_style_set_text_align(&style_wifi_name_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_wifi_name_main_main_default, 4);
	lv_style_set_pad_right(&style_wifi_name_main_main_default, 4);
	lv_style_set_pad_top(&style_wifi_name_main_main_default, 4);
	lv_style_set_pad_bottom(&style_wifi_name_main_main_default, 4);
	lv_obj_add_style(ui->WIFI_name, &style_wifi_name_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_wifi_name_main_scrollbar_default
	static lv_style_t style_wifi_name_main_scrollbar_default;
	if (style_wifi_name_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_name_main_scrollbar_default);
	else
		lv_style_init(&style_wifi_name_main_scrollbar_default);
	lv_style_set_radius(&style_wifi_name_main_scrollbar_default, 0);
	lv_style_set_bg_color(&style_wifi_name_main_scrollbar_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_opa(&style_wifi_name_main_scrollbar_default, 255);
	lv_obj_add_style(ui->WIFI_name, &style_wifi_name_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_textarea_set_text(ui->WIFI_name,"DengsFos");

	//use keyboard on WIFI_name
	lv_obj_add_event_cb(ui->WIFI_name, ta_WIFI_event_cb, LV_EVENT_ALL, g_kb_WIFI);

	//Write codes WIFI_label_2
	ui->WIFI_label_2 = lv_label_create(ui->WIFI);
	lv_obj_set_pos(ui->WIFI_label_2, 41, 154);
	lv_obj_set_size(ui->WIFI_label_2, 100, 32);
	lv_obj_set_scrollbar_mode(ui->WIFI_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->WIFI_label_2, "passward");
	lv_label_set_long_mode(ui->WIFI_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_wifi_label_2_main_main_default
	static lv_style_t style_wifi_label_2_main_main_default;
	if (style_wifi_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_label_2_main_main_default);
	else
		lv_style_init(&style_wifi_label_2_main_main_default);
	lv_style_set_radius(&style_wifi_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_wifi_label_2_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_wifi_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_label_2_main_main_default, 255);
	lv_style_set_shadow_width(&style_wifi_label_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_wifi_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_label_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_wifi_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_wifi_label_2_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_wifi_label_2_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_wifi_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_wifi_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_wifi_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_wifi_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_wifi_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_wifi_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_wifi_label_2_main_main_default, 0);
	lv_obj_add_style(ui->WIFI_label_2, &style_wifi_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes WIFI_passward
	ui->WIFI_passward = lv_textarea_create(ui->WIFI);
	lv_obj_set_pos(ui->WIFI_passward, 151, 153);
	lv_obj_set_size(ui->WIFI_passward, 144, 33);
	lv_obj_set_scrollbar_mode(ui->WIFI_passward, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_wifi_passward_main_main_default
	static lv_style_t style_wifi_passward_main_main_default;
	if (style_wifi_passward_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_passward_main_main_default);
	else
		lv_style_init(&style_wifi_passward_main_main_default);
	lv_style_set_radius(&style_wifi_passward_main_main_default, 4);
	lv_style_set_bg_color(&style_wifi_passward_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_wifi_passward_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_wifi_passward_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_passward_main_main_default, 255);
	lv_style_set_shadow_width(&style_wifi_passward_main_main_default, 0);
	lv_style_set_shadow_color(&style_wifi_passward_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_passward_main_main_default, 255);
	lv_style_set_shadow_spread(&style_wifi_passward_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_passward_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_passward_main_main_default, 0);
	lv_style_set_border_color(&style_wifi_passward_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_wifi_passward_main_main_default, 2);
	lv_style_set_border_opa(&style_wifi_passward_main_main_default, 255);
	lv_style_set_text_color(&style_wifi_passward_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_wifi_passward_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_wifi_passward_main_main_default, 2);
	lv_style_set_text_align(&style_wifi_passward_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_wifi_passward_main_main_default, 4);
	lv_style_set_pad_right(&style_wifi_passward_main_main_default, 4);
	lv_style_set_pad_top(&style_wifi_passward_main_main_default, 4);
	lv_style_set_pad_bottom(&style_wifi_passward_main_main_default, 4);
	lv_obj_add_style(ui->WIFI_passward, &style_wifi_passward_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_wifi_passward_main_scrollbar_default
	static lv_style_t style_wifi_passward_main_scrollbar_default;
	if (style_wifi_passward_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_passward_main_scrollbar_default);
	else
		lv_style_init(&style_wifi_passward_main_scrollbar_default);
	lv_style_set_radius(&style_wifi_passward_main_scrollbar_default, 0);
	lv_style_set_bg_color(&style_wifi_passward_main_scrollbar_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_opa(&style_wifi_passward_main_scrollbar_default, 255);
	lv_obj_add_style(ui->WIFI_passward, &style_wifi_passward_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_textarea_set_text(ui->WIFI_passward,"DengsFos");

	//use keyboard on WIFI_passward
	lv_obj_add_event_cb(ui->WIFI_passward, ta_WIFI_event_cb, LV_EVENT_ALL, g_kb_WIFI);

	//Write codes WIFI_btn_2
	ui->WIFI_btn_2 = lv_btn_create(ui->WIFI);
	lv_obj_set_pos(ui->WIFI_btn_2, 110, 224);
	lv_obj_set_size(ui->WIFI_btn_2, 100, 50);
	lv_obj_set_scrollbar_mode(ui->WIFI_btn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_wifi_btn_2_main_main_default
	static lv_style_t style_wifi_btn_2_main_main_default;
	if (style_wifi_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_btn_2_main_main_default);
	else
		lv_style_init(&style_wifi_btn_2_main_main_default);
	lv_style_set_radius(&style_wifi_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_wifi_btn_2_main_main_default, lv_color_make(0x97, 0xe7, 0xff));
	lv_style_set_bg_grad_color(&style_wifi_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_btn_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_btn_2_main_main_default, 255);
	lv_style_set_shadow_width(&style_wifi_btn_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_wifi_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_btn_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_wifi_btn_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_btn_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_wifi_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_wifi_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_wifi_btn_2_main_main_default, 255);
	lv_style_set_text_color(&style_wifi_btn_2_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_text_font(&style_wifi_btn_2_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_wifi_btn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->WIFI_btn_2, &style_wifi_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->WIFI_btn_2_label = lv_label_create(ui->WIFI_btn_2);
	lv_label_set_text(ui->WIFI_btn_2_label, "Connect");
	lv_obj_set_style_pad_all(ui->WIFI_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->WIFI_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Init events for screen
	events_init_WIFI(ui);
}