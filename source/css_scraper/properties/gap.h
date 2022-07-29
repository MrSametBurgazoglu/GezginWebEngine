//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_GAP_H
#define UNTITLED_GAP_H

#include "css_enum_variables.h"

struct row_gap{
    css_property_value_type propertyValueType;
    int value;
};

struct gap{
    struct row_gap rowGap;
};

#endif //UNTITLED_GAP_H
