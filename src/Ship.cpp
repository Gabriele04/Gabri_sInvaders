#include "../include/Ship.h"

Ship::Ship(float scale, int speed, int lives, bool elite, int power) : Character("../assets/texture/sprite.png", scale,
                                                                                 speed, lives, elite),
                                                                       power(power) {
    if(elite){
        setLives(lives);
        setPower(power);
        setSpeed(speed);
    }
}

void Ship::setElite() {
    if(elite){
        elite = false;
        setLives(lives / 2);
        setPower(power / 2);
        setSpeed(speed / 1.8f);
        return;
    }
    else{
        elite = true;
        setLives(lives);
        setPower(power);
        setSpeed(speed);
    }
}

int Ship::getPower() const {
    return power;
}

void Ship::setPower(int power) {
    this->power = elite ? power * 2 : power;
}

void Ship::update(float deltaTime, float x, float y) {
    move(speed * deltaTime * x, speed * deltaTime * y);
}

void Ship::setSpeed(float speed) {
    this->speed = elite ? speed * 1.8f : speed;
}

void Ship::setLives(int lives) {
    this->lives = elite ? lives * 2 : lives;

}

void Ship::respawn(int lives) {
    setPosition(400.f, 500.f);
    setLives(lives);
}


