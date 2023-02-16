#ifndef COLOR_H
#define COLOR_H

#include <iostream>

#include "vector.h"
using obj_Color = obj_Vector;

void color_printer(std::ostream &out,obj_Color arg_c){
    out << static_cast<int>(255.9 * arg_c.get_value0()) << ' '
        << static_cast<int>(255.9 * arg_c.get_value1()) << ' '
        << static_cast<int>(255.9 * arg_c.get_value2()) << '\n';
}

#endif