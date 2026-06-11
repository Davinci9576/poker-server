#pragma once
#include <SFML/Graphics.hpp>
#include "../Core/AppState.h"
#include <string>

class RegisterScreen{
    private:
    sf::Font font;
    sf::Text titleText;
    sf::Text usernameLabel;
    sf::Text passwordLabel;
    sf::Text ConfirmLabel;

    sf::RectangleShape usernameBox;
    sf::RectangleShape passwordBox;
    sf::RectangleShape registerButton;
    sf::RectangleShape BackButton;
    sf::RectangleShape confirmBox;

    sf::Text usernameText;
    sf::Text passwordText;
    sf::Text registerButtonText;
    sf::Text BackButtonText;
    sf::Text ConfirmText;

    std::string username;
    std::string password;
    std::string confirm;

    bool usernameSelected=false;
    bool passwordSelected=false;
    bool confirmSelected=false;
    public:
    RegisterScreen();

    void update();
    void render(sf::RenderWindow& window);

    void handleEvent(sf::Event& event, sf::RenderWindow& window, AppState& CurrentSate);
};
