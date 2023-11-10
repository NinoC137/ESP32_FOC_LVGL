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
double realtime=0.0;


static lv_obj_t * g_kb_SEM1;
static void kb_SEM1_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *kb = lv_event_get_target(e);
	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}
static void ta_SEM1_event_cb(lv_event_t *e)
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

void setup_scr_SEM1(lv_ui *ui){

	//Write codes SEM1
	ui->SEM1 = lv_obj_create(NULL);

	//Create keyboard on SEM1
	g_kb_SEM1 = lv_keyboard_create(ui->SEM1);
	lv_obj_add_event_cb(g_kb_SEM1, kb_SEM1_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb_SEM1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_scrollbar_mode(ui->SEM1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_main_main_default
	static lv_style_t style_sem1_main_main_default;
	if (style_sem1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_main_main_default);
	else
		lv_style_init(&style_sem1_main_main_default);
	lv_style_set_bg_color(&style_sem1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_sem1_main_main_default, 0);
	lv_obj_add_style(ui->SEM1, &style_sem1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes SEM1_cont_2
	ui->SEM1_cont_2 = lv_obj_create(ui->SEM1);
	lv_obj_set_pos(ui->SEM1_cont_2, 0, 0);
	lv_obj_set_size(ui->SEM1_cont_2, 320, 480);
	lv_obj_set_scrollbar_mode(ui->SEM1_cont_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_cont_2_main_main_default
	static lv_style_t style_sem1_cont_2_main_main_default;
	if (style_sem1_cont_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_cont_2_main_main_default);
	else
		lv_style_init(&style_sem1_cont_2_main_main_default);
	lv_style_set_radius(&style_sem1_cont_2_main_main_default, 0);
	lv_style_set_bg_color(&style_sem1_cont_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_sem1_cont_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_sem1_cont_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_cont_2_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_cont_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_cont_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_cont_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_cont_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_cont_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_cont_2_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_cont_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_cont_2_main_main_default, 2);
	lv_style_set_border_opa(&style_sem1_cont_2_main_main_default, 0);
	lv_style_set_pad_left(&style_sem1_cont_2_main_main_default, 0);
	lv_style_set_pad_right(&style_sem1_cont_2_main_main_default, 0);
	lv_style_set_pad_top(&style_sem1_cont_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sem1_cont_2_main_main_default, 0);
	lv_obj_add_style(ui->SEM1_cont_2, &style_sem1_cont_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes SEM1_win_1
	ui->SEM1_win_1 = lv_win_create(ui->SEM1_cont_2, 40);
	lv_win_add_title(ui->SEM1_win_1, "some details");
	lv_obj_set_pos(ui->SEM1_win_1, 21, 173);
	lv_obj_set_size(ui->SEM1_win_1, 277, 242);

	//Write style state: LV_STATE_DEFAULT for style_sem1_win_1_main_main_default
	static lv_style_t style_sem1_win_1_main_main_default;
	if (style_sem1_win_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_win_1_main_main_default);
	else
		lv_style_init(&style_sem1_win_1_main_main_default);
	lv_style_set_bg_color(&style_sem1_win_1_main_main_default, lv_color_make(0xee, 0xee, 0xf6));
	lv_style_set_bg_grad_color(&style_sem1_win_1_main_main_default, lv_color_make(0xee, 0xee, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_win_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_win_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_win_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_win_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_win_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_win_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_win_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_win_1_main_main_default, 0);
	lv_style_set_outline_color(&style_sem1_win_1_main_main_default, lv_color_make(0x08, 0x1A, 0x0F));
	lv_style_set_outline_width(&style_sem1_win_1_main_main_default, 0);
	lv_style_set_outline_opa(&style_sem1_win_1_main_main_default, 255);
	lv_obj_add_style(ui->SEM1_win_1, &style_sem1_win_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_sem1_win_1_extra_content_main_default
	static lv_style_t style_sem1_win_1_extra_content_main_default;
	if (style_sem1_win_1_extra_content_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_win_1_extra_content_main_default);
	else
		lv_style_init(&style_sem1_win_1_extra_content_main_default);
	lv_style_set_bg_color(&style_sem1_win_1_extra_content_main_default, lv_color_make(0xee, 0xee, 0xf6));
	lv_style_set_bg_grad_color(&style_sem1_win_1_extra_content_main_default, lv_color_make(0xee, 0xee, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_win_1_extra_content_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_win_1_extra_content_main_default, 255);
	lv_style_set_text_color(&style_sem1_win_1_extra_content_main_default, lv_color_make(0x39, 0x3c, 0x41));
	lv_style_set_text_font(&style_sem1_win_1_extra_content_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_letter_space(&style_sem1_win_1_extra_content_main_default, 0);
	lv_style_set_text_line_space(&style_sem1_win_1_extra_content_main_default, 2);
	lv_obj_add_style(lv_win_get_content(ui->SEM1_win_1), &style_sem1_win_1_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_sem1_win_1_extra_header_main_default
	static lv_style_t style_sem1_win_1_extra_header_main_default;
	if (style_sem1_win_1_extra_header_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_win_1_extra_header_main_default);
	else
		lv_style_init(&style_sem1_win_1_extra_header_main_default);
	lv_style_set_bg_color(&style_sem1_win_1_extra_header_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_sem1_win_1_extra_header_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_dir(&style_sem1_win_1_extra_header_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_win_1_extra_header_main_default, 255);
	lv_style_set_text_color(&style_sem1_win_1_extra_header_main_default, lv_color_make(0x39, 0x3c, 0x41));
	lv_style_set_text_font(&style_sem1_win_1_extra_header_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_letter_space(&style_sem1_win_1_extra_header_main_default, 0);
	lv_style_set_text_line_space(&style_sem1_win_1_extra_header_main_default, 2);
	lv_obj_add_style(lv_win_get_header(ui->SEM1_win_1), &style_sem1_win_1_extra_header_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_sem1_win_1_extra_btns_main_default
	static lv_style_t style_sem1_win_1_extra_btns_main_default;
	if (style_sem1_win_1_extra_btns_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_win_1_extra_btns_main_default);
	else
		lv_style_init(&style_sem1_win_1_extra_btns_main_default);
	lv_style_set_radius(&style_sem1_win_1_extra_btns_main_default, 8);
	lv_style_set_bg_color(&style_sem1_win_1_extra_btns_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sem1_win_1_extra_btns_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_win_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_win_1_extra_btns_main_default, 255);

	lv_obj_t *SEM1_win_1_item;
	lv_obj_t *SEM1_win_1_label = lv_label_create(lv_win_get_content(ui->SEM1_win_1));
	
	lv_label_set_text(SEM1_win_1_label, "this is a \nlong text \nto show \nscrollbar. \nif \nit \nis not \nlong enough, \nadd more content");
    //lv_label_set_text_fmt(SEM1_win_1_label,"",);
	//Write codes SEM1_cont_1
	ui->SEM1_cont_1 = lv_obj_create(ui->SEM1);
	lv_obj_set_pos(ui->SEM1_cont_1, -320, 230);
	lv_obj_set_size(ui->SEM1_cont_1, 320, 250);
	lv_obj_set_scrollbar_mode(ui->SEM1_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_cont_1_main_main_default
	static lv_style_t style_sem1_cont_1_main_main_default;
	if (style_sem1_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_cont_1_main_main_default);
	else
		lv_style_init(&style_sem1_cont_1_main_main_default);
	lv_style_set_radius(&style_sem1_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sem1_cont_1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_sem1_cont_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_sem1_cont_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_cont_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_cont_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_cont_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_cont_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_cont_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_cont_1_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_cont_1_main_main_default, 2);
	lv_style_set_border_opa(&style_sem1_cont_1_main_main_default, 0);
	lv_style_set_pad_left(&style_sem1_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sem1_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sem1_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sem1_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->SEM1_cont_1, &style_sem1_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes SEM1_BTN0
	ui->SEM1_BTN0 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_BTN0, 30, 190);
	lv_obj_set_size(ui->SEM1_BTN0, 110, 50);
	lv_obj_set_scrollbar_mode(ui->SEM1_BTN0, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn0_main_main_default
	static lv_style_t style_sem1_btn0_main_main_default;
	if (style_sem1_btn0_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn0_main_main_default);
	else
		lv_style_init(&style_sem1_btn0_main_main_default);
	lv_style_set_radius(&style_sem1_btn0_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn0_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_sem1_btn0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn0_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn0_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn0_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn0_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn0_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn0_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn0_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn0_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn0_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_btn0_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn0_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_sem1_btn0_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_BTN0, &style_sem1_btn0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_BTN0_label = lv_label_create(ui->SEM1_BTN0);
	lv_label_set_text(ui->SEM1_BTN0_label, "0");
	lv_obj_set_style_pad_all(ui->SEM1_BTN0, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_BTN0_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_btn_3
	ui->SEM1_btn_3 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_btn_3, 30, 10);
	lv_obj_set_size(ui->SEM1_btn_3, 50, 50);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_3_main_main_default
	static lv_style_t style_sem1_btn_3_main_main_default;
	if (style_sem1_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_3_main_main_default);
	else
		lv_style_init(&style_sem1_btn_3_main_main_default);
	lv_style_set_radius(&style_sem1_btn_3_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_3_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_sem1_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_3_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_3_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_3_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_3_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_3_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_3_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_btn_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn_3_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_sem1_btn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_3, &style_sem1_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_3_label = lv_label_create(ui->SEM1_btn_3);
	lv_label_set_text(ui->SEM1_btn_3_label, "7");
	lv_obj_set_style_pad_all(ui->SEM1_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_btn_4
	ui->SEM1_btn_4 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_btn_4, 90, 10);
	lv_obj_set_size(ui->SEM1_btn_4, 50, 50);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_4_main_main_default
	static lv_style_t style_sem1_btn_4_main_main_default;
	if (style_sem1_btn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_4_main_main_default);
	else
		lv_style_init(&style_sem1_btn_4_main_main_default);
	lv_style_set_radius(&style_sem1_btn_4_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_4_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_sem1_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_4_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_4_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_4_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_4_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_4_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_4_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_4_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_4_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_btn_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn_4_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_sem1_btn_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_4, &style_sem1_btn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_4_label = lv_label_create(ui->SEM1_btn_4);
	lv_label_set_text(ui->SEM1_btn_4_label, "8");
	lv_obj_set_style_pad_all(ui->SEM1_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_4_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_btn_5
	ui->SEM1_btn_5 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_btn_5, 150, 10);
	lv_obj_set_size(ui->SEM1_btn_5, 50, 50);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_5_main_main_default
	static lv_style_t style_sem1_btn_5_main_main_default;
	if (style_sem1_btn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_5_main_main_default);
	else
		lv_style_init(&style_sem1_btn_5_main_main_default);
	lv_style_set_radius(&style_sem1_btn_5_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_5_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_sem1_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_5_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_5_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_5_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_5_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_5_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_5_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_btn_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn_5_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_sem1_btn_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_5, &style_sem1_btn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_5_label = lv_label_create(ui->SEM1_btn_5);
	lv_label_set_text(ui->SEM1_btn_5_label, "9");
	lv_obj_set_style_pad_all(ui->SEM1_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_5_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_btn_6
	ui->SEM1_btn_6 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_btn_6, 30, 70);
	lv_obj_set_size(ui->SEM1_btn_6, 50, 50);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_6_main_main_default
	static lv_style_t style_sem1_btn_6_main_main_default;
	if (style_sem1_btn_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_6_main_main_default);
	else
		lv_style_init(&style_sem1_btn_6_main_main_default);
	lv_style_set_radius(&style_sem1_btn_6_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_6_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_sem1_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_6_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_6_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_6_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_6_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_6_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_6_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_6_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_6_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_btn_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn_6_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_sem1_btn_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_6, &style_sem1_btn_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_6_label = lv_label_create(ui->SEM1_btn_6);
	lv_label_set_text(ui->SEM1_btn_6_label, "4");
	lv_obj_set_style_pad_all(ui->SEM1_btn_6, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_6_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_btn_7
	ui->SEM1_btn_7 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_btn_7, 90, 70);
	lv_obj_set_size(ui->SEM1_btn_7, 50, 50);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_7, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_7_main_main_default
	static lv_style_t style_sem1_btn_7_main_main_default;
	if (style_sem1_btn_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_7_main_main_default);
	else
		lv_style_init(&style_sem1_btn_7_main_main_default);
	lv_style_set_radius(&style_sem1_btn_7_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_7_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_sem1_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_7_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_7_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_7_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_7_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_7_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_7_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_7_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_7_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_btn_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn_7_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_sem1_btn_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_7, &style_sem1_btn_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_7_label = lv_label_create(ui->SEM1_btn_7);
	lv_label_set_text(ui->SEM1_btn_7_label, "5");
	lv_obj_set_style_pad_all(ui->SEM1_btn_7, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_7_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_btn_8
	ui->SEM1_btn_8 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_btn_8, 30, 130);
	lv_obj_set_size(ui->SEM1_btn_8, 50, 50);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_8, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_8_main_main_default
	static lv_style_t style_sem1_btn_8_main_main_default;
	if (style_sem1_btn_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_8_main_main_default);
	else
		lv_style_init(&style_sem1_btn_8_main_main_default);
	lv_style_set_radius(&style_sem1_btn_8_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_8_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_sem1_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_8_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_8_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_8_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_8_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_8_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_8_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_8_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_8_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_btn_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn_8_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_sem1_btn_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_8, &style_sem1_btn_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_8_label = lv_label_create(ui->SEM1_btn_8);
	lv_label_set_text(ui->SEM1_btn_8_label, "1");
	lv_obj_set_style_pad_all(ui->SEM1_btn_8, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_8_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_btn_9
	ui->SEM1_btn_9 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_btn_9, 150, 70);
	lv_obj_set_size(ui->SEM1_btn_9, 50, 50);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_9, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_9_main_main_default
	static lv_style_t style_sem1_btn_9_main_main_default;
	if (style_sem1_btn_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_9_main_main_default);
	else
		lv_style_init(&style_sem1_btn_9_main_main_default);
	lv_style_set_radius(&style_sem1_btn_9_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_9_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_sem1_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_9_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_9_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_9_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_9_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_9_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_9_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_9_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_9_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_btn_9_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn_9_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_sem1_btn_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_9, &style_sem1_btn_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_9_label = lv_label_create(ui->SEM1_btn_9);
	lv_label_set_text(ui->SEM1_btn_9_label, "6");
	lv_obj_set_style_pad_all(ui->SEM1_btn_9, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_9_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_btn_10
	ui->SEM1_btn_10 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_btn_10, 90, 130);
	lv_obj_set_size(ui->SEM1_btn_10, 50, 50);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_10, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_10_main_main_default
	static lv_style_t style_sem1_btn_10_main_main_default;
	if (style_sem1_btn_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_10_main_main_default);
	else
		lv_style_init(&style_sem1_btn_10_main_main_default);
	lv_style_set_radius(&style_sem1_btn_10_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_10_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_sem1_btn_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_10_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_10_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_10_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_10_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_10_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_10_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_10_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_10_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_10_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_btn_10_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn_10_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_sem1_btn_10_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_10, &style_sem1_btn_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_10_label = lv_label_create(ui->SEM1_btn_10);
	lv_label_set_text(ui->SEM1_btn_10_label, "2");
	lv_obj_set_style_pad_all(ui->SEM1_btn_10, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_10_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_btn_11
	ui->SEM1_btn_11 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_btn_11, 150, 130);
	lv_obj_set_size(ui->SEM1_btn_11, 50, 50);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_11, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_11_main_main_default
	static lv_style_t style_sem1_btn_11_main_main_default;
	if (style_sem1_btn_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_11_main_main_default);
	else
		lv_style_init(&style_sem1_btn_11_main_main_default);
	lv_style_set_radius(&style_sem1_btn_11_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_11_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_sem1_btn_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_11_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_11_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_11_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_11_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_11_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_11_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_11_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_11_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_11_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_btn_11_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn_11_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_sem1_btn_11_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_11, &style_sem1_btn_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_11_label = lv_label_create(ui->SEM1_btn_11);
	lv_label_set_text(ui->SEM1_btn_11_label, "3");
	lv_obj_set_style_pad_all(ui->SEM1_btn_11, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_11_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_btn_12
	ui->SEM1_btn_12 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_btn_12, 150, 190);
	lv_obj_set_size(ui->SEM1_btn_12, 50, 50);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_12, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_12_main_main_default
	static lv_style_t style_sem1_btn_12_main_main_default;
	if (style_sem1_btn_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_12_main_main_default);
	else
		lv_style_init(&style_sem1_btn_12_main_main_default);
	lv_style_set_radius(&style_sem1_btn_12_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_12_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_sem1_btn_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_12_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_12_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_12_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_12_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_12_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_12_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_12_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_12_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_12_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_btn_12_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn_12_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_sem1_btn_12_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_12, &style_sem1_btn_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_12_label = lv_label_create(ui->SEM1_btn_12);
	lv_label_set_text(ui->SEM1_btn_12_label, ".");
	lv_obj_set_style_pad_all(ui->SEM1_btn_12, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_12_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_btn_13
	ui->SEM1_btn_13 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_btn_13, 210, 10);
	lv_obj_set_size(ui->SEM1_btn_13, 50, 70);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_13, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_13_main_main_default
	static lv_style_t style_sem1_btn_13_main_main_default;
	if (style_sem1_btn_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_13_main_main_default);
	else
		lv_style_init(&style_sem1_btn_13_main_main_default);
	lv_style_set_radius(&style_sem1_btn_13_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_13_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_sem1_btn_13_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_13_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_13_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_13_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_13_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_13_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_13_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_13_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_13_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_13_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_13_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_13_main_main_default, 0);
	lv_style_set_text_color(&style_sem1_btn_13_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn_13_main_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_align(&style_sem1_btn_13_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_13, &style_sem1_btn_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_13_label = lv_label_create(ui->SEM1_btn_13);
	lv_label_set_text(ui->SEM1_btn_13_label, "Deleter");
	lv_obj_set_style_pad_all(ui->SEM1_btn_13, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_13_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_btn_14
	ui->SEM1_btn_14 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_btn_14, 210, 90);
	lv_obj_set_size(ui->SEM1_btn_14, 50, 70);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_14, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_14_main_main_default
	static lv_style_t style_sem1_btn_14_main_main_default;
	if (style_sem1_btn_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_14_main_main_default);
	else
		lv_style_init(&style_sem1_btn_14_main_main_default);
	lv_style_set_radius(&style_sem1_btn_14_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_14_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_sem1_btn_14_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_14_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_14_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_14_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_14_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_14_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_14_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_14_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_14_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_14_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_14_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_14_main_main_default, 0);
	lv_style_set_text_color(&style_sem1_btn_14_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn_14_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_sem1_btn_14_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_14, &style_sem1_btn_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_14_label = lv_label_create(ui->SEM1_btn_14);
	lv_label_set_text(ui->SEM1_btn_14_label, "Enter");
	lv_obj_set_style_pad_all(ui->SEM1_btn_14, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_14_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_btn_15
	ui->SEM1_btn_15 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_btn_15, 210, 170);
	lv_obj_set_size(ui->SEM1_btn_15, 50, 70);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_15, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_15_main_main_default
	static lv_style_t style_sem1_btn_15_main_main_default;
	if (style_sem1_btn_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_15_main_main_default);
	else
		lv_style_init(&style_sem1_btn_15_main_main_default);
	lv_style_set_radius(&style_sem1_btn_15_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_15_main_main_default, lv_color_make(0xd3, 0xd3, 0xd3));
	lv_style_set_bg_grad_color(&style_sem1_btn_15_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_15_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_15_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_15_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_15_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_15_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_15_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_15_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_15_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_15_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_15_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_15_main_main_default, 0);
	lv_style_set_text_color(&style_sem1_btn_15_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn_15_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_sem1_btn_15_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_15, &style_sem1_btn_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_15_label = lv_label_create(ui->SEM1_btn_15);
	lv_label_set_text(ui->SEM1_btn_15_label, "Save");
	lv_obj_set_style_pad_all(ui->SEM1_btn_15, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_15_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_btn_16
	ui->SEM1_btn_16 = lv_btn_create(ui->SEM1_cont_1);
	lv_obj_set_pos(ui->SEM1_btn_16, 273, 5);
	lv_obj_set_size(ui->SEM1_btn_16, 43, 18);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_16, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_16_main_main_default
	static lv_style_t style_sem1_btn_16_main_main_default;
	if (style_sem1_btn_16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_16_main_main_default);
	else
		lv_style_init(&style_sem1_btn_16_main_main_default);
	lv_style_set_radius(&style_sem1_btn_16_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_16_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_sem1_btn_16_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_16_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_16_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_16_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_16_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_16_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_16_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_16_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_16_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_16_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_16_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_16_main_main_default, 0);
	lv_style_set_text_color(&style_sem1_btn_16_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_btn_16_main_main_default, &lv_font_montserratMedium_24);
	lv_style_set_text_align(&style_sem1_btn_16_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_16, &style_sem1_btn_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_16_label = lv_label_create(ui->SEM1_btn_16);
	lv_label_set_text(ui->SEM1_btn_16_label, "<");
	lv_obj_set_style_pad_all(ui->SEM1_btn_16, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_16_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_para
	ui->SEM1_para = lv_dropdown_create(ui->SEM1);
	lv_obj_set_pos(ui->SEM1_para, 10, 130);
	lv_obj_set_size(ui->SEM1_para, 130, 30);
	lv_obj_set_scrollbar_mode(ui->SEM1_para, LV_SCROLLBAR_MODE_OFF);
	lv_dropdown_set_options(ui->SEM1_para, "Select paramenter\nP\nI\nD\nSpeed\nFoc\nPlace");
	lv_dropdown_set_symbol(ui->SEM1_para, NULL);

	//Write style state: LV_STATE_DEFAULT for style_sem1_para_main_main_default
	static lv_style_t style_sem1_para_main_main_default;
	if (style_sem1_para_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_para_main_main_default);
	else
		lv_style_init(&style_sem1_para_main_main_default);
	lv_style_set_radius(&style_sem1_para_main_main_default, 3);
	lv_style_set_bg_color(&style_sem1_para_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_sem1_para_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_sem1_para_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_para_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_para_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_para_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_para_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_para_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_para_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_para_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_para_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_sem1_para_main_main_default, 1);
	lv_style_set_border_opa(&style_sem1_para_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_para_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_sem1_para_main_main_default, &lv_font_montserratMedium_12);
	lv_style_set_pad_left(&style_sem1_para_main_main_default, 6);
	lv_style_set_pad_right(&style_sem1_para_main_main_default, 6);
	lv_style_set_pad_top(&style_sem1_para_main_main_default, 8);
	lv_obj_add_style(ui->SEM1_para, &style_sem1_para_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_sem1_para_extra_list_selected_checked
	static lv_style_t style_sem1_para_extra_list_selected_checked;
	if (style_sem1_para_extra_list_selected_checked.prop_cnt > 1)
		lv_style_reset(&style_sem1_para_extra_list_selected_checked);
	else
		lv_style_init(&style_sem1_para_extra_list_selected_checked);
	lv_style_set_radius(&style_sem1_para_extra_list_selected_checked, 3);
	lv_style_set_bg_color(&style_sem1_para_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_sem1_para_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_sem1_para_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_para_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_sem1_para_extra_list_selected_checked, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_sem1_para_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_sem1_para_extra_list_selected_checked, 255);
	lv_style_set_text_color(&style_sem1_para_extra_list_selected_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sem1_para_extra_list_selected_checked, &lv_font_montserratMedium_12);
	lv_obj_add_style(lv_dropdown_get_list(ui->SEM1_para), &style_sem1_para_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_sem1_para_extra_list_main_default
	static lv_style_t style_sem1_para_extra_list_main_default;
	if (style_sem1_para_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_para_extra_list_main_default);
	else
		lv_style_init(&style_sem1_para_extra_list_main_default);
	lv_style_set_radius(&style_sem1_para_extra_list_main_default, 3);
	lv_style_set_bg_color(&style_sem1_para_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_sem1_para_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_sem1_para_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_para_extra_list_main_default, 255);
	lv_style_set_border_color(&style_sem1_para_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_sem1_para_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_sem1_para_extra_list_main_default, 255);
	lv_style_set_text_color(&style_sem1_para_extra_list_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_sem1_para_extra_list_main_default, &lv_font_montserratMedium_12);
	lv_style_set_max_height(&style_sem1_para_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(ui->SEM1_para), &style_sem1_para_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_sem1_para_extra_list_scrollbar_default
	static lv_style_t style_sem1_para_extra_list_scrollbar_default;
	if (style_sem1_para_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_para_extra_list_scrollbar_default);
	else
		lv_style_init(&style_sem1_para_extra_list_scrollbar_default);
	lv_style_set_radius(&style_sem1_para_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_sem1_para_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_opa(&style_sem1_para_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(ui->SEM1_para), &style_sem1_para_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes SEM1_btn_1
	ui->SEM1_btn_1 = lv_btn_create(ui->SEM1);
	lv_obj_set_pos(ui->SEM1_btn_1, 272, -2);
	lv_obj_set_size(ui->SEM1_btn_1, 45, 49);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_1_main_main_default
	static lv_style_t style_sem1_btn_1_main_main_default;
	if (style_sem1_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_1_main_main_default);
	else
		lv_style_init(&style_sem1_btn_1_main_main_default);
	lv_style_set_radius(&style_sem1_btn_1_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_sem1_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_1_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_btn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sem1_btn_1_main_main_default, &lv_font_montserratMedium_36);
	lv_style_set_text_align(&style_sem1_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_1, &style_sem1_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_1_label = lv_label_create(ui->SEM1_btn_1);
	lv_label_set_text(ui->SEM1_btn_1_label, "X");
	lv_obj_set_style_pad_all(ui->SEM1_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes SEM1_option
	ui->SEM1_option = lv_dropdown_create(ui->SEM1);
	lv_obj_set_pos(ui->SEM1_option, 10, 90);
	lv_obj_set_size(ui->SEM1_option, 130, 30);
	lv_obj_set_scrollbar_mode(ui->SEM1_option, LV_SCROLLBAR_MODE_OFF);
	lv_dropdown_set_options(ui->SEM1_option, "Select options\nPole\nAngle\nVelocity\nVLimit\nCurrent Limit\nControlmod");
	lv_dropdown_set_symbol(ui->SEM1_option, NULL);

	//Write style state: LV_STATE_DEFAULT for style_sem1_option_main_main_default
	static lv_style_t style_sem1_option_main_main_default;
	if (style_sem1_option_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_option_main_main_default);
	else
		lv_style_init(&style_sem1_option_main_main_default);
	lv_style_set_radius(&style_sem1_option_main_main_default, 3);
	lv_style_set_bg_color(&style_sem1_option_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_sem1_option_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_sem1_option_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_option_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_option_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_option_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_option_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_option_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_option_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_option_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_option_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_sem1_option_main_main_default, 1);
	lv_style_set_border_opa(&style_sem1_option_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_option_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_sem1_option_main_main_default, &lv_font_FontAwesome5_12);
	lv_style_set_pad_left(&style_sem1_option_main_main_default, 6);
	lv_style_set_pad_right(&style_sem1_option_main_main_default, 6);
	lv_style_set_pad_top(&style_sem1_option_main_main_default, 8);
	lv_obj_add_style(ui->SEM1_option, &style_sem1_option_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_sem1_option_extra_list_selected_checked
	static lv_style_t style_sem1_option_extra_list_selected_checked;
	if (style_sem1_option_extra_list_selected_checked.prop_cnt > 1)
		lv_style_reset(&style_sem1_option_extra_list_selected_checked);
	else
		lv_style_init(&style_sem1_option_extra_list_selected_checked);
	lv_style_set_radius(&style_sem1_option_extra_list_selected_checked, 3);
	lv_style_set_bg_color(&style_sem1_option_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_sem1_option_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_sem1_option_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_option_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_sem1_option_extra_list_selected_checked, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_sem1_option_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_sem1_option_extra_list_selected_checked, 255);
	lv_style_set_text_color(&style_sem1_option_extra_list_selected_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sem1_option_extra_list_selected_checked, &lv_font_montserratMedium_12);
	lv_obj_add_style(lv_dropdown_get_list(ui->SEM1_option), &style_sem1_option_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_sem1_option_extra_list_main_default
	static lv_style_t style_sem1_option_extra_list_main_default;
	if (style_sem1_option_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_option_extra_list_main_default);
	else
		lv_style_init(&style_sem1_option_extra_list_main_default);
	lv_style_set_radius(&style_sem1_option_extra_list_main_default, 3);
	lv_style_set_bg_color(&style_sem1_option_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_sem1_option_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_sem1_option_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_option_extra_list_main_default, 255);
	lv_style_set_border_color(&style_sem1_option_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_sem1_option_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_sem1_option_extra_list_main_default, 255);
	lv_style_set_text_color(&style_sem1_option_extra_list_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_sem1_option_extra_list_main_default, &lv_font_montserratMedium_12);
	lv_style_set_max_height(&style_sem1_option_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(ui->SEM1_option), &style_sem1_option_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_sem1_option_extra_list_scrollbar_default
	static lv_style_t style_sem1_option_extra_list_scrollbar_default;
	if (style_sem1_option_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_option_extra_list_scrollbar_default);
	else
		lv_style_init(&style_sem1_option_extra_list_scrollbar_default);
	lv_style_set_radius(&style_sem1_option_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_sem1_option_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_opa(&style_sem1_option_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(ui->SEM1_option), &style_sem1_option_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes SEM1_motsel
	ui->SEM1_motsel = lv_dropdown_create(ui->SEM1);
	lv_obj_set_pos(ui->SEM1_motsel, 10, 50);
	lv_obj_set_size(ui->SEM1_motsel, 130, 30);
	lv_obj_set_scrollbar_mode(ui->SEM1_motsel, LV_SCROLLBAR_MODE_OFF);
	lv_dropdown_set_options(ui->SEM1_motsel, "MOTTOR\nM1\nM2");
	lv_dropdown_set_symbol(ui->SEM1_motsel, NULL);

	//Write style state: LV_STATE_DEFAULT for style_sem1_motsel_main_main_default
	static lv_style_t style_sem1_motsel_main_main_default;
	if (style_sem1_motsel_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_motsel_main_main_default);
	else
		lv_style_init(&style_sem1_motsel_main_main_default);
	lv_style_set_radius(&style_sem1_motsel_main_main_default, 3);
	lv_style_set_bg_color(&style_sem1_motsel_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_sem1_motsel_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_sem1_motsel_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_motsel_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_motsel_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_motsel_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_motsel_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_motsel_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_motsel_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_motsel_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_motsel_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_sem1_motsel_main_main_default, 1);
	lv_style_set_border_opa(&style_sem1_motsel_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_motsel_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_sem1_motsel_main_main_default, &lv_font_montserratMedium_12);
	lv_style_set_pad_left(&style_sem1_motsel_main_main_default, 6);
	lv_style_set_pad_right(&style_sem1_motsel_main_main_default, 6);
	lv_style_set_pad_top(&style_sem1_motsel_main_main_default, 8);
	lv_obj_add_style(ui->SEM1_motsel, &style_sem1_motsel_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_sem1_motsel_extra_list_selected_checked
	static lv_style_t style_sem1_motsel_extra_list_selected_checked;
	if (style_sem1_motsel_extra_list_selected_checked.prop_cnt > 1)
		lv_style_reset(&style_sem1_motsel_extra_list_selected_checked);
	else
		lv_style_init(&style_sem1_motsel_extra_list_selected_checked);
	lv_style_set_radius(&style_sem1_motsel_extra_list_selected_checked, 3);
	lv_style_set_bg_color(&style_sem1_motsel_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_sem1_motsel_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_sem1_motsel_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_motsel_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_sem1_motsel_extra_list_selected_checked, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_sem1_motsel_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_sem1_motsel_extra_list_selected_checked, 255);
	lv_style_set_text_color(&style_sem1_motsel_extra_list_selected_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sem1_motsel_extra_list_selected_checked, &lv_font_montserratMedium_12);
	lv_obj_add_style(lv_dropdown_get_list(ui->SEM1_motsel), &style_sem1_motsel_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_sem1_motsel_extra_list_main_default
	static lv_style_t style_sem1_motsel_extra_list_main_default;
	if (style_sem1_motsel_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_motsel_extra_list_main_default);
	else
		lv_style_init(&style_sem1_motsel_extra_list_main_default);
	lv_style_set_radius(&style_sem1_motsel_extra_list_main_default, 3);
	lv_style_set_bg_color(&style_sem1_motsel_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_sem1_motsel_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_sem1_motsel_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_motsel_extra_list_main_default, 255);
	lv_style_set_border_color(&style_sem1_motsel_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_sem1_motsel_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_sem1_motsel_extra_list_main_default, 255);
	lv_style_set_text_color(&style_sem1_motsel_extra_list_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_sem1_motsel_extra_list_main_default, &lv_font_montserratMedium_12);
	lv_style_set_max_height(&style_sem1_motsel_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(ui->SEM1_motsel), &style_sem1_motsel_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_sem1_motsel_extra_list_scrollbar_default
	static lv_style_t style_sem1_motsel_extra_list_scrollbar_default;
	if (style_sem1_motsel_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_motsel_extra_list_scrollbar_default);
	else
		lv_style_init(&style_sem1_motsel_extra_list_scrollbar_default);
	lv_style_set_radius(&style_sem1_motsel_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_sem1_motsel_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_opa(&style_sem1_motsel_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(ui->SEM1_motsel), &style_sem1_motsel_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes SEM1_label_1
	ui->SEM1_label_1 = lv_label_create(ui->SEM1);
	lv_obj_set_pos(ui->SEM1_label_1, 164, 86);
	lv_obj_set_size(ui->SEM1_label_1, 133, 29);
	lv_obj_set_scrollbar_mode(ui->SEM1_label_1, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->SEM1_label_1, "0.00");
    lv_label_set_text_fmt(ui->SEM1_label_1,"t%2.0f ",M1labe);  
	lv_label_set_long_mode(ui->SEM1_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sem1_label_1_main_main_default
	static lv_style_t style_sem1_label_1_main_main_default;
	if (style_sem1_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_label_1_main_main_default);
	else
		lv_style_init(&style_sem1_label_1_main_main_default);
	lv_style_set_radius(&style_sem1_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sem1_label_1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_color(&style_sem1_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_label_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_label_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_label_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_sem1_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_sem1_label_1_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_sem1_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_sem1_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_sem1_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sem1_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sem1_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sem1_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_sem1_label_1_main_main_default, 0);
	lv_obj_add_style(ui->SEM1_label_1, &style_sem1_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes SEM1_label_2
	ui->SEM1_label_2 = lv_label_create(ui->SEM1);
	lv_obj_set_pos(ui->SEM1_label_2, 4, 1);
	lv_obj_set_size(ui->SEM1_label_2, 260, 35);
	lv_obj_set_scrollbar_mode(ui->SEM1_label_2, LV_SCROLLBAR_MODE_OFF);
	//lv_label_set_text(ui->SEM1_label_2, "Label");
	lv_label_set_text_fmt(ui->SEM1_label_2,"M1:%f M2:%d DR:%d ",M1labe,M2labe,DRlabe);
	lv_label_set_long_mode(ui->SEM1_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sem1_label_2_main_main_default
	static lv_style_t style_sem1_label_2_main_main_default;
	if (style_sem1_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_label_2_main_main_default);
	else
		lv_style_init(&style_sem1_label_2_main_main_default);
	lv_style_set_radius(&style_sem1_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_sem1_label_2_main_main_default, lv_color_make(0x14, 0x18, 0x1c));
	lv_style_set_bg_grad_color(&style_sem1_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_label_2_main_main_default, 255);
	lv_style_set_shadow_width(&style_sem1_label_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_label_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_sem1_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sem1_label_2_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_sem1_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_sem1_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_sem1_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sem1_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_sem1_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_sem1_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_sem1_label_2_main_main_default, 0);
	lv_obj_add_style(ui->SEM1_label_2, &style_sem1_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes SEM1_btn_17
	ui->SEM1_btn_17 = lv_btn_create(ui->SEM1);
	lv_obj_set_pos(ui->SEM1_btn_17, 164, 75);
	lv_obj_set_size(ui->SEM1_btn_17, 140, 50);
	lv_obj_set_scrollbar_mode(ui->SEM1_btn_17, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sem1_btn_17_main_main_default
	static lv_style_t style_sem1_btn_17_main_main_default;
	if (style_sem1_btn_17_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sem1_btn_17_main_main_default);
	else
		lv_style_init(&style_sem1_btn_17_main_main_default);
	lv_style_set_radius(&style_sem1_btn_17_main_main_default, 5);
	lv_style_set_bg_color(&style_sem1_btn_17_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sem1_btn_17_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sem1_btn_17_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sem1_btn_17_main_main_default, 0);
	lv_style_set_shadow_width(&style_sem1_btn_17_main_main_default, 0);
	lv_style_set_shadow_color(&style_sem1_btn_17_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sem1_btn_17_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sem1_btn_17_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_sem1_btn_17_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sem1_btn_17_main_main_default, 0);
	lv_style_set_border_color(&style_sem1_btn_17_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sem1_btn_17_main_main_default, 0);
	lv_style_set_border_opa(&style_sem1_btn_17_main_main_default, 255);
	lv_style_set_text_color(&style_sem1_btn_17_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_align(&style_sem1_btn_17_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->SEM1_btn_17, &style_sem1_btn_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->SEM1_btn_17_label = lv_label_create(ui->SEM1_btn_17);
	lv_label_set_text(ui->SEM1_btn_17_label, "");
	lv_obj_set_style_pad_all(ui->SEM1_btn_17, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->SEM1_btn_17_label, LV_ALIGN_CENTER, 0, 0);

	//Init events for screen
	events_init_SEM1(ui);
}