#include <gtest/gtest.h>
#include <SFML/Window/Keyboard.hpp>
#include "GameEngine.h"

TEST(TestGameEngine, TestGameEngineRestart) {
    GameEngine game;
    game.restart();
    ASSERT_EQ(game.ship.getLives(), game.ship.isBigShip() ? game.initialShipLives * 2 : game.initialShipLives);
    ASSERT_EQ(game.ship.getPosition().x, 400.f);
    ASSERT_EQ(game.ship.getPosition().y, 500.f);
    ASSERT_EQ(game.alien.getLives(), game.alien.isBoss() ? game.initialAlienLives * 2 : game.initialAlienLives);
}

TEST(TestGameEngine, TestGameEngineUpdate) {
    GameEngine game;
    float alienPosition_y;
    float bulletPosition_y;
    game.shoot = true;

    alienPosition_y = game.alien.getPosition().y;
    bulletPosition_y = game.bullet.getPosition().y;
    game.update(0.1f);
    ASSERT_EQ(game.alien.getPosition().y, alienPosition_y + game.alien.getSpeed() * 0.1f);
    ASSERT_EQ(game.bullet.getPosition().y, bulletPosition_y + game.bullet.getSpeed() * 0.1f);

    alienPosition_y = game.alien.getPosition().y;
    bulletPosition_y = game.bullet.getPosition().y;
    game.update(1.8f);
    ASSERT_EQ(game.alien.getPosition().y, alienPosition_y + game.alien.getSpeed() * 1.8);
    ASSERT_EQ(game.bullet.getPosition().y, bulletPosition_y + game.bullet.getSpeed() * 1.8f);

    game.update(500.f);
    ASSERT_EQ(game.alien.getPosition().y, 50.f);
}