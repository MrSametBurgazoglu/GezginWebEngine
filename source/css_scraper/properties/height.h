//
// Created by samet on 29.07.2022.
//

#ifndef UNTITLED_HEIGHT_H
#define UNTITLED_HEIGHT_H

#include "css_enum_variables.h"
#include "../css_widget.h"

void height_property_set_value(struct css_properties*, char*);
void min_height_property_set_value(struct css_properties*, char*);
void max_height_property_set_value(struct css_properties*, char*);
void compute_height(struct css_properties* dest, struct css_properties* source);

#endif //UNTITLED_HEIGHT_H
