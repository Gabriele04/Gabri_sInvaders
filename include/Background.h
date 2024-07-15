#ifndef GABRI_SINVADERS_BACKGROUND_H
#define GABRI_SINVADERS_BACKGROUND_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Background : public sf::Sprite {
public:
    explicit Background(const std::string &pathFile, float scale = 1.0f);

private:
    sf::Texture texture;
};

#endif //GABRI_SINVADERS_BACKGROUND_H