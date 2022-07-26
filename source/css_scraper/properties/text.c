//
// Created by samet on 26.06.2022.
//

#include "text.h"

#define TEXT_ALIGN_STRING_COUNT 4
#define TEXT_ALIGN_LAST_STRING_COUNT 6
#define TEXT_DECORATION_LINE_STRING_COUNT 4
#define TEXT_DECORATION_STYLE_STRING_COUNT 5
#define TEXT_JUSTIFY_STRING_COUNT 4

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

char* text_overflow_strings[] = {
        "clip",
        "ellipsis",
        "string",
};

char* text_transform_strings[] = {
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

css_text_overflow_type textOverflowTypeList[] = {
        CSS_TEXT_OVERFLOW_CLIP,
        CSS_TEXT_OVERFLOW_ELLIPSIS,
        CSS_TEXT_OVERFLOW_STRING,
};

css_text_transform_type textTransformTypeList[] = {
        CSS_TEXT_TRANSFORM_CAPITALIZE,
        CSS_TEXT_TRANSFORM_LOWERCASE,
        CSS_TEXT_TRANSFORM_NONE,
        CSS_TEXT_TRANSFORM_UPPERCASE,
};

void text_align_property_set_value(struct css_properties*, char*){

}

void text_align_last_property_set_value(struct css_properties*, char*){

}

void text_decoration_property_set_value(struct css_properties*, char*){

}

void text_decoration_color_property_set_value(struct css_properties*, char*){

}

void text_decoration_line_property_set_value(struct css_properties*, char*){

}

void text_decoration_style_property_set_value(struct css_properties*, char*){

}

void text_decoration_thickness_property_set_value(struct css_properties*, char*){

}

void text_indent_property_set_value(struct css_properties*, char*){

}

void text_justify_property_set_value(struct css_properties*, char*){

}

void text_overflow_property_set_value(struct css_properties*, char*){

}

void text_shadow_property_set_value(struct css_properties*, char*){

}

void text_transform_property_set_value(struct css_properties*, char*){

}