//
// Created by samet on 17.06.2022.
//

#ifndef UNTITLED_BACKGROUND_DRAWER_H
#define UNTITLED_BACKGROUND_DRAWER_H

#include "../../css_scraper/css_widget.h"
#include "../draw_properties.h"
#include "sdl_drawer.h"

void draw_background(struct css_properties*, struct draw_properties*, SDL_Renderer*);
void render_background_image(struct css_properties*, struct draw_properties*, SDL_Renderer*);

#endif //UNTITLED_BACKGROUND_DRAWER_H
