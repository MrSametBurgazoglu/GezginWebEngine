//
// Created by samet on 7.04.2022.
//

#ifndef UNTITLED_MAP_H
#define UNTITLED_MAP_H

#include "../../widget.h"
#include <string.h>

int choose_variable_for_map_tag(struct widget*, char*, char*);

void set_widget_properties_for_map_tag(struct widget*);

struct map{
    char* name;
};


#endif //UNTITLED_MAP_H
