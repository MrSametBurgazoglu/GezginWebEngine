//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_BASE_H
#define UNTITLED_BASE_H

#include "../../widget.h"
#include <stdbool.h>
#include <string.h>

int choose_variable_for_base_tag(struct widget* current_widget, char* var_name, char* var_value);

void set_widget_properties_for_base_tag(struct widget*);

struct base{
    char* href;
    form_target target;
};

#endif //UNTITLED_BASE_H
