//
// Created by samet on 23.04.2022.
//

#include "background.h"
#include <stdlib.h> 
#include <string.h>
#include "../../functools/index_founder.h"

#define BACKGROUND_BLEND_MODE_COUNT 10
#define BACKGROUND_REPEAT_TYPE_COUNT 6
#define BACKGROUND_ORIGIN_TYPE_COUNT 3
#define BACKGROUND_CLIP_TYPE_COUNT 3
#define BACKGROUND_ATTACHMENT_TYPE_COUNT 3

char* background_blend_mode_strings[BACKGROUND_BLEND_MODE_COUNT] = {
    "color",
    "color-dodge",
    "darken",
    "lighten",
    "luminosity",
    "multiply",
    "normal",
    "overlay",
    "saturation",
    "screen",
};

char* background_repeat_strings[BACKGROUND_REPEAT_TYPE_COUNT] = {
        "no-repeat",
        "repeat",
        "repeat-x",
        "repeat-y",
        "round",
        "space",
};

char* background_origin_strings[BACKGROUND_ORIGIN_TYPE_COUNT] = {
        "border-box",
        "content-box",
        "padding-box",
};

char* background_attachment_strings[BACKGROUND_ATTACHMENT_TYPE_COUNT] = {
        "fixed",
        "local",
        "scroll",
};

css_background_blend_mode backgroundBlendModeList[BACKGROUND_BLEND_MODE_COUNT] = {
        CSS_BACKGROUND_BLEND_MODE_COLOR,
        CSS_BACKGROUND_BLEND_MODE_COLOR_DODGE,
        CSS_BACKGROUND_BLEND_MODE_DARKEN,
        CSS_BACKGROUND_BLEND_MODE_LIGHTEN,
        CSS_BACKGROUND_BLEND_MODE_LUMINOSITY,
        CSS_BACKGROUND_BLEND_MODE_MULTIPLY,
        CSS_BACKGROUND_BLEND_MODE_NORMAL,
        CSS_BACKGROUND_BLEND_MODE_OVERLAY,
        CSS_BACKGROUND_BLEND_MODE_SATURATION,
        CSS_BACKGROUND_BLEND_MODE_SCREEN,
};

css_background_repeat_type backgroundRepeatTypeList[BACKGROUND_REPEAT_TYPE_COUNT] = {
        CSS_BACKGROUND_REPEAT_TYPE_NO_REPEAT,
        CSS_BACKGROUND_REPEAT_TYPE_REPEAT,
        CSS_BACKGROUND_REPEAT_TYPE_REPEAT_X,
        CSS_BACKGROUND_REPEAT_TYPE_REPEAT_Y,
        CSS_BACKGROUND_REPEAT_TYPE_ROUND,
        CSS_BACKGROUND_REPEAT_TYPE_SPACE,
};

css_background_origin backgroundOriginList[BACKGROUND_ORIGIN_TYPE_COUNT] = {
        CSS_BACKGROUND_ORIGIN_BORDER_BOX,
        CSS_BACKGROUND_ORIGIN_CONTENT_BOX,
        CSS_BACKGROUND_ORIGIN_PADDING_BOX,
};

css_background_clip backgroundClipList[BACKGROUND_CLIP_TYPE_COUNT] = {
        CSS_BACKGROUND_CLIP_BORDER_BOX,
        CSS_BACKGROUND_CLIP_CONTENT_BOX,
        CSS_BACKGROUND_CLIP_PADDING_BOX,
};

css_background_attachment backgroundAttachmentList[BACKGROUND_ATTACHMENT_TYPE_COUNT] = {
        CSS_BACKGROUND_ATTACHMENT_FIXED,
        CSS_BACKGROUND_ATTACHMENT_LOCAL,
        CSS_BACKGROUND_ATTACHMENT_SCROLL,
};

