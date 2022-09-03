//
// Created by samet on 29.08.2022.
//

#include "div_drawer.h"
#include "../../css_scraper/properties/background.h"
#include "../drawer_backend/background_drawer.h"
#include "../drawer_backend/draw_border.h"

void div_drawer_function(struct widget* div_widget, SDL_Renderer* renderer){
    if (div_widget->css_properties->display != CSS_DISPLAY_TYPE_NONE){
        if (div_widget->css_properties->background != NULL){
            draw_background(div_widget->css_properties, div_widget->draw_properties, renderer);
        }
        if (div_widget->css_properties->border != NULL){
            draw_border(div_widget->css_properties, div_widget->draw_properties);
        }
        for (int i = 0; i < div_widget->children_count; ++i) {
            div_widget->children[i]->draw_widget(div_widget->children[i], renderer);
        }
    }
}

void div_render_function(struct widget* div_widget, SDL_Renderer* renderer){
    //check background image if has background image set texture by background image
    if (div_widget->css_properties->display != CSS_DISPLAY_TYPE_NONE){
        if (div_widget->css_properties->background != NULL && div_widget->css_properties->background->background_image_count > 0){
            //render_background_image(div_widget->css_properties, div_widget->draw_properties, renderer);
        }
        for (int i = 0; i < div_widget->children_count; ++i) {
            div_widget->children[i]->render_widget(div_widget->children[i], renderer);
        }
    }
}