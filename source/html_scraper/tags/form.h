//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_FORM_H
#define UNTITLED_FORM_H

#include "../../widget.h"
#include <string.h>
#include <stdbool.h>

void choose_context_for_form_tag(struct widget*, char*);

int choose_variable_for_form_tag(struct widget*, char*, char*);

void set_widget_properties_for_form_tag(struct widget*);

struct form{
    char* accept_charset; // TODO could be enum variable
    char* action;
    bool autocomplete;
    form_enc_type enc_type;
    form_method method;
    char* name;
    bool novalidate;
    form_rel rel;
    form_target target;
};

#endif //UNTITLED_FORM_H
