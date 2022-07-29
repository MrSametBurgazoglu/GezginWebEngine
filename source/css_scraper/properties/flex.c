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

void set_flex(struct css_properties* current_widget, char* value){
    char* values[3];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 4){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    char* end_ptr;
    int int_value;
    switch (index) {
        case 1:
            break;
        case 2:
            int_value = (int) strtol(values[0], &end_ptr, 10);
            current_widget->textShadow->h_shadow = int_value;
            int_value = (int) strtol(values[1], &end_ptr, 10);
            current_widget->textShadow->v_shadow = int_value;
            break;
        case 3:
            int_value = (int) strtol(values[0], &end_ptr, 10);
            current_widget->textShadow->h_shadow = int_value;
            int_value = (int) strtol(values[1], &end_ptr, 10);
            current_widget->textShadow->v_shadow = int_value;
            int_value = (int) strtol(values[2], &end_ptr, 10);
            current_widget->textShadow->blur_radius = int_value;
            break;
        case 4:
            int_value = (int) strtol(values[0], &end_ptr, 10);
            current_widget->textShadow->h_shadow = int_value;
            int_value = (int) strtol(values[1], &end_ptr, 10);
            current_widget->textShadow->v_shadow = int_value;
            int_value = (int) strtol(values[2], &end_ptr, 10);
            current_widget->textShadow->blur_radius = int_value;
            if(current_widget->textShadow->colorRgba == NULL){
                current_widget->textShadow->colorRgba = malloc(sizeof(struct color_rgba));
            }
            get_color(current_widget->textShadow->colorRgba, values[3]);
            break;
        default:
            break;
    }
}

void flex_property_set_value(struct css_properties* current_widget, char* value){
    
}

void flex_basis_property_set_value(struct css_properties* current_widget, char* value){
    
}

void flex_direction_property_set_value(struct css_properties* current_widget, char* value){
    
}

void flex_flow_property_set_value(struct css_properties* current_widget, char* value){
    
}

void flex_grow_property_set_value(struct css_properties* current_widget, char* value){
    
}

void flex_shrink_property_set_value(struct css_properties* current_widget, char* value){
    
}

void flex_wrap_property_set_value(struct css_properties* current_widget, char* value){
    
}