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

void set_background_blend_mode(struct css_properties* current_widget, char* value){
    int index = get_index_from_list_by_string(background_blend_mode_strings, value, BACKGROUND_BLEND_MODE_COUNT);
    current_widget->background->backgroundBlendMode = backgroundBlendModeList[index];
}

void set_background_color(struct css_properties* current_widget, char* value){
    current_widget->background->background_color = get_color(value);
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
            background_image_color_list[index2]->color = get_color(color);
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


void set_background_image(struct css_properties* current_widget,char * value){
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
            current_widget->background->background_image_list[++current_widget->background->background_image_count] = text;
        }
        else if(!strcmp(function_name, "conic-gradient")){
            len = end_index - start_index;
            char * text = malloc(len + 1);
            memcpy(text, start_index, len);
            text[len] = '\0';
            set_background_image_color(current_widget->background->background_image_color_list, text);
            current_widget->background->background_type = CSS_BACKGROUND_TYPE_CONIC_GRADIENT;
        }
        else if(!strcmp(function_name, "linear-gradient")){
            len = end_index - start_index;
            char * text = malloc(len + 1);
            memcpy(text, start_index, len);
            text[len] = '\0';
            set_background_image_color(current_widget->background->background_image_color_list, text);
            current_widget->background->background_type = CSS_BACKGROUND_TYPE_LINEAR_GRADIENT;
        }
        else if(!strcmp(function_name, "radial-gradient")){
            len = end_index - start_index;
            char * text = malloc(len + 1);
            memcpy(text, start_index, len);
            text[len] = '\0';
            set_background_image_color(current_widget->background->background_image_color_list, text);
            current_widget->background->background_type = CSS_BACKGROUND_TYPE_RADIAL_GRADIENT;
        }
        else if(!strcmp(function_name, "repeating-conic-gradient")){
            len = end_index - start_index;
            char * text = malloc(len + 1);
            memcpy(text, start_index, len);
            text[len] = '\0';
            set_background_image_color(current_widget->background->background_image_color_list, text);
            current_widget->background->background_type = CSS_BACKGROUND_TYPE_REPEATING_CONIC_GRADIENT;
        }
        else if(!strcmp(function_name, "repeating-linear-gradient")){
            len = end_index - start_index;
            char * text = malloc(len + 1);
            memcpy(text, start_index, len);
            text[len] = '\0';
            set_background_image_color(current_widget->background->background_image_color_list, text);
            current_widget->background->background_type = CSS_BACKGROUND_TYPE_REPEATING_LINEAR_GRADIENT;
        }
        else if(!strcmp(function_name, "repeating-radial-gradient")){
            len = end_index - start_index;
            char * text = malloc(len + 1);
            memcpy(text, start_index, len);
            text[len] = '\0';
            set_background_image_color(current_widget->background->background_image_color_list, text);
            current_widget->background->background_type = CSS_BACKGROUND_TYPE_REPEATING_RADIAL_GRADIENT;
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
    int index = get_index_from_list_by_string(background_blend_mode_strings, value, BACKGROUND_BLEND_MODE_COUNT);
    background->backgroundRepeatType = backgroundRepeatTypeList[index];
}

void set_background_origin_property(struct css_background* background, char* value){
    int index = get_index_from_list_by_string(background_origin_strings, value, BACKGROUND_ORIGIN_TYPE_COUNT);
    background->backgroundOrigin = backgroundOriginList[index];
}

void set_background_clip_property(struct css_background* background, char* value){//origin strings because same
    int index = get_index_from_list_by_string(background_origin_strings, value, BACKGROUND_CLIP_TYPE_COUNT);
    background->backgroundClip = backgroundClipList[index];
}

void set_background_attachment_property(struct css_background* background, char* value){//origin strings because same
    int index = get_index_from_list_by_string(background_attachment_strings, value, BACKGROUND_ATTACHMENT_TYPE_COUNT);
    background->backgroundAttachment = backgroundAttachmentList[index];
}

void background_blend_mode_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->background == NULL){
        current_widget->background = malloc(sizeof(struct css_background));
    }
    set_background_blend_mode(current_widget, value);
}

