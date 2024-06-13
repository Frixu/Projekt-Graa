#include "Enemy.h"
#include <iostream>
#include <cmath>


Enemy::Enemy() {
    
    if (!mTexture.loadFromFile("images/Enemy/enemy1.png")) {
        std::cerr << "Error loading enemy texture!" << std::endl;
    }
    else {
        std::cout << "Enemy texture loaded successfully." << std::endl;
    }

    mSprite.setColor(sf::Color::Red);
    mSprite.setTexture(mTexture);
    mSprite.setPosition(rand() % 1000, 80.f);
    mVelocity = sf::Vector2f(0.f, 0.f);
}

void Enemy::update() {
    mSprite.move(mVelocity * 0.01f);
}

void Enemy::render(sf::RenderWindow& window) const {
    window.draw(mSprite);
}

sf::FloatRect Enemy::getBounds() const {
    return mSprite.getGlobalBounds();
}