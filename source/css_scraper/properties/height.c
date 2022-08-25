//
// Created by samet on 29.07.2022.
//

#include <string.h>
#include <stdlib.h>

#include "height.h"

void set_height(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "auto")){
        current_widget->heightValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            current_widget->height = first_value;
            current_widget->heightValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
        }
        else if(!strcmp(end_ptr, "%")){
            current_widget->height = first_value;
            current_widget->heightValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
        }
        else{//DEFAULT VALUE
            current_widget->height = CSS_PROPERTY_VALUE_TYPE_AUTO;
        }
    }
}

void set_min_height(struct css_properties* current_widget, char* value){
    char* end_ptr;
    int first_value = (int) strtol(value, &end_ptr, 10);
    if (!strcmp(end_ptr, "px")){
        current_widget->min_height = first_value;
        current_widget->minHeightValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
    }
    else if(!strcmp(end_ptr, "%")){
        current_widget->min_height = first_value;
        current_widget->minHeightValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
    }
    else{//DEFAULT VALUE
        current_widget->min_height = 0;
    }
}

void set_max_height(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "none")){
        current_widget->maxHeightValueType = CSS_PROPERTY_VALUE_TYPE_NONE;
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            current_widget->max_height = first_value;
            current_widget->maxHeightValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
        }
        else if(!strcmp(end_ptr, "%")){
            current_widget->max_height = first_value;
            current_widget->maxHeightValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
        }
        else{//DEFAULT VALUE
            current_widget->maxHeightValueType = CSS_PROPERTY_VALUE_TYPE_NONE;
        }
    }
}

void height_property_set_value(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_widget->height_inherit = true;
    }
    else{
        current_widget->height_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->heightValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
        }
        else{
            set_height(current_widget, value);
        }
    }
}

void min_height_property_set_value(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_widget->min_height_inherit = true;
    }
    else{
        current_widget->min_height_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->min_height = 0;
            current_widget->minHeightValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
        }
        else{
            set_min_height(current_widget, value);
        }
    }
}

void max_height_property_set_value(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_widget->max_height_inherit = true;
    }
    else{
        current_widget->max_height_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->max_height = 0;
            current_widget->maxHeightValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
        }
        else{
            set_max_height(current_widget, value);
        }
    }
}

void compute_inherit_height(struct css_properties* dest, struct css_properties* source){
    if (dest->height_inherit){
        dest->height = source->height;
        dest->heightValueType = source->heightValueType;
    }
    if (dest->min_height_inherit){
        dest->min_height = source->min_height;
        dest->minHeightValueType = source->minHeightValueType;
    }
    if (dest->max_height_inherit){
        dest->max_height = source->max_height;
        dest->maxHeightValueType = source->maxHeightValueType;
    }
}