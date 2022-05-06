/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "HMI_Lite_Sources.h"

static lv_obj_t **Back_Detail_Screen_Lite;
static lv_obj_t *Detail_Screen_Lite;

lv_obj_t *Detail_Screen_Lite_btn_UP;
lv_obj_t *Detail_Screen_Lite_btn_DOWN;
lv_obj_t *Detail_Screen_Lite_btn_BACK;
lv_obj_t *Detail_Screen_Lite_btn_OK;
lv_obj_t *Detail_Screen_Lite_label_1;

void (*setup_Back_Detail_Screen_Lite)();

static void Detail_Screen_Lite_btn_BACK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(*Back_Detail_Screen_Lite))
			(*setup_Back_Detail_Screen_Lite)();
		//pointer to object's dispaly
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(*Back_Detail_Screen_Lite, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
	}
		break;
	default:
		break;
	}
}

void events_init_Detail_Screen_Lite()
{
	lv_obj_add_event_cb(Detail_Screen_Lite_btn_BACK, Detail_Screen_Lite_btn_BACK_event_handler, LV_EVENT_ALL, NULL);
}
void setup_Detail_Screen_Lite(){
   //Write codes screen_1
	Detail_Screen_Lite = lv_obj_create(NULL);
	
	//Create 4 button
	//Write codes screen_btn_BACK
	Detail_Screen_Lite_btn_BACK= lv_btn_create(Detail_Screen_Lite);
	lite_setup_button(Detail_Screen_Lite_btn_BACK,5,85,"BACK");
	//Write codes screen_btn_UP
	Detail_Screen_Lite_btn_UP = lv_btn_create(Detail_Screen_Lite);
	lite_setup_button(Detail_Screen_Lite_btn_UP,45,85,"UP");
	//Write codes screen_btn_DOWN
	Detail_Screen_Lite_btn_DOWN = lv_btn_create(Detail_Screen_Lite);
	lite_setup_button(Detail_Screen_Lite_btn_DOWN,85,85,"DOWN");
	//Write codes screen_btn_OK
	Detail_Screen_Lite_btn_OK = lv_btn_create(Detail_Screen_Lite);
	lite_setup_button(Detail_Screen_Lite_btn_OK,125,85,"OK");

	//Write codes screen_1_label_1
	Detail_Screen_Lite_label_1 = lv_label_create(Detail_Screen_Lite);
	lite_setup_label(Detail_Screen_Lite_label_1,"SCREEN DETAIL",31,30,100,32);
	//create notified bar for detail screen
	lite_create_notified_bar(Detail_Screen_Lite);
	events_init_Detail_Screen_Lite();
}
