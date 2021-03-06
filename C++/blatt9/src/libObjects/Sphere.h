#ifndef SMALLPT_SPHERE_H
#define SMALLPT_SPHERE_H


#include "Vec.h"
#include "Ray.h"


enum Refl_t {

    DIFF, SPEC, REFR

};  // material types, used in radiance()


struct Sphere {

    double rad;       // radius

    Vec position;
    Vec emission;
    Vec color;      // position, emission, color

    Refl_t refl;      // reflection type (DIFFuse, SPECular, REFRactive)

    Sphere(double rad_, Vec p_, Vec e_, Vec c_, Refl_t refl_) :
            rad(rad_), position(p_), emission(e_), color(c_), refl(refl_) {

    }

    [[nodiscard]] //BONUS-AUFGABE 2
    double intersect(const Ray &r) const { // returns distance, 0 if nohit

        Vec op = position - r.o; // Solve t^2*d.d + 2*t*(o-p).d + (o-p).(o-p)-R^2 = 0

        double t;
        double eps = 1e-4;
        double b = op.dot(r.d);
        double det = b * b - op.dot(op) + rad * rad;

        if (det < 0) {
            return 0;
        } else {
            det = sqrt(det);
        }
        return (t = b - det) > eps ? t : ((t = b + det) > eps ? t : 0);

    }

};


#endif //SMALLPT_SPHERE_H
