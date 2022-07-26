//
// Created by samet on 30.05.2022.
//

#include <string.h>
#include <stdlib.h>
#include "css_filter.h"

void get_blur_filter(void* filter_struct, char* value){
    char* value_type;
    float number = strtof(value, &value_type);
    filter_struct = malloc(sizeof(struct css_filter_blur));
    struct css_filter_blur* backdrop_filter = (struct css_filter_blur*) filter_struct;
    backdrop_filter->value = number;
    if(!strcmp(value_type, "px")){
        backdrop_filter->valueType = CSS_PIXEL_VALUE;
    }
    else if(!strcmp(value_type, "rem")){
        backdrop_filter->valueType = CSS_REM_VALUE;
    }
    else{
        backdrop_filter->valueType = CSS_NUMBER_VALUE;
    }
}

void get_brightness_filter(void* filter_struct, char* value){
    char* value_type;
    float number = strtof(value, &value_type);
    filter_struct = malloc(sizeof(struct css_filter_brightness));
    struct css_filter_brightness* backdrop_filter = (struct css_filter_brightness*) filter_struct;
    backdrop_filter->value = number;
    if(!strcmp(value_type, "%")){
        backdrop_filter->valueType = CSS_PERCENT_VALUE;
    }
    else{
        backdrop_filter->valueType = CSS_NUMBER_VALUE;
    }
}

void get_contrast_filter(void* filter_struct, char* value){
    char* value_type;
    float number = strtof(value, &value_type);
    filter_struct = malloc(sizeof(struct css_filter_contrast));
    struct css_filter_contrast* backdrop_filter = (struct css_filter_contrast*) filter_struct;
    backdrop_filter->value = number;
    if(!strcmp(value_type, "%")){
        backdrop_filter->valueType = CSS_PERCENT_VALUE;
    }
    else{
        backdrop_filter->valueType = CSS_NUMBER_VALUE;
    }
}

void get_drop_shadow_filter(void* filter_struct, char* value){
    char* parameters[3];
    int parameter_count = 1;
    parameters[0] = strtok(value, ",");
    char* current_parameter;
    while ((current_parameter = strtok(NULL, ",")) != NULL){
        parameters[parameter_count++] = current_parameter;
    }
    if(parameter_count == 3){
        filter_struct = malloc(sizeof(struct css_filter_drop_shadow));
        struct css_filter_drop_shadow* backdrop_filter = (struct css_filter_drop_shadow*) filter_struct;
        for (int index = 0; index < 3; ++index) {
            char* value_type;
            float number = strtof(parameters[index], &value_type);
            backdrop_filter->value_list[index] = number;
            if(!strcmp(value_type, "%")){
                backdrop_filter->valueType = CSS_PERCENT_VALUE;
            }
            else{
                backdrop_filter->valueType = CSS_NUMBER_VALUE;
            }
        }
    }
}

void get_gray_scale_filter(void* filter_struct, char* value){
    char* value_type;
    float number = strtof(value, &value_type);
    filter_struct = malloc(sizeof(struct css_filter_grayscale));
    struct css_filter_grayscale* backdrop_filter = (struct css_filter_grayscale*) filter_struct;
    backdrop_filter->value = number;
    if(!strcmp(value_type, "%")){
        backdrop_filter->valueType = CSS_PERCENT_VALUE;
    }
    else{
        backdrop_filter->valueType = CSS_NUMBER_VALUE;
    }
}

void get_hue_rotate_filter(void* filter_struct, char* value){
    char* value_type;
    float number = strtof(value, &value_type);
    filter_struct = malloc(sizeof(struct css_filter_hue_rotate));
    struct css_filter_hue_rotate* backdrop_filter = (struct css_filter_hue_rotate*) filter_struct;
    backdrop_filter->value = number;
    if(!strcmp(value_type, "deg")){
        backdrop_filter->valueType = CSS_DEG_VALUE;
    }
    else if(!strcmp(value_type, "turn")){
        backdrop_filter->valueType = CSS_TURN_VALUE;
    }
    else if(!strcmp(value_type, "rad")){
        backdrop_filter->valueType = CSS_RAD_VALUE;
    }
    else{
        backdrop_filter->valueType = CSS_NUMBER_VALUE;
    }
}

void get_invert_filter(void* filter_struct, char* value){
    char* value_type;
    float number = strtof(value, &value_type);
    filter_struct = malloc(sizeof(struct css_filter_invert));
    struct css_filter_invert* backdrop_filter = (struct css_filter_invert*) filter_struct;
    backdrop_filter->value = number;
    if(!strcmp(value_type, "%")){
        backdrop_filter->valueType = CSS_PERCENT_VALUE;
    }
    else{
        backdrop_filter->valueType = CSS_NUMBER_VALUE;
    }
}

void get_opacity_filter(void* filter_struct, char* value){
    char* value_type;
    float number = strtof(value, &value_type);
    filter_struct = malloc(sizeof(struct css_filter_opacity));
    struct css_filter_opacity* backdrop_filter = (struct css_filter_opacity*) filter_struct;
    backdrop_filter->value = number;
    if(!strcmp(value_type, "%")){
        backdrop_filter->valueType = CSS_PERCENT_VALUE;
    }
    else{
        backdrop_filter->valueType = CSS_NUMBER_VALUE;
    }
}

void get_saturate_filter(void* filter_struct, char* value){
    char* value_type;
    float number = strtof(value, &value_type);
    filter_struct = malloc(sizeof(struct css_filter_saturate));
    struct css_filter_saturate* backdrop_filter = (struct css_filter_saturate*) filter_struct;
    backdrop_filter->value = number;
    if(!strcmp(value_type, "%")){
        backdrop_filter->valueType = CSS_PERCENT_VALUE;
    }
    else{
        backdrop_filter->valueType = CSS_NUMBER_VALUE;
    }
}

void get_sepia_filter(void* filter_struct, char* value){
    char* value_type;
    float number = strtof(value, &value_type);
    filter_struct = malloc(sizeof(struct css_filter_sepia));
    struct css_filter_sepia* backdrop_filter = (struct css_filter_sepia*) filter_struct;
    backdrop_filter->value = number;
    if(!strcmp(value_type, "%")){
        backdrop_filter->valueType = CSS_PERCENT_VALUE;
    }
    else{
        backdrop_filter->valueType = CSS_NUMBER_VALUE;
    }
}

void set_filter_property(void* filter_struct, char* function_name, char* variables){
    if (!strcmp(function_name, "blur")){
        get_blur_filter(filter_struct, variables);
    }
    else if (!strcmp(function_name, "brightness")){
        get_brightness_filter(filter_struct, variables);
    }
    else if (!strcmp(function_name, "contrast")){
        get_contrast_filter(filter_struct, variables);
    }
    else if (!strcmp(function_name, "drop-shadow")){
        get_drop_shadow_filter(filter_struct, variables);
    }
    else if (!strcmp(function_name, "gray-scale")){
        get_gray_scale_filter(filter_struct, variables);
    }
    else if (!strcmp(function_name, "hue-rotate")){
        get_hue_rotate_filter(filter_struct, variables);
    }
    else if (!strcmp(function_name, "invert")){
        get_invert_filter(filter_struct, variables);
    }
    else if (!strcmp(function_name, "opacity")){
        get_opacity_filter(filter_struct, variables);
    }
    else if (!strcmp(function_name, "saturate")){
        get_saturate_filter(filter_struct, variables);
    }
    else if (!strcmp(function_name, "sepia")){
        get_sepia_filter(filter_struct, variables);
    }
}