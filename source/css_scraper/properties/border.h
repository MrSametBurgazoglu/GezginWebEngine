//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_BORDER_H
#define UNTITLED_BORDER_H

#include "css_enum_variables.h"
#include "css_color.h"

struct border_line_width{
    css_border_line_type borderLineType;
    int value;
};

struct border_width{
    struct border_line_width* top_border;
    struct border_line_width* left_border;
    struct border_line_width* right_border;
    struct border_line_width* bottom_border;
};

struct border_style{
    css_border_style_type borderStyleTypeTop;
    css_border_style_type borderStyleTypeBottom;
    css_border_style_type borderStyleTypeLeft;
    css_border_style_type borderStyleTypeRight;
};

struct border_color{
    struct color_rgba* topBorderColor;
    struct color_rgba* bottomBorderColor;
    struct color_rgba* rightBorderColor;
    struct color_rgba* leftBorderColor;
};

struct border_radius{
    css_border_radius_type border_top_left_radius_type;
    css_border_radius_type border_top_right_radius_type;
    css_border_radius_type border_bottom_left_radius_type;
    css_border_radius_type border_bottom_right_radius_type;
    int border_top_left_radius_value;
    int border_top_right_radius_value;
    int border_bottom_left_radius_value;
    int border_bottom_right_radius_value;
};

struct border_image_source{
    css_border_image_source_type borderImageSourceType;
    char * value;
};

struct border_image_slice{
    css_border_image_slice_type borderImageSliceType;
    int value;
};

struct border_image_width{
    css_border_image_width_type borderImageWidthType;
    int value;
};

struct border_image_outset{
    css_border_image_outset_type borderImageOutsetType;
    int value;
};

struct border_image{
    struct border_image_source* imageSource;
    struct border_image_slice* imageSlice;
    struct border_image_width* imageWidth;
    struct border_image_outset* imageOutset;
    css_border_image_repeat_type imageRepeatType;
};

struct css_border{
    struct border_width* borderWidth;
    struct border_style* borderStyle;
    struct border_color* borderColor;
    struct border_radius* borderRadius;
    css_border_collapse_type borderCollapseType;
};

#endif //UNTITLED_BORDER_H
