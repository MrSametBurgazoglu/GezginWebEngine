//
// Created by samet on 8.04.2022.
//


#include <string.h>
#include "css_properties_searcher.h"
#include "css_all_properties.h"

#define CSS_PROPERTY_COUNT 147

//TODO WILL "ALL" ADDED
char* css_properties_list[CSS_PROPERTY_COUNT] = {
        "accent-color",
        "align-content",
        "align-items",
        "align-self",
        "animation",
        "animation-delay",
        "animation-direction",
        "animation-duration",
        "animation-fill-mode",
        "animation-iteration-count",
        "animation-name",
        "animation-play-state",
        "animation-timing-function",
        "backdrop-filter",
        "backface-visibility",
        "background",
        "background-attachment",
        "background-blend-mode",
        "background-clip",
        "background-color",
        "background-image",
        "background-origin",
        "background-position",
        "background-repeat",
        "background-size",
        "border",
        "border-bottom",
        "border-bottom-color",
        "border-bottom-left-radius",
        "border-bottom-right-radius",
        "border-bottom-style",
        "border-bottom-width",
        "border-collapse",
        "border-color",
        "border-image",
        "border-image-outset",
        "border-image-repeat",
        "border-image-slice",
        "border-image-source",
        "border-image-width",
        "border-left",
        "border-left-color",
        "border-left-style",
        "border-left-width",
        "border-radius",
        "border-right",
        "border-right-color",
        "border-right-style",
        "border-right-width",
        "border-spacing",
        "border-style",
        "border-top",
        "border-top-color",
        "border-top-left-radius",
        "border-top-right-radius",
        "border-top-style",
        "border-top-width",
        "border-width",
        "bottom",
        "color",
        "column-count",
        "column-fill",
        "column-gap",
        "column-rule",
        "column-rule-color",
        "column-rule-style",
        "column-rule-width",
        "column-span",
        "column-width",
        "columns",
        "flex",
        "flex-basis",
        "flex-direction",
        "flex-flow",
        "flex-grow",
        "flex-shrink",
        "flex-wrap",
        "font",
        "font-family",
        "font-kerning",
        "font-size",
        "font-stretch",
        "font-style",
        "font-variant",
        "font-variant-caps",
        "font-weight",
        "grid-area",
        "grid-auto-columns",
        "grid-auto-flow",
        "grid-auto-rows",
        "grid-column",
        "grid-column-end",
        "grid-column-gap",
        "grid-column-start",
        "grid-gap",
        "grid-row",
        "grid-row-end",
        "grid-row-gap",
        "grid-row-start",
        "grid-template",
        "grid-template-areas",
        "grid-template-columns",
        "grid-template-rows",
        "height",
        "left",
        "margin",
        "margin-bottom",
        "margin-left",
        "margin-right",
        "margin-top",
        "max-height",
        "max-width",
        "min-height",
        "min-width",
        "opacity",
        "outline",
        "outline-color",
        "outline-offset",
        "outline-style",
        "outline-width",
        "overflow",
        "overflow-wrap",
        "overflow-x",
        "overflow-y",
        "padding",
        "padding-bottom",
        "padding-left",
        "padding-right",
        "padding-top",
        "position",
        "resize"
        "right",
        "text-align",
        "text-align-last",
        "text-decoration",
        "text-decoration-color",
        "text-decoration-line",
        "text-decoration-style",
        "text-decoration-thickness",
        "text-indent",
        "text-justify",
        "text-overflow",
        "text-shadow",
        "text-transform",
        "top",
        "visibility",
        "width"
};


//function for testing
//void func(struct css_properties* current_css_widget, char * value){
//    current_css_widget->
//}

