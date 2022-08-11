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