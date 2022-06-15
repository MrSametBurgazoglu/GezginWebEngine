//
// Created by samet on 7.04.2022.
//

#ifndef UNTITLED_IMG_H
#define UNTITLED_IMG_H

#include "../../widget.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void choose_context_for_img_tag(struct widget*, char*);

int choose_variable_for_img_tag(struct widget*, char*, char*);

void set_widget_properties_for_img_tag(struct widget*);

struct img{
    char* alt;
    cross_origin crossorgin;
    int height;
    int width;
    bool ismap;
    loading_type loading;
    char* longdesc;
    referrer_policy referrerpolicy;
    char* sizes; //TODO MAKE THIS VARIABLE
    char* src;
    char* src_set;
    char* usemap;
};

#endif //UNTITLED_IMG_H
