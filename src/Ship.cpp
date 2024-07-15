//
// Created by gab on 7/12/24.
//

#include "../include/Ship.h"

Ship::Ship(float scale, int lives, bool bigShip) : Entity("../assets/texture/sprite.png", scale, 0), lives(lives),
                                                   bigShip(bigShip) {
    if (bigShip)
        this->lives *= 2;
}

bool Ship::isBigShip() const {
    return bigShip;
}

void Ship::setBigShip(bool bigShip) {
    Ship::bigShip = bigShip;
}

void Ship::setLives(int lives) {
    this->lives = bigShip ? lives * 2 : lives;
}

std::string Ship::getBigShip() const {
    return bigShip ? "ON" : "OFF";
}

int Ship::getLives() const {
    return lives;
}

int Ship::takeDamage() {
    if (lives)
        return --lives;
    else
        return 0;
}


