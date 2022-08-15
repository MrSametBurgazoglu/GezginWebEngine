//
// Created by samet on 23.04.2022.
//

#include <stdlib.h>
#include <string.h>
#include "border.h"
#include "../../functools/index_founder.h"

#define BORDER_STYLE_STRING_COUNT 10
#define BORDER_WIDTH_STRING_COUNT 3
#define BORDER_IMAGE_REPEAT_STRING_COUNT 4

char* border_style_strings[BORDER_STYLE_STRING_COUNT] = {
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

char* border_width_strings[BORDER_WIDTH_STRING_COUNT] = {
        "medium",
        "thick",
        "thin",
};

char* border_image_repeat_strings[BORDER_IMAGE_REPEAT_STRING_COUNT] = {
        "repeat",
        "round",
        "space",
        "stretch",
};

css_border_style_type cssBorderStyleTypeList[BORDER_STYLE_STRING_COUNT] = {
        CSS_BORDER_STYLE_TYPE_DASHED,
        CSS_BORDER_STYLE_TYPE_DOTTED,
        CSS_BORDER_STYLE_TYPE_DOUBLE,
        CSS_BORDER_STYLE_TYPE_GROOVE,
        CSS_BORDER_STYLE_TYPE_HIDDEN,
        CSS_BORDER_STYLE_TYPE_INSET,
        CSS_BORDER_STYLE_TYPE_NONE,
        CSS_BORDER_STYLE_TYPE_OUTSET,
        CSS_BORDER_STYLE_TYPE_RIDGE,
        CSS_BORDER_STYLE_TYPE_SOLID,
};

css_border_line_type cssBorderWidthTypeList[BORDER_WIDTH_STRING_COUNT] = {
        CSS_BORDER_LINE_TYPE_MEDIUM,
        CSS_BORDER_LINE_TYPE_THICK,
        CSS_BORDER_LINE_TYPE_THIN,
};

css_border_image_repeat_type cssBorderImageRepeatList[BORDER_IMAGE_REPEAT_STRING_COUNT] = {
        CSS_BORDER_IMAGE_REPEAT_TYPE_REPEAT,
        CSS_BORDER_IMAGE_REPEAT_TYPE_ROUND,
        CSS_BORDER_IMAGE_REPEAT_TYPE_SPACE,
        CSS_BORDER_IMAGE_REPEAT_TYPE_STRETCH,
};

void set_border_top_style(struct css_border* border, char* value){
    int index = get_index_from_list_by_string(border_style_strings, value, BORDER_STYLE_STRING_COUNT);
    if (index != -1){
        border->borderStyle->borderStyleTypeTop = cssBorderStyleTypeList[index];
    }
    else{
        border->borderStyle->borderStyleTypeTop = CSS_BORDER_STYLE_TYPE_NONE;
    }
}

void set_border_left_style(struct css_border* border, char* value){
    int index = get_index_from_list_by_string(border_style_strings, value, BORDER_STYLE_STRING_COUNT);
    if (index != -1){
        border->borderStyle->borderStyleTypeLeft = cssBorderStyleTypeList[index];
    }
    else{
        border->borderStyle->borderStyleTypeLeft = CSS_BORDER_STYLE_TYPE_NONE;
    }
}

void set_border_right_style(struct css_border* border, char* value){
    int index = get_index_from_list_by_string(border_style_strings, value, BORDER_STYLE_STRING_COUNT);
    if (index != -1){
        border->borderStyle->borderStyleTypeRight = cssBorderStyleTypeList[index];
    }
    else{
        border->borderStyle->borderStyleTypeRight = CSS_BORDER_STYLE_TYPE_NONE;
    }
}

void set_border_bottom_style(struct css_border* border, char* value){
    int index = get_index_from_list_by_string(border_style_strings, value, BORDER_STYLE_STRING_COUNT);
    if (index != -1){
        border->borderStyle->borderStyleTypeBottom = cssBorderStyleTypeList[index];
    }
    else{
        border->borderStyle->borderStyleTypeBottom = CSS_BORDER_STYLE_TYPE_NONE;
    }
}

void set_border_style(struct css_border* border, char* value){
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
            set_border_bottom_style(border, values[0]);
            set_border_top_style(border, values[0]);
            set_border_left_style(border, values[0]);
            set_border_right_style(border, values[0]);
            break;
        case 2:
            set_border_bottom_style(border, values[0]);
            set_border_top_style(border, values[0]);
            set_border_left_style(border, values[1]);
            set_border_right_style(border, values[1]);
            break;
        case 3:
            set_border_bottom_style(border, values[2]);
            set_border_top_style(border, values[0]);
            set_border_left_style(border, values[1]);
            set_border_right_style(border, values[1]);
            break;
        case 4:
            set_border_bottom_style(border, values[2]);
            set_border_top_style(border, values[0]);
            set_border_left_style(border, values[3]);
            set_border_right_style(border, values[1]);
            break;
        default:
            break;
    }
}

void set_border_top_width(struct css_border* border, char* value){
    int index = get_index_from_list_by_string(border_width_strings, value, BORDER_WIDTH_STRING_COUNT);
    if (index != -1){
        border->borderWidth->top_border->borderLineType = cssBorderWidthTypeList[index];
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            border->borderWidth->top_border->borderLineType = CSS_BORDER_LINE_TYPE_LENGTH;
            border->borderWidth->top_border->value = first_value;
        }
        else{//DEFAULT VALUE
            border->borderWidth->top_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
        }
    }
}

void set_border_left_width(struct css_border* border, char* value){
    int index = get_index_from_list_by_string(border_width_strings, value, BORDER_WIDTH_STRING_COUNT);
    if (index != -1){
        border->borderWidth->left_border->borderLineType = cssBorderWidthTypeList[index];
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            border->borderWidth->left_border->borderLineType = CSS_BORDER_LINE_TYPE_LENGTH;
            border->borderWidth->left_border->value = first_value;
        }
        else{//DEFAULT VALUE
            border->borderWidth->left_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
        }
    }
}

void set_border_right_width(struct css_border* border, char* value){
    int index = get_index_from_list_by_string(border_width_strings, value, BORDER_WIDTH_STRING_COUNT);
    if (index != -1){
        border->borderWidth->right_border->borderLineType = cssBorderWidthTypeList[index];
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            border->borderWidth->right_border->borderLineType = CSS_BORDER_LINE_TYPE_LENGTH;
            border->borderWidth->right_border->value = first_value;
        }
        else{//DEFAULT VALUE
            border->borderWidth->right_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
        }
    }
}

void set_border_bottom_width(struct css_border* border, char* value){
    int index = get_index_from_list_by_string(border_width_strings, value, BORDER_WIDTH_STRING_COUNT);
    if (index != -1){
        border->borderWidth->bottom_border->borderLineType = cssBorderWidthTypeList[index];
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            border->borderWidth->bottom_border->borderLineType = CSS_BORDER_LINE_TYPE_LENGTH;
            border->borderWidth->bottom_border->value = first_value;
        }
        else{//DEFAULT VALUE
            border->borderWidth->bottom_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
        }
    }
}

