//
// Created by samet on 18.05.2022.
//

#ifndef UNTITLED_COLOR_H
#define UNTITLED_COLOR_H

#include "../css_widget.h"

void color_property_set_value(struct css_properties* current_css_widget, char * value);
void compute_color(struct css_properties* dest, struct css_properties* source);
void free_color(struct css_properties*);

#endif //UNTITLED_COLOR_H
