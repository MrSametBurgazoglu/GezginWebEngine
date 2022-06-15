//
// Created by samet on 8.04.2022.
//


#include <string.h>
#include <malloc.h>
#include "html_tag_searcher.h"
#include "../drawer/draw_functions.h"

//all supported elements names as string
char* html_tag_list[] = {
        "!DOCTYPE",
        "a",
        "abbr",
        "address",
        "area",
        "article",
        "aside",
        "audio",
        "b",
        "base",
        "bdi",
        "bdo",
        "blockquote",
        "body",
        "br",
        "button",
        "canvas",
        "caption",
        "cite",
        "code",
        "col",
        "colgroup",
        "data",
        "datalist",
        "dd",
        "del",
        "details",
        "dfn",
        "dialog",
        "div",
        "dl",
        "dt",
        "em",
        "fieldset",
        "figcaption",
        "figure",
        "footer",
        "form",
        "h1",
        "h2",
        "h3",
        "h4",
        "h5",
        "h6",
        "head",
        "header",
        "hr",
        "html",
        "i",
        "iframe",
        "img",
        "input",
        "ins",
        "kbd",
        "label",
        "legend",
        "li",
        "link",
        "main",
        "map",
        "mark",
        "meta",
        "meter",
        "nav",
        "ol",
        "optgroup",
        "option",
        "output",
        "p",
        "param",
        "picture",
        "pre",
        "progress",
        "q",
        "s",
        "samp",
        "script",
        "section",
        "select",
        "small",
        "source",
        "span",
        "strong",
        "style",
        "sub",
        "summary",
        "sup",
        "svg",
        "table",
        "tbody",
        "td",
        "template",
        "textarea",
        "tfoot",
        "th",
        "thead",
        "time",
        "title",
        "tr",
        "track",
        "u",
        "ul",
        "var",
        "video",
        "wbr",
};

int html_tag_count = 105;

