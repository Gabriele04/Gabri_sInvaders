//
// Created by gab on 7/12/24.
//

#include "ActiveSprite.h"

ActiveSprite::ActiveSprite(const std::string &pathFile, float scale, int lives, float speed) : Sprite(pathFile, scale),
                                                                                               lives(lives),
                                                                                               speed(speed) {}

int ActiveSprite::getLives() const {
    return lives;
}

float ActiveSprite::getSpeed() const {
    return speed;
}

void ActiveSprite::setSpeed(float speed) {
    ActiveSprite::speed = speed;
}

int ActiveSprite::getDamage() {
    return --lives;
}

