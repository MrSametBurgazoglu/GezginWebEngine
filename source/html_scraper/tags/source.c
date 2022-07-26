//
// Created by samet on 8.04.2022.
//

#include <malloc.h>
#include "source.h"

int choose_variable_for_source_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct source* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "media")){
        widget_properties->media = var_value;
    }
    else if(!strcmp(var_name, "sizes")){
        widget_properties->sizes = var_value;
    }
    else if(!strcmp(var_name, "src")){
        widget_properties->src = (var_value);
    }
    else if(!strcmp(var_name, "srcset")){
        widget_properties->srcset = (var_value);
    }
    else if(!strcmp(var_name, "type")){
        widget_properties->type = (var_value);
    }
    return 0;
}

void set_widget_properties_for_source_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_source_tag;
    current_widget->widget_properties = malloc(sizeof(struct source));
}