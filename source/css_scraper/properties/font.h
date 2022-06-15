//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_FONT_H
#define UNTITLED_FONT_H

#include "css_enum_variables.h"

struct font{
    css_font_style fontStyle;
    css_font_variant fontVariant;
    css_font_weight fontWeightType;
    int font_weight_value;
};

struct font_size{
    css_font_size_type fontSizeType;
    int font_size_value;
};

#endif //UNTITLED_FONT_H
