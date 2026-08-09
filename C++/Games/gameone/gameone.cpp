
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <algorithm>

class Game
{
private:
    enum class State
    {
        Menu,
        Playing,
        Pause,
        End,
    };

    sf::RenderWindow window;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::Sprite menuBackgroundSprite;
    sf::Texture menuBackgroundTexture;
    sf::Texture endScreenBackgroundTexture;
    sf::Sprite escapeButtonSprite;

    // Game variables
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Font font;
    sf::Text uiText;
    sf::Text startText;
    sf::Text quitText;
    sf::Text playAgainText; // Added playAgainText
    sf::Text resumeText; // Define resumeText
    sf::Text exitToMenuText; // Define exitToMenuText
    sf::Texture pauseTexture; // Add pauseTexture
    sf::Sprite pauseSprite;   // Add pauseSprite
    sf::Texture overlayTexture; 
    sf::Sprite overlaySprite;   

    sf::Music backgroundMusic;

    sf::SoundBuffer bufferPop1;
    sf::Sound pop1;

    sf::SoundBuffer bufferPop2;
    sf::Sound pop2;

    sf::SoundBuffer bufferPop3;
    sf::Sound pop3;

    sf::SoundBuffer bufferPop4;
    sf::Sound pop4;

    sf::SoundBuffer bufferSelect;
    sf::Sound select;

    State gameState;

    unsigned points;
    int health;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    std::vector<sf::Texture> enemyTextures;
    std::vector<sf::Sprite> enemies;
    int lastPurpleSpawnPoints; // Track the points at which the last purple enemy was spawned
    bool paused; // Variable to track if the game is paused
    bool pauseRendered;

    // Private functions
    void initVariables();
    void initWindow();
    void initFonts();
    void initText();
    void initEnemies();
    void initBackground();
    void initMenuBackground();
    void initPlayingOverlay();

    void handleMenuInput();
    void handleGameInput();
    void handleEndInput(); // Added handleEndInput
    void updateEnemies();
    void renderText(sf::RenderTarget& target);
    void renderEnemies(sf::RenderTarget& target);
    void renderMenu(sf::RenderTarget& target);
    void renderEndScreen(sf::RenderTarget& target); // Added renderEndScreen
    void renderPlayingOverlay(sf::RenderTarget& target);

    void handlePauseInput();
    void renderPauseOverlay(sf::RenderTarget& target);

public:
    // Constructors / Destructors
    Game();
    virtual ~Game();

    // Accessors
    const bool running() const;

    // Functions
    void spawnPurpleEnemy();
    void spawnEnemy();
    void pollEvents();
    void render();
    void update();
    void initPauseOverlay(); // Add initPauseOverlay function
    void initBackgroundMusic();
    void initSounds();
};

void Game::initVariables()
{
    // Game logic
    gameState = State::Menu;
    points = 0;
    health = 20;
    enemySpawnTimerMax = 100.f;
    enemySpawnTimer = enemySpawnTimerMax;
    maxEnemies = 5;
    lastPurpleSpawnPoints = 0; // Initialize lastPurpleSpawnPoints
    paused = false; // Initialize paused state
    pauseRendered = false; // Initialize pauseRendered
}

