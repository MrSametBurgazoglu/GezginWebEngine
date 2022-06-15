//
// Created by samet on 5.04.2022.
//

#include <malloc.h>
#include "bdo.h"

int choose_variable_for_bdo_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct bdo* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "dir")){
        if(!strcmp(var_value, "rtl")){
            widget_properties->direction = HTML_RIGHT;
        }
        else if(!strcmp(var_value, "ltr")){
            widget_properties->direction = HTML_LEFT;
        }
    }
    return 1;
}

void set_widget_properties_for_bdo_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_bdo_tag;
    current_widget->widget_properties = malloc(sizeof(struct bdo));
}