//
// Created by samet on 8.04.2022.
//

#include <malloc.h>
#include "output.h"

int choose_variable_for_output_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct output* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "for")){
        widget_properties->for_ = var_value;
    }
    else if(!strcmp(var_name, "form")){
        widget_properties->form = var_value;
    }
    else if(!strcmp(var_name, "name")){
        widget_properties->name = var_value;
    }
    return 1;
}

void set_widget_properties_for_output_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_output_tag;
    current_widget->widget_properties = (struct output*) malloc(sizeof(struct output));
}