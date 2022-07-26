//
// Created by samet on 7.04.2022.
//

#include <malloc.h>
#include "li.h"

int choose_variable_for_li_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct li* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "value")){
        widget_properties->value = var_value;
    }
    return 0;
}

void set_widget_properties_for_li_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_li_tag;
    current_widget->widget_properties = malloc(sizeof(struct li));
}