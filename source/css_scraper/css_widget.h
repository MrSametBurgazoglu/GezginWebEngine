//
// Created by samet on 11.04.2022.
//

#ifndef UNTITLED_CSS_WIDGET_H
#define UNTITLED_CSS_WIDGET_H

#include <stdbool.h>
#include "properties/css_color.h"
#include "properties/border.h"
#include "properties/box_shadow.h"
#include "properties/clip.h"
#include "properties/column.h"
#include "properties/edge.h"
#include "properties/flex.h"
#include "properties/font.h"
#include "properties/gap.h"

struct css_properties{
    bool accent_color_inherit;
    bool align_content_inherit;
    bool align_items_inherit;
    bool align_self_inherit;
    bool animation_inherit;
    bool backdropFilter_inherit;
    bool backface_visibility_inherit;
    struct color_rgba* accent_color;
    css_align align_content;
    css_align align_items;
    css_align align_self;
    struct css_animation* animation;
    css_filter_type backdropFilterType;
    void* backdrop_filter;
    css_visibility backfaceVisibility;
    struct css_background* background;
    struct css_border* border;
    struct edge_position* edgePosition;
    css_box_decoration_break_type boxDecorationBreakType;
    struct box_shadow* boxShadow;
    css_box_sizing_type boxSizingType;
    css_break_type break_after;
    css_break_type break_before;
    css_break_type break_inside;
    css_caption_side captionSide;
    struct color_rgba* caret_color;
    char* charset;
    css_clear_type clear;
    struct clip* clip;
    //TODO CLIP_PATH
    struct color_rgba *color;
    struct column columns;
    css_column_fill_type column_fill;
    struct column_gap columnGap;
    struct column_rule columnRule;
    css_column_span_type columnSpanType;
    struct column_width columnWidth;
    //TODO CONTENT
    char* counter_increment;
    char* counter_reset;
    css_cursor_type cursor;
    css_direction_type direction;
    css_display_type display;
    css_empty_cells_type empty_cells;
    struct filter* filter;
    struct flex* flex;
    struct flex_flow* flexFlow;
    css_float_type floatType;
    struct font* font;
    //TODO font_feature_settings
    css_property_value_type font_kerning;
    struct font_size* fontSize;
    //TODO font_size_adjust
    css_font_stretch_type fontStretch;
    css_font_variant_caps_type fontVariantCaps;
    struct gap* gap;

};

#endif //UNTITLED_CSS_WIDGET_H