void set_background_blend_mode(struct css_background* background, char* value){
    int index = get_index_from_list_by_string(background_blend_mode_strings, value, BACKGROUND_BLEND_MODE_COUNT);
    if (index != -1){
        background->backgroundBlendMode = backgroundBlendModeList[index];
    }
    else{
        background->backgroundBlendMode = CSS_BACKGROUND_BLEND_MODE_NORMAL;
    }

}

void set_background_color(struct css_background* background, char* value){
    get_color(background->background_color, value);
}

void set_background_image_color(struct css_background_image_color** background_image_color_list, char* value){
    if(background_image_color_list == NULL){
        background_image_color_list = malloc(sizeof(struct css_background_image_color*) * 3);
        background_image_color_list[0] = malloc(sizeof(struct css_background_image_color));
        background_image_color_list[1] = malloc(sizeof(struct css_background_image_color));
        background_image_color_list[2] = malloc(sizeof(struct css_background_image_color));
    }
    char *value2 = strtok(value, ",");
    int index2 = 0;//must be maximum 3
    while (value2 != NULL){
        char* color = strtok(value2, " ");
        if (color == NULL){
            get_color(background_image_color_list[index2]->color, color);
        }
        else{
            char* percent = strtok(NULL, " ");
            background_image_color_list[index2]->percent = (int) strtol(percent, NULL, 10);
        }
        index2++;
        if(index2 == 3){
            break;
        }
        value2 = strtok(NULL, ",");
    }
}

//TODO OPTIMIZE THIS FUNCTION
void set_background_image(struct css_background* background,char * value){
    char* start_index = strchr(value, '(');
    char* end_index = strchr(value, ')');
    if (start_index != NULL && end_index != NULL) {
        size_t len = value - start_index;
        char *function_name = malloc(len + 1);
        memcpy(function_name, value, len);
        function_name[len] = '\0';
        if (!strcmp(function_name, "url")) {
            start_index = strchr(value, '\"');
            end_index = strchr(value, '\"');
            len = end_index - start_index;
            char * text = malloc(len + 1);
            memcpy(text, start_index, len);
            text[len] = '\0';
            background->background_image_list[++background->background_image_count] = text;
        }
        else if(!strcmp(function_name, "conic-gradient")){
            len = end_index - start_index;
            char * text = malloc(len + 1);
            memcpy(text, start_index, len);
            text[len] = '\0';
            set_background_image_color(background->background_image_color_list, text);
            background->background_type = CSS_BACKGROUND_TYPE_CONIC_GRADIENT;
        }
        else if(!strcmp(function_name, "linear-gradient")){
            len = end_index - start_index;
            char * text = malloc(len + 1);
            memcpy(text, start_index, len);
            text[len] = '\0';
            set_background_image_color(background->background_image_color_list, text);
            background->background_type = CSS_BACKGROUND_TYPE_LINEAR_GRADIENT;
        }
        else if(!strcmp(function_name, "radial-gradient")){
            len = end_index - start_index;
            char * text = malloc(len + 1);
            memcpy(text, start_index, len);
            text[len] = '\0';
            set_background_image_color(background->background_image_color_list, text);
            background->background_type = CSS_BACKGROUND_TYPE_RADIAL_GRADIENT;
        }
        else if(!strcmp(function_name, "repeating-conic-gradient")){
            len = end_index - start_index;
            char * text = malloc(len + 1);
            memcpy(text, start_index, len);
            text[len] = '\0';
            set_background_image_color(background->background_image_color_list, text);
            background->background_type = CSS_BACKGROUND_TYPE_REPEATING_CONIC_GRADIENT;
        }
        else if(!strcmp(function_name, "repeating-linear-gradient")){
            len = end_index - start_index;
            char * text = malloc(len + 1);
            memcpy(text, start_index, len);
            text[len] = '\0';
            set_background_image_color(background->background_image_color_list, text);
            background->background_type = CSS_BACKGROUND_TYPE_REPEATING_LINEAR_GRADIENT;
        }
        else if(!strcmp(function_name, "repeating-radial-gradient")){
            len = end_index - start_index;
            char * text = malloc(len + 1);
            memcpy(text, start_index, len);
            text[len] = '\0';
            set_background_image_color(background->background_image_color_list, text);
            background->background_type = CSS_BACKGROUND_TYPE_REPEATING_RADIAL_GRADIENT;
        }
    }
}

