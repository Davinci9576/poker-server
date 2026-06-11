#include "LeaderboardScreen.h"

LeaderBoardScreen::LeaderBoardScreen(){
    font.loadFromFile("Assets/fonts/Roboto-Regular.ttf");
    TitleText.setFont(font);
    TitleText.setString("LeaderBoard");
    TitleText.setCharacterSize(50);
    TitleText.setPosition(220, 40);

    LeaderBoardText.setFont(font);
    LeaderBoardText.setCharacterSize(30);
    LeaderBoardText.setPosition(220, 140);

    ApiService api;
    auto players=api.getLeaderboard("Money");
    std::string text;
    for(int i=0; i<players.size(); i++){
        text+=std::to_string(i+1);
        text+=". ";
        text+=players[i].username;
        text+=" - ";
        text+=std::to_string(players[i].value);
        text+="\n";
    }
    LeaderBoardText.setString(text);
    
    Button.setSize(sf::Vector2f(200, 70));
    Button.setPosition(50, 500);
    Button.setFillColor(sf::Color::Red);

    ButtonText.setCharacterSize(35);
    ButtonText.setPosition(110, 515);
    ButtonText.setFont(font);
    ButtonText.setString("Back");
}

void LeaderBoardScreen::update(sf::RenderWindow& window, AppState& CurrentState){
    sf::Vector2f mousePos=window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if(Button.getGlobalBounds().contains(
        mousePos.x,
        mousePos.y
    )){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            CurrentState=MENU;
        }
    }
}
void LeaderBoardScreen::render(sf::RenderWindow& window){
    window.draw(TitleText);
    window.draw(LeaderBoardText);
    window.draw(Button);
    window.draw(ButtonText);
}
