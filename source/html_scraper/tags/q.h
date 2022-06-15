//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_Q_H
#define UNTITLED_Q_H

#include "../../widget.h"
#include <string.h>

int choose_variable_for_q_tag(struct widget*, char*, char*);

void set_widget_properties_for_q_tag(struct widget*);

struct q{
    char* cite;
};

#endif //UNTITLED_Q_H
