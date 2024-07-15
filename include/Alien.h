//
// Created by gab on 7/12/24.
//

#ifndef GABRI_SINVADERS_ALIEN_H
#define GABRI_SINVADERS_ALIEN_H


#include "ActiveSprite.h"

class Alien : public ActiveSprite {
private:
    bool boss;
public:
    explicit Alien(const std::string &pathFile, float scale = 1.0F, int lives = 1, float speed = 1, bool boss = false);

    bool isBoss() const;

    std::string getBoss() const;

    void setBoss(bool boss);

    void setLives(int lives) override;
};


#endif //GABRI_SINVADERS_ALIEN_H