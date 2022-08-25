//
// Created by samet on 29.05.2022.
//

#ifndef UNTITLED_BACKDROP_FILTER_H
#define UNTITLED_BACKDROP_FILTER_H

#include "../css_widget.h"

void backdrop_filter_property_set_value(struct css_properties*, char*);
void compute_backdrop_filter(struct css_properties* dest, struct css_properties* source);

#endif //UNTITLED_BACKDROP_FILTER_H
