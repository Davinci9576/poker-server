#include "MenuScreen.h"
MenuScreen::MenuScreen(){
    font.loadFromFile("Assets/fonts/Roboto-Regular.ttf");

    playButton.setPosition(300, 120);
    playButton.setFillColor(sf::Color(200, 0, 255));
    playButton.setSize(sf::Vector2f(250, 80));

    profileButton.setFillColor(sf::Color::Green);
    profileButton.setPosition(300, 220);
    profileButton.setSize(sf::Vector2f(250, 80));

    leaderboardButton.setPosition(300, 320);
    leaderboardButton.setFillColor(sf::Color::Red);
    leaderboardButton.setSize(sf::Vector2f(250, 80));

    playText.setFont(font);
    playText.setString("Play");
    playText.setCharacterSize(40);
    playText.setPosition(380, 135);

    profileText.setFont(font);
    profileText.setString("Profile");
    profileText.setCharacterSize(40);
    profileText.setPosition(350, 235);

    leaderboardText.setFont(font);
    leaderboardText.setString("LeaderBoard");
    leaderboardText.setPosition(315, 335);
    leaderboardText.setCharacterSize(40);

}
void MenuScreen::update(sf::RenderWindow& window, AppState& currentState){
    sf::Vector2f mousePos=window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if(playButton.getGlobalBounds().contains(mousePos.x, mousePos.y)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            currentState=AUTH;
        }
    }
    if(profileButton.getGlobalBounds().contains(mousePos.x, mousePos.y)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            currentState=PROFILE;
        }
    }
    if(leaderboardButton.getGlobalBounds().contains(mousePos.x, mousePos.y)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            currentState=LEADERBOARD;
        }
    }
}
void MenuScreen::render(sf::RenderWindow& window){
    window.draw(playButton);
    window.draw(profileButton);
    window.draw(playText);
    window.draw(profileText);
    window.draw(leaderboardButton);
    window.draw(leaderboardText);
}