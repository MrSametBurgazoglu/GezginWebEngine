//
// Created by samet on 8.04.2022.
//

#include "progress.h"

int choose_variable_for_progress_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct progress* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "max")){
        widget_properties->max = strtof(var_value, NULL);
    }
    else if(!strcmp(var_name, "value")){
        widget_properties->value = strtof(var_value, NULL);
    }
    return 1;
}

void set_widget_properties_for_progress_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_progress_tag;
    current_widget->widget_properties = malloc(sizeof(struct progress));
}