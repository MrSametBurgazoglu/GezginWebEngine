//
// Created by samet on 18.08.2022.
//

#ifndef UNTITLED_CSS_SYNCHRONIZER_H
#define UNTITLED_CSS_SYNCHRONIZER_H

#include "../widget.h"

void compute_inherit_css_properties(struct css_properties* dest, struct css_properties* source);
void sync_all_html_tree(struct widget*);
void update_css_properties_by_another_css_properties(struct css_properties* dest, struct css_properties* source);

#endif //UNTITLED_CSS_SYNCHRONIZER_H
