//
// Created by samet on 7.04.2022.
//

#include "input.h"

void choose_context_for_input_tag(struct widget* current_widget, char* context){
    struct input* widget_properties = current_widget->widget_properties;
    if(!strcmp(context, "autofocus")){
        widget_properties->autofocus = true;
    }
    else if(!strcmp(context, "checked")){
        widget_properties->checked = true;
    }
    else if(!strcmp(context, "disabled")){
        widget_properties->disabled = true;
    }
    else if(!strcmp(context, "formnovalidate")){
        widget_properties->formnovalidate = true;
    }
    else if(!strcmp(context, "multiple")){
        widget_properties->multiple = true;
    }
    else if(!strcmp(context, "readonly")){
        widget_properties->readonly = true;
    }
    else if(!strcmp(context, "required")){
        widget_properties->required = true;
    }
}

int choose_variable_for_input_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct input* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "accept")){
        widget_properties->accept = var_value;
    }
    else if(!strcmp(var_name, "alt")){
        widget_properties->alt = var_value;
    }
    else if(!strcmp(var_name, "autocomplete")){
        if(!strcmp(var_value, "on")){
            widget_properties->autocomplete = true;
        }
        else if(!strcmp(var_value, "off")){
            widget_properties->autocomplete = false;
        }
        return 1;
    }
    else if(!strcmp(var_name, "dirname")){
        widget_properties->dirname = var_value;
    }
    else if(!strcmp(var_name, "form")){
        widget_properties->form = var_value;
    }
    else if(!strcmp(var_name, "formaction")){
        widget_properties->formaction = var_value;
    }
    else if(!strcmp(var_name, "formenctype")){
        if(!strcmp(var_value, "text/plain")){
            widget_properties->enctype = FORM_ENC_TYPE_TEXT;
        }
        else if(!strcmp(var_value, "multipart/form-data")){
            widget_properties->enctype = FORM_ENC_TYPE_MULTIPART;
        }
        else if(!strcmp(var_value, "application/x-www-form-urlencoded")){
            widget_properties->enctype = FORM_ENC_TYPE_APPLICATION;
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
    else if(!strcmp(var_name, "height")){
        widget_properties->height = (int)strtol(var_value, NULL, 10);
        return 1;
    }
    else if(!strcmp(var_name, "width")){
        widget_properties->width = (int)strtol(var_value, NULL, 10);
        return 1;
    }
    else if(!strcmp(var_name, "list")){
        widget_properties->list = var_value;
    }
    else if(!strcmp(var_name, "max")){
        widget_properties->max = var_value;//for now
    }
    else if(!strcmp(var_name, "maxlength")){
        widget_properties->max_length = (int)strtol(var_value, NULL, 10);
        return 1;
    }
    else if(!strcmp(var_name, "min")){
        widget_properties->min = var_value;//for now
    }
    else if(!strcmp(var_name, "minlength")){
        widget_properties->min_length = (int)strtol(var_value, NULL, 10);
        return 1;
    }
    else if(!strcmp(var_name, "name")){
        widget_properties->name = var_value;
    }
    else if(!strcmp(var_name, "pattern")){
        widget_properties->pattern = var_value;
    }
    else if(!strcmp(var_name, "placeholder")){
        widget_properties->placeholder = var_value;
    }
    else if(!strcmp(var_name, "size")){
        widget_properties->size = (int)strtol(var_value, NULL, 10);
        return 1;
    }
    else if(!strcmp(var_name, "src")){
        widget_properties->src = var_value;
    }
    else if(!strcmp(var_name, "step")){
        widget_properties->step = (int)strtol(var_value, NULL, 10);
        return 1;
    }
    else if(!strcmp(var_name, "type")){
        if(!strcmp(var_value, "button")){
            widget_properties->type = INPUT_TYPE_BUTTON;
        }
        else if(!strcmp(var_value, "checkbox")){
            widget_properties->type = INPUT_TYPE_CHECKBOX;
        }
        else if(!strcmp(var_value, "color")){
            widget_properties->type = INPUT_TYPE_COLOR;
        }
        else if(!strcmp(var_value, "date")){
            widget_properties->type = INPUT_TYPE_DATE;
        }
        else if(!strcmp(var_value, "datetime-local")){
            widget_properties->type = INPUT_TYPE_DATETIME_LOCAL;
        }
        else if(!strcmp(var_value, "email")){
            widget_properties->type = INPUT_TYPE_EMAIL;
        }
        else if(!strcmp(var_value, "file")){
            widget_properties->type = INPUT_TYPE_FILE;
        }
        else if(!strcmp(var_value, "hidden")){
            widget_properties->type = INPUT_TYPE_HIDDEN;
        }
        else if(!strcmp(var_value, "image")){
            widget_properties->type = INPUT_TYPE_IMAGE;
        }
        else if(!strcmp(var_value, "month")){
            widget_properties->type = INPUT_TYPE_MONTH;
        }
        else if(!strcmp(var_value, "number")){
            widget_properties->type = INPUT_TYPE_NUMBER;
        }
        else if(!strcmp(var_value, "password")){
            widget_properties->type = INPUT_TYPE_PASSWORD;
        }
        else if(!strcmp(var_value, "radio")){
            widget_properties->type = INPUT_TYPE_RADIO;
        }
        else if(!strcmp(var_value, "range")){
            widget_properties->type = INPUT_TYPE_RANGE;
        }
        else if(!strcmp(var_value, "reset")){
            widget_properties->type = INPUT_TYPE_RESET;
        }
        else if(!strcmp(var_value, "search")){
            widget_properties->type = INPUT_TYPE_SEARCH;
        }
        else if(!strcmp(var_value, "submit")){
            widget_properties->type = INPUT_TYPE_SUBMIT;
        }
        else if(!strcmp(var_value, "tel")){
            widget_properties->type = INPUT_TYPE_TEL;
        }
        else if(!strcmp(var_value, "text")){
            widget_properties->type = INPUT_TYPE_TEXT;
        }
        else if(!strcmp(var_value, "time")){
            widget_properties->type = INPUT_TYPE_TIME;
        }
        else if(!strcmp(var_value, "url")){
            widget_properties->type = INPUT_TYPE_URL;
        }
        else if(!strcmp(var_value, "week")){
            widget_properties->type = INPUT_TYPE_WEEK;
        }
        return 1;
    }
    else if(!strcmp(var_name, "value")){
        widget_properties->value = var_value;
    }
}

void set_widget_properties_for_input_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_input_tag;
    current_widget->context_reader_func = choose_context_for_input_tag;
    current_widget->widget_properties = malloc(sizeof(struct input));
}