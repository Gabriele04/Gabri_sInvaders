#include <gtest/gtest.h>
#include "Entity.h"

TEST(TestEntity, TestEntityUpdate) {
    Entity entity("../assets/texture/alien_sprite.png", 1, 12.f);
    entity.update(0.5, 1, 1);
    ASSERT_EQ(entity.getPosition().y, 12.f * 0.5f * 1);
    entity.update(0.8, 1, 1);
    ASSERT_EQ(entity.getPosition().y, 12.f * 0.5f * 1 + 12.f * 0.8f * 1);
}