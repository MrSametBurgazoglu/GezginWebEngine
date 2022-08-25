//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_FONT_H
#define UNTITLED_FONT_H

#include "css_enum_variables.h"
#include "../css_widget.h"

struct font{
    bool font_family_inherited;
    bool font_size_inherited;
    bool font_stretch_inherited;
    bool font_style_inherited;
    bool font_variant_inherited;
    bool font_variant_caps_inherited;
    bool font_weight_inherited;

    bool font_kerning;

    char** font_family;

    int font_family_count;
    int font_weight_value;
    int font_size_value;

    //TODO MAKE IT ALPHABETIC
    css_font_special_type fontSpecialType;
    css_font_style fontStyle;
    css_font_variant_type fontVariantType;
    css_font_weight_type fontWeightType;
    css_font_size_type fontSizeType;
    css_font_stretch_type fontStretchType;
    css_font_variant_caps_type fontVariantCapsType;
};

void font_property_set_value(struct css_properties *, char* value);
void font_family_property_set_value(struct css_properties *, char* value);
void font_feature_settings_property_set_value(struct css_properties *, char* value);//TODO RESEARCH THIS VARIABLE USAGE
void font_kerning_property_set_value(struct css_properties *, char* value);
void font_size_property_set_value(struct css_properties *, char* value);
void font_stretch_property_set_value(struct css_properties *, char* value);
void font_style_property_set_value(struct css_properties *, char* value);
void font_variant_property_set_value(struct css_properties *, char* value);
void font_variant_caps_property_set_value(struct css_properties *, char* value);
void font_weight_property_set_value(struct css_properties *, char* value);
void compute_inherit_font(struct css_properties* dest, struct css_properties* source);
void update_font(struct css_properties* dest, struct css_properties* source);
void free_font(struct css_properties*);

#endif //UNTITLED_FONT_H
