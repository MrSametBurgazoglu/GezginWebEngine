//
// Created by samet on 7.04.2022.
//

#ifndef UNTITLED_LI_H
#define UNTITLED_LI_H

#include "../../widget.h"
#include <string.h>

int choose_variable_for_li_tag(struct widget*, char*, char*);

void set_widget_properties_for_li_tag(struct widget*);

struct li{
    char* value;
};
#endif //UNTITLED_LI_H
