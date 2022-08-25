//
// Created by samet on 11.08.2022.
//

#ifndef UNTITLED_PADDING_H
#define UNTITLED_PADDING_H

#include "css_enum_variables.h"
#include "../css_widget.h"

struct padding{
    bool padding_top_inherit;
    bool padding_bottom_inherit;
    bool padding_left_inherit;
    bool padding_right_inherit;

    css_property_value_type paddingTopValueType;
    css_property_value_type paddingBottomValueType;
    css_property_value_type paddingLeftValueType;
    css_property_value_type paddingRightValueType;

    int padding_top;
    int padding_bottom;
    int padding_left;
    int padding_right;
};

void padding_property_set_value(struct css_properties*, char*);
void padding_top_property_set_value(struct css_properties*, char*);
void padding_bottom_property_set_value(struct css_properties*, char*);
void padding_left_property_set_value(struct css_properties*, char*);
void padding_right_property_set_value(struct css_properties*, char*);
void compute_inherit_padding(struct css_properties* dest, struct css_properties* source);
void update_padding(struct css_properties* dest, struct css_properties* source);
void free_padding(struct css_properties*);

#endif //UNTITLED_PADDING_H
