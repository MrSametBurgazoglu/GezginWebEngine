//
// Created by samet on 8.04.2022.
//

#include "td.h"

int choose_variable_for_td_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct td* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "colspan")){
        widget_properties->colspan = (int)strtol(var_value, NULL, 10);
    }
    else if(!strcmp(var_name, "headers")){
        widget_properties->headers = var_value;
        return 0;
    }
    else if(!strcmp(var_name, "rowspan")){
        widget_properties->rowspan = (int)strtol(var_value, NULL, 10);
    }
    return 1;
}

void set_widget_properties_for_td_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_td_tag;
    current_widget->widget_properties = malloc(sizeof(struct td));
}