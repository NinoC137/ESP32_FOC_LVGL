/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"


void init_scr_del_flag(lv_ui *ui){
	ui->MAIN_del = true;
	ui->menu_del = true;
	ui->TYPE_del = true;
	ui->OTHERS_del = true;
	ui->SET_del = true;
	ui->WIFI_del = true;
	ui->SEM1_del = true;
}

void setup_ui(lv_ui *ui){
	init_scr_del_flag(ui);
	setup_scr_MAIN(ui);
	lv_scr_load(ui->MAIN);
}
