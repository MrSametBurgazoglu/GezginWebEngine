//
// Created by samet on 29.07.2022.
//

#include <string.h>
#include <stdlib.h>

#include "position.h"
#include "../../functools/index_founder.h"

#define POSITION_STRING_COUNT 5

char* position_strings[POSITION_STRING_COUNT] = {
        "absolute",
        "fixed",
        "relative",
        "static",
        "sticky",
};

css_position_type positionTypeList[POSITION_STRING_COUNT] = {
        CSS_POSITION_TYPE_ABSOLUTE,
        CSS_POSITION_TYPE_FIXED,
        CSS_POSITION_TYPE_RELATIVE,
        CSS_POSITION_TYPE_STATIC,
        CSS_POSITION_TYPE_STICKY,
};

void set_position(struct css_properties* current_widget, char* value){
    int index = get_index_from_list_by_string(position_strings, value, POSITION_STRING_COUNT);
    if (index != -1){
        current_widget->position = positionTypeList[index];
    }
    else{
        current_widget->position = CSS_POSITION_TYPE_STATIC;
    }
}

void set_top(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "auto")){
        current_widget->topValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            current_widget->top = first_value;
            current_widget->topValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
        }
        else if(!strcmp(end_ptr, "%")){
            current_widget->top = first_value;
            current_widget->topValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
        }
        else{//DEFAULT VALUE
            current_widget->topValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
        }
    }
}

void set_bottom(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "auto")){
        current_widget->bottomValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            current_widget->bottom = first_value;
            current_widget->bottomValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
        }
        else if(!strcmp(end_ptr, "%")){
            current_widget->bottom = first_value;
            current_widget->bottomValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
        }
        else{//DEFAULT VALUE
            current_widget->bottomValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
        }
    }
}

void set_left(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "auto")){
        current_widget->leftValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            current_widget->left = first_value;
            current_widget->leftValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
        }
        else if(!strcmp(end_ptr, "%")){
            current_widget->left = first_value;
            current_widget->leftValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
        }
        else{//DEFAULT VALUE
            current_widget->leftValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
        }
    }
}

void set_right(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "auto")){
        current_widget->rightValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            current_widget->right = first_value;
            current_widget->rightValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
        }
        else if(!strcmp(end_ptr, "%")){
            current_widget->right = first_value;
            current_widget->rightValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
        }
        else{//DEFAULT VALUE
            current_widget->rightValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
        }
    }
}

void position_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->position_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->position = CSS_POSITION_TYPE_STATIC;
    }
    else{
        set_position(current_widget, value);
    }
}

void top_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->top_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->topValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        set_top(current_widget, value);
    }
}

void bottom_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->bottom_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->bottomValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        set_bottom(current_widget, value);
    }
}

void left_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->left_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->leftValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        set_left(current_widget, value);
    }
}

void right_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->right_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->rightValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        set_right(current_widget, value);
    }
}

void compute_inherit_position(struct css_properties* dest, struct css_properties* source){
    if (dest->position_inherit){
        dest->position = source->position;
    }
    if (dest->left_inherit){
        dest->left = source->left;
    }
    if (dest->right_inherit){
        dest->right = source->right;
    }
    if (dest->top_inherit){
        dest->top = source->top;
    }
    if (dest->bottom_inherit){
        dest->bottom = source->bottom;
    }
}

void update_position(struct css_properties* current_widget, struct css_properties* source){
    if(source->position_inherit){
        current_widget->position_inherit = true;
    }
    else if (source->position != CSS_POSITION_TYPE_EMPTY){
        current_widget->position = source->position;
    }
    if (source->top_inherit){
        current_widget->top_inherit = true;
    }
    else if (source->topValueType != CSS_PROPERTY_VALUE_TYPE_EMPTY){
        current_widget->top = source->top;
        current_widget->topValueType = source->topValueType;
    }
    if (source->bottom_inherit){
        current_widget->bottom_inherit = true;
    }
    else if (source->bottomValueType != CSS_PROPERTY_VALUE_TYPE_EMPTY){
        current_widget->bottom = source->bottom;
        current_widget->bottomValueType = source->bottomValueType;
    }
    if (source->left_inherit){
        current_widget->left_inherit = true;
    }
    else if (source->leftValueType != CSS_PROPERTY_VALUE_TYPE_EMPTY){
        current_widget->left = source->left;
        current_widget->leftValueType = source->leftValueType;
    }
    if (source->right_inherit){
        current_widget->right_inherit = true;
    }
    else if (source->rightValueType != CSS_PROPERTY_VALUE_TYPE_EMPTY){
        current_widget->right = source->right;
        current_widget->rightValueType = source->rightValueType;
    }
}