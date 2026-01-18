#ifndef VEC3_H    // Making sure VEC3 is NOT defined if header is defined in multiple files
#define VEC3_H    // Defining VEC3

#include <cmath>
#include <iostream>

class vec3{
    public:
        double e[3];

        vec3(): e{0, 0, 0} {} // initializes a vector starting at the origin
        vec3(double e0, double e1, double e2): e{e0, e1, e2} {} // initializes vector generally
        
        double x() const{ return e[0]; } // functions to return our (x,y,z) coordinates
        double y() const{ return e[1]; }
        double z() const{ return e[2]; }

        // Vector operations

        vec3 operator-() const{ return vec3(-e[0], -e[1], -e[2]); } // gives colinear vector in opposite direction
        double operator[](int i) const{ return e[i]; }
        double& operator[](int i) { return e[i]; }

        vec3& operator+=(const vec3& v){
            e[0] += v.e[0]; // Adding constant vector to current vector v 
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        vec3& operator*=(double t){
            e[0]*= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3& operator/=(double t){
            return *this *= 1/t; 
        }

        double length_sq() const{
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        double length() const{
            return std::sqrt(length_sq());
        }

};

using point3 = vec3; // point3 is an alias for vec3, used for geometric clarity.

// Vector Utility Functions

inline std::ostream& operator <<(std::ostream& out, const vec3& v){
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2]; 
}

inline vec3 operator+(const vec3& u, const vec3& v){
    return vec3(u.e[0] +v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v){
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v){
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v){
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*=(const vec3& v, double t){
    return vec3(v.e[0] * (1/t), v.e[1] * (1/t), v.e[2] * (1/t));
}

inline vec3 operator*(const vec3& v, double t){
    return v * t;
}

inline double dot_prod(const vec3& u, const vec3&v){
    return v.e[0]*u.e[0] + v.e[1]*u.e[1] + v.e[2]*u.e[2];
}

inline vec3 cross_prod(const vec3& u, const vec3& v){
    return vec3((u.e[1]*v.e[2]) - (u.e[2]*v.e[1]),
                (u.e[2]*v.e[0]) - (u.e[0]*v.e[2]),
                (u.e[0]*v.e[1]) - (u.e[1]*v.e[0]));
}

inline vec3 unit(const vec3& v){
    return v*=(v.length());
}

#endif


