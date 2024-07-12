//
// Created by gab on 7/12/24.
//

#ifndef GABRI_SINVADERS_GAMEENGINE_H
#define GABRI_SINVADERS_GAMEENGINE_H

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"

class GameEngine {
private:
    sf::RenderWindow* window;
    std::map<std::string, sf::Sprite> sprites;
    sf::Text points;
    sf::Font font;

    bool shoot;
    int score;
public:
    bool isShoot() const;

    void setShoot(bool shoot);

    int getScore() const;

    void setScore(int score);

public:
    GameEngine();
    bool active();
    void render();
    void update(float dt);
    void eventManager();
    void restart();
    bool gameOver;
};




#endif //GABRI_SINVADERS_GAMEENGINE_H