void set_background_position(struct css_background_position* backgroundPosition, char* value){
    char* first_position = strtok(value, " ");
    if (first_position != NULL){
        backgroundPosition->positionType = CSS_BACKGROUND_POSITION_TYPE_WORD;
        char* second_position = strtok(NULL, " ");
        if(!strcmp(first_position, "center")){
            backgroundPosition->value2 = 2;
            if (second_position == NULL || !strcmp(second_position, "center")){
                backgroundPosition->value2 = 1;
            }
            else if(!strcmp(second_position, "top")){
                backgroundPosition->value2 = 0;
            }
            else if(!strcmp(first_position, "bottom")){
                backgroundPosition->value2 = 2;
            }
        }
        else if(!strcmp(first_position, "right")){
            backgroundPosition->value1 = 1;
            if(!strcmp(second_position, "top")){
                backgroundPosition->value2 = 0;
            }
            else if(!strcmp(first_position, "center")){
                backgroundPosition->value2 = 1;
            }
            else if(!strcmp(first_position, "bottom")){
                backgroundPosition->value2 = 2;
            }
        }
        else if (!strcmp(first_position, "left")){
            backgroundPosition->value1 = 0;
            if(!strcmp(second_position, "top")){
                backgroundPosition->value2 = 0;
            }
            else if(!strcmp(first_position, "center")){
                backgroundPosition->value2 = 1;
            }
            else if(!strcmp(first_position, "bottom")){
                backgroundPosition->value2 = 2;
            }
        }
        else{
            char* end_ptr;
            char* end_ptr2;
            int first_value = (int) strtol(first_position, &end_ptr, 10);
            int second_value = (int) strtol(second_position, &end_ptr2, 10);
            backgroundPosition->value1 = first_value;
            backgroundPosition->value2 = second_value;
            if (!strcmp(end_ptr, "%")){
                backgroundPosition->positionType = CSS_BACKGROUND_POSITION_TYPE_PERCENT;
            }
            else{//DEFAULT VALUE
                backgroundPosition->positionType = CSS_BACKGROUND_POSITION_TYPE_POS;
            }
        }
    }
}

void set_background_size(struct css_background_size* cssBackgroundSize, char* value){
    char* first_size = strtok(value, " ");
    if (first_size == NULL){//if only one value
        if (!strcmp(first_size, "auto")){
            cssBackgroundSize->backgroundSizeType1 = CSS_BACKGROUND_SIZE_TYPE_AUTO;
            cssBackgroundSize->backgroundSizeType2 = CSS_BACKGROUND_SIZE_TYPE_AUTO;
        }
        else if(!strcmp(first_size, "contain")){
            cssBackgroundSize->backgroundSizeType1 = CSS_BACKGROUND_SIZE_TYPE_CONTAIN;
        }
        else if(!strcmp(first_size, "cover")){
            cssBackgroundSize->backgroundSizeType1 = CSS_BACKGROUND_SIZE_TYPE_COVER;
        }
    }
    else{//if 2 value
        char* second_size = strtok(NULL, " ");
        if (!strcmp(first_size, "auto")){// first one is auto
            cssBackgroundSize->backgroundSizeType1 = CSS_BACKGROUND_SIZE_TYPE_AUTO;
            if(!strcmp(second_size, "auto")){// both of them is auto
                cssBackgroundSize->backgroundSizeType2 = CSS_BACKGROUND_SIZE_TYPE_AUTO;
            }
            else{//only first one is auto
                char* end_ptr;
                cssBackgroundSize->value2 = (int) strtol(second_size, &end_ptr, 10);
                if (!strcmp(end_ptr, "%")){
                    cssBackgroundSize->backgroundSizeType2 = CSS_BACKGROUND_SIZE_TYPE_PERCENTAGE;
                }
                else{
                    cssBackgroundSize->backgroundSizeType2 = CSS_BACKGROUND_SIZE_TYPE_LENGTH;
                }
            }
        }
        else{//we know first one is integer value
            char* end_ptr;
            cssBackgroundSize->value1 = (int) strtol(first_size, &end_ptr, 10);
            if (!strcmp(end_ptr, "%")){
                cssBackgroundSize->backgroundSizeType1 = CSS_BACKGROUND_SIZE_TYPE_PERCENTAGE;
            }
            else{
                cssBackgroundSize->backgroundSizeType1 = CSS_BACKGROUND_SIZE_TYPE_LENGTH;
            }
            if(!strcmp(second_size, "auto")){// if second one is auto
                cssBackgroundSize->backgroundSizeType2 = CSS_BACKGROUND_SIZE_TYPE_AUTO;
            }
            else{//if also second one is integer value
                cssBackgroundSize->value2 = (int) strtol(second_size, &end_ptr, 10);
                if (!strcmp(end_ptr, "%")){
                    cssBackgroundSize->backgroundSizeType2 = CSS_BACKGROUND_SIZE_TYPE_PERCENTAGE;
                }
                else{
                    cssBackgroundSize->backgroundSizeType2 = CSS_BACKGROUND_SIZE_TYPE_LENGTH;
                }
            }
        }
    }
}

