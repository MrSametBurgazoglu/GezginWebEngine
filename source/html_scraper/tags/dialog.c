//
// Created by samet on 5.04.2022.
//

#include <malloc.h>
#include "dialog.h"

void choose_context_for_dialog_tag(struct widget* current_widget, char* context){
    struct dialog* widget_properties = current_widget->widget_properties;
    if(!strcmp(context, "open")){
        widget_properties->open = true;
    }
}

void set_widget_properties_for_dialog_tag(struct widget* current_widget){
    current_widget->context_reader_func = choose_context_for_dialog_tag;
    current_widget->widget_properties = malloc(sizeof(struct dialog));
}