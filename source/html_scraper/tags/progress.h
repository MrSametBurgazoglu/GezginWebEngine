//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_PROGRESS_H
#define UNTITLED_PROGRESS_H

#include "../../widget.h"
#include <string.h>
#include <stdlib.h>

int choose_variable_for_progress_tag(struct widget*, char*, char*);

void set_widget_properties_for_progress_tag(struct widget*);

struct progress{
    float max;
    float value;
};

#endif //UNTITLED_PROGRESS_H
