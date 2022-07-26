//
// Created by samet on 25.04.2022.
//

#ifndef UNTITLED_CSS_TREE_H
#define UNTITLED_CSS_TREE_H

#include <stdbool.h>
#include "../widget.h"


struct css_properties_list_item{
    char* identifier1;
    html_tags identifier2;
    struct css_properties* css_widget;
};

void initialize_css_tree(void);
void add_new_link_to_list(const char *);
void add_new_tag_to_list(struct widget**);
int get_style_tag_list_size(void);
int get_link_tag_list_size(void);
struct widget* get_widget_from_style_tag_list_by_index(int index);
char * get_url_from_link_tag_list_by_index(int index);
struct css_properties* create_new_css_widget_by_id(char* id);
struct css_properties* create_new_css_widget_by_class(char* class_name);
struct css_properties* create_new_css_widget_by_element(char* tag);
struct css_properties* create_new_css_widget_by_element_and_class(char* tag, char* class_name);
struct css_properties* get_css_widget_by_id(char *id);
struct css_properties* get_css_widget_by_class(char *class_name);
struct css_properties* get_css_widget_by_element(html_tags tag);
struct css_properties* get_css_widget_by_element_and_class(html_tags tag, char* class_name);

#endif //UNTITLED_CSS_TREE_H
