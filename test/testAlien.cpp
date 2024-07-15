#include <gtest/gtest.h>
#include "Alien.h"

TEST(TestAlien, TestAlienDamage) {
    Alien alien(1.f, 3, false);
    alien.takeDamage();
    ASSERT_EQ(alien.getLives(), 2);
    alien.takeDamage();
    ASSERT_EQ(alien.getLives(), 1);
    alien.takeDamage();
    ASSERT_EQ(alien.getLives(), 0);
    alien.takeDamage();
    ASSERT_EQ(alien.getLives(), 0);
}

TEST(TestAlien, TestAlienBoss) {
    Alien bigAlien(1.f, 3, 1, true);
    ASSERT_EQ(bigAlien.getLives(), 6);

    Alien normalAlien(1.f, 3, 1, false);
    ASSERT_EQ(normalAlien.getLives(), 3);
}

TEST(TestAlien, TestAlienRespawn) {
    Alien alien(1.f, 3, false);

    alien.respawn(1);
    ASSERT_EQ(alien.getLives(), 1);
    ASSERT_EQ(alien.getPosition().y, 50.f);

    alien.respawn(2);
    ASSERT_EQ(alien.getLives(), 2);
    ASSERT_EQ(alien.getPosition().y, 50.f);

    alien.respawn(3);
    ASSERT_EQ(alien.getLives(), 3);
    ASSERT_EQ(alien.getPosition().y, 50.f);

    alien.respawn(4);
    ASSERT_EQ(alien.getLives(), 4);
    ASSERT_EQ(alien.getPosition().y, 50.f);

}