#ifndef HMI_LITE_Menu_Screen_H
#define HMI_LITE_Menu_Screen_H
#include "lvgl.h"
#include "Arduino.h"
#include "HMI_Sources.h"
static lv_obj_t **Forward_Menu_Screen;
static lv_obj_t **Back_Menu_Screen;
static lv_obj_t *Menu_Screen;

lv_obj_t *Menu_Screen_btn_UP;
lv_obj_t *Menu_Screen_btn_DOWN;
lv_obj_t *Menu_Screen_btn_BACK;
lv_obj_t *Menu_Screen_btn_OK;
lv_obj_t *Menu_Screen_btn_MENU;
lv_obj_t *Menu_Screen_btn_ALARM;
lv_obj_t *Menu_Screen_label_1;
lv_obj_t *Menu_Screen_label_2;
lv_obj_t *Menu_Screen_roller;

typedef struct 
{
	char Option[100]="Connection\nMeasure\nLog Data\nFault & Alarm\nOthers\nDebug\nAbout";
}Menu_Option;

Menu_Option Menu_Option_1;
void (*setup_Forward_Menu_Screen)();
void (*setup_Back_Menu_Screen)();
// static lv_obj_t *Backward_Screen_1;


static void Menu_Screen_btn_OK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(*Forward_Menu_Screen))
		{
			(*setup_Forward_Menu_Screen)();
		}
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
        {
			lv_scr_load_anim(*Forward_Menu_Screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
        }
	}
		break;
	default:
		break;
	}
}
static void Menu_Screen_btn_BACK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(*Back_Menu_Screen))
			(*setup_Back_Menu_Screen)();
		//pointer to object's dispaly
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(*Back_Menu_Screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
	}
		break;
	default:
		break;
	}
}
static void Menu_Screen_btn_UP_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		uint8_t roller_selected = lv_roller_get_selected(Menu_Screen_roller);
		roller_selected++;
		lv_roller_set_selected(Menu_Screen_roller,roller_selected,LV_ANIM_ON);
	}
		break;
	default:
		break;
	}
}
static void Menu_Screen_btn_DOWN_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		uint8_t roller_selected = lv_roller_get_selected(Menu_Screen_roller);
		roller_selected--;
		lv_roller_set_selected(Menu_Screen_roller,roller_selected,LV_ANIM_ON);
	}
		break;
	default:
		break;
	}
}
void events_init_Menu_Screen()
{
	lv_obj_add_event_cb(Menu_Screen_btn_OK, Menu_Screen_btn_OK_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(Menu_Screen_btn_BACK, Menu_Screen_btn_BACK_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(Menu_Screen_btn_UP, Menu_Screen_btn_UP_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(Menu_Screen_btn_DOWN, Menu_Screen_btn_DOWN_event_handler, LV_EVENT_ALL, NULL);
}

static void setup_Menu_Screen(){

	//Write codes Screen_1
	Menu_Screen = lv_obj_create(NULL);
	//Create 6 button
    //Write codes Menu_Screen_btn_MENU
    Menu_Screen_btn_MENU = lv_btn_create(Menu_Screen);
    setup_button(Menu_Screen_btn_MENU,5,245,"MENU");
    //Write codes Menu_Screen_btn_UP
    Menu_Screen_btn_UP = lv_btn_create(Menu_Screen);
    setup_button(Menu_Screen_btn_UP,85,245,"UP");
    //Write codes Menu_Screen_btn_BACK
    Menu_Screen_btn_BACK= lv_btn_create(Menu_Screen);
    setup_button(Menu_Screen_btn_BACK,45,245,"BACK");
    //Write codes Menu_Screen_btn_DOWN
    Menu_Screen_btn_DOWN= lv_btn_create(Menu_Screen);
    setup_button(Menu_Screen_btn_DOWN,125,245,"DOWN");
    //Write codes Menu_Screen_btn_OK
    Menu_Screen_btn_OK = lv_btn_create(Menu_Screen);
    setup_button(Menu_Screen_btn_OK,165,245,"OK");
    //Write codes Menu_Screen_btn_ALARM
    Menu_Screen_btn_ALARM = lv_btn_create(Menu_Screen);
    setup_button(Menu_Screen_btn_ALARM,205,245,"ALARM");
	
	//create roller Menu
	Menu_Screen_roller = lv_roller_create(Menu_Screen);
	setup_roller(Menu_Screen_roller,Menu_Option_1.Option,2,LV_ALIGN_CENTER,100,0,5);

	create_notified_bar(Menu_Screen);
	events_init_Menu_Screen();
}

// extern Menu_Screen_Data Menu_Screen_Data_1;
#endif
