#ifndef GABRI_SINVADERS_ALIEN_H
#define GABRI_SINVADERS_ALIEN_H

#include "Character.h"

class Alien : public Character {
private:
    // More the alien is near to the earth more it turns to red
    std::vector<float> color = {100, 255, 100};
public:
    explicit Alien(float scale = 1.0F, float speed = 1, int lives = 1, bool elite = false);

    void setLives(int lives) override;

    void respawn(int lives) override;

    void setSpeed(float speed) override;

    void setElite() override;

    void update(float deltaTime, float x, float y) override;

};

#endif //GABRI_SINVADERS_ALIEN_H
