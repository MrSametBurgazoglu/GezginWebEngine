//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_OUTPUT_H
#define UNTITLED_OUTPUT_H

#include "../../widget.h"
#include <string.h>

int choose_variable_for_output_tag(struct widget*, char*, char*);

void set_widget_properties_for_output_tag(struct widget*);

struct output{
    char* for_;
    char* form;
    char* name;
};

#endif //UNTITLED_OUTPUT_H
