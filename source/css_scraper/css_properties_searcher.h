//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_CSS_PROPERTIES_SEARCHER_H
#define UNTITLED_CSS_PROPERTIES_SEARCHER_H

#include "../css_scraper/css_widget.h"


struct css_property_function{
    void (*css_widget_property_function) (struct css_properties*, char* value);
};

int get_css_property_number(char*);

void set_css_property_by_number(int number, struct css_properties* current_widget, char * value);

#endif //UNTITLED_CSS_PROPERTIES_SEARCHER_H
