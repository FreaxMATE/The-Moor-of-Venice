#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include <limits.h>
#include <unistd.h>
#include <cmath>
#include <vector>
#include <random>

// Function to generate a random integer between min and max (inclusive)
int getRandomInt(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// Function to generate a square wave
sf::Int16 generateSquareWave(double frequency, int sampleRate, int sampleIndex) {
    return (sampleIndex % static_cast<int>(sampleRate / frequency) < static_cast<int>(sampleRate / frequency) / 2) ? 30000 : -30000;
}

// Function to generate noise
sf::Int16 generateNoise() {
    return (std::rand() % 60000) - 30000;
}

// Function to generate a bass drum sound
sf::Int16 generateBassDrum(int sampleRate, int sampleIndex) {
    double frequency = 60.0; // Low frequency for bass drum
    return 30000 * exp(-0.0004 * sampleIndex) * sin(2 * M_PI * frequency * sampleIndex / sampleRate);
}

// Function to generate a snare drum sound
sf::Int16 generateSnareDrum(int sampleRate, int sampleIndex) {
    return generateNoise() * exp(-0.0004 * sampleIndex);
}

// Function to generate a hi-hat sound
sf::Int16 generateHiHat(int sampleRate, int sampleIndex) {
    return generateNoise() * exp(-0.0008 * sampleIndex);
}

std::string getExecutablePath() {
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    return std::string(result, (count > 0) ? count : 0);
}

std::string getAssetsPath() {
    std::string exePath = getExecutablePath();
    std::filesystem::path path(exePath);
    return path.parent_path().parent_path().string() + "/assets/";
}

Game::Game(int boardSize, int timeLimit, bool startWithWhite) : window(sf::VideoMode(800, 800), "Othello"), board(boardSize, boardSize), ai(), isPlayerTurn(true), gameState(GameState::StartMenu), boardSize(8), playerScore(0), aiScore(0), validMoves(0), timeLimit(200), startWithWhite(true) {
    if (!font.loadFromFile(getAssetsPath() + "fonts/Cave-Story.ttf")) {
        std::cerr << "Failed to load font 'Cave-Story.ttf'" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->boardSize = boardSize;
    this->timeLimit = timeLimit;
    this->startWithWhite = startWithWhite;

    playText.setFont(font);
    playText.setString("Play");
    playText.setCharacterSize(24);
    playText.setFillColor(sf::Color::White);
    playText.setPosition(300, 200);

    switchColorText.setFont(font);
    switchColorText.setString("Color: " + std::string(startWithWhite ? "White" : "Black"));
    switchColorText.setCharacterSize(24);
    switchColorText.setFillColor(sf::Color::White);
    switchColorText.setPosition(300, 300);

    boardSizeText.setFont(font);
    boardSizeText.setString("Board Size: " + std::to_string(boardSize) + "x" + std::to_string(boardSize));
    boardSizeText.setCharacterSize(24);
    boardSizeText.setFillColor(sf::Color::White);
    boardSizeText.setPosition(300, 400);

    timeLimitText.setFont(font);
    timeLimitText.setString("Time Limit: " + std::to_string(timeLimit) + "ms");
    timeLimitText.setCharacterSize(24);
    timeLimitText.setFillColor(sf::Color::White);
    timeLimitText.setPosition(300, 500);

    endText.setFont(font);
    endText.setCharacterSize(24);
    endText.setFillColor(sf::Color::White);
    endText.setPosition(300, 300);

    playerScoreText.setFont(font);
    playerScoreText.setCharacterSize(24);
    playerScoreText.setFillColor(sf::Color::Green); // Green color
    playerScoreText.setPosition(10, 10);

    aiScoreText.setFont(font);
    aiScoreText.setCharacterSize(24);
    aiScoreText.setFillColor(sf::Color::Green); // Green color
    aiScoreText.setPosition(10, 40);

    validMovesText.setFont(font);
    validMovesText.setCharacterSize(24);
    validMovesText.setFillColor(sf::Color::Green); // Green color
    validMovesText.setPosition(10, 70);

    replayText.setFont(font);
    replayText.setString("Replay");
    replayText.setCharacterSize(24);
    replayText.setFillColor(sf::Color::White);
    replayText.setPosition(300, 350);

    closeText.setFont(font);
    closeText.setString("Close");
    closeText.setCharacterSize(24);
    closeText.setFillColor(sf::Color::White);
    closeText.setPosition(300, 600);

    // Define three unique melodies
    const std::vector<std::vector<double>> melodies = {
        {523.25, 440.0, 659.25, 493.88, 587.33, 523.25, 783.99, 659.25, 523.25, 440.0, 659.25, 493.88, 587.33, 523.25, 783.99, 659.25},
        {659.25, 783.99, 523.25, 440.0, 587.33, 493.88, 659.25, 523.25, 783.99, 659.25, 523.25, 440.0, 587.33, 493.88, 659.25, 523.25},
        {440.0, 523.25, 659.25, 783.99, 493.88, 587.33, 523.25, 659.25, 440.0, 523.25, 659.25, 783.99, 493.88, 587.33, 523.25, 659.25}
    };

    const std::vector<std::vector<int>> durations = {
        {400, 300, 500, 300, 400, 500, 300, 400, 500, 300, 400, 500, 300, 400, 500, 300},
        {300, 400, 500, 300, 400, 500, 300, 400, 500, 300, 400, 500, 300, 400, 500, 300},
        {500, 300, 400, 500, 300, 400, 500, 300, 400, 500, 300, 400, 500, 300, 400, 500}
    };

    // Choose a random melody
    int melodyIndex = getRandomInt(0, melodies.size() - 1);
    const std::vector<double>& frequencies = melodies[melodyIndex];
    const std::vector<int>& chosenDurations = durations[melodyIndex];

    const int sampleRate = 44100;
    const int amplitude = 30000;
    std::vector<sf::Int16> samples;

    for (size_t i = 0; i < frequencies.size(); ++i) {
        int noteDuration = sampleRate * chosenDurations[i] / 1000;
        for (int j = 0; j < noteDuration; ++j) {
            // Combine keys (sine wave), bass (square wave), and drums (noise)
            sf::Int16 sample = amplitude * sin(2 * M_PI * frequencies[i] * j / sampleRate) / 6; // Keys
            sample += generateSquareWave(frequencies[i] / 2, sampleRate, j) / 6; // Bass
            if (j % (sampleRate / 4) < sampleRate / 100) {
                sample += generateBassDrum(sampleRate, j) / 2; // Bass drum
            }
            if (j % (sampleRate / 2) < sampleRate / 100) {
                sample += generateSnareDrum(sampleRate, j) / 2; // Snare drum
            }
            if (j % (sampleRate / 8) < sampleRate / 100) {
                sample += generateHiHat(sampleRate, j) / 2; // Hi-hat
            }
            samples.push_back(sample);
        }
        // Add a short pause between notes
        for (int j = 0; j < sampleRate / 20; ++j) {
            samples.push_back(0);
        }
    }

    if (!buffer.loadFromSamples(samples.data(), samples.size(), 1, sampleRate)) {
        std::cerr << "Failed to load sound buffer" << std::endl;
        exit(EXIT_FAILURE);
    }

    sound.setBuffer(buffer);
    sound.setLoop(true); // Loop the sound
    sound.play();
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::MouseMoved:
                updateMenuHover(event.mouseMove.x, event.mouseMove.y); // Call the hover update method
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (gameState == GameState::StartMenu) {
                        handleStartMenuClick(event.mouseButton.x, event.mouseButton.y);
                    } else if (gameState == GameState::Playing) {
                        handleMouseClick(event.mouseButton.x, event.mouseButton.y);
                    } else if (gameState == GameState::EndScreen) {
                        handleEndScreenClick(event.mouseButton.x, event.mouseButton.y);
                    }
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
        }
    }
}

