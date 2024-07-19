#ifndef GABRI_SINVADERS_GAMEENGINE_H
#define GABRI_SINVADERS_GAMEENGINE_H

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "Background.h"
#include "Entity.h"
#include "Ship.h"
#include "Alien.h"
#include <gtest/gtest_prod.h>

class GameEngine {
private:
    sf::RenderWindow *window;

    const int initialAlienLives = 1;
    Alien alien;
    const int initialShipLives = 3;
    Ship ship;

    Entity bullet;
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

    FRIEND_TEST(TestGameEngine, TestGameEngineRestart);
    FRIEND_TEST(TestGameEngine, TestGameEngineUpdate);
    FRIEND_TEST(TestGameEngine, TestGameEngineBulletCollision);
    FRIEND_TEST(TestGameEngine, TestGameEngineShipCollision);

public:

    GameEngine();

    ~GameEngine();

    void run();
};


#endif //GABRI_SINVADERS_GAMEENGINE_H
