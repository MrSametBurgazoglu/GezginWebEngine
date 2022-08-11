//
// Created by samet on 15.04.2022.
//


#include "css_color.h"
#include "css_color_names.h"
#include "../../functools/index_founder.h"

#include <string.h>
#include <stdlib.h>
#include <malloc.h>

void get_color_by_name(struct color_rgba* color_struct, char* name){
    int index = get_index_from_list_by_string(css_color_strings, name, CSS_COLOR_NAME_STRING_COUNT);
    if (index != -1){
        int* values = css_color_name_rgb[index];
        color_struct->alpha = 0;
        color_struct->red = values[0];
        color_struct->green = values[1];
        color_struct->blue = values[2];
    }
    else{
        color_struct->alpha = 0;
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

float HueToRGB(float v1, float v2, float vH)
{
    if (vH < 0)
        vH += 1;

    if (vH > 1)
        vH -= 1;

    if ((6 * vH) < 1)
        return (v1 + (v2 - v1) * 6 * vH);

    if ((2 * vH) < 1)
        return v2;

    if ((3 * vH) < 2)
        return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);

    return v1;
}

void get_color_by_hsl(struct color_rgba* color_struct, float H, float S, float L){
    if (S == 0)
    {
        color_struct->red = color_struct->green = color_struct->blue = (int)(L * 255);
    }
    else
    {
        float v1, v2;
        float hue = (float)H / 360;

        v2 = (L < 0.5) ? (L * (1 + S)) : ((L + S) - (L * S));
        v1 = 2 * L - v2;

        color_struct->red = (int) (255 * HueToRGB(v1, v2, hue + (1.0f / 3)));
        color_struct->green = (int)(255 * HueToRGB(v1, v2, hue));
        color_struct->blue = (int)(255 * HueToRGB(v1, v2, hue - (1.0f / 3)));
    }

}

void get_color_by_hsla(struct color_rgba* color_struct, float H, float S, float L, int alpha){
    color_struct->alpha = alpha;
    get_color_by_hsl(color_struct, H, S, L);
}


void get_color_by_hex(struct color_rgba* color_struct, char* value){
    struct color_rgba* new_color = (struct color_rgba*) malloc(sizeof(struct color_rgba));
    color_struct->alpha = 0;
    int r,g,b;
    sscanf(value, "%02x%02x%02x", &r, &g, &b);
    color_struct->red = r;
    color_struct->green = g;
    color_struct->blue = b;
}

bool get_color(struct color_rgba* colorRgba, char* value){
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
            float function_parameters[3];
            function_parameters[0] = (float ) strtof(value2, NULL);
            int index = 1;
            while ((value2 = strtok(NULL, ",")) != NULL && index < 3){
                function_parameters[index++] = (float) strtof(value2, NULL);
            }
            get_color_by_hsl(colorRgba, function_parameters[0], function_parameters[1], function_parameters[2]);
        }
        else if(!strcmp(function_name, "hsla")){
            char* value2 = strtok(parameters, ",");
            float function_parameters[4];
            function_parameters[0] = (float ) strtof(value2, NULL);
            int index = 1;
            while ((value2 = strtok(NULL, ",")) != NULL && index < 4){
                function_parameters[index++] = (float ) strtof(value2, NULL);
            }
            get_color_by_hsla(colorRgba, function_parameters[0], function_parameters[1], function_parameters[2], function_parameters[3]);
        }
        else{
            return false;
        }
    }
    else if(start_index == NULL && end_index == NULL){
        if(value[0] == '#'){
            get_color_by_hex(colorRgba, value);
        }
    }
    else{
        return false;
    }
    return true;
}

void sync_color(struct color_rgba* source, struct color_rgba* dest){
    dest->alpha = source->alpha;
    dest->red = source->red;
    dest->green = source->green;
    dest->blue = source->blue;
}