void Game::update() {
    if (gameState == GameState::Playing && !isPlayerTurn) {
        ai.makeMove(board, timeLimit); // Use the time limit variable
        isPlayerTurn = true;
        checkGameOver();
    }
    updateScoresAndMoves();
}

void Game::render() {
    window.clear();
    if (gameState == GameState::StartMenu) {
        showStartMenu();
    } else if (gameState == GameState::Playing) {
        board.draw(window);
        board.highlightValidMoves(window, 1);
        window.draw(playerScoreText);
        window.draw(aiScoreText);
        window.draw(validMovesText);
    } else if (gameState == GameState::EndScreen) {
        board.draw(window);
        showEndScreen();
    }
    window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    // Handle keyboard input if needed
}

void Game::handleMouseClick(int x, int y) {
    if (isPlayerTurn) {
        int boardX = x / board.getCellSize();
        int boardY = y / board.getCellSize();
        if (boardX >= 0 && boardX < board.getWidth() && boardY >= 0 && boardY < board.getHeight()) {
            if (board.isValidMove(boardX, boardY, 1)) {
                board.applyMove(boardX, boardY, 1);
                isPlayerTurn = false;
                checkGameOver();
            }
        }
    }
}

void Game::handleStartMenuClick(int x, int y) {
    if (playText.getGlobalBounds().contains(x, y)) {
        isPlayerTurn = startWithWhite;
        gameState = GameState::Playing;
        board.setSize(boardSize, boardSize);
        board.reset();
        if (!startWithWhite) {
            board.setColorInvert(true);
            ai.makeMove(board, timeLimit); // Use the time limit variable
            isPlayerTurn = true;
        }
    } else if (switchColorText.getGlobalBounds().contains(x, y)) {
        startWithWhite = !startWithWhite;
        switchColorText.setString("Color: " + std::string(startWithWhite ? "White" : "Black"));
    } else if (boardSizeText.getGlobalBounds().contains(x, y)) {
        switch (boardSize) {
            case 4: boardSize = 6; break;
            case 6: boardSize = 8; break;
            case 8: boardSize = 10; break;
            case 10: boardSize = 12; break;
            case 12: boardSize = 16; break;
            default: boardSize = 4; break;
        }
        boardSizeText.setString("Board Size: " + std::to_string(boardSize) + "x" + std::to_string(boardSize));
    } else if (timeLimitText.getGlobalBounds().contains(x, y)) {
        switch (timeLimit) {
            case 200: timeLimit = 500; break;
            case 500: timeLimit = 1000; break;
            case 1000: timeLimit = 2000; break;
            case 2000: timeLimit = 5000; break;
            default: timeLimit = 200; break;
        }
        timeLimitText.setString("Time Limit: " + std::to_string(timeLimit) + "ms");
    } else if (closeText.getGlobalBounds().contains(x, y)) {
        window.close();
    }
}

