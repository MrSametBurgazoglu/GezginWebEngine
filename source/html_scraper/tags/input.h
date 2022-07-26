//
// Created by samet on 7.04.2022.
//

#ifndef UNTITLED_INPUT_H
#define UNTITLED_INPUT_H

#include "../../widget.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void choose_context_for_input_tag(struct widget*, char*);

int choose_variable_for_input_tag(struct widget*, char*, char*);

void set_widget_properties_for_input_tag(struct widget*);

struct input{
    char* accept;//TODO FIND ANOTHER WAY
    char* alt;
    bool autocomplete;
    bool autofocus;
    bool checked;
    char* dirname;
    bool disabled;
    char* form;
    char* formaction;
    form_enc_type enctype;
    form_method method;
    bool formnovalidate;
    form_target target;
    int height;
    int width;
    char* list;
    char* max;
    char* min;
    int max_length;
    int min_length;
    bool multiple;
    char* name;
    char* pattern;
    char* placeholder;
    bool readonly;
    bool required;
    int size;
    char* src;
    int step;
    input_type type;
    char* value;
};

#endif //UNTITLED_INPUT_H
