//
// Created by samet on 06.06.2022.
//

#ifndef UNTITLED_DRAW_PROPERTIES_H
#define UNTITLED_DRAW_PROPERTIES_H

#include "drawer_backend/sdl_drawer.h"
#include "draw_structs.h"

//TODO MAYBE WE CAN MAKE SPECIAL TO ELEMENTS NEEDS

struct draw_properties{
    TTF_Font *font;//for text_drawer and child elements
    SDL_Rect rect;
    SDL_Texture *texture;//this will be removed
    struct background_image* backgroundImage;
    struct text_drawer* textDrawer;
};
/*
 * I don't know is this efficient
struct draw_properties_untagged_text{
    SDL_Rect *rect;
    SDL_Texture *texture;
};
*/

#endif //UNTITLED_DRAW_PROPERTIES_H
