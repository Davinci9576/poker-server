#include "LoginScreen.h"

LoginScreen::LoginScreen(){
    font.loadFromFile("Assets/fonts/Roboto-Regular.ttf");

    titleText.setString("Login");
    titleText.setFillColor(sf::Color::White);
    titleText.setFont(font);
    titleText.setPosition(350, 40);
    titleText.setCharacterSize(35);

    usernameLabel.setString("Username");
    usernameLabel.setFillColor(sf::Color::White);
    usernameLabel.setPosition(220, 120);
    usernameLabel.setCharacterSize(35);
    usernameLabel.setFont(font);

    passwordLabel.setPosition(220, 250);
    passwordLabel.setFillColor(sf::Color::White);
    passwordLabel.setCharacterSize(35);
    passwordLabel.setFont(font);
    passwordLabel.setString("Password");

    usernameBox.setPosition(220, 170);
    usernameBox.setSize(sf::Vector2f(350, 50));
    usernameBox.setFillColor(sf::Color::White);

    passwordBox.setPosition(220, 300);
    passwordBox.setSize(sf::Vector2f(350, 50));
    passwordBox.setFillColor(sf::Color::White);

    loginButton.setPosition(220, 420);
    loginButton.setSize(sf::Vector2f(150, 60));
    loginButton.setFillColor(sf::Color::Blue);

    BackButton.setPosition(420, 420);
    BackButton.setSize(sf::Vector2f(150, 60));
    BackButton.setFillColor(sf::Color::Blue);

    usernameText.setString("");
    usernameText.setFillColor(sf::Color::Black);
    usernameText.setPosition(235, 175);
    usernameText.setCharacterSize(35);
    usernameText.setFont(font);

    passwordText.setString("");
    passwordText.setFillColor(sf::Color::Black);
    passwordText.setPosition(235, 305);
    passwordText.setCharacterSize(35);
    passwordText.setFont(font);
    
    loginButtonText.setString("LOGIN");
    loginButtonText.setFillColor(sf::Color::White);
    loginButtonText.setPosition(245, 430);
    loginButtonText.setCharacterSize(35);
    loginButtonText.setFont(font);

    BackButtonText.setString("Back");
    BackButtonText.setFillColor(sf::Color::White);
    BackButtonText.setPosition(455, 430);
    BackButtonText.setCharacterSize(35);
    BackButtonText.setFont(font);
    
    usernameSelected=false;
    passwordSelected=false;

    ShuffleBuffer.loadFromFile("Assets/Audio/s.wav");
    ShuffleSound.setBuffer(ShuffleBuffer);
}

void LoginScreen::update(){
}

void LoginScreen::handleEvent(sf::Event&event, sf::RenderWindow& window, AppState& CurrentState,Player& player, Game game){
    if(event.type==sf::Event::TextEntered){
        if(usernameSelected){
            if(event.text.unicode==8){
                if(!username.empty()){
                    username.pop_back();
                }
            }else if(event.text.unicode>=32 && event.text.unicode<127) {
                username+=static_cast<char>(event.text.unicode);
            }
            usernameText.setString(username);
        }
        else if(passwordSelected){
            if(event.text.unicode==8){
                if(!password.empty()){
                    password.pop_back();
                }
            }else if(event.text.unicode>=32 && event.text.unicode<127){
                password+=static_cast<char>(event.text.unicode);
            }
            std::string hidden(password.length(), '*');
            passwordText.setString(hidden);
        }
    }

    if(event.type==sf::Event::MouseButtonPressed){
        sf::Vector2f mousePos=window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if(loginButton.getGlobalBounds().contains(mousePos.x, mousePos.y)){
            ApiService api;
            LoginResponse response=api.login(username, password);
            if(response.success){
                player.setter(response.username,
                              response.balance,
                              response.wins,
                              response.losses,
                              response.winrate,
                              password
            );
            game.startRound();
            username="";
            password="";
            usernameText.setString(username);
            passwordText.setString(password);
            ShuffleSound.play();
            CurrentState=GAME;
            }
        }
        else if(BackButton.getGlobalBounds().contains(mousePos.x, mousePos.y)){
            username="";
            password="";
            usernameText.setString(username);
            passwordText.setString(password);
            CurrentState=AUTH;
        }
        else if(usernameBox.getGlobalBounds().contains(mousePos.x, mousePos.y)){
            usernameSelected=true;
            passwordSelected=false;
            usernameBox.setFillColor(sf::Color::Yellow);
            passwordBox.setFillColor(sf::Color::White);
        }
        else if(passwordBox.getGlobalBounds().contains(mousePos.x, mousePos.y)){
            usernameSelected=false;
            passwordSelected=true;
            usernameBox.setFillColor(sf::Color::White);
            passwordBox.setFillColor(sf::Color::Yellow);
        }else{
            passwordSelected=false;
            usernameSelected=false;
            usernameBox.setFillColor(sf::Color::White);
            passwordBox.setFillColor(sf::Color::White);
        }
    }
    
}
void LoginScreen::render(sf::RenderWindow& window){
    window.draw(titleText);
    window.draw(usernameLabel);
    window.draw(passwordLabel);
    window.draw(usernameBox);
    window.draw(passwordBox);
    window.draw(loginButton);
    window.draw(BackButton);
    window.draw(usernameText);
    window.draw(passwordText);
    window.draw(loginButtonText);
    window.draw(BackButtonText);
}