void Game::updateMenuHover(int mouseX, int mouseY) {
    if (playText.getGlobalBounds().contains(mouseX, mouseY)) {
        playText.setFillColor(sf::Color::Red); // Highlight color
    } else {
        playText.setFillColor(sf::Color::White); // Default color
    }

    if (switchColorText.getGlobalBounds().contains(mouseX, mouseY)) {
        switchColorText.setFillColor(sf::Color::Red); // Highlight color
    } else {
        switchColorText.setFillColor(sf::Color::White); // Default color
    }

    if (boardSizeText.getGlobalBounds().contains(mouseX, mouseY)) {
        boardSizeText.setFillColor(sf::Color::Red); // Highlight color
    } else {
        boardSizeText.setFillColor(sf::Color::White); // Default color
    }

    if (timeLimitText.getGlobalBounds().contains(mouseX, mouseY)) {
        timeLimitText.setFillColor(sf::Color::Red); // Highlight color
    } else {
        timeLimitText.setFillColor(sf::Color::White); // Default color
    }

    if (replayText.getGlobalBounds().contains(mouseX, mouseY)) {
        replayText.setFillColor(sf::Color::Red); // Highlight color
    } else {
        replayText.setFillColor(sf::Color::White); // Default color
    }

    if (closeText.getGlobalBounds().contains(mouseX, mouseY)) {
        closeText.setFillColor(sf::Color::Red); // Highlight color
    } else {
        closeText.setFillColor(sf::Color::White); // Default color
    }
}

