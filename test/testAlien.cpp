#include <gtest/gtest.h>
#include "Alien.h"
#include "Ship.h"

TEST(TestAlien, TestAlienDamage) {
    Alien alien(1.f, 1, 3, false);
    Ship ship(1.f,1, 1, false, 1);
    alien.takeDamage(ship.getPower());
    ASSERT_EQ(alien.getLives(), 2);
    alien.takeDamage(ship.getPower());
    ASSERT_EQ(alien.getLives(), 1);
    alien.takeDamage(ship.getPower());
    ASSERT_EQ(alien.getLives(), 0);
    alien.takeDamage(ship.getPower());
    ASSERT_EQ(alien.getLives(), 0);
}

TEST(TestAlien, TestAlienBoss) {
    Alien bigAlien(1.f, 1, 3, true);
    ASSERT_EQ(bigAlien.getLives(), 18);
    Alien normalAlien(1.f, 1, 3, false);
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