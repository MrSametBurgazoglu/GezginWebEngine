//
// Created by samet on 23.04.2022.
//

#include "font.h"
#include <stdlib.h>
#include <string.h>
#include "../../functools/index_founder.h"

#define FONT_SPECIAL_TYPE_STRING_COUNT 6
#define FONT_SIZE_STRING_COUNT 9
#define FONT_STRETCH_STRING_COUNT 9
#define FONT_STYLE_STRING_COUNT 3
#define FONT_VARIANT_STRING_COUNT 2
#define FONT_VARIANT_CAPS_STRING_COUNT 8
#define FONT_WEIGHT_STRING_COUNT 4

char* font_special_type_strings[FONT_SPECIAL_TYPE_STRING_COUNT] = {
        "caption",
        "icon",
        "menu",
        "message-box",
        "small-caption",
        "status-bar",
};

char* font_size_strings[FONT_STRETCH_STRING_COUNT] = {
        "large",
        "larger",
        "medium",
        "small",
        "smaller",
        "x-large",
        "x-small",
        "xx-large",
        "xx-small",
};

char* font_stretch_strings[FONT_STRETCH_STRING_COUNT] = {
        "condensed",
        "expanded",
        "extra-condensed",
        "extra-expanded",
        "normal",
        "semi-condensed",
        "semi-expanded",
        "ultra-condensed",
        "ultra-expanded",
};

char* font_style_strings[FONT_STYLE_STRING_COUNT] = {
        "italic",
        "normal",
        "oblique",
};

char* font_variant_strings[FONT_VARIANT_STRING_COUNT] = {
        "normal",
        "small-caps",
};

char* font_variant_caps_strings[FONT_VARIANT_CAPS_STRING_COUNT] = {
        "all-petite-caps",
        "all-small-caps",
        "normal",
        "petite-caps",
        "small-caps",
        "titling-caps",
        "unicase",
        "unset"
};

char* font_weight_strings[FONT_WEIGHT_STRING_COUNT] = {
        "bold",
        "bolder",
        "lighter",
        "normal",
};

css_font_special_type cssFontSpecialTypeList[FONT_SPECIAL_TYPE_STRING_COUNT] = {
        CSS_FONT_SPECIAL_TYPE_CAPTION,
        CSS_FONT_SPECIAL_TYPE_ICON,
        CSS_FONT_SPECIAL_TYPE_MENU,
        CSS_FONT_SPECIAL_TYPE_MESSAGE_BOX,
        CSS_FONT_SPECIAL_TYPE_SMALL_CAPTION,
        CSS_FONT_SPECIAL_TYPE_STATUS_BAR,
};

css_font_size_type cssFontSizeTypeList[FONT_SIZE_STRING_COUNT] = {
        CSS_FONT_SIZE_TYPE_LARGE,
        CSS_FONT_SIZE_TYPE_LARGER,
        CSS_FONT_SIZE_TYPE_MEDIUM,
        CSS_FONT_SIZE_TYPE_SMALL,
        CSS_FONT_SIZE_TYPE_SMALLER,
        CSS_FONT_SIZE_TYPE_X_LARGE,
        CSS_FONT_SIZE_TYPE_X_SMALL,
        CSS_FONT_SIZE_TYPE_XX_LARGE,
        CSS_FONT_SIZE_TYPE_XX_SMALL,
};

css_font_stretch_type cssFontStretchTypeList[FONT_STRETCH_STRING_COUNT] = {
        CSS_FONT_STRETCH_TYPE_CONDENSED,
        CSS_FONT_STRETCH_TYPE_EXPANDED,
        CSS_FONT_STRETCH_TYPE_EXTRA_CONDENSED,
        CSS_FONT_STRETCH_TYPE_EXTRA_EXPANDED,
        CSS_FONT_STRETCH_TYPE_NORMAL,
        CSS_FONT_STRETCH_TYPE_SEMI_CONDENSED,
        CSS_FONT_STRETCH_TYPE_SEMI_EXPANDED,
        CSS_FONT_STRETCH_TYPE_ULTRA_CONDENSED,
        CSS_FONT_STRETCH_TYPE_ULTRA_EXPANDED,
};

css_font_style cssFontStyleList[FONT_STYLE_STRING_COUNT] = {
        CSS_FONT_STYLE_ITALIC,
        CSS_FONT_STYLE_NORMAL,
        CSS_FONT_STYLE_OBLIQUE,
};

