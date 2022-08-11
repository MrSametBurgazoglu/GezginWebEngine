//
// Created by samet on 23.04.2022.
//

#include "animation.h"
#include "../../functools/index_founder.h"

#include <string.h>
#include <stdlib.h>

#define ANIMATION_TIMING_STRING_COUNT 7

char* animation_timing_function_string[ANIMATION_TIMING_STRING_COUNT] = {
        "ease",
        "ease-in",
        "ease-in-out",
        "ease-out",
        "linear",
        "step-end",
        "step-start",
};

css_animation_timing_function cssAnimationTimingFunctionList[ANIMATION_TIMING_STRING_COUNT] = {
        CSS_ANIMATION_TIMING_FUNCTION_EASE,
        CSS_ANIMATION_TIMING_FUNCTION_EASE_IN,
        CSS_ANIMATION_TIMING_FUNCTION_EASE_IN_OUT,
        CSS_ANIMATION_TIMING_FUNCTION_EASE_OUT,
        CSS_ANIMATION_TIMING_FUNCTION_LINEAR,
        CSS_ANIMATION_TIMING_FUNCTION_STEP_END,
        CSS_ANIMATION_TIMING_FUNCTION_STEP_START,
};

void set_animation_play_state(struct animation* animation, char * value){
    if(!strcmp(value, "paused")){
        animation->animationPlayState = CSS_ANIMATION_PLAY_STATE_PAUSED;
    }
    else{
        animation->animationPlayState = CSS_ANIMATION_PLAY_STATE_RUNNING;
    }
}

void set_animation_fill_mode(struct animation* animation, char * value){
    if(!strcmp(value, "forwards")){
        animation->animationFillMode = CSS_ANIMATION_FILL_MODE_FORWARDS;
    }
    else if(!strcmp(value, "backwards")){
        animation->animationFillMode = CSS_ANIMATION_FILL_MODE_BACKWARDS;
    }
    else if(!strcmp(value, "both")){
        animation->animationFillMode = CSS_ANIMATION_FILL_MODE_BOTH;
    }
    else{
        animation->animationFillMode = CSS_ANIMATION_FILL_MODE_NONE;
    }
}

void set_animation_direction(struct animation* animation, char * value){
    if(!strcmp(value, "reverse")){
        animation->animationDirection = CSS_ANIMATION_DIRECTION_REVERSE;
    }
    else if(!strcmp(value, "alternate")){
        animation->animationDirection = CSS_ANIMATION_DIRECTION_ALTERNATE;
    }
    else if(!strcmp(value, "alternate-reverse")){
        animation->animationDirection = CSS_ANIMATION_DIRECTION_ALTERNATE_REVERSE;
    }
    else{
        animation->animationDirection = CSS_ANIMATION_DIRECTION_NORMAL;
    }
}

void set_animation_iteration_count(struct animation* animation, char * value){
    animation->animation_iteration_count = (int) strtol(value, NULL, 10);
}

void set_animation_delay(struct animation* animation, char * value){
    animation->animation_delay = (int) strtol(value, NULL, 10);
}

void set_animation_duration(struct animation* animation, char * value){
    animation->animation_duration = (int) strtol(value, NULL, 10);
}

void set_animation_timing_function(struct animation* animation, char* value){
    char* start_index = strchr(value, '(');
    char* end_index = strchr(value, ')');
    if (start_index != NULL && end_index != NULL){
        size_t len = end_index - start_index;
        size_t len2 = value - start_index;
        char* text = malloc(len + 1);
        char* function_name = malloc(len2 + 1);
        memcpy(text, start_index, len);
        memcpy(function_name, value, len2);
        text[len] = '\0';
        function_name[len2] = '\0';
        if(!strcmp(function_name, "steps")){
            char* value2 = strtok(text, ",");
            int int_value = (int) strtol(value2, NULL, 10);
            value2 = strtok(NULL, ",");
            animation->animationTimingFunction.steps.value = int_value;
            if(!strcmp(value2, "start")){
                animation->animationTimingFunction.steps.is_start = true;
            }
            else{
                animation->animationTimingFunction.steps.is_start = false;
            }
            animation->which_animation_timing_part_active = 1;
        }
        else if(!strcmp(function_name, "cubic-bezier")){
            char* value2;
            int index2 = 0;//must be maximum 3
            while ((value2 = strtok(NULL, ",")) != NULL){//NEED BUGFIX
                animation->animationTimingFunction.cubic_bezier.values[index2++] = (int) strtol(value2, NULL, 10);
            }
            animation->which_animation_timing_part_active = 0;
        }
        else{
            animation->which_animation_timing_part_active = 2;
            animation->animationTimingFunction.timing_function_type = CSS_ANIMATION_TIMING_FUNCTION_EASE;
        }
    }
    else if(start_index == NULL){
        animation->which_animation_timing_part_active = 2;
        animation->animationTimingFunction.timing_function_type = CSS_ANIMATION_TIMING_FUNCTION_EASE;
    }
    else{
        animation->which_animation_timing_part_active = 2;
        int index = get_index_from_list_by_string(animation_timing_function_string, value, ANIMATION_TIMING_STRING_COUNT);
        if (index != -1){
            animation->animationTimingFunction.timing_function_type = cssAnimationTimingFunctionList[index];
        }
        else{//initial or wrong definition
            animation->animationTimingFunction.timing_function_type  = CSS_ANIMATION_TIMING_FUNCTION_EASE;
        }
    }
}

