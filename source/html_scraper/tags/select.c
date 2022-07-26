//
// Created by samet on 8.04.2022.
//

#include "select.h"

void choose_context_for_select_tag(struct widget* current_widget, char* context){
    struct select* widget_properties = current_widget->widget_properties;
    if(!strcmp(context, "autofocus")){
        widget_properties->autofocus = true;
    }
    else if(!strcmp(context, "disabled")){
        widget_properties->disabled = true;
    }
    else if(!strcmp(context, "multiple")){
        widget_properties->multiple = true;
    }
    else if(!strcmp(context, "required")){
        widget_properties->required = true;
    }
}

int choose_variable_for_select_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct select* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "form")){
        widget_properties->form = var_value;
    }
    else if(!strcmp(var_name, "name")){
        widget_properties->name = var_value;
    }
    else if(!strcmp(var_name, "size")){
        widget_properties->size = (int)strtol(var_value, NULL, 10);
        return 1;
    }
    return 0;
}

void set_widget_properties_for_select_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_select_tag;
    current_widget->context_reader_func = choose_context_for_select_tag;
    current_widget->widget_properties = malloc(sizeof(struct select));
}