void Game::initWindow()
{
    window.create(sf::VideoMode(800, 600), "Game 1", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
}

void Game::initBackgroundMusic()
{
    if (!backgroundMusic.openFromFile("Audio/Music.ogg")) // Use a valid path to your music file
    {
        std::cerr << "Failed to load background music!" << std::endl;
        return;
    }
    backgroundMusic.setLoop(true);  // Enable looping
    backgroundMusic.setVolume(50);  // Set volume (0-100)
    backgroundMusic.play();         // Start playing the music
}

void Game::initBackground()
{
    if (!backgroundTexture.loadFromFile("images/bg.png"))
    {
        std::cerr << "Failed to load background texture!" << std::endl;
        return;
    }
    backgroundSprite.setTexture(backgroundTexture);
    float scaleX = static_cast<float>(window.getSize().x) / backgroundSprite.getLocalBounds().width;
    float scaleY = static_cast<float>(window.getSize().y) / backgroundSprite.getLocalBounds().height;
    backgroundSprite.setScale(scaleX, scaleY);
    sf::Color color = backgroundSprite.getColor();
    color.a = 255;
    backgroundSprite.setColor(color);
}

void Game::initMenuBackground()
{
    if (!menuBackgroundTexture.loadFromFile("images/menu.png")) {
        std::cerr << "Failed to load menu background texture!" << std::endl;
        // Handle error...
    }

    menuBackgroundSprite.setTexture(menuBackgroundTexture);
    float scaleX = static_cast<float>(window.getSize().x) / menuBackgroundSprite.getLocalBounds().width;
    float scaleY = static_cast<float>(window.getSize().y) / menuBackgroundSprite.getLocalBounds().height;
    menuBackgroundSprite.setScale(scaleX, scaleY);
    sf::Color color = menuBackgroundSprite.getColor();
    color.a = 255;
    menuBackgroundSprite.setColor(color);
}

void Game::initEnemies()
{
    sf::Texture enemyTexture1, enemyTexture2, enemyTexture3, enemyTexture4; // Add more texture variables as needed
    if (!enemyTexture1.loadFromFile("images/red.png"))
    {
        std::cerr << "Failed to load enemy texture 1!" << std::endl;
        return;
    }
    if (!enemyTexture2.loadFromFile("images/blue.png"))
    {
        std::cerr << "Failed to load enemy texture 2!" << std::endl;
        return;
    }
    if (!enemyTexture3.loadFromFile("images/yellow.png"))
    {
        std::cerr << "Failed to load enemy texture 3!" << std::endl;
        return;
    }
    if (!enemyTexture4.loadFromFile("images/green.png"))
    {
        std::cerr << "Failed to load enemy texture 4!" << std::endl;
        return;
    }

    enemyTextures.push_back(enemyTexture1);
    enemyTextures.push_back(enemyTexture2);
    enemyTextures.push_back(enemyTexture3);
    enemyTextures.push_back(enemyTexture4);
}

void Game::initFonts()
{
    if (!font.loadFromFile("fonts/Gameplay.ttf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
    }
}

void Game::initText()
{
    uiText.setFont(font);
    uiText.setCharacterSize(24);
    uiText.setFillColor(sf::Color::White);
    uiText.setPosition(10.f, 10.f);

    startText.setFont(font);
    startText.setString("Start");
    startText.setCharacterSize(50);
    startText.setFillColor(sf::Color::White);
    startText.setPosition(window.getSize().x / 2 - startText.getGlobalBounds().width / 2, window.getSize().y / 2 - 50);

    quitText.setFont(font);
    quitText.setString("Quit");
    quitText.setCharacterSize(50);
    quitText.setFillColor(sf::Color::White);
    quitText.setPosition(window.getSize().x / 2 - quitText.getGlobalBounds().width / 2, window.getSize().y / 2 + 25);

    playAgainText.setFont(font);
    playAgainText.setString("Play Again");
    playAgainText.setCharacterSize(36);
    playAgainText.setFillColor(sf::Color::White);
    playAgainText.setPosition(window.getSize().x / 2 - playAgainText.getGlobalBounds().width / 2, window.getSize().y / 2 + 100);

    resumeText.setFont(font);
    resumeText.setString("Resume");
    resumeText.setCharacterSize(36);
    resumeText.setFillColor(sf::Color::White);
    resumeText.setPosition(window.getSize().x / 2 - resumeText.getGlobalBounds().width / 2, window.getSize().y / 2 - 50);

    exitToMenuText.setFont(font);
    exitToMenuText.setString("Exit to Menu");
    exitToMenuText.setCharacterSize(36);
    exitToMenuText.setFillColor(sf::Color::White);
    exitToMenuText.setPosition(window.getSize().x / 2 - exitToMenuText.getGlobalBounds().width / 2, window.getSize().y / 2 + 50);
}

void Game::initPauseOverlay()
{
    if (!pauseTexture.loadFromFile("images/pause.png"))
    {
        std::cerr << "Failed to load pause overlay texture!" << std::endl;
        return;
    }

    // Set smooth property to true for better quality
    pauseTexture.setSmooth(true);

    pauseSprite.setTexture(pauseTexture);
    pauseSprite.setPosition(0, 0);

    // Set scale to cover the entire window
    float scaleX = static_cast<float>(window.getSize().x) / pauseSprite.getLocalBounds().width;
    float scaleY = static_cast<float>(window.getSize().y) / pauseSprite.getLocalBounds().height;
    pauseSprite.setScale(scaleX, scaleY);
}

void Game::initPlayingOverlay()
{
    if (!overlayTexture.loadFromFile("images/ov.png"))
    {
        std::cerr << "Failed to load pause overlay texture!" << std::endl;
        return;
    }

    // Set smooth property to true for better quality
    overlayTexture.setSmooth(true);

    overlaySprite.setTexture(overlayTexture);
    overlaySprite.setPosition(0, 0);

    // Set scale to cover the entire window
    float scaleX = static_cast<float>(window.getSize().x) / overlaySprite.getLocalBounds().width;
    float scaleY = static_cast<float>(window.getSize().y) / overlaySprite.getLocalBounds().height;
    overlaySprite.setScale(scaleX, scaleY);
}

Game::Game()
{
    initVariables();
    initWindow();
    initFonts();
    initText();
    initEnemies();
    initBackground();
    initMenuBackground();
    initBackgroundMusic();
    initPlayingOverlay(); // Initialize playing overlay
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    if (!endScreenBackgroundTexture.loadFromFile("images/endscreen.png")) {
        std::cerr << "Failed to load end screen background texture!" << std::endl;
        // Handle error...
    }
}

Game::~Game() {}

const bool Game::running() const
{
    return window.isOpen();
}

void Game::spawnPurpleEnemy()
{
    sf::Sprite purpleEnemy;
    purpleEnemy.setTexture(enemyTextures[3]); // Purple enemy texture
    purpleEnemy.setScale(0.75f, 0.75f);      // Scale

    bool collision = true;
    sf::FloatRect purpleEnemyBounds;

    while (collision)
    {
        purpleEnemy.setPosition(
            static_cast<float>(rand() % static_cast<int>(window.getSize().x - purpleEnemy.getGlobalBounds().width)),
            static_cast<float>(window.getSize().y + rand() % 500));
        purpleEnemyBounds = purpleEnemy.getGlobalBounds();
        collision = false;
        for (const auto& enemy : enemies)
        {
            if (purpleEnemyBounds.intersects(enemy.getGlobalBounds()))
            {
                collision = true;
                break;
            }
        }
    }

    enemies.push_back(purpleEnemy);
}

void Game::spawnEnemy()
{
    int numEnemies = std::min(3 + static_cast<int>(points / 100), maxEnemies); // Limiting to 3 at start, increase with points but not exceeding maxEnemies
    int lastType = -1; // Track the last enemy type

    for (int i = 0; i < numEnemies; ++i)
    {
        int type;
        do
        {
            type = rand() % 3; // Randomly select texture (excluding purple)
        } while (type == lastType); // Ensure a different type from the last one

        lastType = type; // Update the last type
        sf::Sprite newEnemy;
        newEnemy.setTexture(enemyTextures[type]);

        // Set scale based on type
        switch (type)
        {
        case 0:
            newEnemy.setScale(1.0f, 1.0f); // Scale for first type
            break;
        case 1:
            newEnemy.setScale(0.85f, 0.85f); // Scale for second type
            break;
        case 2:
            newEnemy.setScale(0.7f, 0.7f); // Scale for third type
            break;
        }

        bool collision = true;
        sf::FloatRect newEnemyBounds;
        while (collision)
        {
            newEnemy.setPosition(
                static_cast<float>(rand() % static_cast<int>(window.getSize().x - newEnemy.getGlobalBounds().width)),
                static_cast<float>(window.getSize().y + rand() % 500));
            newEnemyBounds = newEnemy.getGlobalBounds();
            collision = false;
            for (const auto& enemy : enemies)
            {
                if (newEnemyBounds.intersects(enemy.getGlobalBounds()))
                {
                    collision = true;
                    break;
                }
            }
        }
        enemies.push_back(newEnemy);
    }
}


void Game::updateEnemies()
{
    // Maximum number of enemies increases as points increase, up to a limit of 7
    int maxEnemiesIncrease = std::min(static_cast<int>(std::sqrt(points) / 100), 5);
    maxEnemies = std::min(3 + maxEnemiesIncrease, 7);

    // Simplified spawn delay that decreases linearly with points
    float spawnDelayDecrease = std::min(points / 2000.0f, 4.0f); // Caps the decrease at 4 seconds
    enemySpawnTimerMax = std::max(1.0f, 5.0f - spawnDelayDecrease); // Ensures a minimum spawn delay of 1 second

    // Spawn an enemy if conditions are met
    if (!paused && enemies.size() < maxEnemies && enemySpawnTimer >= enemySpawnTimerMax)
    {
        spawnEnemy();
        enemySpawnTimer = 0.f; // Reset the spawn timer after spawning an enemy
    }
    else
    {
        enemySpawnTimer += 1.f; // Increment the spawn timer
    }

    // Base fall speed and maximum fall speed
    float baseFallSpeed = 3.0f;
    float maxFallSpeed = 8.0f;

    // Fall speed increases linearly with points, capped at maxFallSpeed
    float fallSpeed = std::min(baseFallSpeed + points * 0.002f, maxFallSpeed);

    // Vector to hold enemies marked for removal
    std::vector<std::vector<sf::Sprite>::iterator> enemiesToRemove;

    // Move and remove enemies
    for (auto it = enemies.begin(); it != enemies.end(); ++it)
    {
        it->move(0.f, -fallSpeed); // Move enemies based on fallSpeed
        if (it->getPosition().y + it->getGlobalBounds().height < 0) // Check if enemy is off-screen
        {
            health -= 1;
            enemiesToRemove.push_back(it); // Mark enemy for removal
        }
    }

    for (auto it = enemiesToRemove.rbegin(); it != enemiesToRemove.rend(); ++it)
    {
        enemies.erase(*it);
    }

    // Chance-based spawn for purple enemies
    if (points - lastPurpleSpawnPoints >= 500) {
        if (rand() % 1000 < 2) { // Approximately 2 out of 1000 chance
            spawnPurpleEnemy();
            lastPurpleSpawnPoints = points; // Update the last spawn point
        }
    }
}


void Game::pollEvents()
{
    sf::Event ev;
    while (window.pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            if (ev.mouseButton.button == sf::Mouse::Left)
            {
                mousePosWindow = sf::Mouse::getPosition(window);
                mousePosView = window.mapPixelToCoords(mousePosWindow);

                switch (gameState)
                {
                case State::Menu:
                    handleMenuInput();
                    break;
                case State::Playing:
                    handleGameInput();
                    break;
                case State::End:
                    handleEndInput();
                    break;
                case State::Pause:
                    if (resumeText.getGlobalBounds().contains(mousePosView))
                    {
                        paused = false; // Resume the game
                        gameState = State::Playing;
                    }
                    else if (exitToMenuText.getGlobalBounds().contains(mousePosView))
                    {
                        gameState = State::Menu; // Return to menu
                    }
                    break;
                }
            }
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
            {
                if (gameState == State::Playing)
                {
                    backgroundMusic.pause();
                    paused = true; // Pause the game
                    gameState = State::Pause;
                }
                else if (gameState == State::Pause)
                {
                    if (backgroundMusic.getStatus() != sf::Music::Playing)
                        backgroundMusic.play(); // Resume playing
                    paused = false; // Resume the game
                    gameState = State::Playing;
                }
            }
            break;
        }
    }
}

void Game::handleMenuInput()
{
    if (startText.getGlobalBounds().contains(mousePosView))
    {
        gameState = State::Playing;
        points = 0;
        health = 20;
        enemies.clear();
        paused = false; // Ensure the game is not paused when starting
        pauseRendered = false; // Reset pauseRendered flag
    }
    else if (quitText.getGlobalBounds().contains(mousePosView))
    {
        window.close();
    }
}

void Game::handleGameInput()
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(mousePosWindow.x, mousePosWindow.y));
    for (auto it = enemies.begin(); it != enemies.end(); ++it)
    {
        sf::FloatRect enemyBounds = it->getGlobalBounds();
        if (enemyBounds.contains(mousePos))
        {
            sf::Vector2i pixelPos = sf::Vector2i(mousePos.x - enemyBounds.left, mousePos.y - enemyBounds.top);
            sf::Color color = it->getTexture()->copyToImage().getPixel(pixelPos.x / enemyBounds.width * it->getTexture()->getSize().x, pixelPos.y / enemyBounds.height * it->getTexture()->getSize().y);
            if (color.a != 0)
            {
                // Check if it's a purple enemy
                if (it->getTexture() == &enemyTextures[3])
                {
                    // Increase health by 5
                    health += 5;
                }
                else
                {
                    // Increase points based on the texture type
                    int textureIndex = -1;
                    for (size_t i = 0; i < enemyTextures.size(); ++i)
                    {
                        if (it->getTexture() == &enemyTextures[i])
                        {
                            textureIndex = i;
                            break;
                        }
                    }
                    if (textureIndex >= 0 && textureIndex <= 2)
                    {
                        points += 10 * (textureIndex + 1); // Increment points based on type
                    }
                }
                // Remove the enemy
                enemies.erase(it);
                break;
            }
        }
    }
}

