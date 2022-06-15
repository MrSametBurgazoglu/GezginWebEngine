//
// Created by samet on 23.04.2022.
//

#ifndef UNTITLED_BOX_SHADOW_H
#define UNTITLED_BOX_SHADOW_H

#include <stdbool.h>
#include "css_color.h"

struct box_shadow{
    int h_offset;
    int v_offset;
    int blur;
    int spread;
    struct color_rgba* color;
    bool inset;
};

#endif //UNTITLED_BOX_SHADOW_H
