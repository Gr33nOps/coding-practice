#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;

// =======================================
// GAME CONSTANTS
// =======================================

const int width = 800;
const int height = 600;
const int blockSize = 20;

// Top 40 pixels are used for the UI
const int playAreaTop = 40;
const int playAreaBottom = height;

const int numBlocksX = width / blockSize;
const int numBlocksY = (playAreaBottom - playAreaTop) / blockSize;

const int MAX_CELLS = numBlocksX * numBlocksY;
const int MAX_SCORE = (MAX_CELLS - 1) * 10;

const string HIGHSCORE_FILE = "highscore.txt";

// =======================================
// GAME STATE
// =======================================

enum class GameState
{
    MENU,
    PLAYING,
    PAUSE,
    GAME_OVER,
    WIN,
    EXIT
};

// =======================================
// SNAKE CLASS
// =======================================

class SNAKE
{
private:
    RectangleShape body[MAX_CELLS];

    int length;
    int blockSize;
    Vector2f direction;
    int score;

    SoundBuffer moveBuffer;
    Sound moveSound;

public:

    SNAKE()
        : length(1),
        blockSize(::blockSize),
        direction(1, 0),
        score(0)
    {
        body[0].setSize(
            Vector2f(blockSize, blockSize)
        );

        body[0].setFillColor(Color::Yellow);

        body[0].setPosition(
            (numBlocksX / 2) * blockSize,
            playAreaTop + ((numBlocksY / 2) * blockSize)
        );

        if (!moveBuffer.loadFromFile("AUDIO/music_move.wav"))
        {
            cout << "Failed to load move sound" << endl;
        }

        moveSound.setBuffer(moveBuffer);
    }

    // =======================================
    // MOVE
    // =======================================

    void move()
    {
        for (int i = length - 1; i > 0; --i)
        {
            body[i].setPosition(
                body[i - 1].getPosition()
            );
        }

        body[0].move(
            direction.x * blockSize,
            direction.y * blockSize
        );
    }

    // =======================================
    // GROW
    // =======================================

    void grow()
    {
        if (length >= MAX_CELLS)
            return;

        body[length].setSize(
            Vector2f(blockSize, blockSize)
        );

        body[length].setFillColor(Color::Green);

        body[length].setPosition(
            body[length - 1].getPosition()
        );

        length++;
    }

    // =======================================
    // CHANGE DIRECTION
    // =======================================

    void changeDirection(Vector2f newDirection)
    {
        // Don't allow the snake to reverse
        if (newDirection.x == -direction.x &&
            newDirection.y == -direction.y)
        {
            return;
        }

        // Don't change to the same direction
        if (newDirection == direction)
        {
            return;
        }

        direction = newDirection;

        moveSound.play();
    }

    // =======================================
    // DRAW
    // =======================================

    void draw(RenderWindow& window)
    {
        for (int i = 0; i < length; i++)
        {
            window.draw(body[i]);
        }
    }

    // =======================================
    // GET HEAD POSITION
    // =======================================

    Vector2f getHeadPosition()
    {
        return body[0].getPosition();
    }

    // =======================================
    // WINDOW COLLISION
    // =======================================

    bool checkCollisionWithWindow()
    {
        Vector2f headPosition =
            body[0].getPosition();

        return
            headPosition.x < 0 ||
            headPosition.x >= width ||
            headPosition.y < playAreaTop ||
            headPosition.y >= playAreaBottom;
    }

    // =======================================
    // SELF COLLISION
    // =======================================

    bool checkCollisionWithItself()
    {
        Vector2f headPosition =
            body[0].getPosition();

        for (int i = 1; i < length; ++i)
        {
            if (headPosition == body[i].getPosition())
            {
                return true;
            }
        }

        return false;
    }

    // =======================================
    // CHECK POSITION
    // =======================================

    bool isPositionOccupied(Vector2f position)
    {
        for (int i = 0; i < length; ++i)
        {
            if (body[i].getPosition() == position)
            {
                return true;
            }
        }

        return false;
    }

    // =======================================
    // SCORE
    // =======================================

    int getScore()
    {
        return score;
    }

    void increaseScore()
    {
        score += 10;
    }

    // =======================================
    // RESET
    // =======================================

