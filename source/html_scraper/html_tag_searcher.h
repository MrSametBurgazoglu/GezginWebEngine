//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_HTML_TAG_SEARCHER_H
#define UNTITLED_HTML_TAG_SEARCHER_H

#include "tags/html_tag_variables.h"
#include "html_tags.h"
#include "../widget.h"


struct html_tag_variables{
    html_tags tag;
    void (*widget_property_function) (struct widget*);//it's unique to html element some of them doesn't have this function
    void (*widget_draw_function) (struct widget*, SDL_Renderer*);//for drawing rendered object
    void (*widget_render_function) (struct widget*, SDL_Renderer*);//render element
    bool end_tag;//is this element need end tag. something like '</div>'
    bool draw;//is this function
};

bool set_html_tag(struct widget*, char*);// set html tag

html_tags get_html_tag_by_name(char *);

#endif //UNTITLED_HTML_TAG_SEARCHER_H
