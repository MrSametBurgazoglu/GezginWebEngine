//
// Created by samet on 5.04.2022.
//

#include <malloc.h>
#include "form.h"

void choose_context_for_form_tag(struct widget* current_widget, char* context){
    struct form* widget_properties = current_widget->widget_properties;
    if(!strcmp(context, "novalidate")){
        widget_properties->novalidate = true;
    }
}

int choose_variable_for_form_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct form* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "accept-charset")){
        widget_properties->accept_charset = var_value;
    }
    else if(!strcmp(var_name, "action")){
        widget_properties->action = var_value;
    }
    else if(!strcmp(var_name, "autocomplete")){
        if(!strcmp(var_value, "off")){
            widget_properties->autocomplete = false;
        }
        else if(!strcmp(var_value, "on")){
            widget_properties->autocomplete = true;
        }
        return 1;
    }
    else if(!strcmp(var_name, "enctype")){
        if(!strcmp(var_value, "text/plain")){
            widget_properties->enc_type = FORM_ENC_TYPE_TEXT;
        }
        else if(!strcmp(var_value, "multipart/form-data")){
            widget_properties->enc_type = FORM_ENC_TYPE_MULTIPART;
        }
        else if(!strcmp(var_value, "application/x-www-form-urlencoded")){
            widget_properties->enc_type = FORM_ENC_TYPE_APPLICATION;
        }
        return 1;
    }
    else if(!strcmp(var_name, "method")){
        if(!strcmp(var_value, "get")){
            widget_properties->method = FORM_METHOD_GET;
        }
        else if(!strcmp(var_value, "post")){
            widget_properties->method = FORM_METHOD_POST;
        }
        return 1;
    }
    else if(!strcmp(var_name, "name")){
        widget_properties->name = var_value;
    }
    else if(!strcmp(var_name, "rel")){
        if(!strcmp(var_value, "external")){
            widget_properties->rel = FORM_REL_EXTERNAL;
        }
        else if(!strcmp(var_value, "help")){
            widget_properties->rel = FORM_REL_HELP;
        }
        else if(!strcmp(var_value, "license")){
            widget_properties->rel = FORM_REL_LICENSE;
        }
        else if(!strcmp(var_value, "next")){
            widget_properties->rel = FORM_REL_NEXT;
        }
        else if(!strcmp(var_value, "nofollow")){
            widget_properties->rel = FORM_REL_NOFOLLOW;
        }
        else if(!strcmp(var_value, "noopener")){
            widget_properties->rel = FORM_REL_NO_OPENER;
        }
        else if(!strcmp(var_value, "noreferrer")){
            widget_properties->rel = FORM_REL_NO_REFERRER;
        }
        else if(!strcmp(var_value, "opener")){
            widget_properties->rel = FORM_REL_OPENER;
        }
        else if(!strcmp(var_value, "prev")){
            widget_properties->rel = FORM_REL_PREV;
        }
        else if(!strcmp(var_value, "search")){
            widget_properties->rel = FORM_REL_SEARCH;
        }
        return 1;
    }
    else if(!strcmp(var_name, "target")){
        if(!strcmp(var_value, "_blank")){
            widget_properties->target = FORM_TARGET_BLANK;
        }
        else if(!strcmp(var_value, "_self")){
            widget_properties->target = FORM_TARGET_SELF;
        }
        else if(!strcmp(var_value, "_parent")){
            widget_properties->target = FORM_TARGET_PARENT;
        }
        else if(!strcmp(var_value, "_top")){
            widget_properties->target = FORM_TARGET_TOP;
        }
        else{
            widget_properties->target = FORM_TARGET_CUSTOM;
        }
        return 1;
    }
    return 0;
}

void set_widget_properties_for_form_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_form_tag;
    current_widget->context_reader_func = choose_context_for_form_tag;
    current_widget->widget_properties = malloc(sizeof(struct form));
}