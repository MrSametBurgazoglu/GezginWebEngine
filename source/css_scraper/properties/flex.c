//
// Created by samet on 23.04.2022.
//

#include <string.h>
#include <stdlib.h>
#include "../../functools/index_founder.h"


#include "flex.h"

#define FLEX_DIRECTION_STRING_COUNT 4

char* flex_direction_strings[FLEX_DIRECTION_STRING_COUNT] = {
        "column",
        "column-reverse",
        "row",
        "row-reverse",
};

css_flex_direction_type flexDirectionTypeList[FLEX_DIRECTION_STRING_COUNT] = {
        CSS_FLEX_DIRECTION_TYPE_COLUMN,
        CSS_FLEX_DIRECTION_TYPE_COLUMN_REVERSE,
        CSS_FLEX_DIRECTION_TYPE_ROW,
        CSS_FLEX_DIRECTION_TYPE_ROW_REVERSE,
};

void set_flex_basis(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "auto")){
        current_widget->flex->flex_basis_valueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
        current_widget->flex->flex_basis_value = current_widget->width;
    }
    else{
        char* end_ptr;
        int int_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            current_widget->flex->flex_basis_valueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            current_widget->flex->flex_basis_value = int_value;
        }
        else{
            current_widget->flex->flex_basis_valueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
            current_widget->flex->flex_basis_value = current_widget->width;
        }
    }
}

void set_flex_direction(struct css_properties* current_widget, char* value){
    int index = get_index_from_list_by_string(flex_direction_strings, value, FLEX_DIRECTION_STRING_COUNT);
    if (index != -1){
        current_widget->flexFlow->flexDirection = flexDirectionTypeList[index];
    }
    else{
        current_widget->flexFlow->flexDirection = CSS_FLEX_DIRECTION_TYPE_ROW;
    }
}

void set_flex_wrap(struct css_properties* current_widget, char* value){

}

void set_flex_flow(struct css_properties* current_widget, char* value){
    char* values[2];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 3){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    set_flex_direction(current_widget, values[0]);
    set_flex_wrap(current_widget, values[1]);
}

void set_flex_grow(struct css_properties* current_widget, char* value){
    int int_value = (int) strtol(value, NULL, 10);
    current_widget->flex->flex_grow_value = int_value;
}

void set_flex_shrink(struct css_properties* current_widget, char* value){
    int int_value = (int) strtol(value, NULL, 10);
    current_widget->flex->flex_shrink_value = int_value;
}

//all three value must be used in this order flex-grow flex-shrink flex-basis
void set_flex(struct css_properties* current_widget, char* value){
    char* values[3];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 4){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }

    switch (index) {//TODO FIX HERE
        case 3:
            set_flex_grow(current_widget, values[0]);
            set_flex_shrink(current_widget, values[1]);
            set_flex_grow(current_widget, values[2]);
            break;
        default:
            break;
    }
}

void flex_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->flex_inherit = true;
    }
    else{
        if (current_widget->flex == NULL){
            current_widget->flex = malloc(sizeof(struct flex));
        }
        if (!strcmp(value, "initial")){
            current_widget->flex->flex_grow_value = 0;
            current_widget->flex->flex_shrink_value = 0;
            current_widget->flex->flex_basis_valueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
        }
        else{
            set_flex(current_widget, value);
        }
    }
}

void flex_basis_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->flex_inherit){
            if (current_widget->flex == NULL){
                current_widget->flex = malloc(sizeof(struct flex));
            }
            current_widget->flex->flex_basis_inherit = true;
        }
    }
    else{
        if (current_widget->flex == NULL){
            current_widget->flex = malloc(sizeof(struct flex));
        }
        if (current_widget->flex_inherit){
            current_widget->flex->flex_shrink_inherit = true;
            current_widget->flex->flex_grow_inherit = true;
            current_widget->flex_inherit = false;
        }
        if (!strcmp(value, "initial")){
            current_widget->flex->flex_basis_valueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
        }
        else{
            set_flex_basis(current_widget, value);
        }
    }
}

void flex_direction_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->flex_flow_inherit){
            if (current_widget->flexFlow == NULL){
                current_widget->flexFlow = malloc(sizeof(struct flex));
            }
            current_widget->flexFlow->flex_direction_inherit = true;
        }
    }
    else{
        if (current_widget->flexFlow == NULL){
            current_widget->flexFlow = malloc(sizeof(struct flex));
        }
        if (current_widget->flex_flow_inherit){
            current_widget->flexFlow->flex_wrap_inherit = true;
            current_widget->flex_flow_inherit = false;
        }
        if (!strcmp(value, "initial")){
            current_widget->flexFlow->flexDirection = CSS_FLEX_DIRECTION_TYPE_ROW;
        }
        else{
            set_flex_direction(current_widget, value);
        }
    }
}

void flex_flow_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->flex_flow_inherit = true;
    }
    else{
        if (current_widget->flexFlow == NULL){
            current_widget->flexFlow = malloc(sizeof(struct flex_flow));
        }
        if (!strcmp(value, "initial")){
            current_widget->flexFlow->flexDirection = CSS_FLEX_DIRECTION_TYPE_ROW;
            current_widget->flexFlow->flexWrap = CSS_FLEX_WRAP_TYPE_NOWRAP;
        }
        else{
            set_flex_flow(current_widget, value);
        }
    }
}

void flex_grow_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->flex_inherit){
            if (current_widget->flex == NULL){
                current_widget->flex = malloc(sizeof(struct flex));
            }
            current_widget->flex->flex_grow_inherit = true;
        }
    }
    else{
        if (current_widget->flex == NULL){
            current_widget->flex = malloc(sizeof(struct flex));
        }
        if (current_widget->flex_inherit){
            current_widget->flex->flex_basis_inherit = true;
            current_widget->flex->flex_shrink_inherit = true;
            current_widget->flex_inherit = false;
        }
        if (!strcmp(value, "initial")){
            current_widget->flex->flex_grow_value = 0;
        }
        else{
            set_flex_grow(current_widget, value);
        }
    }
}

void flex_shrink_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->flex_inherit){
            if (current_widget->flex == NULL){
                current_widget->flex = malloc(sizeof(struct flex));
            }
            current_widget->flex->flex_shrink_inherit = true;
        }
    }
    else{
        if (current_widget->flex == NULL){
            current_widget->flex = malloc(sizeof(struct flex));
        }
        if (current_widget->flex_inherit){
            current_widget->flex->flex_basis_inherit = true;
            current_widget->flex->flex_grow_inherit = true;
            current_widget->flex_inherit = false;
        }
        if (!strcmp(value, "initial")){
            current_widget->flex->flex_shrink_value = 1;
        }
        else{
            set_flex_shrink(current_widget, value);
        }
    }
}

void flex_wrap_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->flex_flow_inherit){
            if (current_widget->flexFlow == NULL){
                current_widget->flexFlow = malloc(sizeof(struct flex));
            }
            current_widget->flexFlow->flex_wrap_inherit = true;
        }
    }
    else{
        if (current_widget->flexFlow == NULL){
            current_widget->flexFlow = malloc(sizeof(struct flex));
        }
        if (current_widget->flex_flow_inherit){
            current_widget->flexFlow->flex_direction_inherit = true;
            current_widget->flex_flow_inherit = false;
        }
        if (!strcmp(value, "initial")){
            current_widget->flexFlow->flexWrap = CSS_FLEX_WRAP_TYPE_NOWRAP;
        }
        else{
            set_flex_wrap(current_widget, value);
        }
    }
}

void free_flex(struct css_properties* current_widget){
    free(current_widget->flex);
    free(current_widget->flexFlow);
}