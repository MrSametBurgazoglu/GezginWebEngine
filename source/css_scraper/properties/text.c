//
// Created by samet on 26.06.2022.
//

#include "text.h"
#include <stdlib.h>
#include <string.h>
#include "../../functools/index_founder.h"

#define TEXT_ALIGN_STRING_COUNT 4
#define TEXT_ALIGN_LAST_STRING_COUNT 6
#define TEXT_DECORATION_LINE_STRING_COUNT 4
#define TEXT_DECORATION_STYLE_STRING_COUNT 5
#define TEXT_JUSTIFY_STRING_COUNT 4
#define TEXT_OVERFLOW_STRING_COUNT 3
#define TEXT_TRANSFORM_STRING_COUNT 4

char* text_align_strings[TEXT_ALIGN_STRING_COUNT] = {
        "center",
        "justify",
        "left",
        "right",
};

char* text_align_last_strings[TEXT_ALIGN_LAST_STRING_COUNT] = {
        "center",
        "end",
        "justify",
        "left",
        "right",
        "start",
};

char* text_decoration_line_strings[TEXT_DECORATION_LINE_STRING_COUNT] = {
        "line-through",
        "none",
        "overline",
        "underline",
};

char* text_decoration_style_strings[TEXT_DECORATION_STYLE_STRING_COUNT] = {
        "dashed",
        "dotted",
        "double",
        "solid",
        "wavy",
};

char* text_justify_strings[TEXT_JUSTIFY_STRING_COUNT] = {
        "auto",
        "inter-character",
        "inter-word",
        "none",
};

char* text_overflow_strings[TEXT_OVERFLOW_STRING_COUNT] = {
        "clip",
        "ellipsis",
        "string",
};

char* text_transform_strings[TEXT_TRANSFORM_STRING_COUNT] = {
        "capitalize",
        "lowercase",
        "none",
        "uppercase"
};

css_text_align_type textAlignTypeList[TEXT_ALIGN_STRING_COUNT] = {
        CSS_TEXT_ALIGN_CENTER,
        CSS_TEXT_ALIGN_JUSTIFY,
        CSS_TEXT_ALIGN_LEFT,
        CSS_TEXT_ALIGN_RIGHT,
};

css_text_align_type textAlignLastTypeList[TEXT_ALIGN_LAST_STRING_COUNT] = {
        CSS_TEXT_ALIGN_CENTER,
        CSS_TEXT_ALIGN_END,
        CSS_TEXT_ALIGN_JUSTIFY,
        CSS_TEXT_ALIGN_LEFT,
        CSS_TEXT_ALIGN_RIGHT,
        CSS_TEXT_ALIGN_START,
};

css_text_decoration_line_type textDecorationLineTypeList[TEXT_DECORATION_LINE_STRING_COUNT] = {
        CSS_TEXT_DECORATION_LINE_LINE_THROUGH,
        CSS_TEXT_DECORATION_LINE_NONE,
        CSS_TEXT_DECORATION_LINE_OVERLINE,
        CSS_TEXT_DECORATION_LINE_UNDERLINE,
};

css_text_decoration_style textDecorationStyleList[TEXT_DECORATION_STYLE_STRING_COUNT] = {
        CSS_TEXT_DECORATION_STYLE_DASHED,
        CSS_TEXT_DECORATION_STYLE_DOTTED,
        CSS_TEXT_DECORATION_STYLE_DOUBLE,
        CSS_TEXT_DECORATION_STYLE_SOLID,
        CSS_TEXT_DECORATION_STYLE_WAVY,
};

css_text_justify_type textJustifyTypeList[TEXT_JUSTIFY_STRING_COUNT] = {
        CSS_TEXT_JUSTIFY_AUTO,
        CSS_TEXT_JUSTIFY_INTER_CHARACTER,
        CSS_TEXT_JUSTIFY_INTER_WORD,
        CSS_TEXT_JUSTIFY_NONE,
};

