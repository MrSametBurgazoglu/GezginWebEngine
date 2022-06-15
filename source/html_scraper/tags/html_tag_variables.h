//
// Created by samet on 5.04.2022.
//

#ifndef UNTITLED_HTML_TAG_VARIABLES_H
#define UNTITLED_HTML_TAG_VARIABLES_H

#include <strings.h>
#include <stdbool.h>

/*
 * variables required for general usage
 * */

typedef enum {
    HTML_DOCTYPE,
    HTML_A,
    HTML_ABBR,
    HTML_ADDRESS,
    HTML_AREA,
    HTML_ARTICLE,
    HTML_ASIDE,
    HTML_AUDIO,
    HTML_B,
    HTML_BASE,
    HTML_BDI,
    HTML_BDO,
    HTML_BLOCKQUOTE,
    HTML_BODY,
    HTML_BR,
    HTML_BUTTON,
    HTML_CANVAS,
    HTML_CAPTION,
    HTML_CITE,
    HTML_CODE,
    HTML_COL,
    HTML_COLGROUP,
    HTML_DATA,
    HTML_DATALIST,
    HTML_DD,
    HTML_DEL,
    HTML_DETAILS,
    HTML_DFN,
    HTML_DIALOG,
    HTML_DIV,
    HTML_DL,
    HTML_DT,
    HTML_EM,
    HTML_FIELDSET,
    HTML_FIGCAPTION,
    HTML_FIGURE,
    HTML_FOOTER,
    HTML_FORM,
    HTML_H1,
    HTML_H2,
    HTML_H3,
    HTML_H4,
    HTML_H5,
    HTML_H6,
    HTML_HEAD,
    HTML_HEADER,
    HTML_HR,
    HTML_HTML,
    HTML_I,
    HTML_IFRAME,
    HTML_IMG,
    HTML_INPUT,
    HTML_INS,
    HTML_KBD,
    HTML_LABEL,
    HTML_LEGEND,
    HTML_LI,
    HTML_LINK,
    HTML_MAIN,
    HTML_MAP,
    HTML_MARK,
    HTML_META,
    HTML_METER,
    HTML_NAV,
    HTML_NOSCRIPT,
    HTML_OL,
    HTML_OPTGROUP,
    HTML_OPTION,
    HTML_OUTPUT,
    HTML_P,
    HTML_PARAM,
    HTML_PICTURE,
    HTML_PRE,
    HTML_PROGRESS,
    HTML_Q,
    HTML_S,
    HTML_SAMP,
    HTML_SCRIPT,
    HTML_SECTION,
    HTML_SELECT,
    HTML_SMALL,
    HTML_SOURCE,
    HTML_SPAN,
    HTML_STRONG,
    HTML_STYLE,
    HTML_SUB,
    HTML_SUMMARY,
    HTML_SUP,
    HTML_SVG,
    HTML_TABLE,
    HTML_TBODY,
    HTML_TD,
    HTML_TEMPLATE,
    HTML_TEXTAREA,
    HTML_TFOOT,
    HTML_TH,
    HTML_THEAD,
    HTML_TIME,
    HTML_TITLE,
    HTML_TR,
    HTML_TRACK,
    HTML_U,
    HTML_UL,
    HTML_VAR,
    HTML_VIDEO,
    HTML_WBR,
    HTML_UNTAGGED_TEXT,
} html_tags;

typedef enum {
    INPUT_TYPE_BUTTON,
    INPUT_TYPE_CHECKBOX,
    INPUT_TYPE_COLOR,
    INPUT_TYPE_DATE,
    INPUT_TYPE_DATETIME_LOCAL,
    INPUT_TYPE_EMAIL,
    INPUT_TYPE_FILE,
    INPUT_TYPE_HIDDEN,
    INPUT_TYPE_IMAGE,
    INPUT_TYPE_MONTH,
    INPUT_TYPE_NUMBER,
    INPUT_TYPE_PASSWORD,
    INPUT_TYPE_RADIO,
    INPUT_TYPE_RANGE,
    INPUT_TYPE_RESET,
    INPUT_TYPE_SEARCH,
    INPUT_TYPE_SUBMIT,
    INPUT_TYPE_TEL,
    INPUT_TYPE_TEXT,
    INPUT_TYPE_TIME,
    INPUT_TYPE_URL,
    INPUT_TYPE_WEEK
} input_type;

typedef enum {
    BUTTON_TYPE_BUTTON,
    BUTTON_TYPE_RESET,
    BUTTON_TYPE_SUBMIT
} button_type;

typedef enum {
    FORM_ENC_TYPE_TEXT,
    FORM_ENC_TYPE_MULTIPART,
    FORM_ENC_TYPE_APPLICATION
} form_enc_type;

typedef enum {
    FORM_METHOD_GET,
    FORM_METHOD_POST
} form_method;

