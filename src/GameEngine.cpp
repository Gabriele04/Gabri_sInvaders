#include <iostream>
#include "../include/GameEngine.h"
#include "SFML/Graphics.hpp"
GameEngine::GameEngine() : background("../assets/texture/background.jpg"), ship(Ship(0.15F, 70, initialShipLives)),
                           alien(Alien(0.2F, 70, initialAlienLives)),
                           bullet(Entity("../assets/texture/bullet.png",0.05F, -500)) {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Gabri's Invaders");
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(60);


    if (!font.loadFromFile("../assets/font/JetBrainsMonoNerdFontMono-Light.ttf"))
        throw std::runtime_error("Failed to load font");
    points.setFont(font);
    points.setCharacterSize(30);
    points.setPosition(15, 15);
    points.setFillColor(sf::Color::White);
    points.setStyle(sf::Text::Bold);
    showStartScreen();

    restart();
}

void GameEngine::showStartScreen() {
    points.setCharacterSize(35);
    points.setString(
            "Little guide:\n- Use the arrow keys\n  to move the ship\n- Press SPACE to shoot\n- Your lives are displayed\n  on the screen\n- The enemies have more\n  than one live\n- Press esc to exit\nGood Luck!\nPress ENTER to continue!");
    window->draw(background);
    window->draw(points);
    window->display();

    bool ready = false;
    while (!ready) {
        sf::Event event{};
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Enter) {
                        ready = true;
                        points.setCharacterSize(30);
                    }
                    break;

                default:
                    break;
            }
        }
    }

    ready = false;
    while (!ready) {
        sf::Event event{};
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;

                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::F) {
                        ship.setElite();
                    } else if (event.key.code == sf::Keyboard::R) {
                        alien.setElite();
                    } else if (event.key.code == sf::Keyboard::Enter) {
                        ready = true;
                    }
                    break;
                default:
                    break;
            }
            window->clear();
            points.setString(
                    "Press F to have a Big Ship \nPress R to face Bosses \nBig Ship: " +
                    ship.getElite() + "\nBoss: " +
                    alien.getElite() + "\nPress ENTER to start!");
            window->draw(background);
            window->draw(points);
            window->display();
        }
    }

}

void GameEngine::restart() {
    ship.respawn(initialShipLives);
    alien.respawn(initialAlienLives);
    points.setString("Points: " + std::to_string(score) + "\nLives: " +
                     std::to_string(ship.getLives()));
    shoot = false;
    score = 0;
    gameOver = false;
}

bool GameEngine::active() {
    return window->isOpen();
}

void GameEngine::render() {
    window->clear();
    window->draw(background);
    window->draw(ship);
    window->draw(alien);
    window->draw(points);
    if (shoot && bullet.getPosition().y > 0)
        window->draw(bullet);
    else
        shoot = false;

    window->display();
}

void GameEngine::update(float dt) {

    if (bullet.getGlobalBounds().intersects(alien.getGlobalBounds())) {
        shoot = false;
        bullet.setPosition(900, 900);
        if (!(alien.takeDamage(ship.getPower()))) {
            alien.respawn(initialAlienLives);
            score++;
        }
    }

    alien.update(dt, 0, 1);

    if (shoot) {
        bullet.update(dt, 0, 1);
    }

    points.setString("Points: " + std::to_string(score) + "\nLives: " + std::to_string(ship.getLives()));
    if (alien.getPosition().y > 600 - 100 ||
        ship.getGlobalBounds().intersects(alien.getGlobalBounds())) {
        if (!ship.takeDamage(alien.isElite() ? 2 : 1)) {
            gameOverScreen();
        }
        alien.respawn(initialAlienLives);
    }
}

void GameEngine::eventManager(float dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (ship.getPosition().x + 80 < 800) {
            ship.update(dt, 7, 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (ship.getPosition().x - 20 > 0) {
            ship.update(dt, -7, 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (ship.getPosition().y - 200 > 0) {
            ship.update(dt, 0, -5);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (ship.getPosition().y + 80 < 600) {
            ship.update(dt, 0, +5);
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
                            bullet.setPosition(ship.getPosition().x, ship.getPosition().y - 50);
                            shoot = true;
                        }
                        break;
                    case sf::Keyboard::Scan::Escape:
                        window->close();
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

void GameEngine::gameOverScreen() {
    gameOver = true;
    points.setCharacterSize(60);
    points.setFillColor(sf::Color::Red);
    points.setString("GAME OVER!\nScore: " + std::to_string(score) + "\nPress \"R\" to retry");
    render();

    while (gameOver) {
        sf::Event event{};
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyPressed :
                    switch (event.key.scancode) {
                        case sf::Keyboard::Scan::R:
                            points.setCharacterSize(30);
                            points.setFillColor(sf::Color::White);
                            restart();
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
}

GameEngine::~GameEngine() {
    delete window;
}

void GameEngine::run() {
    sf::Clock clock;
    while (active()) {
        float dt;
        dt = clock.restart().asSeconds();
        eventManager(dt);
        update(dt);
        render();
    }
}