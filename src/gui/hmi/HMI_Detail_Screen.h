#include "lvgl.h"
#include <stdio.h>
#include "HMI_Sources.h"

static lv_obj_t **Back_Detail_Screen;
static lv_obj_t *Detail_Screen;

lv_obj_t *Detail_Screen_btn_MENU;
lv_obj_t *Detail_Screen_btn_UP;
lv_obj_t *Detail_Screen_btn_DOWN;
lv_obj_t *Detail_Screen_btn_BACK;
lv_obj_t *Detail_Screen_btn_OK;
lv_obj_t *Detail_Screen_btn_ALARM;
lv_obj_t *Detail_Screen_label_1;

void (*setup_Back_Detail_Screen)();

static void Detail_Screen_btn_BACK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(*Back_Detail_Screen))
			(*setup_Back_Detail_Screen)();
		//pointer to object's dispaly
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(*Back_Detail_Screen, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
	}
		break;
	default:
		break;
	}
}

void events_init_Detail_Screen()
{
	lv_obj_add_event_cb(Detail_Screen_btn_BACK, Detail_Screen_btn_BACK_event_handler, LV_EVENT_ALL, NULL);
}
void setup_Detail_Screen(){
   //Write codes screen_1
	Detail_Screen = lv_obj_create(NULL);
	
	//Create 6 button
    //Write codes Detail_Screen_btn_MENU
    Detail_Screen_btn_MENU = lv_btn_create(Detail_Screen);
    setup_button(Detail_Screen_btn_MENU,5,245,"MENU");
    //Write codes Detail_Screen_btn_UP
    Detail_Screen_btn_UP = lv_btn_create(Detail_Screen);
    setup_button(Detail_Screen_btn_UP,85,245,"UP");
    //Write codes Detail_Screen_btn_BACK
    Detail_Screen_btn_BACK= lv_btn_create(Detail_Screen);
    setup_button(Detail_Screen_btn_BACK,45,245,"BACK");
    //Write codes Detail_Screen_btn_DOWN
    Detail_Screen_btn_DOWN= lv_btn_create(Detail_Screen);
    setup_button(Detail_Screen_btn_DOWN,125,245,"DOWN");
    //Write codes Detail_Screen_btn_OK
    Detail_Screen_btn_OK = lv_btn_create(Detail_Screen);
    setup_button(Detail_Screen_btn_OK,165,245,"OK");
    //Write codes Detail_Screen_btn_ALARM
    Detail_Screen_btn_ALARM = lv_btn_create(Detail_Screen);
    setup_button(Detail_Screen_btn_ALARM,205,245,"ALARM");

	//Write codes screen_1_label_1
	Detail_Screen_label_1 = lv_label_create(Detail_Screen);
	setup_label(Detail_Screen_label_1,"SCREEN DETAIL",31,30,100,32);
	//create notified bar for detail screen
	create_notified_bar(Detail_Screen);
	events_init_Detail_Screen();
}