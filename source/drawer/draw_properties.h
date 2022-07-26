//
// Created by samet on 06.06.2022.
//

#ifndef UNTITLED_DRAW_PROPERTIES_H
#define UNTITLED_DRAW_PROPERTIES_H

#include "drawer_backend/sdl_drawer.h"

struct draw_properties{
    SDL_Rect *rect;
    SDL_Texture *texture;
    TTF_Font *font;
    SDL_Color color;
};

#endif //UNTITLED_DRAW_PROPERTIES_H
