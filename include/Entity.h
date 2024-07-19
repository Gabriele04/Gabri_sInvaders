#ifndef GABRI_SINVADERS_ENTITY_H
#define GABRI_SINVADERS_ENTITY_H

#include "Background.h"

class Entity : public sf::Sprite {
protected:
    float speed;
    sf::Texture texture;
public:
    explicit Entity(const std::string &pathFile, float scale = 1.0F, float speed = 1);

    float getSpeed() const;

    virtual void setSpeed(float speed);

    virtual void update(float deltaTime, float x, float y);

    virtual ~Entity() {};
};


#endif //GABRI_SINVADERS_ENTITY_H
