//
// Created by samet on 18.08.2022.
//

#include "css_synchronizer.h"

void sync_css_properties(struct css_properties* dest, struct css_properties* source){
    if(source->accent_color != NULL && dest->accent_color == NULL){
        dest->accent_color = source->accent_color;
    }
    if (dest->align_content_inherit == true){
        dest->align_content = source->align_content;
    }
    if (dest->align_items_inherit == true){
        dest->align_items = source->align_items;
    }
}

void sync_all_html_tree(struct widget* document){
    struct widget** widget_list = malloc(sizeof(struct widget*));
    int *widget_index_list = malloc(sizeof(int));
    widget_list[0] = document;
    widget_index_list[0] = 0;
    int current_index = 0;
    int widget_count = 1;
    while (widget_index_list[0] != document->children_count){
        if(widget_index_list[current_index] == widget_list[current_index]->children_count){
            current_index--;
            widget_count--;
            widget_list = realloc(widget_list, widget_count * sizeof(struct widget*));
            widget_index_list = realloc(widget_index_list, widget_count * sizeof(int ));
            widget_index_list[current_index]++;
        }
        else{
            if(widget_list[current_index]->children[widget_index_list[current_index]]->children_count > 0){
                widget_count++;
                widget_list = realloc(widget_list, widget_count * sizeof(struct widget*));
                widget_index_list = realloc(widget_index_list, widget_count * sizeof(int ));
                widget_list[widget_count-1] = widget_list[current_index]->children[widget_index_list[current_index]];
                widget_index_list[widget_count-1] = 0;
                current_index++;
                if(widget_list[current_index]->draw == true){
                    sync_css_properties(widget_list[current_index]->css_properties, widget_list[current_index]->parent->css_properties);
                }
            }
            else{
                if(widget_list[current_index]->children[widget_index_list[current_index]]->draw == true){
                    sync_css_properties(widget_list[current_index]->css_properties, widget_list[current_index]->parent->css_properties);
                }
                widget_index_list[current_index]++;
            }
        }
    }
}