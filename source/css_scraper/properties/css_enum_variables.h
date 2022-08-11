//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_CSS_ENUM_VARIABLES_H
#define UNTITLED_CSS_ENUM_VARIABLES_H

typedef enum {
    CSS_NUMBER_VALUE,
    CSS_PIXEL_VALUE,
    CSS_REM_VALUE,
    CSS_PERCENT_VALUE,
    CSS_DEG_VALUE,
    CSS_TURN_VALUE,
    CSS_RAD_VALUE,
} css_value_type;


typedef enum {
    CSS_FILTER_TYPE_NONE,
    CSS_FILTER_TYPE_BLUR,
    CSS_FILTER_TYPE_BRIGHTNESS,
    CSS_FILTER_TYPE_CONTRAST,
    CSS_FILTER_TYPE_DROP_SHADOW,
    CSS_FILTER_TYPE_GRAYSCALE,
    CSS_FILTER_TYPE_HUE_ROTATE,
    CSS_FILTER_TYPE_INVERT,
    CSS_FILTER_TYPE_OPACITY,
    CSS_FILTER_TYPE_SATURATE,
    CSS_FILTER_TYPE_SEPIA,
    CSS_FILTER_TYPE_URL,
} css_filter_type;

typedef enum {
    CSS_ALIGN_STRETCH,
    CSS_ALIGN_CENTER,
    CSS_ALIGN_FLEX_START,
    CSS_ALIGN_FLEX_END,
    CSS_ALIGN_SPACE_BETWEEN,
    CSS_ALIGN_SPACE_AROUND,
    CSS_ALIGN_SPACE_EVENLY,
    CSS_ALIGN_BASELINE,
    CSS_ALIGN_AUTO,
} css_align;

typedef enum {
    CSS_ALL_INITIAL,
    CSS_ALL_INHERIT,
    CSS_ALL_UNSET,
} css_all_variable;

typedef enum {
    CSS_VISIBILITY_VISIBLE,
    CSS_VISIBILITY_HIDDEN,
    CSS_VISIBILITY_COLLAPSE,
} css_visibility;

typedef enum {
    CSS_BACKGROUND_TYPE_URL,
    CSS_BACKGROUND_TYPE_CONIC_GRADIENT,
    CSS_BACKGROUND_TYPE_LINEAR_GRADIENT,
    CSS_BACKGROUND_TYPE_RADIAL_GRADIENT,
    CSS_BACKGROUND_TYPE_REPEATING_CONIC_GRADIENT,
    CSS_BACKGROUND_TYPE_REPEATING_LINEAR_GRADIENT,
    CSS_BACKGROUND_TYPE_REPEATING_RADIAL_GRADIENT,
} css_background_type;

typedef enum{
    CSS_BACKGROUND_POSITION_TYPE_WORD,
    CSS_BACKGROUND_POSITION_TYPE_PERCENT,
    CSS_BACKGROUND_POSITION_TYPE_POS,
} css_background_position_type;

typedef enum {
    CSS_BACKGROUND_REPEAT_TYPE_REPEAT,
    CSS_BACKGROUND_REPEAT_TYPE_REPEAT_X,
    CSS_BACKGROUND_REPEAT_TYPE_REPEAT_Y,
    CSS_BACKGROUND_REPEAT_TYPE_NO_REPEAT,
    CSS_BACKGROUND_REPEAT_TYPE_ROUND,
    CSS_BACKGROUND_REPEAT_TYPE_SPACE,
} css_background_repeat_type;

typedef enum {
    CSS_BACKGROUND_SIZE_TYPE_AUTO,
    CSS_BACKGROUND_SIZE_TYPE_LENGTH,
    CSS_BACKGROUND_SIZE_TYPE_PERCENTAGE,
    CSS_BACKGROUND_SIZE_TYPE_COVER,
    CSS_BACKGROUND_SIZE_TYPE_CONTAIN,
} css_background_size_type;

typedef enum {
    CSS_BACKGROUND_ATTACHMENT_SCROLL,
    CSS_BACKGROUND_ATTACHMENT_FIXED,
    CSS_BACKGROUND_ATTACHMENT_LOCAL,
} css_background_attachment;

