//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_SELECT_H
#define UNTITLED_SELECT_H

#include "../../widget.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void choose_context_for_select_tag(struct widget*, char*);

int choose_variable_for_select_tag(struct widget*, char*, char*);

void set_widget_properties_for_select_tag(struct widget*);

struct select{
    bool autofocus;
    bool disabled;
    char* form;
    bool multiple;
    char* name;
    bool required;
    int size;
};

#endif //UNTITLED_SELECT_H
