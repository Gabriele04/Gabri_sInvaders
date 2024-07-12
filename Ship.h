//
// Created by gab on 7/12/24.
//

#ifndef GABRI_SINVADERS_SHIP_H
#define GABRI_SINVADERS_SHIP_H


#include "Sprite.h"

class Ship : public Sprite{
private:
    int lives;
    int power;
public:
    explicit Ship(const std::string &pathFile, float scale = 1.0F, int lives = 1, int power = 1);

    int getLives() const;

    void setLives(int lives);

    int getDamage();

    int getPower() const;

    void setPower(int power);
};


#endif //GABRI_SINVADERS_SHIP_H
