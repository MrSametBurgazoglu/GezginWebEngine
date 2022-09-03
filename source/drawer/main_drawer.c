//
// Created by samet on 14.05.2022.
//

#include "main_drawer.h"
#include "drawer_backend/calculate_dimensions.h"

SDL_Surface *main_surface;
SDL_Texture *main_texture;

void initialize_drawer(int width, int height){
    //init_sdl_drawer();
    set_browser_window_size(width, height);
}

void render_document(struct widget* document, SDL_Renderer* renderer){
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
                    widget_list[current_index]->render_widget(widget_list[current_index], renderer);
                }
            }
            else{
                if(widget_list[current_index]->children[widget_index_list[current_index]]->draw == true){
                    widget_list[current_index]->render_widget(widget_list[current_index], renderer);
                }
                widget_index_list[current_index]++;
            }
        }
    }
    //for every widget, create rects and textures
}

//TODO MAKE UNTAGGED TEXT NOT DRAW, BUT RENDER THEIR TEXTURE IN SELF AND LET PARENT DRAW THEM
//Some widgets need render function because of create texture is a performance problem
void draw_document(struct widget* document, SDL_Renderer * renderer){
    //for every widget, use rects and textures
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
                    widget_list[current_index]->draw_widget(widget_list[current_index], renderer);
                }
            }
            else{
                if(widget_list[current_index]->children[widget_index_list[current_index]]->draw == true){
                    widget_list[current_index]->draw_widget(widget_list[current_index], renderer);
                }
                widget_index_list[current_index]++;
            }
        }
    }
}

void set_draw_properties_for_widget(struct widget* current_widget){
    int pos_x = calculate_x_pos_of_widget(current_widget);
    int pos_y = calculate_y_pos_of_widget(current_widget);
    int width = calculate_width_of_widget(current_widget);
    int height = calculate_height_of_widget(current_widget);
    current_widget->draw_properties->rect.x = pos_x;
    current_widget->draw_properties->rect.y = pos_y;
    current_widget->draw_properties->rect.w = width;
    current_widget->draw_properties->rect.h = height;
}

void set_draw_properties(struct widget* document){//TODO MAKE PARENT LAST
    struct widget** widget_list = malloc(sizeof(struct widget*));
    int *widget_index_list = malloc(sizeof(int));
    widget_list[0] = document;
    widget_index_list[0] = 0;
    int current_index = 0;
    int widget_count = 1;
    while (widget_index_list[0] != document->children_count){
        if(widget_index_list[current_index] == widget_list[current_index]->children_count){
            if(widget_list[current_index]->draw == true){
                set_draw_properties_for_widget(widget_list[current_index]);
            }
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
            }
            else{
                if(widget_list[current_index]->children[widget_index_list[current_index]]->draw == true){
                    set_draw_properties_for_widget(widget_list[current_index]->children[widget_index_list[current_index]]);
                }
                widget_index_list[current_index]++;
            }
        }
    }
}