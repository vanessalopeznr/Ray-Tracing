#ifndef RAY_H
#define RAY_H

#include "vector.h"
using obj_Point = obj_Vector;

class obj_Ray {
    private:
        obj_Point attri_Origin;
        obj_Point attri_Direction;

    
    public:
        obj_Ray() {}
        obj_Ray(const obj_Point& param_Origin, const obj_Point& param_Direction)
                : attri_Origin(param_Origin), attri_Direction(param_Direction) 
        {}
};

#endif