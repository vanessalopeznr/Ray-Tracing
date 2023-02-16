#ifndef SPHERE_H
#define SPHERE_H

#include "figure.h"
#include "vector.h"

class obj_Sphere : public figure {
    private:
        obj_Point attri_Cen;
        double attri_R;

    public:
        obj_Sphere() {};
        obj_Sphere(obj_Point center, double radius) : attri_Cen(center), attri_R(radius) {}; 

        bool hit(const obj_Ray& ray, double t_min, double t_max, obj_Record& record) const;
        // On appelle la fonctionne hit qui viens de object, et on la recrie
};

bool obj_Sphere::hit(const obj_Ray& ray, double t_min, double t_max, obj_Record& record) const {
    obj_Vector vec = ray.get_orig() - attri_Cen; // Vecteur jusqu'a le centre
    // Tout aprés c'est le équation : t^2*b*b + 2*t*b*(A-C) + (A-C)*(A-C) - r
    //                t^2*ray.get_dir + 2*t*ray.get_dir*vec + vec*vec - radius
    double a = ray.get_dir().length_squared(); 
    double b = 2 * dot(vec, ray.get_dir());
    double c = vec.length_squared() - attri_R * attri_R;
    double discriminant = (b * b) - (4 * a * c);
    
    if (discriminant < 0) { // Si le root est pas réel
        return false;
    }  

    // Si le root (qui est = t) est réel, on cherche la plus proche
    // root ou t sont où je touch l'esphere
    double root = (-b - sqrt(discriminant)) / (2 * a); // -b^2 -...
    if (root < t_min || root > t_max) {
        root = (-b + sqrt(discriminant)) / (2 * a); // -b^2 +...
        if (root < t_min || root > t_max) {
            return false;
        }
    }

    // On garde dans le record les informations. (le t plus proche), son point et normal
    record.attri_t = root;
    record.attri_Point = ray.function(record.attri_t); // le point au hauteur du t
    obj_Vector noraml_dir = (record.attri_Point - attri_Cen) / attri_R;
    record.normal_face(ray, noraml_dir);
    
    return true; 
} 



#endif