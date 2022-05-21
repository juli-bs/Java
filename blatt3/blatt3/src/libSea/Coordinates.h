#ifndef BLATT3_COORDINATES_H
#define BLATT3_COORDINATES_H


namespace Sea {

    class Coordinates {
    protected:
        unsigned int x, y;

    public:
        Coordinates(unsigned int newX, unsigned int newY);

        bool samePositionAs(unsigned int otherX, unsigned int otherY) const;
        bool samePositionAs(Coordinates const & otherCoordinates) const;

        unsigned int getX() const;
        unsigned int getY() const;
    };

}


#endif //BLATT3_COORDINATES_H
