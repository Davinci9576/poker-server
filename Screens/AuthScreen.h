#pragma once
#include <SFML/Graphics.hpp>
#include "../Core/AppState.h"

class AuthScreen{
    private:
    sf::Font font;
    sf::RectangleShape loginButton;
    sf::RectangleShape registerButton;
    sf::RectangleShape backButton;

    sf::Text titleText;
    sf::Text loginText;
    sf::Text registerText;
    sf::Text backText;
    
    public:
    AuthScreen();
    
    void update(sf::RenderWindow& window, AppState& CurrentState);
    void render(sf::RenderWindow& window);
};