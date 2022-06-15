//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_AREA_H
#define UNTITLED_AREA_H

#include "../../widget.h"
#include <string.h>

int choose_variable_for_area_tag(struct widget* current_widget, char* var_name, char* var_value);

void set_widget_properties_for_area_tag(struct widget*);

struct area{
    char* alt;
    int* coords_x;
    int* coords_y;
    char* download;
    char* href;
    char* hreflang;
    //char* media; not supported yet
    referrer_policy referrerpolicy;
    form_rel rel;
    shape area_shape;
    form_target target;
    char* media_type;
};

#endif //UNTITLED_AREA_H
