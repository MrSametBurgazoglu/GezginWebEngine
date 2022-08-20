//
// Created by samet on 18.08.2022.
//

#include "css_synchronizer.h"
#include "css_all_properties.h"


//TODO SPLIT THIS FUNCTION TO PROPERTIES
void sync_css_properties(struct css_properties* dest, struct css_properties* source){
    if(dest->accent_color == NULL){
        dest->accent_color = source->accent_color;
    }
    if (dest->align_content_inherit){
        dest->align_content = source->align_content;
    }
    if (dest->align_items_inherit){
        dest->align_items = source->align_items;
    }
    if (dest->align_self_inherit){
        dest->align_self = source->align_self;
    }
    if (dest->animation_inherit){
        dest->animation = source->animation;
    }
    else if(dest->animation != NULL && source->animation != NULL){//if animation is inherit there is no need its sub properties to be inherit
        if (dest->animation->animation_delay_inherit){
            dest->animation->animation_delay = source->animation->animation_delay;
        }
        if (dest->animation->animation_direction_inherit){
            dest->animation->animationDirection = source->animation->animationDirection;
        }
        if (dest->animation->animation_duration_inherit){
            dest->animation->animation_duration = source->animation->animation_duration;
        }
        if (dest->animation->animation_fill_mode_inherit){
            dest->animation->animationFillMode = source->animation->animationFillMode;
        }
        if (dest->animation->animation_iteration_count_inherit){
            dest->animation->animation_iteration_count = source->animation->animation_iteration_count;
        }
        if (dest->animation->animation_direction_inherit){
            dest->animation->animationDirection = source->animation->animationDirection;
        }
        if (dest->animation->animation_name_inherit){
            dest->animation->animation_name = source->animation->animation_name;
        }
        if (dest->animation->animation_play_state_inherit){
            dest->animation->animationPlayState = source->animation->animationPlayState;
        }
        if (dest->animation->animation_timing_function_inherit){
            dest->animation->animationTimingFunction = source->animation->animationTimingFunction;//TODO CHECK THIS SET
        }
    }
    if (dest->backdropFilter_inherit){
        dest->backdropFilterType = source->backdropFilterType;
    }
    if (dest->backface_visibility_inherit){
        dest->backfaceVisibility = source->backfaceVisibility;
    }
    if (dest->background_inherit){
        dest->background = source->background;
    }
    else if (dest->background != NULL && source->background != NULL){
        if (dest->background->background_attachment_inherit){
            dest->background->backgroundAttachment = source->background->backgroundAttachment;
        }
        if (dest->background->background_attachment_inherit){
            dest->background->backgroundAttachment = source->background->backgroundAttachment;
        }
        if (dest->background->background_clip_inherit){
            dest->background->backgroundClip = source->background->backgroundClip;
        }
        if (dest->background->background_color_inherit){
            dest->background->background_color= source->background->background_color;
        }
        if (dest->background->background_image_inherit){
            dest->background->background_image_list = source->background->background_image_list;
            dest->background->background_image_count = source->background->background_image_count;
        }
        if (dest->background->background_origin_inherit){
            dest->background->backgroundOrigin = source->background->backgroundOrigin;
        }
        if (dest->background->background_position_inherit){
            dest->background->backgroundPosition = source->background->backgroundPosition;
        }
        if (dest->background->background_repeat_inherit){
            dest->background->backgroundRepeatType = source->background->backgroundRepeatType;
        }
        if (dest->background->background_size_inherit){
            dest->background->backgroundSize = source->background->backgroundSize;
        }
    }
    if (dest->border_inherit){
        dest->border = source->border;
    }
    else if (dest->border != NULL && source->border != NULL){
        if (dest->border->border_color_inherit){
            dest->border->borderColor = source->border->borderColor;
        }
        else if (dest->border->borderColor != NULL){
            if(dest->border->borderColor->border_color_top_inherit){
                dest->border->borderColor->topBorderColor = source->border->borderColor->topBorderColor;
            }
            if(dest->border->borderColor->border_color_bottom_inherit){
                dest->border->borderColor->bottomBorderColor = source->border->borderColor->bottomBorderColor;
            }
            if (dest->border->borderColor->border_color_left_inherit){
                dest->border->borderColor->leftBorderColor = source->border->borderColor->leftBorderColor;
            }
            if (dest->border->borderColor->border_color_right_inherit){
                dest->border->borderColor->rightBorderColor = source->border->borderColor->rightBorderColor;
            }
        }
        if (dest->border->borderCollapseType == CSS_BORDER_COLLAPSE_TYPE_EMPTY){
            dest->border->borderCollapseType = source->border->borderCollapseType;
        }
        if (dest->border->border_image_inherit){
            dest->border->borderImage = source->border->borderImage;
        }
        else if (dest->border->borderImage != NULL && source->border->borderImage != NULL){
            if (dest->border->borderImage->border_image_outset_inherit){
                dest->border->borderImage->imageOutset = source->border->borderImage->imageOutset;
            }
            if (dest->border->borderImage->border_image_repeat_inherit){
                dest->border->borderImage->imageRepeatType = source->border->borderImage->imageRepeatType;
            }
            if (dest->border->borderImage->border_image_repeat_inherit){
                dest->border->borderImage->imageRepeatType = source->border->borderImage->imageRepeatType;
            }
            if (dest->border->borderImage->border_image_slice_inherit){
                dest->border->borderImage->imageSlice = source->border->borderImage->imageSlice;
            }
            if (dest->border->borderImage->border_image_source_inherit){
                dest->border->borderImage->imageSource = source->border->borderImage->imageSource;
            }
            if (dest->border->borderImage->border_image_width_inherit){
                dest->border->borderImage->imageWidth = source->border->borderImage->imageWidth;
            }
        }
        if (dest->border->border_radius_inherit){
            dest->border->borderRadius = source->border->borderRadius;
        }
        if (source->border->borderSpacing != NULL){
            dest->border->borderSpacing = source->border->borderSpacing;
        }
        if (dest->border->border_style_inherit){
            dest->border->borderStyle = source->border->borderStyle;
        }
    }
    if (dest->color == NULL){
        dest->color = source->color;
    }
    if (dest->column_count_inherit){
        dest->column_count = source->column_count;
    }
    if (dest->column_fill_inherit){
        dest->column_fill = source->column_fill;
    }
    if (dest->column_gap_inherit){
        dest->column_gap = source->column_gap;
    }
    if (dest->column_rule_inherit){
        dest->columnRule = source->columnRule;
    }
    else if (dest->columnRule != NULL && source->columnRule != NULL){
        if (dest->columnRule->column_rule_color_inherit){
            dest->columnRule->columnRuleColor = source->columnRule->columnRuleColor;
        }
        if (dest->columnRule->column_rule_style_inherit){
            dest->columnRule->columnRuleStyleType = source->columnRule->columnRuleStyleType;
        }
        if (dest->columnRule->column_rule_width_inherit){
            dest->columnRule->columnRuleWidth = source->columnRule->columnRuleWidth;
        }
    }
    if (dest->column_span_inherit){
        dest->columnSpanType = source->columnSpanType;
    }
    if (dest->column_width_inherit){
        dest->column_width = source->column_width;
    }
    if (dest->flex_inherit){
        dest->flex = source->flex;
    }
    else if (dest->flex != NULL && source->flex != NULL){
        if (dest->flex->flex_basis_inherit){
            dest->flex->flex_basis_valueType = source->flex->flex_basis_valueType;
            dest->flex->flex_basis_value = source->flex->flex_basis_value;
        }
        if (dest->flex->flex_grow_inherit){
            dest->flex->flex_grow_value = source->flex->flex_grow_value;
        }
        if (dest->flex->flex_shrink_inherit){
            dest->flex->flex_shrink_value = source->flex->flex_shrink_value;
        }
    }
    if (dest->flex_flow_inherit){
        dest->flexFlow = source->flexFlow;
    }
    else if(dest->flexFlow != NULL && source->flexFlow != NULL){
        if (dest->flexFlow->flex_wrap_inherit){
            dest->flexFlow->flexWrap = source->flexFlow->flexWrap;
        }
        if (dest->flexFlow->flex_direction_inherit){
            dest->flexFlow->flexDirection = source->flexFlow->flexDirection;
        }
    }
    if (dest->font == NULL){
        dest->font = source->font;
    }
    else if (source->font != NULL){
        if (dest->font->font_family_count == 0){
            dest->font->font_family = source->font->font_family;
            dest->font->font_family_count = source->font->font_family_count;
        }
        if (source->font->font_kerning){
            dest->font->font_kerning = true;
        }
        if (dest->font->fontSizeType == CSS_FONT_SIZE_TYPE_EMPTY){
            dest->font->fontSizeType = source->font->fontSizeType;
        }
        if (dest->font->fontStretchType == CSS_FONT_SIZE_TYPE_EMPTY){
            dest->font->fontStretchType = source->font->fontStretchType;
        }
        if (dest->font->fontStyle == CSS_FONT_STYLE_EMPTY){
            dest->font->fontStyle = source->font->fontStyle;
        }
        if (dest->font->fontVariantType == CSS_FONT_VARIANT_CAPS_TYPE_EMPTY){
            dest->font->fontVariantType = source->font->fontVariantType;
        }
        if (dest->font->fontVariantCapsType == CSS_FONT_VARIANT_CAPS_TYPE_EMPTY){
            dest->font->fontVariantCapsType = source->font->fontVariantCapsType;
        }
        if (dest->font->fontWeightType == CSS_FONT_VARIANT_CAPS_TYPE_EMPTY){
            dest->font->fontWeightType = source->font->fontWeightType;
            dest->font->font_weight_value = source->font->font_weight_value;
        }
    }
    if (dest->height_inherit){
        dest->height = source->height;
        dest->heightValueType = source->heightValueType;
    }
    if (dest->margin_inherit){
        dest->margin = source->margin;
    }
    else if(dest->margin != NULL && source->margin != NULL){
        if (dest->margin->margin_bottom_inherit){
            dest->margin->margin_bottom = source->margin->margin_bottom;
            dest->margin->marginBottomValueType = source->margin->marginBottomValueType;
        }
        if (dest->margin->margin_top_inherit){
            dest->margin->margin_top = source->margin->margin_top;
            dest->margin->marginTopValueType = source->margin->marginTopValueType;
        }
        if (dest->margin->margin_left_inherit){
            dest->margin->margin_left = source->margin->margin_left;
            dest->margin->marginLeftValueType = source->margin->marginLeftValueType;
        }
        if (dest->margin->margin_right_inherit){
            dest->margin->margin_right = source->margin->margin_right;
            dest->margin->marginRightValueType = source->margin->marginRightValueType;
        }
    }
    if (dest->opacity_inherit){
        dest->opacity = source->opacity;
    }
    if (dest->outline_inherit){
        dest->outline = source->outline;
    }
    else if(dest->margin != NULL && source->margin != NULL){
        if (dest->margin->margin_bottom_inherit){
            dest->margin->margin_bottom = source->margin->margin_bottom;
            dest->margin->marginBottomValueType = source->margin->marginBottomValueType;
        }
        if (dest->margin->margin_top_inherit){
            dest->margin->margin_top = source->margin->margin_top;
            dest->margin->marginTopValueType = source->margin->marginTopValueType;
        }
        if (dest->margin->margin_left_inherit){
            dest->margin->margin_left = source->margin->margin_left;
            dest->margin->marginLeftValueType = source->margin->marginLeftValueType;
        }
        if (dest->margin->margin_right_inherit){
            dest->margin->margin_right = source->margin->margin_right;
            dest->margin->marginRightValueType = source->margin->marginRightValueType;
        }
    }
}

void sync_all_html_tree(struct widget* document){
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
                    sync_css_properties(widget_list[current_index]->css_properties, widget_list[current_index]->parent->css_properties);
                }
            }
            else{
                if(widget_list[current_index]->children[widget_index_list[current_index]]->draw == true){
                    sync_css_properties(widget_list[current_index]->css_properties, widget_list[current_index]->parent->css_properties);
                }
                widget_index_list[current_index]++;
            }
        }
    }
}