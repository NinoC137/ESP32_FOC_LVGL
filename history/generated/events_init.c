/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "selfset.h"
int wificonnect = 0;


int flo=10;
int SAVE=0;
char *paraments;
char options[2];
char mottor[2];

void events_init(lv_ui *ui)
{
}

void video_play(lv_ui *ui)
{

}

static void MAIN_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.menu_del == true)
				setup_scr_menu(&guider_ui);
			lv_scr_load_anim(guider_ui.menu, LV_SCR_LOAD_ANIM_NONE, 500, 100, true);
			guider_ui.MAIN_del = true;
		}
	}
		break;
	default:
		break;
	}
}

void events_init_MAIN(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->MAIN_btn_1, MAIN_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void menu_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.MAIN_del == true)
				setup_scr_MAIN(&guider_ui);
			lv_scr_load_anim(guider_ui.MAIN, LV_SCR_LOAD_ANIM_OVER_TOP, 500, 100, true);
			guider_ui.menu_del = true;
		}
	}
		break;
	default:
		break;
	}
}

static void menu_btn_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.TYPE_del == true)
				setup_scr_TYPE(&guider_ui);
			lv_scr_load_anim(guider_ui.TYPE, LV_SCR_LOAD_ANIM_NONE, 500, 100, true);
			guider_ui.menu_del = true;
		}
	}
		break;
	default:
		break;
	}
}

static void menu_btn_6_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.OTHERS_del == true)
				setup_scr_OTHERS(&guider_ui);
			lv_scr_load_anim(guider_ui.OTHERS, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
			guider_ui.menu_del = true;
		}
	}
		break;
	default:
		break;
	}
}

static void menu_btn_7_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.WIFI_del == true)
				setup_scr_WIFI(&guider_ui);
			lv_scr_load_anim(guider_ui.WIFI, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
			guider_ui.menu_del = true;
		}
	}
		break;
	default:
		break;
	}
}

static void menu_btn_8_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.SEM1_del == true)
				setup_scr_SEM1(&guider_ui);
			lv_scr_load_anim(guider_ui.SEM1, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
			guider_ui.menu_del = true;
		}
	}
		break;
	default:
		break;
	}
}

static void menu_btn_9_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			lv_obj_clean(act_scr);
			if (guider_ui.MAIN_del == true)
				setup_scr_MAIN(&guider_ui);
			lv_scr_load_anim(guider_ui.MAIN, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
			guider_ui.menu_del = true;
		}
	}
		break;
	default:
		break;
	}
}

void events_init_menu(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->menu, menu_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->menu_btn_5, menu_btn_5_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->menu_btn_6, menu_btn_6_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->menu_btn_7, menu_btn_7_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->menu_btn_8, menu_btn_8_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->menu_btn_9, menu_btn_9_event_handler, LV_EVENT_ALL, ui);
}

static void TYPE_RM1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_anim_t TYPE_TM1_anim_x;
	lv_anim_t TYPE_TM1_anim_y;
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{

	//Write animation: TYPE_TM1move in x direction
		lv_anim_init(&TYPE_TM1_anim_x);
		lv_anim_set_var(&TYPE_TM1_anim_x, guider_ui.TYPE_TM1);
		lv_anim_set_time(&TYPE_TM1_anim_x, 2);
		lv_anim_set_exec_cb(&TYPE_TM1_anim_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&TYPE_TM1_anim_x, lv_obj_get_x(guider_ui.TYPE_TM1), 10);
		lv_anim_set_path_cb(&TYPE_TM1_anim_x, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TM1_anim_x);

	//Write animation: TYPE_TM1move in y direction
		lv_anim_init(&TYPE_TM1_anim_y);
		lv_anim_set_var(&TYPE_TM1_anim_y, guider_ui.TYPE_TM1);
		lv_anim_set_time(&TYPE_TM1_anim_y, 2);
		lv_anim_set_exec_cb(&TYPE_TM1_anim_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&TYPE_TM1_anim_y, lv_obj_get_y(guider_ui.TYPE_TM1), 100);
		lv_anim_set_path_cb(&TYPE_TM1_anim_y, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TM1_anim_y);
	}
		break;
	default:
		break;
	}
}

