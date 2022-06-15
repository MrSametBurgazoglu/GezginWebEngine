//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_SOURCE_H
#define UNTITLED_SOURCE_H

#include "../../widget.h"
#include <string.h>

int choose_variable_for_source_tag(struct widget*, char*, char*);

void set_widget_properties_for_source_tag(struct widget*);

struct source{
    char* media;
    char* sizes;
    char* src;
    char* srcset;
    char* type;
};

#endif //UNTITLED_SOURCE_H