css_font_variant_type cssFontVariantTypeList[FONT_VARIANT_STRING_COUNT] = {
        CSS_FONT_VARIANT_NORMAL,
        CSS_FONT_VARIANT_SMALL_CAPS,
};

css_font_variant_caps_type cssFontVariantCapsTypeList[FONT_VARIANT_CAPS_STRING_COUNT] = {
        CSS_FONT_VARIANT_CAPS_TYPE_ALL_PETITE_CAPS,
        CSS_FONT_VARIANT_CAPS_TYPE_ALL_SMALL_CAPS,
        CSS_FONT_VARIANT_CAPS_TYPE_NORMAL,
        CSS_FONT_VARIANT_CAPS_TYPE_PETITE_CAPS,
        CSS_FONT_VARIANT_CAPS_TYPE_SMALL_CAPS,
        CSS_FONT_VARIANT_CAPS_TYPE_TITLING_CAPS,
        CSS_FONT_VARIANT_CAPS_TYPE_UNICASE,
        CSS_FONT_VARIANT_CAPS_TYPE_UNSET,
};

css_font_weight_type cssFontWeightTypeList[FONT_WEIGHT_STRING_COUNT] = {
        CSS_FONT_WEIGHT_BOLD,
        CSS_FONT_WEIGHT_BOLDER,
        CSS_FONT_WEIGHT_LIGHTER,
        CSS_FONT_WEIGHT_NORMAL,
};

void set_font_family(struct font* fontStruct, char* value){
    char* value2;
    int index = 0;
    value2 = strtok(value, " ");
    while (value2 != NULL){
        char* text;
        int length = (int) strlen(value2);
        text = malloc(sizeof(char )* length);
        memcpy(text, value2, length);
        text[length] = '\0';
        index++;
        fontStruct->font_family = realloc(fontStruct->font_family, sizeof(char *) * index);
        fontStruct->font_family[index-1] = text;
        value2 = strtok(NULL, " ");
    }
    fontStruct->font_family_count = index;
}

//will not be implemented until css scraper finished
void set_font_feature_settings(struct font* fontStruct, char* value){
}

void set_font_kerning(struct font* fontStruct, char* value){
    if (!strcmp(value, "normal")){
        fontStruct->font_kerning = true;
    }
}

void set_font_size(struct font* fontStruct, char* value){
    int index = get_index_from_list_by_string(font_size_strings, value, FONT_SIZE_STRING_COUNT);
    if (index != -1){
        fontStruct->fontSizeType = cssFontSizeTypeList[index];
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (!strcmp(end_ptr, "px")){
            fontStruct->font_size_value = first_value;
            fontStruct->fontSizeType = CSS_FONT_SIZE_TYPE_LENGTH;
        }
        else if(!strcmp(end_ptr, "%")){
            fontStruct->font_size_value = first_value;
            fontStruct->fontSizeType = CSS_FONT_SIZE_TYPE_PERCENTAGE;
        }
        else{//DEFAULT VALUE
            fontStruct->fontSizeType = CSS_FONT_SIZE_TYPE_MEDIUM;
        }
    }
}


void set_font_stretch(struct font* fontStruct, char* value){
    int index = get_index_from_list_by_string(font_stretch_strings, value, FONT_STRETCH_STRING_COUNT);
    if (index != -1){
        fontStruct->fontStretchType = cssFontStretchTypeList[index];
    }
    else{
        fontStruct->fontStretchType = CSS_FONT_STRETCH_TYPE_NORMAL;
    }
}

void set_font_style(struct font* fontStruct, char* value){
    int index = get_index_from_list_by_string(font_style_strings, value, FONT_STYLE_STRING_COUNT);
    if (index != -1){
        fontStruct->fontStyle = cssFontStyleList[index];
    }
    else{
        fontStruct->fontStyle = CSS_FONT_STYLE_NORMAL;
    }
}

void set_font_variant(struct font* fontStruct, char* value){
    int index = get_index_from_list_by_string(font_variant_strings, value, FONT_VARIANT_STRING_COUNT);
    if (index != -1){
        fontStruct->fontVariantType = cssFontVariantTypeList[index];
    }
    else{
        fontStruct->fontVariantType = CSS_FONT_VARIANT_NORMAL;
    }
}

void set_font_variant_caps(struct font* fontStruct, char* value){
    int index = get_index_from_list_by_string(font_variant_caps_strings, value, FONT_VARIANT_CAPS_STRING_COUNT);
    if (index != -1){
        fontStruct->fontVariantCapsType = cssFontVariantCapsTypeList[index];
    }
    else{
        fontStruct->fontVariantCapsType = CSS_FONT_VARIANT_CAPS_TYPE_NORMAL;
    }
}

