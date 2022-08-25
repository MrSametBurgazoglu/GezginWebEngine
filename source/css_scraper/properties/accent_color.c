//
// Created by samet on 25.05.2022.
//

#include "css_color.h"
#include "../css_widget.h"
#include "string.h"
#include "accent_color.h"

#include <stdlib.h>

void accent_color_property_set_value(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_widget->accent_color_inherit = true;
    }
    else{
        current_widget->accent_color_inherit = false;
        if(current_widget->accent_color == NULL || current_widget->accent_color_inherit){
            current_widget->accent_color = malloc(sizeof(struct color_rgba));
        }
        if(!strcmp(value, "auto") || !strcmp(value ,"initial")){
            get_color_by_rgb(current_widget->accent_color, 0, 0, 0);
        }
        else{
            get_color(current_widget->accent_color, value);
        }
    }
}

void compute_inherit_accent_color(struct css_properties* dest, struct css_properties* source){
    if(dest->accent_color == NULL){
        dest->accent_color = source->accent_color;
    }
}

void free_accent_color(struct css_properties* current_widget){
    free(current_widget->accent_color);
}