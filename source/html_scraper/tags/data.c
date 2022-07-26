//
// Created by samet on 5.04.2022.
//

#include <malloc.h>
#include "data.h"

int choose_variable_for_data_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct data* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "value")){
        widget_properties->value = var_value;
    }
    return 0;
}

void set_widget_properties_for_data_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_data_tag;
    current_widget->widget_properties = malloc(sizeof(struct data));
}