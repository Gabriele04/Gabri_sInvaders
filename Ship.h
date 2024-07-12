//
// Created by gab on 7/12/24.
//

#ifndef GABRI_SINVADERS_SHIP_H
#define GABRI_SINVADERS_SHIP_H


#include "ActiveSprite.h"

class Ship : public ActiveSprite {
private:
    bool bigShip;
public:
    Ship(const std::string &pathFile, float scale = 1.0F, int lives = 1, float speed = 1, bool bigShip = false);

    bool isBigShip() const;

    void setBigShip(bool bigShip);
};


#endif //GABRI_SINVADERS_SHIP_H
