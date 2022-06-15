//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_DATA_H
#define UNTITLED_DATA_H

#include "../../widget.h"
#include <stdbool.h>
#include <string.h>

int choose_variable_for_data_tag(struct widget*, char*, char*);

void set_widget_properties_for_data_tag(struct widget*);

struct data{
    char* value;
};

#endif //UNTITLED_DATA_H
