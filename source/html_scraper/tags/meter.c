//
// Created by samet on 7.04.2022.
//

#include "meter.h"

int choose_variable_for_meter_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct meter* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "form")){
        widget_properties->form = var_value;
        return 0;
    }
    else if(!strcmp(var_name, "high")){
        widget_properties->high = strtof(var_value, NULL);
    }
    else if(!strcmp(var_name, "low")){
        widget_properties->low = strtof(var_value, NULL);
    }
    else if(!strcmp(var_name, "max")){
        widget_properties->max = strtof(var_value, NULL);
    }
    else if(!strcmp(var_name, "min")){
        widget_properties->min = strtof(var_value, NULL);
    }
    else if(!strcmp(var_name, "optimum")){
        widget_properties->optimum = strtof(var_value, NULL);
    }
    else if(!strcmp(var_name, "value")){
        widget_properties->value = strtof(var_value, NULL);
    }
    return 1;
}

void set_widget_properties_for_meter_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_meter_tag;
    current_widget->widget_properties = malloc(sizeof(struct meter));
}