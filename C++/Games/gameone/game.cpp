// game.cpp
#include "game.h"
#include <sstream>
// Constructor
game::game() {
    // Other initialization code...

    // Load enemy textures and initialize texture points map
    sf::Texture texture1, texture2, texture3;
    // Load textures...
    if (texture1.getSize().x == 0 || texture2.getSize().x == 0 || texture3.getSize().x == 0) {
        std::cerr << "Error: Failed to load one or more enemy textures!" << std::endl;
    }
    else {
        enemyTextures.push_back(texture1);
        enemyTextures.push_back(texture2);
        enemyTextures.push_back(texture3);
    }

    texturePointMap[&texture1] = 10;
    texturePointMap[&texture2] = 20;
    texturePointMap[&texture3] = 30;
}
// Destructor
game::~game() {
    delete window;
}

void game::initVariables() {
    this->window = nullptr;
    this->endgame = false;
    this->points = 0;
    this->health = 20;
    this->enemySpawnTimerMax = 30.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;
    this->mouseHeld = false;
}

void game::initTexture() {
    if (!this->enemyTexture.loadFromFile("E:\\c++ programs\\game1\\gameone\\images\\blue.png")) {
        std::cerr << "Failed to load image!" << std::endl;
    }
}

void game::initFonts() {
    this->font.loadFromFile("Fonts/Gameplay.ttf");
}

void game::initText() {
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(20);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setString("None");
}

void game::initWindow() {
    this->videomode.height = 1080;
    this->videomode.width = 1920;
    this->window = new sf::RenderWindow(this->videomode, "Game One", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
}

void game::initEnemies() {
    sf::Sprite enemySprite(this->enemyTexture);
    enemySprite.setPosition(10.f, 10.f);
    this->enemies.push_back(enemySprite);
}

void game::initEndScreenText() {
    this->endScreenText.setFont(this->font);
    this->endScreenText.setCharacterSize(30);
    this->endScreenText.setString("Game Over\nPress Space to Restart");
    this->endScreenText.setFillColor(sf::Color::White);

    sf::FloatRect textRect = this->endScreenText.getLocalBounds();
    float offsetY = 50.0f;
    this->endScreenText.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    this->endScreenText.setPosition(sf::Vector2f(this->window->getSize().x / 2.0f,
        this->window->getSize().y - textRect.height - offsetY));
}

void game::renderEndScreen() {
    this->window->draw(this->endScreenText);
}

void game::updateEndScreen() {
    if (this->endgame) {
        std::stringstream ss;
        ss << "Game Over! Final Score: " << this->points << "\n  Press SPACE to try again";
        this->endScreenText.setString(ss.str());
    }
}

void game::restartGame() {
    this->points = 0;
    this->health = 20;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->enemies.clear();
    this->endgame = false;
}

void game::restart() {
    this->restartGame();
    this->initText();
}

const bool game::running() const {
    return this->window->isOpen();
}

const bool game::getendgame() const {
    return this->endgame;
}

void game::spawnEnemy() {
    if (enemyTextures.empty()) {
        std::cerr << "Error: No enemy textures available!" << std::endl;
        return;
    }

    int textureIndex = rand() % enemyTextures.size();
    sf::Texture& selectedTexture = enemyTextures[textureIndex];

    auto it = texturePointMap.find(&selectedTexture);
    if (it != texturePointMap.end()) {
        unsigned int points = it->second;
        sf::Sprite enemySprite(selectedTexture);
        enemies.push_back(enemySprite);
    }
    else {
        std::cerr << "Error: Selected texture not found in texturePointMap!" << std::endl;
    }
}
void game::updateMousePositions() {
    this->mouseposwindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mouseposwindow);
}

void game::updateText() {
    std::stringstream ss;
    ss << "Points: " << this->points << "\n"
        << "Health: " << this->health << "\n";
    this->uiText.setString(ss.str());
}

void game::pollEvents() {
    if (this->window) {
        while (this->window->pollEvent(this->ev)) {
            switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
            case sf::Event::MouseButtonPressed:
                if (this->ev.mouseButton.button == sf::Mouse::Left) {
                    this->updateMousePositions();
                    for (auto it = this->enemies.begin(); it != this->enemies.end(); ++it) {
                        if (it->getGlobalBounds().contains(this->mousePosView)) {
                            this->points += 1;
                            std::cout << "Points: " << this->points << std::endl;
                            this->enemies.erase(it);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
}
void game::update() {
    this->pollEvents();
    if (!this->endgame) {
        this->updateText();
        for (size_t i = 0; i < this->enemies.size(); ++i) {
            // Declare and initialize textureIndex
            int textureIndex = rand() % enemyTextures.size();
            sf::Texture& selectedTexture = enemyTextures[textureIndex];

            // Use selectedTexture instead of texture
            auto it = texturePointMap.find(&selectedTexture);
            if (it != texturePointMap.end()) {
                points += it->second;
            }
        }
    }
    if (this->health <= 0)
        this->endgame = true;
    if (this->endgame && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        this->restartGame();
    }
}
void game::render() {
    if (this->window) { // Check if window is not null
        this->window->clear();
        if (this->endgame) {
            this->renderEndScreen();
        }
        // Add rendering code for enemies and text here
        this->window->display();
    }
}