    void reset()
    {
        length = 1;

        direction = Vector2f(1, 0);

        score = 0;

        body[0].setPosition(
            (numBlocksX / 2) * blockSize,
            playAreaTop + ((numBlocksY / 2) * blockSize)
        );
    }

    // =======================================
    // UPDATE
    // =======================================

    void update(GameState& gameState)
    {
        if (gameState != GameState::PLAYING)
            return;

        move();

        if (checkCollisionWithWindow() ||
            checkCollisionWithItself())
        {
            gameState = GameState::GAME_OVER;
        }
    }
};

// =======================================
// FOOD CLASS
// =======================================

class FOOD
{
private:
    RectangleShape food;
    SNAKE& snake;
    int blockSize;

public:

    FOOD(SNAKE& snake, int blockSize)
        : snake(snake),
        blockSize(blockSize)
    {
        food.setSize(
            Vector2f(blockSize, blockSize)
        );

        food.setFillColor(Color::Red);

        spawn();
    }

    // =======================================
    // SPAWN FOOD
    // =======================================

    bool spawn()
    {
        // Try random positions first
        for (int attempt = 0; attempt < 1000; attempt++)
        {
            int x = rand() % numBlocksX;
            int y = rand() % numBlocksY;

            float posX = x * blockSize;
            float posY =
                playAreaTop + (y * blockSize);

            Vector2f position(posX, posY);

            if (!snake.isPositionOccupied(position))
            {
                food.setPosition(position);
                return true;
            }
        }

        // If random attempts fail,
        // search the entire board
        for (int y = 0; y < numBlocksY; y++)
        {
            for (int x = 0; x < numBlocksX; x++)
            {
                Vector2f position(
                    x * blockSize,
                    playAreaTop + (y * blockSize)
                );

                if (!snake.isPositionOccupied(position))
                {
                    food.setPosition(position);
                    return true;
                }
            }
        }

        return false;
    }

    // =======================================
    // DRAW
    // =======================================

    void draw(RenderWindow& window)
    {
        window.draw(food);
    }

    // =======================================
    // GET POSITION
    // =======================================

    Vector2f getPosition()
    {
        return food.getPosition();
    }
};

// =======================================
// GAME CLASS
// =======================================

class GAME
{
private:

    RenderWindow window;

    SNAKE snake;
    FOOD food;

    GameState gameState;

    Clock clock;

    float timer;
    float delay;

    Font font;

    Text startGameText;
    Text exitGameText;

    int highscore;

    SoundBuffer foodBuffer;
    SoundBuffer gameOverBuffer;

    Sound foodSound;
    Sound gameOverSound;

    bool gameOverSoundPlayed;

    // =======================================
    // MENU EVENTS
    // =======================================

    void handleMenuEvents(Event& event)
    {
        if (event.type != Event::KeyPressed)
            return;

        if (event.key.code == Keyboard::Enter)
        {
            snake.reset();
            food.spawn();

            timer = 0.0f;
            gameOverSoundPlayed = false;

            gameState = GameState::PLAYING;
        }
        else if (event.key.code == Keyboard::Q)
        {
            gameState = GameState::EXIT;
            window.close();
        }
    }

    // =======================================
    // PLAYING EVENTS
    // =======================================

    void handlePlayingEvents(Event& event)
    {
        if (event.type != Event::KeyPressed)
            return;

        if (event.key.code == Keyboard::Escape)
        {
            gameState = GameState::PAUSE;
            return;
        }

        // Use the actual keyboard event

        if (event.key.code == Keyboard::Up)
        {
            snake.changeDirection(
                Vector2f(0, -1)
            );
        }
        else if (event.key.code == Keyboard::Down)
        {
            snake.changeDirection(
                Vector2f(0, 1)
            );
        }
        else if (event.key.code == Keyboard::Left)
        {
            snake.changeDirection(
                Vector2f(-1, 0)
            );
        }
        else if (event.key.code == Keyboard::Right)
        {
            snake.changeDirection(
                Vector2f(1, 0)
            );
        }
    }

    // =======================================
    // PAUSE EVENTS
    // =======================================

    void handlePauseEvents(Event& event)
    {
        if (event.type != Event::KeyPressed)
            return;

        if (event.key.code == Keyboard::Escape)
        {
            gameState = GameState::PLAYING;

            clock.restart();
            timer = 0.0f;
        }
        else if (event.key.code == Keyboard::Space)
        {
            snake.reset();
            food.spawn();

            timer = 0.0f;
            gameOverSoundPlayed = false;

            gameState = GameState::MENU;
        }
    }

