//
// Created by samet on 7.04.2022.
//

#ifndef UNTITLED_META_H
#define UNTITLED_META_H

#include "../../widget.h"
#include <string.h>

int choose_variable_for_meta_tag(struct widget*, char*, char*);

void set_widget_properties_for_meta_tag(struct widget*);

struct meta{
    char* charset;// DEFAULT UTF-8
    char* content;
    http_equiv equiv;
    meta_name name;

};

#endif //UNTITLED_META_H
