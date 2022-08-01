//
// Created by samet on 01.08.2022.
//

#include "outline.h"
#include "../../functools/index_founder.h"

#include <string.h>
#include <stdlib.h>

#define OUTLINE_WIDTH_STRING_COUNT 3
#define OUTLINE_STYLE_STRING_COUNT 10


char* outline_width_strings[OUTLINE_WIDTH_STRING_COUNT] = {
        "medium",
        "thick",
        "thin",
};

char* outline_style_strings[OUTLINE_STYLE_STRING_COUNT] = {
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

css_outline_width outlineWidthList[OUTLINE_WIDTH_STRING_COUNT] = {
        CSS_OUTLINE_WIDTH_TYPE_MEDIUM,
        CSS_OUTLINE_WIDTH_TYPE_THIN,
        CSS_OUTLINE_WIDTH_TYPE_THICK,
};

css_outline_style_type outlineStyleTypeList[OUTLINE_STYLE_STRING_COUNT] = {
        CSS_OUTLINE_STYLE_TYPE_DASHED,
        CSS_OUTLINE_STYLE_TYPE_DOTTED,
        CSS_OUTLINE_STYLE_TYPE_DOUBLE,
        CSS_OUTLINE_STYLE_TYPE_GROOVE,
        CSS_OUTLINE_STYLE_TYPE_HIDDEN,
        CSS_OUTLINE_STYLE_TYPE_INSET,
        CSS_OUTLINE_STYLE_TYPE_NONE,
        CSS_OUTLINE_STYLE_TYPE_OUTSET,
        CSS_OUTLINE_STYLE_TYPE_RIDGE,
        CSS_OUTLINE_STYLE_TYPE_SOLID,
};

void set_outline_color(struct outline* outline, char* value){
    get_color(outline->colorRgba, value);
}

void set_outline_offset(struct outline* outline, char* value){
    int int_value = (int) strtol(value, NULL, 10);
    outline->offset = int_value;
}

void set_outline_style(struct outline* outline, char* value){
    int index = get_index_from_list_by_string(outline_style_strings, value, OUTLINE_STYLE_STRING_COUNT);
    if (index != -1){
        outline->outlineStyleType = outlineStyleTypeList[index];
    }
    else{
        outline->outlineStyleType = CSS_OUTLINE_STYLE_TYPE_NONE;
    }
}

void set_outline_width(struct outline* outline, char* value){
    int index = get_index_from_list_by_string(outline_width_strings, value, OUTLINE_WIDTH_STRING_COUNT);
    if (index != -1){
        outline->outlineWidth = outlineWidthList[index];
    }
    else{
        int first_value = (int) strtol(value, NULL, 10);
        outline->outline_width = first_value;
        outline->outlineWidth = CSS_OUTLINE_WIDTH_TYPE_LENGTH;
    }
}

void set_outline(struct outline* outline, char* value){

}

void outline_property_set_value(struct css_properties* current_widget, char* value){

}

void outline_color_property_set_value(struct css_properties* current_widget, char* value){

}

void outline_offset_property_set_value(struct css_properties* current_widget, char* value){

}

void outline_style_property_set_value(struct css_properties* current_widget, char* value){

}

void outline_width_property_set_value(struct css_properties* current_widget, char* value){

}