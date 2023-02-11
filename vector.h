#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iostream>

using std::sqrt;

class obj_Vector { 
    private:
        double attri_Value[3];

    public:
        // Constructores
        obj_Vector() : attri_Value{0,0,0} {}
        obj_Vector(double value0, double value1, double value2) 
                    : attri_Value{value0, value1, value2} 
        {}

        // Metodos get
        double get_value0() const {
            return attri_Value[0];
        }

        double get_value1() const {
            return attri_Value[1];
        }

        double get_value2() const {
            return attri_Value[2];
        }

        // Operadores
        // Turns negative all values
        obj_Vector operator -() const {
            return obj_Vector(-attri_Value[0], -attri_Value[1], -attri_Value[2]);
        }

        // Same as gets???????????????????????????
        // Let us read the values
        double operator [](int param_Position) const {
            return attri_Value[param_Position];
        }

        // Revisarrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
        // Let us use the objet directly and modifie it if we want to
        double& operator [](int param_Position) {
            return attri_Value[param_Position];
        }

        // Makes additions of himself on himself, it doesnt create a copy
        obj_Vector& operator += (const obj_Vector &param_Vector) {
            attri_Value[0] += param_Vector.attri_Value[0];
            attri_Value[1] += param_Vector.attri_Value[1];
            attri_Value[2] += param_Vector.attri_Value[2];
            return *this;  // Returns the same object in which the methode was called
        }

        // Makes a multiplication with a constant, it is directly to the object, not a copy
        obj_Vector& operator *= (const double param_Multiplier) {
            attri_Value[0] *= param_Multiplier;
            attri_Value[1] *= param_Multiplier;
            attri_Value[2] *= param_Multiplier;
            return *this;  // Returns the same object in which the methode was called
        }
        
        double length_squared() const {
            return attri_Value[0]*attri_Value[0] + attri_Value[1]*attri_Value[1] + attri_Value[2]*attri_Value[2];
        }
        double length() const {
            return sqrt(length_squared());
        }
};

#endif