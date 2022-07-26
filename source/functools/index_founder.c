//
// Created by samet on 17.06.2022.
//

#include "index_founder.h"
#include "string.h"

int get_index_from_list_by_string(char** list, char* value, int length){
    int l, m, r, result;
    l = 0;
    r = length;

    while (l <= r) {
        m = l + (r - l) / 2;
        result = strcmp(list[m], value);

        if (result == 0) return m;
        if (result < 0) l = m + 1;
        else r = m - 1;
    }
    return -1;
}