//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_COLUMN_H
#define UNTITLED_COLUMN_H

#include "css_enum_variables.h"
#include "css_color.h"
#include "../css_widget.h"

struct column_rule_width{
    css_column_rule_width_type columnRuleWidthType;
    int value;
};

struct column_rule{
    bool column_rule_style_inherit;
    bool column_rule_width_inherit;
    bool column_rule_color_inherit;
    css_column_rule_style_type columnRuleStyleType;
    struct column_rule_width* columnRuleWidth;
    struct color_rgba* columnRuleColor;
};


void column_count_property_set_value(struct css_properties*, char*);
void column_fill_property_set_value(struct css_properties*, char*);
void column_gap_property_set_value(struct css_properties*, char*);
void column_rule_property_set_value(struct css_properties*, char*);
void column_rule_color_property_set_value(struct css_properties*, char*);
void column_rule_style_property_set_value(struct css_properties*, char*);
void column_rule_width_property_set_value(struct css_properties*, char*);
void column_span_property_set_value(struct css_properties*, char*);
void column_width_property_set_value(struct css_properties*, char*);
void columns_property_set_value(struct css_properties*, char*);
void compute_inherit_column(struct css_properties* dest, struct css_properties* source);
void update_column(struct css_properties* dest, struct css_properties* source);
void free_column(struct css_properties*);


#endif //UNTITLED_COLUMN_H
