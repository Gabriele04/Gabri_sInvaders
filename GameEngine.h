//
// Created by gab on 7/12/24.
//

#ifndef GABRI_SINVADERS_GAMEENGINE_H
#define GABRI_SINVADERS_GAMEENGINE_H

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "Sprite.h"

class GameEngine {
private:
    sf::RenderWindow *window;
    std::map<std::string, sf::Sprite *> sprites;
    sf::Text points;
    sf::Font font;

    bool shoot{};
    int score{};
    const int initialLives = 2;
    int lives = initialLives;
    bool gameOver{};


public:
    GameEngine();

    virtual ~GameEngine();

    bool active();

    void render();

    void update(float dt);

    void eventManager();

    void restart();

    void gameOverScreen();

    void initializeEngine();

    void startScreen();
};


#endif //GABRI_SINVADERS_GAMEENGINE_H
