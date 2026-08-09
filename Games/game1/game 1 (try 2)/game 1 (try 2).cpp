#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Game {
private:
    sf::RenderWindow window;
    sf::Texture enemyTexture;
    sf::Sprite enemy;
    unsigned int points;
    bool endgame;

public:
    Game() : window(sf::VideoMode(800, 600), "Simple Game"), points(0), endgame(false) {
        window.setFramerateLimit(60);
        if (!enemyTexture.loadFromFile("enemy.png")) {
            std::cerr << "Failed to load image!" << std::endl;
            return;
        }
        enemy.setTexture(enemyTexture);
        enemy.setPosition(400.f, 600.f);
    }

    void run() {
        sf::Clock clock;
        sf::Time spawnTimer = sf::seconds(1.0f);

        while (window.isOpen()) {
            handleEvents();
            if (!endgame) {
                update(spawnTimer, clock.restart());
            }
            render();
        }
    }

private:
    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    void update(sf::Time& spawnTimer, sf::Time dt) {
        if (spawnTimer <= sf::Time::Zero) {
            enemy.setPosition(rand() % 700 + 50.f, 600.f);
            spawnTimer = sf::seconds(1.0f);
        }
        else {
            spawnTimer -= dt;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && enemy.getPosition().y <= 0.f) {
            points++;
            std::cout << "Points: " << points << std::endl;
        }

        if (enemy.getPosition().y <= 0.f) {
            endgame = true;
        }
        else {
            enemy.move(0.f, -100.f * dt.asSeconds());
        }
    }

    void render() {
        window.clear();
        window.draw(enemy);
        window.display();
    }
};

int main() {
    std::srand(static_cast<unsigned>(time(NULL)));
    Game game;
    game.run();
    return 0;
}