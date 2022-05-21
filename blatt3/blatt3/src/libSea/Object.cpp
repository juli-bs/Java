#include "Object.h"


namespace Sea {

    Object::Object(Coordinates const & newCoordinates, unsigned int newSize, Sea::Orientation newOrientation)
    : Coordinates(newCoordinates), size(newSize), orientation(newOrientation)
    {
    }

    bool Object::atCoordinates(Coordinates const & coordinates) const {
        if(orientation == Orientation::X) {
            if(x < coordinates.getX() && x + size > coordinates.getX()) {
                return true;
            }
        } else {
            if(y < coordinates.getY() && y + size > coordinates.getY()) {
                return true;
            }
        }

        return false;
    }

    bool Object::intersectsWith(Object const & otherObject) const {

        if(orientation == Orientation::X) {

            for(int i = x; i < x + size; i++) {
                if(atCoordinates(Coordinates(i, y)) && otherObject.atCoordinates(Coordinates(i, otherObject.getY()))) {
                    return true;
                }
            }

        } else {

            for(int i = y, i < y + size; i++) {
                if(atCoordinates(Coordinates(x, i)) && otherObject.atCoordinates(Coordinates(otherObject.getX(), i))) {
                    return true;
                }
            }

        }

        return false;

    }

}
