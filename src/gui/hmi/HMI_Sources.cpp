#include "HMI_Sources.h"
#include"Arduino.h"

lv_obj_t *Screen_notified_obj;
lv_obj_t *Screen_label_wifi;
lv_obj_t *Screen_label_bluetooth;
lv_obj_t *Screen_label_warning;
lv_obj_t *Screen_label_SD;
lv_obj_t *Screen_label_modbus_active;
lv_obj_t *Screen_label_time;

typedef struct Notified_Bar
{
	int temperature = 23, humidity = 75;
	int hour = 14, minute = 10;
	char time[10], information[100];
};

Notified_Bar Notified_Bar;

void setup_button(lv_obj_t *button, int pos_x, int pos_y, char * button_label_str)
{
    lv_obj_set_pos(button, pos_x, pos_y);
	lv_obj_set_size(button, 30, 15);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn
	static lv_style_t style_button ;
	if (style_button.prop_cnt > 1)
		lv_style_reset(&style_button);
	else
		lv_style_init(&style_button);
	lv_style_set_radius(&style_button, 5);
	lv_style_set_bg_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_button, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_button, 255);
	lv_style_set_shadow_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_button, 255);
	lv_style_set_border_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_button, 0);
	lv_style_set_border_opa(&style_button, 255);
	lv_obj_add_style(button, &style_button, LV_PART_MAIN|LV_STATE_DEFAULT);

	lv_obj_t *btn_label;
	btn_label = lv_label_create(button);
    lv_label_set_text(btn_label, button_label_str);
    lv_obj_set_style_text_color(btn_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(btn_label, &lv_font_montserrat_8, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(button, 0, LV_STATE_DEFAULT);
    lv_obj_align(btn_label, LV_ALIGN_CENTER, 0, 0);
}

void setup_label(lv_obj_t *label, char* label_text,int pos_x, int pos_y, int width,int height)
{
	lv_obj_set_pos(label, pos_x, pos_y);
	lv_obj_set_size(label, width, height);
	lv_label_set_text(label, label_text);
	lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
}
void setup_roller(lv_obj_t *roller, char* option,int row_count, int align,int width, int pos_x, int pos_y)
{
	lv_roller_set_options(roller, option, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller, row_count);
    lv_obj_set_width(roller, width);
	lv_obj_align(roller, align, pos_x, pos_y);
}

/*
Create notified bar for screen: icon wifi, bluetooth, warning, modbus active, SD Card, time
*/
void create_notified_bar(lv_obj_t *screen)
{
	//create notified obj
	Screen_notified_obj = lv_obj_create(screen);
	lv_obj_set_pos(Screen_notified_obj, 0, 0);
	lv_obj_set_size(Screen_notified_obj, 240, 20);
	//create font wifi
	Screen_label_wifi = lv_label_create(Screen_notified_obj);
	setup_label(Screen_label_wifi,"wifi",-15,-15,30,30);
	lv_label_set_text(Screen_label_wifi,LV_SYMBOL_WIFI);
	//create font bluetooth
	Screen_label_bluetooth = lv_label_create(Screen_notified_obj);
	setup_label(Screen_label_bluetooth,"bluetooth",5,-15,30,30);
	lv_label_set_text(Screen_label_bluetooth,LV_SYMBOL_BLUETOOTH);
	//create font warning
	Screen_label_warning = lv_label_create(Screen_notified_obj);
	setup_label(Screen_label_warning,"warning",25,-15,30,30);
	lv_label_set_text(Screen_label_warning,LV_SYMBOL_WARNING);
	//create font modbus_active
	Screen_label_modbus_active = lv_label_create(Screen_notified_obj);
	setup_label(Screen_label_modbus_active,"modbus_active",45,-15,30,30);
	lv_label_set_text(Screen_label_modbus_active,LV_SYMBOL_REFRESH);
	//create font SD
	Screen_label_SD = lv_label_create(Screen_notified_obj);
	setup_label(Screen_label_SD,"SD Card",70,-15,10,15);
	lv_label_set_text(Screen_label_SD,LV_SYMBOL_SD_CARD);

	//create label time
	Screen_label_time = lv_label_create(Screen_notified_obj);
	sprintf(Notified_Bar.time, "%d:%d",Notified_Bar.hour,Notified_Bar.minute);
	setup_label(Screen_label_time, Notified_Bar.time,170,-15,40,30); 
}