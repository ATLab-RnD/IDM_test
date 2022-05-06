#ifndef HMI_LITE_SOURCES_H
#define HMI_LITE_SOURCES_H

#include "lvgl.h"


void setup_button(lv_obj_t *button, int pos_x, int pos_y, char * button_label_str);
void setup_label(lv_obj_t *label, char* label_text,int pos_x, int pos_y, int width,int height);
void setup_roller(lv_obj_t *roller, char* option,int row_count, int align,int width, int pos_x, int pos_y);
void create_notified_bar(lv_obj_t *screen);
#endif