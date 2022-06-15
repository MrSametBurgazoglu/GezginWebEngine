//
// Created by samet on 29.05.2022.
//

#include <string.h>
#include <stdlib.h>
#include "backdrop_filter.h"
#include "css_filter.h"

void backdrop_filter_property_set_value(struct css_properties* current_css_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_css_widget->backdropFilter_inherit = true;
    }
    else{
        char* start_index = strchr(value, '(');
        char* end_index = strchr(value, ')');
        if (start_index != NULL && end_index != NULL) {
            size_t len = end_index - start_index;
            size_t len2 = value - start_index;
            char *variables = malloc(len + 1);
            char *function_name = malloc(len2 + 1);
            memcpy(variables, start_index, len);
            memcpy(function_name, value, len2);
            variables[len] = '\0';
            function_name[len2] = '\0';
            set_filter_property(current_css_widget->backdrop_filter, function_name, variables);
        }
    }
}