typedef enum {
    FORM_TARGET_BLANK,
    FORM_TARGET_SELF,
    FORM_TARGET_PARENT,
    FORM_TARGET_TOP,
    FORM_TARGET_CUSTOM
} form_target;

typedef enum {
    SHAPE_DEFAULT,
    SHAPE_RECT,
    SHAPE_CIRCLE,
    SHAPE_POLY
} shape;

typedef enum {
    PRELOAD_AUTO,
    PRELOAD_METADATA,
    PRELOAD_NONE
} preload_option;

typedef enum {
    FORM_REL_ALTERNATE,
    FORM_REL_AUTHOR,
    FORM_REL_BOOKMARK,
    FORM_REL_DNS_PREFETCH,
    FORM_REL_EXTERNAL,
    FORM_REL_HELP,
    FORM_REL_ICON,
    FORM_REL_LICENSE,
    FORM_REL_NEXT,
    FORM_REL_NOFOLLOW,
    FORM_REL_NO_OPENER,
    FORM_REL_NO_REFERRER,
    FORM_REL_OPENER,
    FORM_REL_PINGBACK,
    FORM_REL_PRECONNECT,
    FORM_REL_PREFETCH,
    FORM_REL_PRELOAD,
    FORM_REL_PRERENDER,
    FORM_REL_PREV,
    FORM_REL_SEARCH,
    FORM_REL_STYLESHEET,
    FORM_REL_TAG,
} form_rel;

typedef enum{
    LOADING_TYPE_EAGER,
    LOADING_TYPE_LAZY,
} loading_type;

typedef enum {
    POLICY_NO_REFERRER,
    POLICY_NO_REFERRER_WHEN_DOWNGRADE,
    POLICY_ORIGIN,
    POLICY_ORIGIN_WHEN_CROSS_ORIGIN,
    POLICY_SAME_ORIGIN,
    POLICY_STRICT_ORIGIN,
    POLICY_STRICT_ORIGIN_WHEN_CROSS_ORIGIN,
    POLICY_UNSAFE_URL,
} referrer_policy;

typedef enum {
    SANDBOX_ALLOW_NONE,
    SANDBOX_ALLOW_FORMS,
    SANDBOX_ALLOW_MODALS,
    SANDBOX_ALLOW_ORIENTATION_LOCK,
    SANDBOX_ALLOW_POINTER_LOCK,
    SANDBOX_ALLOW_POPUPS,
    SANDBOX_ALLOW_POPUPS_TO_ESCAPE_SANDBOX,
    SANDBOX_ALLOW_PRESENTATION,
    SANDBOX_ALLOW_SAME_ORIGIN,
    SANDBOX_ALLOW_SCRIPTS,
    SANDBOX_ALLOW_TOP_NAVIGATION,
    SANDBOX_ALLOW_TOP_NAVIGATION_BY_USER_ACTIVATION,
} sandbox_allow;

typedef enum {
    CROSS_ORIGIN_ANONYMOUS,
    CROSS_ORIGIN_USE_CREDENTIALS,
} cross_origin;

typedef enum {
    HTTP_EQUIV_CONTENT_SECURITY_POLICY,
    HTTP_EQUIV_CONTENT_TYPE,
    HTTP_EQUIV_DEFAULT_STYLE,
    HTTP_EQUIV_REFRESH,
} http_equiv;

typedef enum{
    META_NAME_APPLICATION_NAME,
    META_NAME_AUTHOR,
    META_NAME_DESCRIPTION,
    META_NAME_GENERATOR,
    META_NAME_KEYWORDS,
    META_NAME_VIEWPORT,
} meta_name;

typedef enum {
    OL_TYPE_1,
    OL_TYPE_a,
    OL_TYPE_A,
    OL_TYPE_i,
    OL_TYPE_I,
} ol_type;

typedef enum {
    TEXTAREA_WRAP_HARD,
    TEXTAREA_WRAP_SOFT,
} textarea_wrap;

typedef enum{
    TABLE_SCOPE_COL,
    TABLE_SCOPE_ROW,
    TABLE_SCOPE_COLGROUP,
    TABLE_SCOPE_ROWGROUP,
} table_scope;

typedef enum{
    TRACK_KIND_CAPTIONS,
    TRACK_KIND_CHAPTERS,
    TRACK_KIND_DESCRIPTIONS,
    TRACK_KIND_METADATA,
    TRACK_KIND_SUBTITLES,
} track_kind;

typedef enum {HTML_RIGHT, HTML_LEFT, HTML_UP, HTML_DOWN, HTML_AUTO} html_direction;

struct standart_html_objects{
    //char *access_key; will not be SUPPORTED, but I am not sure
    size_t class_count;
    char **class;
    bool contenteditable;
    /* data-* */
    //char *dir;
    //html_direction direction;
    bool draggable;
    bool hidden;
    char *id;
    //char *lang;
    //char *spell_check;
    //int spell_check_control;
    char *style;
    //int tab_index;
};

#endif //UNTITLED_HTML_TAG_VARIABLES_H