//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_COL_H
#define UNTITLED_COL_H


#include "../../widget.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int choose_variable_for_col_tag(struct widget*, char*, char*);

void set_widget_properties_for_col_tag(struct widget*);

struct col{
    int number;
};

#endif //UNTITLED_COL_H