void set_border_width(struct css_border* border, char* value){
    char* values[4];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 4){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1:
            set_border_bottom_width(border, values[0]);
            set_border_top_width(border, values[0]);
            set_border_left_width(border, values[0]);
            set_border_right_width(border, values[0]);
            break;
        case 2:
            set_border_bottom_width(border, values[0]);
            set_border_top_width(border, values[0]);
            set_border_left_width(border, values[1]);
            set_border_right_width(border, values[1]);
            break;
        case 3:
            set_border_bottom_width(border, values[2]);
            set_border_top_width(border, values[0]);
            set_border_left_width(border, values[1]);
            set_border_right_width(border, values[1]);
            break;
        case 4:
            set_border_bottom_width(border, values[2]);
            set_border_top_width(border, values[0]);
            set_border_left_width(border, values[3]);
            set_border_right_width(border, values[1]);
        default:
            break;
    }
}

//TODO IF A STRUCT HAVE A INHERIT VALUE AND THIS STRUCT'S VARIABLES ALSO HAVE INHERIT VALUES INSIDE STRUCT PROBABLY WE DON'T NEED STRUCT'S INHERIT VALUE

void set_border_top_color(struct css_border* border, char* value){
    get_color(border->borderColor->topBorderColor, value);
}

void set_border_left_color(struct css_border* border, char* value){
    get_color(border->borderColor->leftBorderColor, value);
}

void set_border_right_color(struct css_border* border, char* value){
    get_color(border->borderColor->rightBorderColor, value);
}

void set_border_bottom_color(struct css_border* border, char* value){
    get_color(border->borderColor->bottomBorderColor, value);
}

void set_border_color(struct css_border* border, char* value){
    char* values[4];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 4){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1:
            set_border_bottom_color(border, values[0]);
            set_border_top_color(border, values[0]);
            set_border_left_color(border, values[0]);
            set_border_right_color(border, values[0]);
            break;
        case 2:
            set_border_bottom_color(border, values[0]);
            set_border_top_color(border, values[0]);
            set_border_left_color(border, values[1]);
            set_border_right_color(border, values[1]);
            break;
        case 3:
            set_border_bottom_color(border, values[2]);
            set_border_top_color(border, values[0]);
            set_border_left_color(border, values[1]);
            set_border_right_color(border, values[1]);
            break;
        case 4:
            set_border_bottom_color(border, values[2]);
            set_border_top_color(border, values[0]);
            set_border_left_color(border, values[3]);
            set_border_right_color(border, values[1]);
        default:
            break;
    }
}

void set_border(struct css_border* border, char* value){
    char* values[3];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 3){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1:
            set_border_style(border, values[0]);
            break;
        case 2:
            set_border_width(border, values[0]);
            set_border_style(border, values[1]);
            break;
        case 3:
            set_border_width(border, values[0]);
            set_border_style(border, values[1]);
            set_border_color(border, values[2]);
            break;
        default:
            break;
    }
}

void set_border_bottom_left_radius(struct css_border* border, char* value){
    char* value_type;
    int number = (int) strtol(value, &value_type, 10);
    border->borderRadius->border_bottom_left_radius_value = number;
    if(!strcmp(value_type, "%")){
        border->borderRadius->border_bottom_left_radius_type = CSS_BORDER_RADIUS_TYPE_PERCENTAGE;
    }
    else{
        border->borderRadius->border_bottom_left_radius_type = CSS_BORDER_RADIUS_TYPE_LENGTH;
    }
}

void set_border_bottom_right_radius(struct css_border* border, char* value){
    char* value_type;
    int number = (int) strtol(value, &value_type, 10);
    border->borderRadius->border_bottom_right_radius_value = number;
    if(!strcmp(value_type, "%")){
        border->borderRadius->border_bottom_right_radius_type = CSS_BORDER_RADIUS_TYPE_PERCENTAGE;
    }
    else{
        border->borderRadius->border_bottom_right_radius_type = CSS_BORDER_RADIUS_TYPE_LENGTH;
    }
}

void set_border_top_left_radius(struct css_border* border, char* value){
    char* value_type;
    int number = (int) strtol(value, &value_type, 10);
    border->borderRadius->border_top_left_radius_type = number;
    if(!strcmp(value_type, "%")){
        border->borderRadius->border_top_left_radius_type = CSS_BORDER_RADIUS_TYPE_PERCENTAGE;
    }
    else{
        border->borderRadius->border_top_left_radius_type = CSS_BORDER_RADIUS_TYPE_LENGTH;
    }
}

void set_border_top_right_radius(struct css_border* border, char* value){
    char* value_type;
    int number = (int) strtol(value, &value_type, 10);
    border->borderRadius->border_top_right_radius_value = number;
    if(!strcmp(value_type, "%")){
        border->borderRadius->border_top_right_radius_type = CSS_BORDER_RADIUS_TYPE_PERCENTAGE;
    }
    else{
        border->borderRadius->border_top_right_radius_type = CSS_BORDER_RADIUS_TYPE_LENGTH;
    }
}

void set_border_radius(struct css_border* border, char* value){
    char* values[4];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 4){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1:
            set_border_bottom_left_radius(border, values[0]);
            set_border_bottom_right_radius(border, values[0]);
            set_border_top_left_radius(border, values[0]);
            set_border_top_right_radius(border, values[0]);
            break;
        case 2:
            set_border_bottom_left_radius(border, values[1]);
            set_border_bottom_right_radius(border, values[0]);
            set_border_top_left_radius(border, values[0]);
            set_border_top_right_radius(border, values[1]);
            break;
        case 3:
            set_border_bottom_left_radius(border, values[1]);
            set_border_bottom_right_radius(border, values[2]);
            set_border_top_left_radius(border, values[0]);
            set_border_top_right_radius(border, values[1]);
            break;
        case 4:
            set_border_bottom_left_radius(border, values[3]);
            set_border_bottom_right_radius(border, values[2]);
            set_border_top_left_radius(border, values[0]);
            set_border_top_right_radius(border, values[1]);
            break;
        default:
            break;
    }
}

void set_border_spacing(struct css_border* border, char* value){
    char* values[2];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 2){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    int value_h;
    int value_v;
    switch (index) {
        case 1:
            value_h = (int) strtol(values[0], NULL, 10);
            border->borderSpacing->h_spacing = value_h;
            border->borderSpacing->v_spacing = value_h;
            break;
        case 2:
            value_h = (int) strtol(values[0], NULL, 10);
            value_v = (int) strtol(values[1], NULL, 10);
            border->borderSpacing->h_spacing = value_h;
            border->borderSpacing->v_spacing = value_v;
            break;
        default:
            break;
    }
}

void set_border_bottom(struct css_border* border, char* value){
    char* values[3];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 3){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1:
            set_border_bottom_style(border, values[0]);
            break;
        case 2:
            set_border_bottom_style(border, values[1]);
            set_border_bottom_width(border, values[0]);
            break;
        case 3:
            set_border_bottom_style(border, values[1]);
            set_border_bottom_width(border, values[0]);
            set_border_bottom_color(border, values[2]);
            break;
        default:
            break;
    }
}

void set_border_top(struct css_border* border, char* value){
    char* values[3];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 3){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1:
            set_border_top_style(border, values[0]);
            break;
        case 2:
            set_border_top_style(border, values[1]);
            set_border_top_width(border, values[0]);
            break;
        case 3:
            set_border_top_style(border, values[1]);
            set_border_top_width(border, values[0]);
            set_border_top_color(border, values[2]);
            break;
        default:
            break;
    }
}

