//
// Created by samet on 5.04.2022.
//

#include <malloc.h>
#include "audio.h"
#include <string.h>

void choose_context_for_audio_tag(struct widget* current_widget, char* context){
    struct audio* widget_properties = current_widget->widget_properties;
    if(!strcmp(context, "autoplay")){
        widget_properties->autoplay = true;
    }
    else if(!strcmp(context, "controls")){
        widget_properties->controls = true;
    }
    else if(!strcmp(context, "loop")){
        widget_properties->loop = true;
    }
    else if(!strcmp(context, "muted")){
        widget_properties->muted = true;
    }
}

int choose_variable_for_audio_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct audio* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "src")){
        widget_properties->src = var_value;
    }
    else if(!strcmp(var_name, "preload")){
        if(!strcmp(var_value, "auto")){
            widget_properties->preload = PRELOAD_AUTO;
        }
        else if(!strcmp(var_value, "metadata")){
            widget_properties->preload = PRELOAD_METADATA;
        }
        else if(!strcmp(var_value, "none")){
            widget_properties->preload = PRELOAD_NONE;
        }
        return 1;
    }
    return 0;
}

void set_widget_properties_for_audio_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_audio_tag;
    current_widget->context_reader_func = choose_context_for_audio_tag;
    current_widget->widget_properties = malloc(sizeof(struct audio));
}