void set_background_repeat_property(struct css_background* background, char* value){
    int index = get_index_from_list_by_string(background_repeat_strings, value, BACKGROUND_BLEND_MODE_COUNT);
    if (index != -1){
        background->backgroundRepeatType = backgroundRepeatTypeList[index];
    }
    else{
        background->backgroundRepeatType = CSS_BACKGROUND_REPEAT_TYPE_NO_REPEAT;
    }

}

void set_background_origin_property(struct css_background* background, char* value){
    int index = get_index_from_list_by_string(background_origin_strings, value, BACKGROUND_ORIGIN_TYPE_COUNT);
    if (index != -1) {
        background->backgroundOrigin = backgroundOriginList[index];
    }
    else{
        background->backgroundOrigin = CSS_BACKGROUND_ORIGIN_PADDING_BOX;
    }
}

void set_background_clip_property(struct css_background* background, char* value){//origin strings because same
    int index = get_index_from_list_by_string(background_origin_strings, value, BACKGROUND_CLIP_TYPE_COUNT);
    if (index != -1) {
        background->backgroundClip = backgroundClipList[index];
    }
    else{
        background->backgroundClip = CSS_BACKGROUND_CLIP_BORDER_BOX;
    }
}

void set_background_attachment_property(struct css_background* background, char* value){//origin strings because same
    int index = get_index_from_list_by_string(background_attachment_strings, value, BACKGROUND_ATTACHMENT_TYPE_COUNT);
    if (index != -1) {
        background->backgroundAttachment = backgroundAttachmentList[index];
    }
    else{
        background->backgroundAttachment = CSS_BACKGROUND_ATTACHMENT_SCROLL;
    }
}

void set_background(struct css_background* background, char* value){//TODO IMPLEMENT THIS
    const char* delim = " ";
    char* value2;
    value2 = strtok(NULL, delim);//animation duration
    if(value2 != NULL){
        set_background_color(background, value2);
        value2 = strtok(NULL, delim);
        if (value2 != NULL){
            set_background_image(background, value2);
            value2 = strtok(NULL, delim);
            if(value2 != NULL){// get position and get size if given
                /*
                char* value3;
                value3 = strtok(value2, "/");
                if (value3 == NULL){
                    background_position_property_set_value(current_widget, value2);
                }
                else{
                    background_position_property_set_value(current_widget, value3);
                    value3 = strtok(NULL, "/");
                    background_size_property_set_value(current_widget, value3);
                }
                */
            }
        }
    }
}

void background_blend_mode_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->background == NULL){
        current_widget->background = malloc(sizeof(struct css_background));
    }
    set_background_blend_mode(current_widget->background, value);
}