void set_border_left(struct css_border* border, char* value){
    char* values[3];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 3){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1:
            set_border_left_style(border, values[0]);
            break;
        case 2:
            set_border_left_style(border, values[1]);
            set_border_left_width(border, values[0]);
            break;
        case 3:
            set_border_left_style(border, values[1]);
            set_border_left_width(border, values[0]);
            set_border_left_color(border, values[2]);
            break;
        default:
            break;
    }
}

void set_border_right(struct css_border* border, char* value){
    char* values[3];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 3){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1:
            set_border_right_style(border, values[0]);
            break;
        case 2:
            set_border_right_style(border, values[1]);
            set_border_right_width(border, values[0]);
            break;
        case 3:
            set_border_right_style(border, values[1]);
            set_border_right_width(border, values[0]);
            set_border_right_color(border, values[2]);
            break;
        default:
            break;
    }
}

void set_border_image_outset(struct css_border* border, char* value){
    int values[4];
    char* value2;
    int index = 0;
    css_border_image_outset_type widthType[4];
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 5){
        char *end_char;
        values[index] = (int) strtol(value2, &end_char, 10);
        if (!strcmp(end_char, "px")){
            widthType[index] = CSS_BORDER_IMAGE_OUTSET_TYPE_LENGTH;
        }
        else{
            widthType[index] =  CSS_BORDER_IMAGE_OUTSET_TYPE_NUMBER;
        }
        index++;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1:
            border->borderImage->imageOutset->valueTop = values[0];
            border->borderImage->imageOutset->valueRight = values[0];
            border->borderImage->imageOutset->valueBottom = values[0];
            border->borderImage->imageOutset->valueLeft = values[0];
            border->borderImage->imageOutset->borderImageOutsetTypeTop = widthType[0];
            border->borderImage->imageOutset->borderImageOutsetTypeRight = widthType[0];
            border->borderImage->imageOutset->borderImageOutsetTypeBottom = widthType[0];
            border->borderImage->imageOutset->borderImageOutsetTypeLeft = widthType[0];
            break;
        case 2:
            border->borderImage->imageOutset->valueTop = values[0];
            border->borderImage->imageOutset->valueRight = values[1];
            border->borderImage->imageOutset->valueBottom = values[0];
            border->borderImage->imageOutset->valueLeft = values[1];
            border->borderImage->imageOutset->borderImageOutsetTypeTop = widthType[0];
            border->borderImage->imageOutset->borderImageOutsetTypeRight = widthType[1];
            border->borderImage->imageOutset->borderImageOutsetTypeBottom = widthType[0];
            border->borderImage->imageOutset->borderImageOutsetTypeLeft = widthType[1];
            break;
        case 3:
            border->borderImage->imageOutset->valueTop = values[0];
            border->borderImage->imageOutset->valueRight = values[1];
            border->borderImage->imageOutset->valueBottom = values[2];
            border->borderImage->imageOutset->valueLeft = values[1];
            border->borderImage->imageOutset->borderImageOutsetTypeTop = widthType[0];
            border->borderImage->imageOutset->borderImageOutsetTypeRight = widthType[1];
            border->borderImage->imageOutset->borderImageOutsetTypeBottom = widthType[2];
            border->borderImage->imageOutset->borderImageOutsetTypeLeft = widthType[1];
            break;
        case 4:
            border->borderImage->imageOutset->valueTop = values[0];
            border->borderImage->imageOutset->valueRight = values[1];
            border->borderImage->imageOutset->valueBottom = values[2];
            border->borderImage->imageOutset->valueLeft = values[3];
            border->borderImage->imageOutset->borderImageOutsetTypeTop = widthType[0];
            border->borderImage->imageOutset->borderImageOutsetTypeRight = widthType[1];
            border->borderImage->imageOutset->borderImageOutsetTypeBottom = widthType[2];
            border->borderImage->imageOutset->borderImageOutsetTypeLeft = widthType[3];
        default:
            break;
    }
}

void set_border_image_repeat(struct css_border* border, char* value){
    int index = get_index_from_list_by_string(border_image_repeat_strings, value, BORDER_IMAGE_REPEAT_STRING_COUNT);
    if (index != -1){
        border->borderImage->imageRepeatType = cssBorderImageRepeatList[index];
    }
    else{
        border->borderImage->imageRepeatType = CSS_BORDER_IMAGE_REPEAT_TYPE_STRETCH;
    }
}
//TODO CHECK THIS FUNCTION
void set_border_image_slice(struct css_border* border, char* value){
    int values[4];
    css_border_image_slice_type widthType[4];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 5){
        char *end_char;
        values[index] = (int) strtol(value2, &end_char, 10);
        if (!strcmp(end_char, "fill")){
            widthType[index] = CSS_BORDER_IMAGE_SLICE_TYPE_FILL;
        }
        else if (!strcmp(end_char, "%")){
            widthType[index] = CSS_BORDER_IMAGE_SLICE_TYPE_PERCENTAGE;
        }
        else{
            widthType[index] = CSS_BORDER_IMAGE_SLICE_TYPE_NUMBER;
        }
        index++;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1:
            border->borderImage->imageSlice->valueTop = values[0];
            border->borderImage->imageSlice->valueRight = values[0];
            border->borderImage->imageSlice->valueBottom = values[0];
            border->borderImage->imageSlice->valueLeft = values[0];
            border->borderImage->imageSlice->borderImageSliceTypeTop = widthType[0];
            border->borderImage->imageSlice->borderImageSliceTypeRight = widthType[0];
            border->borderImage->imageSlice->borderImageSliceTypeBottom = widthType[0];
            border->borderImage->imageSlice->borderImageSliceTypeLeft = widthType[0];
            break;
        case 2:
            border->borderImage->imageSlice->valueTop = values[0];
            border->borderImage->imageSlice->valueRight = values[1];
            border->borderImage->imageSlice->valueBottom = values[0];
            border->borderImage->imageSlice->valueLeft = values[1];
            border->borderImage->imageSlice->borderImageSliceTypeTop = widthType[0];
            border->borderImage->imageSlice->borderImageSliceTypeRight = widthType[1];
            border->borderImage->imageSlice->borderImageSliceTypeBottom = widthType[0];
            border->borderImage->imageSlice->borderImageSliceTypeLeft = widthType[1];
            break;
        case 3:
            border->borderImage->imageSlice->valueTop = values[0];
            border->borderImage->imageSlice->valueRight = values[1];
            border->borderImage->imageSlice->valueBottom = values[2];
            border->borderImage->imageSlice->valueLeft = values[1];
            border->borderImage->imageSlice->borderImageSliceTypeTop = widthType[0];
            border->borderImage->imageSlice->borderImageSliceTypeRight = widthType[1];
            border->borderImage->imageSlice->borderImageSliceTypeBottom = widthType[2];
            border->borderImage->imageSlice->borderImageSliceTypeLeft = widthType[1];
            break;
        case 4:
            border->borderImage->imageSlice->valueTop = values[0];
            border->borderImage->imageSlice->valueRight = values[1];
            border->borderImage->imageSlice->valueBottom = values[2];
            border->borderImage->imageSlice->valueLeft = values[3];
            border->borderImage->imageSlice->borderImageSliceTypeTop = widthType[0];
            border->borderImage->imageSlice->borderImageSliceTypeRight = widthType[1];
            border->borderImage->imageSlice->borderImageSliceTypeBottom = widthType[2];
            border->borderImage->imageSlice->borderImageSliceTypeLeft = widthType[3];
        default:
            break;
    }
}

