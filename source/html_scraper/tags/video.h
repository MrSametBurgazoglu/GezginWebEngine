//
// Created by samet on 8.04.2022.
//

#ifndef UNTITLED_VIDEO_H
#define UNTITLED_VIDEO_H

#include "../../widget.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void choose_context_for_video_tag(struct widget*, char*);

int choose_variable_for_video_tag(struct widget*, char*, char*);

void set_widget_properties_for_video_tag(struct widget*);

struct video{
    bool autoplay;
    bool controls;
    int height;
    int width;
    bool loop;
    bool muted;
    char* poster;
    preload_option preload;
    char* src;
};


#endif //UNTITLED_VIDEO_H