    // =======================================
    // GAME OVER EVENTS
    // =======================================

    void handleGameOverEvents(Event& event)
    {
        if (event.type != Event::KeyPressed)
            return;

        if (event.key.code == Keyboard::Space)
        {
            snake.reset();
            food.spawn();

            timer = 0.0f;
            gameOverSoundPlayed = false;

            gameState = GameState::MENU;
        }
        else if (event.key.code == Keyboard::Enter)
        {
            snake.reset();
            food.spawn();

            timer = 0.0f;
            gameOverSoundPlayed = false;

            gameState = GameState::PLAYING;
        }
    }

    // =======================================
    // WIN EVENTS
    // =======================================

    void handleGameWinEvents(Event& event)
    {
        if (event.type != Event::KeyPressed)
            return;

        if (event.key.code == Keyboard::Space)
        {
            snake.reset();
            food.spawn();

            timer = 0.0f;
            gameOverSoundPlayed = false;

            gameState = GameState::MENU;
        }
        else if (event.key.code == Keyboard::Enter)
        {
            snake.reset();
            food.spawn();

            timer = 0.0f;
            gameOverSoundPlayed = false;

            gameState = GameState::PLAYING;
        }
    }

    // =======================================
    // EVENT HANDLER
    // =======================================

    void handleEvent()
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                return;
            }

            switch (gameState)
            {
            case GameState::MENU:
                handleMenuEvents(event);
                break;

            case GameState::PLAYING:
                handlePlayingEvents(event);
                break;

            case GameState::PAUSE:
                handlePauseEvents(event);
                break;

            case GameState::GAME_OVER:
                handleGameOverEvents(event);
                break;

            case GameState::WIN:
                handleGameWinEvents(event);
                break;

            case GameState::EXIT:
                break;
            }
        }
    }

    // =======================================
    // BORDER
    // =======================================

    RectangleShape createBorder()
    {
        RectangleShape borderLine;

        borderLine.setSize(
            Vector2f(
                width,
                playAreaBottom - playAreaTop
            )
        );

        borderLine.setFillColor(
            Color::Transparent
        );

        borderLine.setOutlineThickness(2);

        borderLine.setOutlineColor(
            Color::White
        );

        borderLine.setPosition(
            0,
            playAreaTop
        );

        return borderLine;
    }

    // =======================================
    // TEXT HELPER
    // =======================================

    Text textInGame(
        string content,
        int size,
        Color color,
        Vector2f position)
    {
        Text text;

        text.setFont(font);
        text.setString(content);
        text.setCharacterSize(size);
        text.setFillColor(color);
        text.setPosition(position);

        return text;
    }

    // =======================================
    // UPDATE
    // =======================================

    void update()
    {
        if (gameState != GameState::PLAYING)
        {
            clock.restart();
            return;
        }

        float deltaTime =
            clock.restart().asSeconds();

        timer += deltaTime;

        if (timer < delay)
            return;

        timer = 0.0f;

        // Move snake
        snake.update(gameState);

        // Snake died
        if (gameState == GameState::GAME_OVER)
        {
            updateHighscore();

            if (!gameOverSoundPlayed)
            {
                gameOverSound.play();
                gameOverSoundPlayed = true;
            }

            return;
        }

        // Check food
        checkCollisionWithFood();

        // Win
        if (snake.getScore() >= MAX_SCORE)
        {
            updateHighscore();
            gameState = GameState::WIN;
        }
    }

    // =======================================
    // FOOD COLLISION
    // =======================================

    void checkCollisionWithFood()
    {
        if (snake.getHeadPosition() !=
            food.getPosition())
        {
            return;
        }

        snake.grow();
        snake.increaseScore();

        foodSound.play();

        // Spawn new food
        if (!food.spawn())
        {
            updateHighscore();
            gameState = GameState::WIN;
        }
    }

    // =======================================
    // LOAD HIGH SCORE
    // =======================================

    void loadHighscore()
    {
        ifstream infile(HIGHSCORE_FILE);

        if (infile.is_open())
        {
            infile >> highscore;
            infile.close();
        }
        else
        {
            highscore = 0;
        }
    }

    // =======================================
    // SAVE HIGH SCORE
    // =======================================

    void saveHighscore()
    {
        ofstream outfile(HIGHSCORE_FILE);

        if (outfile.is_open())
        {
            outfile << highscore;
            outfile.close();
        }
    }

    // =======================================
    // UPDATE HIGH SCORE
    // =======================================

    void updateHighscore()
    {
        int currentScore =
            snake.getScore();

        if (currentScore > highscore)
        {
            highscore = currentScore;
            saveHighscore();
        }
    }

    // =======================================
    // MENU RENDER
    // =======================================

    void renderMenu()
    {
        Text snakeGameText =
            textInGame(
                "SNAKE GAME",
                120,
                Color::White,
                Vector2f(
                    width / 2.0f,
                    height / 3.5f
                )
            );

        FloatRect titleRect =
            snakeGameText.getLocalBounds();

        snakeGameText.setOrigin(
            titleRect.width / 2.0f,
            titleRect.height / 2.0f
        );

        startGameText =
            textInGame(
                "[Enter] START",
                50,
                Color::Green,
                Vector2f(
                    width / 2.0f,
                    height / 1.5f
                )
            );

        FloatRect startRect =
            startGameText.getLocalBounds();

        startGameText.setOrigin(
            startRect.width / 2.0f,
            startRect.height / 2.0f
        );

        exitGameText =
            textInGame(
                "[Q] Quit",
                50,
                Color::Red,
                Vector2f(
                    width / 2.0f,
                    height / 1.25f
                )
            );

        FloatRect exitRect =
            exitGameText.getLocalBounds();

        exitGameText.setOrigin(
            exitRect.width / 2.0f,
            exitRect.height / 2.0f
        );

        window.draw(snakeGameText);
        window.draw(startGameText);
        window.draw(exitGameText);
    }

    // =======================================
    // GAME RENDER
    // =======================================

    void renderGame()
    {
        snake.draw(window);
        food.draw(window);

        RectangleShape borderLine =
            createBorder();

        window.draw(borderLine);

        Text scoreText =
            textInGame(
                "SCORE: " +
                to_string(snake.getScore()),
                30,
                Color::White,
                Vector2f(20, 5)
            );

        Text pauseText =
            textInGame(
                "[ESC] PAUSE",
                30,
                Color::White,
                Vector2f(616, 5)
            );

        window.draw(scoreText);
        window.draw(pauseText);
    }

    // =======================================
    // PAUSE RENDER
    // =======================================

    void renderPause()
    {
        renderGame();

        Text pauseText =
            textInGame(
                "PAUSED",
                100,
                Color::Yellow,
                Vector2f(
                    width / 2.0f,
                    height / 2.0f - 80
                )
            );

        FloatRect pauseRect =
            pauseText.getLocalBounds();

        pauseText.setOrigin(
            pauseRect.width / 2.0f,
            pauseRect.height / 2.0f
        );

        Text restartText =
            textInGame(
                "[ESC] Resume\n[Space] Menu",
                40,
                Color::White,
                Vector2f(
                    width / 2.0f,
                    height / 2.0f + 60
                )
            );

        FloatRect restartRect =
            restartText.getLocalBounds();

        restartText.setOrigin(
            restartRect.width / 2.0f,
            restartRect.height / 2.0f
        );

        window.draw(pauseText);
        window.draw(restartText);
    }

    // =======================================
    // WIN RENDER
    // =======================================

    void renderWin()
    {
        RectangleShape scoreBox(
            Vector2f(400, 150)
        );

        scoreBox.setOutlineThickness(2);
        scoreBox.setOutlineColor(Color::White);
        scoreBox.setFillColor(Color::Black);

        scoreBox.setOrigin(200, 75);
        scoreBox.setPosition(400, 300);

        Text winText =
            textInGame(
                "YOU WIN!",
                120,
                Color::Green,
                Vector2f(
                    width / 2.0f,
                    height / 6.0f
                )
            );

        FloatRect winRect =
            winText.getLocalBounds();

        winText.setOrigin(
            winRect.width / 2.0f,
            winRect.height / 2.0f
        );

        Text restartText =
            textInGame(
                "[Enter] Play Again\n[Space] Menu",
                40,
                Color::White,
                Vector2f(
                    width / 2.0f,
                    height / 1.5f + 60
                )
            );

        FloatRect restartRect =
            restartText.getLocalBounds();

        restartText.setOrigin(
            restartRect.width / 2.0f,
            restartRect.height / 2.0f
        );

        Text scoreText =
            textInGame(
                "Score: " +
                to_string(snake.getScore()),
                50,
                Color::Green,
                Vector2f(210, 230)
            );

        Text highScoreText =
            textInGame(
                "Best: " +
                to_string(highscore),
                50,
                Color::Yellow,
                Vector2f(210, 300)
            );

        window.draw(winText);
        window.draw(restartText);
        window.draw(scoreBox);
        window.draw(scoreText);
        window.draw(highScoreText);
    }

    // =======================================
    // GAME OVER RENDER
    // =======================================

    void renderGameOver()
    {
        RectangleShape scoreBox(
            Vector2f(400, 150)
        );

        scoreBox.setOutlineThickness(2);
        scoreBox.setOutlineColor(Color::White);
        scoreBox.setFillColor(Color::Black);

        scoreBox.setOrigin(200, 75);
        scoreBox.setPosition(400, 300);

        Text gameOverText =
            textInGame(
                "GAME OVER!",
                120,
                Color::Red,
                Vector2f(
                    width / 2.0f,
                    height / 6.0f
                )
            );

        FloatRect gameOverRect =
            gameOverText.getLocalBounds();

        gameOverText.setOrigin(
            gameOverRect.width / 2.0f,
            gameOverRect.height / 2.0f
        );

        Text restartText =
            textInGame(
                "[Enter] Play Again\n[Space] Menu",
                40,
                Color::White,
                Vector2f(
                    width / 2.0f,
                    height / 1.5f + 60
                )
            );

        FloatRect restartRect =
            restartText.getLocalBounds();

        restartText.setOrigin(
            restartRect.width / 2.0f,
            restartRect.height / 2.0f
        );

        Text scoreText =
            textInGame(
                "Score: " +
                to_string(snake.getScore()),
                50,
                Color::Green,
                Vector2f(210, 230)
            );

        Text highScoreText =
            textInGame(
                "Best: " +
                to_string(highscore),
                50,
                Color::Yellow,
                Vector2f(210, 300)
            );

        window.draw(gameOverText);
        window.draw(restartText);
        window.draw(scoreBox);
        window.draw(scoreText);
        window.draw(highScoreText);
    }

    // =======================================
    // RENDER
    // =======================================

    void render()
    {
        window.clear();

        switch (gameState)
        {
        case GameState::MENU:
            renderMenu();
            break;

        case GameState::PLAYING:
            renderGame();
            break;

        case GameState::PAUSE:
            renderPause();
            break;

        case GameState::WIN:
            renderWin();
            break;

        case GameState::GAME_OVER:
            renderGameOver();
            break;

        case GameState::EXIT:
            break;
        }

        window.display();
    }

