//
// Created by samet on 11.08.2022.
//

#ifndef UNTITLED_OVERFLOW_H
#define UNTITLED_OVERFLOW_H

#include "css_enum_variables.h"
#include "../css_widget.h"

struct overflow{
    bool overflow_wrap_inherit;
    bool overflow_x_inherit;
    bool overflow_y_inherit;

    css_overflow_wrap_type wrap;
    css_overflow_type overflowX;
    css_overflow_type overflowY;
};

void overflow_property_set_value(struct css_properties*, char*);
void overflow_wrap_property_set_value(struct css_properties*, char*);
void overflow_x_property_set_value(struct css_properties*, char*);
void overflow_y_property_set_value(struct css_properties*, char*);

#endif //UNTITLED_OVERFLOW_H
