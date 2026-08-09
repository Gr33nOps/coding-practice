#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>

#ifdef _WIN32
#include <Windows.h>
#endif

using namespace sf;
using namespace std;

// Forward declarations
class GameLogic;
class GameDesign;
class EventHandling;

// Define different game states
enum GameState {
    MAIN_MENU,
    CLICK_TO_PLAY,
    PLAYING,
    GAME_OVER
};

enum Medal {
    BRONZE,
    SILVER,
    GOLD,
    PLATINUM,
    NO_MEDAL
};

// ============================================================================
// RESOURCE MANAGER CLASS
// ============================================================================
class ResourceManager {
public:
    static bool loadTexture(Texture& texture, const string& path) {
        if (!texture.loadFromFile(path)) {
            cerr << "Error loading texture from " << path << endl;
            return false;
        }
        return true;
    }

    static bool loadFont(Font& font, const string& path) {
        if (!font.loadFromFile(path)) {
            cerr << "Error loading font from " << path << endl;
            return false;
        }
        return true;
    }
};

// ============================================================================
// SOUND MANAGER CLASS
// ============================================================================
class SoundManager {
private:
    SoundBuffer flapBuffer;
    SoundBuffer scoreBuffer;
    SoundBuffer collisionBuffer;
    Sound flapSound;
    Sound scoreSound;
    Sound collisionSound;

public:
    bool checkCollisionSound;

    SoundManager() : checkCollisionSound(true) {
        // Load sound files
        if (!flapBuffer.loadFromFile("audio/audio_flap.wav")) {
            cerr << "Error loading flap sound" << endl;
        }
        if (!scoreBuffer.loadFromFile("audio/audio_score.wav")) {
            cerr << "Error loading score sound" << endl;
        }
        if (!collisionBuffer.loadFromFile("audio/audio_crash.wav")) {
            cerr << "Error loading collision sound" << endl;
        }

        // Set buffers to sounds
        flapSound.setBuffer(flapBuffer);
        scoreSound.setBuffer(scoreBuffer);
        collisionSound.setBuffer(collisionBuffer);
    }

    void playFlapSound() {
        flapSound.play();
    }

    void playScoreSound() {
        scoreSound.play();
    }

    void playCollisionSound() {
        if (checkCollisionSound) {
            collisionSound.play();
        }
    }
};

// ============================================================================
// GAME LOGIC CLASS
// ============================================================================
class GameLogic {
private:
    // Game constants
    static const float GROUND_Y;
    static const float GROUND_WIDTH;
    static const float GROUND_HEIGHT;
    static const float MAX_ROTATION_UP;
    static const float MAX_ROTATION_DOWN;

    // Bird animation
    int currentBirdTexture;
    int frameCounter;

    // Game state variables
    int frames;
    bool pipeCollided;

    // Bird physics
    float birdVelocity;
    bool isFlapping;

    // Unused variables removed
    float flapDuration;
    float flapTimer;
    float rotation;
    float rotationHoldTimer;
    bool spacePressed;

    // High score management
    void saveHighScore();
    void loadHighScore();

public:
    // Textures and sprites
    Texture bird[3];
    Sprite birdSprite;
    Texture pipeTexture;
    Sprite pipeSprite;
    vector<Sprite> pipes;

    // Game variables
    int score;
    int highScore;
    bool gameOver;

    // Sound manager
    SoundManager soundManager;

    GameLogic();

    // Game mechanics
    void switchBirdTexture();
    void addPipe();
    void drawPipes(RenderWindow& window);
    void updatePipe();
    bool checkPipeCollision();
    void updateBirdPosition(float dt);
    void checkGameOver();
    void removeOffScreenPipes();
    void checkScore();
    void resetGame();

    // Getters for private members
    bool getIsFlapping() const { return isFlapping; }
    void setIsFlapping(bool flapping) { isFlapping = flapping; }
    float getBirdVelocity() const { return birdVelocity; }
    void setBirdVelocity(float velocity) { birdVelocity = velocity; }
    bool getPipeCollided() const { return pipeCollided; }
};

