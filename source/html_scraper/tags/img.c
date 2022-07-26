//
// Created by samet on 7.04.2022.
//

#include "img.h"

void choose_context_for_img_tag(struct widget* current_widget, char* context){
    struct img* widget_properties = current_widget->widget_properties;
    if(!strcmp(context, "ismap")){
        widget_properties->ismap = true;
    }
}

int choose_variable_for_img_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct img* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "alt")){
        widget_properties->alt = var_value;
    }
    else if(!strcmp(var_name, "crossorigin")){
        if(!strcmp(var_value, "anonymous")){
            widget_properties->crossorgin = CROSS_ORIGIN_ANONYMOUS;
        }
        else if(!strcmp(var_value, "use-credentials")){
            widget_properties->crossorgin = CROSS_ORIGIN_USE_CREDENTIALS;
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
    else if(!strcmp(var_name, "longdesc")){
        widget_properties->longdesc = var_value;
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
        else if(!strcmp(var_value, "unsafe-url")){
            widget_properties->referrerpolicy = POLICY_UNSAFE_URL;
        }
        return 1;
    }
    else if(!strcmp(var_name, "sizes")){
        widget_properties->sizes = var_value;
    }
    else if(!strcmp(var_name, "src")){
        widget_properties->src = var_value;
    }
    else if(!strcmp(var_name, "srcset")){
        widget_properties->src_set = var_value;
    }
    else if(!strcmp(var_name, "usemap")){
        widget_properties->usemap = var_value;
    }
    return 0;
}

void set_widget_properties_for_img_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_img_tag;
    current_widget->context_reader_func = choose_context_for_img_tag;
    current_widget->widget_properties = malloc(sizeof(struct img));
}