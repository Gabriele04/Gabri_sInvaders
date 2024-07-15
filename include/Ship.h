//
// Created by gab on 7/12/24.
//

#ifndef GABRI_SINVADERS_SHIP_H
#define GABRI_SINVADERS_SHIP_H


#include "Entity.h"

class Ship : public Entity {
private:
    int lives;
    bool bigShip;
public:
    explicit Ship(float scale = 1.0F, int lives = 1, bool bigShip = false);

    bool isBigShip() const;

    std::string getBigShip() const;

    void setBigShip(bool bigShip);

    void setLives(int lives);

    int getLives() const;

    int takeDamage();
};


#endif //GABRI_SINVADERS_SHIP_H
