//
// Created by samet on 7.04.2022.
//

#ifndef UNTITLED_OL_H
#define UNTITLED_OL_H

#include "../../widget.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void choose_context_for_ol_tag(struct widget*, char*);

int choose_variable_for_ol_tag(struct widget*, char*, char*);

void set_widget_properties_for_ol_tag(struct widget*);

struct ol{
    bool reversed;
    int start;
    ol_type type;
};

#endif //UNTITLED_OL_H
