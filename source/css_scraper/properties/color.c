//
// Created by samet on 18.05.2022.
//

#include "color.h"
#include "css_color.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void color_property_set_value(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_widget->color_inherit = true;
    }
    else{
        current_widget->color_inherit = false;
        if(current_widget->color == NULL){
            current_widget->color = malloc(sizeof(struct color_rgba));
        }
        get_color(current_widget->color, value);
    }
}

void compute_inherit_color(struct css_properties* dest, struct css_properties* source){
    if (dest->color == NULL){
        dest->color = source->color;
    }
}

void free_color(struct css_properties* current_widget){
    free(current_widget->color);
}

void update_color(struct css_properties* current_widget, struct css_properties* source){
    if(source->color_inherit){
        current_widget->color_inherit = true;
        current_widget->color = NULL;
    }
    else if (source->color != NULL){
        current_widget->color = source->color;
    }
}