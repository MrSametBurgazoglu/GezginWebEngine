//
// Created by samet on 26.06.2022.
//

#ifndef UNTITLED_TEXT_H
#define UNTITLED_TEXT_H

#include "css_enum_variables.h"
#include "css_color.h"
#include "../css_widget.h"

struct text_decoration{
    bool text_decoration_color_inherit;
    bool text_decoration_line_inherit;
    bool text_decoration_style_inherit;
    bool text_decoration_thickness_inherit;
    struct color_rgba* textDecorationColor;
    css_text_decoration_line_type textDecorationLine;
    css_text_decoration_style textDecorationStyle;
    css_text_thickness_type textThicknessType;
    int text_thickness_value;

};

struct text_indent{
    css_value_type valueType;
    int value;
};

//if this property is none free its struct
struct text_shadow{
    int h_shadow;
    int v_shadow;
    int blur_radius;
    struct color_rgba* colorRgba;
};

void text_align_property_set_value(struct css_properties*, char*);
void text_align_last_property_set_value(struct css_properties*, char*);
void text_decoration_property_set_value(struct css_properties*, char*);
void text_decoration_color_property_set_value(struct css_properties*, char*);
void text_decoration_line_property_set_value(struct css_properties*, char*);
void text_decoration_style_property_set_value(struct css_properties*, char*);
void text_decoration_thickness_property_set_value(struct css_properties*, char*);
void text_indent_property_set_value(struct css_properties*, char*);
void text_justify_property_set_value(struct css_properties*, char*);
void text_overflow_property_set_value(struct css_properties*, char*);
void text_shadow_property_set_value(struct css_properties*, char*);
void text_transform_property_set_value(struct css_properties*, char*);

#endif //UNTITLED_TEXT_H
