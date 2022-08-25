//
// Created by samet on 26.05.2022.
//

#ifndef UNTITLED_ALIGN_H
#define UNTITLED_ALIGN_H

#include "../css_widget.h"

void align_content_property_set_value(struct css_properties*, char*);
void align_items_property_set_value(struct css_properties*, char*);
void align_self_property_set_value(struct css_properties*, char*);
void compute_align(struct css_properties* dest, struct css_properties* source);

#endif //UNTITLED_ALIGN_H
