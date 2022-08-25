//
// Created by samet on 29.07.2022.
//

#ifndef UNTITLED_POSITION_H
#define UNTITLED_POSITION_H

#include "css_enum_variables.h"
#include "../css_widget.h"

void position_property_set_value(struct css_properties*, char*);
void top_property_set_value(struct css_properties*, char*);
void bottom_property_set_value(struct css_properties*, char*);
void left_property_set_value(struct css_properties*, char*);
void right_property_set_value(struct css_properties*, char*);
void compute_position(struct css_properties* dest, struct css_properties* source);

#endif //UNTITLED_POSITION_H
