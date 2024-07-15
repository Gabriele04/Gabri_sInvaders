//
// Created by gab on 7/12/24.
//

#ifndef GABRI_SINVADERS_ALIEN_H
#define GABRI_SINVADERS_ALIEN_H


#include "Entity.h"

class Alien : public Entity {
private:
    int lives;
    bool boss;
public:
    explicit Alien(float scale = 1.0F, int lives = 1, float speed = 1, bool boss = false);

    bool isBoss() const;

    std::string getBoss() const;

    void setBoss(bool boss);

    void setLives(int lives);

    int getLives() const;

    void respawn(int lives);

    int takeDamage();
};


#endif //GABRI_SINVADERS_ALIEN_H
