//
// Created by gab on 7/12/24.
//

#include "Ship.h"

Ship::Ship(const std::string &pathFile, float scale, int lives, int power) : Sprite(pathFile, scale), lives(lives), power(power) {}

int Ship::getLives() const {
    return lives;
}

void Ship::setLives(int lives) {
    Ship::lives = lives;
}

int Ship::getPower() const {
    return power;
}

void Ship::setPower(int power) {
    Ship::power = power;
}

int Ship::getDamage() {
    return --lives;
}
