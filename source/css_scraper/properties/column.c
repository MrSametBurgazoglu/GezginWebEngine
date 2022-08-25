//
// Created by samet on 23.04.2022.
//

#include "column.h"
#include "../../functools/index_founder.h"

#include <stdlib.h>
#include <string.h>

#define COLUMN_RULE_STYLE_STRING_COUNT 10
#define COLUMN_RULE_WIDTH_STRING_COUNT 3

char* column_rule_style_strings[COLUMN_RULE_STYLE_STRING_COUNT] = {
        "dashed",
        "dotted",
        "double",
        "groove",
        "hidden",
        "inset",
        "none",
        "outset",
        "ridge",
        "solid",
};

char* column_rule_width_strings[COLUMN_RULE_WIDTH_STRING_COUNT] = {
        "medium",
        "thick",
        "thin",
};

css_column_rule_style_type columnRuleStyleTypeList[COLUMN_RULE_STYLE_STRING_COUNT] = {
        CSS_COLUMN_RULE_STYLE_DASHED,
        CSS_COLUMN_RULE_STYLE_DOTTED,
        CSS_COLUMN_RULE_STYLE_DOUBLE,
        CSS_COLUMN_RULE_STYLE_GROOVE,
        CSS_COLUMN_RULE_STYLE_HIDDEN,
        CSS_COLUMN_RULE_STYLE_INSET,
        CSS_COLUMN_RULE_STYLE_NONE,
        CSS_COLUMN_RULE_STYLE_OUTSET,
        CSS_COLUMN_RULE_STYLE_RIDGE,
        CSS_COLUMN_RULE_STYLE_SOLID,
};

css_column_rule_width_type columnRuleWidthTypeList[COLUMN_RULE_WIDTH_STRING_COUNT] = {
        CSS_COLUMN_RULE_WIDTH_TYPE_MEDIUM,
        CSS_COLUMN_RULE_WIDTH_TYPE_THIN,
        CSS_COLUMN_RULE_WIDTH_TYPE_THICK,
};

void set_column_count(struct css_properties* current_widget, char* value){
    int first_value = (int) strtol(value, NULL, 10);
    current_widget->column_count = first_value;
}

void set_column_fill(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "auto")){
        current_widget->column_fill = CSS_COLUMN_FILL_TYPE_AUTO;
    }
    else{
        current_widget->column_fill = CSS_COLUMN_FILL_TYPE_BALANCE;
    }
}

void set_column_gap(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "normal")){
        current_widget->column_gap = 1;
    }
    else{
        int first_value = (int) strtol(value, NULL, 10);
        current_widget->column_gap = first_value;
    }
}

void set_column_rule_color(struct column_rule* columnRule, char* value){
    get_color(columnRule->columnRuleColor, value);
}

void set_column_rule_style(struct column_rule* columnRule, char* value){
    int index = get_index_from_list_by_string(column_rule_style_strings, value, COLUMN_RULE_STYLE_STRING_COUNT);
    if (index != -1){
        columnRule->columnRuleStyleType = columnRuleStyleTypeList[index];
    }
    else{
        columnRule->columnRuleStyleType = CSS_COLUMN_RULE_STYLE_NONE;
    }
}

void set_column_rule_width(struct column_rule* columnRule, char* value){
    int index = get_index_from_list_by_string(column_rule_width_strings, value, COLUMN_RULE_WIDTH_STRING_COUNT);
    if (index != -1){
        columnRule->columnRuleWidth->columnRuleWidthType = columnRuleWidthTypeList[index];
    }
    else{
        int first_value = (int) strtol(value, NULL, 10);
        columnRule->columnRuleWidth->value = first_value;
        columnRule->columnRuleWidth->columnRuleWidthType = CSS_COLUMN_RULE_WIDTH_TYPE_LENGTH;
    }
}

