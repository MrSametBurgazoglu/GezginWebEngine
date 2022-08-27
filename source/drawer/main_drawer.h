//
// Created by samet on 14.05.2022.
//

#ifndef UNTITLED_MAIN_DRAWER_H
#define UNTITLED_MAIN_DRAWER_H

#include "../widget.h"
#include "drawer_backend/sdl_drawer.h"
//#include "draw_properties.h"

void initialize_drawer(void *);
void render_document(struct widget*, SDL_Renderer*);
void draw_document(struct widget*, SDL_Renderer *);
void set_draw_properties(struct widget* document);

#endif //UNTITLED_MAIN_DRAWER_H
