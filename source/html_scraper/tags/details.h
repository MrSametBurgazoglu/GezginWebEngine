//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_DETAILS_H
#define UNTITLED_DETAILS_H

#include "../../widget.h"
#include <string.h>
#include <stdbool.h>

void choose_context_for_details_tag(struct widget*, char*);

void set_widget_properties_for_details_tag(struct widget*);

struct details{
    bool open;
};

#endif //UNTITLED_DETAILS_H
