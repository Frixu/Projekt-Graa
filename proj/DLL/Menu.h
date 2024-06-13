/*#ifndef MENU_H
#define MENU_H

#include "API.h"
#include <SFML/Graphics.hpp>
#include <vector>

class EXPORT_API Menu {
public:
    Menu();
    void render(sf::RenderWindow& window) const;
    void handleInput(sf::Keyboard::Key key);
    int getSelectedItem() const;

private:
    std::vector<sf::RectangleShape> mMenuItems;
    int mSelectedItemIndex;

    void moveUp();
    void moveDown();
};

#endif*/

#ifndef MENU_H
#define MENU_H

#include "API.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "SettingsMenu.h"

class EXPORT_API Menu {
public:
    Menu(sf::Music& music);
    void render(sf::RenderWindow& window) const;
    void handleInput(sf::Keyboard::Key key);
    int getSelectedItem() const;

private:
    std::vector<sf::Text> mMenuItems;
    int mSelectedItemIndex;
    sf::Font mFont;
    SettingsMenu mSettingsMenu;
    bool inSettings;
    sf::Music& mMusic;

    void updateSettingsItems();

    void loadGame(const std::string& filename);

    void moveUp();
    void moveDown();
};

#endif // MENU_H