css_text_overflow_type textOverflowTypeList[TEXT_OVERFLOW_STRING_COUNT] = {
        CSS_TEXT_OVERFLOW_CLIP,
        CSS_TEXT_OVERFLOW_ELLIPSIS,
        CSS_TEXT_OVERFLOW_STRING,
};

css_text_transform_type textTransformTypeList[TEXT_TRANSFORM_STRING_COUNT] = {
        CSS_TEXT_TRANSFORM_CAPITALIZE,
        CSS_TEXT_TRANSFORM_LOWERCASE,
        CSS_TEXT_TRANSFORM_NONE,
        CSS_TEXT_TRANSFORM_UPPERCASE,
};

void set_text_align(struct css_properties* current_widget, char* value){
    int index = get_index_from_list_by_string(text_align_strings, value, TEXT_ALIGN_STRING_COUNT);
    if (index != -1){
        current_widget->textAlign = textAlignTypeList[index];
    }
    else{
        current_widget->textAlign = CSS_TEXT_ALIGN_LEFT;
    }
}

void set_text_align_last(struct css_properties* current_widget, char* value){
    int index = get_index_from_list_by_string(text_align_last_strings, value, TEXT_ALIGN_LAST_STRING_COUNT);
    if (index != -1){
        current_widget->textAlignLast = textAlignLastTypeList[index];
    }
    else{
        current_widget->textAlignLast = CSS_TEXT_ALIGN_LEFT;
    }
}

void set_text_decoration_color(struct text_decoration* current_text_decoration, char* value){
    if (current_text_decoration->textDecorationColor == NULL){
        current_text_decoration->textDecorationColor = malloc(sizeof(struct color_rgba));
    }
    get_color(current_text_decoration->textDecorationColor, value);
}

void set_text_decoration_line(struct text_decoration* current_text_decoration, char* value){
    int index = get_index_from_list_by_string(text_decoration_line_strings, value, TEXT_DECORATION_LINE_STRING_COUNT);
    if (index != -1){
        current_text_decoration->textDecorationLine = textDecorationLineTypeList[index];
    }
    else{
        current_text_decoration->textDecorationLine = CSS_TEXT_DECORATION_LINE_NONE;
    }
}

void set_text_decoration_style(struct text_decoration* current_text_decoration, char* value){
    int index = get_index_from_list_by_string(text_decoration_style_strings, value, TEXT_DECORATION_STYLE_STRING_COUNT);
    if (index != -1){
        current_text_decoration->textDecorationStyle = textDecorationStyleList[index];
    }
    else{
        current_text_decoration->textDecorationStyle = CSS_TEXT_DECORATION_STYLE_SOLID;
    }
}

//THIS FUNCTION MUST BE CHECK
void set_text_decoration_thickness(struct text_decoration* current_text_decoration, char* value){
    if (!strcmp(value, "auto")){
        //NOT SUPPORTED YET
    }
    else if (!strcmp(value, "from-font")){
        //NOT SUPPORTED YET
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            current_text_decoration->textDecorationThickness->value = first_value;
            current_text_decoration->textDecorationThickness->textThicknessType = CSS_TEXT_DECORATION_THICKNESS_FROM_LENGTH;
        }
        else if(!strcmp(end_ptr, "%")){
            current_text_decoration->textDecorationThickness->value = first_value;
            current_text_decoration->textDecorationThickness->textThicknessType = CSS_TEXT_DECORATION_THICKNESS_FROM_PERCENTAGE;
        }
        else{//DEFAULT VALUE
            current_text_decoration->textDecorationThickness->textThicknessType = CSS_TEXT_DECORATION_THICKNESS_AUTO;
        }
    }
}

//this values must be in this order text-decoration-line text-decoration-color text-decoration-style text-decoration-thickness
void set_text_decoration(struct css_properties* current_widget, char* value){
    char* values[4];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 5){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    char* end_ptr;
    int int_value;
    switch (index) {
        case 1:
            set_text_decoration_line(current_widget->textDecoration, values[0]);
            break;
        case 2:
            set_text_decoration_line(current_widget->textDecoration, values[0]);
            set_text_decoration_color(current_widget->textDecoration, values[1]);
            break;
        case 3:
            set_text_decoration_line(current_widget->textDecoration, values[0]);
            set_text_decoration_color(current_widget->textDecoration, values[1]);
            set_text_decoration_style(current_widget->textDecoration, values[2]);
            break;
        case 4:
            set_text_decoration_line(current_widget->textDecoration, values[0]);
            set_text_decoration_color(current_widget->textDecoration, values[1]);
            set_text_decoration_style(current_widget->textDecoration, values[2]);
            set_text_decoration_thickness(current_widget->textDecoration, values[3]);
            break;
        default:
            break;
    }
}

