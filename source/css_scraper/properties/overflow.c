//
// Created by samet on 11.08.2022.
//

#include "overflow.h"
#include "../../functools/index_founder.h"

#include <string.h>
#include <stdlib.h>

#define OVERFLOW_WRAP_STRING_COUNT 3
#define OVERFLOW_STRING_COUNT 5


char* overflow_wrap_strings[OVERFLOW_WRAP_STRING_COUNT] = {
        "anywhere",
        "break-word",
        "normal",
};

char* overflow_strings[OVERFLOW_STRING_COUNT] = {
        "auto",
        "clip",
        "hidden",
        "scroll",
        "visible",
};

css_overflow_wrap_type overflowWrapTypeList[OVERFLOW_WRAP_STRING_COUNT] = {
        CSS_OVERFLOW_WRAP_ANYWHERE,
        CSS_OVERFLOW_WRAP_BREAK_WORD,
        CSS_OVERFLOW_WRAP_NORMAL,
};

css_overflow_type overflowTypeList[OVERFLOW_STRING_COUNT] = {
        CSS_OVERFLOW_AUTO,
        CSS_OVERFLOW_CLIP,
        CSS_OVERFLOW_HIDDEN,
        CSS_OVERFLOW_SCROLL,
        CSS_OVERFLOW_VISIBLE,
};

void set_overflow_wrap(struct overflow* overflow, char* value){
    int index = get_index_from_list_by_string(overflow_wrap_strings, value, OVERFLOW_WRAP_STRING_COUNT);
    if (index != -1){
        overflow->wrap = overflowWrapTypeList[index];
    }
    else{
        overflow->wrap = CSS_OVERFLOW_WRAP_NORMAL;
    }
}

void set_overflow_x(struct overflow* overflow, char* value){
    int index = get_index_from_list_by_string(overflow_strings, value, OVERFLOW_STRING_COUNT);
    if (index != -1){
        overflow->overflowX = overflowTypeList[index];
    }
    else{
        overflow->overflowX = CSS_OVERFLOW_VISIBLE;
    }
}

void set_overflow_y(struct overflow* overflow, char* value){
    int index = get_index_from_list_by_string(overflow_strings, value, OVERFLOW_STRING_COUNT);
    if (index != -1){
        overflow->overflowY = overflowTypeList[index];
    }
    else{
        overflow->overflowY = CSS_OVERFLOW_VISIBLE;
    }
}

void set_overflow(struct overflow* overflow, char* value){
    int index = get_index_from_list_by_string(overflow_strings, value, OVERFLOW_STRING_COUNT);
    if (index != -1){
        overflow->overflowX = overflowTypeList[index];
        overflow->overflowY = overflowTypeList[index];
    }
    else{
        overflow->overflowX = CSS_OVERFLOW_VISIBLE;
        overflow->overflowY = CSS_OVERFLOW_VISIBLE;
    }
}

void overflow_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->overflow_inherit = true;
    }
    else{
        current_widget->overflow_inherit = false;
        if (current_widget->overflow == NULL){
            current_widget->overflow = malloc(sizeof(struct overflow));
        }
        if(!strcmp(value, "initial")){
            current_widget->overflow->overflowX = CSS_OVERFLOW_VISIBLE;
            current_widget->overflow->overflowY = CSS_OVERFLOW_VISIBLE;
        }
        else{
            set_overflow(current_widget->overflow, value);
        }
    }
}

void overflow_wrap_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->overflow_inherit){
            if (current_widget->overflow == NULL){
                current_widget->overflow = malloc(sizeof(struct overflow));
            }
            current_widget->overflow->overflow_wrap_inherit = true;
        }
    }
    else{
        if (current_widget->overflow == NULL){
            current_widget->overflow = malloc(sizeof(struct overflow));
        }
        if (current_widget->overflow_inherit){
            current_widget->overflow->overflow_x_inherit = true;
            current_widget->overflow->overflow_y_inherit = true;
            current_widget->overflow_inherit = false;
        }
        current_widget->overflow->overflow_wrap_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->overflow->wrap = CSS_OVERFLOW_WRAP_NORMAL;
        }
        else{
            set_overflow_wrap(current_widget->overflow, value);
        }
    }
}

void overflow_x_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->overflow_inherit){
            if (current_widget->overflow == NULL){
                current_widget->overflow = malloc(sizeof(struct overflow));
            }
            current_widget->overflow->overflow_x_inherit = true;
        }
    }
    else{
        if (current_widget->overflow == NULL){
            current_widget->overflow = malloc(sizeof(struct overflow));
        }
        if (current_widget->overflow_inherit){
            current_widget->overflow->overflow_wrap_inherit = true;
            current_widget->overflow->overflow_y_inherit = true;
            current_widget->overflow_inherit = false;
        }
        current_widget->overflow->overflow_x_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->overflow->overflowX = CSS_OVERFLOW_VISIBLE;
        }
        else{
            set_overflow_x(current_widget->overflow, value);
        }
    }
}

void overflow_y_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->overflow_inherit){
            if (current_widget->overflow == NULL){
                current_widget->overflow = malloc(sizeof(struct overflow));
            }
            current_widget->overflow->overflow_y_inherit = true;
        }
    }
    else{
        if (current_widget->overflow == NULL){
            current_widget->overflow = malloc(sizeof(struct overflow));
        }
        if (current_widget->overflow_inherit){
            current_widget->overflow->overflow_wrap_inherit = true;
            current_widget->overflow->overflow_x_inherit = true;
            current_widget->overflow_inherit = false;
        }
        current_widget->overflow->overflow_y_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->overflow->overflowY = CSS_OVERFLOW_VISIBLE;
        }
        else{
            set_overflow_y(current_widget->overflow, value);
        }
    }
}

void free_overflow(struct css_properties* current_widget){
    free(current_widget->overflow);
}