void Game::handlePauseInput()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        mousePosWindow = sf::Mouse::getPosition(window);
        mousePosView = window.mapPixelToCoords(mousePosWindow);

        if (resumeText.getGlobalBounds().contains(mousePosView))
        {
            paused = false; // Resume the game
            gameState = State::Playing;
        }
        else if (exitToMenuText.getGlobalBounds().contains(mousePosView))
        {
            gameState = State::Menu; // Exit to menu
            paused = false; // Reset paused state
            points = 0; // Reset points
            health = 20; // Reset health
            enemies.clear(); // Clear enemies
        }
    }
}

void Game::handleEndInput()
{
    if (playAgainText.getGlobalBounds().contains(mousePosView))
    {
        gameState = State::Playing;
        points = 0;
        health = 20;
        enemies.clear(); // Clear enemies vector when restarting the game
        paused = false; // Reset paused state
    }
    else if (quitText.getGlobalBounds().contains(mousePosView))
    {
        window.close();
    }
}

void Game::update()
{
    pollEvents();
    if (!paused) // Update the game only if it's not paused
    {
        updateEnemies();

        if (health <= 0)
        {
            gameState = State::End;
        }
    }
    else if (!pauseRendered) // Render the pause screen only once
    {
        render();
        pauseRendered = true;
    }
}