void Game::showStartMenu() {
    window.draw(playText);
    window.draw(switchColorText);
    window.draw(boardSizeText);
    window.draw(timeLimitText);
    window.draw(closeText);
}

void Game::showEndScreen() {
    // Create a semi-transparent black rectangle
    sf::RectangleShape backgroundRect(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    backgroundRect.setFillColor(sf::Color(0, 0, 0, 150)); // Black with 150 alpha
    backgroundRect.setOrigin(backgroundRect.getSize().x / 2, backgroundRect.getSize().y / 2); // Set origin to the center
    backgroundRect.setPosition(window.getSize().x / 2, window.getSize().y / 2); // Position it in the middle of the window

    window.draw(backgroundRect);
    window.draw(endText);
    window.draw(playerScoreText);
    window.draw(aiScoreText);
    window.draw(replayText);
    window.draw(closeText);
}


void Game::handleEndScreenClick(int x, int y) {
    if (replayText.getGlobalBounds().contains(x, y)) {
        gameState = GameState::StartMenu;
    } else if (closeText.getGlobalBounds().contains(x, y)) {
        window.close();
    }
}

void Game::checkGameOver() {
    bool playerHasMoves = false;
    bool aiHasMoves = false;

    for (int x = 0; x < board.getWidth(); ++x) {
        for (int y = 0; y < board.getHeight(); ++y) {
            if (board.isValidMove(x, y, 1)) {
                playerHasMoves = true;
            }
            if (board.isValidMove(x, y, -1)) {
                aiHasMoves = true;
            }
        }
    }

    if (!playerHasMoves || !aiHasMoves) {
        int playerScore = 0;
        int aiScore = 0;
        for (int x = 0; x < board.getWidth(); ++x) {
            for (int y = 0; y < board.getHeight(); ++y) {
                if (board.getCell(x, y) == 1) {
                    playerScore++;
                } else if (board.getCell(x, y) == -1) {
                    aiScore++;
                }
            }
        }

        if (playerScore > aiScore) {
            endText.setString("You win!");
        } else if (aiScore > playerScore) {
            endText.setString("AI wins!");
        } else {
            endText.setString("It's a draw!");
        }

        // Print final scores to stdout
        std::cout << "Final Scores:\n";
        std::cout << "Player Score: " << playerScore << "\n";
        std::cout << "AI Score: " << aiScore << "\n";

        // Update score texts for the end screen
        playerScoreText.setString("Player Score: " + std::to_string(playerScore));
        aiScoreText.setString("AI Score: " + std::to_string(aiScore));

        gameState = GameState::EndScreen;
    }
}

void Game::updateScoresAndMoves() {
    int newPlayerScore = 0;
    int newAiScore = 0;
    int newValidMoves = 0;

    for (int x = 0; x < board.getWidth(); ++x) {
        for (int y = 0; y < board.getHeight(); ++y) {
            if (board.getCell(x, y) == 1) {
                newPlayerScore++;
            } else if (board.getCell(x, y) == -1) {
                newAiScore++;
            }
            if (board.isValidMove(x, y, 1)) {
                newValidMoves++;
            }
        }
    }

    if (newPlayerScore != playerScore || newAiScore != aiScore || newValidMoves != validMoves) {
        playerScore = newPlayerScore;
        aiScore = newAiScore;
        validMoves = newValidMoves;

        playerScoreText.setString("Player Score: " + std::to_string(playerScore));
        aiScoreText.setString("AI Score: " + std::to_string(aiScore));
        validMovesText.setString("Valid Moves: " + std::to_string(validMoves));

        // Print current scores and valid moves to stdout
        std::cout << "Current Scores:\n";
        std::cout << "Player Score: " << playerScore << "\n";
        std::cout << "AI Score: " << aiScore << "\n";
        std::cout << "Valid Moves: " << validMoves << "\n";
    }
}
