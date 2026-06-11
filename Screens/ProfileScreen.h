#pragma once
#include <SFML/Graphics.hpp>
#include "../BackEnd/player.h"
#include "../Core/AppState.h"

class ProfileScreen{
    private:
    Player& player;
    sf::Font font;
    sf::Text usernameText;
    sf::Text balanceText;
    sf::Text winsText;
    sf::Text lossesText;
    sf::Text winrateText;
    sf::RectangleShape backButton;
    sf::Text backText;
    public:
    ProfileScreen(Player& p);
    void update(sf::RenderWindow& window, AppState& currentState);
    void render(sf::RenderWindow& window);
};
