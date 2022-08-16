//
// Created by samet on 11.04.2022.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "css_scraper.h"
#include "css_properties_searcher.h"
#include "../html_scraper/tags/html_untagged_text.h"
#include "../html_scraper/html_tag_searcher.h"

//TODO we can set only first character to zero in memset functions when clear context
//TODO make clear function for every css tree

//init variables
void initialize_css_scraper(void){
    initialize_css_tree();
}

//TODO IMPLEMENT THIS FOR EVERY CSS PROPERTIES HAS INHERIT
void sync_css_properties(struct css_properties* dest, struct css_properties* source){
    if(source->accent_color != NULL){
        dest->accent_color = source->accent_color;
    }
}

//for element itself
void scrape_css_from_inline_style(struct css_properties* css_widget, char* text){
    char* current_character = text;
    char *context = malloc(128 * sizeof(char ));
    int current_count = 0;
    char* property;
    char* value;
    int property_number;
    do {
        if(*current_character != ' ' && *current_character != '\n' && *current_character != '\t'){//unimportant characters
            context[current_count++] = *current_character;
        }
        else if (*current_character == ':') {//property found
            property = malloc(current_count * sizeof(char )+1);
            property[current_count] = '\0';
            strncpy(property, context, current_count);
            memset(context, 0, current_count);
            property_number = get_css_property_number(property);
        }
        else if (*current_character == ';') {//property found
            value = malloc(current_count * sizeof(char )+1);
            value[current_count] = '\0';
            strncpy(value, context, current_count);
            memset(context, 0, current_count);
            set_css_property_by_number(property_number, css_widget, value);
        }
    }
    while (*current_character++ != '\0');

}
//TODO MAKE DOCUMENT CSS PROPERTIES BY INITIAL VALUES
void set_css_properties(struct widget* current_widget, struct widget* parent_widget){
    if(parent_widget->css_properties != NULL){
        sync_css_properties(current_widget->css_properties, parent_widget->css_properties);
    }
    size_t class_count = current_widget->html_variables->class_count;
    struct css_properties *current_css_properties;
    for (size_t index = 0; index < class_count; ++index) {
        char* class_name = current_widget->html_variables->class[index];
        current_css_properties = get_css_widget_by_class(class_name);
        if(current_css_properties != NULL){
            sync_css_properties(current_widget->css_properties, current_css_properties);
        }
        current_css_properties = get_css_widget_by_element_and_class(current_widget->html_tag, class_name);
        if(current_css_properties != NULL){
            sync_css_properties(current_widget->css_properties, current_css_properties);
        }
    }
    current_css_properties = get_css_widget_by_element(current_widget->html_tag);
    if(current_css_properties != NULL){
        sync_css_properties(current_widget->css_properties, current_css_properties);
    }
    current_css_properties = get_css_widget_by_id(current_widget->html_variables->id);
    if(current_css_properties != NULL){
        sync_css_properties(current_widget->css_properties, current_css_properties);
    }
    if(current_widget->html_variables->style != NULL){
        printf("WOW:%s:WOW", current_widget->html_variables->style);
        //scrape_css_from_inline_style(current_widget->css_properties, current_widget->html_variables->style);
    }

}

//last call
void scrape_css_from_document(struct widget* document){
    // search drawable tags and set css properties
    // malloc css properties
    // connect childrens to each other this needs double linked list
    // add is draw and css properties from files,  style tags, inline styles
    struct widget** widget_list = malloc(sizeof(struct widget*));
    int *widget_index_list = malloc(sizeof(int));
    widget_list[0] = document;
    widget_index_list[0] = 0;
    int current_index = 0;
    int widget_count = 1;
    while (widget_index_list[0] != document->children_count){
        if(widget_index_list[current_index] == widget_list[current_index]->children_count){
            current_index--;
            widget_count--;
            widget_list = realloc(widget_list, widget_count * sizeof(struct widget*));
            widget_index_list = realloc(widget_index_list, widget_count * sizeof(int ));
            widget_index_list[current_index]++;
        }
        else{
            if(widget_list[current_index]->children[widget_index_list[current_index]]->children_count > 0){
                widget_count++;
                widget_list = realloc(widget_list, widget_count * sizeof(struct widget*));
                widget_index_list = realloc(widget_index_list, widget_count * sizeof(int ));
                widget_list[widget_count-1] = widget_list[current_index]->children[widget_index_list[current_index]];
                widget_index_list[widget_count-1] = 0;
                current_index++;
                if(widget_list[current_index]->draw == true){
                    set_css_properties(widget_list[current_index], widget_list[current_index-1]);
                }
            }
            else{
                if(widget_list[current_index]->children[widget_index_list[current_index]]->draw == true){
                    set_css_properties(widget_list[current_index]->children[widget_index_list[current_index]], widget_list[current_index]);
                }
                widget_index_list[current_index]++;
            }
        }
    }
}

