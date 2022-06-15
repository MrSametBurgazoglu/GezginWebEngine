//
// Created by samet on 7.04.2022.
//

#ifndef UNTITLED_OPTGROUP_H
#define UNTITLED_OPTGROUP_H

#include "../../widget.h"
#include <string.h>
#include <stdbool.h>

void choose_context_for_optgroup_tag(struct widget*, char*);

int choose_variable_for_optgroup_tag(struct widget*, char*, char*);

void set_widget_properties_for_optgroup_tag(struct widget*);

struct optgroup{
    bool disabled;
    char* label;
};

#endif //UNTITLED_OPTGROUP_H
