//
// Created by samet on 5.04.2022.
//

#include "iframe.h"

void choose_context_for_iframe_tag(struct widget* current_widget, char* context){//TODO IS THIS RIGHT?
    struct iframe* widget_properties = current_widget->widget_properties;
    if(!strcmp(context, "allow")){
        widget_properties->allow = true;
    }
}

int choose_variable_for_iframe_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct iframe* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "allowfullscreen")){
        if(!strcmp(var_value, "true")){
            widget_properties->allowfullscreen = true;
        }
        else{
            widget_properties->allowfullscreen = false;
        }
        return 1;
    }
    else if(!strcmp(var_name, "allowpaymentrequest")){
        if(!strcmp(var_value, "true")){
            widget_properties->allowpaymentrequest = true;
        }
        else{
            widget_properties->allowpaymentrequest = false;
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
    else if(!strcmp(var_name, "loading")){
        if(!strcmp(var_value, "eager")){
            widget_properties->loading = LOADING_TYPE_EAGER;
        }
        else if(!strcmp(var_value, "lazy")){
            widget_properties->loading = LOADING_TYPE_LAZY;
        }
        return 1;
    }
    else if(!strcmp(var_name, "name")){
        widget_properties->name = var_value;
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
        else if(!strcmp(var_value, "strict-origin-when-cross-origin")){
            widget_properties->referrerpolicy = POLICY_STRICT_ORIGIN_WHEN_CROSS_ORIGIN;
        }
        else if(!strcmp(var_value, "unsafe-url")){
            widget_properties->referrerpolicy = POLICY_UNSAFE_URL;
        }
        return 1;
    }
    else if(!strcmp(var_name, "sandbox")){
        if(!strcmp(var_value, "allow-forms")){
            widget_properties->sandbox = SANDBOX_ALLOW_FORMS;
        }
        else if(!strcmp(var_value, "allow-modals")){
            widget_properties->sandbox = SANDBOX_ALLOW_MODALS;
        }
        else if(!strcmp(var_value, "allow-orientation-lock")){
            widget_properties->sandbox = SANDBOX_ALLOW_ORIENTATION_LOCK;
        }
        else if(!strcmp(var_value, "allow-pointer-lock")){
            widget_properties->sandbox = SANDBOX_ALLOW_POINTER_LOCK;
        }
        else if(!strcmp(var_value, "allow-popups")){
            widget_properties->sandbox = SANDBOX_ALLOW_POPUPS;
        }
        else if(!strcmp(var_value, "allow-popups-to-escape-sandbox")){
            widget_properties->sandbox = SANDBOX_ALLOW_POPUPS_TO_ESCAPE_SANDBOX;
        }
        else if(!strcmp(var_value, "allow-presentation")){
            widget_properties->sandbox = SANDBOX_ALLOW_PRESENTATION;
        }
        else if(!strcmp(var_value, "allow-same-origin")){
            widget_properties->sandbox = SANDBOX_ALLOW_SAME_ORIGIN;
        }
        else if(!strcmp(var_value, "allow-scripts")){
            widget_properties->sandbox = SANDBOX_ALLOW_SCRIPTS;
        }
        else if(!strcmp(var_value, "allow-top-navigation")){
            widget_properties->sandbox = SANDBOX_ALLOW_TOP_NAVIGATION;
        }
        else if(!strcmp(var_value, "allow-top-navigation-by-user-activation")){
            widget_properties->sandbox = SANDBOX_ALLOW_TOP_NAVIGATION_BY_USER_ACTIVATION;
        }
        else{
            widget_properties->sandbox = SANDBOX_ALLOW_NONE;
        }
        return 1;
    }
    else if(!strcmp(var_name, "src")){
        widget_properties->src = var_value;
    }
    else if(!strcmp(var_name, "srcdoc")){
        widget_properties->srcdoc = var_value;
    }
    return 0;
}

void set_widget_properties_for_iframe_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_iframe_tag;
    current_widget->context_reader_func = choose_context_for_iframe_tag;
    current_widget->widget_properties = malloc(sizeof(struct iframe));
}