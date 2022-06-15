//
// Created by samet on 30.01.2022.
//

#ifndef UNTITLED_HTML_SCRAPER_H
#define UNTITLED_HTML_SCRAPER_H

#include "html_tags.h"


struct widget* scrape_html_from_file(char*);
void free_tree(struct widget*);
int choose_variable_for_standard_vars(struct widget*, char*, char*, int*);
int set_tag_context_for_standard_vars(struct  widget*, char*);


#endif //UNTITLED_HTML_SCRAPER_H
