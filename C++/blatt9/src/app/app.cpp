#include "app.h"

#include <stdio.h>
#include <vector>
using std::vector;
#include <future>
using std::async;

#include "Constants.h"


vector<Sphere> spheres = {
        Sphere(1e5, Vec(1e5 + 1, 40.8, 81.6), Vec(), Vec(.75, .25, .25), DIFF),//Left
        Sphere(1e5, Vec(-1e5 + 99, 40.8, 81.6), Vec(), Vec(.25, .25, .75), DIFF),//Rght
        Sphere(1e5, Vec(50, 40.8, 1e5), Vec(), Vec(.75, .75, .75), DIFF),//Back
        Sphere(1e5, Vec(50, 40.8, -1e5 + 170), Vec(), Vec(), DIFF),//Frnt
        Sphere(1e5, Vec(50, 1e5, 81.6), Vec(), Vec(.75, .75, .75), DIFF),//Botm
        Sphere(1e5, Vec(50, -1e5 + 81.6, 81.6), Vec(), Vec(.75, .75, .75), DIFF),//Top
        Sphere(16.5, Vec(27, 16.5, 47), Vec(), Vec(1, 1, 1) * .999, SPEC),//Mirr
        Sphere(16.5, Vec(73, 16.5, 78), Vec(), Vec(1, 1, 1) * .999, REFR),//Glas
        Sphere(600, Vec(50, 681.6 - .27, 81.6), Vec(12, 12, 12), Vec(), DIFF) //Lite
};


Vec radiance(const Ray &r, int depth, unsigned short *Xi) {

    double distanceToIntersection;                               // distance to intersection
    int intersectedObjectID = 0;                               // id of intersected object

    if (!intersect(r, distanceToIntersection, intersectedObjectID)) {
        return Vec(); // if miss, return black
    }

    const Sphere &hitObject = spheres[intersectedObjectID];        // the hit object

    Vec x = r.o + r.d * distanceToIntersection;
    Vec n = (x - hitObject.position).norm();
    Vec nl = n.dot(r.d) < 0 ? n : n * -1;
    Vec hitObjectColor = hitObject.color;

    double maxRefl = getMaxReflection(hitObjectColor); // max refl

    if (++depth > 5) {
        if (erand48(Xi) < maxRefl) {
            hitObjectColor = hitObjectColor * (1 / maxRefl);
        } else {
            return hitObject.emission; //R.R.
        }
    }
    if (hitObject.refl == DIFF) {                  // Ideal DIFFUSE reflection
        returnIdealDiffuseReflection(Xi, depth, nl, hitObject, x);
    } else if (hitObject.refl == SPEC) {          // Ideal SPECULAR reflection
        return hitObject.emission + hitObjectColor.mult(radiance(Ray(x, r.d - n * 2 * n.dot(r.d)), depth, Xi));
    }

    Ray reflRay(x, r.d - n * 2 * n.dot(r.d));     // Ideal dielectric REFRACTION

    bool rayFromOutside = n.dot(nl) > 0;                // Ray from outside going in?

    double nnt = rayFromOutside ? (1 / 1.5) : (1.5 / 1);
    double ddn = r.d.dot(nl);
    double cos2t;

    if ((cos2t = 1 - nnt * nnt * (1 - ddn * ddn)) < 0) {  // Total internal reflection
        return hitObject.emission + hitObjectColor.mult(radiance(reflRay, depth, Xi));
    }

    Vec tdir = (r.d * nnt - n * ((rayFromOutside ? 1 : -1) * (ddn * nnt + sqrt(cos2t)))).norm();

    double c = 1 - (rayFromOutside ? -ddn : tdir.dot(n));

    double Re = 0.04 + (1 - 0.04) * c * c * c * c * c;
    double Tr = 1 - Re;
    double P = .25 + .5 * Re;
    double RP = Re / P;
    double TP = Tr / (1 - P);

    return hitObject.emission + hitObjectColor.mult((depth > 2) ? (erand48(Xi) < P ?   // Russian roulette
                                                                   radiance(reflRay, depth, Xi) * RP :
                                                                   radiance(Ray(x, tdir), depth, Xi) * TP) :
                                                    radiance(reflRay, depth, Xi) * Re +
                                                    radiance(Ray(x, tdir), depth, Xi) * Tr);

}

