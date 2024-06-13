#ifndef PLAYER_H
#define PLAYER_H

#include "API.h"
#include <SFML/Graphics.hpp>

class EXPORT_API Player {
public:
    Player(int windowWidth, int windowHeight);
    ~Player();

    void handleInput(sf::Keyboard::Key key, bool isPressed);
    void update();
    void render(sf::RenderWindow& window) const;
    sf::Vector2f getPosition() const;

private:
    sf::Sprite mSprite;
    sf::Texture mTexture;
    sf::Vector2f mVelocity;
    bool mIsMovingLeft;
    bool mIsMovingRight;
    int mWindowWidth;
    int mWindowHeight;

    sf::Texture loadTexture(const std::string& filepath);
};

#endif