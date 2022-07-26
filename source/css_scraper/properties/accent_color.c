//
// Created by samet on 25.05.2022.
//

#include "css_color.h"
#include "../css_widget.h"
#include "string.h"
#include "accent_color.h"

#define ACCENT_DEFAULT_VALUE 0,0,0


void accent_color_property_set_value(struct css_properties* current_css_widget, char* value){
    if(!strcmp(value, "auto") || !strcmp(value ,"initial")){
        get_color_by_rgb(current_css_widget->accent_color, ACCENT_DEFAULT_VALUE);
        current_css_widget->accent_color_inherit = false;
    }
    else if (!strcmp(value, "inherit")){
        current_css_widget->accent_color_inherit = true;
    }
    else{
        get_color(current_css_widget->accent_color, value);
        current_css_widget->accent_color_inherit = false;
    }
}