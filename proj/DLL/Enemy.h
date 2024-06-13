#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "API.h"
#include <SFML/Graphics.hpp>

class EXPORT_API Enemy {
public:
    Enemy();
    void update();
    void render(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    static std::vector<sf::Vector2f> existingPositions;

private:
    sf::Sprite mSprite;
    sf::Texture mTexture;
    sf::Vector2f mVelocity;
    static const float minDistance;
};

#endif