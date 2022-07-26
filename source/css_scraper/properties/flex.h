//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_FLEX_H
#define UNTITLED_FLEX_H

#include "css_enum_variables.h"

struct flex{
    css_property_value_type flex_grow_valueType;
    css_property_value_type flex_shrink_valueType;
    css_property_value_type flex_basis_valueType;
    int flex_grow_value;
    int flex_shrink_value;
    int flex_basis_value;
};

struct flex_flow{
    css_flex_direction_type flexDirection;
    css_flex_wrap_type flexWrap;
};


#endif //UNTITLED_FLEX_H
