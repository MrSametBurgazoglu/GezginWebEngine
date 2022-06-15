//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_COLGROUP_H
#define UNTITLED_COLGROUP_H

#include "../../widget.h"
#include <stdlib.h>
#include <string.h>

int choose_variable_for_colgroup_tag(struct widget*, char*, char*);

void set_widget_properties_for_colgroup_tag(struct widget*);

struct colgroup{
    int number;
};

#endif //UNTITLED_COLGROUP_H