typedef enum {
    CSS_BACKGROUND_BLEND_MODE_NORMAL,
    CSS_BACKGROUND_BLEND_MODE_MULTIPLY,
    CSS_BACKGROUND_BLEND_MODE_SCREEN,
    CSS_BACKGROUND_BLEND_MODE_OVERLAY,
    CSS_BACKGROUND_BLEND_MODE_DARKEN,
    CSS_BACKGROUND_BLEND_MODE_LIGHTEN,
    CSS_BACKGROUND_BLEND_MODE_COLOR_DODGE,
    CSS_BACKGROUND_BLEND_MODE_SATURATION,
    CSS_BACKGROUND_BLEND_MODE_COLOR,
    CSS_BACKGROUND_BLEND_MODE_LUMINOSITY,
} css_background_blend_mode;

typedef enum {
    CSS_BACKGROUND_CLIP_BORDER_BOX,
    CSS_BACKGROUND_CLIP_PADDING_BOX,
    CSS_BACKGROUND_CLIP_CONTENT_BOX,
} css_background_clip;

typedef enum {
    CSS_BACKGROUND_ORIGIN_PADDING_BOX,
    CSS_BACKGROUND_ORIGIN_BORDER_BOX,
    CSS_BACKGROUND_ORIGIN_CONTENT_BOX,
} css_background_origin;

typedef enum {
    CSS_BORDER_LINE_TYPE_MEDIUM,
    CSS_BORDER_LINE_TYPE_THIN,
    CSS_BORDER_LINE_TYPE_THICK,
    CSS_BORDER_LINE_TYPE_LENGTH,
} css_border_line_type;

typedef enum {
    CSS_BORDER_STYLE_TYPE_NONE,
    CSS_BORDER_STYLE_TYPE_HIDDEN,
    CSS_BORDER_STYLE_TYPE_DOTTED,
    CSS_BORDER_STYLE_TYPE_DASHED,
    CSS_BORDER_STYLE_TYPE_SOLID,
    CSS_BORDER_STYLE_TYPE_DOUBLE,
    CSS_BORDER_STYLE_TYPE_GROOVE,
    CSS_BORDER_STYLE_TYPE_RIDGE,
    CSS_BORDER_STYLE_TYPE_INSET,
    CSS_BORDER_STYLE_TYPE_OUTSET,
} css_border_style_type;

typedef enum {
    CSS_BORDER_RADIUS_TYPE_LENGTH,
    CSS_BORDER_RADIUS_TYPE_PERCENTAGE,
} css_border_radius_type;

typedef enum {
    CSS_BORDER_COLLAPSE_TYPE_SEPARATE,
    CSS_BORDER_COLLAPSE_TYPE_COLLAPSE,
} css_border_collapse_type;

typedef enum {
    CSS_BORDER_IMAGE_SOURCE_TYPE_NONE,
    CSS_BORDER_IMAGE_SOURCE_TYPE_IMAGE,
} css_border_image_source_type;

typedef enum {
    CSS_BORDER_IMAGE_SLICE_TYPE_NUMBER,
    CSS_BORDER_IMAGE_SLICE_TYPE_PERCENTAGE,
    CSS_BORDER_IMAGE_SLICE_TYPE_FILL,
} css_border_image_slice_type;

typedef enum {
    CSS_BORDER_IMAGE_WIDTH_TYPE_LENGTH,
    CSS_BORDER_IMAGE_WIDTH_TYPE_NUMBER,
    CSS_BORDER_IMAGE_WIDTH_TYPE_PERCENTAGE,
    CSS_BORDER_IMAGE_WIDTH_TYPE_AUTO,
} css_border_image_width_type;

typedef enum {
    CSS_BORDER_IMAGE_OUTSET_TYPE_LENGTH,
    CSS_BORDER_IMAGE_OUTSET_TYPE_NUMBER,
} css_border_image_outset_type;

typedef enum {
    CSS_BORDER_IMAGE_REPEAT_TYPE_STRETCH,
    CSS_BORDER_IMAGE_REPEAT_TYPE_REPEAT,
    CSS_BORDER_IMAGE_REPEAT_TYPE_ROUND,
    CSS_BORDER_IMAGE_REPEAT_TYPE_SPACE,
} css_border_image_repeat_type;

