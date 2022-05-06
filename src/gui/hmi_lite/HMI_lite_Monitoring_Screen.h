#ifndef HMI_LITE_Monitoring_Screen_Lite_H
#define HMI_LITE_Monitoring_Screen_Lite_H
// #include "../general/gui_guider.h"
#include "lvgl.h"
#include "Arduino.h"
#include "HMI_Lite_Sources.h"
static lv_obj_t **Forward_Monitoring_Screen_Lite;
static lv_obj_t *Monitoring_Screen_Lite;

lv_obj_t *Monitoring_Screen_Lite_btn_UP;
lv_obj_t *Monitoring_Screen_Lite_btn_DOWN;
lv_obj_t *Monitoring_Screen_Lite_btn_BACK;
lv_obj_t *Monitoring_Screen_Lite_btn_OK;
lv_obj_t *Monitoring_Screen_Lite_label_1;


void (*setup_Forward_Monitoring_Screen_Lite)();
// static lv_obj_t *Backward_Screen_Lite;


static void Monitoring_Screen_Lite_btn_OK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(*Forward_Monitoring_Screen_Lite))
        {
			(*setup_Forward_Monitoring_Screen_Lite)();
        }
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
        {
			lv_scr_load_anim(*Forward_Monitoring_Screen_Lite, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
        }
	}
		break;
	default:
		break;
	}
}

void events_init_Monitoring_Screen_Lite()
{
	lv_obj_add_event_cb(Monitoring_Screen_Lite_btn_OK, Monitoring_Screen_Lite_btn_OK_event_handler, LV_EVENT_ALL, NULL);
}

static void setup_Monitoring_Screen_Lite(){

	//Write codes screen
	Monitoring_Screen_Lite = lv_obj_create(NULL);
	//Create 4 button
	//Write codes screen_btn_BACK
	Monitoring_Screen_Lite_btn_BACK= lv_btn_create(Monitoring_Screen_Lite);
	lite_setup_button(Monitoring_Screen_Lite_btn_BACK,5,85,"BACK");
	//Write codes screen_btn_UP
	Monitoring_Screen_Lite_btn_UP = lv_btn_create(Monitoring_Screen_Lite);
	lite_setup_button(Monitoring_Screen_Lite_btn_UP,45,85,"UP");
	//Write codes screen_btn_DOWN
	Monitoring_Screen_Lite_btn_DOWN = lv_btn_create(Monitoring_Screen_Lite);
	lite_setup_button(Monitoring_Screen_Lite_btn_DOWN,85,85,"DOWN");
	//Write codes screen_btn_OK
	Monitoring_Screen_Lite_btn_OK = lv_btn_create(Monitoring_Screen_Lite);
	lite_setup_button(Monitoring_Screen_Lite_btn_OK,125,85,"OK");
	//Write codes screen_1_label_1
	Monitoring_Screen_Lite_label_1 = lv_label_create(Monitoring_Screen_Lite);
	lite_setup_label(Monitoring_Screen_Lite_label_1,"Monitoring_Screen_Lite.title",31,30,100,32);
	events_init_Monitoring_Screen_Lite();
	//create nofitified bar
	lite_create_notified_bar(Monitoring_Screen_Lite);
}

// extern Monitoring_Screen_Lite_Data Monitoring_Screen_Lite_Data_1;
#endif
