//
// Created by samet on 8.04.2022.
//

#include <malloc.h>
#include "track.h"

int choose_variable_for_track_tag(struct widget* current_widget, char* var_name, char* var_value){
    struct track* widget_properties = current_widget->widget_properties;
    if(!strcmp(var_name, "kind")){
        if (!strcmp(var_value, "captions")){
            widget_properties->kind = TRACK_KIND_CAPTIONS;
        }
        else if (!strcmp(var_value, "chapters")){
            widget_properties->kind = TRACK_KIND_CHAPTERS;
        }
        else if (!strcmp(var_value, "descriptions")){
            widget_properties->kind = TRACK_KIND_DESCRIPTIONS;
        }
        else if (!strcmp(var_value, "metadata")){
            widget_properties->kind = TRACK_KIND_METADATA;
        }
        else if (!strcmp(var_value, "subtitles")){
            widget_properties->kind = TRACK_KIND_SUBTITLES;
        }
        return 1;
    }
    else if(!strcmp(var_name, "label")){
        widget_properties->label = var_value;
    }
    else if(!strcmp(var_name, "src")){
        widget_properties->src = var_value;
    }
    else if(!strcmp(var_name, "srclang")){
        widget_properties->srclang = var_value;
    }
    return 0;
}

void set_widget_properties_for_track_tag(struct widget* current_widget){
    current_widget->var_reader_func = choose_variable_for_track_tag;
    current_widget->widget_properties = malloc(sizeof(struct track));
}