void set_font_weight(struct font* fontStruct, char* value){
    int index = get_index_from_list_by_string(font_weight_strings, value, FONT_WEIGHT_STRING_COUNT);
    if (index != -1){
        fontStruct->fontWeightType = cssFontWeightTypeList[index];
    }
    else{
        char* end_ptr;
        int first_value = (int) strtol(value, &end_ptr, 10);
        if (value != end_ptr){
            fontStruct->font_weight_value = first_value;
            fontStruct->fontWeightType = CSS_FONT_WEIGHT_NUMBER;
        }
        else{//DEFAULT VALUE
            fontStruct->fontWeightType = CSS_FONT_WEIGHT_NORMAL;
        }
    }
}

/*this property order must be font-style font-variant font-weight font-size/line-height font-family
 * if 5 value font-style font-variant font-weight font-size/line-height font-family
 * if 4 value font-style font-variant font-weight font-size/line-height font-family
 *
 * */
void set_font(struct font* fontStruct, char* value){
    int index = get_index_from_list_by_string(font_special_type_strings, value, FONT_SPECIAL_TYPE_STRING_COUNT);
    if (index != -1){
        fontStruct->fontSpecialType = cssFontSpecialTypeList[index];
    }
    else{
        fontStruct->fontSpecialType = CSS_FONT_SPECIAL_TYPE_NONE;
        char* values[5];
        char* value2;
        index = 0;
        value2 = strtok(value, " ");
        while (value2 != NULL && index < 6){
            values[index++] = value2;
            value2 = strtok(NULL, " ");
        }
        switch (index) {
            case 2:
                set_font_size(fontStruct, values[0]);
                set_font_family(fontStruct, values[1]);
                break;
            case 3:
                set_font_style(fontStruct, values[0]);
                set_font_variant_caps(fontStruct, values[0]);
                set_font_size(fontStruct, values[1]);
                set_font_family(fontStruct, values[2]);
                break;
            case 4:
                set_font_style(fontStruct, values[0]);
                set_font_weight(fontStruct, values[1]);
                set_font_size(fontStruct, values[2]);
                set_font_family(fontStruct, values[3]);
                break;
            case 5:
                set_font_style(fontStruct, values[0]);
                set_font_variant_caps(fontStruct, values[1]);
                set_font_weight(fontStruct, values[2]);
                set_font_size(fontStruct, values[3]);
                set_font_family(fontStruct, values[4]);
            default:
                break;
        }
    }
}

void font_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->font_inherit = true;
    }
    else{
        current_widget->font_inherit = false;
        if (current_widget->font == NULL){
            current_widget->font = malloc(sizeof(struct font));
        }
        if (current_widget->font->font_family == NULL){
            current_widget->font->font_family = malloc(sizeof(char *));
        }
        if (!strcmp(value, "initial")){
            current_widget->font->font_family[0] = malloc(sizeof(char ) * 5);
            memcpy(current_widget->font->font_family[0], "sans\0", 5);// is \0 added?
            current_widget->font->fontSizeType = CSS_FONT_SIZE_TYPE_MEDIUM;
            current_widget->font->fontStyle = CSS_FONT_STYLE_NORMAL;
            current_widget->font->fontVariantType = CSS_FONT_VARIANT_NORMAL;
            current_widget->font->fontWeightType = CSS_FONT_WEIGHT_NORMAL;
        }
        else{
            set_font(current_widget->font, value);
        }
    }
}

void font_family_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->font_inherit){
            if (current_widget->font == NULL){
                current_widget->font = malloc(sizeof(struct font));
            }
            current_widget->font->font_family_inherited = true;
        }
    }
    else{
        if (current_widget->font == NULL){
            current_widget->font = malloc(sizeof(struct font));
        }
        if (current_widget->font_inherit){
            current_widget->font->font_size_inherited = true;
            current_widget->font->font_stretch_inherited = true;
            current_widget->font->font_style_inherited = true;
            current_widget->font->font_variant_caps_inherited = true;
            current_widget->font->font_variant_inherited = true;
            current_widget->font->font_weight_inherited = true;
            current_widget->font_inherit = false;
        }
        if (current_widget->font->font_family == NULL){
            current_widget->font->font_family = malloc(sizeof(char *));
        }
        else{
            for (int i = 0; i < current_widget->font->font_family_count; ++i) {
                free(current_widget->font->font_family[i]);
            }
            free(current_widget->font->font_family);
            current_widget->font->font_family_count = 0;
        }
        if (!strcmp(value, "initial")){
            current_widget->font->font_family[0] = malloc(sizeof(char ) * 5);
            memcpy(current_widget->font->font_family[0], "sans\0", 5);// is \0 added?
        }
        else{
            set_font_family(current_widget->font, value);
        }
    }
}

