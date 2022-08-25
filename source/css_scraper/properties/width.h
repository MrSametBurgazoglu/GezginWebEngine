//
// Created by samet on 29.07.2022.
//

#ifndef UNTITLED_WIDTH_H
#define UNTITLED_WIDTH_H

#include "css_enum_variables.h"
#include "../css_widget.h"

void width_property_set_value(struct css_properties*, char*);
void min_width_property_set_value(struct css_properties*, char*);
void max_width_property_set_value(struct css_properties*, char*);
void compute_width(struct css_properties* dest, struct css_properties* source);

#endif //UNTITLED_WIDTH_H
