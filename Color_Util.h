#ifndef COLOR_H
#define COLOR_H

#include "vector_stor.h"
#include <iostream>

using color = vec3;

void write_color(std::ostream& out, const color& pixc){
    auto r = pixc.x();
    auto g = pixc.y();
    auto b = pixc.z();
    
    // Translate the [0,1] component values to the PPM-format byte range [0,256)
    int rbyte = int(255.999 *r);
    int bbyte = int(255.999 *g);
    int gbyte = int(255.999 *b);

    // Pixel color components:
    out << rbyte << ' ' << bbyte << ' ' << gbyte << '\n';
}

#endif

