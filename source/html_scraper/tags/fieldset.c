//
// Created by samet on 5.04.2022.
//

#include <malloc.h>
#include "fieldset.h"

void choose_context_for_fieldset_tag(struct widget* current_widget, char* context){
    struct fieldset* widget_properties = current_widget->widget_properties;
    if(!strcmp(context, "disabled")){
        widget_properties->disabled = true;
    }
}

int choose_variable_for_fieldset_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct fieldset* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "form")){
        widget_properties->form = var_value;
    }
    else if(!strcmp(var_name, "name")){
        widget_properties->name = var_value;
    }
    return 0;
}

void set_widget_properties_for_fieldset_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_fieldset_tag;
    current_widget->context_reader_func = choose_context_for_fieldset_tag;
    current_widget->widget_properties = malloc(sizeof(struct fieldset));
}