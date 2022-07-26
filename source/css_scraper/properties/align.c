//
// Created by samet on 26.05.2022.
//

#include <stdlib.h>
#include "string.h"
#include "../css_widget.h"
#include "align.h"
#include "../../functools/index_founder.h"

#define ALIGN_CONTENT_STRING_COUNT 8

char* align_content_strings[ALIGN_CONTENT_STRING_COUNT] = {
        "baseline",
        "center",
        "flex-end",
        "flex-start",
        "space-around",
        "space-between",
        "space-evenly",
        "stretch",
};

css_align cssAlignTypeList[ALIGN_CONTENT_STRING_COUNT] = {
        CSS_ALIGN_BASELINE,
        CSS_ALIGN_CENTER,
        CSS_ALIGN_FLEX_END,
        CSS_ALIGN_FLEX_START,
        CSS_ALIGN_SPACE_AROUND,
        CSS_ALIGN_SPACE_BETWEEN,
        CSS_ALIGN_SPACE_EVENLY,
        CSS_ALIGN_STRETCH,
};

void set_align_content(struct css_properties* current_css_widget, char* value){
    int index = get_index_from_list_by_string(align_content_strings, value, ALIGN_CONTENT_STRING_COUNT);
    if (index != -1){
        current_css_widget->align_content = cssAlignTypeList[index];
    }
    else{
        current_css_widget->align_content = CSS_ALIGN_STRETCH;
    }
}

void set_align_items(struct css_properties* current_css_widget, char* value){
    int index = get_index_from_list_by_string(align_content_strings, value, ALIGN_CONTENT_STRING_COUNT);
    if (index != -1){
        current_css_widget->align_items = cssAlignTypeList[index];
    }
    else{
        current_css_widget->align_items = CSS_ALIGN_STRETCH;
    }
}

void set_align_self(struct css_properties* current_css_widget, char* value){
    int index = get_index_from_list_by_string(align_content_strings, value, ALIGN_CONTENT_STRING_COUNT);
    if (index != -1){
        current_css_widget->align_self = cssAlignTypeList[index];
    }
    else{
        current_css_widget->align_self = CSS_ALIGN_STRETCH;
    }
}

void align_content_property_set_value(struct css_properties* current_css_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_css_widget->align_content_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_css_widget->align_content = CSS_ALIGN_STRETCH;
    }
    else{
        set_align_content(current_css_widget, value);
    }
}

void align_items_property_set_value(struct css_properties* current_css_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_css_widget->align_items_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_css_widget->align_items = CSS_ALIGN_STRETCH;
    }
    else{
        set_align_items(current_css_widget, value);
    }
}

void align_self_property_set_value(struct css_properties* current_css_widget, char* value){
    if(!strcmp(value, "inherit")){
        current_css_widget->align_self_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_css_widget->align_self = CSS_ALIGN_STRETCH;
    }
    else{
        set_align_self(current_css_widget, value);
    }
}