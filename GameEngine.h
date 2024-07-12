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
    std::vector<sf::Sprite> sprites;
    sf::Text points;
};


#endif //GABRI_SINVADERS_GAMEENGINE_H
