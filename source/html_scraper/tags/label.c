//
// Created by samet on 7.04.2022.
//

#include <malloc.h>
#include "label.h"

int choose_variable_for_label_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct label* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "form")){
        widget_properties->form = var_value;
    }
    else if(!strcmp(var_name, "for")){
        widget_properties->for_ = var_value;
    }
    return 0;
}

void set_widget_properties_for_label_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_label_tag;
    current_widget->widget_properties = malloc(sizeof(struct label));
}