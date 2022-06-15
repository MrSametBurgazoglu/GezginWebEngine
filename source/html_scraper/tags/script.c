//
// Created by samet on 8.04.2022.
//

#include <malloc.h>
#include "script.h"

void choose_context_for_script_tag(struct widget* current_widget, char* context){
    struct script* widget_properties = current_widget->widget_properties;
    if(!strcmp(context, "async")){
        widget_properties->async = true;
    }
    else if(!strcmp(context, "defer")){
        widget_properties->defer = true;
    }
}

int choose_variable_for_script_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct script* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "crossorigin")){
        if(!strcmp(var_value, "anonymous")){
            widget_properties->origin = CROSS_ORIGIN_ANONYMOUS;
        }
        else if(!strcmp(var_value, "use-credentials")){
            widget_properties->origin = CROSS_ORIGIN_USE_CREDENTIALS;
        }
        return 1;
    }
    else if(!strcmp(var_name, "integrity")){
        widget_properties->integrity = var_value;
    }
    else if(!strcmp(var_name, "nomodule")){
        if(!strcmp(var_value, "True")){
            widget_properties->nomodule = true;
        }
        else if(!strcmp(var_value, "False")){
            widget_properties->nomodule = false;
        }
        return 1;
    }
    else if(!strcmp(var_name, "referrerpolicy")){
        if(!strcmp(var_value, "no-referrer")){
            widget_properties->referrerpolicy = POLICY_NO_REFERRER;
        }
        else if(!strcmp(var_value, "no-referrer-when-downgrade")){
            widget_properties->referrerpolicy = POLICY_NO_REFERRER_WHEN_DOWNGRADE;
        }
        else if(!strcmp(var_value, "origin")){
            widget_properties->referrerpolicy = POLICY_ORIGIN;
        }
        else if(!strcmp(var_value, "origin-when-cross-origin")){
            widget_properties->referrerpolicy = POLICY_ORIGIN_WHEN_CROSS_ORIGIN;
        }
        else if(!strcmp(var_value, "same-origin")){
            widget_properties->referrerpolicy = POLICY_SAME_ORIGIN;
        }
        else if(!strcmp(var_value, "strict-origin")){
            widget_properties->referrerpolicy = POLICY_STRICT_ORIGIN;
        }
        else if(!strcmp(var_value, "strict-origin-when-cross-origin")){
            widget_properties->referrerpolicy = POLICY_STRICT_ORIGIN_WHEN_CROSS_ORIGIN;
        }
        else if(!strcmp(var_value, "unsafe-url")){
            widget_properties->referrerpolicy = POLICY_UNSAFE_URL;
        }
        return 1;
    }
    else if(!strcmp(var_name, "src")){
        widget_properties->src = var_value;
    }
    else if(!strcmp(var_name, "type")){
        widget_properties->type = var_value;
    }
    return 0;
}

void set_widget_properties_for_script_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_script_tag;
    current_widget->context_reader_func = choose_context_for_script_tag;
    current_widget->widget_properties = malloc(sizeof(struct script));
}