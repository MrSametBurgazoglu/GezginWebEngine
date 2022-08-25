//
// Created by samet on 11.08.2022.
//

#ifndef UNTITLED_OPACITY_H
#define UNTITLED_OPACITY_H

#include "css_enum_variables.h"
#include "../css_widget.h"

void opacity_property_set_value(struct css_properties*, char*);
void compute_inherit_opacity(struct css_properties* dest, struct css_properties* source);
void update_opacity(struct css_properties* dest, struct css_properties* source);

#endif //UNTITLED_OPACITY_H
