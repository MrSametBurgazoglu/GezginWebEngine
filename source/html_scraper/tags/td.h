//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_TD_H
#define UNTITLED_TD_H

#include "../../widget.h"
#include <string.h>
#include <stdlib.h>

int choose_variable_for_td_tag(struct widget*, char*, char*);

void set_widget_properties_for_td_tag(struct widget*);

struct td{
    int colspan;
    char* headers;
    int rowspan;
};

#endif //UNTITLED_TD_H