void set_border_image_source(struct css_border* border, char* value){
    size_t length = strlen(value);
    char* text = malloc((length+1) * sizeof(char));
    memcpy(text, value, length);
    text[length] = '\0';
    border->borderImage->imageSource = text;
}

void set_border_image_width(struct css_border* border, char* value){
    int values[4];
    css_border_image_width_type widthType[4];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 5){
        char *end_char;
        values[index] = (int) strtol(value2, &end_char, 10);
        if (!strcmp(end_char, "auto")){
            widthType[index] = CSS_BORDER_IMAGE_WIDTH_TYPE_AUTO;
        }
        else if (!strcmp(end_char, "px")){
            widthType[index] = CSS_BORDER_IMAGE_WIDTH_TYPE_LENGTH;
        }
        else if (!strcmp(end_char, "%")){
            widthType[index] = CSS_BORDER_IMAGE_WIDTH_TYPE_PERCENTAGE;
        }
        else{
            widthType[index] = CSS_BORDER_IMAGE_WIDTH_TYPE_NUMBER;
        }
        index++;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1:
            border->borderImage->imageWidth->valueTop = values[0];
            border->borderImage->imageWidth->valueRight = values[0];
            border->borderImage->imageWidth->valueBottom = values[0];
            border->borderImage->imageWidth->valueLeft = values[0];
            border->borderImage->imageWidth->borderImageWidthTypeTop = widthType[0];
            border->borderImage->imageWidth->borderImageWidthTypeBottom = widthType[0];
            border->borderImage->imageWidth->borderImageWidthTypeLeft = widthType[0];
            border->borderImage->imageWidth->borderImageWidthTypeRight = widthType[0];
            break;
        case 2:
            border->borderImage->imageWidth->valueTop = values[0];
            border->borderImage->imageWidth->valueRight = values[1];
            border->borderImage->imageWidth->valueBottom = values[0];
            border->borderImage->imageWidth->valueLeft = values[1];
            border->borderImage->imageWidth->borderImageWidthTypeTop = widthType[0];
            border->borderImage->imageWidth->borderImageWidthTypeRight = widthType[1];
            border->borderImage->imageWidth->borderImageWidthTypeBottom = widthType[0];
            border->borderImage->imageWidth->borderImageWidthTypeLeft = widthType[1];
            break;
        case 3:
            border->borderImage->imageWidth->valueTop = values[0];
            border->borderImage->imageWidth->valueRight = values[1];
            border->borderImage->imageWidth->valueBottom = values[2];
            border->borderImage->imageWidth->valueLeft = values[1];
            border->borderImage->imageWidth->borderImageWidthTypeTop = widthType[0];
            border->borderImage->imageWidth->borderImageWidthTypeRight = widthType[1];
            border->borderImage->imageWidth->borderImageWidthTypeBottom = widthType[2];
            border->borderImage->imageWidth->borderImageWidthTypeLeft = widthType[1];
            break;
        case 4:
            border->borderImage->imageWidth->valueTop = values[0];
            border->borderImage->imageWidth->valueRight = values[1];
            border->borderImage->imageWidth->valueBottom = values[2];
            border->borderImage->imageWidth->valueLeft = values[3];
            border->borderImage->imageWidth->borderImageWidthTypeTop = widthType[0];
            border->borderImage->imageWidth->borderImageWidthTypeRight = widthType[1];
            border->borderImage->imageWidth->borderImageWidthTypeBottom = widthType[2];
            border->borderImage->imageWidth->borderImageWidthTypeLeft = widthType[3];
        default:
            break;
    }
}


//unless other web engines this property take maximum 3 variable
void set_border_image(struct css_border* border, char* value){
    char* values[3];
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL && index < 4){
        values[index++] = value2;
        value2 = strtok(NULL, " ");
    }
    switch (index) {
        case 1://if there is one value it is source
            set_border_image_source(border, values[0]);
            break;
        case 2://if there is two value it is source and repeat
            set_border_image_source(border, values[0]);
            set_border_image_repeat(border, values[1]);
            break;
        case 3://if there is three value it is source, slice and repeat
            set_border_image_source(border, values[1]);
            set_border_image_slice(border, values[0]);
            set_border_image_repeat(border, values[2]);
            break;
        default:
            break;
    }
}

void set_border_collapse(struct css_border* border, char* value){
    if (!strcmp(value, "collapse")){
        border->borderCollapseType = CSS_BORDER_COLLAPSE_TYPE_COLLAPSE;
    }
    else{
        border->borderCollapseType = CSS_BORDER_COLLAPSE_TYPE_SEPARATE;
    }
}

void border_property_set_value(struct css_properties* current_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_widget->border_inherit = true;
        //MAYBE WE CAN FREE ALLOCATED MEMORY IF ITS ALREADY ALLOCATED
    }
    else{
        current_widget->border_inherit = false;
        if (current_widget->border->borderStyle == NULL){
            current_widget->border->borderStyle = malloc(sizeof(struct border_style));
        }
        if (current_widget->border->borderWidth == NULL){
            current_widget->border->borderWidth = malloc(sizeof(struct border_width));
            current_widget->border->borderWidth->top_border = malloc(sizeof(struct border_line_width));
            current_widget->border->borderWidth->bottom_border = malloc(sizeof(struct border_line_width));
            current_widget->border->borderWidth->right_border = malloc(sizeof(struct border_line_width));
            current_widget->border->borderWidth->left_border = malloc(sizeof(struct border_line_width));
        }
        if (current_widget->border->borderColor == NULL){
            current_widget->border->borderColor = malloc(sizeof(struct border_color));
            current_widget->border->borderColor->topBorderColor = malloc(sizeof(struct color_rgba));
            current_widget->border->borderColor->bottomBorderColor = malloc(sizeof(struct color_rgba));
            current_widget->border->borderColor->leftBorderColor = malloc(sizeof(struct color_rgba));
            current_widget->border->borderColor->rightBorderColor = malloc(sizeof(struct color_rgba));
        }
        if (!strcmp(value, "initial")){
            current_widget->border->borderStyle->borderStyleTypeTop = CSS_BORDER_STYLE_TYPE_NONE;
            current_widget->border->borderStyle->borderStyleTypeBottom = CSS_BORDER_STYLE_TYPE_NONE;
            current_widget->border->borderStyle->borderStyleTypeLeft = CSS_BORDER_STYLE_TYPE_NONE;
            current_widget->border->borderStyle->borderStyleTypeRight = CSS_BORDER_STYLE_TYPE_NONE;
            current_widget->border->borderWidth->top_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
            current_widget->border->borderWidth->bottom_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
            current_widget->border->borderWidth->left_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
            current_widget->border->borderWidth->right_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
            sync_color(current_widget->color, current_widget->border->borderColor->topBorderColor);
            sync_color(current_widget->color, current_widget->border->borderColor->bottomBorderColor);
            sync_color(current_widget->color, current_widget->border->borderColor->leftBorderColor);
            sync_color(current_widget->color, current_widget->border->borderColor->rightBorderColor);
        }
        else{
            set_border(current_widget->border, value);
        }
    }
}

