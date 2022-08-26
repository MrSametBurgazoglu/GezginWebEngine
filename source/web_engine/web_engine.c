//
// Created by samet on 14.05.2022.
//

#include "../html_scraper/html_scraper.h"
#include "../css_scraper/css_scraper.h"
#include "../drawer/main_drawer.h"

struct widget* document;

void open_web_page(char* file_url){
    initialize_css_scraper();
    document = scrape_html_from_file(file_url);
    execute_css_scraper();
    scrape_css_from_document(document);
    set_inherit_css_widgets(document);
}

void draw_page(SDL_Renderer* renderer){
    draw_document(document, renderer);
}

void render_page(SDL_Renderer* renderer){
    render_document(document, renderer);
}

/*
void give_input(Input input){
    //make changes
}
*/
void exit_web_engine(void ){
    free_tree(document);
}