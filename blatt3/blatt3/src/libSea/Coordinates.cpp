#include "Coordinates.h"


namespace Sea {

    Coordinates::Coordinates(unsigned int newX, unsigned int newY)
    : x(newX), y(newY)
    {
    }

    bool Coordinates::samePositionAs(unsigned int otherX, unsigned int otherY) const
    {
        return x == otherX && y == otherY;
    }

    bool Coordinates::samePositionAs(Coordinates const & otherCoordinates) const
    {
        return samePositionAs(otherCoordinates.x, otherCoordinates.y);
    }

    unsigned int Coordinates::getX() const
    {
        return x;
    }

    unsigned int Coordinates::getY() const
    {
        return y;
    }

}
