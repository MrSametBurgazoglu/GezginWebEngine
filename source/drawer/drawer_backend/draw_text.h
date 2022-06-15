//
// Created by samet on 04.06.2022.
//

#ifndef UNTITLED_DRAW_TEXT_H
#define UNTITLED_DRAW_TEXT_H

#include "sdl_drawer.h"
#include "../../css_scraper/properties/css_color.h"

//not implemented yet
void get_text_texture(SDL_Renderer *renderer, char *text, struct color_rgba* colorRgba,
                      TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect);

#endif //UNTITLED_DRAW_TEXT_H
