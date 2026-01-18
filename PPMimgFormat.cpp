#include "vector_stor.h"
#include "Color_Util.h"

#include <iostream>



int main(){
    // Image width & height 
    int img_w = 256;
    int img_h = 256;
    int maxval = 255;

    // Rendering as a PPM image
    std::cout << "P3\n" << img_w << ' ' << img_h << "\n" << maxval << "\n";
    // makes 256x256 grid of values
    // These (R,G,B) components are represented by real values between 0 and 1 inclusive, \
    which are then scaled to values between 0 and 255
    for (int j = 0; j < img_h; ++j){
        std::clog << "\rScanlines remaining: " << (img_h - j) << ' ' << std::flush; 

        for (int i = 0; i < img_w; i++){
            auto pixel_color = color(double((i)/=(img_w-1)), double((j)/=(img_h-1)), 0);
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "r/Done.    \n";

    return 0;

}