//will not be implemented until css scraper finished may be never
void font_feature_settings_property_set_value(struct css_properties* current_widget, char* value){

}

void font_kerning_property_set_value(struct css_properties* current_widget, char* value){
    //may be we can move font kerning to current widget
    if (current_widget->font == NULL){
        current_widget->font = malloc(sizeof(struct font));
    }
    if (current_widget->font_inherit){
        current_widget->font->font_size_inherited = true;
        current_widget->font->font_stretch_inherited = true;
        current_widget->font->font_style_inherited = true;
        current_widget->font->font_variant_caps_inherited = true;
        current_widget->font->font_variant_inherited = true;
        current_widget->font->font_weight_inherited = true;
        current_widget->font_inherit = false;
    }
    else{
        set_font_kerning(current_widget->font, value);
    }
}

void font_size_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->font_inherit){
            if (current_widget->font == NULL){
                current_widget->font = malloc(sizeof(struct font));
            }
            current_widget->font->font_size_inherited = true;
        }
    }
    else{
        if (current_widget->font == NULL){
            current_widget->font = malloc(sizeof(struct font));
        }
        if (current_widget->font_inherit){
            current_widget->font->font_family_inherited = true;
            current_widget->font->font_stretch_inherited = true;
            current_widget->font->font_style_inherited = true;
            current_widget->font->font_variant_caps_inherited = true;
            current_widget->font->font_variant_inherited = true;
            current_widget->font->font_weight_inherited = true;
            current_widget->font_inherit = false;
        }
        if (!strcmp(value, "initial")){
            current_widget->font->fontSizeType = CSS_FONT_SIZE_TYPE_MEDIUM;
        }
        else{
            set_font_size(current_widget->font, value);
        }
    }
}


void font_stretch_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->font_inherit){
            if (current_widget->font == NULL){
                current_widget->font = malloc(sizeof(struct font));
            }
            current_widget->font->font_stretch_inherited = true;
        }
    }
    else{
        if (current_widget->font == NULL){
            current_widget->font = malloc(sizeof(struct font));
        }
        if (current_widget->font_inherit){
            current_widget->font->font_family_inherited = true;
            current_widget->font->font_size_inherited = true;
            current_widget->font->font_style_inherited = true;
            current_widget->font->font_variant_caps_inherited = true;
            current_widget->font->font_variant_inherited = true;
            current_widget->font->font_weight_inherited = true;
            current_widget->font_inherit = false;
        }
        if (!strcmp(value, "initial")){
            current_widget->font->fontStretchType = CSS_FONT_STRETCH_TYPE_NORMAL;
        }
        else{
            set_font_stretch(current_widget->font, value);
        }
    }
}

void font_style_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->font_inherit){
            if (current_widget->font == NULL){
                current_widget->font = malloc(sizeof(struct font));
            }
            current_widget->font->font_style_inherited = true;
        }
    }
    else{
        if (current_widget->font == NULL){
            current_widget->font = malloc(sizeof(struct font));
        }
        if (current_widget->font_inherit){
            current_widget->font->font_family_inherited = true;
            current_widget->font->font_size_inherited = true;
            current_widget->font->font_stretch_inherited = true;
            current_widget->font->font_variant_caps_inherited = true;
            current_widget->font->font_variant_inherited = true;
            current_widget->font->font_weight_inherited = true;
            current_widget->font_inherit = false;
        }
        if (!strcmp(value, "initial")){
            current_widget->font->fontStyle = CSS_FONT_STYLE_NORMAL;
        }
        else{
            set_font_style(current_widget->font, value);
        }
    }
}

