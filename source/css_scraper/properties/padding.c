//
// Created by samet on 11.08.2022.
//

#include "padding.h"

#include <string.h>
#include <stdlib.h>

void set_padding_top(struct padding* padding, char* value){
    if (!strcmp(value, "auto")){
        padding->paddingTopValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        char *end_char;
        int int_value = (int) strtol(value, &end_char, 10);
        if (!strcmp(end_char, "px")){
            padding->paddingTopValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            padding->padding_top = int_value;
        }
        else if(!strcmp(end_char, "%")){
            padding->paddingTopValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
            padding->padding_top = int_value;
        }
    }
}

void set_padding_bottom(struct padding* padding, char* value){
    if (!strcmp(value, "auto")){
        padding->paddingBottomValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        char *end_char;
        int int_value = (int) strtol(value, &end_char, 10);
        if (!strcmp(end_char, "px")){
            padding->paddingBottomValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            padding->padding_bottom = int_value;
        }
        else if(!strcmp(end_char, "%")){
            padding->paddingBottomValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
            padding->padding_bottom = int_value;
        }
    }
}

void set_padding_left(struct padding* padding, char* value){
    if (!strcmp(value, "auto")){
        padding->paddingLeftValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        char *end_char;
        int int_value = (int) strtol(value, &end_char, 10);
        if (!strcmp(end_char, "px")){
            padding->paddingLeftValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            padding->padding_left = int_value;
        }
        else if(!strcmp(end_char, "%")){
            padding->paddingLeftValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
            padding->padding_left = int_value;
        }
    }
}

void set_padding_right(struct padding* padding, char* value){
    if (!strcmp(value, "auto")){
        padding->paddingRightValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        char *end_char;
        int int_value = (int) strtol(value, &end_char, 10);
        if (!strcmp(end_char, "px")){
            padding->paddingRightValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            padding->padding_right = int_value;
        }
        else if(!strcmp(end_char, "%")){
            padding->paddingRightValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
            padding->padding_right = int_value;
        }
    }
}


void set_padding(struct padding* padding, char* value){
    char* values[4];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 5){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1:
            set_padding_top(padding, values[0]);
            set_padding_right(padding, values[0]);
            set_padding_bottom(padding, values[0]);
            set_padding_left(padding, values[0]);
            break;
        case 2:
            set_padding_top(padding, values[0]);
            set_padding_right(padding, values[1]);
            set_padding_bottom(padding, values[0]);
            set_padding_left(padding, values[1]);
            break;
        case 3:
            set_padding_top(padding, values[0]);
            set_padding_right(padding, values[1]);
            set_padding_bottom(padding, values[2]);
            set_padding_left(padding, values[1]);
            break;
        case 4:
            set_padding_top(padding, values[0]);
            set_padding_right(padding, values[1]);
            set_padding_bottom(padding, values[2]);
            set_padding_left(padding, values[3]);
            break;
        default:
            break;
    }
}

void padding_top_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if(!current_widget->padding_inherit){
            if(current_widget->padding == NULL){
                current_widget->padding = malloc(sizeof(struct padding));
            }
            current_widget->padding->padding_top_inherit = true;
        }
    }
    else{
        if(current_widget->padding == NULL){
            current_widget->padding = malloc(sizeof(struct padding));
        }
        if(current_widget->padding_inherit){
            current_widget->padding->padding_bottom_inherit = true;
            current_widget->padding->padding_left_inherit = true;
            current_widget->padding->padding_right_inherit = true;
        }
        current_widget->padding->padding_top_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->padding->paddingTopValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            current_widget->padding->padding_top = 0;
        }
        else{
            set_padding_top(current_widget->padding, value);
        }
    }
}

