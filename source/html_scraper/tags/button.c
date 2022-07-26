//
// Created by samet on 5.04.2022.
//

#include <malloc.h>
#include "button.h"

void choose_context_for_button_tag(struct widget* current_widget, char* context){
    struct button* widget_properties = current_widget->widget_properties;
    if(!strcmp(context, "autofocus")){
        widget_properties->auto_focus = true;
    }
    else if(!strcmp(context, "disabled")){
        widget_properties->disabled = true;
    }
    else if(!strcmp(context, "formnovalidate")){
        widget_properties->formnovalidate = true;
    }
}

int choose_variable_for_button_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct button* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "type")){
        if(!strcmp(var_value, "button")){
            widget_properties->type = BUTTON_TYPE_BUTTON;
        }
        else if(!strcmp(var_value, "reset")){
            widget_properties->type = BUTTON_TYPE_RESET;
        }
        else if(!strcmp(var_value, "submit")){
            widget_properties->type = BUTTON_TYPE_SUBMIT;
        }
        return 1;
    }
    else if(!strcmp(var_name, "form")){
        widget_properties->form = var_value;
    }
    else if(!strcmp(var_name, "formaction")){
        widget_properties->form_action = var_value;
    }
    else if(!strcmp(var_name, "formenctype")){
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
    else if(!strcmp(var_name, "formmethod")){
        if(!strcmp(var_value, "get")){
            widget_properties->method = FORM_METHOD_GET;
        }
        else if(!strcmp(var_value, "post")){
            widget_properties->method = FORM_METHOD_POST;
        }
        return 1;
    }
    else if(!strcmp(var_name, "formtarget")){
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
            widget_properties->formnovalidate = FORM_TARGET_CUSTOM;
        }
        return 1;
    }
    else if(!strcmp(var_name, "name")){
        widget_properties->name = var_value;
    }
    else if(!strcmp(var_name, "value")){
        widget_properties->value = var_value;
    }
    return 0;
}

void set_widget_properties_for_button_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_button_tag;
    current_widget->context_reader_func = choose_context_for_button_tag;
    current_widget->widget_properties = malloc(sizeof(struct button));
}