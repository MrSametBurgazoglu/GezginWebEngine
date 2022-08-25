//
// Created by samet on 01.08.2022.
//

#include "margin.h"

#include <string.h>
#include <stdlib.h>

void set_margin_top(struct margin* margin, char* value){
    if (!strcmp(value, "auto")){
        margin->marginTopValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        char *end_char;
        int int_value = (int) strtol(value, &end_char, 10);
        if (!strcmp(end_char, "px")){
            margin->marginTopValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            margin->margin_top = int_value;
        }
        else if(!strcmp(end_char, "%")){
            margin->marginTopValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
            margin->margin_top = int_value;
        }
    }
}

void set_margin_bottom(struct margin* margin, char* value){
    if (!strcmp(value, "auto")){
        margin->marginBottomValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        char *end_char;
        int int_value = (int) strtol(value, &end_char, 10);
        if (!strcmp(end_char, "px")){
            margin->marginBottomValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            margin->margin_bottom = int_value;
        }
        else if(!strcmp(end_char, "%")){
            margin->marginBottomValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
            margin->margin_bottom = int_value;
        }
    }
}

void set_margin_left(struct margin* margin, char* value){
    if (!strcmp(value, "auto")){
        margin->marginLeftValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        char *end_char;
        int int_value = (int) strtol(value, &end_char, 10);
        if (!strcmp(end_char, "px")){
            margin->marginLeftValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            margin->margin_left = int_value;
        }
        else if(!strcmp(end_char, "%")){
            margin->marginLeftValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
            margin->margin_left = int_value;
        }
    }
}

void set_margin_right(struct margin* margin, char* value){
    if (!strcmp(value, "auto")){
        margin->marginRightValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        char *end_char;
        int int_value = (int) strtol(value, &end_char, 10);
        if (!strcmp(end_char, "px")){
            margin->marginRightValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            margin->margin_right = int_value;
        }
        else if(!strcmp(end_char, "%")){
            margin->marginRightValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
            margin->margin_right = int_value;
        }
    }
}


void set_margin(struct margin* margin, char* value){
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
            set_margin_top(margin, values[0]);
            set_margin_right(margin, values[0]);
            set_margin_bottom(margin, values[0]);
            set_margin_left(margin, values[0]);
            break;
        case 2:
            set_margin_top(margin, values[0]);
            set_margin_right(margin, values[1]);
            set_margin_bottom(margin, values[0]);
            set_margin_left(margin, values[1]);
            break;
        case 3:
            set_margin_top(margin, values[0]);
            set_margin_right(margin, values[1]);
            set_margin_bottom(margin, values[2]);
            set_margin_left(margin, values[1]);
            break;
        case 4:
            set_margin_top(margin, values[0]);
            set_margin_right(margin, values[1]);
            set_margin_bottom(margin, values[2]);
            set_margin_left(margin, values[3]);
            break;
        default:
            break;
    }
}

void margin_top_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if(!current_widget->margin_inherit){
            if(current_widget->margin == NULL){
                current_widget->margin = malloc(sizeof(struct margin));
            }
            current_widget->margin->margin_top_inherit = true;
        }
    }
    else{
        if(current_widget->margin == NULL){
            current_widget->margin = malloc(sizeof(struct margin));
        }
        if(current_widget->margin_inherit){
            current_widget->margin->margin_bottom_inherit = true;
            current_widget->margin->margin_left_inherit = true;
            current_widget->margin->margin_right_inherit = true;
        }
        current_widget->margin->margin_top_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->margin->marginTopValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            current_widget->margin->margin_top = 0;
        }
        else{
            set_margin_top(current_widget->margin, value);
        }
    }
}

