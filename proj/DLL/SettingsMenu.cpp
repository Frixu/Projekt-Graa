#include "SettingsMenu.h"
#include <iostream>

SettingsMenu::SettingsMenu(sf::Music& music)
    : mSelectedItemIndex(0), mMusicOn(true), mMusicVolume(50.0f), mMusic(music) {
    if (!mFont.loadFromFile("font/font.ttf")) {
    }

    mSettingsItems.resize(3);

    mSettingsItems[0].setFont(mFont);
    mSettingsItems[0].setCharacterSize(24);
    mSettingsItems[0].setFillColor(sf::Color::Red);
    mSettingsItems[0].setPosition(300.f, 200.f);

    mSettingsItems[1].setFont(mFont);
    mSettingsItems[1].setCharacterSize(24);
    mSettingsItems[1].setFillColor(sf::Color::White);
    mSettingsItems[1].setPosition(300.f, 260.f);

    mSettingsItems[2].setFont(mFont);
    mSettingsItems[2].setCharacterSize(24);
    mSettingsItems[2].setFillColor(sf::Color::White);
    mSettingsItems[2].setPosition(300.f, 320.f);

    updateMenuText();
}

void SettingsMenu::render(sf::RenderWindow& window) const {
    for (const auto& item : mSettingsItems) {
        window.draw(item);
    }
}

void SettingsMenu::handleInput(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::Up) {
        moveUp();
    }
    else if (key == sf::Keyboard::Down) {
        moveDown();
    }
    else if (key == sf::Keyboard::Enter) {
        if (mSelectedItemIndex == 0) {
            toggleMusic();
        }
    }
    else if (key == sf::Keyboard::Left) {
        adjustVolume(false);
    }
    else if (key == sf::Keyboard::Right) {
        adjustVolume(true);
    }
}

bool SettingsMenu::isMusicOn() const {
    return mMusicOn;
}

float SettingsMenu::getMusicVolume() const {
    return mMusicVolume;
}

int SettingsMenu::getSelectedItem() const {
    return mSelectedItemIndex;
}

void SettingsMenu::moveUp() {
    if (mSelectedItemIndex > 0) {
        mSettingsItems[mSelectedItemIndex].setFillColor(sf::Color::White);
        mSelectedItemIndex--;
        mSettingsItems[mSelectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void SettingsMenu::moveDown() {
    if (mSelectedItemIndex < mSettingsItems.size() - 1) {
        mSettingsItems[mSelectedItemIndex].setFillColor(sf::Color::White);
        mSelectedItemIndex++;
        mSettingsItems[mSelectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void SettingsMenu::toggleMusic() {
    mMusicOn = !mMusicOn;
    if (mMusicOn) {
        mMusic.play();
    }
    else {
        mMusic.stop();
    }
    updateMenuText();
}

void SettingsMenu::adjustVolume(bool increase) {
    if (increase) {
        mMusicVolume = std::min(mMusicVolume + 5.0f, 100.0f);
    }
    else {
        mMusicVolume = std::max(mMusicVolume - 5.0f, 0.0f);
    }
    mMusic.setVolume(mMusicVolume);
    updateMenuText();
}

void SettingsMenu::updateMenuText() {
    mSettingsItems[0].setString(mMusicOn ? "Muzyka: Wlaczona" : "Muzyka: Wylaczona");
    mSettingsItems[1].setString("Glosnosc: " + std::to_string(static_cast<int>(mMusicVolume)));
    mSettingsItems[2].setString("Powrot");
}