void set_text_indent(struct css_properties* current_widget, char* value){
    char* end_ptr;
    int first_value = (int) strtol(value, &end_ptr, 10);
    if (!strcmp(end_ptr, "px")){
        current_widget->textIndent->value = first_value;
        current_widget->textIndent->valueType = CSS_PIXEL_VALUE;
    }
    else if(!strcmp(end_ptr, "%")){
        current_widget->textIndent->value = first_value;
        current_widget->textIndent->valueType = CSS_PERCENT_VALUE;
    }
    else{//DEFAULT VALUE
        current_widget->textIndent->value = 0;
        current_widget->textIndent->valueType = CSS_PIXEL_VALUE;
    }
}

void set_text_justify(struct css_properties* current_widget, char* value){
    int index = get_index_from_list_by_string(text_justify_strings, value, TEXT_JUSTIFY_STRING_COUNT);
    if (index != -1){
        current_widget->textJustify = textJustifyTypeList[index];
    }
    else{
        current_widget->textJustify = CSS_TEXT_JUSTIFY_AUTO;
    }
}

void set_text_overflow(struct css_properties* current_widget, char* value){
    int index = get_index_from_list_by_string(text_overflow_strings, value, TEXT_OVERFLOW_STRING_COUNT);
    if (index != -1){
        current_widget->textOverflow = textOverflowTypeList[index];
    }
    else{
        current_widget->textOverflow = CSS_TEXT_OVERFLOW_CLIP;
    }
}

void set_text_shadow(struct css_properties* current_widget, char* value){
    char* values[4];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 5){
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


void set_text_transform(struct css_properties* current_widget, char* value){
    int index = get_index_from_list_by_string(text_transform_strings, value, TEXT_TRANSFORM_STRING_COUNT);
    if (index != -1){
        current_widget->textTransformType = textTransformTypeList[index];
    }
    else{
        current_widget->textTransformType = CSS_TEXT_TRANSFORM_NONE;
    }
}

void text_align_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->text_align_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        if(current_widget->direction == CSS_DIRECTION_TYPE_LTR){
            current_widget->textAlign = CSS_TEXT_ALIGN_LEFT;
        }
        else{
            current_widget->textAlign = CSS_TEXT_ALIGN_RIGHT;
        }
    }
    else{
        set_text_align(current_widget, value);
    }
}

void text_align_last_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->text_align_last_inherit = true;
    }
    else if(!strcmp(value, "initial") || !strcmp(value, "auto")){
        current_widget->textAlignLast = CSS_TEXT_ALIGN_LEFT;
    }
    else{
        set_text_align_last(current_widget, value);
    }
}

void text_decoration_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->text_decoration_inherit = true;
    }
    else{
        if (current_widget->textDecoration == NULL){
            current_widget->textDecoration = malloc(sizeof(struct text_decoration));
        }
        if (current_widget->textDecoration->textDecorationThickness == NULL){
            current_widget->textDecoration->textDecorationThickness = malloc(sizeof(struct text_decoration_thickness));
        }
        if (current_widget->textDecoration->textDecorationColor == NULL){
            current_widget->textDecoration->textDecorationColor = malloc(sizeof(struct color_rgba));
        }
        if(!strcmp(value, "initial")){
            current_widget->textDecoration->textDecorationLine = CSS_TEXT_DECORATION_LINE_NONE;
            sync_color(current_widget->color ,current_widget->textDecoration->textDecorationColor);
            current_widget->textDecoration->textDecorationStyle = CSS_TEXT_DECORATION_STYLE_SOLID;
            current_widget->textDecoration->textDecorationThickness->textThicknessType = CSS_TEXT_DECORATION_THICKNESS_AUTO;
        }
        else{
            set_text_decoration(current_widget, value);
        }
    }
}