void set_animation_name(struct animation* animation, char* value){
    size_t len = strlen(value);
    char* name = malloc(len+1);
    memcpy(name, value, len);
    name[len] = '\0';
    animation->animation_name = name;
}



void animation_timing_function_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct animation));
    }
    if (!strcmp(value, "inherit")){
        current_widget->animation->animation_timing_function_inherit = true;
    }
    else{
        current_widget->animation->animation_timing_function_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->animation->animationTimingFunction.timing_function_type = CSS_ANIMATION_TIMING_FUNCTION_EASE;
        }
        else{
            set_animation_timing_function(current_widget->animation, value);
        }
    }
}

void animation_name_property_set_value(struct css_properties *current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct animation));
    }
    set_animation_name(current_widget->animation, value);
}



void animation_duration_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct animation));
    }
    if(!strcmp(value, "inherit")){
        current_widget->animation->animation_duration_inherit = true;
    }
    else{
        current_widget->animation->animation_duration_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->animation->animation_duration = 0;
        }
        else{
            set_animation_duration(current_widget->animation, value);
        }
    }
}

void animation_delay_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct animation));
    }
    if(!strcmp(value, "inherit")){
        current_widget->animation->animation_delay_inherit = true;
    }
    else{
        current_widget->animation->animation_delay_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->animation->animation_delay = 0;
        }
        else{
            set_animation_delay(current_widget->animation, value);
        }
    }
}

void animation_iteration_count_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct animation));
    }
    if(!strcmp(value, "inherit")){
        current_widget->animation->animation_iteration_count_inherit = true;
    }
    else{
        current_widget->animation->animation_iteration_count_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->animation->animation_iteration_count = 1;
        }
        else{
            set_animation_iteration_count(current_widget->animation, value);
        }
    }
}

void animation_direction_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct animation));
    }
    if(!strcmp(value, "inherit")){
        current_widget->animation->animation_direction_inherit = true;
    }
    else{
        current_widget->animation->animation_direction_inherit = true;
        if(!strcmp(value, "initial")){
            current_widget->animation->animation_direction_inherit = true;
        }
        else{
            set_animation_direction(current_widget->animation, value);
        }
    }
}

void animation_fill_mode_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct animation));
    }
    if(!strcmp(value, "inherit")){
        current_widget->animation->animation_fill_mode_inherit = true;
    }
    else{
        current_widget->animation->animation_fill_mode_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->animation->animationFillMode = CSS_ANIMATION_FILL_MODE_NONE;
        }
        else{
            set_animation_fill_mode(current_widget->animation, value);
        }
    }
}

void animation_play_state_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct animation));
    }
    if(!strcmp(value, "inherit")){
        current_widget->animation->animation_play_state_inherit = true;
    }
    else{
        current_widget->animation->animation_play_state_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->animation->animationPlayState = CSS_ANIMATION_PLAY_STATE_RUNNING;
        }
        else{
            set_animation_play_state(current_widget->animation, value);
        }
    }
}

void animation_property_set_value(struct css_properties *current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct animation));
    }
    char* value2 = strtok(value, " ");//animation name
    if(!strcmp(value2, "initial")){
        current_widget->animation->animation_name = "none";
        current_widget->animation->animation_duration = 0;
        current_widget->animation->animationTimingFunction.timing_function_type = CSS_ANIMATION_TIMING_FUNCTION_EASE;
        current_widget->animation->animation_delay = 0;
        current_widget->animation->animation_iteration_count = 1;
        current_widget->animation->animationDirection = CSS_ANIMATION_DIRECTION_NORMAL;
        current_widget->animation->animationFillMode = CSS_ANIMATION_FILL_MODE_NONE;
        current_widget->animation->animationPlayState = CSS_ANIMATION_PLAY_STATE_RUNNING;
    }
    else if(!strcmp(value2, "inherit")){
        current_widget->animation_inherit = true;
    }
    else{
        const char* delim = " ";
        animation_name_property_set_value(current_widget, value2);
        value2 = strtok(NULL, delim);//animation duration
        if(value2 != NULL){
            animation_duration_property_set_value(current_widget, value2);
            value2 = strtok(NULL, delim);
            if(value2 != NULL){
                animation_timing_function_property_set_value(current_widget, value2);
                value2 = strtok(NULL, delim);
                if(value2 != NULL){
                    animation_delay_property_set_value(current_widget, value2);
                    value2 = strtok(NULL, delim);
                    if(value2 != NULL){
                        animation_iteration_count_property_set_value(current_widget, value2);
                        value2 = strtok(NULL, delim);
                        if(value2 != NULL){
                            animation_direction_property_set_value(current_widget, value2);
                            value2 = strtok(NULL, delim);
                            if(value2 != NULL){
                                animation_fill_mode_property_set_value(current_widget, value2);
                                value2 = strtok(NULL, delim);
                                if(value2 != NULL){
                                    animation_play_state_property_set_value(current_widget, value2);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