void set_column_rule(struct css_properties* current_widget, char* value){
    char* values[3];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 4){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1:
            set_column_rule_color(current_widget->columnRule, values[0]);
            break;
        case 2:
            set_column_rule_width(current_widget->columnRule, values[0]);
            set_column_rule_color(current_widget->columnRule, values[1]);
            break;
        case 3:
            set_column_rule_width(current_widget->columnRule, values[0]);
            set_column_rule_style(current_widget->columnRule, values[1]);
            set_column_rule_color(current_widget->columnRule, values[2]);
            break;
        default:
            break;
    }
}

void set_column_span(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "all")){
        current_widget->columnSpanType = CSS_COLUMN_SPAN_TYPE_ALL;
    }
    else{
        current_widget->columnSpanType = CSS_COLUMN_SPAN_TYPE_NONE;
    }
}

void set_column_width(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "auto")){
        current_widget->column_width = 1;
    }
    else{
        int first_value = (int) strtol(value, NULL, 10);
        current_widget->column_width = first_value;
    }
}

void set_columns(struct css_properties* current_widget, char* value){
    char* values[2];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 3){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1://it must be auto
            set_column_width(current_widget, "auto");
            set_column_count(current_widget, "auto");
            break;
        case 2:
            set_column_width(current_widget, values[0]);
            set_column_count(current_widget, values[1]);
            break;
        default:
            break;
    }
}


void column_count_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->column_count_inherit = true;
    }
    else{
        current_widget->column_count_inherit = false;
        if(!strcmp(value, "initial")){//not right but good enough for now
            current_widget->column_count = 0;
        }
        else{
            set_column_count(current_widget, value);
        }
    }
}

void column_fill_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->column_fill_inherit = true;
    }
    else{
        current_widget->column_fill_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->column_fill = CSS_COLUMN_FILL_TYPE_BALANCE;
        }
        else{
            set_column_fill(current_widget, value);
        }
    }
}

void column_gap_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->column_gap_inherit = true;
    }
    else{
        current_widget->column_gap_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->column_gap = 1;
        }
        else{
            set_column_gap(current_widget, value);
        }
    }
}

void column_rule_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->column_rule_inherit = true;
    }
    else{
        current_widget->column_rule_inherit = false;
        if (current_widget->columnRule == NULL){
            current_widget->columnRule = malloc(sizeof(struct column_rule));
        }
        if (current_widget->columnRule->columnRuleWidth == NULL){
            current_widget->columnRule->columnRuleWidth = malloc(sizeof(struct column_rule_width));
        }
        if (current_widget->columnRule->columnRuleColor == NULL){
            current_widget->columnRule->columnRuleColor = malloc(sizeof(struct color_rgba));
        }
        current_widget->columnRule->column_rule_color_inherit = false;
        current_widget->columnRule->column_rule_width_inherit = false;
        current_widget->columnRule->column_rule_style_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->columnRule->columnRuleWidth->columnRuleWidthType = CSS_COLUMN_RULE_WIDTH_TYPE_MEDIUM;
            current_widget->columnRule->columnRuleStyleType = CSS_COLUMN_RULE_STYLE_NONE;
            sync_color(current_widget->color, current_widget->columnRule->columnRuleColor);
        }
        else{
            set_column_rule(current_widget, value);
        }
    }
}

void column_rule_color_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->column_rule_inherit){
            if (current_widget->columnRule == NULL){
                current_widget->columnRule = malloc(sizeof(struct column_rule));
            }
            current_widget->columnRule->column_rule_color_inherit = true;
        }
    }
    else{
        if (current_widget->columnRule == NULL){
            current_widget->columnRule = malloc(sizeof(struct column_rule));
        }
        if (current_widget->column_rule_inherit){
            current_widget->columnRule->column_rule_width_inherit = true;
            current_widget->columnRule->column_rule_style_inherit = true;
        }
        current_widget->columnRule->column_rule_color_inherit = false;
        if (current_widget->columnRule->columnRuleColor == NULL){
            current_widget->columnRule->columnRuleColor = malloc(sizeof(struct color_rgba));
        }
        if(!strcmp(value, "initial")){
            sync_color(current_widget->color, current_widget->columnRule->columnRuleColor);
        }
        else{
            set_column_rule_color(current_widget->columnRule, value);
        }
    }
}

