#include <stdexcept>
#include "../include/Entity.h"

Entity::Entity(const std::string &pathFile, float scale, float speed) : speed(speed) {
    if (!texture.loadFromFile(pathFile)) {
        throw std::runtime_error("Failed to load texture from file: " + pathFile);
    }
    texture.setSmooth(true);
    setTexture(texture);
    setScale(scale, scale);
}

float Entity::getSpeed() const {
    return speed;
}

void Entity::setSpeed(float speed) {
    this->speed = speed;
}

void Entity::update(float deltaTime, float x, float y) {
    move(speed * deltaTime * x, speed * deltaTime * y);
}

