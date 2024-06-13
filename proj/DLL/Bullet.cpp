#include "Bullet.h"
#include <iostream>

Bullet::Bullet(sf::Vector2f position) {
    if (!mTexture.loadFromFile("images/Bullet/bullet.png")) {
        std::cerr << "Error loading bullet texture!" << std::endl;
    }

    mSprite.setColor(sf::Color::Yellow);
    mSprite.setTexture(mTexture);
    mSprite.setPosition(position);
    mVelocity = sf::Vector2f(0.f, -85.0f);
}

void Bullet::update() {
    mSprite.move(mVelocity * 0.01f);
}

void Bullet::render(sf::RenderWindow& window) const {
    window.draw(mSprite);
}

sf::FloatRect Bullet::getBounds() const {
    return mSprite.getGlobalBounds();
}