// Static member definitions
const float GameLogic::GROUND_Y = 620.0f;
const float GameLogic::GROUND_WIDTH = 800.0f;
const float GameLogic::GROUND_HEIGHT = 100.0f;
const float GameLogic::MAX_ROTATION_UP = 30.0f;
const float GameLogic::MAX_ROTATION_DOWN = 90.0f;

GameLogic::GameLogic()
    : currentBirdTexture(0), frameCounter(0), frames(0), pipeCollided(false),
    birdVelocity(0.0f), isFlapping(false), flapDuration(2.0f), flapTimer(0.0f),
    rotation(0.0f), rotationHoldTimer(0.5f), spacePressed(false),
    score(0), highScore(0), gameOver(false) {

    // Load bird textures
    ResourceManager::loadTexture(bird[0], "Images/flappy1.png");
    ResourceManager::loadTexture(bird[1], "Images/flappy2.png");
    ResourceManager::loadTexture(bird[2], "Images/flappy3.png");
    birdSprite.setTexture(bird[0]);

    // Load pipe texture
    ResourceManager::loadTexture(pipeTexture, "Images/pipe.png");
    pipeSprite.setTexture(pipeTexture);

    loadHighScore();
}

void GameLogic::switchBirdTexture() {
    frameCounter++;
    if (frameCounter >= 10) {
        currentBirdTexture = (currentBirdTexture + 1) % 3;
        birdSprite.setTexture(bird[currentBirdTexture]);
        frameCounter = 0;
    }
}

void GameLogic::addPipe() {
    if (frames % 120 == 0) {
        int r = rand() % 275 + 75;
        int gap = 200;

        Sprite pipeL(pipeTexture);
        pipeL.setPosition(1000, static_cast<float>(r + gap));

        Sprite pipeU(pipeTexture);
        pipeU.setPosition(1000, static_cast<float>(r));
        pipeU.setScale(1, -1);

        pipes.push_back(pipeL);
        pipes.push_back(pipeU);
    }
    frames++;
}

void GameLogic::drawPipes(RenderWindow& window) {
    for (const auto& pipe : pipes) {
        window.draw(pipe);
    }
}

void GameLogic::updatePipe() {
    for (auto& pipe : pipes) {
        pipe.move(-4, 0);
    }
}

bool GameLogic::checkPipeCollision() {
    if (pipeCollided) return true;

    FloatRect birdBounds = birdSprite.getGlobalBounds();
    for (const auto& pipe : pipes) {
        FloatRect pipeBounds = pipe.getGlobalBounds();
        if (birdBounds.intersects(pipeBounds)) {
            soundManager.playCollisionSound();
            soundManager.checkCollisionSound = false;
            pipeCollided = true;
            return true;
        }
    }
    return false;
}

void GameLogic::updateBirdPosition(float dt) {
    if (pipeCollided) {
        birdVelocity = 0;
        return;
    }

    if (isFlapping) {
        birdVelocity = -13.0f;
        isFlapping = false;
    }

    birdVelocity += 0.3f;
    birdVelocity = min(birdVelocity, 13.0f);
    birdSprite.move(0, birdVelocity * dt);

    if (birdVelocity < 0) {
        birdSprite.setRotation(max(birdVelocity * 1.5f, -MAX_ROTATION_UP));
    }
    else {
        birdSprite.setRotation(min(birdVelocity * 0.5f, MAX_ROTATION_DOWN));
    }

    if (birdSprite.getPosition().y < 0) {
        birdSprite.setPosition(birdSprite.getPosition().x, 0);
        birdVelocity = 0;
    }
}

void GameLogic::checkGameOver() {
    FloatRect groundBounds(0, GROUND_Y, GROUND_WIDTH, GROUND_HEIGHT);
    FloatRect birdBounds = birdSprite.getGlobalBounds();

    if (birdBounds.intersects(groundBounds)) {
        birdSprite.setPosition(birdSprite.getPosition().x, GROUND_Y - birdBounds.height);
        soundManager.playCollisionSound();
        gameOver = true;
    }

    if (gameOver && score > highScore) {
        highScore = score;
        saveHighScore();
    }
}

