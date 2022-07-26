//
// Created by samet on 8.04.2022.
//

#include "th.h"

int choose_variable_for_th_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct th* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "abbr")){
        widget_properties->abbr = var_value;
    }
    else if(!strcmp(var_name, "colspan")){
        widget_properties->colspan = (int)strtol(var_value, NULL, 10);
        return 1;
    }
    else if(!strcmp(var_name, "headers")){
        widget_properties->headers = var_value;
    }
    else if(!strcmp(var_name, "rowspan")){
        widget_properties->rowspan = (int)strtol(var_value, NULL, 10);
        return 1;
    }
    else if(!strcmp(var_name, "scope")){
        if (!strcmp(var_value, "col")){
            widget_properties->scope = TABLE_SCOPE_COL;
        }
        else if (!strcmp(var_value, "colgroup")){
            widget_properties->scope = TABLE_SCOPE_COLGROUP;
        }
        else if (!strcmp(var_value, "row")){
            widget_properties->scope = TABLE_SCOPE_ROW;
        }
        else if (!strcmp(var_value, "rowgroup")){
            widget_properties->scope = TABLE_SCOPE_ROWGROUP;
        }
        return 1;
    }
    return 0;
}

void set_widget_properties_for_th_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_th_tag;
    current_widget->widget_properties = malloc(sizeof(struct th));
}