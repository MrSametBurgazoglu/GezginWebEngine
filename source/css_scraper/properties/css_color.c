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

struct color_rgba* get_color_by_name(char* name){
    struct color_rgba* new_color = (struct color_rgba*) malloc(sizeof(struct color_rgba));
    if (strcmp(name, "red") == 0){
        new_color->alpha = 255;
        new_color->red = 255;
        new_color->green = 0;
        new_color->blue = 0;
    }
    else{// return default color
        new_color->alpha = 255;
        new_color->red = 0;
        new_color->green = 0;
        new_color->blue = 0;
    }
    return new_color;
}

struct color_rgba* get_color_by_rgb(int red, int green, int blue){
    struct color_rgba* new_color = (struct color_rgba*) malloc(sizeof(struct color_rgba));
    new_color->alpha = 255;
    new_color->red = red;
    new_color->green = green;
    new_color->blue = blue;
    return new_color;
}

struct color_rgba* get_color_by_rgba(int alpha, int red, int green, int blue){
    struct color_rgba* new_color = (struct color_rgba*) malloc(sizeof(struct color_rgba));
    new_color->alpha = alpha;
    new_color->red = red;
    new_color->green = green;
    new_color->blue = blue;
    return new_color;
}

//TODO USE FORMULA TO TRANSFORM
struct color_rgba* get_color_by_hsl(int color, int gray, int lightness){
    struct color_rgba* new_color = (struct color_rgba*) malloc(sizeof(struct color_rgba));
    new_color->alpha = 0;
    new_color->red = 0;
    new_color->green = 0;
    new_color->blue = 0;
    return new_color;
}

struct color_rgba* get_color_by_hsla(int color, int gray, int lightness, int alpha){
    struct color_rgba* new_color = (struct color_rgba*) malloc(sizeof(struct color_rgba));
    new_color->alpha = alpha;
    new_color->red = 0;
    new_color->green = 0;
    new_color->blue = 0;
    return new_color;
}


//TODO MAKE TRANSFORM
//DON'T FORGET FIRST CHARACTER IS '#'
struct color_rgba* get_color_by_hex(char* value){
    struct color_rgba* new_color = (struct color_rgba*) malloc(sizeof(struct color_rgba));
    new_color->alpha = 0;
    new_color->red = 0;
    new_color->green = 0;
    new_color->blue = 0;
    return new_color;
}

struct color_rgba* get_color(char* value){
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
            return get_color_by_rgb(function_parameters[0], function_parameters[1], function_parameters[2]);
        }
        else if(!strcmp(function_name, "rgba")){
            char* value2 = strtok(parameters, ",");
            int function_parameters[4];
            function_parameters[0] = (int) strtol(value2, NULL, 10);
            int index = 1;
            while ((value2 = strtok(NULL, ",")) != NULL && index < 4){
                function_parameters[index++] = (int) strtol(value2, NULL, 10);
            }
            return get_color_by_rgba(function_parameters[0], function_parameters[1], function_parameters[2], function_parameters[3]);
        }
        else if(!strcmp(function_name, "hsl")){
            char* value2 = strtok(parameters, ",");
            int function_parameters[3];
            function_parameters[0] = (int) strtol(value2, NULL, 10);
            int index = 1;
            while ((value2 = strtok(NULL, ",")) != NULL && index < 3){
                function_parameters[index++] = (int) strtol(value2, NULL, 10);
            }
            return get_color_by_hsl(function_parameters[0], function_parameters[1], function_parameters[2]);
        }
        else if(!strcmp(function_name, "hsla")){
            char* value2 = strtok(parameters, ",");
            int function_parameters[4];
            function_parameters[0] = (int) strtol(value2, NULL, 10);
            int index = 1;
            while ((value2 = strtok(NULL, ",")) != NULL && index < 4){
                function_parameters[index++] = (int) strtol(value2, NULL, 10);
            }
            return get_color_by_hsla(function_parameters[0], function_parameters[1], function_parameters[2], function_parameters[3]);
        }
        else{
            return get_color_by_rgb(0, 0, 0);
        }
    }
    else if(start_index == NULL && end_index == NULL){
        if(value[0] == '#'){//TODO IS THIS NECESSARY?
            return get_color_by_hex(value);
        }
    }
    else{//TODO this must be default value
        return get_color_by_rgb(0, 0, 0);
    }
}
