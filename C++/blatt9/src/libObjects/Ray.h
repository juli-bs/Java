#ifndef SMALLPT_RAY_H
#define SMALLPT_RAY_H


#include "Vec.h"


struct Ray {

    Vec o, d;

    Ray(Vec o_, Vec d_) : o(o_), d(d_) {

    }

};


#endif //SMALLPT_RAY_H
