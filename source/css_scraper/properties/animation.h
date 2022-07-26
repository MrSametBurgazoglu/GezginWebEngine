//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_ANIMATION_H
#define UNTITLED_ANIMATION_H

#include <stdbool.h>
//#include "css_enum_variables.h"
#include "../css_widget.h"

typedef enum {
    CSS_ANIMATION_TIMING_FUNCTION_LINEAR,
    CSS_ANIMATION_TIMING_FUNCTION_EASE,
    CSS_ANIMATION_TIMING_FUNCTION_EASE_IN,
    CSS_ANIMATION_TIMING_FUNCTION_EASE_OUT,
    CSS_ANIMATION_TIMING_FUNCTION_EASE_IN_OUT,
    CSS_ANIMATION_TIMING_FUNCTION_STEP_START,
    CSS_ANIMATION_TIMING_FUNCTION_STEP_END,
} css_animation_timing_function;

typedef enum {
    CSS_ANIMATION_DIRECTION_NORMAL,
    CSS_ANIMATION_DIRECTION_REVERSE,
    CSS_ANIMATION_DIRECTION_ALTERNATE,
    CSS_ANIMATION_DIRECTION_ALTERNATE_REVERSE,
} css_animation_direction;

typedef enum {
    CSS_ANIMATION_FILL_MODE_NONE,
    CSS_ANIMATION_FILL_MODE_FORWARDS,
    CSS_ANIMATION_FILL_MODE_BACKWARDS,
    CSS_ANIMATION_FILL_MODE_BOTH,
} css_animation_fill_mode;


typedef enum {
    CSS_ANIMATION_PLAY_STATE_PAUSED,
    CSS_ANIMATION_PLAY_STATE_RUNNING,
} css_animation_play_state;


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

struct css_animation{
    char* animation_name;
    int animation_delay;
    bool animation_delay_inherit;
    int animation_duration;
    bool animation_duration_inherit;
    int animation_iteration_count;
    bool animation_iteration_count_inherit;
    css_animation_direction animationDirection;
    bool animation_direction_inherit;
    css_animation_fill_mode animationFillMode;
    bool animation_fill_mode_inherit;
    css_animation_play_state animationPlayState;
    bool animation_play_state_inherit;
    union CSS_ANIMATION_TIMING_FUNCTION animationTimingFunction;
    bool animation_timing_function_inherit;
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

#endif //UNTITLED_ANIMATION_H
