//
// Created by samet on 7.04.2022.
//

#include <malloc.h>
#include "option.h"

void choose_context_for_option_tag(struct widget* current_widget, char* context){
    struct option* widget_properties = current_widget->widget_properties;
    if(!strcmp(context, "disabled")){
        widget_properties->disabled = true;
    }
    else if(!strcmp(context, "selected")){
        widget_properties->selected = true;
    }
}

int choose_variable_for_option_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct option* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "label")){
        widget_properties->label = var_value;
    }
    else if(!strcmp(var_name, "value")){
        widget_properties->value = var_value;
    }
    return 0;
}

void set_widget_properties_for_option_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_option_tag;
    current_widget->context_reader_func = choose_context_for_option_tag;
    current_widget->widget_properties = malloc(sizeof(struct option));
}