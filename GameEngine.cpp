//
// Created by gab on 7/12/24.
//

#include "GameEngine.h"
#include "Sprite.h"

GameEngine::GameEngine() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Gabri's Invaders");
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(60);

    sprites.insert(std::pair<std::string, sf::Sprite>("Ship", Sprite("texture/sprite.png")));
    sprites.insert(std::pair<std::string, sf::Sprite>("Alien", Sprite("texture/alien_sprite.png")));
    sprites.insert(std::pair<std::string, sf::Sprite>("Bullet", Sprite("texture/bullet.png")));
    sprites.insert(std::pair<std::string, sf::Sprite>("Background", Sprite("texture/background.jpg")));

    points.setString("Points: ");
    points.setFillColor(sf::Color(200,200,200));
    points.setStyle(sf::Text::Bold | sf::Text::Italic);
    restart();
}

void GameEngine::restart() {
    sprites["Ship"].setPosition(400.f, 500.f);
    sprites["Alien"].setPosition(rand() % 600 + 100, 50.f);
    points.setPosition(10, 10);
    points.setString("Points: ");
    shoot = false;
    score = 0;
    gameOver = false;
}

bool GameEngine::active() {
    return window->isOpen();
}

void GameEngine::render() {
    window->clear();
    window->draw(sprites["Background"]);
    window->draw(sprites["Ship"]);
    window->draw(sprites["Alien"]);
    window->draw(sprites["Bullet"]);
    window->draw(points);
    if(shoot && sprites["Bullet"].getPosition().y > 0)
        window->draw(sprites["Bullet"]);
    else
        shoot = false;

    window->display();
}