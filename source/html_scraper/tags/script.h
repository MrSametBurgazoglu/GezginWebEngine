//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_SCRIPT_H
#define UNTITLED_SCRIPT_H

#include "../../widget.h"
#include <string.h>
#include <stdbool.h>

void choose_context_for_script_tag(struct widget*, char*);

int choose_variable_for_script_tag(struct widget*, char*, char*);

void set_widget_properties_for_script_tag(struct widget*);

struct script{
    bool async;
    cross_origin origin;
    bool defer;
    char* integrity;
    bool nomodule;
    referrer_policy referrerpolicy;
    char* src;
    char* type;
};

#endif //UNTITLED_SCRIPT_H
