#include "Menu.h"
#include <iostream>
#include <fstream>

Menu::Menu(sf::Music& music) : mSelectedItemIndex(0), inSettings(false), mMusic(music), mSettingsMenu(music){
    if (!mFont.loadFromFile("font/font.ttf")) {
        // Handle error
    }

    std::vector<std::string> menuTexts = { "Nowa Gra", "Ustawienia", "Wczytaj Gre", "Wyjscie" };


    float windowWidth = 1000.0f; // Szerokość okna
    float windowHeight = 800.0f; // Wysokość okna

    for (int i = 0; i < menuTexts.size(); ++i) {
        sf::Text item;
        item.setFont(mFont);
        item.setString(menuTexts[i]);
        item.setCharacterSize(30);
        item.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White);
        // Oblicz szerokość tekstu
        sf::FloatRect textBounds = item.getLocalBounds();
        float xPosition = (windowWidth - textBounds.width) / 2.0f; // Wyśrodkowanie w poziomie
        float yPosition = 250.0f + i * 60.0f; // Pozycjonowanie w pionie

        item.setPosition(xPosition, yPosition);
        mMenuItems.push_back(item);
    }
}

void Menu::render(sf::RenderWindow& window) const {
    if (inSettings) {
        mSettingsMenu.render(window);
    }
    else {
        for (const auto& item : mMenuItems) {
            window.draw(item);
        }
    }
}

void Menu::handleInput(sf::Keyboard::Key key) {
    if (inSettings) {
        mSettingsMenu.handleInput(key);
        if (key == sf::Keyboard::Enter && mSettingsMenu.getSelectedItem() == 2) {
            inSettings = false;
        }
    }
    else {
        if (key == sf::Keyboard::Up) {
            moveUp();
        }
        else if (key == sf::Keyboard::Down) {
            moveDown();
        }
        else if (key == sf::Keyboard::Enter) {
            if (mSelectedItemIndex == 0) {
                
            }
            else if (mSelectedItemIndex == 1){
                inSettings = true;
            }
            else if (mSelectedItemIndex == 2) {
                // Load Game
                try {
                    loadGame("savegame.dat");
                    std::cout << "Game loaded successfully!" << std::endl;
                    
                }
                catch (const std::exception& e) {
                    std::cerr << "Error loading game: " << e.what() << std::endl;
                }
            }
            else if (mSelectedItemIndex == 3) {
                // Exit
            }
        }

        for (int i = 0; i < mMenuItems.size(); ++i) {
            mMenuItems[i].setFillColor(i == mSelectedItemIndex ? sf::Color::Red : sf::Color::White);
        }
    }
}

void Menu::moveUp() {
    if (mSelectedItemIndex > 0) {
        mMenuItems[mSelectedItemIndex].setFillColor(sf::Color::White);
        mSelectedItemIndex--;
        mMenuItems[mSelectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if (mSelectedItemIndex < mMenuItems.size() - 1) {
        mMenuItems[mSelectedItemIndex].setFillColor(sf::Color::White);
        mSelectedItemIndex++;
        mMenuItems[mSelectedItemIndex].setFillColor(sf::Color::Red);
    }
}

int Menu::getSelectedItem() const {
    return mSelectedItemIndex;
}

void Menu::loadGame(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        throw std::runtime_error("Error opening file for loading!");
    }

    int score;
    inFile.read(reinterpret_cast<char*>(&score), sizeof(score));
    
    inFile.close();


}