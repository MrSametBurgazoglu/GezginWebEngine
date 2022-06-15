//
// Created by samet on 5.04.2022.
//

#include "a.h"
#include "malloc.h"

int choose_variable_for_a_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct a* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "download")){
        widget_properties->download = var_value;
    }
    else if(!strcmp(var_name, "href")){
        widget_properties->href = var_value;
    }
    else if(!strcmp(var_name, "hreflang")){
        widget_properties->hreflang = var_value;
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
        else if(!strcmp(var_value, "strict-origin-when-cross-origin")){
            widget_properties->referrerpolicy = POLICY_STRICT_ORIGIN_WHEN_CROSS_ORIGIN;
        }
        else if(!strcmp(var_value, "unsafe-url")){
            widget_properties->referrerpolicy = POLICY_UNSAFE_URL;
        }
        return 1;
    }
    else if(!strcmp(var_name, "rel")){
        if(!strcmp(var_value, "alternate")){
            widget_properties->rel = FORM_REL_ALTERNATE;
        }
        else if(!strcmp(var_value, "author")){
            widget_properties->rel = FORM_REL_AUTHOR;
        }
        else if(!strcmp(var_value, "bookmark")){
            widget_properties->rel = FORM_REL_BOOKMARK;
        }
        else if(!strcmp(var_value, "external")){
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
        else if(!strcmp(var_value, "noreferrer")){
            widget_properties->rel = FORM_REL_NO_REFERRER;
        }
        else if(!strcmp(var_value, "noopener")){
            widget_properties->rel = FORM_REL_NO_OPENER;
        }
        else if(!strcmp(var_value, "prev")){
            widget_properties->rel = FORM_REL_PREV;
        }
        else if(!strcmp(var_value, "search")){
            widget_properties->rel = FORM_REL_SEARCH;
        }
        else if(!strcmp(var_value, "tag")){
            widget_properties->rel = FORM_REL_TAG;
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
    else if(!strcmp(var_name, "type")){
        widget_properties->media_type = var_value;
    }
    return 0;
}

void set_widget_properties_for_a_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_a_tag;
    current_widget->widget_properties = malloc(sizeof(struct a));
}