//
// Created by samet on 7.04.2022.
//

#include <malloc.h>
#include "meta.h"

int choose_variable_for_meta_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct meta* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "charset")){
        widget_properties->charset = var_value;
    }
    else if(!strcmp(var_name, "content")){
        widget_properties->content = var_value;
    }
    else if(!strcmp(var_name, "http-equiv")){
        if(!strcmp(var_value, "content-security-policy")){
            widget_properties->equiv = HTTP_EQUIV_CONTENT_SECURITY_POLICY;
        }
        else if(!strcmp(var_value, "content-type")){
            widget_properties->equiv = HTTP_EQUIV_CONTENT_TYPE;
        }
        else if(!strcmp(var_value, "default-style")){
            widget_properties->equiv = HTTP_EQUIV_DEFAULT_STYLE;
        }
        else if(!strcmp(var_value, "refresh")){
            widget_properties->equiv = HTTP_EQUIV_REFRESH;
        }
        return 1;
    }
    else if(!strcmp(var_name, "name")){
        if(!strcmp(var_value, "application-name")){
            widget_properties->name = META_NAME_APPLICATION_NAME;
        }
        else if(!strcmp(var_value, "author")){
            widget_properties->name = META_NAME_AUTHOR;
        }
        else if(!strcmp(var_value, "description")){
            widget_properties->name = META_NAME_DESCRIPTION;
        }
        else if(!strcmp(var_value, "generator")){
            widget_properties->name = META_NAME_GENERATOR;
        }
        else if(!strcmp(var_value, "keywords")){
            widget_properties->name = META_NAME_KEYWORDS;
        }
        else if(!strcmp(var_value, "viewport")){
            widget_properties->name = META_NAME_VIEWPORT;
        }
        return 1;
    }
}

void set_widget_properties_for_meta_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_meta_tag;
    current_widget->widget_properties = malloc(sizeof(struct meta));
}