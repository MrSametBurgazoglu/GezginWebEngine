//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_TEXTAREA_H
#define UNTITLED_TEXTAREA_H

#include "../../widget.h"
#include <string.h>
#include <stdbool.h>

void choose_context_for_textarea_tag(struct widget*, char*);

int choose_variable_for_textarea_tag(struct widget*, char*, char*);

void set_widget_properties_for_textarea_tag(struct widget*);

struct textarea{
    bool autofocus;
    int cols;
    char* dirname;
    bool disabled;
    char* form;
    int maxlength;
    char* name;
    char* placeholder;
    bool readonly;
    bool required;
    int rows;
    textarea_wrap wrap;
};

#endif //UNTITLED_TEXTAREA_H
