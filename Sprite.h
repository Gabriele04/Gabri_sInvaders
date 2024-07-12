//
// Created by gab on 7/12/24.
//

#ifndef GABRI_SINVADERS_SPRITE_H
#define GABRI_SINVADERS_SPRITE_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Sprite : public sf::Sprite {
public:
    explicit Sprite(const std::string &pathFile, float scale = 1.0F);

private:
    sf::Texture texture;
};


#endif //GABRI_SINVADERS_SPRITE_H
