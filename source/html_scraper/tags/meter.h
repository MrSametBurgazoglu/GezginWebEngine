//
// Created by samet on 7.04.2022.
//

#ifndef UNTITLED_METER_H
#define UNTITLED_METER_H

#include "../../widget.h"
#include <string.h>
#include <stdlib.h>

int choose_variable_for_meter_tag(struct widget*, char*, char*);

void set_widget_properties_for_meter_tag(struct widget*);

struct meter{
    char* form;
    float high;
    float low;
    float max;
    float min;
    float optimum;
    float value;
};

#endif //UNTITLED_METER_H
