//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_FLEX_H
#define UNTITLED_FLEX_H

#include "css_enum_variables.h"
#include "../css_widget.h"

struct flex{
    bool flex_basis_inherit;
    bool flex_grow_inherit;
    bool flex_shrink_inherit;
    css_property_value_type flex_basis_valueType;
    int flex_grow_value;
    int flex_shrink_value;
    int flex_basis_value;
};

struct flex_flow{
    bool flex_direction_inherit;
    bool flex_wrap_inherit;
    css_flex_direction_type flexDirection;
    css_flex_wrap_type flexWrap;
};

void flex_property_set_value(struct css_properties*, char*);
void flex_basis_property_set_value(struct css_properties*, char*);
void flex_direction_property_set_value(struct css_properties*, char*);
void flex_flow_property_set_value(struct css_properties*, char*);
void flex_grow_property_set_value(struct css_properties*, char*);
void flex_shrink_property_set_value(struct css_properties*, char*);
void flex_wrap_property_set_value(struct css_properties*, char*);
void compute_flex(struct css_properties* dest, struct css_properties* source);
void free_flex(struct css_properties*);

#endif //UNTITLED_FLEX_H