void font_variant_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->font_inherit){
            if (current_widget->font == NULL){
                current_widget->font = malloc(sizeof(struct font));
            }
            current_widget->font->font_variant_inherited = true;
        }
    }
    else{
        if (current_widget->font == NULL){
            current_widget->font = malloc(sizeof(struct font));
        }
        if (current_widget->font_inherit){
            current_widget->font->font_family_inherited = true;
            current_widget->font->font_size_inherited = true;
            current_widget->font->font_stretch_inherited = true;
            current_widget->font->font_style_inherited = true;
            current_widget->font->font_variant_caps_inherited = true;
            current_widget->font->font_weight_inherited = true;
            current_widget->font_inherit = false;
        }
        if (!strcmp(value, "initial")){
            current_widget->font->fontVariantType = CSS_FONT_VARIANT_NORMAL;
        }
        else{
            set_font_variant_caps(current_widget->font, value);
        }
    }
}

void font_variant_caps_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->font_inherit){
            if (current_widget->font == NULL){
                current_widget->font = malloc(sizeof(struct font));
            }
            current_widget->font->font_variant_caps_inherited = true;
        }
    }
    else{
        if (current_widget->font == NULL){
            current_widget->font = malloc(sizeof(struct font));
        }
        if (current_widget->font_inherit){
            current_widget->font->font_family_inherited = true;
            current_widget->font->font_size_inherited = true;
            current_widget->font->font_stretch_inherited = true;
            current_widget->font->font_style_inherited = true;
            current_widget->font->font_variant_inherited = true;
            current_widget->font->font_weight_inherited = true;
            current_widget->font_inherit = false;
        }
        if (!strcmp(value, "initial")){
            current_widget->font->fontVariantCapsType = CSS_FONT_VARIANT_CAPS_TYPE_NORMAL;
        }
        else{
            set_font_variant_caps(current_widget->font, value);
        }
    }
}

void font_weight_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->font_inherit){
            if (current_widget->font == NULL){
                current_widget->font = malloc(sizeof(struct font));
            }
            current_widget->font->font_weight_inherited = true;
        }
    }
    else{
        if (current_widget->font == NULL){
            current_widget->font = malloc(sizeof(struct font));
        }
        if (current_widget->font_inherit){
            current_widget->font->font_family_inherited = true;
            current_widget->font->font_size_inherited = true;
            current_widget->font->font_stretch_inherited = true;
            current_widget->font->font_style_inherited = true;
            current_widget->font->font_variant_inherited = true;
            current_widget->font->font_variant_caps_inherited = true;
            current_widget->font_inherit = false;
        }
        if (!strcmp(value, "initial")){
            current_widget->font->fontWeightType = CSS_FONT_WEIGHT_NORMAL;
        }
        else{
            set_font_weight(current_widget->font, value);
        }
    }
}

void compute_inherit_font(struct css_properties* dest, struct css_properties* source){
    if (dest->font == NULL){
        dest->font = source->font;
    }
    else if (source->font != NULL){
        if (dest->font->font_family_count == 0){
            dest->font->font_family = source->font->font_family;
            dest->font->font_family_count = source->font->font_family_count;
        }
        if (source->font->font_kerning){
            dest->font->font_kerning = true;
        }
        if (dest->font->fontSizeType == CSS_FONT_SIZE_TYPE_EMPTY){
            dest->font->fontSizeType = source->font->fontSizeType;
        }
        if (dest->font->fontStretchType == CSS_FONT_SIZE_TYPE_EMPTY){
            dest->font->fontStretchType = source->font->fontStretchType;
        }
        if (dest->font->fontStyle == CSS_FONT_STYLE_EMPTY){
            dest->font->fontStyle = source->font->fontStyle;
        }
        if (dest->font->fontVariantType == CSS_FONT_VARIANT_CAPS_TYPE_EMPTY){
            dest->font->fontVariantType = source->font->fontVariantType;
        }
        if (dest->font->fontVariantCapsType == CSS_FONT_VARIANT_CAPS_TYPE_EMPTY){
            dest->font->fontVariantCapsType = source->font->fontVariantCapsType;
        }
        if (dest->font->fontWeightType == CSS_FONT_VARIANT_CAPS_TYPE_EMPTY){
            dest->font->fontWeightType = source->font->fontWeightType;
            dest->font->font_weight_value = source->font->font_weight_value;
        }
    }
}

void free_font(struct css_properties* current_widget){
    for (int i = 0; i < current_widget->font->font_family_count; ++i) {
        free(current_widget->font->font_family[i]);
    }
    free(current_widget->font->font_family);
    free(current_widget->font);
}

void update_font(struct css_properties* current_widget, struct css_properties* source){
    if(source->font_inherit){
        current_widget->font_inherit = true;
        current_widget->font = NULL;
    }
    else if (source->font != NULL){
        current_widget->font = source->font;
    }
}