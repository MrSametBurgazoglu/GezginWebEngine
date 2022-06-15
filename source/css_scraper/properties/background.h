//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_BACKGROUND_H
#define UNTITLED_BACKGROUND_H

#include "css_enum_variables.h"
#include "css_color.h"
#include "../css_widget.h"

struct css_background_position{
    css_background_position_type positionType;
    int value1;
    int value2;
};

struct css_background_size{
    css_background_size_type backgroundSizeType;
    int value1;
    int value2;
};

struct css_background{
    struct color_rgba* background_color;
    char** background_image_list;
    int background_image_count;
    struct css_background_position* backgroundPosition;
    css_background_repeat_type backgroundRepeatType;
    struct css_background_size* backgroundSize;
    css_background_attachment backgroundAttachment;
    css_background_blend_mode backgroundBlendMode;
    css_background_clip backgroundClip;
    css_background_origin backgroundOrigin;
};

void background_blend_property_set_value(struct css_properties* current_widget,char * value);

void background_color_property_set_value(struct css_properties* current_widget,char * value);

void background_image_property_set_value(struct css_properties* current_widget,char * value);

void background_position_property_set_value(struct css_properties* current_widget,char * value);

void background_size_property_set_value(struct css_properties* current_widget,char * value);

void background_repeat_property_set_value(struct css_properties* current_widget,char * value);

void background_origin_property_set_value(struct css_properties* current_widget,char * value);

void background_clip_property_set_value(struct css_properties* current_widget,char * value);

void background_attachment_property_set_value(struct css_properties* current_widget,char * value);

void background_property_set_value(struct css_properties* current_widget,char * value);



#endif //UNTITLED_BACKGROUND_H
