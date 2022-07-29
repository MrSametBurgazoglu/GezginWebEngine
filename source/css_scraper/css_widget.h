//
// Created by samet on 11.04.2022.
//

#ifndef UNTITLED_CSS_WIDGET_H
#define UNTITLED_CSS_WIDGET_H

#include <stdbool.h>
#include "properties/css_color.h"
#include "properties/box_shadow.h"
#include "properties/clip.h"
#include "properties/edge.h"
#include "properties/flex.h"
#include "properties/gap.h"

//MAKE IT ALPHABETIC AFTER FINISHED
struct css_properties{
    bool accent_color_inherit;
    bool align_content_inherit;
    bool align_items_inherit;
    bool align_self_inherit;
    bool animation_inherit;
    bool backdropFilter_inherit;
    bool backface_visibility_inherit;
    bool background_inherit;
    bool border_inherit;
    bool font_inherit;
    bool text_align_inherit;
    bool text_align_last_inherit;
    bool text_decoration_inherit;
    bool text_indent_inherit;
    bool text_justify_inherit;
    bool text_overflow_inherit;
    bool text_shadow_inherit;
    bool text_transform_inherit;
    bool column_count_inherit;
    bool column_fill_inherit;
    bool column_gap_inherit;
    bool column_rule_inherit;
    bool column_span_inherit;
    bool column_width_inherit;

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

    struct font* font;

    css_text_align_type textAlign;
    css_text_align_type textAlignLast;
    struct text_decoration* textDecoration;
    struct text_indent* textIndent;
    css_text_justify_type textJustify;
    css_text_overflow_type textOverflow;
    css_text_transform_type textTransformType;
    struct text_shadow* textShadow;

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
    css_column_fill_type column_fill;
    int column_gap;
    struct column_rule* columnRule;
    css_column_span_type columnSpanType;
    int column_width;
    int column_count;

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
    struct gap* gap;

};

#endif //UNTITLED_CSS_WIDGET_H
