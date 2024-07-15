#include <gtest/gtest.h>
#include "Ship.h"

TEST(TestShip, TestShipDamage) {
    Ship ship(1.0f, 3, false);
    ship.takeDamage();
    ASSERT_EQ(ship.getLives(), 2);
    ship.takeDamage();
    ASSERT_EQ(ship.getLives(), 1);
    ship.takeDamage();
    ASSERT_EQ(ship.getLives(), 0);
    ship.takeDamage();
    ASSERT_EQ(ship.getLives(), 0);
}

TEST(TestShip, TestShipBigShip) {
    Ship bigShip(1.0f, 3, true);
    ASSERT_EQ(bigShip.getLives(), 6);
    Ship normalShip(1.0f, 3, false);
    ASSERT_EQ(normalShip.getLives(), 3);
}