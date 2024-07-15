//
// Created by gab on 7/12/24.
//

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

    void setSpeed(float speed);

    virtual void update(float deltaTime);

    virtual ~Entity() {}
};


#endif //GABRI_SINVADERS_ENTITY_H
