//
// Created by gab on 7/12/24.
//

#include <iostream>
#include "GameEngine.h"
#include "Sprite.h"
#include "SFML/Graphics.hpp"

GameEngine::GameEngine() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Gabri's Invaders");
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(60);


    sprites.insert(std::pair<std::string, sf::Sprite *>("Ship", new Sprite("texture/sprite.png")));
    sprites.insert(std::pair<std::string, sf::Sprite *>("Alien", new Sprite("texture/alien_sprite.png")));
    sprites.insert(std::pair<std::string, sf::Sprite *>("Bullet", new Sprite("texture/bullet.png")));
    sprites.insert(std::pair<std::string, sf::Sprite *>("Background", new Sprite("texture/background.jpg")));

    points.setString("Points: ");
    points.setFillColor(sf::Color(200, 200, 200));
    points.setStyle(sf::Text::Bold | sf::Text::Italic);
    restart();
}

void GameEngine::restart() {
    sprites["Ship"]->setPosition(400.f, 500.f);
    sprites["Alien"]->setPosition(rand() % 600 + 100, 50.f);
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
    window->draw(*sprites["Background"]);
    window->draw(*sprites["Ship"]);
    window->draw(*sprites["Alien"]);
    window->draw(*sprites["Bullet"]);
    window->draw(points);
    if (shoot && sprites["Bullet"]->getPosition().y > 0)
        window->draw(*sprites["Bullet"]);
    else
        shoot = false;

    window->display();
}

void GameEngine::update(float dt) {
    sprites["Alien"]->move(0, 70 * dt);
    if (shoot) {
        sprites["Bullet"]->move(0, -20);
    }
    if (sprites["Bullet"]->getGlobalBounds().intersects(sprites["Alien"]->getGlobalBounds())) {
        sprites["Alien"]->setPosition(rand() % 600 + 100, 50.f);
        shoot = false;
        score++;
        std::string scores = std::to_string(score);
        points.setString("Points: " + scores);
        std::cout << score << std::endl;
    }
    if (sprites["Alien"]->getPosition().y > 600 - 100 ||
        sprites["Ship"]->getGlobalBounds().intersects(sprites["Alien"]->getGlobalBounds())) {
        points.setCharacterSize(60);
        points.setString("GAME OVER!\nScore: " + std::to_string(score) + "\nPress \"R\" to retry");
        gameOver = true;
    }
}

void GameEngine::eventManager() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (sprites["Ship"]->getPosition().x + 80 < 800) {
            sprites["Ship"]->move(7, 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (sprites["Ship"]->getPosition().x - 20 > 0) {
            sprites["Ship"]->move(-7, 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (sprites["Ship"]->getPosition().y - 200 > 0) {
            sprites["Ship"]->move(0, -5);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (sprites["Ship"]->getPosition().y + 80 < 600) {
            sprites["Ship"]->move(0, +5);
        }
    }

    sf::Event event{};
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed :
                switch (event.key.scancode) {
                    case sf::Keyboard::Scan::R:
                        if (gameOver) {
                            restart();
                        }
                        break;
                    case sf::Keyboard::Scan::Space:
                        if (!shoot) {
                            sprites["Bullet"]->setPosition(sprites["Ship"]->getPosition().x,
                                                           sprites["Ship"]->getPosition().y - 20);
                            shoot = true;
                        }
                        break;

                    default:
                        break;
                }
                break;
            case sf::Event::Closed :
                window->close();
                break;
            default:
                break;
        }
    }
}


GameEngine::~GameEngine() {
    delete window;
    for (const auto &sprite: sprites) {
        delete sprite.second;
    }
    sprites.clear();
}
