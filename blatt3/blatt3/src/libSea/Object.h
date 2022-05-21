#ifndef BLATT3_OBJECT_H
#define BLATT3_OBJECT_H


#include "Coordinates.h"


namespace Sea {

    enum class Orientation {
        X,
        Y
    };

    class Object : public Coordinates {
    protected:
        unsigned int const size;
        Orientation const orientation;

    public:
        Object(Coordinates const & newCoordinates, unsigned int newSize, Orientation newOrientation);

        bool atCoordinates(Coordinates const & coordinates) const;
        bool intersectsWith(Object const & otherObject) const;
    };

}


#endif //BLATT3_OBJECT_H
