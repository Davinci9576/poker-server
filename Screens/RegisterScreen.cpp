#include "RegisterScreen.h"
#include "../BackEnd/player.h"
#include "../API/API.h"

RegisterScreen::RegisterScreen(){
    font.loadFromFile("Assets/fonts/Roboto-Regular.ttf");

    titleText.setString("Register");
    titleText.setFillColor(sf::Color::White);
    titleText.setFont(font);
    titleText.setPosition(320, 40);
    titleText.setCharacterSize(45);

    usernameLabel.setString("Username");
    usernameLabel.setFillColor(sf::Color::White);
    usernameLabel.setPosition(225, 120);
    usernameLabel.setCharacterSize(35);
    usernameLabel.setFont(font);

    passwordLabel.setPosition(225, 240);
    passwordLabel.setFillColor(sf::Color::White);
    passwordLabel.setCharacterSize(35);
    passwordLabel.setFont(font);
    passwordLabel.setString("Password");

    ConfirmLabel.setPosition(225, 340);
    ConfirmLabel.setFillColor(sf::Color::White);
    ConfirmLabel.setCharacterSize(35);
    ConfirmLabel.setFont(font);
    ConfirmLabel.setString("Confirm password");

    usernameBox.setPosition(225, 160);
    usernameBox.setSize(sf::Vector2f(350, 50));
    usernameBox.setFillColor(sf::Color::White);

    passwordBox.setPosition(220, 280);
    passwordBox.setSize(sf::Vector2f(350, 50));
    passwordBox.setFillColor(sf::Color::White);

    confirmBox.setPosition(225, 400);
    confirmBox.setSize(sf::Vector2f(350, 50));
    confirmBox.setFillColor(sf::Color::White);

    registerButton.setPosition(225, 500);
    registerButton.setSize(sf::Vector2f(160, 60));
    registerButton.setFillColor(sf::Color::Blue);

    BackButton.setPosition(415, 500);
    BackButton.setSize(sf::Vector2f(160, 60));
    BackButton.setFillColor(sf::Color::Blue);

    usernameText.setString("");
    usernameText.setFillColor(sf::Color::Black);
    usernameText.setPosition(235, 165);
    usernameText.setCharacterSize(35);
    usernameText.setFont(font);

    passwordText.setString("");
    passwordText.setFillColor(sf::Color::Black);
    passwordText.setPosition(235, 285);
    passwordText.setCharacterSize(35);
    passwordText.setFont(font);

    ConfirmText.setString("");
    ConfirmText.setFillColor(sf::Color::Black);
    ConfirmText.setCharacterSize(35);
    ConfirmText.setFont(font);
    ConfirmText.setPosition(235, 405);
    
    registerButtonText.setString("REGISTER");
    registerButtonText.setFillColor(sf::Color::White);
    registerButtonText.setPosition(240, 512);
    registerButtonText.setCharacterSize(35);
    registerButtonText.setFont(font);

    BackButtonText.setString("Back");
    BackButtonText.setFillColor(sf::Color::White);
    BackButtonText.setPosition(465, 512);
    BackButtonText.setCharacterSize(35);
    BackButtonText.setFont(font);

}
void RegisterScreen::update(){
}
void RegisterScreen::handleEvent(sf::Event& event, sf::RenderWindow& window, AppState& CurrentState){
    if(event.type==sf::Event::TextEntered){
        if(usernameSelected){
            if(event.text.unicode==8){
                if(!username.empty()){
                    username.pop_back();
                }
            }
    else{
        username+=static_cast<char>(event.text.unicode);
    }    usernameText.setString(username);
        }else if(passwordSelected){
            if(event.text.unicode==8){
                if(!password.empty()){
                    password.pop_back();
                }
            }else{
            password+=static_cast<char>(event.text.unicode);
            }
            std::string hidden(password.length(), '*');
            passwordText.setString(hidden);
        }else if(confirmSelected){
            if(event.text.unicode==8){
                if(!confirm.empty()){
                    confirm.pop_back();
                }
            }else{
                confirm+=static_cast<char>(event.text.unicode);
            }
            ConfirmText.setString(confirm);
        }
    }
    if(event.type==sf::Event::MouseButtonPressed){
        sf::Vector2f mousePos=window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if(registerButton.getGlobalBounds().contains(mousePos.x, mousePos.y)){
            ApiService api;
            bool success=api.registerUser(username, password);
            if(success){
                CurrentState=LOGIN;
            }
        }
        else if(BackButton.getGlobalBounds().contains(mousePos.x, mousePos.y)){
            CurrentState=AUTH;
        }
        else if(usernameBox.getGlobalBounds().contains(mousePos.x, mousePos.y)){
            usernameSelected=true;
            passwordSelected=false;
            usernameBox.setFillColor(sf::Color::Yellow);
            passwordBox.setFillColor(sf::Color::White);
            confirmBox.setFillColor(sf::Color::White);
        }
        else if(passwordBox.getGlobalBounds().contains(mousePos.x, mousePos.y)){
            usernameSelected=false;
            passwordSelected=true;
            passwordBox.setFillColor(sf::Color::Yellow);
            usernameBox.setFillColor(sf::Color::White);
            confirmBox.setFillColor(sf::Color::White);
        }else if(confirmBox.getGlobalBounds().contains(mousePos.x, mousePos.y)){
            usernameSelected=false;
            passwordSelected=false;
            confirmSelected=true;
            passwordBox.setFillColor(sf::Color::White);
            usernameBox.setFillColor(sf::Color::White);
            confirmBox.setFillColor(sf::Color::Yellow);
        }
        else{
            usernameSelected=false;
            passwordSelected=false;
            confirmSelected=false;
            usernameBox.setFillColor(sf::Color::White);
            passwordBox.setFillColor(sf::Color::White);
            confirmBox.setFillColor(sf::Color::White);
        }
    }
}
void RegisterScreen::render(sf::RenderWindow& window){
    window.draw(titleText);
    window.draw(usernameLabel);
    window.draw(passwordLabel);
    window.draw(usernameBox);
    window.draw(passwordBox);
    window.draw(registerButton);
    window.draw(BackButton);
    window.draw(usernameText);
    window.draw(passwordText);
    window.draw(registerButtonText);
    window.draw(BackButtonText);
    window.draw(ConfirmLabel);
    window.draw(confirmBox);
    window.draw(ConfirmText);
}