//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_BDO_H
#define UNTITLED_BDO_H

#include "../../widget.h"
#include <stdbool.h>
#include <string.h>

int choose_variable_for_bdo_tag(struct widget*, char*, char*);

void set_widget_properties_for_bdo_tag(struct widget*);

struct bdo{
    html_direction direction;
};

#endif //UNTITLED_BDO_H
