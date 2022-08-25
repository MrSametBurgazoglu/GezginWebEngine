//
// Created by samet on 25.05.2022.
//

#ifndef UNTITLED_ACCENT_COLOR_H
#define UNTITLED_ACCENT_COLOR_H

void accent_color_property_set_value(struct css_properties*, char*);
void compute_inherit_accent_color(struct css_properties* dest, struct css_properties* source);
void update_accent_color(struct css_properties* dest, struct css_properties* source);
void free_accent_color(struct css_properties* current_widget);

#endif //UNTITLED_ACCENT_COLOR_H
