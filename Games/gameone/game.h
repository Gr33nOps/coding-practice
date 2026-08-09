// game.h
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <ctime> // Include <ctime> for time()

class game {
private:
    sf::RenderWindow* window;
    sf::VideoMode videomode;
    sf::Event ev;

    bool endgame;
    unsigned int points;
    unsigned int health;
    float enemySpawnTimerMax;
    float enemySpawnTimer;
    unsigned int maxEnemies;
    bool mouseHeld;

    sf::Text uiText;
    sf::Font font;
    sf::Text endScreenText;

    sf::Texture enemyTexture; // Declare enemyTexture

    std::vector<sf::Texture> enemyTextures; // Add enemyTextures vector
    std::vector<sf::Sprite> enemies;
    std::map<const sf::Texture*, unsigned int> texturePointMap;

    sf::Vector2i mouseposwindow; // Declare mouse position variables
    sf::Vector2f mousePosView;

public:
    // Member functions declaration
    game();
    ~game();

    const bool running() const;
    const bool getendgame() const;

    void initVariables(); // Corrected function name
    void initTexture();
    void initFonts();
    void initText();
    void initWindow(); // Corrected function name
    void initEnemies();
    void initEndScreenText();
    void renderEndScreen();
    void updateEndScreen();
    void restartGame();
    void restart();
    void spawnEnemy();
    void updateMousePositions();
    void updateText();
    void pollEvents(); // Corrected function name
    void update();
    void render();
};

#endif // GAME_H