void text_decoration_color_property_set_value(struct css_properties* current_widget, char* value){
    if (current_widget->textDecoration == NULL){
        current_widget->textDecoration = malloc(sizeof(struct text_decoration));
    }
    if (!strcmp(value, "inherit")){
        current_widget->textDecoration->text_decoration_color_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        sync_color(current_widget->color, current_widget->textDecoration->textDecorationColor);
    }
    else{
        get_color(current_widget->textDecoration->textDecorationColor, value);
    }
}

void text_decoration_line_property_set_value(struct css_properties* current_widget, char* value){
    if (current_widget->textDecoration == NULL){
        current_widget->textDecoration = malloc(sizeof(struct text_decoration));
    }
    if (!strcmp(value, "inherit")){
        current_widget->textDecoration->text_decoration_line_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->textDecoration->textDecorationLine = CSS_TEXT_DECORATION_LINE_NONE;
    }
    else{
        set_text_decoration_line(current_widget->textDecoration, value);
    }
}

void text_decoration_style_property_set_value(struct css_properties* current_widget, char* value){
    if (current_widget->textDecoration == NULL){
        current_widget->textDecoration = malloc(sizeof(struct text_decoration));
    }
    if (!strcmp(value, "inherit")){
        current_widget->textDecoration->text_decoration_style_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->textDecoration->textDecorationStyle = CSS_TEXT_DECORATION_STYLE_SOLID;
    }
    else{
        set_text_decoration_style(current_widget->textDecoration, value);
    }
}

void text_decoration_thickness_property_set_value(struct css_properties* current_widget, char* value){
    if (current_widget->textDecoration == NULL){
        current_widget->textDecoration = malloc(sizeof(struct text_decoration));
    }
    if (!strcmp(value, "inherit")){
        current_widget->textDecoration->text_decoration_thickness_inherit = true;
    }
    else{
        if (current_widget->textDecoration->textDecorationThickness == NULL){
            current_widget->textDecoration->textDecorationThickness = malloc(sizeof(struct text_decoration_thickness));
        }
        if(!strcmp(value, "initial")){
            current_widget->textDecoration->textDecorationThickness->textThicknessType = CSS_TEXT_DECORATION_THICKNESS_AUTO;
        }
        else{
            set_text_decoration_thickness(current_widget->textDecoration, value);
        }
    }
}

void text_indent_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->text_indent_inherit = true;
    }
    else{
        if (current_widget->textIndent == NULL){
            current_widget->textIndent = malloc(sizeof(struct text_indent));
        }
        if (!strcmp(value, "initial")){
            current_widget->textIndent->value = 0;
            current_widget->textIndent->valueType = CSS_PIXEL_VALUE;
        }
        else{
            set_text_indent(current_widget, value);
        }
    }
}

void text_justify_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->text_justify_inherit = true;
    }
    else if (!strcmp(value, "initial")){
        current_widget->textJustify = CSS_TEXT_JUSTIFY_AUTO;
    }
    else{
        set_text_justify(current_widget, value);
    }
}

void text_overflow_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->text_overflow_inherit = true;
    }
    else if (!strcmp(value, "initial")){
        current_widget->textOverflow = CSS_TEXT_OVERFLOW_CLIP;
    }
    else{
        set_text_overflow(current_widget, value);
    }
}

void text_shadow_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->text_shadow_inherit = true;
    }
    else{
        if (!strcmp(value, "initial")){
            //do nothing or create a value for none
        }
        else{
            if (current_widget->textShadow == NULL){
                current_widget->textShadow = malloc(sizeof(struct text_shadow));
            }
            set_text_shadow(current_widget, value);
        }
    }
}

void text_transform_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->text_transform_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->textTransformType = CSS_TEXT_TRANSFORM_NONE;
    }
    else{
        set_text_transform(current_widget, value);
    }
}