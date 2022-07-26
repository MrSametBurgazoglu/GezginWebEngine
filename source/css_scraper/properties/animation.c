//
// Created by samet on 23.04.2022.
//

#include <string.h>
#include <stdlib.h>
#include "animation.h"


void animation_timing_function_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct css_animation));
    }
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
            current_widget->animation->animationTimingFunction.steps.value = int_value;
            if(!strcmp(value2, "start")){
                current_widget->animation->animationTimingFunction.steps.is_start = true;
            }
            else{
                current_widget->animation->animationTimingFunction.steps.is_start = false;
            }
            current_widget->animation->which_animation_timing_part_active = 1;
        }
        else if(!strcmp(function_name, "cubic-bezier")){
            char* value2;
            int index2 = 0;//must be maximum 3
            while ((value2 = strtok(NULL, ",")) != NULL){
                current_widget->animation->animationTimingFunction.cubic_bezier.values[index2++] = (int) strtol(value2, NULL, 10);
            }
            current_widget->animation->which_animation_timing_part_active = 0;
        }
        else{
            current_widget->animation->which_animation_timing_part_active = 2;
            current_widget->animation->animationTimingFunction.timing_function_type = CSS_ANIMATION_TIMING_FUNCTION_EASE;
        }
    }
    else if(start_index == NULL){
        current_widget->animation->which_animation_timing_part_active = 2;
        current_widget->animation->animationTimingFunction.timing_function_type = CSS_ANIMATION_TIMING_FUNCTION_EASE;
    }
    else{
        current_widget->animation->which_animation_timing_part_active = 2;
        if(!strcmp(value, "linear")){
            current_widget->animation->animationTimingFunction.timing_function_type  = CSS_ANIMATION_TIMING_FUNCTION_LINEAR;
        }
        //else if(!strcmp(value, "ease")){
        //    current_widget->animation->animationTimingFunction.timing_function_type  = CSS_ANIMATION_TIMING_FUNCTION_EASE;
        //}
        else if(!strcmp(value, "ease-in")){
            current_widget->animation->animationTimingFunction.timing_function_type  = CSS_ANIMATION_TIMING_FUNCTION_EASE_IN;
        }
        else if(!strcmp(value, "ease-out")){
            current_widget->animation->animationTimingFunction.timing_function_type  = CSS_ANIMATION_TIMING_FUNCTION_EASE_OUT;
        }
        else if(!strcmp(value, "ease-in-out")){
            current_widget->animation->animationTimingFunction.timing_function_type  = CSS_ANIMATION_TIMING_FUNCTION_EASE_IN_OUT;
        }
        else if(!strcmp(value, "step-start")){
            current_widget->animation->animationTimingFunction.timing_function_type  = CSS_ANIMATION_TIMING_FUNCTION_STEP_START;
        }
        else if(!strcmp(value, "step-end")){
            current_widget->animation->animationTimingFunction.timing_function_type  = CSS_ANIMATION_TIMING_FUNCTION_STEP_END;
        }
        else if(!strcmp(value, "inherit")){
            current_widget->animation->animation_timing_function_inherit  = true;
        }
        else{//initial or wrong definition
            current_widget->animation->animationTimingFunction.timing_function_type  = CSS_ANIMATION_TIMING_FUNCTION_EASE;
        }
    }
}

void animation_name_property_set_value(struct css_properties *current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct css_animation));
    }
    size_t len = strlen(value);
    char* name = malloc(len+1);
    memcpy(name, value, len);
    name[len] = '\0';
    current_widget->animation->animation_name = name;
}



void animation_duration_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct css_animation));
    }
    if(!strcmp(value, "inherit")){
        current_widget->animation->animation_duration_inherit = true;
    }
    else{
        current_widget->animation->animation_duration = (int) strtol(value, NULL, 10);
    }
}

//TODO CONTROL INITIAL VALUE
void animation_delay_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct css_animation));
    }
    if(!strcmp(value, "inherit")){
        current_widget->animation->animation_delay_inherit = true;
    }
    else{
        current_widget->animation->animation_delay = (int) strtol(value, NULL, 10);
    }
}

void animation_iteration_count_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct css_animation));
    }
    if(!strcmp(value, "inherit")){
        current_widget->animation->animation_iteration_count_inherit = true;
    }
    else{
        current_widget->animation->animation_iteration_count = (int) strtol(value, NULL, 10);
    }
}

void animation_direction_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct css_animation));
    }
    if(!strcmp(value, "inherit")){
        current_widget->animation->animation_direction_inherit = true;
    }
    else if(!strcmp(value, "reverse")){
        current_widget->animation->animationDirection = CSS_ANIMATION_DIRECTION_REVERSE;
    }
    else if(!strcmp(value, "alternate")){
        current_widget->animation->animationDirection = CSS_ANIMATION_DIRECTION_ALTERNATE;
    }
    else if(!strcmp(value, "alternate-reverse")){
        current_widget->animation->animationDirection = CSS_ANIMATION_DIRECTION_ALTERNATE_REVERSE;
    }
    else{
        current_widget->animation->animationDirection = CSS_ANIMATION_DIRECTION_NORMAL;
    }
}

void animation_fill_mode_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct css_animation));
    }
    if(!strcmp(value, "inherit")){
        current_widget->animation->animation_fill_mode_inherit = true;
    }
    else if(!strcmp(value, "forwards")){
        current_widget->animation->animationFillMode = CSS_ANIMATION_FILL_MODE_FORWARDS;
    }
    else if(!strcmp(value, "backwards")){
        current_widget->animation->animationFillMode = CSS_ANIMATION_FILL_MODE_BACKWARDS;
    }
    else if(!strcmp(value, "both")){
        current_widget->animation->animationFillMode = CSS_ANIMATION_FILL_MODE_BOTH;
    }
    else{
        current_widget->animation->animationFillMode = CSS_ANIMATION_FILL_MODE_NONE;
    }
}

void animation_play_state_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct css_animation));
    }
    if(!strcmp(value, "inherit")){
        current_widget->animation->animation_play_state_inherit = true;
    }
    else if(!strcmp(value, "paused")){
        current_widget->animation->animationPlayState = CSS_ANIMATION_PLAY_STATE_PAUSED;
    }
    else{
        current_widget->animation->animationPlayState = CSS_ANIMATION_PLAY_STATE_RUNNING;
    }
}

void animation_property_set_value(struct css_properties *current_widget, char* value){
    if(current_widget->animation == NULL){
        current_widget->animation = malloc(sizeof(struct css_animation));
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
