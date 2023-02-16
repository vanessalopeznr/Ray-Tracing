#ifndef RAY_H
#define RAY_H

#include "vector.h"
using obj_Point = obj_Vector;

class obj_Ray {
    private:
        obj_Point attri_Orig;
        obj_Point attri_Dir;

    
    public:
        // Constructeurs
        obj_Ray() {}
        obj_Ray(const obj_Point& origin, const obj_Point& direction)
                : attri_Orig(origin), attri_Dir(direction) 
        {}

        // Description gets
        obj_Point get_orig() const {
            return attri_Orig;
        }

        obj_Point get_dir() const {
            return attri_Dir;
        }

        // La fonction d'un ligne, P = A + t*b
        obj_Point function(double arg_t) const {
            return attri_Orig + arg_t * attri_Dir;
        }
};

#endif