void GameLogic::removeOffScreenPipes() {
    auto it = remove_if(pipes.begin(), pipes.end(), [](const Sprite& pipe) {
        return pipe.getPosition().x + pipe.getGlobalBounds().width < 0;
        });
    pipes.erase(it, pipes.end());

    // Optimize vector capacity
    if (pipes.capacity() > pipes.size() * 2 && pipes.capacity() > 10) {
        vector<Sprite>(pipes).swap(pipes);
    }
}

void GameLogic::checkScore() {
    for (size_t i = 0; i < pipes.size(); i += 2) {
        if (i + 1 < pipes.size()) {  // Safety check
            float pipeWidth = pipes[i].getGlobalBounds().width;
            if (pipes[i].getPosition().x + pipeWidth < birdSprite.getPosition().x &&
                pipes[i].getPosition().x + pipeWidth > birdSprite.getPosition().x - 3) {
                score++;
                soundManager.playScoreSound();
            }
        }
    }
}

void GameLogic::resetGame() {
    birdSprite.setPosition(250, 300);
    birdSprite.setRotation(0);
    birdVelocity = 0;
    frames = 0;
    pipes.clear();
    gameOver = false;
    score = 0;
    pipeCollided = false;
    soundManager.checkCollisionSound = true;
}

void GameLogic::saveHighScore() {
    ofstream file("highscore.txt");
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
    else {
        cerr << "Error: Could not save high score" << endl;
    }
}

void GameLogic::loadHighScore() {
    ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    // If file doesn't exist, highScore remains 0 (default)
}

// ============================================================================
// GAME DESIGN CLASS
// ============================================================================
class GameDesign {
private:
    // UI Textures
    Texture background;
    Texture flappyLogo;
    Texture start;
    Texture quit;
    Texture restart;
    Texture menu;
    Texture gameOver;
    Texture scoreBox;

    // Medal textures
    Texture bronze;
    Texture silver;
    Texture gold;
    Texture platinum;
    Texture noMedal;

public:
    // UI Sprites
    Sprite bgSprite;
    Sprite flappyLogoSprite;
    Sprite startSprite;
    Sprite quitSprite;
    Sprite restartSprite;
    Sprite menuSprite;
    Sprite gameOverSprite;
    Sprite scoreBoxSprite;

    // Medal sprites (not used but kept for compatibility)
    Sprite bronzeSprite;
    Sprite silverSprite;
    Sprite goldSprite;
    Sprite platinumSprite;
    Sprite noMedalSprite;

    Font font;
    Medal medal;  // Not used but kept for compatibility

    GameDesign();

    // Drawing methods
    void drawBackground(RenderWindow& window);
    void drawGameMenu(RenderWindow& window);
    void drawGameOver(RenderWindow& window);
    void displayScore(RenderWindow& window, int score);
    void drawCentered(RenderWindow& window, Sprite& sprite, float x, float y);
    void drawCentered(RenderWindow& window, Text& text, float x, float y);
    void drawNotCentered(RenderWindow& window, Text& text, float x, float y);
    void drawMedal(RenderWindow& window, int score);
};

GameDesign::GameDesign() : medal(NO_MEDAL) {
    // Load UI textures
    ResourceManager::loadTexture(background, "Images/background.png");
    bgSprite.setTexture(background);

    ResourceManager::loadTexture(flappyLogo, "Images/Flappy_Logo.png");
    flappyLogoSprite.setTexture(flappyLogo);

    ResourceManager::loadTexture(start, "Images/start.png");
    startSprite.setTexture(start);

    ResourceManager::loadTexture(quit, "Images/quit.png");
    quitSprite.setTexture(quit);

    ResourceManager::loadTexture(restart, "Images/restart.png");
    restartSprite.setTexture(restart);

    ResourceManager::loadTexture(menu, "Images/menu.png");
    menuSprite.setTexture(menu);

    ResourceManager::loadTexture(gameOver, "Images/gameover.png");
    gameOverSprite.setTexture(gameOver);
    gameOverSprite.setScale(1.2f, 1.2f);

    ResourceManager::loadTexture(scoreBox, "Images/score_background.png");
    scoreBoxSprite.setTexture(scoreBox);

    // Load medal textures
    ResourceManager::loadTexture(bronze, "Images/bronze.png");
    ResourceManager::loadTexture(silver, "Images/silver.png");
    ResourceManager::loadTexture(gold, "Images/gold.png");
    ResourceManager::loadTexture(platinum, "Images/platinum.png");
    ResourceManager::loadTexture(noMedal, "Images/no_medal.png");

    // Load font
    ResourceManager::loadFont(font, "font/flappy-font (1).ttf");
}

