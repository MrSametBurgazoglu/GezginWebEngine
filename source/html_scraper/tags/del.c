//
// Created by samet on 5.04.2022.
//

#include <malloc.h>
#include "del.h"

int choose_variable_for_del_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct del* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "cite")){
        widget_properties->cite = var_value;
    }
    else if(!strcmp(var_name, "datetime")){
        /*
         * TODO SET STRUCT VARIABLES WITH PARSING THIS TAG'S VALUE
         * */
    }
    return 0;
}

void set_widget_properties_for_del_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_del_tag;
    current_widget->widget_properties = malloc(sizeof(struct del));
}