void Game::renderText(sf::RenderTarget& target)
{
    std::stringstream ss;
    ss << "Points: " << points << "\n"
        << "Health: " << health;
    uiText.setString(ss.str());
    target.draw(uiText);

    // Render playAgainText if in End state
    if (gameState == State::End)
    {
        target.draw(playAgainText);
    }
}

void Game::renderEnemies(sf::RenderTarget& target)
{
    for (auto& e : enemies)
    {
        target.draw(e);
    }
}

void Game::renderMenu(sf::RenderTarget& target)
{
    target.draw(menuBackgroundSprite);
    target.draw(startText);
    target.draw(quitText);
}

void Game::renderEndScreen(sf::RenderTarget& target)
{
    sf::Sprite endScreenBackgroundSprite;
    endScreenBackgroundSprite.setTexture(endScreenBackgroundTexture);
    target.draw(endScreenBackgroundSprite);

    sf::Text endText;
    endText.setFont(font);
    endText.setString(" Game Over ");
    endText.setCharacterSize(40);
    endText.setFillColor(sf::Color::White);
    endText.setPosition(window.getSize().x / 2 - endText.getGlobalBounds().width / 2, window.getSize().y / 2 - 50);
    target.draw(endText);

    // Draw total points text
    sf::Text endText2;
    endText2.setFont(font);
    endText2.setString("Total Points: " + std::to_string(points));
    endText2.setCharacterSize(30);
    endText2.setFillColor(sf::Color::White);
    endText2.setPosition(window.getSize().x / 2 - endText2.getGlobalBounds().width / 2, window.getSize().y / 2 + 8); // Adjusted y-coordinate
    target.draw(endText2);

    // Draw play again text
    target.draw(playAgainText);
}
void Game::renderPauseOverlay(sf::RenderTarget& target)
{
    if (paused)
    {
        target.draw(pauseSprite);

        // Center the options horizontally at the bottom of the screen
        float posX = (window.getSize().x - resumeText.getGlobalBounds().width - exitToMenuText.getGlobalBounds().width - 00) / 2.f;
        float posY = window.getSize().y - resumeText.getGlobalBounds().height - 20;

        resumeText.setPosition(posX - resumeText.getGlobalBounds().width + 110, posY);
        exitToMenuText.setPosition(posX + resumeText.getGlobalBounds().width + 50, posY);

        target.draw(resumeText);
        target.draw(exitToMenuText);
    }
}