static void TYPE_RDRV_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_anim_t TYPE_TDRV_anim_x;
	lv_anim_t TYPE_TDRV_anim_y;
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{

	//Write animation: TYPE_TDRVmove in x direction
		lv_anim_init(&TYPE_TDRV_anim_x);
		lv_anim_set_var(&TYPE_TDRV_anim_x, guider_ui.TYPE_TDRV);
		lv_anim_set_time(&TYPE_TDRV_anim_x, 2);
		lv_anim_set_exec_cb(&TYPE_TDRV_anim_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&TYPE_TDRV_anim_x, lv_obj_get_x(guider_ui.TYPE_TDRV), 10);
		lv_anim_set_path_cb(&TYPE_TDRV_anim_x, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TDRV_anim_x);

	//Write animation: TYPE_TDRVmove in y direction
		lv_anim_init(&TYPE_TDRV_anim_y);
		lv_anim_set_var(&TYPE_TDRV_anim_y, guider_ui.TYPE_TDRV);
		lv_anim_set_time(&TYPE_TDRV_anim_y, 2);
		lv_anim_set_exec_cb(&TYPE_TDRV_anim_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&TYPE_TDRV_anim_y, lv_obj_get_y(guider_ui.TYPE_TDRV), 94);
		lv_anim_set_path_cb(&TYPE_TDRV_anim_y, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TDRV_anim_y);
	}
		break;
	default:
		break;
	}
}

static void TYPE_RM1M2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_anim_t TYPE_TM1M2_anim_x;
	lv_anim_t TYPE_TM1M2_anim_y;
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{

	//Write animation: TYPE_TM1M2move in x direction
		lv_anim_init(&TYPE_TM1M2_anim_x);
		lv_anim_set_var(&TYPE_TM1M2_anim_x, guider_ui.TYPE_TM1M2);
		lv_anim_set_time(&TYPE_TM1M2_anim_x, 2);
		lv_anim_set_exec_cb(&TYPE_TM1M2_anim_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&TYPE_TM1M2_anim_x, lv_obj_get_x(guider_ui.TYPE_TM1M2), 10);
		lv_anim_set_path_cb(&TYPE_TM1M2_anim_x, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TM1M2_anim_x);

	//Write animation: TYPE_TM1M2move in y direction
		lv_anim_init(&TYPE_TM1M2_anim_y);
		lv_anim_set_var(&TYPE_TM1M2_anim_y, guider_ui.TYPE_TM1M2);
		lv_anim_set_time(&TYPE_TM1M2_anim_y, 2);
		lv_anim_set_exec_cb(&TYPE_TM1M2_anim_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&TYPE_TM1M2_anim_y, lv_obj_get_y(guider_ui.TYPE_TM1M2), 40);
		lv_anim_set_path_cb(&TYPE_TM1M2_anim_y, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TM1M2_anim_y);
	}
		break;
	default:
		break;
	}
}

static void TYPE_RM2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_anim_t TYPE_TM2_anim_x;
	lv_anim_t TYPE_TM2_anim_y;
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{

	//Write animation: TYPE_TM2move in x direction
		lv_anim_init(&TYPE_TM2_anim_x);
		lv_anim_set_var(&TYPE_TM2_anim_x, guider_ui.TYPE_TM2);
		lv_anim_set_time(&TYPE_TM2_anim_x, 2);
		lv_anim_set_exec_cb(&TYPE_TM2_anim_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&TYPE_TM2_anim_x, lv_obj_get_x(guider_ui.TYPE_TM2), 10);
		lv_anim_set_path_cb(&TYPE_TM2_anim_x, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TM2_anim_x);

	//Write animation: TYPE_TM2move in y direction
		lv_anim_init(&TYPE_TM2_anim_y);
		lv_anim_set_var(&TYPE_TM2_anim_y, guider_ui.TYPE_TM2);
		lv_anim_set_time(&TYPE_TM2_anim_y, 2);
		lv_anim_set_exec_cb(&TYPE_TM2_anim_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&TYPE_TM2_anim_y, lv_obj_get_y(guider_ui.TYPE_TM2), 94);
		lv_anim_set_path_cb(&TYPE_TM2_anim_y, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TM2_anim_y);
	}
		break;
	default:
		break;
	}
}

