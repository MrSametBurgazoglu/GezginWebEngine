//
// Created by samet on 7.04.2022.
//

#include <malloc.h>
#include "link.h"

int choose_variable_for_link_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct link* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "crossorigin")){
        if(!strcmp(var_value, "anonymous")){
            widget_properties->crossorigin = CROSS_ORIGIN_ANONYMOUS;
        }
        else if(!strcmp(var_value, "use-credentials")){
            widget_properties->crossorigin = CROSS_ORIGIN_USE_CREDENTIALS;
        }
        return 1;
    }
    else if(!strcmp(var_name, "href")){
        widget_properties->href = var_value;
        add_new_link_to_list(var_value);
    }
    else if(!strcmp(var_name, "hreflang")){
        widget_properties->hreflang = var_value;
    }
    else if(!strcmp(var_name, "media")){
        widget_properties->media = var_value;
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
    else if(!strcmp(var_name, "rel")){
        if(!strcmp(var_value, "alternate")){
            widget_properties->rel = FORM_REL_ALTERNATE;
        }
        else if(!strcmp(var_value, "author")){
            widget_properties->rel = FORM_REL_AUTHOR;
        }
        else if(!strcmp(var_value, "dns-prefetch")){
            widget_properties->rel = FORM_REL_DNS_PREFETCH;
        }
        else if(!strcmp(var_value, "help")){
            widget_properties->rel = FORM_REL_HELP;
        }
        else if(!strcmp(var_value, "icon")){
            widget_properties->rel = FORM_REL_ICON;
        }
        else if(!strcmp(var_value, "license")){
            widget_properties->rel = FORM_REL_LICENSE;
        }
        else if(!strcmp(var_value, "next")){
            widget_properties->rel = FORM_REL_NEXT;
        }
        else if(!strcmp(var_value, "pingback")){
            widget_properties->rel = FORM_REL_PINGBACK;
        }
        else if(!strcmp(var_value, "preconnect")){
            widget_properties->rel = FORM_REL_PRECONNECT;
        }
        else if(!strcmp(var_value, "prefetch")){
            widget_properties->rel = FORM_REL_PREFETCH;
        }
        else if(!strcmp(var_value, "preload")){
            widget_properties->rel = FORM_REL_PRELOAD;
        }
        else if(!strcmp(var_value, "prerender")){
            widget_properties->rel = FORM_REL_PRERENDER;
        }
        else if(!strcmp(var_value, "prev")){
            widget_properties->rel = FORM_REL_PREV;
        }
        else if(!strcmp(var_value, "search")){
            widget_properties->rel = FORM_REL_SEARCH;
        }
        else if(!strcmp(var_value, "stylesheet")){
            widget_properties->rel = FORM_REL_STYLESHEET;
        }
        return 1;
    }
    else if(!strcmp(var_name, "sizes")){
        widget_properties->sizes = var_value;
    }
    else if(!strcmp(var_name, "title")){
        widget_properties->title = var_value;
    }
    else if(!strcmp(var_name, "type")){
        widget_properties->mediatype = var_value;
    }
    return 0;
}

void set_widget_properties_for_link_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_link_tag;
    current_widget->widget_properties = malloc(sizeof(struct link));
}