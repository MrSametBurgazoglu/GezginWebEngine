//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_BLOCKQUOTE_H
#define UNTITLED_BLOCKQUOTE_H


#include "../../widget.h"
#include <stdbool.h>
#include <string.h>

int choose_variable_for_blockquote_tag(struct widget*, char*, char*);

void set_widget_properties_for_blockquote_tag(struct widget*);

struct blockquote{
    char* cite;
};

#endif //UNTITLED_BLOCKQUOTE_H
