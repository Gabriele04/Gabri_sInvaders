#ifndef GABRI_SINVADERS_SHIP_H
#define GABRI_SINVADERS_SHIP_H

#include "Character.h"

class Ship : public Character {
private:
    int power;
public:
    explicit Ship(float scale = 1.0F, int speed = 50, int lives = 1, bool elite = false, int power = 1);

    int getPower() const;

    void setPower(int power);

    void setSpeed(float speed) override;

    void setLives(int lives) override;

    void update(float deltaTime, float x, float y) override;

    void setElite() override;

    void respawn(int lives) override;

};


#endif //GABRI_SINVADERS_SHIP_H
