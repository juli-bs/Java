#ifndef SMALLPT_APP_H
#define SMALLPT_APP_H


#include "../libObjects/Vec.h"
#include "../libObjects/Ray.h"
#include "../libObjects/Sphere.h"



Vec radiance(Ray const &r, int depth, unsigned short *Xi); // BONUS-AUFGABE 2 - const rechts von dem Typ der const gemacht werden soll
Vec returnIdealDiffuseReflection(unsigned short *Xi, int depth, Vec nl, Sphere const& hitObject, Vec x);

int toInt(double x);

bool intersect(Ray const &r, double &t, int &id);// BONUS-AUFGABE 2 - const rechts von dem Typ der const gemacht werden soll

double getMaxReflection(Vec const &hitObjectColor);
double erand48(unsigned short Xi[3]);
double clamp(double x);

void loopOverImage(int samples, Ray camera, Vec directionX, Vec directionY, Vec r, Vec *c);
void writeFile(Vec* c);


#endif //SMALLPT_APP_H
