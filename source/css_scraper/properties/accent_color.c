//
// Created by samet on 25.05.2022.
//

#include <stdlib.h>
#include "css_color.h"
#include "../css_widget.h"
#include "string.h"
#include "accent_color.h"

#define ACCENT_DEFAULT_VALUE 0,0,0


//TODO MAKE IT BETTER
void accent_color_property_set_value(struct css_properties* current_css_widget, char * value){
    if(!strcmp(value, "auto") || !strcmp(value ,"initial")){
        current_css_widget->accent_color = get_color_by_rgb(ACCENT_DEFAULT_VALUE);
    }
    else if (!strcmp(value, "inherit")){
        current_css_widget->accent_color_inherit = true;
    }
    else{
        current_css_widget->accent_color =  get_color(value);
    }
}