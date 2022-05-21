#ifndef BLATT3_INIT_H
#define BLATT3_INIT_H


#include <string>
#include <vector>

#include "Coordinates.h"
#include "Object.h"

#include "PlayerSea.h"
#include "Ship.h"


void initializePlayerSeasWithShips(std::vector<GameObjects::PlayerSea> & playerSeas);
std::string inputPlayerName();

void initializeShips(GameObjects::PlayerSea & playerSea);
bool initializeShip(GameObjects::PlayerSea & playerSea, unsigned int size);
GameObjects::Ship inputShip(unsigned int size);

Sea::Coordinates inputCoordinates();
Sea::Orientation inputOrientation();
bool checkForInputError();


#endif //BLATT3_INIT_H
