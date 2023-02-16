#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iostream>

using std::sqrt;

class obj_Vector { 
    private:
        double attri_V[3];

    public:
        // Constructores
        obj_Vector() : attri_V{0,0,0} {}
        obj_Vector(double value0, double value1, double value2) 
                    : attri_V{value0, value1, value2} 
        {}

        // Metodos get
        double get_value0() const {
            return attri_V[0];
        }

        double get_value1() const {
            return attri_V[1];
        }

        double get_value2() const {
            return attri_V[2];
        }

        // Operadores
        // Turns negative all values, but the result its a copy
        obj_Vector operator -() const {
            return obj_Vector(-attri_V[0], -attri_V[1], -attri_V[2]);
        }

        /*
        // Same as gets???????????????????????????
        // Let us read the values
        double operator [](int arg_i) const {
            return attri_V[arg_i];
        }

        // Revisarrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
        // Let us use the objet directly and modifie it if we want to
        // Le & permet d'accéder à la variable double qui existe déjà
        double& operator [](int arg_i) {
            return attri_V[arg_i];
        }
        */

        // Makes additions of himself on himself, it doesnt create a copy
        obj_Vector& operator += (const obj_Vector &arg_v) {
            attri_V[0] += arg_v.attri_V[0];
            attri_V[1] += arg_v.attri_V[1];
            attri_V[2] += arg_v.attri_V[2];
            return *this;  // Returns the same object in which the methode was called
        }

        // Makes a multiplication with a constant, it is directly to the object, not a copy
        obj_Vector& operator *= (const double arg_t) {
            attri_V[0] *= arg_t;
            attri_V[1] *= arg_t;
            attri_V[2] *= arg_t;
            return *this;  // Returns the same object in which the methode was called
        }
        
        double length_squared() const {
            return attri_V[0]*attri_V[0] + attri_V[1]*attri_V[1] + attri_V[2]*attri_V[2];
        }
        double length() const {
            return sqrt(length_squared());
        }
        
};

// Operateur pour multiplication, definition du multiplication fois un scalar
obj_Vector operator *(double arg_a, const obj_Vector &arg_v) {
    return obj_Vector(arg_a*arg_v.get_value0(), arg_a*arg_v.get_value1(), arg_a*arg_v.get_value2());
}
// REVISARRRR!!!!!, SON IGUALES, SI ALGO BORRAR EL DE ARRIBA NO EL DE ABAJO, ESCRIBEME ANTES
obj_Vector operator *(const obj_Vector &arg_v, double arg_a) {
    return obj_Vector(arg_a*arg_v.get_value0(), arg_a*arg_v.get_value1(), arg_a*arg_v.get_value2());
}

// Definition du multiplication entre des vecteurs
obj_Vector operator *(const obj_Vector &arg_v1, const obj_Vector &arg_v2) {
    return obj_Vector(arg_v1.get_value0() * arg_v2.get_value0(), 
                        arg_v1.get_value1() * arg_v2.get_value1(), 
                        arg_v1.get_value2() * arg_v2.get_value2());
}

double dot(const obj_Vector &arg_v1, const obj_Vector &arg_v2) {
    return arg_v1.get_value0() * arg_v2.get_value0()
            + arg_v1.get_value1() * arg_v2.get_value1()
            + arg_v1.get_value2() * arg_v2.get_value2();
}
// Definition de la division
obj_Vector operator /(obj_Vector arg_v, double arg_a) {
    return (1/arg_a) * arg_v;
}

// Definition du sum entre des vecteurs
obj_Vector operator +(const obj_Vector &arg_v1, const obj_Vector &arg_v2) {
    return obj_Vector(arg_v1.get_value0() + arg_v2.get_value0(), 
                        arg_v1.get_value1() + arg_v2.get_value1(), 
                        arg_v1.get_value2() + arg_v2.get_value2());
}

// Definition de la substraction entre des vecteurs
obj_Vector operator -(const obj_Vector &arg_v1, const obj_Vector &arg_v2) {
    return obj_Vector(arg_v1.get_value0() - arg_v2.get_value0(), 
                        arg_v1.get_value1() - arg_v2.get_value1(), 
                        arg_v1.get_value2() - arg_v2.get_value2());
}

// Unitarisation du vecteur
obj_Vector unit_vector(obj_Vector arg_v) {
    return arg_v / arg_v.length();
}

#endif