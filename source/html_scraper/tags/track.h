//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_TRACK_H
#define UNTITLED_TRACK_H

#include "../../widget.h"
#include <string.h>
#include <stdbool.h>

int choose_variable_for_track_tag(struct widget*, char*, char*);

void set_widget_properties_for_track_tag(struct widget*);

struct track{
    bool default_track;
    track_kind kind;
    char* label;
    char* src;
    char* srclang;
};

#endif //UNTITLED_TRACK_H
