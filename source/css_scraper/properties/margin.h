//
// Created by samet on 01.08.2022.
//

#ifndef UNTITLED_MARGIN_H
#define UNTITLED_MARGIN_H

#include "css_enum_variables.h"
#include "../css_widget.h"

struct margin{
    bool margin_top_inherit;
    bool margin_bottom_inherit;
    bool margin_left_inherit;
    bool margin_right_inherit;

    css_property_value_type marginTopValueType;
    css_property_value_type marginBottomValueType;
    css_property_value_type marginLeftValueType;
    css_property_value_type marginRightValueType;

    int margin_top;
    int margin_bottom;
    int margin_left;
    int margin_right;
};

void margin_property_set_value(struct css_properties*, char*);
void margin_top_property_set_value(struct css_properties*, char*);
void margin_bottom_property_set_value(struct css_properties*, char*);
void margin_left_property_set_value(struct css_properties*, char*);
void margin_right_property_set_value(struct css_properties*, char*);


#endif //UNTITLED_MARGIN_H
