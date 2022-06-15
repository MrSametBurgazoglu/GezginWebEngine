//
// Created by samet on 7.04.2022.
//

#ifndef UNTITLED_INS_H
#define UNTITLED_INS_H

#include "../../widget.h"
#include <string.h>

int choose_variable_for_ins_tag(struct widget*, char*, char*);

void set_widget_properties_for_ins_tag(struct widget*);

struct ins{
    char* cite;
    char* datetime;
};

#endif //UNTITLED_INS_H