void border_bottom_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderStyle == NULL){
        current_widget->border->borderStyle = malloc(sizeof(struct border_style));
    }
    if (current_widget->border->borderWidth == NULL){
        current_widget->border->borderWidth = malloc(sizeof(struct border_width));
    }
    if (current_widget->border->borderColor == NULL){
        current_widget->border->borderColor = malloc(sizeof(struct border_color));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderStyle->border_style_bottom_inherit = true;
        current_widget->border->borderWidth->border_width_bottom_inherit = true;
        current_widget->border->borderColor->border_color_bottom_inherit = true;
    }
    else{
        current_widget->border->borderStyle->border_style_bottom_inherit = false;
        current_widget->border->borderWidth->border_width_bottom_inherit = true;
        current_widget->border->borderColor->border_color_bottom_inherit = true;
        if (current_widget->border->borderColor->bottomBorderColor == NULL){
            current_widget->border->borderColor->bottomBorderColor = malloc(sizeof(struct color_rgba));
        }
        if (current_widget->border->borderWidth->bottom_border == NULL){
            current_widget->border->borderWidth->bottom_border = malloc(sizeof(struct border_line_width));
        }
        if (!strcmp(value, "initial")){
            current_widget->border->borderStyle->borderStyleTypeBottom = CSS_BORDER_STYLE_TYPE_NONE;
            current_widget->border->borderWidth->bottom_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
            sync_color(current_widget->color, current_widget->border->borderColor->bottomBorderColor);
        }
        else{
            set_border_bottom(current_widget->border, value);
        }
    }
}

void border_bottom_color_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderColor == NULL){
        current_widget->border->borderColor = malloc(sizeof(struct border_color));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderColor->border_color_bottom_inherit = true;
    }
    else{
        current_widget->border->borderColor->border_color_bottom_inherit = false;
        if(current_widget->border->borderColor->bottomBorderColor == NULL){
            current_widget->border->borderColor->bottomBorderColor = malloc(sizeof(struct color_rgba));
        }
        if (!strcmp(value, "initial")){
            if (current_widget->color == NULL){
                get_color_by_rgb(current_widget->border->borderColor->bottomBorderColor, 0, 0, 0);
            }
            else{
                sync_color(current_widget->color, current_widget->border->borderColor->bottomBorderColor);
            }
        }
        else{
            set_border_bottom_color(current_widget->border, value);
        }
    }
}

void border_bottom_left_radius_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderRadius == NULL){
        current_widget->border->borderRadius = malloc(sizeof(struct border_radius));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderRadius->border_bottom_left_radius_inherit = true;
    }
    else{
        current_widget->border->borderRadius->border_bottom_left_radius_inherit = false;
        if (!strcmp(value, "initial")){//DID WE NEED THIS?
            current_widget->border->borderRadius->border_bottom_left_radius_type = CSS_BORDER_RADIUS_TYPE_LENGTH;
            current_widget->border->borderRadius->border_bottom_left_radius_value = 0;
        }
        else{
            set_border_bottom_left_radius(current_widget->border, value);
        }
    }
}

void border_bottom_right_radius_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderRadius == NULL){
        current_widget->border->borderRadius = malloc(sizeof(struct border_radius));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderRadius->border_bottom_right_radius_inherit = true;
    }
    else{
        current_widget->border->borderRadius->border_bottom_right_radius_inherit = false;
        if (!strcmp(value, "initial")){//DID WE NEED THIS?
            current_widget->border->borderRadius->border_bottom_right_radius_type = CSS_BORDER_RADIUS_TYPE_LENGTH;
            current_widget->border->borderRadius->border_bottom_right_radius_value = 0;
        }
        else{
            set_border_bottom_right_radius(current_widget->border, value);
        }
    }
}

void border_bottom_style_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderStyle == NULL){
        current_widget->border->borderStyle = malloc(sizeof(struct border_style));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderStyle->border_style_bottom_inherit = true;
    }
    else{
        current_widget->border->borderStyle->border_style_bottom_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->border->borderStyle->borderStyleTypeBottom = CSS_BORDER_STYLE_TYPE_NONE;
        }
        else{
            set_border_bottom_style(current_widget->border, value);
        }
    }
}

void border_bottom_width_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if(current_widget->border->borderWidth == NULL){
        current_widget->border->borderWidth = malloc(sizeof(struct border_width));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderWidth->border_width_top_inherit = true;
    }
    else{
        if(current_widget->border->borderWidth->top_border == NULL){
            current_widget->border->borderWidth->top_border = malloc(sizeof(struct border_line_width));
        }
        set_border_top_width(current_widget->border, value);
    }
}

void border_collapse_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->border_collapse_inherit = true;
    }
    else{
        current_widget->border->border_collapse_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->border->borderCollapseType = CSS_BORDER_COLLAPSE_TYPE_SEPARATE;
        }
        else{
            set_border_collapse(current_widget->border, value);
        }
    }
}

void border_color_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->border_color_inherit = true;
    }
    else{
        current_widget->border->border_color_inherit = false;
        if (current_widget->border->borderColor == NULL){
            current_widget->border->borderColor = malloc(sizeof(struct border_color));
        }
        if (!strcmp(value, "initial")){
            if (current_widget->color == NULL){
                get_color_by_rgb(current_widget->border->borderColor->bottomBorderColor, 0, 0, 0);
                get_color_by_rgb(current_widget->border->borderColor->topBorderColor, 0, 0, 0);
                get_color_by_rgb(current_widget->border->borderColor->rightBorderColor, 0, 0, 0);
                get_color_by_rgb(current_widget->border->borderColor->leftBorderColor, 0, 0, 0);
            }
            else{//maybe we need alpha to
                sync_color(current_widget->color, current_widget->border->borderColor->bottomBorderColor);
                sync_color(current_widget->color, current_widget->border->borderColor->topBorderColor);
                sync_color(current_widget->color, current_widget->border->borderColor->leftBorderColor);
                sync_color(current_widget->color, current_widget->border->borderColor->rightBorderColor);
            }
        }
        else{
            set_border_color(current_widget->border, value);
        }
    }
}

/*unless other web engines this property always take 3 as this order (source, slice, repeat)
 * */
