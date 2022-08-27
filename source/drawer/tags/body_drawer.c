//
// Created by samet on 27.08.2022.
//

#include "body_drawer.h"
#include "../../css_scraper/properties/background.h"
#include "../drawer_backend/background_drawer.h"
#include "../drawer_backend/draw_border.h"

void body_drawer_function(struct widget* body_widget, SDL_Renderer* renderer){
    if (body_widget->css_properties->display != CSS_DISPLAY_TYPE_NONE){
        if (body_widget->css_properties->background != NULL){
            draw_background(body_widget->css_properties, body_widget->draw_properties, renderer);
        }
        if (body_widget->css_properties->border != NULL){
            draw_border(body_widget->css_properties, body_widget->draw_properties);
        }
        for (int i = 0; i < body_widget->children_count; ++i) {
            body_widget->children[i]->draw_widget(body_widget->children[i], renderer);
        }
    }
}

void body_render_function(struct widget* body_widget, SDL_Renderer* renderer){
    //check background image if has background image set texture by background image
    if (body_widget->css_properties->display != CSS_DISPLAY_TYPE_NONE){
        if (body_widget->css_properties->background != NULL && body_widget->css_properties->background->background_image_count > 0){
            //render_background_image(body_widget->css_properties, body_widget->draw_properties, renderer);
        }
        for (int i = 0; i < body_widget->children_count; ++i) {
            body_widget->children[i]->render_widget(body_widget->children[i], renderer);
        }
    }
}