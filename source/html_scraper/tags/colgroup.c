//
// Created by samet on 5.04.2022.
//

#include "colgroup.h"

int choose_variable_for_colgroup_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct colgroup* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "span")){
        widget_properties->number = (int)strtol(var_value, NULL, 10);
    }
    return 1;
}

void set_widget_properties_for_colgroup_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_colgroup_tag;
    current_widget->widget_properties = malloc(sizeof(struct colgroup));
}