//
// Created by samet on 7.04.2022.
//

#ifndef UNTITLED_LINK_H
#define UNTITLED_LINK_H

#include "../../widget.h"
#include "../../css_scraper/css_tree.h"
#include <string.h>

int choose_variable_for_link_tag(struct widget*, char*, char*);

void set_widget_properties_for_link_tag(struct widget* current_widget);

struct link{//TODO CONTROL THIS
    cross_origin crossorigin;
    char* href;
    char* hreflang;
    char* media;// TODO FIX THIS
    referrer_policy referrerpolicy;
    form_rel rel;
    char* sizes;
    char* title;
    char* mediatype;
};

#endif //UNTITLED_LINK_H