void border_image_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if(!strcmp(value, "inherit")){
        current_widget->border->border_image_inherit = true;
    }
    else{
        current_widget->border->border_image_inherit = false;
        if (current_widget->border->borderImage == NULL){
            current_widget->border->borderImage = malloc(sizeof(struct border_image));
            current_widget->border->borderImage->imageOutset = malloc(sizeof(struct border_image_outset));
            current_widget->border->borderImage->imageWidth = malloc(sizeof(struct border_image_width));
            current_widget->border->borderImage->imageSlice = malloc(sizeof(struct border_image_slice));
        }
        if (!strcmp(value, "initial")){
            current_widget->border->borderImage->imageSlice->valueTop = 100;
            current_widget->border->borderImage->imageSlice->valueBottom = 100;
            current_widget->border->borderImage->imageSlice->valueLeft = 100;
            current_widget->border->borderImage->imageSlice->valueRight = 100;
            current_widget->border->borderImage->imageSlice->borderImageSliceTypeTop = CSS_BORDER_IMAGE_SLICE_TYPE_PERCENTAGE;
            current_widget->border->borderImage->imageSlice->borderImageSliceTypeBottom = CSS_BORDER_IMAGE_SLICE_TYPE_PERCENTAGE;
            current_widget->border->borderImage->imageSlice->borderImageSliceTypeLeft = CSS_BORDER_IMAGE_SLICE_TYPE_PERCENTAGE;
            current_widget->border->borderImage->imageSlice->borderImageSliceTypeRight = CSS_BORDER_IMAGE_SLICE_TYPE_PERCENTAGE;
            current_widget->border->borderImage->imageWidth->valueTop = 1;
            current_widget->border->borderImage->imageWidth->valueBottom = 1;
            current_widget->border->borderImage->imageWidth->valueLeft = 1;
            current_widget->border->borderImage->imageWidth->valueRight = 1;
            current_widget->border->borderImage->imageWidth->borderImageWidthTypeTop = CSS_BORDER_IMAGE_WIDTH_TYPE_NUMBER;
            current_widget->border->borderImage->imageWidth->borderImageWidthTypeBottom = CSS_BORDER_IMAGE_WIDTH_TYPE_NUMBER;
            current_widget->border->borderImage->imageWidth->borderImageWidthTypeLeft = CSS_BORDER_IMAGE_WIDTH_TYPE_NUMBER;
            current_widget->border->borderImage->imageWidth->borderImageWidthTypeRight = CSS_BORDER_IMAGE_WIDTH_TYPE_NUMBER;
            current_widget->border->borderImage->imageOutset->valueTop = 1;
            current_widget->border->borderImage->imageOutset->valueBottom = 1;
            current_widget->border->borderImage->imageOutset->valueLeft = 1;
            current_widget->border->borderImage->imageOutset->valueRight = 1;
            current_widget->border->borderImage->imageOutset->borderImageOutsetTypeTop = CSS_BORDER_IMAGE_OUTSET_TYPE_NUMBER;
            current_widget->border->borderImage->imageOutset->borderImageOutsetTypeBottom = CSS_BORDER_IMAGE_OUTSET_TYPE_NUMBER;
            current_widget->border->borderImage->imageOutset->borderImageOutsetTypeLeft = CSS_BORDER_IMAGE_OUTSET_TYPE_NUMBER;
            current_widget->border->borderImage->imageOutset->borderImageOutsetTypeRight = CSS_BORDER_IMAGE_OUTSET_TYPE_NUMBER;
            current_widget->border->borderImage->imageRepeatType = CSS_BORDER_IMAGE_REPEAT_TYPE_STRETCH;
        }
        else{
            set_border_image(current_widget->border, value);
        }
    }
}

void border_image_outset_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderImage == NULL){
        current_widget->border->borderImage = malloc(sizeof(struct border_image));
    }
    if(!strcmp(value, "inherit")){
        current_widget->border->borderImage->border_image_outset_inherit = true;
    }
    else{
        current_widget->border->borderImage->border_image_outset_inherit = false;
        if (current_widget->border->borderImage->imageOutset == NULL){
            current_widget->border->borderImage->imageOutset = malloc(sizeof(struct border_image_outset));
        }
        if (!strcmp(value, "initial")){
            current_widget->border->borderImage->imageOutset->valueTop = 0;
            current_widget->border->borderImage->imageOutset->valueBottom = 0;
            current_widget->border->borderImage->imageOutset->valueLeft = 0;
            current_widget->border->borderImage->imageOutset->valueRight = 0;
            current_widget->border->borderImage->imageOutset->borderImageOutsetTypeTop = CSS_BORDER_IMAGE_OUTSET_TYPE_LENGTH;
            current_widget->border->borderImage->imageOutset->borderImageOutsetTypeBottom = CSS_BORDER_IMAGE_OUTSET_TYPE_LENGTH;
            current_widget->border->borderImage->imageOutset->borderImageOutsetTypeLeft = CSS_BORDER_IMAGE_OUTSET_TYPE_LENGTH;
            current_widget->border->borderImage->imageOutset->borderImageOutsetTypeRight = CSS_BORDER_IMAGE_OUTSET_TYPE_LENGTH;
        }
        else{
            set_border_image_outset(current_widget->border, value);
        }
    }
}

void border_image_repeat_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderImage == NULL){
        current_widget->border->borderImage = malloc(sizeof(struct border_image));
    }
    if(!strcmp(value, "inherit")){
        current_widget->border->borderImage->border_image_repeat_inherit = true;
    }
    else{
        current_widget->border->borderImage->border_image_repeat_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->border->borderImage->imageRepeatType = CSS_BORDER_IMAGE_REPEAT_TYPE_STRETCH;
        }
        else{
            set_border_image_repeat(current_widget->border, value);
        }
    }
}

void border_image_slice_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderImage == NULL){
        current_widget->border->borderImage = malloc(sizeof(struct border_image));
    }
    if(!strcmp(value, "inherit")){
        current_widget->border->borderImage->border_image_slice_inherit = true;
    }
    else{
        current_widget->border->borderImage->border_image_slice_inherit = false;
        if (current_widget->border->borderImage->imageSlice == NULL){
            current_widget->border->borderImage->imageSlice = malloc(sizeof(struct border_image_width));
        }
        if (!strcmp(value, "initial")){
            current_widget->border->borderImage->imageSlice->valueTop = 100;
            current_widget->border->borderImage->imageSlice->valueBottom = 100;
            current_widget->border->borderImage->imageSlice->valueLeft = 100;
            current_widget->border->borderImage->imageSlice->valueRight = 100;
            current_widget->border->borderImage->imageSlice->borderImageSliceTypeTop = CSS_BORDER_IMAGE_SLICE_TYPE_PERCENTAGE;
            current_widget->border->borderImage->imageSlice->borderImageSliceTypeBottom = CSS_BORDER_IMAGE_SLICE_TYPE_PERCENTAGE;
            current_widget->border->borderImage->imageSlice->borderImageSliceTypeLeft = CSS_BORDER_IMAGE_SLICE_TYPE_PERCENTAGE;
            current_widget->border->borderImage->imageSlice->borderImageSliceTypeRight = CSS_BORDER_IMAGE_SLICE_TYPE_PERCENTAGE;
        }
        else{
            set_border_image_slice(current_widget->border, value);
        }
    }
}

void border_image_source_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderImage == NULL){
        current_widget->border->borderImage = malloc(sizeof(struct border_image));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderImage->border_image_source_inherit = true;
    }
    else{
        current_widget->border->borderImage->border_image_source_inherit = false;
        if (strcmp(value, "initial") != 0){//default value is empty string
            set_border_image_source(current_widget->border, value);
        }
    }
}

void border_image_width_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderImage == NULL){
        current_widget->border->borderImage = malloc(sizeof(struct border_image));
    }
    if(!strcmp(value, "inherit")){
        current_widget->border->borderImage->border_image_width_inherit = true;
    }
    else{
        current_widget->border->borderImage->border_image_width_inherit = false;
        if (current_widget->border->borderImage->imageWidth == NULL){
            current_widget->border->borderImage->imageWidth = malloc(sizeof(struct border_image_width));
        }
        if (!strcmp(value, "initial")){
            current_widget->border->borderImage->imageWidth->valueTop = 1;
            current_widget->border->borderImage->imageWidth->valueBottom = 1;
            current_widget->border->borderImage->imageWidth->valueLeft = 1;
            current_widget->border->borderImage->imageWidth->valueRight = 1;
            current_widget->border->borderImage->imageWidth->borderImageWidthTypeTop = CSS_BORDER_IMAGE_WIDTH_TYPE_NUMBER;
            current_widget->border->borderImage->imageWidth->borderImageWidthTypeBottom = CSS_BORDER_IMAGE_WIDTH_TYPE_NUMBER;
            current_widget->border->borderImage->imageWidth->borderImageWidthTypeLeft = CSS_BORDER_IMAGE_WIDTH_TYPE_NUMBER;
            current_widget->border->borderImage->imageWidth->borderImageWidthTypeRight = CSS_BORDER_IMAGE_WIDTH_TYPE_NUMBER;
        }
        else{
            set_border_image_width(current_widget->border, value);
        }
    }
}