void padding_bottom_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if(!current_widget->padding_inherit){
            if(current_widget->padding == NULL){
                current_widget->padding = malloc(sizeof(struct padding));
            }
            current_widget->padding->padding_bottom_inherit = true;
        }
    }
    else{
        if(current_widget->padding == NULL){
            current_widget->padding = malloc(sizeof(struct padding));
        }
        if(current_widget->padding_inherit){
            current_widget->padding->padding_top_inherit = true;
            current_widget->padding->padding_left_inherit = true;
            current_widget->padding->padding_right_inherit = true;
        }
        current_widget->padding->padding_bottom_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->padding->paddingBottomValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            current_widget->padding->padding_bottom = 0;
        }
        else{
            set_padding_bottom(current_widget->padding, value);
        }
    }
}

void padding_left_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if(!current_widget->padding_inherit){
            if(current_widget->padding == NULL){
                current_widget->padding = malloc(sizeof(struct padding));
            }
            current_widget->padding->padding_left_inherit = true;
        }
    }
    else{
        if(current_widget->padding == NULL){
            current_widget->padding = malloc(sizeof(struct padding));
        }
        if(current_widget->padding_inherit){
            current_widget->padding->padding_top_inherit = true;
            current_widget->padding->padding_bottom_inherit = true;
            current_widget->padding->padding_right_inherit = true;
        }
        current_widget->padding->padding_left_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->padding->paddingLeftValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            current_widget->padding->padding_left = 0;
        }
        else{
            set_padding_left(current_widget->padding, value);
        }
    }
}

void padding_right_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if(!current_widget->padding_inherit){
            if(current_widget->padding == NULL){
                current_widget->padding = malloc(sizeof(struct padding));
            }
            current_widget->padding->padding_right_inherit = true;
        }
    }
    else{
        if(current_widget->padding == NULL){
            current_widget->padding = malloc(sizeof(struct padding));
        }
        if(current_widget->padding_inherit){
            current_widget->padding->padding_top_inherit = true;
            current_widget->padding->padding_bottom_inherit = true;
            current_widget->padding->padding_left_inherit = true;
        }
        current_widget->padding->padding_right_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->padding->paddingRightValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            current_widget->padding->padding_right = 0;
        }
        else{
            set_padding_right(current_widget->padding, value);
        }
    }
}

void padding_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->padding_inherit = true;
    }
    else{
        current_widget->padding_inherit = false;
        if(current_widget->padding == NULL){
            current_widget->padding = malloc(sizeof(struct padding));
        }
        if (!strcmp(value, "initial")){//maybe we can do nothing
            current_widget->padding->padding_top = 0;
            current_widget->padding->padding_bottom = 0;
            current_widget->padding->padding_left = 0;
            current_widget->padding->padding_right = 0;
            current_widget->padding->paddingTopValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
            current_widget->padding->paddingBottomValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
            current_widget->padding->paddingLeftValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
            current_widget->padding->paddingRightValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
        }
        else{
            set_padding(current_widget->padding, value);
        }
    }
}

void compute_inherit_padding(struct css_properties* dest, struct css_properties* source){
    if(dest->padding_inherit){
        dest->padding = source->padding;
    }
    else if(dest->padding != NULL && source->padding != NULL){
        if(dest->padding->padding_top_inherit){
            dest->padding->padding_top = source->padding->padding_top;
            dest->padding->paddingTopValueType = source->padding->paddingTopValueType;
        }
        if(dest->padding->padding_bottom_inherit){
            dest->padding->padding_bottom = source->padding->padding_bottom;
            dest->padding->paddingBottomValueType = source->padding->paddingBottomValueType;
        }
        if(dest->padding->padding_left_inherit){
            dest->padding->padding_left = source->padding->padding_left;
            dest->padding->paddingLeftValueType = source->padding->paddingLeftValueType;
        }
        if(dest->padding->padding_right_inherit){
            dest->padding->padding_right = source->padding->padding_right;
            dest->padding->paddingRightValueType = source->padding->paddingRightValueType;
        }
    }
}

void free_padding(struct css_properties* current_widget){
    free(current_widget->padding);
}