static void TYPE_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.menu_del == true)
				setup_scr_menu(&guider_ui);
			lv_scr_load_anim(guider_ui.menu, LV_SCR_LOAD_ANIM_NONE, 500, 100, true);
			guider_ui.TYPE_del = true;
		}
	}
		break;
	default:
		break;
	}
}

static void TYPE_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_anim_t TYPE_TM1_anim_x;
	lv_anim_t TYPE_TM1_anim_y;
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{

	//Write animation: TYPE_TM1move in x direction
		lv_anim_init(&TYPE_TM1_anim_x);
		lv_anim_set_var(&TYPE_TM1_anim_x, guider_ui.TYPE_TM1);
		lv_anim_set_time(&TYPE_TM1_anim_x, 2);
		lv_anim_set_exec_cb(&TYPE_TM1_anim_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&TYPE_TM1_anim_x, lv_obj_get_x(guider_ui.TYPE_TM1), -305);
		lv_anim_set_path_cb(&TYPE_TM1_anim_x, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TM1_anim_x);

	//Write animation: TYPE_TM1move in y direction
		lv_anim_init(&TYPE_TM1_anim_y);
		lv_anim_set_var(&TYPE_TM1_anim_y, guider_ui.TYPE_TM1);
		lv_anim_set_time(&TYPE_TM1_anim_y, 2);
		lv_anim_set_exec_cb(&TYPE_TM1_anim_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&TYPE_TM1_anim_y, lv_obj_get_y(guider_ui.TYPE_TM1), 100);
		lv_anim_set_path_cb(&TYPE_TM1_anim_y, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TM1_anim_y);
	}
		break;
	default:
		break;
	}
}

static void TYPE_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_anim_t TYPE_TM2_anim_x;
	lv_anim_t TYPE_TM2_anim_y;
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{

	//Write animation: TYPE_TM2move in x direction
		lv_anim_init(&TYPE_TM2_anim_x);
		lv_anim_set_var(&TYPE_TM2_anim_x, guider_ui.TYPE_TM2);
		lv_anim_set_time(&TYPE_TM2_anim_x, 2);
		lv_anim_set_exec_cb(&TYPE_TM2_anim_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&TYPE_TM2_anim_x, lv_obj_get_x(guider_ui.TYPE_TM2), 320);
		lv_anim_set_path_cb(&TYPE_TM2_anim_x, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TM2_anim_x);

	//Write animation: TYPE_TM2move in y direction
		lv_anim_init(&TYPE_TM2_anim_y);
		lv_anim_set_var(&TYPE_TM2_anim_y, guider_ui.TYPE_TM2);
		lv_anim_set_time(&TYPE_TM2_anim_y, 2);
		lv_anim_set_exec_cb(&TYPE_TM2_anim_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&TYPE_TM2_anim_y, lv_obj_get_y(guider_ui.TYPE_TM2), 100);
		lv_anim_set_path_cb(&TYPE_TM2_anim_y, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TM2_anim_y);
	}
		break;
	default:
		break;
	}
}

