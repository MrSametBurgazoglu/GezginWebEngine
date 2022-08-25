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

bool set_outline_color(struct outline* outline, char* value){
    return get_color(outline->colorRgba, value);
}

bool set_outline_offset(struct outline* outline, char* value){
    char * endptr;
    int int_value = (int) strtol(value, &endptr, 10);
    outline->offset = int_value;
    if (value == endptr){
        return false;
    }
    return true;
}

bool set_outline_style(struct outline* outline, char* value){
    int index = get_index_from_list_by_string(outline_style_strings, value, OUTLINE_STYLE_STRING_COUNT);
    if (index != -1){
        outline->outlineStyleType = outlineStyleTypeList[index];
        return true;
    }
    else{
        outline->outlineStyleType = CSS_OUTLINE_STYLE_TYPE_NONE;
        return false;
    }
}

bool set_outline_width(struct outline* outline, char* value){
    int index = get_index_from_list_by_string(outline_width_strings, value, OUTLINE_WIDTH_STRING_COUNT);
    if (index != -1){
        outline->outlineWidth = outlineWidthList[index];
        return true;
    }
    else{
        char* endptr;
        int first_value = (int) strtol(value, &endptr, 10);
        outline->outline_width = first_value;
        outline->outlineWidth = CSS_OUTLINE_WIDTH_TYPE_LENGTH;
        if (value == endptr){
            return false;
        }
        return true;
    }
}

void set_outline(struct outline* outline, char* value){
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
            set_outline_style(outline, values[0]);
            break;
        case 2:
            if (set_outline_style(outline, values[0])){
                if (!set_outline_color(outline, values[1])){
                    set_outline_width(outline, values[1]);
                }
            }
            else{
                if (!set_outline_color(outline, values[0])){
                    set_outline_width(outline, values[0]);
                }
                set_outline_style(outline, values[1]);
            }
            break;
        case 3:
            if (set_outline_style(outline, values[0])){
                if (set_outline_color(outline, values[1])){
                    set_outline_width(outline, values[2]);
                }
                else{
                    set_outline_width(outline, values[1]);
                    set_outline_color(outline, values[2]);
                }
            }
            else if(set_outline_color(outline, values[0])){
                if (set_outline_style(outline, values[1])){
                    set_outline_width(outline, values[2]);
                }
                else{
                    set_outline_width(outline, values[1]);
                    set_outline_style(outline, values[2]);
                }
            }
            else{
                set_outline_width(outline, values[0]);
                if (set_outline_style(outline, values[1])){
                    set_outline_color(outline, values[2]);
                }
                else{
                    set_outline_color(outline, values[1]);
                    set_outline_style(outline, values[2]);
                }
            }
            break;
        default:
            break;
    }
}

void outline_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        current_widget->outline_inherit = true;
    }
    else{
        current_widget->outline_inherit = false;
        if (current_widget->outline == NULL){
            current_widget->outline = malloc(sizeof(struct outline));
        }
        if(!strcmp(value, "initial")){
            current_widget->outline->outlineWidth = CSS_OUTLINE_WIDTH_TYPE_MEDIUM;
            current_widget->outline->outlineStyleType = CSS_OUTLINE_STYLE_TYPE_INSET;
            if (current_widget->outline->colorRgba == NULL){
                current_widget->outline->colorRgba = malloc(sizeof(struct color_rgba));
            }
            sync_color(current_widget->color, current_widget->outline->colorRgba);
        }
        else{
            set_outline(current_widget->outline, value);
        }
    }
}

