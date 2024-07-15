//
// Created by gab on 7/12/24.
//

#include "../include/Alien.h"

Alien::Alien(const std::string &pathFile, float scale, int lives, float speed, bool boss) : ActiveSprite(pathFile,
                                                                                                         scale, lives,
                                                                                                         speed),
                                                                                            boss(boss) {
    if (boss)
        lives *= 2;
}

bool Alien::isBoss() const {
    return boss;
}

void Alien::setBoss(bool boss) {
    Alien::boss = boss;
}

void Alien::setLives(int lives) {
    this->lives = boss ? lives * 2 : lives;
}

std::string Alien::getBoss() const {
    return boss ? "ON" : "OFF";
}