static void TYPE_btn_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_anim_t TYPE_TM1M2_anim_x;
	lv_anim_t TYPE_TM1M2_anim_y;
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{

	//Write animation: TYPE_TM1M2move in x direction
		lv_anim_init(&TYPE_TM1M2_anim_x);
		lv_anim_set_var(&TYPE_TM1M2_anim_x, guider_ui.TYPE_TM1M2);
		lv_anim_set_time(&TYPE_TM1M2_anim_x, 2);
		lv_anim_set_exec_cb(&TYPE_TM1M2_anim_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&TYPE_TM1M2_anim_x, lv_obj_get_x(guider_ui.TYPE_TM1M2), -305);
		lv_anim_set_path_cb(&TYPE_TM1M2_anim_x, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TM1M2_anim_x);

	//Write animation: TYPE_TM1M2move in y direction
		lv_anim_init(&TYPE_TM1M2_anim_y);
		lv_anim_set_var(&TYPE_TM1M2_anim_y, guider_ui.TYPE_TM1M2);
		lv_anim_set_time(&TYPE_TM1M2_anim_y, 2);
		lv_anim_set_exec_cb(&TYPE_TM1M2_anim_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&TYPE_TM1M2_anim_y, lv_obj_get_y(guider_ui.TYPE_TM1M2), 40);
		lv_anim_set_path_cb(&TYPE_TM1M2_anim_y, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TM1M2_anim_y);
	}
		break;
	default:
		break;
	}
}

static void TYPE_btn_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_anim_t TYPE_TDRV_anim_x;
	lv_anim_t TYPE_TDRV_anim_y;
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{

	//Write animation: TYPE_TDRVmove in x direction
		lv_anim_init(&TYPE_TDRV_anim_x);
		lv_anim_set_var(&TYPE_TDRV_anim_x, guider_ui.TYPE_TDRV);
		lv_anim_set_time(&TYPE_TDRV_anim_x, 2);
		lv_anim_set_exec_cb(&TYPE_TDRV_anim_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&TYPE_TDRV_anim_x, lv_obj_get_x(guider_ui.TYPE_TDRV), 320);
		lv_anim_set_path_cb(&TYPE_TDRV_anim_x, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TDRV_anim_x);

	//Write animation: TYPE_TDRVmove in y direction
		lv_anim_init(&TYPE_TDRV_anim_y);
		lv_anim_set_var(&TYPE_TDRV_anim_y, guider_ui.TYPE_TDRV);
		lv_anim_set_time(&TYPE_TDRV_anim_y, 2);
		lv_anim_set_exec_cb(&TYPE_TDRV_anim_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&TYPE_TDRV_anim_y, lv_obj_get_y(guider_ui.TYPE_TDRV), 100);
		lv_anim_set_path_cb(&TYPE_TDRV_anim_y, &lv_anim_path_linear);
		lv_anim_start(&TYPE_TDRV_anim_y);
	}
		break;
	default:
		break;
	}
}

void events_init_TYPE(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->TYPE_RM1, TYPE_RM1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->TYPE_RDRV, TYPE_RDRV_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->TYPE_RM1M2, TYPE_RM1M2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->TYPE_RM2, TYPE_RM2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->TYPE_btn_1, TYPE_btn_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->TYPE_btn_2, TYPE_btn_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->TYPE_btn_3, TYPE_btn_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->TYPE_btn_4, TYPE_btn_4_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->TYPE_btn_5, TYPE_btn_5_event_handler, LV_EVENT_ALL, ui);
}

static void OTHERS_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.menu_del == true)
				setup_scr_menu(&guider_ui);
			lv_scr_load_anim(guider_ui.menu, LV_SCR_LOAD_ANIM_NONE, 500, 100, true);
			guider_ui.OTHERS_del = true;
		}
	}
		break;
	default:
		break;
	}
}

void events_init_OTHERS(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->OTHERS_btn_1, OTHERS_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void SET_SM1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.SEM1_del == true)
				setup_scr_SEM1(&guider_ui);
			lv_scr_load_anim(guider_ui.SEM1, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
			guider_ui.SET_del = true;
		}
	}
		break;
	default:
		break;
	}
}

static void SET_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.menu_del == true)
				setup_scr_menu(&guider_ui);
			lv_scr_load_anim(guider_ui.menu, LV_SCR_LOAD_ANIM_NONE, 500, 100, true);
			guider_ui.SET_del = true;
		}
	}
		break;
	default:
		break;
	}
}

void events_init_SET(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->SET_SM1, SET_SM1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SET_btn_3, SET_btn_3_event_handler, LV_EVENT_ALL, ui);
}

