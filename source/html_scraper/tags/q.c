//
// Created by samet on 8.04.2022.
//

#include <malloc.h>
#include "q.h"

int choose_variable_for_q_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct q* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "cite")){
        widget_properties->cite = var_value;
    }
    return 0;
}

void set_widget_properties_for_q_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_q_tag;
    current_widget->widget_properties = malloc(sizeof(struct q));
}