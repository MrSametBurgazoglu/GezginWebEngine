//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_IFRAME_H
#define UNTITLED_IFRAME_H

#include "../../widget.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void choose_context_for_iframe_tag(struct widget*, char*);

int choose_variable_for_iframe_tag(struct widget*, char*, char*);

void set_widget_properties_for_iframe_tag(struct widget*);

struct iframe{
    bool allow;
    bool allowfullscreen;
    bool allowpaymentrequest;
    int height;
    int width;
    loading_type loading;
    char* name;
    referrer_policy referrerpolicy;
    sandbox_allow sandbox;
    char* src;
    char* srcdoc;
};


#endif //UNTITLED_IFRAME_H
