//
// Created by gab on 7/12/24.
//

#include "../include/Alien.h"

Alien::Alien(float scale, int lives, float speed, bool boss) : Entity("../assets/texture/alien_sprite.png",
                                                                      scale,
                                                                      speed), lives(lives), boss(boss) {
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

int Alien::getLives() const {
    return lives;
}

void Alien::respawn(int lives) {
    setPosition(rand() % 600 + 100, 50.f);
    setLives(lives);
}

int Alien::takeDamage() {
    return --lives;
}