static void WIFI_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.menu_del == true)
				setup_scr_menu(&guider_ui);
			lv_scr_load_anim(guider_ui.menu, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
			guider_ui.WIFI_del = true;
		}
	}
		break;
	default:
		break;
	}
}

static void WIFI_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		
		wificonnect=1;
	}
		break;
	default:
		break;
	}
}

void events_init_WIFI(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->WIFI_btn_1, WIFI_btn_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->WIFI_btn_2, WIFI_btn_2_event_handler, LV_EVENT_ALL, ui);
}

static void SEM1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_SCREEN_LOAD_START:
	{
	}
		break;
	default:
		break;
	}
}

static void SEM1_BTN0_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		/*setdata[data]=0;
		setchardata[data]='0';
		data++;
		if(data>10)
		{
		  data=0;
		  setdata=NULL;
		  setchardata=NULL;
		}
		realtime=setdatachange();*/
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		/*setdata[data]=7;
		setchardata[data]='7';
		data++;
		if(data>10)
		{
		  data=0;
		  setdata=NULL;
		  setchardata=NULL;
		}
		realtime=setdatachange();*/
		
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		/*setdata[data]=8;
		setchardata[data]='8';
		data++;
		if(data>10)
		{
		  data=0;
		  setdata=NULL;
		  setchardata=NULL;
		}
		realtime=setdatachange();*/
		
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		/*setdata[data]=9;
		setchardata[data]='9';
		data++;
		if(data>10)
		{
		  data=0;
		  setdata=NULL;
		  setchardata=NULL;
		}
		realtime=setdatachange();*/
		
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_6_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		/*setdata[data]=4;
		setchardata[data]='4';
		data++;
		if(data>10)
		{
		  data=0;
		  setdata=NULL;
		  setchardata=NULL;
		}
		realtime=setdatachange();*/
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_7_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		/*setdata[data]=5;
		setchardata[data]='5';
		data++;
		if(data>10)
		{
		  data=0;
		  setdata=NULL;
		  setchardata=NULL;
		}
		realtime=setdatachange();*/
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_8_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		/*setdata[data]=1;
		data++;
		if(data>10)
		{
		  data=10;
		  setdata=0;
		}
		realtime=setdatachange();*/
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_9_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		/*setdata[data]=6;
		setchardata[data]='6';
		data++;
		if(data>10)
		{
		  data=0;
		  setdata=NULL;
		  setchardata=NULL;
		}
		realtime=setdatachange();*/
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_10_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		/*setdata[data]=2;
		setchardata[data]='2';
		data++;
		if(data>10)
		{
		  data=0;
		  setdata=NULL;
		  setchardata=NULL;
		}
		realtime=setdatachange();*/
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_11_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		/*setdata[data]='3';
		setchardata[data]='3';
		data++;
		if(data>10)
		{
		  data=0;
		  setdata=NULL;
		  setchardata=NULL;
		}
		realtime=setdatachange();*/
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_12_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		//setdata[data]='.';
		/*flo=data;
		setchardata[data]='.';
		data++;
		if(data>10)
		{
		  data=0;
		  setdata=0;
		  setchardata=NULL;
		}
		realtime=setdatachange();*/
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_13_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		/*setdata[data]=NULL;
		setchardata[data]=NULL;
		data--;
		if(flo!=10)
		{
		  if(data<flo)
		 {
		  flo=0;
		 }
		}
		
		if(data<0)
		{
		  flo=0;
		  data=0;
		  setdata=0;
		}
		realtime=setdatachange();*/
		
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_14_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		/*SEM1_typecele();*/
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_15_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		SAVE=1;
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_16_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_anim_t SEM1_cont_1_anim_x;
	lv_anim_t SEM1_cont_1_anim_y;
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{

	//Write animation: SEM1_cont_1move in x direction
		lv_anim_init(&SEM1_cont_1_anim_x);
		lv_anim_set_var(&SEM1_cont_1_anim_x, guider_ui.SEM1_cont_1);
		lv_anim_set_time(&SEM1_cont_1_anim_x, 2);
		lv_anim_set_exec_cb(&SEM1_cont_1_anim_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&SEM1_cont_1_anim_x, lv_obj_get_x(guider_ui.SEM1_cont_1), -330);
		lv_anim_set_path_cb(&SEM1_cont_1_anim_x, &lv_anim_path_linear);
		lv_anim_start(&SEM1_cont_1_anim_x);

	//Write animation: SEM1_cont_1move in y direction
		lv_anim_init(&SEM1_cont_1_anim_y);
		lv_anim_set_var(&SEM1_cont_1_anim_y, guider_ui.SEM1_cont_1);
		lv_anim_set_time(&SEM1_cont_1_anim_y, 2);
		lv_anim_set_exec_cb(&SEM1_cont_1_anim_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&SEM1_cont_1_anim_y, lv_obj_get_y(guider_ui.SEM1_cont_1), 230);
		lv_anim_set_path_cb(&SEM1_cont_1_anim_y, &lv_anim_path_linear);
		lv_anim_start(&SEM1_cont_1_anim_y);
	}
		break;
	default:
		break;
	}
}

