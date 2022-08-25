//
// Created by samet on 11.08.2022.
//

#include "resize.h"
#include "../../functools/index_founder.h"

#include <string.h>
#include <stdlib.h>

#define RESIZE_STRING_COUNT 5


char* resize_strings[RESIZE_STRING_COUNT] = {
        "both",
        "horizontal",
        "none",
        "vertical",
};

css_resize_type resizeTypeList[RESIZE_STRING_COUNT] = {
        CSS_RESIZE_BOTH,
        CSS_RESIZE_HORIZONTAL,
        CSS_RESIZE_NONE,
        CSS_RESIZE_VERTICAL,
};

void set_resize(struct css_properties* current_widget, char* value){
    int index = get_index_from_list_by_string(resize_strings, value, RESIZE_STRING_COUNT);
    if (index != -1){
        current_widget->resize = resizeTypeList[index];
    }
    else{
        current_widget->resize = CSS_RESIZE_NONE;
    }
}

void resize_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->resize_inherit = true;
    }
    else{
        current_widget->resize_inherit = true;
        if(!strcmp(value, "initial")){
            current_widget->resize = CSS_RESIZE_NONE;
        }
        else{
            set_resize(current_widget, value);
        }
    }
}

void compute_resize(struct css_properties* dest, struct css_properties* source){
    if (dest->resize_inherit){
        dest->resize = source->resize;
    }
}