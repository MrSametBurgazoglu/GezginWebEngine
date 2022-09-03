//
// Created by samet on 09.06.2022.
//

#include "untagged_text_drawer.h"
#include "../drawer_backend/draw_text.h"
#include "../../html_scraper/tags/html_untagged_text.h"
#include "../drawer_backend/sdl_drawer.h"
#include "../drawer_backend/calculate_dimensions.h"

//rect (x,y) must be defined by parent before draw or rendering

void untagged_text_drawer_function(struct widget* text_widget, SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, text_widget->draw_properties->text_texture, NULL, &text_widget->draw_properties->rect);
}


void untagged_text_render_function(struct widget* text_widget, SDL_Renderer* renderer){
    if (text_widget->draw_properties == NULL){
        text_widget->draw_properties = malloc(sizeof(struct draw_properties));
    }
    //else if (text_widget->draw_properties->text_texture != NULL) {
    //    SDL_DestroyTexture(text_widget->draw_properties->text_texture);
    //}
    struct text_untagged* properties = (struct text_untagged*) text_widget->widget_properties;
    struct css_properties* cssProperties = (struct css_properties*) text_widget->parent->css_properties;
    TTF_Font *font = TTF_OpenFont("../docs/fonts/Sans.ttf", 24);
    get_text_texture(renderer,
                     properties->value,
                     cssProperties->color,
                     font,
                     &text_widget->draw_properties->text_texture,
                     &text_widget->draw_properties->rect);
    text_widget->draw_properties->rect.x = calculate_x_pos_text_widget(text_widget);
    text_widget->draw_properties->rect.y = calculate_y_pos_text_widget(text_widget);
    printf("rectx:%d,recty:%d\n", text_widget->draw_properties->rect.x, text_widget->draw_properties->rect.y);
    printf("tag:%d\n", text_widget->parent->html_tag);
}