void GameDesign::drawBackground(RenderWindow& window) {
    window.draw(bgSprite);
}

void GameDesign::drawGameMenu(RenderWindow& window) {
    drawCentered(window, flappyLogoSprite, 400, 200);
    drawCentered(window, startSprite, 400, 400);
    drawCentered(window, quitSprite, 400, 500);
}

void GameDesign::drawGameOver(RenderWindow& window) {
    drawCentered(window, gameOverSprite, 400, 130);
    drawCentered(window, restartSprite, 225, 550);
    drawCentered(window, menuSprite, 575, 550);
    drawCentered(window, scoreBoxSprite, 400, 350);
}

void GameDesign::displayScore(RenderWindow& window, int score) {
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setString(to_string(score));
    scoreText.setCharacterSize(70);
    scoreText.setFillColor(Color::White);
    scoreText.setOutlineColor(Color::Black);
    scoreText.setOutlineThickness(5);
    scoreText.setPosition(20, 10);
    window.draw(scoreText);
}

void GameDesign::drawCentered(RenderWindow& window, Sprite& sprite, float x, float y) {
    FloatRect rect = sprite.getLocalBounds();
    sprite.setOrigin(rect.width / 2.0f, rect.height / 2.0f);
    sprite.setPosition(x, y);
    window.draw(sprite);
}

void GameDesign::drawCentered(RenderWindow& window, Text& text, float x, float y) {
    FloatRect rect = text.getLocalBounds();
    text.setOrigin(rect.width / 2.0f, rect.height / 2.0f);
    text.setPosition(x, y);
    window.draw(text);
}

void GameDesign::drawNotCentered(RenderWindow& window, Text& text, float x, float y) {
    text.setPosition(x, y);
    window.draw(text);
}

void GameDesign::drawMedal(RenderWindow& window, int score) {
    Sprite medalSprite;

    if (score >= 40) {
        medalSprite.setTexture(platinum);
    }
    else if (score >= 30) {
        medalSprite.setTexture(gold);
    }
    else if (score >= 20) {
        medalSprite.setTexture(silver);
    }
    else if (score >= 10) {
        medalSprite.setTexture(bronze);
    }
    else {
        medalSprite.setTexture(noMedal);
    }

    drawCentered(window, medalSprite, 502, 365);
}

// ============================================================================
// EVENT HANDLING CLASS
// ============================================================================
class EventHandling {
private:
    Texture groundTexture;

public:
    Sprite groundSprite1;
    Sprite groundSprite2;

    EventHandling();

    // Event handling methods
    bool isMouseOver(Sprite& sprite, const Vector2i& mousePos);
    void handleMainMenu(RenderWindow& window, GameLogic& gameLogic, GameDesign& gameDesign,
        const Event& event, GameState& gameState);
    void handleGameOverScreen(RenderWindow& window, GameLogic& gameLogic, GameDesign& gameDesign,
        const Event& event, GameState& gameState);

    // Ground methods
    void moveGround(Time dt);
    void drawGround(RenderWindow& window);

    // Game update and render methods
    void updateGameLogic(GameLogic& gameLogic, float deltaTime);
    void renderGameElements(RenderWindow& window, GameLogic& gameLogic,
        GameDesign& gameDesign);
};

EventHandling::EventHandling() {
    ResourceManager::loadTexture(groundTexture, "Images/ground.png");
    groundSprite1.setTexture(groundTexture);
    groundSprite2.setTexture(groundTexture);
    groundSprite1.setPosition(0, 620);
    groundSprite2.setPosition(groundSprite1.getGlobalBounds().width, 620);
}

