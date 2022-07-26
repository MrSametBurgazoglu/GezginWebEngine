//
// Created by samet on 05.06.2022.
//

#include "html_drawer.h"
#include "../../css_scraper/properties/background.h"

void html_drawer_function(struct widget* html_widget, void* renderer){

}

void html_render_function(struct widget* html_widget, void* renderer){
    //check background image if has background image set texture by background image
    if(html_widget->css_properties->background != NULL){
        struct css_background* background = html_widget->css_properties->background;
        if(background->background_image != NULL){
            //background texture
        }
    }

}