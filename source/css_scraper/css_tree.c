//
// Created by samet on 25.04.2022.
//

#include "css_tree.h"
#include "../html_scraper/html_tag_searcher.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int css_properties_by_id_list_size;
int css_properties_by_class_list_size;
int css_properties_by_element_list_size;
int style_tag_list_size;
int style_link_list_size;
struct css_properties_list_item** cssWidgetByIDList;
struct css_properties_list_item** cssWidgetByClassList;
struct css_properties_list_item** cssWidgetByElementList;//by name of html tag
struct widget** style_tag_list;//css properties by html style tags
char** style_link_list;//links for css files

void initialize_css_tree(){
    style_link_list_size = 0;
    style_tag_list_size = 0;
    css_properties_by_id_list_size = 0;
    css_properties_by_class_list_size = 0;
    css_properties_by_element_list_size = 0;
    cssWidgetByIDList = malloc(0);
    cssWidgetByElementList = malloc(0);
    cssWidgetByClassList = malloc(0);
    style_tag_list = malloc(0);
    style_link_list = malloc(0);
}

void add_new_link_to_list(const char* link_address){
    style_link_list_size++;
    style_link_list = realloc(style_link_list, sizeof(char*) * style_link_list_size);
    *style_link_list[style_link_list_size-1] = *link_address;
}

void add_new_tag_to_list(struct widget** html_widget){
    style_tag_list_size++;
    style_tag_list = (struct widget**) realloc(style_tag_list, sizeof(struct widget*) * style_tag_list_size);
    style_tag_list[style_tag_list_size-1] = *html_widget;
}

struct css_properties* create_new_css_widget_by_id(char* id){
    css_properties_by_id_list_size++;
    cssWidgetByIDList = realloc(cssWidgetByIDList, sizeof(struct css_properties_list_item*) * css_properties_by_id_list_size);
    cssWidgetByIDList[css_properties_by_id_list_size-1] =  malloc(sizeof(struct css_properties_list_item));
    cssWidgetByIDList[css_properties_by_id_list_size-1]->identifier1 = id;
    cssWidgetByIDList[css_properties_by_id_list_size-1]->css_widget = malloc(sizeof(struct css_properties));
    return cssWidgetByIDList[css_properties_by_id_list_size-1]->css_widget;
}

struct css_properties* create_new_css_widget_by_class(char* class_name){
    css_properties_by_class_list_size++;
    cssWidgetByClassList = realloc(cssWidgetByClassList, sizeof(struct css_properties_list_item*) * css_properties_by_class_list_size);
    cssWidgetByClassList[css_properties_by_class_list_size-1] = malloc(sizeof(struct css_properties_list_item));
    cssWidgetByClassList[css_properties_by_class_list_size-1]->identifier1 = class_name;
    cssWidgetByClassList[css_properties_by_class_list_size-1]->css_widget = malloc(sizeof(struct css_properties));
    return cssWidgetByClassList[css_properties_by_class_list_size-1]->css_widget;
}

struct css_properties* create_new_css_widget_by_element(char* tag){
    html_tags element = get_html_tag_by_name(tag);
    css_properties_by_element_list_size++;
    cssWidgetByElementList = realloc(cssWidgetByElementList, sizeof(struct css_properties_list_item*) * css_properties_by_element_list_size);
    cssWidgetByElementList[css_properties_by_element_list_size-1] = malloc(sizeof(struct css_properties_list_item));
    cssWidgetByElementList[css_properties_by_element_list_size-1]->identifier2 = element;
    cssWidgetByElementList[css_properties_by_element_list_size-1]->css_widget = malloc(sizeof(struct css_properties));
    return cssWidgetByElementList[css_properties_by_element_list_size-1]->css_widget;
}

struct css_properties* create_new_css_widget_by_element_and_class(char* tag, char* class_name){
    html_tags element = get_html_tag_by_name(tag);
    css_properties_by_class_list_size++;
    cssWidgetByClassList = realloc(cssWidgetByClassList, sizeof(struct css_properties_list_item*) * css_properties_by_class_list_size);
    cssWidgetByClassList[css_properties_by_class_list_size-1] = malloc(sizeof(struct css_properties_list_item));
    cssWidgetByClassList[css_properties_by_class_list_size-1]->identifier1 = class_name;
    cssWidgetByClassList[css_properties_by_class_list_size-1]->identifier2 = element;
    cssWidgetByClassList[css_properties_by_class_list_size-1]->css_widget = malloc(sizeof(struct css_properties));
    return cssWidgetByClassList[css_properties_by_class_list_size-1]->css_widget;
}

struct css_properties* get_css_widget_by_id(char *id){
    for (int index = 0; index < css_properties_by_id_list_size; ++index) {
        if(strcmp(cssWidgetByIDList[index]->identifier1, id) == 0){
            return cssWidgetByIDList[index]->css_widget;
        }
    }
    return NULL;
}

struct css_properties* get_css_widget_by_class(char *class_name){
    for (int index = 0; index < css_properties_by_class_list_size; ++index) {
        if(strcmp(cssWidgetByClassList[index]->identifier1, class_name) == 0){
            return cssWidgetByClassList[index]->css_widget;
        }
    }
    return NULL;
}

struct css_properties* get_css_widget_by_element(html_tags tag){
    for (int index = 0; index < css_properties_by_element_list_size; ++index) {
        if(cssWidgetByElementList[index]->identifier2 == tag){
            return cssWidgetByElementList[index]->css_widget;
        }
    }
    return NULL;
}

struct css_properties* get_css_widget_by_element_and_class(html_tags tag, char* class_name){
    for (int index = 0; index < css_properties_by_class_list_size; ++index) {
        if(strcmp(cssWidgetByClassList[index]->identifier1, class_name) == 0 && cssWidgetByClassList[index]->identifier2 == tag){
            return cssWidgetByClassList[index]->css_widget;
        }
    }
    return NULL;
}

int get_style_tag_list_size(void){
    return style_tag_list_size;
}

int get_link_tag_list_size(void){
    return style_link_list_size;
}

struct widget* get_widget_from_style_tag_list_by_index(int index){
    return style_tag_list[index];
}
char* get_url_from_link_tag_list_by_index(int index){
    return style_link_list[index];
}