#pragma once
#ifndef BULLET_H
#define BULLET_H

#include "API.h"
#include <SFML/Graphics.hpp>

class EXPORT_API Bullet {
public:
    Bullet(sf::Vector2f position);
    void update();
    void render(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;

private:
    sf::Sprite mSprite;
    sf::Texture mTexture;
    sf::Vector2f mVelocity;
};

#endif