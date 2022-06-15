//
// Created by samet on 04.06.2022.
//

#include "draw_text.h"

void get_text_texture(SDL_Renderer *renderer, char *text, struct color_rgba* colorRgba,
                       TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect) {
    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {colorRgba->red, colorRgba->green, colorRgba->blue, colorRgba->alpha};

    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(*texture, NULL, NULL, &text_width, &text_height);
    SDL_FreeSurface(surface);
    //rect->x = x;
    //rect->y = y;
    rect->w = text_width + 10;
    rect->h = text_height + 10;
}