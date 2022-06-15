//
// Created by samet on 7.04.2022.
//

#ifndef UNTITLED_LABEL_H
#define UNTITLED_LABEL_H

#include "../../widget.h"
#include <string.h>

int choose_variable_for_label_tag(struct widget*, char*, char*);

void set_widget_properties_for_label_tag(struct widget*);

struct label{
    char* for_;
    char* form;
};


#endif //UNTITLED_LABEL_H
