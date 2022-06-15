//
// Created by samet on 7.04.2022.
//

#include "ol.h"

void choose_context_for_ol_tag(struct widget* current_widget, char* context){
    struct ol* widget_properties = current_widget->widget_properties;
    if(!strcmp(context, "reversed")){
        widget_properties->reversed = false;
    }
}

int choose_variable_for_ol_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct ol* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "start")){
        widget_properties->start = widget_properties->start = (int)strtol(var_value, NULL, 10);;
    }
    else if(!strcmp(var_name, "type")){
        if(!strcmp(var_value, "1")){
            widget_properties->type = OL_TYPE_1;
        }
        else if(!strcmp(var_value, "A")){
            widget_properties->type = OL_TYPE_A;
        }
        else if(!strcmp(var_value, "a")){
            widget_properties->type = OL_TYPE_a;
        }
        else if(!strcmp(var_value, "I")){
            widget_properties->type = OL_TYPE_I;
        }
        else if(!strcmp(var_value, "i")){
            widget_properties->type = OL_TYPE_i;
        }
    }
    return 1;
}

void set_widget_properties_for_ol_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_ol_tag;
    current_widget->context_reader_func = choose_context_for_ol_tag;
    current_widget->widget_properties = malloc(sizeof(struct ol));
}