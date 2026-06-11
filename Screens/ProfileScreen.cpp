#include "ProfileScreen.h"
ProfileScreen::ProfileScreen(Player& p):
player(p){
    font.loadFromFile("Assets/fonts/Roboto-Regular.ttf");

    usernameText.setFont(font);
    balanceText.setFont(font);
    winsText.setFont(font);
    lossesText.setFont(font);
    winrateText.setFont(font);

    usernameText.setCharacterSize(30);
    balanceText.setCharacterSize(30);
    winsText.setCharacterSize(30);
    lossesText.setCharacterSize(30);
    winrateText.setCharacterSize(30);

    usernameText.setPosition(50, 50);
    balanceText.setPosition(50, 100);
    winsText.setPosition(50, 150);
    lossesText.setPosition(50, 200);
    winrateText.setPosition(50, 250);

    backButton.setSize(sf::Vector2f(200, 70));
    backButton.setPosition(50, 400);
    backButton.setFillColor(sf::Color::Red);
    backText.setString("Back");
    backText.setFont(font);
    backText.setCharacterSize(35);
    backText.setPosition(110, 415);
}
void ProfileScreen::update(sf::RenderWindow& window, AppState& currentState){
    usernameText.setString("Username: "+player.UsernameGive());
    balanceText.setString("Balance: "+std::to_string(player.BalanceGive()));
    winsText.setString("Wins: "+std::to_string(player.WinsGive()));
    lossesText.setString("Losses: "+std::to_string(player.LossesGive()));
    winrateText.setString("Winrate: "+std::to_string(player.WinrateGive()));

    sf::Vector2f mousePos=window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if(backButton.getGlobalBounds().contains(mousePos.x, mousePos.y)){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                currentState=MENU;
            }
        }
}
void ProfileScreen::render(sf::RenderWindow& window){
    window.draw(usernameText);
    window.draw(balanceText);
    window.draw(winsText);
    window.draw(lossesText);
    window.draw(winrateText);
    window.draw(backButton);
    window.draw(backText);
}
