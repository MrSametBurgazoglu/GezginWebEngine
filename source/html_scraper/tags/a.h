//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H

#include "../../widget.h"
#include <string.h>

int choose_variable_for_a_tag(struct widget*, char*, char*);

void set_widget_properties_for_a_tag(struct widget*);

struct a{
    char* download;
    char* href;
    char* hreflang;
    //char* media; not supported yet
    //char* ping; some browsers not support this
    referrer_policy referrerpolicy;
    form_rel rel;
    form_target target;
    char* media_type;
};

#endif //UNTITLED_A_H
