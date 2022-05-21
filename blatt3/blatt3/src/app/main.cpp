#include <vector>
using std::vector;

#include "PlayerSea.h"
using GameObjects::PlayerSea;

#include "init.h"
#include "game.h"
#include "test.h"


int main()
{
    if (testPassed()) {
        vector<PlayerSea> playerSeas;
        initializePlayerSeasWithShips(playerSeas);

        gameLoop(playerSeas);
    }
    return 0;
}
