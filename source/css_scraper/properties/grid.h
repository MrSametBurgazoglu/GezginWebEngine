//
// Created by samet on 31.07.2022.
//

#ifndef UNTITLED_GRID_H
#define UNTITLED_GRID_H

#include "css_enum_variables.h"
#include "../css_widget.h"

struct grid_row{
    css_property_value_type gridRowStartValueType;
    css_property_value_type gridRowEndValueType;
    int grid_row_start;
    int grid_row_end;
};


struct grid_column{
    css_property_value_type gridColumnStartValueType;
    css_property_value_type gridColumnEndValueType;
    int grid_column_start;
    int grid_column_end;
};

struct grid_template_item{
    css_property_value_type valueType;
    int value;
};

struct grid_template{
    bool grid_template_rows_inherit;
    bool grid_template_columns_inherit;
    char* grid_template_areas;
    int grid_template_rows_count;
    int grid_template_columns_count;
    struct grid_template_item** gridTemplateRowsValue;
    struct grid_template_item** gridTemplateColumnsValue;
};

struct grid_auto{
    css_property_value_type gridAutoRowsValueType;
    css_property_value_type gridAutoColumnsValueType;
    int grid_auto_rows;
    int grid_auto_columns;
    int grid_auto_columns_max;
    css_grid_auto_flow_type gridAutoFlowType;
};

struct grid_gap{
    css_property_value_type gridRowGapValueType;
    css_property_value_type gridColumnGapValueType;
    int grid_row_gap;
    int grid_column_gap;
};

struct grid{
    struct grid_row* gridRow;
    struct grid_column* gridColumn;
    struct grid_template* gridTemplate;
    struct grid_auto* gridAuto;
    struct grid_gap* gridGap;
};

void grid_property_set_value(struct css_properties*, char*);
void grid_area_property_set_value(struct css_properties*, char*);
void grid_auto_columns_property_set_value(struct css_properties*, char*);
void grid_auto_flow_property_set_value(struct css_properties*, char*);
void grid_auto_rows_property_set_value(struct css_properties*, char*);
void grid_column_property_set_value(struct css_properties*, char*);
void grid_column_end_property_set_value(struct css_properties*, char*);
void grid_column_gap_property_set_value(struct css_properties*, char*);
void grid_column_start_property_set_value(struct css_properties*, char*);
void grid_gap_property_set_value(struct css_properties*, char*);
void grid_row_property_set_value(struct css_properties*, char*);
void grid_row_end_property_set_value(struct css_properties*, char*);
void grid_row_gap_property_set_value(struct css_properties*, char*);
void grid_row_start_property_set_value(struct css_properties*, char*);
void grid_template_property_set_value(struct css_properties*, char*);
void grid_template_areas_property_set_value(struct css_properties*, char*);
void grid_template_columns_property_set_value(struct css_properties*, char*);
void grid_template_rows_property_set_value(struct css_properties*, char*);


#endif //UNTITLED_GRID_H
