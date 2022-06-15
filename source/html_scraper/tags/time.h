//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_TIME_H
#define UNTITLED_TIME_H

#include "../../widget.h"
#include <string.h>

int choose_variable_for_time_tag(struct widget*, char*, char*);

void set_widget_properties_for_time_tag(struct widget*);

struct time{
    int year;
    int month;
    int week;
    int day;
    int hour;
    int minute;
    int second;
};

#endif //UNTITLED_TIME_H