void Game::renderPlayingOverlay(sf::RenderTarget& target)
{
        target.draw(overlaySprite);
}

void Game::render()
{
    window.clear();

    switch (gameState)
    {
    case State::Menu:
        renderMenu(window);
        break;
    case State::Playing:
        window.draw(backgroundSprite);
        renderEnemies(window);
        renderPlayingOverlay(window);
        renderText(window);
        break;
    case State::End:
        renderEndScreen(window);
        break;
    case State::Pause:
        renderPauseOverlay(window); // Render pause overlay
        break;
    }

    window.display();
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    Game game;
    game.initPauseOverlay(); // Initialize pause overlay

    while (game.running())
    {
        game.update();
        game.render();
    }

    return 0;
}


/*
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

const int width = 800;
const int height = 600;
const int blockSize = 20;
const int numBlocksX = width / blockSize;
const int numBlocksY = height / blockSize;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Fruit {
public:
    int x, y;
    Fruit() {
        Spawn();
    }
    void Spawn() {
        x = rand() % numBlocksX;
        y = rand() % numBlocksY;
    }
};

class Snake {
public:
    int body[100][2];
    int length;
    Direction dir;
    bool isGameOver;

    Snake() {
        Reset();
    }

    void Reset() {
        length = 1;
        body[0][0] = numBlocksX / 2;
        body[0][1] = numBlocksY / 2;
        dir = STOP;
        isGameOver = false;
    }

    void ChangeDirection(Direction newDir) {
        if ((dir == LEFT && newDir != RIGHT) ||
            (dir == RIGHT && newDir != LEFT) ||
            (dir == UP && newDir != DOWN) ||
            (dir == DOWN && newDir != UP) ||
            dir == STOP) {
            dir = newDir;
        }
    }

    void Move() {
        if (dir == STOP) return;

        int newX = body[0][0];
        int newY = body[0][1];

        if (dir == LEFT) newX--;
        if (dir == RIGHT) newX++;
        if (dir == UP) newY--;
        if (dir == DOWN) newY++;

        if (newX < 0 || newX >= numBlocksX || newY < 0 || newY >= numBlocksY) {
            isGameOver = true;
            return;
        }

        for (int i = length; i > 0; i--) {
            body[i][0] = body[i - 1][0];
            body[i][1] = body[i - 1][1];
        }
        body[0][0] = newX;
        body[0][1] = newY;

        // Check for self-collision, excluding the last segment
        for (int i = 1; i < length - 1; i++) {
            if (body[i][0] == newX && body[i][1] == newY) {
                isGameOver = true;
            }
        }
    }

    void Grow() {
        length++;
    }

    bool CheckCollision(int x, int y) {
        for (int i = 0; i < length; i++) {
            if (body[i][0] == x && body[i][1] == y) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    sf::RenderWindow window(sf::VideoMode(width, height), "Snake Game");

    Snake snake;
    Fruit fruit;
    int playerScore = 0;

    sf::Clock clock;
    float timer = 0.0f;
    float delay = 0.1f;

    while (window.isOpen()) {
        float time = clock.restart().asSeconds();
        timer += time;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            snake.ChangeDirection(LEFT);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            snake.ChangeDirection(RIGHT);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            snake.ChangeDirection(UP);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            snake.ChangeDirection(DOWN);
        }

        if (timer > delay) {
            timer = 0.0f;
            snake.Move();

            if (snake.isGameOver) {
                std::cout << "Game Over! Your score is " << playerScore << std::endl;
                snake.Reset();
                playerScore = 0;
            }

            if (snake.CheckCollision(fruit.x, fruit.y)) {
                snake.Grow();
                fruit.Spawn();
                playerScore += 10;
            }
        }

        window.clear();

        sf::RectangleShape segmentShape(sf::Vector2f(blockSize, blockSize));
        segmentShape.setFillColor(sf::Color::Green);
        for (int i = 0; i < snake.length; i++) {
            segmentShape.setPosition(snake.body[i][0] * blockSize, snake.body[i][1] * blockSize);
            window.draw(segmentShape);
        }

        sf::RectangleShape fruitShape(sf::Vector2f(blockSize, blockSize));
        fruitShape.setFillColor(sf::Color::Red);
        fruitShape.setPosition(fruit.x * blockSize, fruit.y * blockSize);
        window.draw(fruitShape);

        window.display();
    }

    return 0;
}

*/

