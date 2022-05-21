#include "game.h"

// TODO Aufgabe 7:
//  Bringe die `include`- und `using`-Anweisungen in eine sinnvolle Ordnung.
#include "Coordinates.h"
#include "PlayerSea.h"
using GameObjects::PlayerSea;
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using Sea::Coordinates;
using std::vector;
#include "init.h"
using std::cin;


// TODO Aufgabe 7:
//  Zerlege die Funktion `gameLoop(..)` in sinnvolle, kürzere Teilfunktionen.
void gameLoop(vector<PlayerSea> & playerSeas)
{
    cout << endl << "Los geht's!" << endl;
    for (unsigned int round = 0;; ++round) {
        PlayerSea & currentPlayerSea = playerSeas[round % 2];
        PlayerSea & otherPlayerSea = playerSeas[(round + 1) % 2];

        Coordinates targetCoordinates = inputMissileTargetCoordinates(currentPlayerSea);
        bool hit = currentPlayerSea.sendMissileTo(otherPlayerSea, targetCoordinates);
        if (hit) {
            cout << "Treffer!" << endl;
        }
        else {
            cout << "Daneben!" << endl;
        }

        bool gameFinished = false;
        if (otherPlayerSea.allShipsDestroyed()) {
            cout << "Das letzte Schiff von " << otherPlayerSea.getPlayerName() << " ist versenkt. "
                 << currentPlayerSea.getPlayerName() << " hat gewonnen." << endl;
            gameFinished = true;
        }
        if (gameFinished) {
            break;
        }
    }
}

Coordinates inputMissileTargetCoordinates(PlayerSea const & currentPlayerSea)
{
    while (true) {
        cout << endl << currentPlayerSea.getPlayerName() << " zielt auf" << endl;
        Coordinates targetCoordinates = inputCoordinates();

        if (currentPlayerSea.missileAlreadySentTo(targetCoordinates)) {
            cout << "Diese Koordinaten hast du schon probiert." << endl;
            continue;
        }
        return targetCoordinates;
    }
}
