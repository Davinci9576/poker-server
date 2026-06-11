#include "AuthScreen.h"

AuthScreen::AuthScreen(){
    font.loadFromFile("Assets/fonts/Roboto-Regular.ttf");
    loginButton.setFillColor(sf::Color::Red);
    loginButton.setPosition(300, 180);
    loginButton.setSize(sf::Vector2f(200, 70));
    
    registerButton.setFillColor(sf::Color::Red);
    registerButton.setPosition(300, 300);
    registerButton.setSize(sf::Vector2f(200, 70));

    backButton.setFillColor(sf::Color::Red);
    backButton.setPosition(100, 420);
    backButton.setSize(sf::Vector2f(200, 70));


    titleText.setFont(font);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(180, 50);
    titleText.setCharacterSize(35);
    titleText.setString("Authentication center");

    loginText.setFont(font);
    loginText.setCharacterSize(35);
    loginText.setPosition(355, 195);
    loginText.setFillColor(sf::Color::White);
    loginText.setString("Login");

    registerText.setFont(font);
    registerText.setCharacterSize(35);
    registerText.setPosition(330, 315);
    registerText.setString("Register");
    registerText.setFillColor(sf::Color::White);

    backText.setFont(font);
    backText.setPosition(160, 435);
    backText.setCharacterSize(35);
    backText.setFillColor(sf::Color::White);
    backText.setString("Back");
}

void AuthScreen::update(sf::RenderWindow& window, AppState& CurrentState){
    sf::Vector2f mousePos=window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if(loginButton.getGlobalBounds().contains(mousePos.x, mousePos.y)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            CurrentState=LOGIN;
        }
    }
    if(registerButton.getGlobalBounds().contains(mousePos.x, mousePos.y)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            CurrentState=REGISTER;
        }
    }
    if(backButton.getGlobalBounds().contains(mousePos.x, mousePos.y)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            CurrentState=MENU;
        }
    }
}
void AuthScreen::render(sf::RenderWindow& window){
    window.draw(loginButton);
    window.draw(registerButton);
    window.draw(backButton);
    window.draw(titleText);
    window.draw(loginText);
    window.draw(registerText);
    window.draw(backText);
}