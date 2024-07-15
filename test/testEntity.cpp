#include <gtest/gtest.h>
#include "Entity.h"

TEST(TestEntity, TestEntityUpdate) {
    Entity entity("../../assets/texture/alien_sprite.png", 1, 12.0F);
    entity.update(0.5);
    ASSERT_EQ(entity.getPosition().y, 12.0f * 0.5f);
    entity.update(0.8);
    ASSERT_EQ(entity.getPosition().y, 12.0f * 0.5f + 12.0f * 0.8f);
}