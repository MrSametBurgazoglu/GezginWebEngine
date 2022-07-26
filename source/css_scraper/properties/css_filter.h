//
// Created by samet on 30.05.2022.
//

#ifndef UNTITLED_CSS_FILTER_H
#define UNTITLED_CSS_FILTER_H

#include "css_enum_variables.h"
#include "css_color.h"
#include "../css_widget.h"

struct css_filter_blur{
    css_value_type valueType;
    float value;
};

struct css_filter_brightness{
    css_value_type valueType;
    float value;
};

struct css_filter_contrast{
    css_value_type valueType;
    float value;
};

struct css_filter_drop_shadow{
    css_value_type valueType;
    float value_list[3];
    struct color_rgba* color;
};

struct css_filter_grayscale{
    css_value_type valueType;
    float value;
};

struct css_filter_hue_rotate{
    css_value_type valueType;
    float value;
};

struct css_filter_invert{
    css_value_type valueType;
    float value;
};

struct css_filter_opacity{
    css_value_type valueType;
    float value;
};

struct css_filter_saturate{
    css_value_type valueType;
    float value;
};

struct css_filter_sepia{
    css_value_type valueType;
    float value;
};

void set_filter_property(void*, char*, char*);

#endif //UNTITLED_CSS_FILTER_H