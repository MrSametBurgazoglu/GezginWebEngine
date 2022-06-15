//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_STYLE_H
#define UNTITLED_STYLE_H

#include "../../widget.h"
#include <string.h>

int choose_variable_for_style_tag(struct widget*, char*, char*);

void set_widget_properties_for_style_tag(struct widget*);

struct style{
    char* media;
    char* type;
};

#endif //UNTITLED_STYLE_H