static void SEM1_para_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t * dropdown = lv_event_get_target(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_dropdown_get_selected_str(dropdown,paraments,1);
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.menu_del == true)
				setup_scr_menu(&guider_ui);
			lv_scr_load_anim(guider_ui.menu, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
			guider_ui.SEM1_del = true;
		}
	}
		break;
	default:
		break;
	}
}

static void SEM1_option_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		//lv_dropdown_get_selected_str(option,options,2);
	}
		break;
	default:
		break;
	}
}

static void SEM1_motsel_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		/*lv_dropdown_get_selected_str(motsel,mottor,2);*/
	}
		break;
	default:
		break;
	}
}

static void SEM1_btn_17_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_anim_t SEM1_cont_1_anim_x;
	lv_anim_t SEM1_cont_1_anim_y;
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{

	//Write animation: SEM1_cont_1move in x direction
		lv_anim_init(&SEM1_cont_1_anim_x);
		lv_anim_set_var(&SEM1_cont_1_anim_x, guider_ui.SEM1_cont_1);
		lv_anim_set_time(&SEM1_cont_1_anim_x, 2);
		lv_anim_set_exec_cb(&SEM1_cont_1_anim_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&SEM1_cont_1_anim_x, lv_obj_get_x(guider_ui.SEM1_cont_1), 0);
		lv_anim_set_path_cb(&SEM1_cont_1_anim_x, &lv_anim_path_linear);
		lv_anim_start(&SEM1_cont_1_anim_x);

	//Write animation: SEM1_cont_1move in y direction
		lv_anim_init(&SEM1_cont_1_anim_y);
		lv_anim_set_var(&SEM1_cont_1_anim_y, guider_ui.SEM1_cont_1);
		lv_anim_set_time(&SEM1_cont_1_anim_y, 2);
		lv_anim_set_exec_cb(&SEM1_cont_1_anim_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&SEM1_cont_1_anim_y, lv_obj_get_y(guider_ui.SEM1_cont_1), 230);
		lv_anim_set_path_cb(&SEM1_cont_1_anim_y, &lv_anim_path_linear);
		lv_anim_start(&SEM1_cont_1_anim_y);
	}
		break;
	default:
		break;
	}
}

void events_init_SEM1(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->SEM1, SEM1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_BTN0, SEM1_BTN0_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_3, SEM1_btn_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_4, SEM1_btn_4_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_5, SEM1_btn_5_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_6, SEM1_btn_6_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_7, SEM1_btn_7_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_8, SEM1_btn_8_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_9, SEM1_btn_9_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_10, SEM1_btn_10_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_11, SEM1_btn_11_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_12, SEM1_btn_12_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_13, SEM1_btn_13_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_14, SEM1_btn_14_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_15, SEM1_btn_15_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_16, SEM1_btn_16_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_para, SEM1_para_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_1, SEM1_btn_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_option, SEM1_option_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_motsel, SEM1_motsel_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->SEM1_btn_17, SEM1_btn_17_event_handler, LV_EVENT_ALL, ui);
}