bool EventHandling::isMouseOver(Sprite& sprite, const Vector2i& mousePos) {
    return sprite.getGlobalBounds().contains(static_cast<float>(mousePos.x),
        static_cast<float>(mousePos.y));
}

void EventHandling::handleMainMenu(RenderWindow& window, GameLogic& gameLogic,
    GameDesign& gameDesign, const Event& event,
    GameState& gameState) {
    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
        Vector2i mousePos = Mouse::getPosition(window);
        if (isMouseOver(gameDesign.startSprite, mousePos)) {
            gameLogic.resetGame();
            gameState = CLICK_TO_PLAY;
        }
        if (isMouseOver(gameDesign.quitSprite, mousePos)) {
            window.close();
        }
    }
}

void EventHandling::handleGameOverScreen(RenderWindow& window, GameLogic& gameLogic,
    GameDesign& gameDesign, const Event& event,
    GameState& gameState) {
    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
        Vector2i mousePos = Mouse::getPosition(window);
        if (isMouseOver(gameDesign.restartSprite, mousePos)) {
            gameLogic.resetGame();
            gameState = CLICK_TO_PLAY;
        }
        if (isMouseOver(gameDesign.menuSprite, mousePos)) {
            gameState = MAIN_MENU;
        }
    }
}

void EventHandling::moveGround(Time dt) {
    const int moveSpeed = 300;
    groundSprite1.move(-moveSpeed * dt.asSeconds(), 0.0f);
    groundSprite2.move(-moveSpeed * dt.asSeconds(), 0.0f);

    // Ensure seamless connection between the ground sprites
    if (groundSprite1.getPosition().x + groundSprite1.getGlobalBounds().width <= 0) {
        groundSprite1.setPosition(groundSprite2.getPosition().x + groundSprite2.getGlobalBounds().width,
            groundSprite1.getPosition().y);
    }
    if (groundSprite2.getPosition().x + groundSprite2.getGlobalBounds().width <= 0) {
        groundSprite2.setPosition(groundSprite1.getPosition().x + groundSprite1.getGlobalBounds().width,
            groundSprite2.getPosition().y);
    }
}

void EventHandling::drawGround(RenderWindow& window) {
    window.draw(groundSprite1);
    window.draw(groundSprite2);
}

void EventHandling::updateGameLogic(GameLogic& gameLogic, float deltaTime) {
    if (!gameLogic.checkPipeCollision()) {
        float velocity = gameLogic.getBirdVelocity();
        velocity += 0.5f;
        gameLogic.setBirdVelocity(velocity);
        gameLogic.birdSprite.move(0, velocity);
        gameLogic.switchBirdTexture();
        gameLogic.updateBirdPosition(deltaTime);

        gameLogic.addPipe();
        gameLogic.updatePipe();
        gameLogic.removeOffScreenPipes();

        moveGround(sf::seconds(deltaTime));
        gameLogic.checkScore();
    }
    else {
        float velocity = gameLogic.getBirdVelocity();
        velocity += 2;
        gameLogic.setBirdVelocity(velocity);
        gameLogic.birdSprite.move(0, velocity);
    }

    gameLogic.checkGameOver();
}

void EventHandling::renderGameElements(RenderWindow& window, GameLogic& gameLogic,
    GameDesign& gameDesign) {
    gameDesign.drawBackground(window);
    gameLogic.drawPipes(window);
    drawGround(window);
    window.draw(gameLogic.birdSprite);
    gameDesign.displayScore(window, gameLogic.score);
}

// ============================================================================
// MAIN GAME FUNCTIONS
// ============================================================================
void handleEvents(RenderWindow& window, GameLogic& gameLogic, GameDesign& gameDesign,
    EventHandling& eventHandling, GameState& gameState, Event& event) {
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }

        switch (gameState) {
        case MAIN_MENU:
            eventHandling.handleMainMenu(window, gameLogic, gameDesign, event, gameState);
            break;

        case CLICK_TO_PLAY:
            if ((event.type == Event::KeyPressed && event.key.code == Keyboard::Space) ||
                (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)) {
                gameState = PLAYING;
                gameLogic.setIsFlapping(true);
            }
            break;

        case PLAYING:
            if (!gameLogic.getPipeCollided() &&
                ((event.type == Event::KeyPressed && event.key.code == Keyboard::Space) ||
                    (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left))) {
                gameLogic.setIsFlapping(true);
            }
            break;

        case GAME_OVER:
            eventHandling.handleGameOverScreen(window, gameLogic, gameDesign, event, gameState);
            break;
        }
    }
}

