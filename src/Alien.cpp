#include <iostream>
#include "../include/Alien.h"

Alien::Alien(float scale, float speed, int lives, bool elite) : Character("../assets/texture/alien_sprite.png", scale,
                                                                         speed, lives, elite) {
    if(elite){
        setLives(lives);
        setSpeed(speed);
    }
}

void Alien::setLives(int lives) {
    this->lives = elite ? lives * 6 : lives;
}

void Alien::respawn(int lives) {
    setPosition(rand() % 600 + 100, 50.f);
    setLives(lives);
    color = {100, 255, 100};
}

void Alien::update(float deltaTime, float x, float y) {
    move(speed * deltaTime * x, speed * deltaTime * y);
    color[0] += deltaTime * 0.34 * speed;
    color[1] -= deltaTime * 0.55 * speed;
    color[2] -= deltaTime * 0.21 * speed;
    setColor(sf::Color(static_cast<int>(color[0]), static_cast<int>(color[1]), static_cast<int>(color[2])));
}

void Alien::setSpeed(float speed) {
    this->speed = elite ? speed / 2 : speed;
}

void Alien::setElite() {
    if(elite){
        elite = false;
        setLives(lives / 6);
        setSpeed(speed * 2);
        return;
    }
    else{
        elite = true;
        setLives(lives);
        setSpeed(speed);
    }
}