void background_color_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->background_inherit){
            if (current_widget->background == NULL){
                current_widget->background = malloc(sizeof(struct css_background));
            }
            current_widget->background->background_color_inherit = true;
        }
    }
    else{
        if (current_widget->background == NULL){
            current_widget->background = malloc(sizeof(struct css_background));
        }
        if (current_widget->background_inherit){
            current_widget->background = malloc(sizeof(struct css_background));
            current_widget->background->background_size_inherit = true;
            current_widget->background->background_position_inherit = true;
            current_widget->background->background_origin_inherit = true;
            current_widget->background->background_image_inherit = true;
            current_widget->background->background_clip_inherit = true;
            current_widget->background->background_attachment_inherit = true;
            current_widget->background->background_repeat_inherit = true;
        }
        if (current_widget->background->background_color == NULL){
            current_widget->background->background_color = malloc(sizeof(struct color_rgba));
        }
        current_widget->background->background_color_inherit = false;
        if (!strcmp(value, "initial")){
            get_color_by_rgba(current_widget->background->background_color, 0, 0, 0, 0);//transparent
        }
        else{
            set_background_color(current_widget->background, value);
        }
    }
}


void background_image_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->background_inherit){
            if (current_widget->background == NULL){
                current_widget->background = malloc(sizeof(struct css_background));
            }
            current_widget->background->background_image_inherit = true;
        }
    }
    else{
        if (current_widget->background == NULL){
            current_widget->background = malloc(sizeof(struct css_background));
        }
        if (current_widget->background_inherit){
            current_widget->background = malloc(sizeof(struct css_background));
            current_widget->background->background_size_inherit = true;
            current_widget->background->background_position_inherit = true;
            current_widget->background->background_origin_inherit = true;
            current_widget->background->background_color_inherit = true;
            current_widget->background->background_clip_inherit = true;
            current_widget->background->background_attachment_inherit = true;
            current_widget->background->background_repeat_inherit = true;
        }
        current_widget->background->background_image_inherit = false;
        if (strcmp(value, "initial") != 0){
            set_background_image(current_widget->background, value);
        }
    }
}

void background_position_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->background_inherit){
            if (current_widget->background == NULL){
                current_widget->background = malloc(sizeof(struct css_background));
            }
            current_widget->background->background_position_inherit = true;
        }
    }
    else{
        if (current_widget->background == NULL){
            current_widget->background = malloc(sizeof(struct css_background));
        }
        if (current_widget->background_inherit){
            current_widget->background = malloc(sizeof(struct css_background));
            current_widget->background->background_size_inherit = true;
            current_widget->background->background_color_inherit = true;
            current_widget->background->background_origin_inherit = true;
            current_widget->background->background_image_inherit = true;
            current_widget->background->background_clip_inherit = true;
            current_widget->background->background_attachment_inherit = true;
            current_widget->background->background_repeat_inherit = true;
        }
        current_widget->background->background_position_inherit = false;
        if (current_widget->background->backgroundPosition == NULL){
            current_widget->background->backgroundPosition = malloc(sizeof(struct css_background_position));
        }
        if(!strcmp(value, "initial")){
            current_widget->background->backgroundPosition->value1 = 0;
            current_widget->background->backgroundPosition->value2 = 0;
            current_widget->background->backgroundPosition->positionType = CSS_BACKGROUND_POSITION_TYPE_POS;
        }
        else{
            set_background_position(current_widget->background->backgroundPosition, value);
        }
        if (!strcmp(value, "initial")){
            get_color_by_rgba(current_widget->background->background_color, 0, 0, 0, 0);//transparent
        }
        else{
            set_background_color(current_widget->background, value);
        }
    }
}

