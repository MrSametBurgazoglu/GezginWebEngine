//
// Created by samet on 15.04.2022.
//

#ifndef UNTITLED_CSS_COLOR_H
#define UNTITLED_CSS_COLOR_H

struct color_rgba{
    int alpha;
    int red;
    int green;
    int blue;
};

//struct color_rgba* get_color_by_name(char*);

struct color_rgba* get_color_by_rgb(int, int, int);
struct color_rgba* get_color_by_rgba(int, int, int, int);

struct color_rgba* get_color(char* value);

#endif //UNTITLED_CSS_COLOR_H
