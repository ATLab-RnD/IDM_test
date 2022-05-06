#ifndef HMI_LITE_Monitoring_SCREEN_H
#define HMI_LITE_Monitoring_SCREEN_H
// #include "../general/gui_guider.h"
#include "lvgl.h"
#include "Arduino.h"
#include "HMI_Sources.h"
static lv_obj_t **Forward_Monitoring_Screen;
static lv_obj_t *Monitoring_Screen;

lv_obj_t *Monitoring_Screen_btn_UP;
lv_obj_t *Monitoring_Screen_btn_DOWN;
lv_obj_t *Monitoring_Screen_btn_BACK;
lv_obj_t *Monitoring_Screen_btn_OK;
lv_obj_t *Monitoring_Screen_label_1;
lv_obj_t *Monitoring_Screen_btn_MENU;
lv_obj_t *Monitoring_Screen_btn_ALARM;

void (*setup_Forward_Monitoring_Screen)();
// static lv_obj_t *Backward_screen;


static void Monitoring_Screen_btn_OK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(*Forward_Monitoring_Screen))
        {
			(*setup_Forward_Monitoring_Screen)();
        }
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
        {
			lv_scr_load_anim(*Forward_Monitoring_Screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
        }
	}
		break;
	default:
		break;
	}
}

void events_init_Monitoring_Screen()
{
	lv_obj_add_event_cb(Monitoring_Screen_btn_OK, Monitoring_Screen_btn_OK_event_handler, LV_EVENT_ALL, NULL);
}

static void setup_Monitoring_Screen(){

	//Write codes screen
	Monitoring_Screen = lv_obj_create(NULL);
	//Create 6 button
    //Write codes Monitoring_Screen_btn_MENU
    Monitoring_Screen_btn_MENU = lv_btn_create(Monitoring_Screen);
    setup_button(Monitoring_Screen_btn_MENU,5,245,"MENU");
    //Write codes Monitoring_Screen_btn_UP
    Monitoring_Screen_btn_UP = lv_btn_create(Monitoring_Screen);
    setup_button(Monitoring_Screen_btn_UP,85,245,"UP");
    //Write codes Monitoring_Screen_btn_BACK
    Monitoring_Screen_btn_BACK= lv_btn_create(Monitoring_Screen);
    setup_button(Monitoring_Screen_btn_BACK,45,245,"BACK");
    //Write codes Monitoring_Screen_btn_DOWN
    Monitoring_Screen_btn_DOWN= lv_btn_create(Monitoring_Screen);
    setup_button(Monitoring_Screen_btn_DOWN,125,245,"DOWN");
    //Write codes Monitoring_Screen_btn_OK
    Monitoring_Screen_btn_OK = lv_btn_create(Monitoring_Screen);
    setup_button(Monitoring_Screen_btn_OK,165,245,"OK");
    //Write codes Monitoring_Screen_btn_ALARM
    Monitoring_Screen_btn_ALARM = lv_btn_create(Monitoring_Screen);
    setup_button(Monitoring_Screen_btn_ALARM,205,245,"ALARM");
	//Write codes screen_1_label_1
	Monitoring_Screen_label_1 = lv_label_create(Monitoring_Screen);
	setup_label(Monitoring_Screen_label_1,"Monitoring_Screen.title",31,30,100,32);
	events_init_Monitoring_Screen();
	//create nofitified bar
	create_notified_bar(Monitoring_Screen);
}

// extern Monitoring_Screen_Data Monitoring_Screen_Data_1;
#endif
