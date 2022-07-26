//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_DEL_H
#define UNTITLED_DEL_H

#include "../../widget.h"
#include <string.h>

int choose_variable_for_del_tag(struct widget*, char*, char*);

void set_widget_properties_for_del_tag(struct widget*);

struct del{
    char* cite;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

#endif //UNTITLED_DEL_H
