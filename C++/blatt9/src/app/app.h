#ifndef SMALLPT_APP_H
#define SMALLPT_APP_H


#include <vector>

#include "../libObjects/Vec.h"
#include "../libObjects/Ray.h"
#include "../libObjects/Sphere.h"



Vec radiance(Ray const &r, int depth, std::vector<int>& Xi); // BONUS-AUFGABE 2 - const rechts von dem Typ der const gemacht werden soll
// BONUS-AUFGABE 5 Übergabe von Referenzen
Vec returnIdealDiffuseReflection(std::vector<int>& Xi, int& depth, Vec& nl, Sphere const& hitObject, Vec& x); // BONUS-AUFGABE 5 Übergabe von Referenzen

int toInt(double& x);// BONUS-AUFGABE 5 Übergabe von Referenzen

bool intersect(Ray const &r, double &t, int &id);// BONUS-AUFGABE 2 - const rechts von dem Typ der const gemacht werden soll

double getMaxReflection(Vec const &hitObjectColor);
double erand48();
double clamp(double& x);// BONUS-AUFGABE 5 Übergabe von Referenzen

void loopOverImage(int& samples, Ray& camera, Vec& directionX, Vec& directionY, Vec& r, std::vector<Vec>& pixelArray);// BONUS-AUFGABE 5 Übergabe von Referenzen
void writeFile(std::vector<Vec> pixelArray);


#endif //SMALLPT_APP_H
