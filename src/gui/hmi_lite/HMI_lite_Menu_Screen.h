#ifndef HMI_LITE_Menu_Screen_Lite_H
#define HMI_LITE_Menu_Screen_Lite_H
// #include "../general/gui_guider.h"
#include "lvgl.h"
#include "Arduino.h"
#include "HMI_Lite_Sources.h"
static lv_obj_t **Forward_Menu_Screen_Lite;
static lv_obj_t **Back_Menu_Screen_Lite;
static lv_obj_t *Menu_Screen_Lite;

lv_obj_t *Menu_Screen_Lite_btn_UP;
lv_obj_t *Menu_Screen_Lite_btn_DOWN;
lv_obj_t *Menu_Screen_Lite_btn_BACK;
lv_obj_t *Menu_Screen_Lite_btn_OK;
lv_obj_t *Menu_Screen_Lite_label_1;
lv_obj_t *Menu_Screen_Lite_label_2;
lv_obj_t *Menu_Screen_Lite_roller;

typedef struct 
{
	char Option[100]="Connection\nMeasure\nLog Data\nFault & Alarm\nOthers\nDebug\nAbout";
}Menu_Option;

Menu_Option Menu_Option_1;
void (*setup_Forward_Menu_Screen_Lite)();
void (*setup_Back_Menu_Screen_Lite)();
// static lv_obj_t *Backward_Screen_Lite_1;


static void Menu_Screen_Lite_btn_OK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(*Forward_Menu_Screen_Lite))
		{
			(*setup_Forward_Menu_Screen_Lite)();
		}
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
        {
			lv_scr_load_anim(*Forward_Menu_Screen_Lite, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
        }
	}
		break;
	default:
		break;
	}
}
static void Menu_Screen_Lite_btn_BACK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(*Back_Menu_Screen_Lite))
			(*setup_Back_Menu_Screen_Lite)();
		//pointer to object's dispaly
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(*Back_Menu_Screen_Lite, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
	}
		break;
	default:
		break;
	}
}
static void Menu_Screen_Lite_btn_UP_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		uint8_t roller_selected = lv_roller_get_selected(Menu_Screen_Lite_roller);
		roller_selected++;
		lv_roller_set_selected(Menu_Screen_Lite_roller,roller_selected,LV_ANIM_ON);
	}
		break;
	default:
		break;
	}
}
static void Menu_Screen_Lite_btn_DOWN_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		uint8_t roller_selected = lv_roller_get_selected(Menu_Screen_Lite_roller);
		roller_selected--;
		lv_roller_set_selected(Menu_Screen_Lite_roller,roller_selected,LV_ANIM_ON);
	}
		break;
	default:
		break;
	}
}
void events_init_Menu_Screen_Lite()
{
	lv_obj_add_event_cb(Menu_Screen_Lite_btn_OK, Menu_Screen_Lite_btn_OK_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(Menu_Screen_Lite_btn_BACK, Menu_Screen_Lite_btn_BACK_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(Menu_Screen_Lite_btn_UP, Menu_Screen_Lite_btn_UP_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(Menu_Screen_Lite_btn_DOWN, Menu_Screen_Lite_btn_DOWN_event_handler, LV_EVENT_ALL, NULL);
}

static void setup_Menu_Screen_Lite(){

	//Write codes Screen_1
	Menu_Screen_Lite = lv_obj_create(NULL);
	//Create 4 button
	//Write codes Screen_1_btn_BACK
	Menu_Screen_Lite_btn_BACK= lv_btn_create(Menu_Screen_Lite);
	lite_setup_button(Menu_Screen_Lite_btn_BACK,5,85,"BACK");
	//Write codes Screen_1_btn_UP
	Menu_Screen_Lite_btn_UP = lv_btn_create(Menu_Screen_Lite);
	lite_setup_button(Menu_Screen_Lite_btn_UP,45,85,"UP");
	//Write codes Screen_1_btn_DOWN
	Menu_Screen_Lite_btn_DOWN = lv_btn_create(Menu_Screen_Lite);
	lite_setup_button(Menu_Screen_Lite_btn_DOWN,85,85,"DOWN");
	//Write codes Screen_1_btn_OK
	Menu_Screen_Lite_btn_OK = lv_btn_create(Menu_Screen_Lite);
	lite_setup_button(Menu_Screen_Lite_btn_OK,125,85,"OK");
	
	//create roller Menu
	Menu_Screen_Lite_roller = lv_roller_create(Menu_Screen_Lite);
	lite_setup_roller(Menu_Screen_Lite_roller,Menu_Option_1.Option,2,LV_ALIGN_CENTER,100,0,5);

	create_notified_bar(Menu_Screen_Lite);
	events_init_Menu_Screen_Lite();
}

// extern Menu_Screen_Lite_Data Menu_Screen_Lite_Data_1;
#endif