void renderMainMenu(RenderWindow& window, GameDesign& gameDesign, EventHandling& eventHandling) {
    gameDesign.drawBackground(window);
    gameDesign.drawGameMenu(window);
    eventHandling.drawGround(window);
}

void renderPlaying(RenderWindow& window, GameLogic& gameLogic, GameDesign& gameDesign,
    EventHandling& eventHandling, float deltaTime) {
    eventHandling.updateGameLogic(gameLogic, deltaTime);
    eventHandling.renderGameElements(window, gameLogic, gameDesign);
}

void renderGameOver(RenderWindow& window, GameDesign& gameDesign, EventHandling& eventHandling,
    GameLogic& gameLogic) {
    gameDesign.drawBackground(window);
    gameDesign.drawGameOver(window);
    eventHandling.drawGround(window);

    Text highScoreText;
    highScoreText.setFont(gameDesign.font);
    highScoreText.setString(to_string(gameLogic.highScore));
    highScoreText.setCharacterSize(50);
    highScoreText.setFillColor(Color::White);
    highScoreText.setOutlineColor(Color::Black);
    highScoreText.setOutlineThickness(3);
    gameDesign.drawNotCentered(window, highScoreText, 210, 380);

    Text scoreText;
    scoreText.setFont(gameDesign.font);
    scoreText.setString(to_string(gameLogic.score));
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(Color::White);
    scoreText.setOutlineColor(Color::Black);
    scoreText.setOutlineThickness(3);
    gameDesign.drawNotCentered(window, scoreText, 210, 290);

    gameDesign.drawMedal(window, gameLogic.score);
}

void renderClickToPlay(RenderWindow& window, GameLogic& gameLogic, GameDesign& gameDesign,
    EventHandling& eventHandling, float deltaTime) {
    gameDesign.drawBackground(window);

    // Simulate light bird movement during "CLICK_TO_PLAY"
    float velocity = gameLogic.getBirdVelocity();
    velocity += 0.3f;
    velocity = min(velocity, 5.0f);
    gameLogic.setBirdVelocity(velocity);
    gameLogic.birdSprite.move(0, velocity * deltaTime);

    gameLogic.switchBirdTexture();
    window.draw(gameLogic.birdSprite);

    eventHandling.moveGround(sf::seconds(deltaTime));
    eventHandling.drawGround(window);
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main() {
    RenderWindow window(VideoMode(800, 700), "Flappy Bird");
    window.setFramerateLimit(60);

    srand(static_cast<unsigned>(time(nullptr)));

    GameLogic gameLogic;
    GameDesign gameDesign;
    EventHandling eventHandling;

    GameState gameState = MAIN_MENU;
    Clock clock;

    while (window.isOpen()) {
        Event event;
        Time dt = clock.restart();
        float deltaTime = dt.asSeconds();

        handleEvents(window, gameLogic, gameDesign, eventHandling, gameState, event);

        window.clear();

        if (gameLogic.getIsFlapping()) {
            gameLogic.soundManager.playFlapSound();
        }

        switch (gameState) {
        case MAIN_MENU:
            renderMainMenu(window, gameDesign, eventHandling);
            break;

        case CLICK_TO_PLAY:
            renderClickToPlay(window, gameLogic, gameDesign, eventHandling, deltaTime);
            break;

        case PLAYING:
            renderPlaying(window, gameLogic, gameDesign, eventHandling, deltaTime);
            if (gameLogic.gameOver) {
                gameState = GAME_OVER;
            }
            break;

        case GAME_OVER:
            renderGameOver(window, gameDesign, eventHandling, gameLogic);
            break;
        }

        window.display();
    }

    return 0;
}