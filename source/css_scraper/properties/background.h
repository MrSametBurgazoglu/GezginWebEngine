//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_BACKGROUND_H
#define UNTITLED_BACKGROUND_H

#include "css_enum_variables.h"
#include "css_color.h"
#include "../css_widget.h"


// value1: left->0 right->1 center->2
// value2: top->0 center->1 bottom->2
struct css_background_position{
    css_background_position_type positionType;
    int value1;
    int value2;
};

struct css_background_size{
    css_background_size_type backgroundSizeType1;
    css_background_size_type backgroundSizeType2;
    int value1;
    int value2;
};

struct css_background_image_color{
    struct color_rgba* color;
    int percent;
};


struct css_background{
    struct color_rgba* background_color;
    char** background_image_list;
    struct css_background_image_color** background_image_color_list;
    css_background_type background_type;
    int background_image_count;
    bool background_image_inherit;
    bool background_position_inherit;
    bool background_color_inherit;
    bool background_repeat_inherit;
    bool background_origin_inherit;
    bool background_clip_inherit;
    bool background_attachment_inherit;
    bool background_size_inherit;
    struct css_background_position* backgroundPosition;
    css_background_repeat_type backgroundRepeatType;
    struct css_background_size* backgroundSize;
    css_background_attachment backgroundAttachment;
    css_background_blend_mode backgroundBlendMode;
    css_background_clip backgroundClip;
    css_background_origin backgroundOrigin;
};

void background_blend_mode_property_set_value(struct css_properties* current_widget,char * value);
void background_color_property_set_value(struct css_properties* current_widget,char * value);
void background_image_property_set_value(struct css_properties* current_widget,char * value);
void background_position_property_set_value(struct css_properties* current_widget,char * value);
void background_size_property_set_value(struct css_properties* current_widget,char * value);
void background_repeat_property_set_value(struct css_properties* current_widget,char * value);
void background_origin_property_set_value(struct css_properties* current_widget,char * value);
void background_clip_property_set_value(struct css_properties* current_widget,char * value);
void background_attachment_property_set_value(struct css_properties* current_widget,char * value);
void background_property_set_value(struct css_properties* current_widget,char * value);
void compute_inherit_background(struct css_properties* dest, struct css_properties* source);
void update_background(struct css_properties* dest, struct css_properties* source);
void free_background(struct css_properties*);

#endif //UNTITLED_BACKGROUND_H
