#ifndef GABRI_SINVADERS_CHARACTER_H
#define GABRI_SINVADERS_CHARACTER_H


#include "Entity.h"

class Character : public Entity {
protected:
    int lives;
    bool elite;
public:
    explicit Character(std::string pathFile, float scale = 1.0F, float speed = 50, int lives = 1, bool elite = false);

    bool isElite() const;

    std::string getElite() const;

    virtual void setElite() = 0;

    virtual void respawn(int lives) = 0;

    virtual void setLives(int lives);

    int getLives() const;

    int takeDamage(int damage);
};


#endif //GABRI_SINVADERS_CHARACTER_H
