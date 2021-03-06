#ifndef SMALLPT_VEC_H
#define SMALLPT_VEC_H


#include <math.h>


struct Vec {

    double x, y, z;

    // position, also color (r,g,b)
    Vec(double x_ = 0, double y_ = 0, double z_ = 0) {
        x = x_;
        y = y_;
        z = z_;
    }

    Vec operator+(Vec const &b) const { // BONUS-AUFGABE 2 - const rechts von dem Typ der const gemacht werden soll
        return Vec(x + b.x, y + b.y, z + b.z);
    }

    Vec operator-(Vec const &b) const { // BONUS-AUFGABE 2 - const rechts von dem Typ der const gemacht werden soll
        return Vec(x - b.x, y - b.y, z - b.z);
    }

    Vec operator*(double b) const {
        return Vec(x * b, y * b, z * b);
    }

    void operator+=(Vec const &b) {
        x += b.x;
        y += b.y;
        z += b.z;
    }

    [[nodiscard]] // BONUS-AUFGABE 2
    Vec mult(Vec const &b) const { // BONUS-AUFGABE 2 - const rechts von dem Typ der const gemacht werden soll
        return ((x * b.x), (y * b.y), (z * b.z)); // BONUS-AUFGABE 2 - Avoid repeating the return type
    }

    Vec &norm() {
        return *this = *this * (1 / sqrt(x * x + y * y + z * z));
    }

    [[nodiscard]] // BONUS-AUFGABE 2
    double dot(Vec const &b) const { // BONUS-AUFGABE 2 - const rechts von dem Typ der const gemacht werden soll
        return x * b.x + y * b.y + z * b.z;
    } // cross:

    Vec operator%(Vec &b) const { // BONUS-AUFGABE 2 - Methode const gemacht
        return ((y * b.z - z * b.y), (z * b.x - x * b.z), (x * b.y - y * b.x)); // BONUS-AUFGABE 2 - Avoid repeating the return type
    }

};


#endif //SMALLPT_VEC_H
