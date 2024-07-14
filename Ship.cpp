//
// Created by gab on 7/12/24.
//

#include "Ship.h"

Ship::Ship(const std::string &pathFile, float scale, int lives, float speed, bool bigShip) : ActiveSprite(pathFile,
                                                                                                          scale, lives,
                                                                                                          speed),
                                                                                             bigShip(bigShip) {
    if (bigShip)
        lives *= 2;
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