Vec returnIdealDiffuseReflection(unsigned short *Xi, int depth, Vec nl, Sphere const& hitObject, Vec x) {

    double r1 = 2 * M_PI * erand48(Xi);
    double r2 = erand48(Xi);
    double r2s = sqrt(r2);

    Vec w = nl;
    Vec u = (((fabs(w.x) > .1) ? Vec(0, 1) : Vec(1)) % w).norm();
    Vec v = w % u;

    Vec d = (u * cos(r1) * r2s + v * sin(r1) * r2s + w * sqrt(1 - r2)).norm();

    return hitObject.emission + hitObject.color.mult(radiance(Ray(x, d), depth, Xi));

}

double getMaxReflection(Vec const &hitObjectColor) {

    return ((hitObjectColor.x > hitObjectColor.y) && (hitObjectColor.x > hitObjectColor.z)) ?
           hitObjectColor.x : (hitObjectColor.y > hitObjectColor.z ? hitObjectColor.y
                                                                   : hitObjectColor.z);

}

bool intersect(const Ray &r, double &t, int &id) {

    double n = sizeof(spheres) / sizeof(Sphere), inf = t = 1e20;
    bool d;
    for (int i = int(n); i--;) {
        if ((d = spheres[i].intersect(r)) && d < t) {
            t = d;
            id = i;
        }
    }
    return t < inf;

}

double erand48(unsigned short Xi[3]) {

    return double(rand()) / RAND_MAX;

} // added for compatibility

void loopOverImage(int samples, Ray camera, Vec directionX, Vec directionY, Vec r, Vec *c) {

    for (int row = 0; row < HEIGHT; row++) {                       // Loop over image rows
        fprintf(stderr, "\rRendering (%d spp) %5.2f%%", samples * 4, 100. * row / (HEIGHT - 1));

        auto newRow = async(std::launch::deferred, [&]() {
            for (unsigned short column = 0, Xi[3] = {0, 0, static_cast<unsigned short>(row * row * row)};
                 column < WIDTH; column++) { // Loop cols
                for (int subpixelRow = 0, i = (HEIGHT - row - 1) * WIDTH + column;
                     subpixelRow < 2; subpixelRow++) {  // 2x2 subpixel rows
                    for (int subpixelColumn = 0;
                         subpixelColumn < 2; subpixelColumn++, r = Vec()) {        // 2x2 subpixel cols
                        for (int s = 0; s < samples; s++) {
                            double r1 = 2 * erand48(Xi);
                            double dx = r1 < 1 ? sqrt(r1) - 1 : 1 - sqrt(2 - r1);
                            double r2 = 2 * erand48(Xi);
                            double dy = r2 < 1 ? sqrt(r2) - 1 : 1 - sqrt(2 - r2);

                            Vec d = directionX * (((subpixelColumn + .5 + dx) / 2 + column) / WIDTH - .5) +
                                    directionY * (((subpixelRow + .5 + dy) / 2 + row) / HEIGHT - .5) + camera.d;

                            r = r + radiance(Ray(camera.o + d * 140, d.norm()), 0, Xi) * (1. / samples);
                        } // Camera rays are pushed ^^^^^ forward to start in interior
                        c[i] = c[i] + Vec(clamp(r.x), clamp(r.y), clamp(r.z)) * .25;
                    }
                }
            }
        });

    }

}

double clamp(double x) {

    return x < 0 ? 0 : x > 1 ? 1 : x;

}


int toInt(double x) {

    return int(pow(clamp(x), 1 / 2.2) * 255 + .5);

}

void writeFile(Vec *c) {

    FILE *f = fopen("image.ppm", "w");         // Write image to PPM file.
    fprintf(f, "P3\n%d %d\n%d\n", WIDTH, HEIGHT, 255);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        fprintf(f, "%d %d %d ", toInt(c[i].x), toInt(c[i].y), toInt(c[i].z));
    }

}
