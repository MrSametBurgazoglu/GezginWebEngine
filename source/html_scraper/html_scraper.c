//
// Created by samet on 30.01.2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "html_tags.h"
#include "html_scraper.h"
#include "html_tag_searcher.h"
#include "../drawer/tags/untagged_text_drawer.h"

/*
 * free widget tree
 * */
void free_tree(struct widget* document){
    struct widget* current_widget = document;
    while (document->children_count > 0){
        if(current_widget->children_count > 0){
            current_widget = current_widget->children[current_widget->children_count-1];
        }
        else{//if element don't have any child we can delete it
            //TODO DELETE EVERYTHING ABOUT ELEMENT
            free(current_widget->html_variables);
            if (current_widget->widget_properties != NULL){
                free(current_widget->widget_properties);
            }
            free(current_widget->children);
            current_widget = current_widget->parent;
            free(current_widget->children[current_widget->children_count - 1]);
            current_widget->children_count = current_widget->children_count - 1;
        }
    }
}

int choose_variable_for_standard_vars(struct widget* current_widget, char* var_name, char* var_value, int* free_value){
    if(!strcmp(var_name, "id")){
        current_widget->html_variables->id = var_value;
        printf("%s:%s\n", var_name, var_value);
    }
    else if(!strcmp(var_name, "class")){
        char* class;
        class = strtok(var_value, " ");
        current_widget->html_variables->class = malloc(sizeof(char *));
        current_widget->html_variables->class[0] = class;
        while (class != NULL){
            current_widget->html_variables->class_count++;
            current_widget->html_variables->class = (char**) realloc(current_widget->html_variables->class,
                                                                     sizeof(char *) * current_widget->html_variables->class_count);
            current_widget->html_variables->class[current_widget->html_variables->class_count-1] = class;
            class = strtok(NULL, " ");
        }
    }
    else if(!strcmp(var_name, "style")){
        current_widget->html_variables->style = var_value;
        printf("%s:%s\n", var_name, var_value);
    }
    else if(!strcmp(var_name, "contenteditable")){
        if(!strcmp(var_value, "true")){
            current_widget->html_variables->contenteditable = true;
        }
        else{// is this necessary?
            current_widget->html_variables->contenteditable = false;
        }
        printf("%s:%s\n", var_name, var_value);
        *free_value = 1;
    }
    else if(!strcmp(var_name, "draggable")){
        if(!strcmp(var_value, "true")){
            current_widget->html_variables->draggable = true;
        }
        else{// is this necessary?
            current_widget->html_variables->draggable = false;
        }
        printf("%s:%s\n", var_name, var_value);
        *free_value = 1;
    }
    else{
        printf("%s:%s\n", var_name, var_value);
        return 0;
    }
    return 1;
}

int set_tag_context_for_standard_vars(struct  widget* current_widget, char* tag_context){
    if(!strcmp(tag_context, "contenteditable")){
        current_widget->html_variables->contenteditable = true;
    }
    else{
        printf("undefined var\n");
        return 0;
    }
    return 1;
}

struct widget* scrape_html_from_file(char* file_name){
    FILE *fp;
    fp = fopen(file_name, "r");
    int current_character;
    char *context = malloc(128 * sizeof(char ));
    if(fp == NULL) {
        perror("Error in opening file");
        //return(-1);
    }

