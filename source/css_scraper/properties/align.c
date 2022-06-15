//
// Created by samet on 26.05.2022.
//

#include <stdlib.h>
#include "string.h"
#include "../css_widget.h"
#include "align.h"

void align_content_property_set_value(struct css_properties* current_css_widget, char* value){
    if(!strcmp(value, "stretch") || !strcmp(value, "initial")){
        current_css_widget->align_content = CSS_ALIGN_STRETCH;
    }
    else if(!strcmp(value, "center")){
        current_css_widget->align_content = CSS_ALIGN_CENTER;
    }
    else if(!strcmp(value, "flex-start")){
        current_css_widget->align_content = CSS_ALIGN_FLEX_START;
    }
    else if(!strcmp(value, "flex-end")){
        current_css_widget->align_content = CSS_ALIGN_FLEX_END;
    }
    else if(!strcmp(value, "space-between")){
        current_css_widget->align_content = CSS_ALIGN_SPACE_BETWEEN;
    }
    else if(!strcmp(value, "space-around")){
        current_css_widget->align_content = CSS_ALIGN_SPACE_AROUND;
    }
    else if(!strcmp(value, "space-evenly")){
        current_css_widget->align_content = CSS_ALIGN_SPACE_EVENLY;
    }
    else if(!strcmp(value, "inherit")){
        current_css_widget->align_content_inherit = true;
    }
}

void align_items_property_set_value(struct css_properties* current_css_widget, char* value){
    if(!strcmp(value, "stretch") || !strcmp(value, "initial")){
        current_css_widget->align_items = CSS_ALIGN_STRETCH;
    }
    else if(!strcmp(value, "center")){
        current_css_widget->align_items = CSS_ALIGN_CENTER;
    }
    else if(!strcmp(value, "flex-start")){
        current_css_widget->align_items = CSS_ALIGN_FLEX_START;
    }
    else if(!strcmp(value, "flex-end")){
        current_css_widget->align_items = CSS_ALIGN_FLEX_END;
    }
    else if(!strcmp(value, "baseline")){
        current_css_widget->align_items = CSS_ALIGN_BASELINE;
    }
    else if(!strcmp(value, "inherit")){
        current_css_widget->align_items_inherit = true;
    }
}

void align_self_property_set_value(struct css_properties* current_css_widget, char* value){
    if(!strcmp(value, "auto") || !strcmp(value, "initial") || !strcmp(value, "inherit")){
        current_css_widget->align_self_inherit = true;
    }
    else if(!strcmp(value, "stretch")){
        current_css_widget->align_self = CSS_ALIGN_STRETCH;
    }
    else if(!strcmp(value, "center")){
        current_css_widget->align_self = CSS_ALIGN_CENTER;
    }
    else if(!strcmp(value, "flex-start")){
        current_css_widget->align_self = CSS_ALIGN_FLEX_START;
    }
    else if(!strcmp(value, "flex-end")){
        current_css_widget->align_self = CSS_ALIGN_FLEX_END;
    }
    else if(!strcmp(value, "baseline")){
        current_css_widget->align_self = CSS_ALIGN_BASELINE;
    }
}
