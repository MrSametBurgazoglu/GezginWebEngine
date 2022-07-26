//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_FIELDSET_H
#define UNTITLED_FIELDSET_H

#include "../../widget.h"
#include <string.h>
#include <stdbool.h>

void choose_context_for_fieldset_tag(struct widget*, char*);

int choose_variable_for_fieldset_tag(struct widget*, char*, char*);

void set_widget_properties_for_fieldset_tag(struct widget*);

struct fieldset{
    bool disabled;
    char* form;
    char* name;
};

#endif //UNTITLED_FIELDSET_H
