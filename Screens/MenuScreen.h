#pragma once
#include <SFML/Graphics.hpp>
#include "../Core/AppState.h"

class MenuScreen{
    private:
    sf::Font font;
    sf::RectangleShape playButton;
    sf::RectangleShape profileButton;
    sf::RectangleShape leaderboardButton;

    sf::Text playText;
    sf::Text profileText;
    sf::Text leaderboardText;
    public:
    MenuScreen();

    void update(sf::RenderWindow& window, AppState& currentState);
    void render(sf::RenderWindow& window);
};