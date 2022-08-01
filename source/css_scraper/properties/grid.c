//
// Created by samet on 31.07.2022.
//

#include "grid.h"
#include <stdlib.h>
#include <string.h>
#include "../../functools/index_founder.h"

#define GRID_AUTO_FLOW_STRING_COUNT 5

char* grid_auto_flow_strings[GRID_AUTO_FLOW_STRING_COUNT] = {
        "column",
        "column dense",
        "dense",
        "row",
        "row dense",
};

css_grid_auto_flow_type gridAutoFlowTypeList[GRID_AUTO_FLOW_STRING_COUNT] = {
        CSS_GRID_AUTO_FLOW_TYPE_COLUMN,
        CSS_GRID_AUTO_FLOW_TYPE_COLUMN_DENSE,
        CSS_GRID_AUTO_FLOW_TYPE_DENSE,
        CSS_GRID_AUTO_FLOW_TYPE_ROW,
        CSS_GRID_AUTO_FLOW_TYPE_ROW_DENSE,
};

void set_grid_auto_columns(struct grid_auto* gridAuto, char* value){
    if (!strcmp(value, "auto")){
        gridAuto->gridAutoColumnsValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else if(!strcmp(value, "max-content")){
        gridAuto->gridAutoColumnsValueType = CSS_PROPERTY_VALUE_TYPE_MAX_CONTENT;
    }
    else if(!strcmp(value, "min-content")){
        gridAuto->gridAutoColumnsValueType = CSS_PROPERTY_VALUE_TYPE_MIN_CONTENT;
    }
    else if(!strncmp(value, "minmax(", 7)){
        gridAuto->gridAutoColumnsValueType = CSS_PROPERTY_VALUE_TYPE_MINMAX;
        char* index = strchr(value, ')');
        size_t len = index - &value[7];
        char* parameters = malloc(len + 1);
        memcpy(parameters, &value[7], len);
        parameters[len] = '\0';
        char* parameter1 = strtok(parameters, ",");
        char* parameter2 = strtok(NULL, ",");
        if (parameter2 != NULL){
            int parameter1_int = (int) strtol(parameter1, NULL, 10);
            int parameter2_int = (int) strtol(parameter2, NULL, 10);
            gridAuto->gridAutoColumnsValueType = CSS_PROPERTY_VALUE_TYPE_MINMAX;
            gridAuto->grid_auto_columns = parameter1_int;
            gridAuto->grid_auto_columns_max = parameter2_int;
        }
    }
    else{
        char *end_char;
        int int_value = (int) strtol(value, &end_char, 10);
        if (!strcmp(end_char, "px")){
            gridAuto->gridAutoColumnsValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            gridAuto->grid_auto_columns = int_value;
        }
        else if(!strcmp(end_char, "%")){
            gridAuto->gridAutoColumnsValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
            gridAuto->grid_auto_columns = int_value;
        }
    }
}

void set_grid_auto_flow(struct grid_auto* gridAuto, char* value){
    int index = get_index_from_list_by_string(grid_auto_flow_strings, value, GRID_AUTO_FLOW_STRING_COUNT);
    if (index != -1){
        gridAuto->gridAutoFlowType = gridAutoFlowTypeList[index];
    }
    else{
        gridAuto->gridAutoFlowType = CSS_GRID_AUTO_FLOW_TYPE_ROW;
    }
}

void set_grid_auto_rows(struct grid_auto* gridAuto, char* value){
    if (!strcmp(value, "auto")){
        gridAuto->gridAutoRowsValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else if(!strcmp(value, "max-content")){
        gridAuto->gridAutoRowsValueType = CSS_PROPERTY_VALUE_TYPE_MAX_CONTENT;
    }
    else if(!strcmp(value, "min-content")){
        gridAuto->gridAutoRowsValueType = CSS_PROPERTY_VALUE_TYPE_MIN_CONTENT;
    }
    else{
        char *end_char;
        int int_value = (int) strtol(value, &end_char, 10);
        if (!strcmp(end_char, "px")){
            gridAuto->gridAutoColumnsValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
            gridAuto->grid_auto_columns = int_value;
        }
        else if(!strcmp(end_char, "%")){
            gridAuto->gridAutoColumnsValueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
            gridAuto->grid_auto_columns = int_value;
        }
    }
}

void set_grid_column_end(struct grid_column* gridColumn, char* value){
    if (!strcmp(value, "auto")){
        gridColumn->gridColumnEndValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    char* value1 = strtok(value, " ");
    char* value2 = strtok(NULL, " ");
    if (value2 == NULL){
        gridColumn->gridColumnEndValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
        int first_value = (int) strtol(value1, NULL, 10);
        gridColumn->grid_column_end = first_value;
    }
    else{
        if (!strcmp(value1, "span")){
            gridColumn->gridColumnEndValueType = CSS_PROPERTY_VALUE_TYPE_SPAN;
            int first_value = (int) strtol(value2, NULL, 10);
            gridColumn->grid_column_end = first_value;
        }
    }
}

void set_grid_column_gap(struct grid_gap* gridGap, char* value){
    int first_value = (int) strtol(value, NULL, 10);
    gridGap->grid_column_gap = first_value;
}

void set_grid_column_start(struct grid_column* gridColumn, char* value){
    if (!strcmp(value, "auto")){
        gridColumn->gridColumnStartValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        gridColumn->gridColumnStartValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
        int first_value = (int) strtol(value, NULL, 10);
        gridColumn->grid_column_start = first_value;
    }
}

void set_grid_column(struct grid_column* gridColumn, char* value){
    char* value1 = strtok(value, " ");
    char* value2 = strtok(NULL, " ");
    set_grid_column_start(gridColumn, value1);
    set_grid_column_end(gridColumn, value2);
}

void set_grid_row_end(struct grid_row* gridRow, char* value){
    if (!strcmp(value, "auto")){
        gridRow->gridRowEndValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    char* value1 = strtok(value, " ");
    char* value2 = strtok(NULL, " ");
    if (value2 == NULL){
        gridRow->gridRowEndValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
        int first_value = (int) strtol(value1, NULL, 10);
        gridRow->grid_row_end = first_value;
    }
    else{
        if (!strcmp(value1, "span")){
            gridRow->gridRowEndValueType = CSS_PROPERTY_VALUE_TYPE_SPAN;
            int first_value = (int) strtol(value2, NULL, 10);
            gridRow->grid_row_end = first_value;
        }
    }
}

void set_grid_row_gap(struct grid_gap* gridGap, char* value){
    int first_value = (int) strtol(value, NULL, 10);
    gridGap->grid_row_gap = first_value;
}

void set_grid_row_start(struct grid_row* gridRow, char* value){
    if (!strcmp(value, "auto")){
        gridRow->gridRowStartValueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
    }
    else{
        gridRow->gridRowStartValueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
        int first_value = (int) strtol(value, NULL, 10);
        gridRow->grid_row_start = first_value;
    }
}

void set_grid_row(struct grid_row* gridRow, char* value){
    char* value1 = strtok(value, " ");
    char* value2 = strtok(NULL, " ");
    set_grid_row_start(gridRow, value1);
    set_grid_row_end(gridRow, value2);
}

void set_grid_area(struct grid* grid, char* value){
    char* value1 = strtok(value, "/");
    char* value2 = strtok(NULL, "/");
    char* value3 = strtok(NULL, "/");
    char* value4 = strtok(NULL, "/");
    set_grid_row_start(grid->gridRow, value1);
    set_grid_column_start(grid->gridColumn, value2);
    set_grid_row_end(grid->gridRow, value3);
    set_grid_column_end(grid->gridColumn, value4);
}

void set_grid_gap(struct grid_gap* gridGap, char* value){
    char* value1 = strtok(value, " ");
    char* value2 = strtok(NULL, " ");
    set_grid_row_gap(gridGap, value1);
    set_grid_column_gap(gridGap, value2);
}

void set_grid_template_areas(struct grid_template* gridTemplate, char* value){
    size_t len = strlen(value);
    char* parameters = malloc(len + 1);
    memcpy(parameters, value, len);
    parameters[len] = '\0';
    gridTemplate->grid_template_areas = parameters;

}

void set_grid_template_columns(struct grid_template* gridTemplate, char* value){
    char** values = malloc(sizeof(char ));
    int index2 = 0;
    char* value2;
    values[index2] = strtok(value, " ");
    while ((value2 = strtok(NULL, ",")) != NULL){
        values[index2++] = value2;
    }
    gridTemplate->grid_template_columns_count = index2;
    gridTemplate->gridTemplateColumnsValue = malloc(sizeof(struct grid_template_item*) * index2);
    for (int i = 0; i < index2; ++i) {
        struct grid_template_item* item = malloc(sizeof(struct grid_template_item));
        if (!strcmp(values[i], "auto")){
            item->valueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
        }
        else{
            char *end_char;
            int int_value = (int) strtol(values[i], &end_char, 10);
            if (!strcmp(end_char, "px")){
                item->valueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
                item->value = int_value;
            }
            else if(!strcmp(end_char, "%")){
                item->valueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
                item->value = int_value;
            }
        }
        gridTemplate->gridTemplateColumnsValue[i] = item;
    }
}

void set_grid_template_rows(struct grid_template* gridTemplate, char* value){
    char** values = malloc(sizeof(char ));
    int index2 = 0;
    char* value2;
    values[index2] = strtok(value, " ");
    while ((value2 = strtok(NULL, ",")) != NULL){
        values[index2++] = value2;
    }
    gridTemplate->grid_template_rows_count = index2;
    gridTemplate->gridTemplateRowsValue = malloc(sizeof(struct grid_template_item*) * index2);
    for (int i = 0; i < index2; ++i) {
        struct grid_template_item* item = malloc(sizeof(struct grid_template_item));
        if (!strcmp(values[i], "auto")){
            item->valueType = CSS_PROPERTY_VALUE_TYPE_AUTO;
        }
        else{
            char *end_char;
            int int_value = (int) strtol(values[i], &end_char, 10);
            if (!strcmp(end_char, "px")){
                item->valueType = CSS_PROPERTY_VALUE_TYPE_LENGTH;
                item->value = int_value;
            }
            else if(!strcmp(end_char, "%")){
                item->valueType = CSS_PROPERTY_VALUE_TYPE_PERCENTAGE;
                item->value = int_value;
            }
            gridTemplate->gridTemplateRowsValue[i] = item;
        }

    }
}

void set_grid_template(struct grid_template* gridTemplate, char* value){
    char* value1 = strtok(value, "/");
    char* value2 = strtok(NULL, "/");
    set_grid_template_rows(gridTemplate, value1);
    set_grid_template_columns(gridTemplate, value2);
}

void set_grid(struct css_properties* current_widget, char* value){//TODO FIX THIS ITS SO COMPLICATE

}

void grid_property_set_value(struct css_properties* current_widget, char* value){//TODO IMPLEMENT THIS FUNCTION LATER

}

void grid_area_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_auto_columns_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_auto_flow_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_auto_rows_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_column_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_column_end_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_column_gap_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_column_start_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_gap_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_row_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_row_end_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_row_gap_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_row_start_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_template_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_template_areas_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_template_columns_property_set_value(struct css_properties* current_widget, char* value){

}

void grid_template_rows_property_set_value(struct css_properties* current_widget, char* value){

}