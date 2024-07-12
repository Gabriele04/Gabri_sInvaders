#include <SFML/System/Clock.hpp>
#include "GameEngine.h"

int main() {
    sf::Clock clock;
    srand(time(NULL));

    GameEngine game;

    while(game.active()){
        float dt;
        dt = clock.restart().asSeconds();
        game.eventManager();
        game.update(dt);
        game.render();
    }
    return 0;
}