void background_color_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->background == NULL){
        current_widget->background = malloc(sizeof(struct css_background));
    }
    if (!strcmp(value, "initial")){
        current_widget->background->background_color = get_color_by_rgba(0, 0, 0, 0);//transparent
    }
    else if(!strcmp(value, "inherit")){
        current_widget->background->background_color_inherit = true;
    }
    else{
        set_background_color(current_widget, value);
    }
}


void background_image_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->background == NULL){
        current_widget->background = malloc(sizeof(struct css_background));
    }
    set_background_image(current_widget, value);
}

void background_position_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->background == NULL){
        current_widget->background = malloc(sizeof(struct css_background));
    }
    if (current_widget->background->backgroundPosition == NULL){
        current_widget->background->backgroundPosition = malloc(sizeof(struct css_background_position));
    }
    if (!strcmp(value, "inherit")){
        current_widget->background->background_position_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->background->backgroundPosition->value1 = 0;
        current_widget->background->backgroundPosition->value2 = 0;
        current_widget->background->backgroundPosition->positionType = CSS_BACKGROUND_POSITION_TYPE_POS;
    }
    set_background_position(current_widget->background->backgroundPosition, value);
}

void background_size_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->background == NULL){
        current_widget->background = malloc(sizeof(struct css_background));
    }
    if (current_widget->background->backgroundSize == NULL){
        current_widget->background->backgroundSize = malloc(sizeof(struct css_background_size));
    }
    set_background_size(current_widget->background->backgroundSize, value);

}

void background_repeat_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->background == NULL){
        current_widget->background = malloc(sizeof(struct css_background));
    }
    if (!strcmp(value, "inherit")){
        current_widget->background->background_repeat_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->background->backgroundRepeatType = CSS_BACKGROUND_REPEAT_TYPE_REPEAT;
    }
    else{
        set_background_repeat_property(current_widget->background, value);
    }
}

void background_origin_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->background == NULL){
        current_widget->background = malloc(sizeof(struct css_background));
    }
    if (!strcmp(value, "inherit")){
        current_widget->background->background_origin_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->background->backgroundOrigin = CSS_BACKGROUND_ORIGIN_PADDING_BOX;
    }
    else{
        set_background_origin_property(current_widget->background, value);
    }
}

void background_clip_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->background == NULL){
        current_widget->background = malloc(sizeof(struct css_background));
    }
    if (!strcmp(value, "inherit")){
        current_widget->background->background_clip_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->background->backgroundClip = CSS_BACKGROUND_CLIP_BORDER_BOX;
    }
    else{
        set_background_clip_property(current_widget->background, value);
    }

}

void background_attachment_property_set_value(struct css_properties* current_widget, char* value){
    if(current_widget->background == NULL){
        current_widget->background = malloc(sizeof(struct css_background));
    }
    if (!strcmp(value, "inherit")){
        current_widget->background->background_attachment_inherit = true;
    }
    else if(!strcmp(value, "initial")){
        current_widget->background->backgroundAttachment = CSS_BACKGROUND_ATTACHMENT_SCROLL;
    }
    else{
        set_background_attachment_property(current_widget->background, value);
    }

}

//background must be in this sort: bg-color bg-image position(2 value)/bg-size bg-repeat bg-origin bg-clip bg-attachment
void background_property_set_value(struct css_properties* current_widget, char * value){
    if(current_widget->background == NULL){
        current_widget->background = malloc(sizeof(struct css_background));
    }
    else if(!strcmp(value, "inherit")){
        current_widget->background_inherit = true;
    }
    else if(!strcmp(value, "initial")){

    }
    else{
        const char* delim = " ";
        char* value2;
        value2 = strtok(NULL, delim);//animation duration
        if(value2 != NULL){
            background_color_property_set_value(current_widget, value2);
            value2 = strtok(NULL, delim);
            if (value2 != NULL){
                background_image_property_set_value(current_widget, value2);
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
}