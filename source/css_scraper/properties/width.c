//
// Created by samet on 29.07.2022.
//

#include <string.h>
#include <stdlib.h>

#include "width.h"

void set_width(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "auto")){
        current_widget->widthValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            current_widget->width = first_value;
            current_widget->widthValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
        }
        else if(!strcmp(end_ptr, "%")){
            current_widget->width = first_value;
            current_widget->widthValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
        }
        else{//DEFAULT VALUE
            current_widget->width = CSS_PROPERTY_VALUE_TYPE_AUTO;
        }
    }
}

void set_min_width(struct css_properties* current_widget, char* value){
    char* end_ptr;
    int first_value = (int) strtol(value, &end_ptr, 10);
    if (!strcmp(end_ptr, "px")){
        current_widget->min_width = first_value;
        current_widget->minWidthValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
    }
    else if(!strcmp(end_ptr, "%")){
        current_widget->min_width = first_value;
        current_widget->minWidthValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
    }
    else{//DEFAULT VALUE
        current_widget->min_width = 0;
    }
}

void set_max_width(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "none")){
        current_widget->maxWidthValueType = CSS_PROPERTY_VALUE_TYPE_NONE;
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            current_widget->max_width = first_value;
            current_widget->maxWidthValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
        }
        else if(!strcmp(end_ptr, "%")){
            current_widget->max_width = first_value;
            current_widget->maxWidthValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
        }
        else{//DEFAULT VALUE
            current_widget->maxWidthValueType = CSS_PROPERTY_VALUE_TYPE_NONE;
        }
    }
}

void width_property_set_value(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_widget->width_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->widthValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        set_width(current_widget, value);
    }
}

void min_width_property_set_value(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_widget->min_width_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->min_width = 0;
        current_widget->minWidthValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
    }
    else{
        set_min_width(current_widget, value);
    }
}

void max_width_property_set_value(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_widget->max_width_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->max_width = 0;
        current_widget->maxWidthValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
    }
    else{
        set_max_width(current_widget, value);
    }
}

void compute_inherit_width(struct css_properties* dest, struct css_properties* source){
    if (dest->width_inherit){
        dest->width = source->width;
        dest->widthValueType = source->widthValueType;
    }
    if (dest->min_width_inherit){
        dest->min_width = source->min_width;
        dest->minWidthValueType = source->minWidthValueType;
    }
    if (dest->max_width_inherit){
        dest->max_width = source->max_width;
        dest->maxWidthValueType = source->maxWidthValueType;
    }
}

void update_width(struct css_properties* current_widget, struct css_properties* source){
    if(source->width_inherit){
        current_widget->width_inherit = true;
    }
    else if (current_widget->widthValueType != CSS_PROPERTY_VALUE_TYPE_EMPTY){
        current_widget->width = source->width;
        current_widget->widthValueType = source->widthValueType;
    }
    if(source->max_width_inherit){
        current_widget->max_width_inherit = true;
    }
    else if (current_widget->maxWidthValueType != CSS_PROPERTY_VALUE_TYPE_EMPTY){
        current_widget->max_width = source->max_width;
        current_widget->maxWidthValueType = source->maxWidthValueType;
    }
    if(source->min_width_inherit){
        current_widget->min_width_inherit = true;
    }
    else if (current_widget->minWidthValueType != CSS_PROPERTY_VALUE_TYPE_EMPTY){
        current_widget->min_width = source->min_width;
        current_widget->minWidthValueType = source->minWidthValueType;
    }
}