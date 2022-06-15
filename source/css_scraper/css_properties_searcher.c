//
// Created by samet on 8.04.2022.
//


#include <string.h>
#include "css_properties_searcher.h"
#include "css_all_properties.h"


//TODO WILL "ALL" ADDED
char* css_properties_list[] = {
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
        "color",
};

int css_property_count = 16;


//function for testing
//void func(struct css_properties* current_css_widget, char * value){
//    current_css_widget->
//}

struct css_property_function css_property_function_list[] = {
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
        /*background_property_set_value, NOT IMPLEMENTED YET
        background_attachment_property_set_value,
        background_blend_property_set_value,
         */
        color_property_set_value,
};


/*
 * find property by using binary search
 * */
int css_property_search(char* property)
{
    int l, m, r, result;
    l = 0;
    r = css_property_count;

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