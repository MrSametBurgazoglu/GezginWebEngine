//
// Created by samet on 23.04.2022.
//

#include "background.h"
#include <stdlib.h> 
#include <string.h>

void background_blend_mode_property_set_value(struct css_properties* current_widget,char * value){

}

void set_background_color(struct css_properties* current_widget, char* value){
    current_widget->background->background_color = get_color(value);
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
    }
}

void background_color_property_set_value(struct css_properties* current_widget,char * value){
    if(current_widget->background == NULL){
        current_widget->background = malloc(sizeof(struct css_background));
    }
    set_background_color(current_widget, value);
}


void background_image_property_set_value(struct css_properties* current_widget,char * value){
    if(current_widget->background == NULL){
        current_widget->background = malloc(sizeof(struct css_background));
    }
    //current_widget->background->
}

void background_position_property_set_value(struct css_properties* current_widget,char * value){

}

void background_size_property_set_value(struct css_properties* current_widget,char * value){

}

void background_repeat_property_set_value(struct css_properties* current_widget,char * value){

}

void background_origin_property_set_value(struct css_properties* current_widget,char * value){

}

void background_clip_property_set_value(struct css_properties* current_widget,char * value){

}

void background_attachment_property_set_value(struct css_properties* current_widget,char * value){

}

void background_property_set_value(struct css_properties* current_widget,char * value){

}