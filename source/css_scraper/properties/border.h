//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_BORDER_H
#define UNTITLED_BORDER_H

#include "css_enum_variables.h"
#include "css_color.h"
#include "../css_widget.h"

struct border_line_width{
    css_border_line_type borderLineType;
    int value;
};

struct border_width{
    bool border_width_top_inherit;
    bool border_width_left_inherit;
    bool border_width_right_inherit;
    bool border_width_bottom_inherit;
    struct border_line_width* top_border;
    struct border_line_width* left_border;
    struct border_line_width* right_border;
    struct border_line_width* bottom_border;
};

struct border_style{
    bool border_style_top_inherit;
    bool border_style_left_inherit;
    bool border_style_right_inherit;
    bool border_style_bottom_inherit;
    css_border_style_type borderStyleTypeTop;
    css_border_style_type borderStyleTypeBottom;
    css_border_style_type borderStyleTypeLeft;
    css_border_style_type borderStyleTypeRight;
};

struct border_color{
    bool border_color_top_inherit;
    bool border_color_left_inherit;
    bool border_color_right_inherit;
    bool border_color_bottom_inherit;
    struct color_rgba* topBorderColor;
    struct color_rgba* bottomBorderColor;
    struct color_rgba* rightBorderColor;
    struct color_rgba* leftBorderColor;
};

struct border_radius{
    bool border_top_left_radius_inherit;
    bool border_top_right_radius_inherit;
    bool border_bottom_left_radius_inherit;
    bool border_bottom_right_radius_inherit;
    css_border_radius_type border_top_left_radius_type;
    css_border_radius_type border_top_right_radius_type;
    css_border_radius_type border_bottom_left_radius_type;
    css_border_radius_type border_bottom_right_radius_type;
    int border_top_left_radius_value;
    int border_top_right_radius_value;
    int border_bottom_left_radius_value;
    int border_bottom_right_radius_value;
};

struct border_image_slice{
    css_border_image_slice_type borderImageSliceTypeTop;
    css_border_image_slice_type borderImageSliceTypeBottom;
    css_border_image_slice_type borderImageSliceTypeLeft;
    css_border_image_slice_type borderImageSliceTypeRight;
    int valueTop;
    int valueBottom;
    int valueLeft;
    int valueRight;
};

struct border_image_width{
    css_border_image_width_type borderImageWidthTypeTop;
    css_border_image_width_type borderImageWidthTypeBottom;
    css_border_image_width_type borderImageWidthTypeLeft;
    css_border_image_width_type borderImageWidthTypeRight;
    int valueTop;
    int valueBottom;
    int valueLeft;
    int valueRight;
};

struct border_image_outset{
    css_border_image_outset_type borderImageOutsetTypeTop;
    css_border_image_outset_type borderImageOutsetTypeBottom;
    css_border_image_outset_type borderImageOutsetTypeLeft;
    css_border_image_outset_type borderImageOutsetTypeRight;
    int valueTop;
    int valueBottom;
    int valueLeft;
    int valueRight;
};

struct border_image{
    bool border_image_source_inherit;
    bool border_image_slice_inherit;
    bool border_image_width_inherit;
    bool border_image_outset_inherit;
    bool border_image_repeat_inherit;
    char* imageSource;
    struct border_image_slice* imageSlice;
    struct border_image_width* imageWidth;
    struct border_image_outset* imageOutset;
    css_border_image_repeat_type imageRepeatType;
};

struct border_spacing{
    int h_spacing;
    int v_spacing;
};

struct css_border{
    bool border_width_inherit;
    bool border_style_inherit;
    bool border_color_inherit;
    bool border_radius_inherit;
    bool border_spacing_inherit;
    bool border_image_inherit;
    bool border_collapse_inherit;
    struct border_width* borderWidth;
    struct border_style* borderStyle;
    struct border_color* borderColor;
    struct border_radius* borderRadius;
    struct border_spacing* borderSpacing;
    struct border_image* borderImage;
    css_border_collapse_type borderCollapseType;
};

void border_property_set_value(struct css_properties*, char*);
void border_bottom_property_set_value(struct css_properties*, char*);
void border_bottom_color_property_set_value(struct css_properties*, char*);
void border_bottom_left_radius_property_set_value(struct css_properties*, char*);
void border_bottom_right_radius_property_set_value(struct css_properties*, char*);
void border_bottom_style_property_set_value(struct css_properties*, char*);
void border_bottom_width_property_set_value(struct css_properties*, char*);
void border_collapse_property_set_value(struct css_properties*, char*);
void border_color_property_set_value(struct css_properties*, char*);
void border_image_property_set_value(struct css_properties*, char*);
void border_image_outset_property_set_value(struct css_properties*, char*);
void border_image_repeat_property_set_value(struct css_properties*, char*);
void border_image_slice_property_set_value(struct css_properties*, char*);
void border_image_source_property_set_value(struct css_properties*, char*);
void border_image_width_property_set_value(struct css_properties*, char*);
void border_left_property_set_value(struct css_properties*, char*);
void border_left_color_property_set_value(struct css_properties*, char*);
void border_left_style_property_set_value(struct css_properties*, char*);
void border_left_width_property_set_value(struct css_properties*, char*);
void border_radius_property_set_value(struct css_properties*, char*);
void border_right_property_set_value(struct css_properties*, char*);
void border_right_color_property_set_value(struct css_properties*, char*);
void border_right_style_property_set_value(struct css_properties*, char*);
void border_right_width_property_set_value(struct css_properties*, char*);
void border_spacing_property_set_value(struct css_properties*, char*);
void border_style_property_set_value(struct css_properties*, char*);
void border_top_property_set_value(struct css_properties*, char*);
void border_top_color_property_set_value(struct css_properties*, char*);
void border_top_left_radius_property_set_value(struct css_properties*, char*);
void border_top_right_radius_property_set_value(struct css_properties*, char*);
void border_top_style_property_set_value(struct css_properties*, char*);
void border_top_width_property_set_value(struct css_properties*, char*);
void border_width_property_set_value(struct css_properties*, char*);

#endif //UNTITLED_BORDER_H