void background_size_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->background_inherit){
            if (current_widget->background == NULL){
                current_widget->background = malloc(sizeof(struct css_background));
            }
            current_widget->background->background_size_inherit = true;
        }
    }
    else{
        if (current_widget->background == NULL){
            current_widget->background = malloc(sizeof(struct css_background));
        }
        if (current_widget->background_inherit){
            current_widget->background = malloc(sizeof(struct css_background));
            current_widget->background->background_position_inherit = true;
            current_widget->background->background_color_inherit = true;
            current_widget->background->background_origin_inherit = true;
            current_widget->background->background_image_inherit = true;
            current_widget->background->background_clip_inherit = true;
            current_widget->background->background_attachment_inherit = true;
            current_widget->background->background_repeat_inherit = true;
        }
        current_widget->background->background_size_inherit = false;
        if (current_widget->background->backgroundSize == NULL){
            current_widget->background->backgroundSize = malloc(sizeof(struct css_background_size));
        }
        if(!strcmp(value, "initial")){
            current_widget->background->backgroundSize->backgroundSizeType1 = CSS_BACKGROUND_SIZE_TYPE_AUTO;
            current_widget->background->backgroundSize->backgroundSizeType2 = CSS_BACKGROUND_SIZE_TYPE_AUTO;
        }
        else{
            set_background_size(current_widget->background->backgroundSize, value);
        }
    }
}

void background_repeat_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->background_inherit){
            if (current_widget->background == NULL){
                current_widget->background = malloc(sizeof(struct css_background));
            }
            current_widget->background->background_repeat_inherit = true;
        }
    }
    else{
        if (current_widget->background == NULL){
            current_widget->background = malloc(sizeof(struct css_background));
        }
        if (current_widget->background_inherit){
            current_widget->background = malloc(sizeof(struct css_background));
            current_widget->background->background_position_inherit = true;
            current_widget->background->background_color_inherit = true;
            current_widget->background->background_origin_inherit = true;
            current_widget->background->background_image_inherit = true;
            current_widget->background->background_clip_inherit = true;
            current_widget->background->background_attachment_inherit = true;
            current_widget->background->background_size_inherit = true;
        }
        current_widget->background->background_repeat_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->background->backgroundRepeatType = CSS_BACKGROUND_REPEAT_TYPE_REPEAT;
        }
        else{
            set_background_repeat_property(current_widget->background, value);
        }
    }
}

void background_origin_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->background_inherit){
            if (current_widget->background == NULL){
                current_widget->background = malloc(sizeof(struct css_background));
            }
            current_widget->background->background_origin_inherit = true;
        }
    }
    else{
        if (current_widget->background == NULL){
            current_widget->background = malloc(sizeof(struct css_background));
        }
        if (current_widget->background_inherit){
            current_widget->background = malloc(sizeof(struct css_background));
            current_widget->background->background_position_inherit = true;
            current_widget->background->background_color_inherit = true;
            current_widget->background->background_repeat_inherit = true;
            current_widget->background->background_image_inherit = true;
            current_widget->background->background_clip_inherit = true;
            current_widget->background->background_attachment_inherit = true;
            current_widget->background->background_size_inherit = true;
        }
        current_widget->background->background_origin_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->background->backgroundOrigin = CSS_BACKGROUND_ORIGIN_PADDING_BOX;
        }
        else{
            set_background_origin_property(current_widget->background, value);
        }
    }
}

void background_clip_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->background_inherit){
            if (current_widget->background == NULL){
                current_widget->background = malloc(sizeof(struct css_background));
            }
            current_widget->background->background_clip_inherit = true;
        }
    }
    else{
        if (current_widget->background == NULL){
            current_widget->background = malloc(sizeof(struct css_background));
        }
        if (current_widget->background_inherit){
            current_widget->background = malloc(sizeof(struct css_background));
            current_widget->background->background_position_inherit = true;
            current_widget->background->background_color_inherit = true;
            current_widget->background->background_repeat_inherit = true;
            current_widget->background->background_image_inherit = true;
            current_widget->background->background_origin_inherit = true;
            current_widget->background->background_attachment_inherit = true;
            current_widget->background->background_size_inherit = true;
        }
        current_widget->background->background_clip_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->background->backgroundClip = CSS_BACKGROUND_CLIP_BORDER_BOX;
        }
        else{
            set_background_clip_property(current_widget->background, value);
        }
    }
}

