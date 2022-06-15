//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_TH_H
#define UNTITLED_TH_H

#include "../../widget.h"
#include <string.h>
#include <stdlib.h>

int choose_variable_for_th_tag(struct widget*, char*, char*);

void set_widget_properties_for_th_tag(struct widget*);

struct th{
    char* abbr;
    int colspan;
    char* headers;
    int rowspan;
    table_scope scope;
};

#endif //UNTITLED_TH_H
