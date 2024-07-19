#include <gtest/gtest.h>
#include "GameEngine.h"

TEST(TestGameEngine, TestGameEngineRestart) {
    GameEngine game;
    game.restart();
    ASSERT_EQ(game.ship.getLives(), game.ship.isElite() ? game.initialShipLives * 2 : game.initialShipLives);
    ASSERT_EQ(game.ship.getPosition().x, 400.f);
    ASSERT_EQ(game.ship.getPosition().y, 500.f);
    ASSERT_EQ(game.alien.getLives(), game.alien.isElite() ? game.initialAlienLives * 6 : game.initialAlienLives);
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

TEST(TestGameEngine, TestGameEngineBulletCollision) {
    GameEngine game;
    game.alien.setElite();

    game.shoot = true;
    game.bullet.setPosition(400, 300);
    game.alien.setPosition(400, 300);
    game.update(0.016f);
    ASSERT_EQ(game.bullet.getPosition().x, 900);
    ASSERT_EQ(game.bullet.getPosition().y, 900);
    ASSERT_EQ(game.alien.getLives(), 5);
    ASSERT_EQ(game.score, 0);

    game.shoot = true;
    game.bullet.setPosition(400, 300);
    game.alien.setPosition(400, 300);
    game.update(0.016f);
    ASSERT_EQ(game.bullet.getPosition().x, 900);
    ASSERT_EQ(game.bullet.getPosition().y, 900);
    ASSERT_EQ(game.alien.getLives(), 4);
    ASSERT_EQ(game.score, 0);

    game.ship.setPower(5);
    game.shoot = true;
    game.bullet.setPosition(400, 300);
    game.alien.setPosition(400, 300);
    game.update(0.016f);
    ASSERT_EQ(game.bullet.getPosition().x, 900);
    ASSERT_EQ(game.bullet.getPosition().y, 900);
    ASSERT_EQ(game.alien.getLives(), 6);
    ASSERT_EQ(game.score, 1);
}

TEST (TestGameEngine, TestGameEngineShipCollision){
    GameEngine game;

    game.alien.setPosition(400, 500);
    game.ship.setPosition(400, 500);
    game.update(0.016f);
    ASSERT_EQ(game.ship.getLives(), 2);
    ASSERT_EQ(game.alien.getLives(), game.initialAlienLives);

    game.alien.setPosition(400, 500);
    game.ship.setPosition(400, 500);
    game.update(0.016f);
    ASSERT_EQ(game.ship.getLives(), 1);
    ASSERT_EQ(game.alien.getLives(), game.initialAlienLives);

    game.alien.setPosition(400, 500);
    game.ship.setPosition(400, 500);
    game.update(0.016f);
    ASSERT_EQ(game.ship.getLives(), 3);

}