struct css_properties* get_current_css_widget(char* selector){
    char first_character = selector[0];
    char *element;
    char *class;
    struct css_properties* current_css_widget;
    switch (first_character) {
        case '#':
            current_css_widget = get_css_widget_by_id(selector);
            if (current_css_widget != NULL) {
                current_css_widget = create_new_css_widget_by_id(selector);
            }
            break;
        case '.':
            class = selector + 1;
            current_css_widget = get_css_widget_by_class(class);
            if (current_css_widget == NULL) {
                current_css_widget = create_new_css_widget_by_class(class);
            }
            break;
        default:
            element = strtok(selector, ".");
            class = strtok(NULL, ".");
            html_tags htmlTag = get_html_tag_by_name(element);
            if (class == NULL) {
                current_css_widget = get_css_widget_by_element(htmlTag);
                if(current_css_widget == NULL){
                    current_css_widget = create_new_css_widget_by_element(element);
                }
            } else {
                current_css_widget = get_css_widget_by_element_and_class(htmlTag, class);
                if (current_css_widget == NULL){
                    current_css_widget = create_new_css_widget_by_element_and_class(element, class);
                }
            }
            break;

    }
    return current_css_widget;
}


/*create css properties from file
 * */
void scrape_css_from_file(char* file_name){
    FILE *fp;
    fp = fopen(file_name, "r");
    int selector_count = 0;
    struct css_properties** css_widget_list = (struct css_properties**) malloc(sizeof(struct css_properties*) * selector_count);//selector list
    struct css_properties* current_css_widget; //for temporary
    int current_character = fgetc(fp);
    char *context = malloc(128 * sizeof(char ));
    int current_count = 0;//context char count
    char* selector;
    char* property;
    char* value;
    int property_number;
    while (feof(fp)) {
        while (feof(fp)) {
            if (current_character == '{') {//finish selectors start to properties
                selector = malloc(current_count * sizeof(char) + 1);
                selector[current_count] = '\0';
                strncpy(selector, context, current_count);
                memset(context, 0, current_count);
                current_count = 0;
                current_css_widget = get_current_css_widget(selector);
                selector_count++;
                css_widget_list = realloc(css_widget_list, sizeof(struct css_properties *) * selector_count);
                css_widget_list[selector_count-1] = current_css_widget;
                current_character = fgetc(fp);
                break;
            } else if (current_character == ',') {// add new selector
                selector = malloc(current_count * sizeof(char) + 1);
                selector[current_count] = '\0';
                strncpy(selector, context, current_count);
                memset(context, 0, current_count);
                current_count = 0;
                current_css_widget = get_current_css_widget(selector);
                selector_count++;
                css_widget_list = realloc(css_widget_list, sizeof(struct css_properties *) * selector_count);
                css_widget_list[selector_count-1] = current_css_widget;
            } else if (current_character != ' ' && current_character != '\n' &&
                       current_character != '\t') {//unimportant characters
                context[current_count++] = (char) current_character;
            }
            current_character = fgetc(fp);
        }
        memset(context, 0, current_count);
        current_count = 0;
        do {
            if (current_character == '}'){//finish this block
                if(property != NULL && current_count > 0){
                    value = malloc(current_count * sizeof(char) + 1);
                    value[current_count] = '\0';
                    strncpy(value, context, current_count);
                    memset(context, 0, current_count);
                    current_count = 0;
                    printf("property:%s, value:%s, property_number:%d\n", property, value, property_number);
                    for (int index = 0; index < selector_count; ++index) {
                        set_css_property_by_number(property_number, css_widget_list[index], value);
                    }
                    free(property);
                    free(value);// is this wrong? if we do this this means all property set functions must use malloc
                    property = NULL;
                }
                current_count = 0;
                selector_count = 0;
                current_character = fgetc(fp);
                break;
            }
            else if (current_character == ':') {//property found
                property = malloc(current_count * sizeof(char) + 1);
                property[current_count] = '\0';
                strncpy(property, context, current_count);
                memset(context, 0, current_count);
                current_count = 0;
                property_number = get_css_property_number(property);
            } else if (current_character == ';') {//value found
                value = malloc(current_count * sizeof(char) + 1);
                value[current_count] = '\0';
                strncpy(value, context, current_count);
                memset(context, 0, current_count);
                current_count = 0;
                if(property != NULL){
                    printf("property:%s, value:%s, property_number:%d\n", property, value, property_number);
                    for (int index = 0; index < selector_count; ++index) {//for every selector
                        set_css_property_by_number(property_number, css_widget_list[index], value);
                    }
                    free(property);
                    property = NULL;
                }
                free(value);
            } else if (current_character != ' ' && current_character != '\n' &&
                       current_character != '\t') {//unimportant characters
                context[current_count++] = (char ) current_character;

            }
        } while (feof(fp));
        memset(context, 0, current_count);
        current_count = 0;
    }
    free(context);
    fclose(fp);
}

