#ifndef COLOR_H
#define COLOR_H

#include <iostream>

#include "vector.h"
using obj_Color = obj_Vector;

void color_panel(std::ostream &out,obj_Color param_Color){
    out << static_cast<int>(255.999 * param_Color.get_value0()) << ' '
        << static_cast<int>(255.999 * param_Color.get_value1()) << ' '
        << static_cast<int>(255.999 * param_Color.get_value2()) << '\n';
}

#endif