void border_left_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderStyle == NULL){
        current_widget->border->borderStyle = malloc(sizeof(struct border_style));
    }
    if (current_widget->border->borderWidth == NULL){
        current_widget->border->borderWidth = malloc(sizeof(struct border_width));
    }
    if (current_widget->border->borderColor == NULL){
        current_widget->border->borderColor = malloc(sizeof(struct border_color));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderStyle->border_style_left_inherit = true;
        current_widget->border->borderWidth->border_width_left_inherit = true;
        current_widget->border->borderColor->border_color_left_inherit = true;
    }
    else{
        current_widget->border->borderStyle->border_style_left_inherit = false;
        current_widget->border->borderWidth->border_width_left_inherit = true;
        current_widget->border->borderColor->border_color_left_inherit = true;
        if (current_widget->border->borderColor->leftBorderColor == NULL){
            current_widget->border->borderColor->leftBorderColor = malloc(sizeof(struct color_rgba));
        }
        if (current_widget->border->borderWidth->left_border == NULL){
            current_widget->border->borderWidth->left_border = malloc(sizeof(struct border_line_width));
        }
        if (!strcmp(value, "initial")){
            current_widget->border->borderStyle->borderStyleTypeLeft = CSS_BORDER_STYLE_TYPE_NONE;
            current_widget->border->borderWidth->left_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
            sync_color(current_widget->color, current_widget->border->borderColor->leftBorderColor);
        }
        else{
            set_border_left(current_widget->border, value);
        }
    }
}

void border_left_color_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderColor == NULL){
        current_widget->border->borderColor = malloc(sizeof(struct border_color));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderColor->border_color_left_inherit = true;
    }
    else{
        current_widget->border->borderColor->border_color_left_inherit = false;
        if(current_widget->border->borderColor->leftBorderColor == NULL){
            current_widget->border->borderColor->leftBorderColor = malloc(sizeof(struct color_rgba));
        }
        if (!strcmp(value, "initial")){
            if (current_widget->color == NULL){
                get_color_by_rgb(current_widget->border->borderColor->leftBorderColor, 0, 0, 0);
            }
            else{
                sync_color(current_widget->color, current_widget->border->borderColor->leftBorderColor);
            }
        }
        else{
            set_border_left_color(current_widget->border, value);
        }
    }
}

void border_left_style_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderStyle == NULL){
        current_widget->border->borderStyle = malloc(sizeof(struct border_style));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderStyle->border_style_left_inherit = true;
    }
    else{
        current_widget->border->borderStyle->border_style_left_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->border->borderStyle->borderStyleTypeLeft = CSS_BORDER_STYLE_TYPE_NONE;
        }
        else{
            set_border_left_style(current_widget->border, value);
        }
    }
}

void border_left_width_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if(current_widget->border->borderWidth == NULL){
        current_widget->border->borderWidth = malloc(sizeof(struct border_width));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderWidth->border_width_left_inherit = true;
    }
    else{
        if(current_widget->border->borderWidth->left_border == NULL){
            current_widget->border->borderWidth->left_border = malloc(sizeof(struct border_line_width));
        }
        set_border_left_width(current_widget->border, value);
    }
}

void border_radius_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->border_radius_inherit = true;
    }
    else{
        current_widget->border->border_radius_inherit = false;
        if(current_widget->border->borderRadius == NULL){
            current_widget->border->borderRadius = malloc(sizeof(struct border_radius));
        }
        set_border_radius(current_widget->border, value);
    }
}

void border_right_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderStyle == NULL){
        current_widget->border->borderStyle = malloc(sizeof(struct border_style));
    }
    if (current_widget->border->borderWidth == NULL){
        current_widget->border->borderWidth = malloc(sizeof(struct border_width));
    }
    if (current_widget->border->borderColor == NULL){
        current_widget->border->borderColor = malloc(sizeof(struct border_color));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderStyle->border_style_right_inherit = true;
        current_widget->border->borderWidth->border_width_right_inherit = true;
        current_widget->border->borderColor->border_color_right_inherit = true;
    }
    else{
        current_widget->border->borderStyle->border_style_right_inherit = false;
        current_widget->border->borderWidth->border_width_right_inherit = true;
        current_widget->border->borderColor->border_color_right_inherit = true;
        if (current_widget->border->borderColor->rightBorderColor == NULL){
            current_widget->border->borderColor->rightBorderColor = malloc(sizeof(struct color_rgba));
        }
        if (current_widget->border->borderWidth->right_border == NULL){
            current_widget->border->borderWidth->right_border = malloc(sizeof(struct border_line_width));
        }
        if (!strcmp(value, "initial")){
            current_widget->border->borderStyle->borderStyleTypeRight = CSS_BORDER_STYLE_TYPE_NONE;
            current_widget->border->borderWidth->right_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
            sync_color(current_widget->color, current_widget->border->borderColor->rightBorderColor);
        }
        else{
            set_border_right(current_widget->border, value);
        }
    }
}

void border_right_color_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderColor == NULL){
        current_widget->border->borderColor = malloc(sizeof(struct border_color));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderColor->border_color_right_inherit = true;
    }
    else{
        current_widget->border->borderColor->border_color_right_inherit = false;
        if(current_widget->border->borderColor->rightBorderColor == NULL){
            current_widget->border->borderColor->rightBorderColor = malloc(sizeof(struct color_rgba));
        }
        if (!strcmp(value, "initial")){
            if (current_widget->color == NULL){
                get_color_by_rgb(current_widget->border->borderColor->rightBorderColor, 0, 0, 0);
            }
            else{
                sync_color(current_widget->color, current_widget->border->borderColor->rightBorderColor);
            }
        }
        else{
            set_border_bottom_color(current_widget->border, value);
        }
    }
}

void border_right_style_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderStyle == NULL){
        current_widget->border->borderStyle = malloc(sizeof(struct border_style));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderStyle->border_style_right_inherit = true;
    }
    else{
        current_widget->border->borderStyle->border_style_right_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->border->borderStyle->borderStyleTypeRight = CSS_BORDER_STYLE_TYPE_NONE;
        }
        else{
            set_border_right_style(current_widget->border, value);
        }
    }
}

void border_right_width_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if(current_widget->border->borderWidth == NULL){
        current_widget->border->borderWidth = malloc(sizeof(struct border_width));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderWidth->border_width_right_inherit = true;
    }
    else{
        if(current_widget->border->borderWidth->right_border == NULL){
            current_widget->border->borderWidth->right_border = malloc(sizeof(struct border_line_width));
        }
        set_border_right_width(current_widget->border, value);
    }
}

void border_spacing_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->border_spacing_inherit = true;
    }
    else{
        current_widget->border->border_spacing_inherit = false;
        if (current_widget->border->borderSpacing == NULL){
            current_widget->border->borderSpacing = malloc(sizeof(struct border_spacing));
        }
        if (!strcmp(value, "initial")){
            current_widget->border->borderSpacing->h_spacing = 2;
            current_widget->border->borderSpacing->v_spacing = 2;
        }
        else{
            set_border_spacing(current_widget->border, value);
        }
    }
}

