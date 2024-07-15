//
// Created by gab on 7/12/24.
//

#include <iostream>
#include "GameEngine.h"
#include "Sprite.h"
#include "SFML/Graphics.hpp"
#include "Ship.h"
#include "Alien.h"

GameEngine::GameEngine() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Gabri's Invaders");
    initializeEngine();
    restart();
}

void GameEngine::initializeEngine() {
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(60);

    sprites.insert(std::pair<std::string, sf::Sprite *>("Ship", new Ship("../assets/texture/sprite.png", 0.15F,
                                                                         initialShipLives, 1)));
    sprites.insert(
            std::pair<std::string, sf::Sprite *>("Alien", new Alien("../assets/texture/alien_sprite.png", 0.2F,
                                                                    initialAlienLives, 1)));
    sprites.insert(std::pair<std::string, sf::Sprite *>("Bullet", new Sprite("../assets/texture/bullet.png", 0.05F)));
    sprites.insert(std::pair<std::string, sf::Sprite *>("Background", new Sprite("../assets/texture/background.jpg")));

    if (!font.loadFromFile("../assets/font/JetBrainsMonoNerdFontMono-Light.ttf"))
        throw std::runtime_error("Failed to load font");
    points.setFont(font);
    points.setCharacterSize(30);
    points.setPosition(15, 15);
    points.setFillColor(sf::Color::White);
    points.setStyle(sf::Text::Bold);
    startScreen();
}

void GameEngine::startScreen() {
    points.setCharacterSize(35);
    points.setString(
            "Little guide:\n- Use the arrow keys\n  to move the ship\n- Press SPACE to shoot\n- Your lives are displayed\n  on the screen\n- The enemies have more\n  than one live\n- Press esc to exit\nGood Luck!\nPress ENTER to continue!");
    window->draw(*sprites["Background"]);
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
                        dynamic_cast<Ship *>(sprites["Ship"])->setBigShip(
                                !(dynamic_cast<Ship *>(sprites["Ship"])->isBigShip()));
                    } else if (event.key.code == sf::Keyboard::R) {
                        dynamic_cast<Alien *>(sprites["Alien"])->setBoss(
                                !(dynamic_cast<Alien *>(sprites["Alien"])->isBoss()));
                    } else if (event.key.code == sf::Keyboard::Enter) {
                        ready = true;
                    }
                    break;
                default:
                    break;
            }
            window->clear();
            points.setString(
                    "Press F to have a Big Ship (lives x2)\nPress R to face Bosses (lives x2)\nBig Ship: " +
                    dynamic_cast<Ship *>(sprites["Ship"])->getBigShip() + "\nBoss: " +
                    dynamic_cast<Alien *>(sprites["Alien"])->getBoss() + "\nPress ENTER to start!");
            window->draw(*sprites["Background"]);
            window->draw(points);
            window->display();
        }
    }

}

void GameEngine::restart() {

    dynamic_cast<Ship *>(sprites["Ship"])->setLives(initialShipLives);
    dynamic_cast<Alien *>(sprites["Alien"])->setLives(initialAlienLives);
    sprites["Ship"]->setPosition(400.f, 500.f);
    sprites["Alien"]->setPosition(rand() % 600 + 100, 50.f);
    points.setString("Points: " + std::to_string(score) + "\nLives: " +
                     std::to_string(dynamic_cast<Ship *>(sprites["Ship"])->getLives()));
    std::cout << "Lives" << std::to_string(dynamic_cast<Ship *>(sprites["Ship"])->getLives()) << std::endl;
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
    window->draw(points);
    if (shoot && sprites["Bullet"]->getPosition().y > 0)
        window->draw(*sprites["Bullet"]);
    else
        shoot = false;

    window->display();
}

void GameEngine::update(float dt) {
    sprites["Alien"]->move(0, 70 * dt * dynamic_cast<Alien *>(sprites["Alien"])->getSpeed());

    if (shoot) {
        sprites["Bullet"]->move(0, -20);
    }

    if (sprites["Bullet"]->getGlobalBounds().intersects(sprites["Alien"]->getGlobalBounds())) {
        shoot = false;
        sprites["Bullet"]->setPosition(900, 900);
        if (!(dynamic_cast<Alien *>(sprites["Alien"])->getDamage())) {
            sprites["Alien"]->setPosition(rand() % 600 + 100, 50.f);
            score++;
            std::string scores = std::to_string(score);
            points.setString("Points: " + scores + "\nLives: " +
                             std::to_string(dynamic_cast<Ship *>(sprites["Ship"])->getLives()));
            std::cout << score << std::endl;
            dynamic_cast<Alien *>(sprites["Alien"])->setLives(initialAlienLives);
        }
    }

    if (dynamic_cast<Ship *>(sprites["Ship"])->getLives() != shipLives) {
        shipLives = dynamic_cast<Ship *>(sprites["Ship"])->getLives();
        points.setString("Points: " + std::to_string(score) + "\nLives: " + std::to_string(shipLives));
    }

    if (sprites["Alien"]->getPosition().y > 600 - 100 ||
        sprites["Ship"]->getGlobalBounds().intersects(sprites["Alien"]->getGlobalBounds())) {
        if (!(dynamic_cast<Ship *>(sprites["Ship"])->getDamage())) {
            gameOverScreen();
        }
        sprites["Alien"]->setPosition(rand() % 600 + 100, 50.f);
        sprites["Alien"]->setPosition(rand() % 600 + 100, 50.f);
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
    gameOver = true;

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
    for (const auto &sprite: sprites) {
        delete sprite.second;
    }
}

void GameEngine::run() {
    sf::Clock clock;
    while (active()) {
        float dt;
        dt = clock.restart().asSeconds();
        eventManager();
        update(dt);
        render();
    }

}