//initialize list for later use
struct html_tag_variables htmlTagVariables[105] = {
        [0].tag = HTML_DOCTYPE,
        [0].end_tag = true,
        [1].tag = HTML_A,
        [1].widget_property_function = set_widget_properties_for_a_tag,
        [1].widget_draw_function = html_drawer_function,
        [1].widget_render_function = html_render_function,
        [1].draw = true,
        [2].tag = HTML_ABBR,
        [2].draw = true,
        [3].tag = HTML_ADDRESS,
        [3].draw = true,
        [4].tag = HTML_AREA,
        [4].end_tag = true,
        [4].widget_property_function = set_widget_properties_for_area_tag,
        [4].draw = true,
        [5].tag = HTML_ARTICLE,
        [5].draw = true,
        [6].tag = HTML_ASIDE,
        [6].draw = true,
        [7].tag = HTML_AUDIO,
        [7].widget_property_function = set_widget_properties_for_audio_tag,
        [7].draw = true,
        [8].tag = HTML_B,
        [8].draw = true,
        [9].tag = HTML_BASE,
        [9].end_tag = true,
        [10].tag = HTML_BDI,
        [11].tag = HTML_BDO,
        [11].widget_property_function = set_widget_properties_for_bdo_tag,
        [12].tag = HTML_BLOCKQUOTE,
        [12].widget_property_function = set_widget_properties_for_blockquote_tag,
        [12].draw = true,
        [13].tag = HTML_BODY,
        [13].draw = true,
        [14].tag = HTML_BR,
        [14].end_tag = true,
        [14].draw = true,
        [15].tag = HTML_BUTTON,
        [15].widget_property_function = set_widget_properties_for_button_tag,
        [15].draw = true,
        [16].tag = HTML_CANVAS,
        [16].widget_property_function = set_widget_properties_for_canvas_tag,
        [16].draw = true,
        [17].tag = HTML_CAPTION,
        [17].draw = true,
        [18].tag = HTML_CITE,
        [18].draw = true,
        [19].tag = HTML_CODE,
        [19].draw = true,
        [20].tag = HTML_COL,
        [20].end_tag = true,
        [20].widget_property_function = set_widget_properties_for_col_tag,
        [20].draw = true,
        [21].tag = HTML_COLGROUP,
        [21].widget_property_function = set_widget_properties_for_colgroup_tag,
        [21].draw = true,
        [22].tag = HTML_DATA,
        [22].widget_property_function = set_widget_properties_for_data_tag,
        [23].tag = HTML_DATALIST,
        [23].draw = true,
        [24].tag = HTML_DD,
        [24].draw = true,
        [25].tag = HTML_DEL,
        [25].widget_property_function = set_widget_properties_for_del_tag,
        [25].draw = true,
        [26].tag = HTML_DETAILS,
        [26].widget_property_function = set_widget_properties_for_details_tag,
        [26].draw = true,
        [27].tag = HTML_DFN,
        [27].draw = true,
        [28].tag = HTML_DIALOG,
        [28].widget_property_function = set_widget_properties_for_dialog_tag,
        [29].tag = HTML_DIV,
        [29].draw = true,
        [30].tag = HTML_DL,
        [30].draw = true,
        [31].tag = HTML_DT,
        [31].draw = true,
        [32].tag = HTML_EM,
        [32].draw = true,
        [33].tag = HTML_FIELDSET,
        [33].widget_property_function = set_widget_properties_for_fieldset_tag,
        [33].draw = true,
        [34].tag = HTML_FIGCAPTION,
        [34].draw = true,
        [35].tag = HTML_FIGURE,
        [35].draw = true,
        [36].tag = HTML_FOOTER,
        [36].draw = true,
        [37].tag = HTML_FORM,
        [37].widget_property_function = set_widget_properties_for_form_tag,
        [37].draw = true,
        [38].tag = HTML_H1,
        [38].draw = true,
        [39].tag = HTML_H2,
        [39].draw = true,
        [40].tag = HTML_H3,
        [40].draw = true,
        [41].tag = HTML_H4,
        [41].draw = true,
        [42].tag = HTML_H5,
        [42].draw = true,
        [43].tag = HTML_H6,
        [43].draw = true,
        [44].tag = HTML_HEAD,
        [45].tag = HTML_HEADER,
        [45].draw = true,
        [46].tag = HTML_HR,
        [46].end_tag = true,
        [46].draw = true,
        [47].tag = HTML_HTML,
        [47].draw = true,
        [48].tag = HTML_I,
        [48].draw = true,
        [49].tag = HTML_IFRAME,
        [49].widget_property_function = set_widget_properties_for_iframe_tag,
        [49].draw = true,
        [50].tag = HTML_IMG,
        [50].end_tag = true,
        [50].draw = true,
        [50].widget_property_function = set_widget_properties_for_img_tag,
        [51].tag = HTML_INPUT,
        [51].widget_property_function = set_widget_properties_for_input_tag,
        [51].end_tag = true,
        [51].draw = true,
        [52].tag = HTML_INS,
        [52].widget_property_function = set_widget_properties_for_ins_tag,
        [52].draw = true,
        [53].tag = HTML_KBD,
        [53].draw = true,
        [54].tag = HTML_LABEL,
        [54].widget_property_function = set_widget_properties_for_label_tag,
        [54].draw = true,
        [55].tag = HTML_LEGEND,
        [55].draw = true,
        [56].tag = HTML_LI,
        [56].widget_property_function = set_widget_properties_for_li_tag,
        [56].draw = true,
        [57].tag = HTML_LINK,
        [57].widget_property_function = set_widget_properties_for_link_tag,
        [57].end_tag = true,
        [58].tag = HTML_MAIN,
        [58].draw = true,
        [59].tag = HTML_MAP,
        [59].widget_property_function = set_widget_properties_for_map_tag,
        [59].draw = true,
        [60].tag = HTML_MARK,
        [60].draw = true,
        [61].tag = HTML_META,
        [61].widget_property_function = set_widget_properties_for_meta_tag,
        [61].end_tag = true,
        [62].tag = HTML_METER,
        [62].widget_property_function = set_widget_properties_for_meter_tag,
        [63].tag = HTML_NAV,
        [63].draw = true,
        [64].tag = HTML_OL,
        [64].widget_property_function = set_widget_properties_for_ol_tag,
        [64].draw = true,
        [65].tag = HTML_OPTGROUP,
        [65].widget_property_function = set_widget_properties_for_optgroup_tag,
        [66].tag = HTML_OPTION,
        [66].widget_property_function = set_widget_properties_for_option_tag,
        [67].tag = HTML_OUTPUT,
        [67].widget_property_function = set_widget_properties_for_output_tag,
        [67].draw = true,
        [68].tag = HTML_P,
        [68].draw = true,
        [69].tag = HTML_PARAM,
        [69].widget_property_function = set_widget_properties_for_param_tag,
        [69].end_tag = true,
        [70].tag = HTML_PICTURE,
        [71].tag = HTML_PRE,
        [71].draw = true,
        [72].tag = HTML_PROGRESS,
        [72].widget_property_function = set_widget_properties_for_progress_tag,
        [73].tag = HTML_Q,
        [73].widget_property_function = set_widget_properties_for_q_tag,
        [73].draw = true,
        [74].tag = HTML_S,
        [74].draw = true,
        [75].tag = HTML_SAMP,
        [75].draw = true,
        [76].tag = HTML_SCRIPT,
        [76].widget_property_function = set_widget_properties_for_script_tag,
        [77].tag = HTML_SECTION,
        [77].draw = true,
        [78].tag = HTML_SELECT,
        [78].widget_property_function = set_widget_properties_for_select_tag,
        [79].tag = HTML_SMALL,
        [79].draw = true,
        [80].tag = HTML_SOURCE,
        [80].widget_property_function = set_widget_properties_for_source_tag,
        [80].end_tag = true,
        [81].tag = HTML_SPAN,
        [82].tag = HTML_STRONG,
        [82].draw = true,
        [83].tag = HTML_STYLE,
        [83].widget_property_function = set_widget_properties_for_style_tag,
        [84].tag = HTML_SUB,
        [84].draw = true,
        [85].tag = HTML_SUMMARY,
        [85].draw = true,
        [86].tag = HTML_SUP,
        [86].draw = true,
        [87].tag = HTML_SVG,
        [88].tag = HTML_TABLE,
        [88].draw = true,
        [89].tag = HTML_TBODY,
        [89].draw = true,
        [90].tag = HTML_TD,
        [90].widget_property_function = set_widget_properties_for_td_tag,
        [90].draw = true,
        [91].tag = HTML_TEMPLATE,
        [92].tag = HTML_TEXTAREA,
        [92].widget_property_function = set_widget_properties_for_textarea_tag,
        [93].tag = HTML_TFOOT,
        [93].draw = true,
        [94].tag = HTML_TH,
        [94].widget_property_function = set_widget_properties_for_th_tag,
        [94].draw = true,
        [95].tag = HTML_THEAD,
        [95].draw = true,
        [96].tag = HTML_TIME,
        [96].widget_property_function = set_widget_properties_for_time_tag,
        [97].tag = HTML_TITLE,
        [98].tag = HTML_TR,
        [98].draw = true,
        [99].tag = HTML_TRACK,
        [99].widget_property_function = set_widget_properties_for_track_tag,
        [99].end_tag = true,
        [100].tag = HTML_U,
        [100].draw = true,
        [101].tag = HTML_UL,
        [101].draw = true,
        [102].tag = HTML_VAR,
        [102].draw = true,
        [103].tag = HTML_VIDEO,
        [103].widget_property_function = set_widget_properties_for_video_tag,
        [103].draw = true,
        [104].tag = HTML_WBR,
};

/*
 *binary search for finding element by string
 * its return index
 * */
int search(char* tag_name)
{
    int l, m, r, result;
    l = 0;
    r = html_tag_count;

    while (l <= r) {
        m = l + (r - l) / 2;
        result = strcmp(html_tag_list[m], tag_name);

        if (result == 0) return m;
        if (result < 0) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

html_tags get_html_tag_by_name(char * tag_name){
    int result = search(tag_name);
    return htmlTagVariables[result].tag;
}

bool set_html_tag(struct widget* current_widget, char* tag_name){
    int result = search(tag_name);
    current_widget->html_tag = htmlTagVariables[result].tag;
    if(htmlTagVariables[result].widget_property_function != NULL){
        htmlTagVariables[result].widget_property_function(current_widget);
    }
    if (htmlTagVariables[result].draw == true){
        current_widget->css_properties = malloc(sizeof(struct css_properties));//if the element isn't drawn it doesn't need css properties
        current_widget->draw = true;
    }
    if (htmlTagVariables[result].end_tag == true){
        return true;//if element don't have ending tag like '</div>'
    }
    return false;
}