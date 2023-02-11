#include <iostream>

#include "vector.h"
#include "color.h"

int main() {
    
    // Image

    const int image_width = 256;
    const int image_height = 256;

    // Render

    //Imprime la talla
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    //Normaliza los valores de  color
    
    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            obj_Color pixel(double(i)/(image_width - 1), double(j)/(image_height - 1), 0.25);
            // double in the i and j is necessary, if not, image is black
            color_panel(std::cout, pixel); // Entender mejor
        }
    }
    
    std::cerr << "\nDone.\n";
    
    /*
    // vector.h tests
    obj_Vector vector3(1,2,3);
    std::cout << "\n" << vector3.get_value0() << vector3.get_value1() 
                << vector3.get_value2() << "\n";

    vector3 = vector3.operator-();
    std::cout << "\n" << vector3.get_value0() << vector3.get_value1() 
                << vector3.get_value2() << "\n";

    double a = vector3.operator[](1);
    double b = vector3.get_value1();
    double& c = vector3.operator[](1);
    std::cout << "\n" << a << b << c << "\n";

    obj_Vector vector1(1,2,3);
    vector3.operator+=(vector1);
    std::cout << "\n" << vector3.get_value0() << vector3.get_value1() 
                << vector3.get_value2() << "\n";
    std::cout << "\n" << vector1.get_value0() << vector1.get_value1() 
                << vector1.get_value2() << "\n";

    vector1.operator*=(2);
    std::cout << "\n" << vector1.get_value0() << vector1.get_value1() 
                << vector1.get_value2() << "\n";
    
    
    std::cout << "\n" << vector1.length_squared() << ' ' << vector1.length() 
                << vector1.get_value2() << "\n";
    
    */
}