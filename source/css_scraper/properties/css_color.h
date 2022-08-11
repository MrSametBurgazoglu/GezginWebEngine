//
// Created by samet on 15.04.2022.
//

#ifndef UNTITLED_CSS_COLOR_H
#define UNTITLED_CSS_COLOR_H

#include <stdbool.h>

struct color_rgba{
    int alpha;
    int red;
    int green;
    int blue;
};

void get_color_by_name(struct color_rgba*, char*);

void get_color_by_rgb(struct color_rgba*, int, int, int);
void get_color_by_rgba(struct color_rgba*, int, int, int, int);

bool get_color(struct color_rgba*, char* value);

void sync_color(struct color_rgba* source, struct color_rgba* dest);

#endif //UNTITLED_CSS_COLOR_H