void outline_color_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->outline_inherit){
            if (current_widget->outline == NULL){
                current_widget->outline = malloc(sizeof(struct outline));
            }
            current_widget->outline->outline_color_inherit = true;
        }
    }
    else{
        if (current_widget->outline == NULL){
            current_widget->outline = malloc(sizeof(struct outline));
        }
        if (current_widget->outline_inherit){
            current_widget->outline->outline_style_inherit = true;
            current_widget->outline->outline_offset_inherit = true;
            current_widget->outline->outline_width_inherit = true;
            current_widget->outline_inherit = false;
        }
        current_widget->outline->outline_color_inherit = false;
        if (current_widget->outline->colorRgba == NULL){
            current_widget->outline->colorRgba = malloc(sizeof(struct color_rgba));
        }
        if(!strcmp(value, "initial")){
            sync_color(current_widget->color, current_widget->outline->colorRgba);
        }
        else{
            set_outline_color(current_widget->outline, value);
        }
    }
}

void outline_offset_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->outline_inherit){
            if (current_widget->outline == NULL){
                current_widget->outline = malloc(sizeof(struct outline));
            }
            current_widget->outline->outline_offset_inherit = true;
        }
    }
    else{
        if (current_widget->outline == NULL){
            current_widget->outline = malloc(sizeof(struct outline));
        }
        if (current_widget->outline_inherit){
            current_widget->outline->outline_style_inherit = true;
            current_widget->outline->outline_color_inherit = true;
            current_widget->outline->outline_width_inherit = true;
            current_widget->outline_inherit = false;
        }
        current_widget->outline->outline_offset_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->outline->offset = 0;
        }
        else{
            set_outline_offset(current_widget->outline, value);
        }
    }
}

void outline_style_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->outline_inherit){
            if (current_widget->outline == NULL){
                current_widget->outline = malloc(sizeof(struct outline));
            }
            current_widget->outline->outline_style_inherit = true;
        }
    }
    else{
        if (current_widget->outline == NULL){
            current_widget->outline = malloc(sizeof(struct outline));
        }
        if (current_widget->outline_inherit){
            current_widget->outline->outline_offset_inherit = true;
            current_widget->outline->outline_color_inherit = true;
            current_widget->outline->outline_width_inherit = true;
            current_widget->outline_inherit = false;
        }
        current_widget->outline->outline_style_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->outline->outlineStyleType = CSS_OUTLINE_STYLE_TYPE_NONE;
        }
        else{
            set_outline_style(current_widget->outline, value);
        }
    }
}

void outline_width_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->outline_inherit){
            if (current_widget->outline == NULL){
                current_widget->outline = malloc(sizeof(struct outline));
            }
            current_widget->outline->outline_width_inherit = true;
        }
    }
    else{
        if (current_widget->outline == NULL){
            current_widget->outline = malloc(sizeof(struct outline));
        }
        if (current_widget->outline_inherit){
            current_widget->outline->outline_offset_inherit = true;
            current_widget->outline->outline_color_inherit = true;
            current_widget->outline->outline_style_inherit = true;
            current_widget->outline_inherit = false;
        }
        current_widget->outline->outline_width_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->outline->outlineWidth = CSS_OUTLINE_WIDTH_TYPE_MEDIUM;
        }
        else{
            set_outline_color(current_widget->outline, value);
        }
    }
}

void compute_inherit_outline(struct css_properties* dest, struct css_properties* source){
    if (dest->outline_inherit){
        dest->outline = source->outline;
    }
    else if(dest->outline != NULL && source->outline != NULL){
        if (dest->outline->outline_width_inherit){
            dest->outline->outlineWidth = source->outline->outlineWidth;
        }
        if (dest->outline->outline_offset_inherit){
            dest->outline->offset = source->outline->offset;
        }
        if (dest->outline->outline_color_inherit){
            dest->outline->colorRgba = source->outline->colorRgba;
        }
        if (dest->outline->outline_style_inherit){
            dest->outline->outlineStyleType = source->outline->outlineStyleType;
        }
    }
}

void free_outline(struct css_properties* current_widget){
    free(current_widget->outline->colorRgba);
    free(current_widget->outline);
}

void update_outline(struct css_properties* current_widget, struct css_properties* source){
    if(source->outline_inherit){
        current_widget->outline_inherit = true;
        current_widget->outline = NULL;
    }
    else if (source->outline != NULL){
        current_widget->outline = source->outline;
    }
}