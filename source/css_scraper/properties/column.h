//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_COLUMN_H
#define UNTITLED_COLUMN_H

#include "css_enum_variables.h"
#include "css_color.h"

struct column{
    css_property_value_type column_width_type;
    css_property_value_type column_count_type;
    int column_width;
    int column_count;
};

struct column_rule_width{
    css_column_rule_width_type columnRuleWidthType;
    int value;
};

struct column_rule_color{
    css_column_rule_color_type columnRuleColorType;
    struct color_rgba* color;
};

struct column_rule{
    css_column_rule_type columnRuleType;
    struct column_rule_width columnRuleWidth;
    struct column_rule_color columnRuleColor;
};

struct column_width{
    css_property_value_type column_width_type;
    int value;
};

#endif //UNTITLED_COLUMN_H
