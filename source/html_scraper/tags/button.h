//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_BUTTON_H
#define UNTITLED_BUTTON_H


#include "../../widget.h"
#include <stdbool.h>
#include <string.h>

void choose_context_for_button_tag(struct widget*, char*);

int choose_variable_for_button_tag(struct widget*, char*, char*);

void set_widget_properties_for_button_tag(struct widget*);

struct button{
    bool auto_focus;
    bool disabled;
    bool formnovalidate;
    char* form;
    char* form_action;
    char* name;
    char* value;
    form_enc_type enc_type;
    form_method method;
    form_target target;
    button_type type;
};

#endif //UNTITLED_BUTTON_H
