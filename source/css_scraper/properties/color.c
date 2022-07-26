//
// Created by samet on 18.05.2022.
//

#include "color.h"
#include "css_color.h"
#include <string.h>
#include <stdlib.h>

// for now this value will be only color name
void color_property_set_value(struct css_properties* current_css_widget, char* value){
    if(current_css_widget->color == NULL){
        current_css_widget->color = malloc(sizeof(struct color_rgba));
    }
    //TODO IMPLEMENT THIS
    if(!strcmp(value, "initial"))
    get_color(current_css_widget->color, value);
}