typedef enum {
    CSS_PROPERTY_VALUE_TYPE_AUTO,
    CSS_PROPERTY_VALUE_TYPE_LENGTH,
    CSS_PROPERTY_VALUE_TYPE_PIXEL,
    CSS_PROPERTY_VALUE_TYPE_PERCENTAGE,
    CSS_PROPERTY_VALUE_TYPE_NONE,
    CSS_PROPERTY_VALUE_TYPE_NORMAL,
    CSS_PROPERTY_VALUE_TYPE_MAX_CONTENT,
    CSS_PROPERTY_VALUE_TYPE_MIN_CONTENT,
    CSS_PROPERTY_VALUE_TYPE_SPAN,
    CSS_PROPERTY_VALUE_TYPE_MINMAX,
    CSS_PROPERTY_VALUE_TYPE_FIT_CONTENT,
} css_property_value_type;

typedef enum {
    CSS_BOX_DECORATION_BREAK_TYPE_SLICE,
    CSS_BOX_DECORATION_BREAK_TYPE_CLONE,
    CSS_BOX_DECORATION_BREAK_TYPE_UNSET,
} css_box_decoration_break_type;

typedef enum {
    CSS_BOX_SIZING_TYPE_CONTENT_BOX,
    CSS_BOX_SIZING_TYPE_BORDER_BOX,
} css_box_sizing_type;

typedef enum{
    CSS_BREAK_TYPE_AUTO,
    CSS_BREAK_TYPE_ALL,
    CSS_BREAK_TYPE_ALWAYS,
    CSS_BREAK_TYPE_AVOID,
    CSS_BREAK_TYPE_AVOID_COLUMN,
    CSS_BREAK_TYPE_AVOID_PAGE,
    CSS_BREAK_TYPE_AVOID_REGION,
    CSS_BREAK_TYPE_COLUMN,
    CSS_BREAK_TYPE_LEFT,
    CSS_BREAK_TYPE_PAGE,
    CSS_BREAK_TYPE_RECTO,
    CSS_BREAK_TYPE_REGION,
    CSS_BREAK_TYPE_RIGHT,
    CSS_BREAK_TYPE_VERSO,
} css_break_type;

typedef enum {
    CSS_CAPTION_SIDE_TOP,
    CSS_CAPTION_SIDE_BOTTOM,
} css_caption_side;

typedef enum {
    CSS_CLEAR_TYPE_NONE,
    CSS_CLEAR_TYPE_LEFT,
    CSS_CLEAR_TYPE_RIGHT,
    CSS_CLEAR_TYPE_BOTH,
} css_clear_type;

typedef enum {
    CSS_CLIP_TYPE_AUTO,
    CSS_CLIP_TYPE_SHAPE,
} css_clip_type;

typedef enum {
    CSS_COLUMN_FILL_TYPE_BALANCE,
    CSS_COLUMN_FILL_TYPE_AUTO,
} css_column_fill_type;

typedef enum {
    CSS_COLUMN_RULE_STYLE_NONE,
    CSS_COLUMN_RULE_STYLE_HIDDEN,
    CSS_COLUMN_RULE_STYLE_DOTTED,
    CSS_COLUMN_RULE_STYLE_DASHED,
    CSS_COLUMN_RULE_STYLE_SOLID,
    CSS_COLUMN_RULE_STYLE_DOUBLE,
    CSS_COLUMN_RULE_STYLE_GROOVE,
    CSS_COLUMN_RULE_STYLE_RIDGE,
    CSS_COLUMN_RULE_STYLE_INSET,
    CSS_COLUMN_RULE_STYLE_OUTSET,
} css_column_rule_style_type;

typedef enum {
    CSS_COLUMN_RULE_WIDTH_TYPE_MEDIUM,
    CSS_COLUMN_RULE_WIDTH_TYPE_THIN,
    CSS_COLUMN_RULE_WIDTH_TYPE_THICK,
    CSS_COLUMN_RULE_WIDTH_TYPE_LENGTH,
} css_column_rule_width_type;

typedef enum {
    CSS_COLUMN_SPAN_TYPE_NONE,
    CSS_COLUMN_SPAN_TYPE_ALL,
} css_column_span_type;

