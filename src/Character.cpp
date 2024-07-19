#include <iostream>
#include "Character.h"

Character::Character(std::string pathFile, float scale, float speed, int lives, bool elite) : Entity(pathFile, scale,
                                                                                                    speed),
                                                                                             lives(lives),
                                                                                             elite(elite) {}

int Character::getLives() const {
    return lives;
}

void Character::setLives(int lives) {
    this->lives = lives;
}

std::string Character::getElite() const {
    return elite ? "ON" : "OFF";
}

int Character::takeDamage(int damage) {
    if (lives - damage >= 0) {
        lives -= damage;
        return lives;
    }
    else {
        return 0;
    }
}

bool Character::isElite() const {
    return elite;
}

