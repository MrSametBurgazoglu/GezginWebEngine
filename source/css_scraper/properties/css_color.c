//
// Created by samet on 15.04.2022.
//

#include <malloc.h>
#include "css_color.h"
#include <string.h>
#include <stdlib.h>

char* predefined_color_name_list[] = {
        "black",
};

int predefined_color_value_list[][4] = {
        {255, 255, 255, 255},
};

void get_color_by_name(struct color_rgba* color_struct, char* name){
    if (strcmp(name, "red") == 0){
        color_struct->alpha = 255;
        color_struct->red = 255;
        color_struct->green = 0;
        color_struct->blue = 0;
    }
    else{// return default color
        color_struct->alpha = 255;
        color_struct->red = 0;
        color_struct->green = 0;
        color_struct->blue = 0;
    }
}

void get_color_by_rgb(struct color_rgba* color_struct, int red, int green, int blue){
    color_struct->alpha = 255;
    color_struct->red = red;
    color_struct->green = green;
    color_struct->blue = blue;
}

void get_color_by_rgba(struct color_rgba* color_struct, int alpha, int red, int green, int blue){
    color_struct->alpha = alpha;
    color_struct->red = red;
    color_struct->green = green;
    color_struct->blue = blue;
}

//TODO USE FORMULA TO TRANSFORM
void get_color_by_hsl(struct color_rgba* color_struct, int color, int gray, int lightness){
    color_struct->alpha = 0;
    color_struct->red = 0;
    color_struct->green = 0;
    color_struct->blue = 0;
}

void get_color_by_hsla(struct color_rgba* color_struct, int color, int gray, int lightness, int alpha){
    color_struct->alpha = alpha;
    color_struct->red = 0;
    color_struct->green = 0;
    color_struct->blue = 0;
}


//TODO MAKE TRANSFORM
//DON'T FORGET FIRST CHARACTER IS '#'
void get_color_by_hex(struct color_rgba* color_struct, char* value){
    struct color_rgba* new_color = (struct color_rgba*) malloc(sizeof(struct color_rgba));
    color_struct->alpha = 0;
    color_struct->red = 0;
    color_struct->green = 0;
    color_struct->blue = 0;
}

//TODO CHECK IS STRUCT NULL
void get_color(struct color_rgba* colorRgba, char* value){
    char* start_index = strchr(value, '(');
    char* end_index = strchr(value, ')');
    if (start_index != NULL && end_index != NULL){
        size_t len = end_index - start_index;
        size_t len2 = value - start_index;
        char* parameters = malloc(len + 1);
        char* function_name = malloc(len2 + 1);
        memcpy(parameters, start_index, len);
        memcpy(function_name, value, len2);
        parameters[len] = '\0';
        function_name[len2] = '\0';
        if(!strcmp(function_name, "rgb")){
            char* value2 = strtok(parameters, ",");
            int function_parameters[3];
            function_parameters[0] = (int) strtol(value2, NULL, 10);
            int index = 1;
            while ((value2 = strtok(NULL, ",")) != NULL && index < 3){
                function_parameters[index++] = (int) strtol(value2, NULL, 10);
            }
            get_color_by_rgb(colorRgba, function_parameters[0], function_parameters[1], function_parameters[2]);
        }
        else if(!strcmp(function_name, "rgba")){
            char* value2 = strtok(parameters, ",");
            int function_parameters[4];
            function_parameters[0] = (int) strtol(value2, NULL, 10);
            int index = 1;
            while ((value2 = strtok(NULL, ",")) != NULL && index < 4){
                function_parameters[index++] = (int) strtol(value2, NULL, 10);
            }
            get_color_by_rgba(colorRgba, function_parameters[0], function_parameters[1], function_parameters[2], function_parameters[3]);
        }
        else if(!strcmp(function_name, "hsl")){
            char* value2 = strtok(parameters, ",");
            int function_parameters[3];
            function_parameters[0] = (int) strtol(value2, NULL, 10);
            int index = 1;
            while ((value2 = strtok(NULL, ",")) != NULL && index < 3){
                function_parameters[index++] = (int) strtol(value2, NULL, 10);
            }
            get_color_by_hsl(colorRgba, function_parameters[0], function_parameters[1], function_parameters[2]);
        }
        else if(!strcmp(function_name, "hsla")){
            char* value2 = strtok(parameters, ",");
            int function_parameters[4];
            function_parameters[0] = (int) strtol(value2, NULL, 10);
            int index = 1;
            while ((value2 = strtok(NULL, ",")) != NULL && index < 4){
                function_parameters[index++] = (int) strtol(value2, NULL, 10);
            }
            get_color_by_hsla(colorRgba, function_parameters[0], function_parameters[1], function_parameters[2], function_parameters[3]);
        }
        else{
            return get_color_by_rgb(0, 0, 0);
        }
    }
    else if(start_index == NULL && end_index == NULL){
        if(value[0] == '#'){//TODO IS THIS NECESSARY?
            get_color_by_hex(colorRgba, value);
        }
    }
    else{//TODO this must be default value
        get_color_by_rgb(colorRgba, 0, 0, 0);
    }
}
//TODO CHECK COLOR STRUCT IS EMPTY HERE
void sync_color(struct color_rgba* source, struct color_rgba* dest){
    dest->alpha = source->alpha;
    dest->red = source->red;
    dest->green = source->green;
    dest->blue = source->blue;
}