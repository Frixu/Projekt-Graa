#ifndef SETTINGS_MENU_H
#define SETTINGS_MENU_H

#include "API.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class EXPORT_API SettingsMenu {
public:
    SettingsMenu(sf::Music& music);
    void render(sf::RenderWindow& window) const;
    void handleInput(sf::Keyboard::Key key);
    bool isMusicOn() const;
    float getMusicVolume() const;
    int getSelectedItem() const;

private:
    std::vector<sf::Text> mSettingsItems;
    int mSelectedItemIndex;
    sf::Font mFont;
    bool mMusicOn;
    float mMusicVolume;
    sf::Music& mMusic;

    void moveUp();
    void moveDown();
    void toggleMusic();
    void adjustVolume(bool increase);
    void updateMenuText();
};

#endif // SETTINGS_MENU_H