#pragma once
#include <SFML/Graphics.hpp>
#include "../Core/AppState.h"
#include "../API/API.h"

class LeaderBoardScreen{
    private:
    sf::Font font;
    sf::Text TitleText;
    sf::Text LeaderBoardText;
    sf::RectangleShape Button;
    sf::Text ButtonText;
    public:
    LeaderBoardScreen();
    void update(sf::RenderWindow& window, AppState& CurrentState);
    void render(sf::RenderWindow& window);
};