typedef enum {
    CSS_CURSOR_TYPE_ALIAS,
    CSS_CURSOR_TYPE_ALL_SCROLL,
    CSS_CURSOR_TYPE_AUTO,
    CSS_CURSOR_TYPE_CELL,
    CSS_CURSOR_TYPE_CONTEXT_MENU,
    CSS_CURSOR_TYPE_COL_RESIZE,
    CSS_CURSOR_TYPE_COPY,
    CSS_CURSOR_TYPE_CROSSHAIR,
    CSS_CURSOR_TYPE_DEFAULT,
    CSS_CURSOR_TYPE_E_RESIZE,
    CSS_CURSOR_TYPE_EW_RESIZE,
    CSS_CURSOR_TYPE_GRAB,
    CSS_CURSOR_TYPE_GRABBING,
    CSS_CURSOR_TYPE_HELP,
    CSS_CURSOR_TYPE_MOVE,
    CSS_CURSOR_TYPE_N_RESIZE,
    CSS_CURSOR_TYPE_NE_RESIZE,
    CSS_CURSOR_TYPE_NESW_RESIZE,
    CSS_CURSOR_TYPE_NS_RESIZE,
    CSS_CURSOR_TYPE_NW_RESIZE,
    CSS_CURSOR_TYPE_NWSE_RESIZE,
    CSS_CURSOR_TYPE_NO_DROP,
    CSS_CURSOR_TYPE_NONE,
    CSS_CURSOR_TYPE_NOT_ALLOWED,
    CSS_CURSOR_TYPE_POINTER,
    CSS_CURSOR_TYPE_PROGRESS,
    CSS_CURSOR_TYPE_ROW_RESIZE,
    CSS_CURSOR_TYPE_S_RESIZE,
    CSS_CURSOR_TYPE_SE_RESIZE,
    CSS_CURSOR_TYPE_SW_RESIZE,
    CSS_CURSOR_TYPE_TEXT,
    CSS_CURSOR_TYPE_URL,
    CSS_CURSOR_TYPE_VERTICAL_TEXT,
    CSS_CURSOR_TYPE_W_RESIZE,
    CSS_CURSOR_TYPE_WAIT,
    CSS_CURSOR_TYPE_ZOOM_IN,
    CSS_CURSOR_TYPE_ZOOM_OUT,
} css_cursor_type;

typedef enum {
    CSS_DIRECTION_TYPE_LTR,
    CSS_DIRECTION_TYPE_RTL,
} css_direction_type;

typedef enum {
    CSS_DISPLAY_TYPE_INLINE,
    CSS_DISPLAY_TYPE_BLOCK,
    CSS_DISPLAY_TYPE_CONTENTS,
    CSS_DISPLAY_TYPE_FLEX,
    CSS_DISPLAY_TYPE_GRID,
    CSS_DISPLAY_TYPE_INLINE_BLOCK,
    CSS_DISPLAY_TYPE_INLINE_FLEX,
    CSS_DISPLAY_TYPE_INLINE_GRID,
    CSS_DISPLAY_TYPE_INLINE_TABLE,
    CSS_DISPLAY_TYPE_LIST_ITEM,
    CSS_DISPLAY_TYPE_RUN_IN,
    CSS_DISPLAY_TYPE_TABLE,
    CSS_DISPLAY_TYPE_TABLE_CAPTION,
    CSS_DISPLAY_TYPE_TABLE_COLUMN_GROUP,
    CSS_DISPLAY_TYPE_TABLE_HEADER_GROUP,
    CSS_DISPLAY_TYPE_TABLE_FOOTER_GROUP,
    CSS_DISPLAY_TYPE_TABLE_ROW_GROUP,
    CSS_DISPLAY_TYPE_TABLE_CELL,
    CSS_DISPLAY_TYPE_TABLE_COLUMN,
    CSS_DISPLAY_TYPE_TABLE_ROW,
    CSS_DISPLAY_TYPE_NONE,
} css_display_type;

typedef enum {
    CSS_EMPTY_CELLS_TYPE_SHOW,
    CSS_EMPTY_CELLS_TYPE_HIDE,
} css_empty_cells_type;

typedef enum {
    CSS_FLEX_DIRECTION_TYPE_ROW,
    CSS_FLEX_DIRECTION_TYPE_ROW_REVERSE,
    CSS_FLEX_DIRECTION_TYPE_COLUMN,
    CSS_FLEX_DIRECTION_TYPE_COLUMN_REVERSE,
} css_flex_direction_type;

typedef enum {
    CSS_FLEX_WRAP_TYPE_NOWRAP,
    CSS_FLEX_WRAP_TYPE_WRAP,
    CSS_FLEX_WRAP_TYPE_WRAP_REVERSE,
} css_flex_wrap_type;

