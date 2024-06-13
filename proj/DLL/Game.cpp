#include "Game.h"
#include <iostream>

Game::Game() : mWindow(sf::VideoMode(1000, 800), "My Game"),mIsPlaying(false), mInSettings(false),mMusic(), mMenu(mMusic), mSettingsMenu(mMusic), mScore(0), mPlayer(windowWidth, windowHeight){
    try {
        if (!mFont.loadFromFile("font/font.ttf")) {
            throw std::runtime_error("font loading error");
        }
        mPlayer = Player(windowWidth, windowHeight);
        mScoreText.setFont(mFont);
        mScoreText.setCharacterSize(24);
        mScoreText.setFillColor(sf::Color::White);
        mScoreText.setPosition(450.f, 0.f);
        mScoreText.setString("SCORE: 0");
        mScore = 0;

        if (!mMusic.openFromFile("music/muzyka1.ogg")) {
            throw std::runtime_error("Music loading error");
        }

        mMusic.setLoop(true); // Ustaw zapętlanie
        mMusic.setVolume(50.f);
        mMusic.play(); // Odtwórz muzykę
        std::cout << "Music loaded and playing." << std::endl;

    }
    catch (const std :: exception & e) {
            std::cerr << "Exception caught in Game constructor: " << e.what() << std::endl;
            std::exit(EXIT_FAILURE);
        }
}


void Game::run(){
    try {
        sf::Clock clock;
        while (mWindow.isOpen()) {
            processEvents();
            sf::Time deltaTime = clock.restart();
            update();
            render();
        }
    }catch(const std::exception& e){
        std::cerr << "Exception cayght in run method: " << e.what() << std::endl;
    }
}

void Game::saveGame(const std::string& filename) {
    std::string filepath = filename;
    std::ofstream outFile(filepath, std::ios::binary);
    if (!outFile) {
        throw std::runtime_error("Error opening file for saving!");
    }

    outFile.write(reinterpret_cast<const char*>(&mScore), sizeof(mScore));

    outFile.close();
}

void Game::loadGame(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        throw std::runtime_error("Error opening file for loading!");
    }

    inFile.read(reinterpret_cast<char*>(&mScore), sizeof(mScore));

    
    mScoreText.setString("Score: " + std::to_string(mScore));

    inFile.close();

    mIsPlaying = true;
}


void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            mWindow.close();
        if (event.type == sf::Event::KeyPressed) {
            if (mIsPlaying) {
                handlePlayerInput(event.key.code, true);
                if (event.key.code == sf::Keyboard::S) {
                    try {
                        saveGame("savegame.dat");
                        std::cout << "Game saved successfully!" << std::endl;
                    }
                    catch (const std::exception& e) {
                        std::cerr << "Error saving game: " << e.what() << std::endl;
                    }
                }
            }
            else {
                mMenu.handleInput(event.key.code);
                if (event.key.code == sf::Keyboard::Enter) {
                    if (mMenu.getSelectedItem() == 0) {
                        mIsPlaying = true;
                    }
                    else if (mMenu.getSelectedItem() == 2) {
                        // Load Game
                        try {
                            loadGame("savegame.dat");
                            std::cout << "Game loaded successfully!" << std::endl;
                        }
                        catch (const std::exception& e) {
                            std::cerr << "Error loading game: " << e.what() << std::endl;
                        }
                    }
                    else if (mMenu.getSelectedItem() == 1) {
                        mInSettings = true;
                    }
                    else if (mMenu.getSelectedItem() == 3) {
                        mWindow.close();
                    }
                }
            }
        }
        if (event.type == sf::Event::KeyReleased && mIsPlaying) {
            handlePlayerInput(event.key.code, false);
        }
    }
}


void Game::update() {
    if (mIsPlaying) {
        mPlayer.update();
        for (auto& enemy : mEnemies) {
            enemy.update();
        }
        for (auto& bullet : mBullets) {
            bullet.update();
        }
        spawnEnemies();
        checkCollisions();

        mScoreText.setString("SCORE: " + std::to_string(mScore));
    }
}

void Game::render() {
    mWindow.clear();
    if (mIsPlaying) {
        mPlayer.render(mWindow);
        for (const auto& enemy : mEnemies) {
            enemy.render(mWindow);
        }
        for (const auto& bullet : mBullets) {
            bullet.render(mWindow);
        }
        mWindow.draw(mScoreText);
    } else {
        mMenu.render(mWindow);
    }
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::Left || key == sf::Keyboard::Right) {
        mPlayer.handleInput(key, isPressed);
    } else if (key == sf::Keyboard::Space && isPressed) {
        mBullets.push_back(Bullet(mPlayer.getPosition()));
    }
}

void Game::spawnEnemies() {
    if (mEnemies.size() < 5) {
        mEnemies.push_back(Enemy());
    }
}

void Game::checkCollisions() {
    for (auto bulletIt = mBullets.begin(); bulletIt != mBullets.end();) {
        bool bulletRemoved = false;
        for (auto enemyIt = mEnemies.begin(); enemyIt != mEnemies.end() && !bulletRemoved;) {
            if (bulletIt->getBounds().intersects(enemyIt->getBounds())) {
                enemyIt = mEnemies.erase(enemyIt);
                bulletIt = mBullets.erase(bulletIt);
                bulletRemoved = true;
                mScore++;
            } else {
                ++enemyIt;
            }
        }
        if (!bulletRemoved) {
            ++bulletIt;
        }
    }
}

void Game::setScore(int score) {
    mScore = score;
    mScoreText.setString("Score: " + std::to_string(mScore));
}