//
// Created by samet on 11.08.2022.
//

#ifndef UNTITLED_RESIZE_H
#define UNTITLED_RESIZE_H

#include "css_enum_variables.h"
#include "../css_widget.h"

void resize_property_set_value(struct css_properties*, char*);
void compute_inherit_resize(struct css_properties* dest, struct css_properties* source);
void update_resize(struct css_properties* dest, struct css_properties* source);

#endif //UNTITLED_RESIZE_H
