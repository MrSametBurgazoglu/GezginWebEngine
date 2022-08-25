//
// Created by samet on 11.08.2022.
//

#ifndef UNTITLED_VISIBILITY_H
#define UNTITLED_VISIBILITY_H

#include "css_enum_variables.h"
#include "../css_widget.h"

void visibility_property_set_value(struct css_properties*, char*);
void compute_visibility(struct css_properties* dest, struct css_properties* source);

#endif //UNTITLED_VISIBILITY_H
