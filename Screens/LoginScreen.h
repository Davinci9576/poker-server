#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Core/AppState.h"
#include "../API/API.h"
#include "../BackEnd/Player.h"
#include "../BackEnd/Game.h"
#include <string>

class LoginScreen{
    private:
    sf::Font font;
    sf::Text titleText;
    sf::Text usernameLabel;
    sf::Text passwordLabel;

    sf::RectangleShape usernameBox;
    sf::RectangleShape passwordBox;
    sf::RectangleShape loginButton;
    sf::RectangleShape BackButton;

    sf::Text usernameText;
    sf::Text passwordText;
    sf::Text loginButtonText;
    sf::Text BackButtonText;

    std::string username;
    std::string password;
    
    sf::SoundBuffer ShuffleBuffer;
    sf::Sound ShuffleSound;


    bool usernameSelected=false;
    bool passwordSelected=false;
    public:
    LoginScreen();

    void update();
    void render(sf::RenderWindow& window);

    void handleEvent(sf::Event& event, sf::RenderWindow& window, AppState& CurrentState, Player& player, Game game);
};
