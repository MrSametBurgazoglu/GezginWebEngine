//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_ANIMATION_H
#define UNTITLED_ANIMATION_H

#include <stdbool.h>
#include "css_enum_variables.h"
#include "../css_widget.h"


struct cubic_bezier_function{
    int values[4];
};

struct steps_function{
    int value;
    bool is_start;
};

union CSS_ANIMATION_TIMING_FUNCTION{
    struct cubic_bezier_function cubic_bezier;
    struct steps_function steps;
    css_animation_timing_function timing_function_type;
};

struct animation{
    bool animation_name_inherit;
    bool animation_delay_inherit;
    bool animation_duration_inherit;
    bool animation_iteration_count_inherit;
    bool animation_direction_inherit;
    bool animation_fill_mode_inherit;
    bool animation_play_state_inherit;
    bool animation_timing_function_inherit;

    char* animation_name;
    int animation_delay;
    int animation_duration;
    int animation_iteration_count;;
    css_animation_direction animationDirection;
    css_animation_fill_mode animationFillMode;
    css_animation_play_state animationPlayState;
    union CSS_ANIMATION_TIMING_FUNCTION animationTimingFunction;
    int which_animation_timing_part_active;//0,1,2
};

void animation_property_set_value(struct css_properties*, char*);
void animation_play_state_property_set_value(struct css_properties* current_css_widget, char * value);
void animation_fill_mode_property_set_value(struct css_properties* current_css_widget, char * value);
void animation_direction_property_set_value(struct css_properties* current_css_widget, char * value);
void animation_iteration_count_property_set_value(struct css_properties* current_css_widget, char * value);
void animation_delay_property_set_value(struct css_properties* current_css_widget, char * value);
void animation_duration_property_set_value(struct css_properties* current_css_widget, char * value);
void animation_timing_function_property_set_value(struct css_properties* current_css_widget, char* value);
void animation_name_property_set_value(struct css_properties* current_css_widget, char* value);
void compute_animation(struct css_properties* dest, struct css_properties* source);
void free_animation(struct css_properties*);

#endif //UNTITLED_ANIMATION_H
