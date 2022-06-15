//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_AUDIO_H
#define UNTITLED_AUDIO_H

#include "../../widget.h"
#include <stdbool.h>

void choose_context_for_audio_tag(struct widget*, char*);

int choose_variable_for_audio_tag(struct widget*, char*, char*);

void set_widget_properties_for_audio_tag(struct widget*);

struct audio{
    bool autoplay;
    bool controls;
    bool loop;
    bool muted;
    preload_option preload;
    char *src;
};

#endif //UNTITLED_AUDIO_H