public:

    // =======================================
    // CONSTRUCTOR
    // =======================================

    GAME()
        : window(
            VideoMode(width, height),
            "Snake Game"
        ),
        snake(),
        food(snake, blockSize),
        gameState(GameState::MENU),
        timer(0.0f),
        delay(0.1f),
        highscore(0),
        gameOverSoundPlayed(false)
    {
        if (!font.loadFromFile("Font/Square.ttf"))
        {
            cout << "Failed to load font" << endl;
        }

        if (!foodBuffer.loadFromFile(
            "AUDIO/music_food.wav"))
        {
            cout << "Failed to load food sound"
                << endl;
        }

        foodSound.setBuffer(foodBuffer);

        if (!gameOverBuffer.loadFromFile(
            "AUDIO/music_gameover.wav"))
        {
            cout << "Failed to load game over sound"
                << endl;
        }

        gameOverSound.setBuffer(gameOverBuffer);

        loadHighscore();
    }

    // =======================================
    // RUN GAME
    // =======================================

    void run()
    {
        while (window.isOpen())
        {
            handleEvent();
            update();
            render();
        }
    }
};

// =======================================
// MAIN
// =======================================

int main()
{
    srand(
        static_cast<unsigned int>(
            time(nullptr)
            )
    );

    GAME game;

    game.run();

    return 0;
}