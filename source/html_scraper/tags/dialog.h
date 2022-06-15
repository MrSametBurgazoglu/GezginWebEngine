//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_DIALOG_H
#define UNTITLED_DIALOG_H

#include "../../widget.h"
#include <string.h>
#include <stdbool.h>

void choose_context_for_dialog_tag(struct widget*, char*);

void set_widget_properties_for_dialog_tag(struct widget*);

struct dialog{
    bool open;
};

#endif //UNTITLED_DIALOG_H
