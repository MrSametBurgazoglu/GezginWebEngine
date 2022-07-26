//
// Created by samet on 7.04.2022.
//

#ifndef UNTITLED_OPTION_H
#define UNTITLED_OPTION_H

#include "../../widget.h"
#include <string.h>
#include <stdbool.h>

void choose_context_for_option_tag(struct widget*, char*);

int choose_variable_for_option_tag(struct widget*, char*, char*);

void set_widget_properties_for_option_tag(struct widget*);

struct option{
    bool disabled;
    char* label;
    bool selected;
    char* value;
};

#endif //UNTITLED_OPTION_H
