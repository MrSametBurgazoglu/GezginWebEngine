//
// Created by samet on 7.04.2022.
//

#include <malloc.h>
#include "optgroup.h"

void choose_context_for_optgroup_tag(struct widget* current_widget, char* context){
    struct optgroup* widget_properties = current_widget->widget_properties;
    if(!strcmp(context, "disabled")){
        widget_properties->disabled = true;
    }
}

int choose_variable_for_optgroup_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct optgroup* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "label")){
        widget_properties->label = var_value;
    }
    return 0;
}

void set_widget_properties_for_optgroup_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_optgroup_tag;
    current_widget->context_reader_func = choose_context_for_optgroup_tag;
    current_widget->widget_properties = malloc(sizeof(struct optgroup));
}