#ifndef GABRI_SINVADERS_GAMEENGINE_H
#define GABRI_SINVADERS_GAMEENGINE_H

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "Background.h"
#include "Entity.h"
#include "Ship.h"
#include "Bullet.h"
#include "Alien.h"

class GameEngine {
private:
    sf::RenderWindow *window;

    const int initialAlienLives = 1;
    Alien alien;
    const int initialShipLives = 3;
    Ship ship;

    Bullet bullet;
    Background background;

    sf::Text points;
    sf::Font font;
    bool shoot = false;
    int score = 0;

    bool gameOver = false;

    bool active();

    void render();

    void update(float dt);

    void eventManager(float dt);

    void restart();

    void gameOverScreen();

    void showStartScreen();

public:

    GameEngine();

    ~GameEngine();

    void run();
};


#endif //GABRI_SINVADERS_GAMEENGINE_H
