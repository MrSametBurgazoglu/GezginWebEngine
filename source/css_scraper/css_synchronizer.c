//
// Created by samet on 18.08.2022.
//

#include "css_synchronizer.h"
#include "css_all_properties.h"


//TODO SPLIT THIS FUNCTION TO PROPERTIES
void compute_inherit_css_properties(struct css_properties* dest, struct css_properties* source){
    compute_inherit_accent_color(dest, source);
    compute_inherit_align(dest, source);
    compute_inherit_animation(dest, source);
    compute_inherit_backdrop_filter(dest, source);
    compute_inherit_backface_visibility(dest, source);
    compute_inherit_background(dest, source);
    compute_inherit_border(dest, source);
    compute_inherit_color(dest, source);
    compute_inherit_column(dest, source);
    compute_inherit_flex(dest, source);
    compute_inherit_font(dest, source);
    compute_inherit_height(dest, source);
    compute_inherit_margin(dest, source);
    compute_inherit_opacity(dest, source);
    compute_inherit_outline(dest, source);
    compute_inherit_overflow(dest, source);
    compute_inherit_padding(dest, source);
    compute_inherit_position(dest, source);
    compute_inherit_resize(dest, source);
    compute_inherit_text(dest, source);
    compute_inherit_visibility(dest, source);
    compute_inherit_width(dest, source);
}

void update_css_properties_by_another_css_properties(struct css_properties* dest, struct css_properties* source){
    update_accent_color(dest, source);
    update_align(dest, source);
    update_animation(dest, source);
    update_backdrop_filter(dest, source);
    update_backface_visibility(dest, source);
    update_background(dest, source);
    update_border(dest, source);
    update_color(dest, source);
    update_column(dest, source);
    update_flex(dest, source);
    update_font(dest, source);
    update_height(dest, source);
    update_margin(dest, source);
    update_opacity(dest, source);
    update_outline(dest, source);
    update_overflow(dest, source);
    update_padding(dest, source);
    update_position(dest, source);
    update_resize(dest, source);
    update_text(dest, source);
    update_visibility(dest, source);
    update_width(dest, source);
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
                    compute_inherit_css_properties(widget_list[current_index]->css_properties, widget_list[current_index]->parent->css_properties);
                }
            }
            else{
                if(widget_list[current_index]->children[widget_index_list[current_index]]->draw == true){
                    compute_inherit_css_properties(widget_list[current_index]->css_properties, widget_list[current_index]->parent->css_properties);
                }
                widget_index_list[current_index]++;
            }
        }
    }
}