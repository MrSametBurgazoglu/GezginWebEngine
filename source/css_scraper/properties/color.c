//
// Created by samet on 18.05.2022.
//

#include "color.h"
#include "css_color.h"

// for now this value will be only color name
void color_property_set_value(struct css_properties* current_css_widget, char * value){
    current_css_widget->color = get_color(value);
}