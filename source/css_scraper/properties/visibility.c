//
// Created by samet on 11.08.2022.
//

#include "visibility.h"

#include <string.h>
#include <stdlib.h>

void set_visibility(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "hidden")){
        current_widget->visibility = CSS_VISIBILITY_HIDDEN;
    }
    else if(!strcmp(value, "collapse")){
        current_widget->visibility = CSS_VISIBILITY_COLLAPSE;
    }
    else{
        current_widget->visibility = CSS_VISIBILITY_VISIBLE;
    }
}

void visibility_property_set_value(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_widget->visibility_inherit = true;
    }
    else{
        current_widget->visibility_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->visibility = CSS_VISIBILITY_VISIBLE;
        }
        else {
            set_visibility(current_widget, value);
        }
    }
}

void compute_inherit_visibility(struct css_properties* dest, struct css_properties* source){
    if (dest->visibility == CSS_VISIBILITY_EMPTY){
        dest->visibility = source->visibility;
    }
}

void update_visibility(struct css_properties* current_widget, struct css_properties* source){
    if(source->visibility_inherit){
        current_widget->visibility_inherit = true;
    }
    else if (source->visibility != CSS_VISIBILITY_EMPTY){
        current_widget->visibility = source->visibility;
    }
}