    struct widget *document = (struct widget*) malloc(sizeof(struct widget));
    memset(document, 0, sizeof(struct widget));
    document->children = (struct widget**) malloc(0);
    document->children_count = 0;
    document->draw_properties = malloc(sizeof(struct draw_properties));
    document->draw_properties->rect.x = 0;
    document->draw_properties->rect.y = 0;
    struct widget *current_widget = document;
    /* first variables */
    int current_count = 0;
    do {
        current_character = fgetc(fp);
        if( feof(fp) ) {
            break;
        }
        if(current_character == '<'){ // start of tag
            if (current_count > 0){
                struct widget *new_widget = (struct widget*) malloc(sizeof(struct widget));
                new_widget->html_tag = HTML_UNTAGGED_TEXT;
                new_widget->widget_properties = malloc(sizeof(struct text_untagged));
                //TODO iplement new_widget->draw_widget, new_widget->render_widget
                new_widget->parent = current_widget;
                new_widget->children_count = 0;
                current_widget->children_count = current_widget->children_count + 1;
                if (current_widget->children_count == 1){
                    current_widget->children = malloc(sizeof(struct widget*));
                }
                else{
                    current_widget->children = realloc(current_widget->children, current_widget->children_count * sizeof(struct widget*));
                }
                current_widget->children[current_widget->children_count-1] = new_widget;
                struct text_untagged *text = new_widget->widget_properties;
                new_widget->html_variables = NULL;
                new_widget->children = NULL;
                new_widget->draw_properties = malloc(sizeof(struct draw_properties));
                new_widget->draw_properties->rect.x = 0;
                new_widget->draw_properties->rect.y = 0;
                new_widget->child_index = current_widget->children_count-1;
                text->value = malloc(current_count * sizeof(char )+1);
                text->value[current_count] = '\0';
                strncpy(text->value, context, current_count);
                printf("\ntag:text_tag,value:%s\n", text->value);
                memset(context, 0, current_count);
                new_widget->draw_widget = untagged_text_drawer_function;
                new_widget->render_widget = untagged_text_render_function;
            }
            current_count = 0;
            current_character = fgetc(fp);

            if(current_character == '/'){ // if this is an end tag like </something>
                /* close last tag | is it necessary to get name*/
                //TODO IS THIS NECESSARY
                while ((current_character = fgetc(fp)) != '>'){
                    context[current_count] = (char)current_character;
                    current_count++;
                }
                char *tag_context = malloc(current_count * sizeof(char )+1);
                tag_context[current_count] = '\0';
                strncpy(tag_context, context, current_count);
                current_count = 0;
                printf("tag_end:%s\n", tag_context);
                memset(context, 0, current_count);
                current_widget = current_widget->parent;
            }
            else{/* create new widget with initialization */
                struct widget *new_widget = (struct widget*) malloc(sizeof(struct widget));
                new_widget->html_variables = (struct standart_html_objects*) malloc(sizeof(struct standart_html_objects));
                new_widget->parent = current_widget;
                new_widget->children_count = 0;
                current_widget->children_count = current_widget->children_count + 1;
                current_widget->children = realloc(current_widget->children, current_widget->children_count * sizeof(struct widget*));
                current_widget->children[current_widget->children_count-1] = new_widget;
                new_widget->child_index = current_widget->children_count-1;
                current_widget = new_widget;
                //TODO MAKE CURRENT WIDGET INIT FUNCTION
                current_widget->var_reader_func = NULL;
                current_widget->context_reader_func = NULL;
                current_widget->html_variables->class_count = 0;
                current_widget->html_variables->draggable = false;
                current_widget->html_variables->contenteditable = false;
                current_widget->html_variables->style = NULL;
                current_widget->children = NULL;
                bool tag_found = false;
                context[0] = (char) current_character;
                current_count = 1;
                bool close_tag = false;
                while ((current_character = fgetc(fp)) != '>'){
                    if (current_character == ' '){
                        if(!tag_found){
                            char *tag_name = malloc(current_count * sizeof(char )+1);
                            tag_name[current_count] = '\0';
                            strncpy(tag_name, context, current_count);
                            printf("tag_start:%s\n", tag_name);
                            close_tag = set_html_tag(new_widget, tag_name);
                            memset(context, 0, current_count);// is this necessary
                            current_count = 0;
                            tag_found = true;
                            free(tag_name);
                        }
                        else if(current_count > 0){
                            char *tag_context = malloc(current_count * sizeof(char )+1);
                            tag_context[current_count] = '\0';
                            strncpy(tag_context, context, current_count);
                            memset(context, 0, current_count);
                            if(!set_tag_context_for_standard_vars(current_widget, tag_context)){
                                if(new_widget->context_reader_func != NULL){ //TODO MAKE FUNCTION POINTER LESS
                                    new_widget->context_reader_func(new_widget, tag_context);
                                }
                            }
                            current_count = 0;
                            printf("tag_context:%s\n", tag_context);
                            free(tag_context);
                        }
                    }
                    else if(current_character == '='){
                        char *var_name = malloc(current_count * sizeof(char )+1);
                        var_name[current_count] = '\0';
                        strncpy(var_name, context, current_count);
                        memset(context, 0, current_count);
                        current_count = 0;
                        int beginning_character = fgetc(fp);
                        char *var_value;
                        if(beginning_character == '"'){
                            while ((current_character = fgetc(fp)) != '"'){
                                context[current_count] = (char)current_character;
                                current_count++;
                            }
                        }
                        else{
                            printf("error");
                        }
                        var_value = malloc(current_count * sizeof(char )+1);
                        var_value[current_count] = '\0';
                        strncpy(var_value, context, current_count);
                        memset(context, 0, current_count);
                        current_count = 0;
                        int free_value = 0;
                        int* free_value_pointer = &free_value;
                        if(!choose_variable_for_standard_vars(current_widget, var_name, var_value, free_value_pointer)){
                            if(new_widget->var_reader_func != NULL){
                                *free_value_pointer = new_widget->var_reader_func(new_widget, var_name, var_value);
                            }
                        }
                        if (*free_value_pointer == 1){
                            free(var_value);
                            printf("VAR_NAME:%s", var_name);
                            *free_value_pointer = 0;
                        }
                        free(var_name);
                    }
                    else{
                        context[current_count] = (char)current_character;
                        current_count++;
                    }
                }
                if(current_count > 0){
                    if(!tag_found){
                        char *tag_name = malloc(current_count * sizeof(char )+1);
                        tag_name[current_count] = '\0';
                        strncpy(tag_name, context, current_count);
                        printf("tag_start:%s\n", tag_name);
                        close_tag = set_html_tag(new_widget, tag_name);
                        memset(context, 0, current_count);
                        tag_found = true;
                        free(tag_name);
                    }
                    else {
                        char *tag_context = malloc(current_count * sizeof(char )+1);
                        tag_context[current_count] = '\0';
                        strncpy(tag_context, context, current_count);
                        memset(context, 0, current_count);
                        printf("tag_context:%s\n", tag_context);

                        if(!set_tag_context_for_standard_vars(current_widget, tag_context)){
                            if(new_widget->context_reader_func != NULL){
                                new_widget->context_reader_func(new_widget, tag_context);
                            }
                        }
                        free(tag_context);
                    }
                    if(close_tag){//close this tag
                        current_widget = current_widget->parent;
                        printf("close last tag\n");
                    }
                }
            }
            current_count = 0;
        }
        else{
            if(current_character != '\n' && current_character != '\t' && current_character != ' '){
                context[current_count] = (char)current_character;
                current_count++;
                //printf("%c", current_character);
            }
        }

    } while(1);
    free(context);
    fclose(fp);
    //free_tree(first_widget);
    return document;
}