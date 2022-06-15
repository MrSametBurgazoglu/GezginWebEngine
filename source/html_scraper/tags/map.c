//
// Created by samet on 7.04.2022.
//

#include <malloc.h>
#include "map.h"

int choose_variable_for_map_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct map* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "name")){
        widget_properties->name = var_value;
    }
    return 0;
}

void set_widget_properties_for_map_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_map_tag;
    current_widget->widget_properties = malloc(sizeof(struct map));
}