/*
#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>


int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(400, 400), "Analog Clock");

    // Load font for displaying digital time
    sf::Font font;
    if (!font.loadFromFile("E:\\c++ programs\\game1\\gameone\\fonts\\Gameplay.ttf")) {
        return EXIT_FAILURE;
    }

    // Create clock hands
    sf::RectangleShape hourHand(sf::Vector2f(120, 4));
    sf::RectangleShape minuteHand(sf::Vector2f(160, 2));
    sf::RectangleShape secondHand(sf::Vector2f(180, 1));

    // Set origin of hands to their centers
    hourHand.setOrigin(60, 2);
    minuteHand.setOrigin(80, 1);
    secondHand.setOrigin(90, 0.5f);

    // Set colors for clock hands
    hourHand.setFillColor(sf::Color::Black);
    minuteHand.setFillColor(sf::Color::Blue);
    secondHand.setFillColor(sf::Color::Red);

    // Create clock face
    sf::CircleShape clockFace(200);
    clockFace.setFillColor(sf::Color::White);
    clockFace.setOutlineThickness(2);
    clockFace.setOutlineColor(sf::Color::Black);
    clockFace.setOrigin(200, 200);

    // Create text for displaying digital time
    sf::Text digitalTime;
    digitalTime.setFont(font);
    digitalTime.setCharacterSize(24);
    digitalTime.setFillColor(sf::Color::Black);
    digitalTime.setOutlineColor(sf::Color::White);
    digitalTime.setOutlineThickness(2);

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Get current time
        std::time_t currentTime = std::time(nullptr);
        std::tm localTime;
        localtime_s(&localTime, &currentTime);

        // Update rotation of clock hands
        hourHand.setRotation(localTime.tm_hour * 30 + localTime.tm_min / 2);
        minuteHand.setRotation(localTime.tm_min * 6 + localTime.tm_sec / 10);
        secondHand.setRotation(localTime.tm_sec * 6);

        // Update digital time
        std::string timeStr = std::to_string(localTime.tm_hour) + ":" +
            std::to_string(localTime.tm_min) + ":" +
            std::to_string(localTime.tm_sec);
        digitalTime.setString(timeStr);

        // Clear the window
        window.clear(sf::Color::White);

        // Draw clock face
        window.draw(clockFace);

        // Draw clock hands
        window.draw(hourHand);
        window.draw(minuteHand);
        window.draw(secondHand);

        // Draw digital time
        digitalTime.setPosition(160, 360);
        window.draw(digitalTime);

        // Display everything
        window.display();
    }

    return 0;
}

*/