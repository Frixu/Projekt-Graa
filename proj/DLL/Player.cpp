#include "Player.h"
#include <iostream>

sf::Texture Player::loadTexture(const std::string& filepath)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filepath))
    {
        throw std::runtime_error("Error loading texture: " + filepath);
    }
    return texture;
}
Player::Player(int windowWidth, int windowHeight) : mWindowWidth(windowWidth), mWindowHeight(windowHeight), mIsMovingLeft(false), mIsMovingRight(false) {
    try {
        mTexture = loadTexture("images/Player/player2.png");
        std::cout << "Player texture loaded successfully." << std::endl;
        std::cout << "Player texture size: " << mTexture.getSize().x << "x" << mTexture.getSize().y << std::endl;
        mSprite.setTexture(mTexture);
        mSprite.setPosition(400.f, 700.f);
        mVelocity = sf::Vector2f(35.f, 0.f);
        std::cout << "Player position: " << mSprite.getPosition().x << ", " << mSprite.getPosition().y << std::endl;

        mSprite.setColor(sf::Color::Green);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught in Player constructor: " << e.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

Player::~Player()
{
}


void Player::handleInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::Left) {
        mIsMovingLeft = isPressed;
    }
    else if (key == sf::Keyboard::Right) {
        mIsMovingRight = isPressed;
    }
}

void Player::update() {
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingLeft) {
        movement.x -= mVelocity.x;
    }
    if (mIsMovingRight) {
        movement.x += mVelocity.x;
    }
    mSprite.move(movement * 0.01f);
}

void Player::render(sf::RenderWindow& window) const {
    window.draw(mSprite);
}

sf::Vector2f Player::getPosition() const {
    return mSprite.getPosition();
}