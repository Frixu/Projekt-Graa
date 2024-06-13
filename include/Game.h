#ifndef GAME_H
#define GAME_H

#include "API.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Menu.h"
#include "SettingsMenu.h"
#include <vector>
#include <stdexcept>
#include <fstream>

class EXPORT_API Game {
public:
    Game();
    void run();
    void saveGame(const std::string& filename);
    void loadGame(const std::string& filename);
    void setScore(int score);

private:
    void processEvents();
    void update();
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void spawnEnemies();
    void checkCollisions();

    sf::RenderWindow mWindow;
    Player mPlayer;
    std::vector<Enemy> mEnemies;
    std::vector<Bullet> mBullets;
    Menu mMenu;

    SettingsMenu mSettingsMenu;
    bool mIsPlaying;
    bool mInSettings;

    int mScore;
    sf::Text mScoreText;
    sf::Font mFont;
    sf::Music mMusic;

    const int windowWidth = 1000;
    const int windowHeight = 800;
};

#endif