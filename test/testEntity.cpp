#include <gtest/gtest.h>
#include "Entity.h"

TEST(TestEntity, TestEntityUpdate) {
    Entity entity("../../assets/texture/alien_sprite.png", 1, 12.f);
    entity.update(0.5);
    ASSERT_EQ(entity.getPosition().y, 12.f * 0.5f);
    entity.update(0.8);
    ASSERT_EQ(entity.getPosition().y, 12.f * 0.5f + 12.f * 0.8f);
}