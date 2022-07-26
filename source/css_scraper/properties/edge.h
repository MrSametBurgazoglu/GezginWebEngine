//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_EDGE_H
#define UNTITLED_EDGE_H

#include "css_enum_variables.h"

struct btlr_position{
    css_property_value_type propertyValueType;
    int value;
};

struct edge_position{
    struct btlr_position bottom;
    struct btlr_position top;
    struct btlr_position left;
    struct btlr_position right;
};

#endif //UNTITLED_EDGE_H
