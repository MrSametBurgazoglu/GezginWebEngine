//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_PARAM_H
#define UNTITLED_PARAM_H

#include "../../widget.h"
#include <string.h>

int choose_variable_for_param_tag(struct widget*, char*, char*);

void set_widget_properties_for_param_tag(struct widget*);

struct param{
    char* name;
    char* value;
};

#endif //UNTITLED_PARAM_H
