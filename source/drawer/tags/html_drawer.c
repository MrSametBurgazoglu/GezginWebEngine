//
// Created by samet on 05.06.2022.
//

#include "html_drawer.h"
#include "../../css_scraper/properties/background.h"
#include "../drawer_backend/background_drawer.h"
#include "../drawer_backend/draw_border.h"

void html_drawer_function(struct widget* html_widget, SDL_Renderer* renderer){
    if (html_widget->css_properties->display != CSS_DISPLAY_TYPE_NONE){
        if (html_widget->css_properties->background != NULL){
            draw_background(html_widget->css_properties, html_widget->draw_properties, renderer);
        }
        if (html_widget->css_properties->border != NULL){
            draw_border(html_widget->css_properties, html_widget->draw_properties);
        }
        for (int i = 0; i < html_widget->children_count; ++i) {
            html_widget->children[i]->draw_widget(html_widget->children[i], renderer);
        }
    }
}

void html_render_function(struct widget* html_widget, SDL_Renderer* renderer){
    //check background image if has background image set texture by background image
    if (html_widget->css_properties->display != CSS_DISPLAY_TYPE_NONE){
        if (html_widget->css_properties->background != NULL && html_widget->css_properties->background->background_image_count > 0){
            //render_background_image(html_widget->css_properties, html_widget->draw_properties, renderer);
        }
        for (int i = 0; i < html_widget->children_count; ++i) {
            html_widget->children[i]->render_widget(html_widget->children[i], renderer);
        }
    }
}