void margin_bottom_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if(!current_widget->margin_inherit){
            if(current_widget->margin == NULL){
                current_widget->margin = malloc(sizeof(struct margin));
            }
            current_widget->margin->margin_bottom_inherit = true;
        }
    }
    else{
        if(current_widget->margin == NULL){
            current_widget->margin = malloc(sizeof(struct margin));
        }
        if(current_widget->margin_inherit){
            current_widget->margin->margin_top_inherit = true;
            current_widget->margin->margin_left_inherit = true;
            current_widget->margin->margin_right_inherit = true;
        }
        current_widget->margin->margin_bottom_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->margin->marginBottomValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            current_widget->margin->margin_bottom = 0;
        }
        else{
            set_margin_bottom(current_widget->margin, value);
        }
    }
}

void margin_left_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if(!current_widget->margin_inherit){
            if(current_widget->margin == NULL){
                current_widget->margin = malloc(sizeof(struct margin));
            }
            current_widget->margin->margin_left_inherit = true;
        }
    }
    else{
        if(current_widget->margin == NULL){
            current_widget->margin = malloc(sizeof(struct margin));
        }
        if(current_widget->margin_inherit){
            current_widget->margin->margin_top_inherit = true;
            current_widget->margin->margin_bottom_inherit = true;
            current_widget->margin->margin_right_inherit = true;
        }
        current_widget->margin->margin_left_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->margin->marginLeftValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            current_widget->margin->margin_left = 0;
        }
        else{
            set_margin_left(current_widget->margin, value);
        }
    }
}

void margin_right_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if(!current_widget->margin_inherit){
            if(current_widget->margin == NULL){
                current_widget->margin = malloc(sizeof(struct margin));
            }
            current_widget->margin->margin_right_inherit = true;
        }
    }
    else{
        if(current_widget->margin == NULL){
            current_widget->margin = malloc(sizeof(struct margin));
        }
        if(current_widget->margin_inherit){
            current_widget->margin->margin_top_inherit = true;
            current_widget->margin->margin_bottom_inherit = true;
            current_widget->margin->margin_left_inherit = true;
        }
        current_widget->margin->margin_right_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->margin->marginRightValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            current_widget->margin->margin_right = 0;
        }
        else{
            set_margin_right(current_widget->margin, value);
        }
    }
}

void margin_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->margin_inherit = true;
    }
    else{
        current_widget->margin_inherit = false;
        if(current_widget->margin == NULL){
            current_widget->margin = malloc(sizeof(struct margin));
        }
        if (!strcmp(value, "initial")){//do nothing
            current_widget->margin->margin_top = 0;
            current_widget->margin->margin_bottom = 0;
            current_widget->margin->margin_left = 0;
            current_widget->margin->margin_right = 0;
            current_widget->margin->marginTopValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
            current_widget->margin->marginBottomValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
            current_widget->margin->marginLeftValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
            current_widget->margin->marginRightValueType = CSS_PROPERTY_VALUE_TYPE_PIXEL;
        }
        else{
            set_margin(current_widget->margin, value);
        }
    }
}

void compute_inherit_margin(struct css_properties* dest, struct css_properties* source){
    if (dest->margin_inherit){
        dest->margin = source->margin;
    }
    else if(dest->margin != NULL && source->margin != NULL){
        if (dest->margin->margin_bottom_inherit){
            dest->margin->margin_bottom = source->margin->margin_bottom;
            dest->margin->marginBottomValueType = source->margin->marginBottomValueType;
        }
        if (dest->margin->margin_top_inherit){
            dest->margin->margin_top = source->margin->margin_top;
            dest->margin->marginTopValueType = source->margin->marginTopValueType;
        }
        if (dest->margin->margin_left_inherit){
            dest->margin->margin_left = source->margin->margin_left;
            dest->margin->marginLeftValueType = source->margin->marginLeftValueType;
        }
        if (dest->margin->margin_right_inherit){
            dest->margin->margin_right = source->margin->margin_right;
            dest->margin->marginRightValueType = source->margin->marginRightValueType;
        }
    }
}

void free_margin(struct css_properties* current_widget){
    free(current_widget->margin);
}

void update_margin(struct css_properties* current_widget, struct css_properties* source){
    if(source->margin_inherit){
        current_widget->margin_inherit = true;
        current_widget->margin = NULL;
    }
    else if (source->margin != NULL){
        current_widget->margin = source->margin;
    }
}