//
// Created by samet on 8.04.2022.
//

#include <malloc.h>
#include "time.h"

int choose_variable_for_time_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct time* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "datetime")){//NEED AN ALGORITHM TO PARSE STRING
        widget_properties->year = 0;
    }
    return 1;
}

void set_widget_properties_for_time_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_time_tag;
    current_widget->widget_properties = malloc(sizeof(struct time));
}