typedef enum {
    CSS_FLOAT_TYPE_NONE,
    CSS_FLOAT_TYPE_LEFT,
    CSS_FLOAT_TYPE_RIGHT,
} css_float_type;

typedef enum {
    CSS_FONT_STYLE_NORMAL,
    CSS_FONT_STYLE_ITALIC,
    CSS_FONT_STYLE_OBLIQUE,
} css_font_style;

typedef enum {
    CSS_FONT_VARIANT_NORMAL,
    CSS_FONT_VARIANT_SMALL_CAPS,
} css_font_variant_type;

typedef enum {
    CSS_FONT_WEIGHT_NORMAL,
    CSS_FONT_WEIGHT_BOLD,
    CSS_FONT_WEIGHT_BOLDER,
    CSS_FONT_WEIGHT_LIGHTER,
    CSS_FONT_WEIGHT_NUMBER,
} css_font_weight_type;

typedef enum {
    CSS_FONT_SIZE_TYPE_MEDIUM,
    CSS_FONT_SIZE_TYPE_XX_SMALL,
    CSS_FONT_SIZE_TYPE_X_SMALL,
    CSS_FONT_SIZE_TYPE_SMALL,
    CSS_FONT_SIZE_TYPE_LARGE,
    CSS_FONT_SIZE_TYPE_X_LARGE,
    CSS_FONT_SIZE_TYPE_XX_LARGE,
    CSS_FONT_SIZE_TYPE_SMALLER,
    CSS_FONT_SIZE_TYPE_LARGER,
    CSS_FONT_SIZE_TYPE_LENGTH,
    CSS_FONT_SIZE_TYPE_PERCENTAGE,
} css_font_size_type;

typedef enum {
    CSS_FONT_STRETCH_TYPE_ULTRA_CONDENSED,
    CSS_FONT_STRETCH_TYPE_EXTRA_CONDENSED,
    CSS_FONT_STRETCH_TYPE_CONDENSED,
    CSS_FONT_STRETCH_TYPE_SEMI_CONDENSED,
    CSS_FONT_STRETCH_TYPE_NORMAL,
    CSS_FONT_STRETCH_TYPE_SEMI_EXPANDED,
    CSS_FONT_STRETCH_TYPE_EXPANDED,
    CSS_FONT_STRETCH_TYPE_EXTRA_EXPANDED,
    CSS_FONT_STRETCH_TYPE_ULTRA_EXPANDED,
    CSS_FONT_STRETCH_TYPE_INITIAL,
    CSS_FONT_STRETCH_TYPE_INHERIT,
} css_font_stretch_type;

typedef enum {
    CSS_FONT_VARIANT_CAPS_TYPE_NORMAL,
    CSS_FONT_VARIANT_CAPS_TYPE_SMALL_CAPS,
    CSS_FONT_VARIANT_CAPS_TYPE_ALL_SMALL_CAPS,
    CSS_FONT_VARIANT_CAPS_TYPE_PETITE_CAPS,
    CSS_FONT_VARIANT_CAPS_TYPE_ALL_PETITE_CAPS,
    CSS_FONT_VARIANT_CAPS_TYPE_UNICASE,
    CSS_FONT_VARIANT_CAPS_TYPE_TITLING_CAPS,
    CSS_FONT_VARIANT_CAPS_TYPE_UNSET,
} css_font_variant_caps_type;

typedef enum {
    CSS_FONT_SANS,
} css_font_type;

typedef enum {
    CSS_FONT_SPECIAL_TYPE_NONE,
    CSS_FONT_SPECIAL_TYPE_CAPTION,
    CSS_FONT_SPECIAL_TYPE_ICON,
    CSS_FONT_SPECIAL_TYPE_MENU,
    CSS_FONT_SPECIAL_TYPE_MESSAGE_BOX,
    CSS_FONT_SPECIAL_TYPE_SMALL_CAPTION,
    CSS_FONT_SPECIAL_TYPE_STATUS_BAR,
} css_font_special_type;

typedef enum {
    CSS_GRID_AUTO_FLOW_TYPE_ROW,
    CSS_GRID_AUTO_FLOW_TYPE_COLUMN,
    CSS_GRID_AUTO_FLOW_TYPE_DENSE,
    CSS_GRID_AUTO_FLOW_TYPE_ROW_DENSE,
    CSS_GRID_AUTO_FLOW_TYPE_COLUMN_DENSE,
} css_grid_auto_flow_type;

