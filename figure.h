#ifndef FIGURE_H
#define FIGURE_H

#include "ray.h"

struct obj_Record {
    obj_Point attri_Point;
    obj_Vector attri_Normal;
    double attri_t;
    bool attri_dir_n;

    void normal_face(const obj_Ray& ray, const obj_Vector& normal_dir) {
        attri_dir_n = dot(ray.get_dir(), normal_dir) < 0; // Pour savoir le direction 
        // du le vecteur normal
        if (attri_dir_n = true) {
            attri_Normal = normal_dir;
        } else {
            attri_Normal = -normal_dir;
        }
    }
};

class figure {
    public:
        virtual bool hit(const obj_Ray& ray, double t_min, double t_max, obj_Record& record) const = 0;
        // abstract base class
        // on doit l'utiliser dans une autre class (heritage)
};

#endif