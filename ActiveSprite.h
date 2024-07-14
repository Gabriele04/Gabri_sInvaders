//
// Created by gab on 7/12/24.
//

#ifndef GABRI_SINVADERS_ACTIVESPRITE_H
#define GABRI_SINVADERS_ACTIVESPRITE_H


#include "Sprite.h"

class ActiveSprite : public Sprite {
private:
    int lives;
    float speed;
public:
    ActiveSprite(const std::string &pathFile, float scale = 1.0F, int lives = 1, float speed = 1);

    int getLives() const;

    virtual void setLives(int lives) = 0;

    float getSpeed() const;

    void setSpeed(float speed);

    int getDamage();
};


#endif //GABRI_SINVADERS_ACTIVESPRITE_H
