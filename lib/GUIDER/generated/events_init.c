/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

extern int wifiConfirmFlag;

void events_init(lv_ui *ui)
{
}

static void btn_1_WIFISet_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.screen_1_del == true)
				setup_scr_screen_1(&guider_ui);
			lv_scr_load_anim(guider_ui.screen_1, LV_SCR_LOAD_ANIM_NONE, 100, 100, false);
			guider_ui.btn_1_del = false;
		}
	}
		break;
	default:
		break;
	}
}

static void btn_1_img_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_add_flag(guider_ui.btn_1_img_4, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

void events_init_btn_1(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->btn_1_WIFISet, btn_1_WIFISet_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->btn_1_img_4, btn_1_img_4_event_handler, LV_EVENT_ALL, ui);
}

static void screen_1_Back_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.btn_1_del == true)
				setup_scr_btn_1(&guider_ui);
			lv_scr_load_anim(guider_ui.btn_1, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
			guider_ui.screen_1_del = true;
		}
	}
		break;
	default:
		break;
	}
}

static void screen_1_WIFIPWD_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
	}
		break;
	default:
		break;
	}
}

static void screen_1_WIFI_Confrim_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		wifiConfirmFlag = 1;
	}
		break;
	default:
		break;
	}
}

static void screen_1_WIFIID_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
	}
		break;
	default:
		break;
	}
}

void events_init_screen_1(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_1_Back, screen_1_Back_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_1_WIFIPWD, screen_1_WIFIPWD_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_1_WIFI_Confrim, screen_1_WIFI_Confrim_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_1_WIFIID, screen_1_WIFIID_event_handler, LV_EVENT_ALL, ui);
}