void column_rule_style_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->column_rule_inherit){
            if (current_widget->columnRule == NULL){
                current_widget->columnRule = malloc(sizeof(struct column_rule));
            }
            current_widget->columnRule->column_rule_style_inherit = true;
        }
    }
    else{
        if (current_widget->columnRule == NULL){
            current_widget->columnRule = malloc(sizeof(struct column_rule));
        }
        if (current_widget->column_rule_inherit){
            current_widget->columnRule->column_rule_width_inherit = true;
            current_widget->columnRule->column_rule_color_inherit = true;
        }
        current_widget->columnRule->column_rule_style_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->columnRule->columnRuleStyleType = CSS_COLUMN_RULE_STYLE_NONE;
        }
        else{
            set_column_rule_style(current_widget->columnRule, value);
        }
    }
}

void column_rule_width_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->column_rule_inherit){
            if (current_widget->columnRule == NULL){
                current_widget->columnRule = malloc(sizeof(struct column_rule));
            }
            current_widget->columnRule->column_rule_width_inherit = true;
        }
    }
    else{
        if (current_widget->columnRule == NULL){
            current_widget->columnRule = malloc(sizeof(struct column_rule));
        }
        if (current_widget->column_rule_inherit){
            current_widget->columnRule->column_rule_style_inherit = true;
            current_widget->columnRule->column_rule_color_inherit = true;
        }
        current_widget->columnRule->column_rule_width_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->columnRule->columnRuleWidth->columnRuleWidthType= CSS_COLUMN_RULE_WIDTH_TYPE_MEDIUM;
        }
        else{
            set_column_rule_width(current_widget->columnRule, value);
        }
    }
}

void column_span_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->column_span_inherit = true;
    }
    else{
        if(!strcmp(value, "initial")){
            current_widget->columnSpanType = CSS_COLUMN_SPAN_TYPE_NONE;
        }
        else{
            set_column_span(current_widget, value);
        }
    }
}

void column_width_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->column_width_inherit = true;
    }
    else{
        if(!strcmp(value, "initial")){
            current_widget->column_width = 1;
        }
        else{
            set_column_width(current_widget, value);
        }
    }
}

void columns_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->column_width_inherit = true;
        current_widget->column_count_inherit = true;
    }
    else{
        current_widget->column_width_inherit = false;
        current_widget->column_count_inherit = false;
        if(!strcmp(value, "initial")){
            set_column_width(current_widget,"auto");
            set_column_count(current_widget, "auto");
        }
        else{
            set_columns(current_widget, value);
        }
    }
}

void compute_inherit_column(struct css_properties* dest, struct css_properties* source){
    if (dest->column_count_inherit){
        dest->column_count = source->column_count;
    }
    if (dest->column_fill_inherit){
        dest->column_fill = source->column_fill;
    }
    if (dest->column_gap_inherit){
        dest->column_gap = source->column_gap;
    }
    if (dest->column_rule_inherit){
        dest->columnRule = source->columnRule;
    }
    else if (dest->columnRule != NULL && source->columnRule != NULL){
        if (dest->columnRule->column_rule_color_inherit){
            dest->columnRule->columnRuleColor = source->columnRule->columnRuleColor;
        }
        if (dest->columnRule->column_rule_style_inherit){
            dest->columnRule->columnRuleStyleType = source->columnRule->columnRuleStyleType;
        }
        if (dest->columnRule->column_rule_width_inherit){
            dest->columnRule->columnRuleWidth = source->columnRule->columnRuleWidth;
        }
    }
    if (dest->column_span_inherit){
        dest->columnSpanType = source->columnSpanType;
    }
    if (dest->column_width_inherit){
        dest->column_width = source->column_width;
    }
}

void free_column(struct css_properties* current_widget){
    free(current_widget->columnRule->columnRuleWidth);
    free(current_widget->columnRule->columnRuleColor);
    free(current_widget->columnRule);
}