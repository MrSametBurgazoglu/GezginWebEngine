//
// Created by samet on 26.08.2022.
//

#ifndef UNTITLED_CALCULATE_DIMENSIONS_H
#define UNTITLED_CALCULATE_DIMENSIONS_H

#include "../../widget.h"
#include "../draw_properties.h"

void set_browser_window_size(int width, int height);
int get_window_height();
int get_window_width();
int calculate_width_of_widget(struct widget*);
int calculate_height_of_widget(struct widget*);
int calculate_x_pos_of_widget(struct widget*);
int calculate_y_pos_of_widget(struct widget*);
int calculate_x_pos_text_widget(struct widget*);
int calculate_y_pos_text_widget(struct widget*);

#endif //UNTITLED_CALCULATE_DIMENSIONS_H
