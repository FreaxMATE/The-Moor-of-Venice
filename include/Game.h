#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Board.h"
#include "AI.h"

class Game {
public:
    Game(int boardSize, int timeLimit, bool startWithWhite);
    void run();

private:
    void processEvents();
    void update();
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void handleMouseClick(int x, int y);
    void showStartMenu();
    void showEndScreen();
    void updateMenuHover(int mouseX, int mouseY);
    void handleStartMenuClick(int x, int y);
    void handleEndScreenClick(int x, int y);
    void checkGameOver();
    void updateScoresAndMoves();

    sf::RenderWindow window;
    sf::Font font;
    sf::Text playText;
    sf::Text switchColorText;
    sf::Text boardSizeText;
    sf::Text timeLimitText;
    sf::Text endText;
    sf::Text playerScoreText;
    sf::Text aiScoreText;
    sf::Text validMovesText;
    sf::Text replayText;
    sf::Text closeText;
    sf::SoundBuffer buffer;
    sf::Sound sound;

    Board board;
    AI ai;
    bool isPlayerTurn;
    enum class GameState { StartMenu, Playing, EndScreen } gameState;
    int boardSize;
    int playerScore;
    int aiScore;
    int validMoves;
    int timeLimit;
    bool startWithWhite;
};

#endif // GAME_H