struct css_property_function css_property_function_list[CSS_PROPERTY_COUNT] = {
        accent_color_property_set_value,
        align_content_property_set_value,
        align_items_property_set_value,
        align_self_property_set_value,
        animation_property_set_value,
        animation_delay_property_set_value,
        animation_direction_property_set_value,
        animation_duration_property_set_value,
        animation_fill_mode_property_set_value,
        animation_iteration_count_property_set_value,
        animation_name_property_set_value,
        animation_play_state_property_set_value,
        animation_timing_function_property_set_value,
        backdrop_filter_property_set_value,
        backface_visibility_property_set_value,
        background_property_set_value,
        background_attachment_property_set_value,
        background_blend_mode_property_set_value,
        background_clip_property_set_value,
        background_color_property_set_value,
        background_image_property_set_value,
        background_origin_property_set_value,
        background_position_property_set_value,
        background_repeat_property_set_value,
        background_size_property_set_value,
        border_property_set_value,
        border_bottom_property_set_value,
        border_bottom_color_property_set_value,
        border_bottom_left_radius_property_set_value,
        border_bottom_right_radius_property_set_value,
        border_bottom_style_property_set_value,
        border_bottom_width_property_set_value,
        border_collapse_property_set_value,
        border_color_property_set_value,
        border_image_property_set_value,
        border_image_outset_property_set_value,
        border_image_repeat_property_set_value,
        border_image_slice_property_set_value,
        border_image_source_property_set_value,
        border_image_width_property_set_value,
        border_left_property_set_value,
        border_left_color_property_set_value,
        border_left_style_property_set_value,
        border_left_width_property_set_value,
        border_radius_property_set_value,
        border_right_property_set_value,
        border_right_color_property_set_value,
        border_right_style_property_set_value,
        border_right_width_property_set_value,
        border_spacing_property_set_value,
        border_style_property_set_value,
        border_top_property_set_value,
        border_top_color_property_set_value,
        border_top_left_radius_property_set_value,
        border_top_right_radius_property_set_value,
        border_top_style_property_set_value,
        border_top_width_property_set_value,
        border_width_property_set_value,
        bottom_property_set_value,
        color_property_set_value,
        column_count_property_set_value,
        column_fill_property_set_value,
        column_gap_property_set_value,
        column_rule_property_set_value,
        column_rule_color_property_set_value,
        column_rule_style_property_set_value,
        column_rule_width_property_set_value,
        column_span_property_set_value,
        column_width_property_set_value,
        columns_property_set_value,
        flex_property_set_value,
        flex_basis_property_set_value,
        flex_direction_property_set_value,
        flex_flow_property_set_value,
        flex_grow_property_set_value,
        flex_shrink_property_set_value,
        flex_wrap_property_set_value,
        font_property_set_value,
        font_family_property_set_value,
        font_kerning_property_set_value,
        font_size_property_set_value,
        font_stretch_property_set_value,
        font_style_property_set_value,
        font_variant_property_set_value,
        font_variant_caps_property_set_value,
        font_weight_property_set_value,
        grid_property_set_value,
        grid_area_property_set_value,
        grid_auto_columns_property_set_value,
        grid_auto_flow_property_set_value,
        grid_auto_rows_property_set_value,
        grid_column_property_set_value,
        grid_column_end_property_set_value,
        grid_column_gap_property_set_value,
        grid_column_start_property_set_value,
        grid_gap_property_set_value,
        grid_row_property_set_value,
        grid_row_end_property_set_value,
        grid_row_gap_property_set_value,
        grid_row_start_property_set_value,
        grid_template_areas_property_set_value,
        grid_template_columns_property_set_value,
        grid_template_rows_property_set_value,
        height_property_set_value,
        left_property_set_value,
        margin_property_set_value,
        margin_bottom_property_set_value,
        margin_left_property_set_value,
        margin_right_property_set_value,
        margin_top_property_set_value,
        max_height_property_set_value,
        max_width_property_set_value,
        min_height_property_set_value,
        min_width_property_set_value,
        opacity_property_set_value,
        outline_property_set_value,
        outline_color_property_set_value,
        outline_offset_property_set_value,
        outline_style_property_set_value,
        outline_width_property_set_value,
        overflow_property_set_value,
        overflow_wrap_property_set_value,
        overflow_x_property_set_value,
        overflow_y_property_set_value,
        padding_property_set_value,
        padding_bottom_property_set_value,
        padding_left_property_set_value,
        padding_right_property_set_value,
        padding_top_property_set_value,
        position_property_set_value,
        resize_property_set_value,
        right_property_set_value,
        text_align_property_set_value,
        text_align_last_property_set_value,
        text_decoration_property_set_value,
        text_decoration_color_property_set_value,
        text_decoration_line_property_set_value,
        text_decoration_style_property_set_value,
        text_decoration_thickness_property_set_value,
        text_indent_property_set_value,
        text_justify_property_set_value,
        text_overflow_property_set_value,
        text_shadow_property_set_value,
        text_transform_property_set_value,
        top_property_set_value,
        visibility_property_set_value,
        width_property_set_value,
};


/*
 * find property by using binary search
 * */
int css_property_search(char* property)
{
    int l, m, r, result;
    l = 0;
    r = CSS_PROPERTY_COUNT;

    while (l <= r) {
        m = l + (r - l) / 2;
        result = strcmp(css_properties_list[m], property);

        if (result == 0) return m;
        if (result < 0) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int get_css_property_number(char* property){
    return css_property_search(property);
}

void set_css_property_by_number(int number, struct css_properties* current_widget, char* value){
    css_property_function_list[number].css_widget_property_function(current_widget, value);
}