//
// Created by samet on 26.08.2022.
//

#include "calculate_dimensions.h"

int browser_window_height;
int browser_window_width;

void set_browser_window_size(int width, int height){
    browser_window_width = width;
    browser_window_height = height;
}

int get_window_height(){
    return browser_window_height;
}

int get_window_width(){
    return browser_window_width;
}

int calculate_width_of_widget(struct widget* current_widget){
    if (current_widget->css_properties->display == CSS_DISPLAY_TYPE_BLOCK){
        return browser_window_width;
    }
}

int calculate_height_of_widget(struct widget* current_widget){
    int total_height = 0;
    for (int i = 0; i < current_widget->children_count; ++i) {
        total_height += current_widget->children[i]->draw_properties->rect.h;
    }
    return total_height;
}

int calculate_x_pos_of_widget(struct widget* current_widget){
    switch (current_widget->css_properties->position) {
        case CSS_POSITION_TYPE_STICKY:
            return current_widget->parent->draw_properties->rect.x;
            break;
        case CSS_POSITION_TYPE_EMPTY:
            return current_widget->parent->draw_properties->rect.x;
            break;
        case CSS_POSITION_TYPE_STATIC:
            return current_widget->parent->draw_properties->rect.x;
            break;
        case CSS_POSITION_TYPE_ABSOLUTE:
            break;
        case CSS_POSITION_TYPE_FIXED:
            break;
        case CSS_POSITION_TYPE_RELATIVE:
            if (current_widget->css_properties->left != 0){
                printf("left.%d\n", current_widget->css_properties->left);
                return current_widget->parent->draw_properties->rect.x + current_widget->css_properties->left;
            }
            else if (current_widget->css_properties->right != 0){
                return current_widget->parent->draw_properties->rect.w - current_widget->css_properties->right;
            }
            else{
                return current_widget->parent->draw_properties->rect.x;
            }
    }
}

int calculate_y_pos_of_widget(struct widget* current_widget){
    struct widget* before_current_widget;
    switch (current_widget->css_properties->position) {
        case CSS_POSITION_TYPE_STICKY:
            before_current_widget = current_widget->child_index > 0 ? current_widget->parent->children[current_widget->child_index-1] : current_widget->parent;
            return current_widget->parent->draw_properties->rect.x;
            break;
        case CSS_POSITION_TYPE_EMPTY:
            if (current_widget->child_index > 0 && (current_widget->parent->children[current_widget->child_index-1]->draw == true || current_widget->parent->children[current_widget->child_index-1]->html_tag == HTML_UNTAGGED_TEXT)){
                before_current_widget = current_widget->parent->children[current_widget->child_index-1];
                return before_current_widget->draw_properties->rect.y + before_current_widget->draw_properties->rect.h;
            }
            else{
                before_current_widget = current_widget->parent;
                return before_current_widget->draw_properties->rect.y;
            }
            break;
        case CSS_POSITION_TYPE_STATIC:
            before_current_widget = current_widget->child_index > 0 ? current_widget->parent->children[current_widget->child_index-1] : current_widget->parent;
            return before_current_widget->draw_properties->rect.y + before_current_widget->draw_properties->rect.h;
            break;
        case CSS_POSITION_TYPE_ABSOLUTE:
            break;
        case CSS_POSITION_TYPE_FIXED:
            break;
        case CSS_POSITION_TYPE_RELATIVE:
            break;
    }
}

int calculate_y_pos_text_widget(struct widget* current_widget){
    if (current_widget->child_index > 0 && current_widget->parent->children[current_widget->child_index-1]->draw == true){
        return current_widget->parent->children[current_widget->child_index-1]->draw_properties->rect.y + current_widget->parent->children[current_widget->child_index-1]->draw_properties->rect.h;
    }
    else{
        return current_widget->parent->draw_properties->rect.y;
    }
}

int calculate_x_pos_text_widget(struct widget* current_widget){
    return current_widget->parent->draw_properties->rect.x;
}