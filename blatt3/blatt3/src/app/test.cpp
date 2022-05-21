// TODO:
//  Entfernt die Kommentar-Zeichen (//) für Aufgaben, die erledigt sind und getestet werden sollen:

#define TEST_AUFGABE_2 // TODO Aufgabe 2
//#define TEST_AUFGABE_3 // TODO Aufgabe 3
//#define TEST_AUFGABE_4 // TODO Aufgabe 4


#include "test.h"

#include <iostream>
using std::cout;
using std::endl;

#include "Object.h"
using Sea::Object;
using Sea::Coordinates;
using Sea::Orientation;

#include "Missile.h"
#ifdef CLASS_MISSILE_COMPLETE
using GameObjects::Missile;
#endif

#include "Ship.h"
using GameObjects::Ship;


bool testPassed()
{
    bool testResult =
            testObjectIntersection() &&
            testMissile() &&
            testShip();

    if (testResult) {
        cout << "Test OK." << endl;
        return true;
    }
    cout << "Test fehlgeschlagen." << endl;
    return false;
}

bool testObjectIntersection()
{
#ifdef TEST_AUFGABE_2
    Object const o0(Coordinates(0, 1), 3, Orientation::X);
    Object const o1(Coordinates(0, 0), 3, Orientation::X);
    Object const o2(Coordinates(2, 1), 3, Orientation::X);
    Object const o3(Coordinates(0, 0), 3, Orientation::Y);
    Object const o4(Coordinates(1, 0), 3, Orientation::Y);
    Object const o5(Coordinates(2, 0), 3, Orientation::Y);
    return
        o0.intersectsWith(o0) &&
        !o0.intersectsWith(o1) &&
        o0.intersectsWith(o2) &&
        o0.intersectsWith(o3) &&
        o0.intersectsWith(o4) &&
        o0.intersectsWith(o5);
#else
    return true;
#endif
}

bool testMissile()
{
#ifdef TEST_AUFGABE_3
    Missile missile(Coordinates(1, 2));
    bool const hitBefore = missile.hasHitSomething();
    missile.hitSomething();
    bool const hitAfter = missile.hasHitSomething();
    return
        !hitBefore &&
        hitAfter &&
        missile.getX() == 1 &&
        missile.getY() == 2;
#else
    return true;
#endif
}

bool testShip()
{
#ifdef TEST_AUFGABE_4
    Ship ship(Coordinates(1, 1), 2, Orientation::X);
    Missile missile1(Coordinates(1, 1));
    Missile missile2(Coordinates(2, 1));
    bool const shipBefore = ship.isDestroyed();
    bool missileBefore = missile1.hasHitSomething();
    ship.checkAndUpdateIncomingMissile(missile1);
    bool const shipBetween = ship.isDestroyed();
    bool const missileAfter = missile1.hasHitSomething();
    ship.checkAndUpdateIncomingMissile(missile2);
    bool const shipAfter = ship.isDestroyed();
    return
            !shipBefore &&
            !missileBefore &&
            !shipBetween &&
            missileAfter &&
            shipAfter;
#else
    return true;
#endif
}
