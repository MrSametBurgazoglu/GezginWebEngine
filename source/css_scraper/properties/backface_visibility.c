//
// Created by samet on 31.05.2022.
//

#include "backface_visibility.h"
#include "string.h"

void backface_visibility_property_set_value(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_widget->backface_visibility_inherit = true;
    }
    else if(!strcmp(value, "hidden")){
        current_widget->backfaceVisibility = CSS_VISIBILITY_HIDDEN;
    }
    else{
        current_widget->backfaceVisibility = CSS_VISIBILITY_VISIBLE;
    }
}