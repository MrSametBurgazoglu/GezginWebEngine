//
// Created by samet on 17.06.2022.
//

#include "background_drawer.h"
#include "../../css_scraper/properties/background.h"

void draw_background(struct css_properties* css_widget, struct draw_properties* draw_properties, SDL_Renderer* renderer){
    if (css_widget->background != NULL){
        printf("its not null\n");
    }
    if (css_widget->background != NULL && css_widget->background->background_image_count > 0) {
        SDL_RenderCopy(renderer, draw_properties->background_image, NULL,
                       &draw_properties->rect);
    }
    if (css_widget->background->background_color != NULL){
        printf("color not null\n");
        SDL_Rect rect;
        rect.x = 50;
        rect.y = 50;
        rect.w = 50;
        rect.h = 50;
        SDL_SetRenderDrawColor(renderer,
                               css_widget->background->background_color->red,
                               css_widget->background->background_color->green,
                               css_widget->background->background_color->blue,
                               css_widget->background->background_color->alpha);
        SDL_RenderFillRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }
}

void render_background_image(struct css_properties* css_widget, struct draw_properties* draw_properties, SDL_Renderer* renderer){
    /*
    int w, h;
    SDL_Texture* img;
    SDL_Rect* rect;
    char* image_path = css_widget->background->background_image_list[0];
    img = IMG_LoadTexture(renderer, image_path);
    SDL_QueryTexture(img, NULL, NULL, &w, &h);
    rect->w = w;
    rect->h = h;
    draw_properties->backgroundImage->background_image = img;
    draw_properties->backgroundImage->rect = rect;
     */
}