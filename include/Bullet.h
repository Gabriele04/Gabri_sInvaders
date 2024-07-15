#ifndef GABRI_SINVADERS_BULLET_H
#define GABRI_SINVADERS_BULLET_H


#include "Entity.h"

class Bullet : public Entity {
public:
    explicit Bullet(float scale = 1.0f, float speed = 1);
};


#endif //GABRI_SINVADERS_BULLET_H