/*get css properties from html style tag
 * */

void scrape_css_from_style_tag(struct widget* widget){
    int selector_count = 0;
    struct css_properties** css_widget_list = (struct css_properties**) malloc(sizeof(struct css_properties*) * selector_count);
    struct text_untagged* text = widget->children[0]->widget_properties;
    struct css_properties* current_css_widget;
    char* current_character = text->value;
    char *context = malloc(128 * sizeof(char ));
    int current_count = 0;
    char* selector;
    char* property;
    char* value;
    int property_number;
    while (*current_character != '\0') {
        while (*current_character != '\0') {
            if (*current_character == '{') {//finish selectors start to properties
                selector = malloc(current_count * sizeof(char) + 1);
                selector[current_count] = '\0';
                strncpy(selector, context, current_count);
                memset(context, 0, current_count);
                current_count = 0;
                current_css_widget = get_current_css_widget(selector);
                selector_count++;
                css_widget_list = realloc(css_widget_list, sizeof(struct css_properties *) * selector_count);
                css_widget_list[selector_count-1] = current_css_widget;
                *current_character++;
                break;
            } else if (*current_character == ',') {// add new selector
                selector = malloc(current_count * sizeof(char) + 1);
                selector[current_count] = '\0';
                strncpy(selector, context, current_count);
                memset(context, 0, current_count);
                current_count = 0;
                current_css_widget = get_current_css_widget(selector);
                selector_count++;
                css_widget_list = realloc(css_widget_list, sizeof(struct css_properties *) * selector_count);
                css_widget_list[selector_count-1] = current_css_widget;
                //*(css_widget_list[selector_count - 1]) = *current_css_widget;
            } else if (*current_character != ' ' && *current_character != '\n' &&
                       *current_character != '\t') {//unimportant characters
                context[current_count++] = *current_character;
            }
            *current_character++;
        }
        memset(context, 0, current_count);
        current_count = 0;
        do {
            if (*current_character == '}'){
                if(property != NULL && current_count > 0){
                    value = malloc(current_count * sizeof(char) + 1);
                    value[current_count] = '\0';
                    strncpy(value, context, current_count);
                    memset(context, 0, current_count);
                    current_count = 0;
                    printf("property:%s, value:%s, property_number:%d\n", property, value, property_number);
                    for (int index = 0; index < selector_count; ++index) {
                        set_css_property_by_number(property_number, css_widget_list[index], value);
                    }
                    free(property);
                    free(value);
                    property = NULL;
                }
                current_count = 0;
                selector_count = 0;
                //css_widget_list = realloc(css_widget_list, 0);
                //free(css_widget_list);
                //css_widget_list = malloc(selector_count);
                *current_character++;
                break;
            }
            else if (*current_character == ':') {//property found
                property = malloc(current_count * sizeof(char) + 1);
                property[current_count] = '\0';
                strncpy(property, context, current_count);
                memset(context, 0, current_count);
                current_count = 0;
                property_number = get_css_property_number(property);
            }
            else if (*current_character == ';') {//property found
                value = malloc(current_count * sizeof(char) + 1);
                value[current_count] = '\0';
                strncpy(value, context, current_count);
                memset(context, 0, current_count);
                current_count = 0;
                if(property != NULL){
                    printf("property:%s, value:%s, property_number:%d\n", property, value, property_number);
                    for (int index = 0; index < selector_count; ++index) {
                        set_css_property_by_number(property_number, css_widget_list[index], value);
                    }
                    free(property);
                    property = NULL;
                }
                free(value);
            }
            else if (*current_character != ' ' && *current_character != '\n' && *current_character != '\t') {//unimportant characters
                context[current_count++] = *current_character;

            }
        } while (*current_character++ != '\0');
        memset(context, 0, current_count);
        current_count = 0;
    }
    free(context);
}

void create_css_properties_from_style_tags(){
    for (int index = 0; index < get_style_tag_list_size(); ++index) {
        scrape_css_from_style_tag(get_widget_from_style_tag_list_by_index(index));
    }
}

void create_css_properties_from_style_files(){
    for (int index = 0; index < get_link_tag_list_size(); ++index) {
        scrape_css_from_file(get_url_from_link_tag_list_by_index(index));
    }
}

void execute_css_scraper(void ){
    create_css_properties_from_style_files();
    create_css_properties_from_style_tags();
}