void background_attachment_property_set_value(struct css_properties* current_widget, char* value){
    if (!strcmp(value, "inherit")){
        if (!current_widget->background_inherit){
            if (current_widget->background == NULL){
                current_widget->background = malloc(sizeof(struct css_background));
            }
            current_widget->background->background_attachment_inherit = true;
        }
    }
    else{
        if (current_widget->background == NULL){
            current_widget->background = malloc(sizeof(struct css_background));
        }
        if (current_widget->background_inherit){
            current_widget->background = malloc(sizeof(struct css_background));
            current_widget->background->background_position_inherit = true;
            current_widget->background->background_color_inherit = true;
            current_widget->background->background_repeat_inherit = true;
            current_widget->background->background_image_inherit = true;
            current_widget->background->background_origin_inherit = true;
            current_widget->background->background_clip_inherit = true;
            current_widget->background->background_size_inherit = true;
        }
        current_widget->background->background_attachment_inherit = false;
        if(!strcmp(value, "initial")){
            current_widget->background->backgroundAttachment = CSS_BACKGROUND_ATTACHMENT_SCROLL;
        }
        else{
            set_background_attachment_property(current_widget->background, value);
        }
    }
}

//background must be in this sort: bg-color bg-image position(2 value)/bg-size bg-repeat bg-origin bg-clip bg-attachment
//TODO IMPLEMENT THIS FUNCTION'S INITIAL SECTION
void background_property_set_value(struct css_properties* current_widget, char * value){
    if (!strcmp(value, "inherit")){
        current_widget->background_inherit = true;
    }
    else{
        if(current_widget->background == NULL || current_widget->background_inherit){
            current_widget->background = malloc(sizeof(struct css_background));
        }
        current_widget->background_inherit = false;
        if (!strcmp(value, "initial")){
            //implement here
        }
        else{
            set_background(current_widget->background, value);
        }
    }
}

void compute_inherit_background(struct css_properties* dest, struct css_properties* source){
    if (dest->background_inherit){
        dest->background = source->background;
    }
    else if (dest->background != NULL && source->background != NULL){
        if (dest->background->background_attachment_inherit){
            dest->background->backgroundAttachment = source->background->backgroundAttachment;
        }
        if (dest->background->background_attachment_inherit){
            dest->background->backgroundAttachment = source->background->backgroundAttachment;
        }
        if (dest->background->background_clip_inherit){
            dest->background->backgroundClip = source->background->backgroundClip;
        }
        if (dest->background->background_color_inherit){
            dest->background->background_color= source->background->background_color;
        }
        if (dest->background->background_image_inherit){
            dest->background->background_image_list = source->background->background_image_list;
            dest->background->background_image_count = source->background->background_image_count;
        }
        if (dest->background->background_origin_inherit){
            dest->background->backgroundOrigin = source->background->backgroundOrigin;
        }
        if (dest->background->background_position_inherit){
            dest->background->backgroundPosition = source->background->backgroundPosition;
        }
        if (dest->background->background_repeat_inherit){
            dest->background->backgroundRepeatType = source->background->backgroundRepeatType;
        }
        if (dest->background->background_size_inherit){
            dest->background->backgroundSize = source->background->backgroundSize;
        }
    }
}

void free_background(struct css_properties* current_widget){
    free(current_widget->background->backgroundPosition);
    free(current_widget->background->background_color);
    for (int i = 0; i < current_widget->background->background_image_count; ++i) {
        free(current_widget->background->background_image_color_list[i]->color);
        free(current_widget->background->background_image_color_list[i]);
    }
    free(current_widget->background->background_image_color_list);
    free(current_widget->background->background_image_list);
}

void update_background(struct css_properties* current_widget, struct css_properties* source){
    if(source->background_inherit){
        current_widget->background_inherit = true;
        current_widget->background = NULL;
    }
    else if (source->background != NULL){
        current_widget->background = source->background;
    }
}