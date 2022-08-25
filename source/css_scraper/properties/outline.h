//
// Created by samet on 01.08.2022.
//

#ifndef UNTITLED_OUTLINE_H
#define UNTITLED_OUTLINE_H

#include "css_enum_variables.h"
#include "../css_widget.h"

struct outline{
    bool outline_color_inherit;
    bool outline_offset_inherit;
    bool outline_style_inherit;
    bool outline_width_inherit;

    struct color_rgba* colorRgba;
    int offset;
    css_outline_style_type outlineStyleType;
    css_outline_width outlineWidth;
    int outline_width;
};


void outline_property_set_value(struct css_properties*, char*);
void outline_color_property_set_value(struct css_properties*, char*);
void outline_offset_property_set_value(struct css_properties*, char*);
void outline_style_property_set_value(struct css_properties*, char*);
void outline_width_property_set_value(struct css_properties*, char*);
void compute_inherit_outline(struct css_properties* dest, struct css_properties* source);
void update_outline(struct css_properties* dest, struct css_properties* source);
void free_outline(struct css_properties*);

#endif //UNTITLED_OUTLINE_H
