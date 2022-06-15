//
// Created by samet on 8.04.2022.
//

#include <malloc.h>
#include <stdlib.h>
#include "textarea.h"

void choose_context_for_textarea_tag(struct widget* current_widget, char* context){
    struct textarea* widget_properties = current_widget->widget_properties;
    if(!strcmp(context, "autofocus")){
        widget_properties->autofocus = true;
    }
    else if(!strcmp(context, "disabled")){
        widget_properties->disabled = true;
    }
    else if(!strcmp(context, "readonly")){
        widget_properties->readonly = true;
    }
    else if(!strcmp(context, "required")){
        widget_properties->required = true;
    }
}

int choose_variable_for_textarea_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct textarea* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "col")){
        widget_properties->cols = (int)strtol(var_value, NULL, 10);
        return 1;
    }
    else if(!strcmp(var_name, "dirname")){
        widget_properties->dirname = var_value;
    }
    else if(!strcmp(var_name, "form")){
        widget_properties->form = var_value;
    }
    else if(!strcmp(var_name, "maxlength")){
        widget_properties->maxlength = (int)strtol(var_value, NULL, 10);
        return 1;
    }
    else if(!strcmp(var_name, "name")){
        widget_properties->name = var_value;
    }
    else if(!strcmp(var_name, "placeholder")){
        widget_properties->placeholder = var_value;
    }
    else if(!strcmp(var_name, "rows")){
        widget_properties->rows = (int)strtol(var_value, NULL, 10);
        return 1;
    }
    else if(!strcmp(var_name, "wrap")){
        if (!strcmp(var_value, "hard")){
            widget_properties->wrap = TEXTAREA_WRAP_HARD;
        }
        else if (!strcmp(var_value, "soft")){
            widget_properties->wrap = TEXTAREA_WRAP_SOFT;
        }
        return 1;
    }
    return 0;
}

void set_widget_properties_for_textarea_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_textarea_tag;
    current_widget->context_reader_func = choose_context_for_textarea_tag;
    current_widget->widget_properties = malloc(sizeof(struct textarea));
}