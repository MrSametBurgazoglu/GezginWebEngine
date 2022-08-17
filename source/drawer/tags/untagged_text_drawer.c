//
// Created by samet on 09.06.2022.
//

#include "untagged_text_drawer.h"
#include "../drawer_backend/draw_text.h"
#include "../../html_scraper/tags/html_untagged_text.h"
#include "../drawer_backend/sdl_drawer.h"

//rect (x,y) must be defined by parent before draw or rendering

void untagged_text_drawer_function(struct widget* text_widget, void* renderer){
    SDL_RenderCopy(renderer, text_widget->draw_properties->texture, NULL, text_widget->draw_properties->rect);
    printf("TEXT RENDER COPY\n");
}


void untagged_text_render_function(struct widget* text_widget, SDL_Renderer* renderer){
    if (text_widget->draw_properties == NULL){
        text_widget->draw_properties = malloc(sizeof(struct draw_properties));
    }
    /*
    else if (text_widget->draw_properties->texture != NULL){
        SDL_DestroyTexture(text_widget->draw_properties->texture);
    }*/
    struct text_untagged* properties = (struct text_untagged*) text_widget->widget_properties;
    TTF_Font *font = TTF_OpenFont("../docs/fonts/Sans.ttf", 24);
    struct color_rgba* colorRgba = malloc(sizeof(struct color_rgba));
    colorRgba->red = 0;
    colorRgba->green = 0;
    colorRgba->blue = 0;
    colorRgba->alpha = 0;
    SDL_Rect* rect;
    /*
    get_text_texture(renderer,
                     properties->value,
                     colorRgba,
                     font,
                     &text_widget->draw_properties->texture,
                     rect);
                     */
}