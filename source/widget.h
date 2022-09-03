//
// Created by samet on 11.04.2022.
//

#ifndef UNTITLED_WIDGET_H
#define UNTITLED_WIDGET_H

#include "html_scraper/tags/html_tag_variables.h"
#include "css_scraper/css_widget.h"
#include "drawer/draw_properties.h"

struct widget {
    int children_count;//total children count
    int child_index; // index of widget on parent's children list
    html_tags html_tag;
    void *widget_properties;//properties for unique to html tag
    struct standart_html_objects *html_variables;
    struct css_properties* css_properties;//css properties for this widget
    struct draw_properties* draw_properties;//required variables for drawing
    struct widget** children;
    struct widget* parent;
    int (*var_reader_func)(struct widget*, char*, char*);//reading html parameters use '=' for assigning
    void (*context_reader_func)(struct widget*, char*);//reading html parameters assign by parameter itself
    void (*render_widget) (struct widget*,  SDL_Renderer* renderer_source);//render function for preparing to draw
    void (*draw_widget) (struct widget*, SDL_Renderer* renderer_source);//draw rendering object to screen
    bool draw;// is this widget has drawing function
};

#endif //UNTITLED_WIDGET_H
