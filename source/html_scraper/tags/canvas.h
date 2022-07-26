//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_CANVAS_H
#define UNTITLED_CANVAS_H

#include "../../widget.h"
#include <stdlib.h>
#include <string.h>

int choose_variable_for_canvas_tag(struct widget*, char*, char*);

void set_widget_properties_for_canvas_tag(struct widget*);

struct canvas{
    int width;
    int height;
};

#endif //UNTITLED_CANVAS_H