void border_style_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->border_style_inherit = true;
    }
    else{
        if (current_widget->border->borderStyle == NULL){
            current_widget->border->borderStyle = malloc(sizeof(struct border_style));
        }
        if (!strcmp(value, "initial")){
            current_widget->border->borderStyle->borderStyleTypeBottom = CSS_BORDER_STYLE_TYPE_NONE;
            current_widget->border->borderStyle->borderStyleTypeTop = CSS_BORDER_STYLE_TYPE_NONE;
            current_widget->border->borderStyle->borderStyleTypeLeft = CSS_BORDER_STYLE_TYPE_NONE;
            current_widget->border->borderStyle->borderStyleTypeRight = CSS_BORDER_STYLE_TYPE_NONE;
        }
        else{
            set_border_style(current_widget->border, value);
        }
    }
}

void border_top_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderStyle == NULL){
        current_widget->border->borderStyle = malloc(sizeof(struct border_style));
    }
    if (current_widget->border->borderWidth == NULL){
        current_widget->border->borderWidth = malloc(sizeof(struct border_width));
    }
    if (current_widget->border->borderColor == NULL){
        current_widget->border->borderColor = malloc(sizeof(struct border_color));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderStyle->border_style_top_inherit = true;
        current_widget->border->borderWidth->border_width_top_inherit = true;
        current_widget->border->borderColor->border_color_top_inherit = true;
    }
    else{
        current_widget->border->borderStyle->border_style_top_inherit = false;
        current_widget->border->borderWidth->border_width_top_inherit = true;
        current_widget->border->borderColor->border_color_top_inherit = true;
        if (current_widget->border->borderColor->topBorderColor == NULL){
            current_widget->border->borderColor->topBorderColor = malloc(sizeof(struct color_rgba));
        }
        if (current_widget->border->borderWidth->top_border == NULL){
            current_widget->border->borderWidth->top_border = malloc(sizeof(struct border_line_width));
        }
        if (!strcmp(value, "initial")){
            current_widget->border->borderStyle->borderStyleTypeTop = CSS_BORDER_STYLE_TYPE_NONE;
            current_widget->border->borderWidth->top_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
            sync_color(current_widget->color, current_widget->border->borderColor->topBorderColor);
        }
        else{
            set_border_top(current_widget->border, value);
        }
    }
}

void border_top_color_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderColor == NULL){
        current_widget->border->borderColor = malloc(sizeof(struct border_color));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderColor->border_color_top_inherit = true;
    }
    else{
        current_widget->border->borderColor->border_color_top_inherit = false;
        if(current_widget->border->borderColor->topBorderColor == NULL){
            current_widget->border->borderColor->topBorderColor = malloc(sizeof(struct color_rgba));
        }
        if (!strcmp(value, "initial")){
            if (current_widget->color == NULL){
                get_color_by_rgb(current_widget->border->borderColor->topBorderColor, 0, 0, 0);
            }
            else{
                sync_color(current_widget->color ,current_widget->border->borderColor->topBorderColor);
            }
        }
        else{
            set_border_top_color(current_widget->border, value);
        }
    }
}

void border_top_left_radius_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderRadius == NULL){
        current_widget->border->borderRadius = malloc(sizeof(struct border_radius));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderRadius->border_top_left_radius_inherit = true;
    }
    else{
        current_widget->border->borderRadius->border_top_left_radius_inherit = false;
        if (!strcmp(value, "initial")){//DID WE NEED THIS?
            current_widget->border->borderRadius->border_top_left_radius_type = CSS_BORDER_RADIUS_TYPE_LENGTH;
            current_widget->border->borderRadius->border_top_left_radius_value = 0;
        }
        else{
            set_border_top_left_radius(current_widget->border, value);
        }
    }
}

void border_top_right_radius_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderRadius == NULL){
        current_widget->border->borderRadius = malloc(sizeof(struct border_radius));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderRadius->border_top_right_radius_inherit = true;
    }
    else{
        current_widget->border->borderRadius->border_top_right_radius_inherit = false;
        if (!strcmp(value, "initial")){//DID WE NEED THIS?
            current_widget->border->borderRadius->border_top_right_radius_type = CSS_BORDER_RADIUS_TYPE_LENGTH;
            current_widget->border->borderRadius->border_top_right_radius_value = 0;
        }
        else{
            set_border_top_right_radius(current_widget->border, value);
        }
    }
}

void border_top_style_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (current_widget->border->borderStyle == NULL){
        current_widget->border->borderStyle = malloc(sizeof(struct border_style));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderStyle->border_style_top_inherit = true;
    }
    else{
        current_widget->border->borderStyle->border_style_top_inherit = false;
        if (!strcmp(value, "initial")){
            current_widget->border->borderStyle->borderStyleTypeTop = CSS_BORDER_STYLE_TYPE_NONE;
        }
        else{
            set_border_top_style(current_widget->border, value);
        }
    }
}

void border_top_width_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if(current_widget->border->borderWidth == NULL){
        current_widget->border->borderWidth = malloc(sizeof(struct border_width));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->borderWidth->border_width_top_inherit = true;
    }
    else{
        if(current_widget->border->borderWidth->top_border == NULL){
            current_widget->border->borderWidth->top_border = malloc(sizeof(struct border_line_width));
        }
        set_border_top_width(current_widget->border, value);
    }
}

void border_width_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->border == NULL){
        current_widget->border = malloc(sizeof(struct css_border));
    }
    if (!strcmp(value, "inherit")){
        current_widget->border->border_width_inherit = true;
    }
    else{
        if (current_widget->border->borderWidth == NULL){
            current_widget->border->borderWidth = malloc(sizeof(struct border_width));
        }
        if(current_widget->border->borderWidth->bottom_border == NULL){//if one of them is null then all of them is null
            current_widget->border->borderWidth->bottom_border = malloc(sizeof(struct border_line_width));
            current_widget->border->borderWidth->top_border = malloc(sizeof(struct border_line_width));
            current_widget->border->borderWidth->left_border = malloc(sizeof(struct border_line_width));
            current_widget->border->borderWidth->right_border = malloc(sizeof(struct border_line_width));
        }
        if (!strcmp(value, "initial")){
            current_widget->border->borderWidth->bottom_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
            current_widget->border->borderWidth->top_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
            current_widget->border->borderWidth->left_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
            current_widget->border->borderWidth->right_border->borderLineType = CSS_BORDER_LINE_TYPE_MEDIUM;
        }
        else{
            set_border_width(current_widget->border, value);
        }
    }
}

void free_border(struct css_properties* current_widget){
    free(current_widget->border->borderWidth);
    free(current_widget->border->borderStyle);
    free(current_widget->border->borderColor->bottomBorderColor);
    free(current_widget->border->borderColor->leftBorderColor);
    free(current_widget->border->borderColor->rightBorderColor);
    free(current_widget->border->borderColor->topBorderColor);
    free(current_widget->border->borderColor);
    free(current_widget->border->borderSpacing);
    free(current_widget->border->borderImage->imageOutset);
    free(current_widget->border->borderImage->imageSlice);
    free(current_widget->border->borderImage->imageWidth);
    free(current_widget->border->borderImage);
}