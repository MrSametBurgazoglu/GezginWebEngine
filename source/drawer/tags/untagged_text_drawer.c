//
// Created by samet on 09.06.2022.
//

#include "untagged_text_drawer.h"
#include "../drawer_backend/draw_text.h"
#include "../../html_scraper/tags/html_untagged_text.h"

//rect (x,y) must be defined by parent before draw or rendering

void untagged_text_drawer_function(struct widget* text_widget, void* renderer){
    SDL_RenderCopy(renderer, text_widget->draw_properties->texture, NULL, text_widget->draw_properties->rect);
}


void untagged_text_render_function(struct widget* text_widget, struct widget* parent_widget, void* renderer){
    if (text_widget->draw_properties == NULL){
        text_widget->draw_properties = malloc(sizeof(struct draw_properties));
    }
    else if (text_widget->draw_properties->texture == NULL){
        SDL_DestroyTexture(text_widget->draw_properties->texture);
    }
    struct text_untagged* properties = (struct text_untagged*) text_widget->widget_properties;
    get_text_texture(renderer,
                     properties->value,
                     parent_widget->css_properties->color,
                     parent_widget->draw_properties->font,
                     &text_widget->draw_properties->texture,
                     text_widget->draw_properties->rect);
}