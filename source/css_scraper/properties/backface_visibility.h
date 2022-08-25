//
// Created by samet on 31.05.2022.
//

#ifndef UNTITLED_BACKFACE_VISIBILITY_H
#define UNTITLED_BACKFACE_VISIBILITY_H

#include "../css_widget.h"

void backface_visibility_property_set_value(struct css_properties*, char*);
void compute_backface_visibility(struct css_properties* dest, struct css_properties* source);

#endif //UNTITLED_BACKFACE_VISIBILITY_H