typedef enum {
    CSS_TEXT_ALIGN_LEFT,
    CSS_TEXT_ALIGN_RIGHT,
    CSS_TEXT_ALIGN_CENTER,
    CSS_TEXT_ALIGN_JUSTIFY,
    CSS_TEXT_ALIGN_START,
    CSS_TEXT_ALIGN_END,
} css_text_align_type;

typedef enum {
    CSS_TEXT_DECORATION_LINE_NONE,
    CSS_TEXT_DECORATION_LINE_UNDERLINE,
    CSS_TEXT_DECORATION_LINE_OVERLINE,
    CSS_TEXT_DECORATION_LINE_LINE_THROUGH,
} css_text_decoration_line_type;

typedef enum {
    CSS_TEXT_DECORATION_STYLE_SOLID,
    CSS_TEXT_DECORATION_STYLE_DOUBLE,
    CSS_TEXT_DECORATION_STYLE_DOTTED,
    CSS_TEXT_DECORATION_STYLE_DASHED,
    CSS_TEXT_DECORATION_STYLE_WAVY,
} css_text_decoration_style;

typedef enum {
    CSS_TEXT_DECORATION_THICKNESS_AUTO,
    CSS_TEXT_DECORATION_THICKNESS_FROM_FONT,
    CSS_TEXT_DECORATION_THICKNESS_FROM_LENGTH,
    CSS_TEXT_DECORATION_THICKNESS_FROM_PERCENTAGE,
} css_text_thickness_type;

typedef enum {
    CSS_TEXT_JUSTIFY_AUTO,
    CSS_TEXT_JUSTIFY_INTER_WORD,
    CSS_TEXT_JUSTIFY_INTER_CHARACTER,
    CSS_TEXT_JUSTIFY_NONE,
} css_text_justify_type;

typedef enum {
    CSS_TEXT_OVERFLOW_CLIP,
    CSS_TEXT_OVERFLOW_ELLIPSIS,
    CSS_TEXT_OVERFLOW_STRING,
} css_text_overflow_type;

typedef enum {
    CSS_TEXT_TRANSFORM_NONE,
    CSS_TEXT_TRANSFORM_CAPITALIZE,
    CSS_TEXT_TRANSFORM_UPPERCASE,
    CSS_TEXT_TRANSFORM_LOWERCASE,
} css_text_transform_type;

typedef enum {
    CSS_POSITION_TYPE_STATIC,
    CSS_POSITION_TYPE_ABSOLUTE,
    CSS_POSITION_TYPE_FIXED,
    CSS_POSITION_TYPE_RELATIVE,
    CSS_POSITION_TYPE_STICKY,
} css_position_type;

typedef enum {
    CSS_OUTLINE_WIDTH_TYPE_MEDIUM,
    CSS_OUTLINE_WIDTH_TYPE_THIN,
    CSS_OUTLINE_WIDTH_TYPE_THICK,
    CSS_OUTLINE_WIDTH_TYPE_LENGTH,
} css_outline_width;

typedef enum {
    CSS_OUTLINE_STYLE_TYPE_NONE,
    CSS_OUTLINE_STYLE_TYPE_HIDDEN,
    CSS_OUTLINE_STYLE_TYPE_DOTTED,
    CSS_OUTLINE_STYLE_TYPE_DASHED,
    CSS_OUTLINE_STYLE_TYPE_SOLID,
    CSS_OUTLINE_STYLE_TYPE_DOUBLE,
    CSS_OUTLINE_STYLE_TYPE_GROOVE,
    CSS_OUTLINE_STYLE_TYPE_RIDGE,
    CSS_OUTLINE_STYLE_TYPE_INSET,
    CSS_OUTLINE_STYLE_TYPE_OUTSET,
} css_outline_style_type;

typedef enum {
    CSS_OVERFLOW_VISIBLE,
    CSS_OVERFLOW_HIDDEN,
    CSS_OVERFLOW_CLIP,
    CSS_OVERFLOW_SCROLL,
    CSS_OVERFLOW_AUTO,
} css_overflow_type;

typedef enum {
    CSS_OVERFLOW_WRAP_NORMAL,
    CSS_OVERFLOW_WRAP_ANYWHERE,
    CSS_OVERFLOW_WRAP_BREAK_WORD,
} css_overflow_wrap_type;



#endif //UNTITLED_CSS_ENUM_VARIABLES_H
