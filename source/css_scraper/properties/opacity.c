//
// Created by samet on 11.08.2022.
//

#include "visibility.h"

#include <string.h>
#include <stdlib.h>

void set_opacity(struct css_properties* current_widget, char* value){
    float float_value = strtof(value, NULL);
    current_widget->opacity = float_value;
}

void opacity_property_set_value(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_widget->opacity_inherit = true;
    }
    else{
        current_widget->opacity_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->opacity = 1;
        }
        else{
            set_opacity(current_widget, value);
        }
    }
}

void compute_inherit_opacity(struct css_properties* dest, struct css_properties* source){
    if (dest->opacity_inherit){
        dest->opacity = source->opacity;
    }
}