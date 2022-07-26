//
// Created by samet on 5.04.2022.
//

#include <malloc.h>
#include "base.h"

int choose_variable_for_base_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct base* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "href")){
        widget_properties->href = var_value;
    }
    else if(!strcmp(var_name, "target")){
        if(!strcmp(var_value, "_blank")){
            widget_properties->target = FORM_TARGET_BLANK;
        }
        else if(!strcmp(var_value, "_self")){
            widget_properties->target = FORM_TARGET_SELF;
        }
        else if(!strcmp(var_value, "_parent")){
            widget_properties->target = FORM_TARGET_PARENT;
        }
        else if(!strcmp(var_value, "_top")){
            widget_properties->target = FORM_TARGET_TOP;
        }
        return 1;
    }
    return 0;
}

void set_widget_properties_for_base_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_base_tag;
    current_widget->widget_properties = malloc(sizeof(struct base));
}