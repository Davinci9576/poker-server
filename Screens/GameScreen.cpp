#include "GameScreen.h"
#include <iostream>

GameScreen::GameScreen(Game& g)
    : game(g),
    showRaiseMenu(false),
    raiseAmount(0)
{
    font.loadFromFile("Assets/fonts/Roboto-Regular.ttf");

    welcomeText.setFont(font);
    welcomeText.setCharacterSize(30);
    welcomeText.setPosition(30, 20);
    welcomeText.setFillColor(sf::Color::White);
    
    balanceText.setFont(font);
    balanceText.setPosition(30, 70);
    balanceText.setCharacterSize(24);

    table.setSize(sf::Vector2f(600, 250));
    table.setFillColor(sf::Color::Green);
    table.setPosition(100, 150);

    card1.setSize(sf::Vector2f(100, 140));
    card1.setPosition(280, 450);
    card1.setFillColor(sf::Color::White);

    card2.setSize(sf::Vector2f(100, 140));
    card2.setPosition(420, 450);
    card2.setFillColor(sf::Color::White);
    auto hand=game.getPlayerHand();

    foldButton.setSize(sf::Vector2f(150, 60));
    foldButton.setPosition(150, 650);
    foldButton.setFillColor(sf::Color::Red);

    callButton.setSize(sf::Vector2f(150, 60));
    callButton.setPosition(325, 650);
    callButton.setFillColor(sf::Color::Blue);

    raiseButton.setSize(sf::Vector2f(150, 60));
    raiseButton.setPosition(500, 650);
    raiseButton.setFillColor(sf::Color::Green);

    foldText.setFont(font);
    foldText.setString("FOLD");
    foldText.setPosition(190, 665);

    callText.setFont(font);
    callText.setString("CALL");
    callText.setPosition(370, 665);

    raiseText.setFont(font);
    raiseText.setString("RAISE");
    raiseText.setPosition(535, 665);

    raisePanel.setSize(sf::Vector2f(300, 250));
    raisePanel.setPosition(250, 150);
    raisePanel.setFillColor(sf::Color(50, 50, 50));

    plus10Button.setSize(sf::Vector2f(80, 40));
    plus10Button.setPosition(sf::Vector2f(280, 240));
    plus10Button.setFillColor(sf::Color::Green);

    plus50Button.setSize(sf::Vector2f(80, 40));
    plus50Button.setPosition(380, 240);
    plus50Button.setFillColor(sf::Color::Green);

    plus100Button.setSize(sf::Vector2f(80, 40));
    plus100Button.setPosition(280, 300);
    plus100Button.setFillColor(sf::Color::Green);

    confirmButton.setSize(sf::Vector2f(120, 50));
    confirmButton.setPosition(340, 360);
    confirmButton.setFillColor(sf::Color::Blue);

    cancelButton.setSize(sf::Vector2f(120, 50));
    cancelButton.setPosition(340, 425);
    cancelButton.setFillColor(sf::Color::Red);

    RaiseAmountText.setFont(font);
    RaiseAmountText.setCharacterSize(24);
    RaiseAmountText.setFillColor(sf::Color::White);
    RaiseAmountText.setPosition(300, 180);
    RaiseAmountText.setString("Raise: 0");

    Plus10Text.setFont(font);
    Plus10Text.setCharacterSize(20);
    Plus10Text.setFillColor(sf::Color::Black);
    Plus10Text.setPosition(300, 248);
    Plus10Text.setString("+10");

    Plus50Text.setFont(font);
    Plus50Text.setCharacterSize(20);
    Plus50Text.setFillColor(sf::Color::Black);
    Plus50Text.setPosition(400, 248);
    Plus50Text.setString("+50");

    Plus100Text.setFont(font);
    Plus100Text.setCharacterSize(20);
    Plus100Text.setFillColor(sf::Color::Black);
    Plus100Text.setPosition(295, 308);
    Plus100Text.setString("+100");

    confirmText.setFont(font);
    confirmText.setCharacterSize(20);
    confirmText.setFillColor(sf::Color::White);
    confirmText.setPosition(355, 375);
    confirmText.setString("Confirm");

    cancelText.setFont(font);
    cancelText.setCharacterSize(20);
    cancelText.setFillColor(sf::Color::White);
    cancelText.setPosition(365, 440);
    cancelText.setString("Cancel");

    playAgainButton.setFillColor(sf::Color::Red);
    playAgainButton.setSize(sf::Vector2f(120, 50));
    playAgainButton.setPosition(460, 360);

    returnMenuButton.setFillColor(sf::Color::Red);
    returnMenuButton.setSize(sf::Vector2f(120, 50));
    returnMenuButton.setPosition(610, 360);

    showResultMenu.setFillColor(sf::Color::Green);
    showResultMenu.setPosition(425, 250);
    showResultMenu.setSize(sf::Vector2f(350, 200));

    resultText.setFont(font);
    resultText.setCharacterSize(30);
    resultText.setFillColor(sf::Color::White);
    resultText.setPosition(500, 280);
    
    playAgainText.setFont(font);
    playAgainText.setString("Play Again");
    playAgainText.setPosition(470, 372);
    playAgainText.setCharacterSize(20);
    playAgainText.setFillColor(sf::Color::White);
    
    menuText.setFont(font);
    menuText.setString("Menu");
    menuText.setPosition(640, 372);
    menuText.setCharacterSize(20);
    menuText.setFillColor(sf::Color::White);

    cardBackTexture.loadFromFile("Assets/Cards/card_back.png");

    card1Sprite.setPosition(280, 450);
    card2Sprite.setPosition(420, 450);

    flop1Sprite.setPosition(180, 250);
    flop2Sprite.setPosition(280, 250);
    flop3Sprite.setPosition(380, 250);
    turnSprite.setPosition(480, 250);
    riverSprite.setPosition(580, 250);

    dealer1Sprite.setPosition(280, 50);
    dealer2Sprite.setPosition(420, 50);

    if(!cardBuffer.loadFromFile("Assets/Audio/s.wav")){
        std::cout<<"Failed to load shuffling.wav";
    }
    raiseBuffer.loadFromFile("Assets/Audio/raise.wav");
    raiseSound.setBuffer(raiseBuffer);
    
    cardSound.setBuffer(cardBuffer);
    buttonBuffer.loadFromFile("Assets/Audio/button.wav");
    ButtonSound.setBuffer(buttonBuffer);

    oneCardBuffer.loadFromFile("Assets/Audio/oneCard.wav");
    oneCardSound.setBuffer(oneCardBuffer);

    tripleCardBuffer.loadFromFile("Assets/Audio/tripleCard.wav");
    tripleSound.setBuffer(tripleCardBuffer);
}

void GameScreen::handleEvent(sf::Event& event, sf::RenderWindow& window, AppState& CurrentState){
    if(event.type==sf::Event::MouseButtonPressed){
        sf::Vector2f mousePos=window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if(result){
            if(playAgainButton.getGlobalBounds().contains(mousePos)){
                game.refreshResult();
                game.startRound();
                result=false;
                raiseAmount=0;
                resultText.setString("");
                ButtonSound.play();
                playCardAfterButton=true;
                dealer1Sprite.setTexture(cardBackTexture);
                dealer2Sprite.setTexture(cardBackTexture);

            }else if(returnMenuButton.getGlobalBounds().contains(mousePos)){
                game.refreshResult();
                result=false;
                raiseAmount=0;
                resultText.setString("");
                ButtonSound.play();
                dealer1Sprite.setTexture(cardBackTexture);
                dealer2Sprite.setTexture(cardBackTexture);
                CurrentState=MENU;
            }
            return;
        }
        if(showRaiseMenu){
            if(plus10Button.getGlobalBounds().contains(mousePos)){
                raiseAmount+=10;
                raiseSound.play();
            }
            else if(plus50Button.getGlobalBounds().contains(mousePos)){
                raiseAmount+=50;
                raiseSound.play();
            }else if(plus100Button.getGlobalBounds().contains(mousePos)){
                raiseAmount+=100;
                raiseSound.play();
            }
            else if(confirmButton.getGlobalBounds().contains(mousePos)){
                game.Raise(raiseAmount);
                raiseAmount=0;
                showRaiseMenu=false;
                ButtonSound.play();
            }else if(cancelButton.getGlobalBounds().contains(mousePos)){
                showRaiseMenu=false;
                raiseAmount=0;
                ButtonSound.play();
            }
        }else{
            if(foldButton.getGlobalBounds().contains(mousePos)){
                game.fold();
                game.refreshResult();
                game.startRound();
                result=false;
                raiseAmount=0;
                resultText.setString("");
                ButtonSound.play();
                game.foldLost();
            }
            else if(callButton.getGlobalBounds().contains(mousePos)){
                game.nextStage();
                ButtonSound.play();
                auto community=game.getCommunityCards();
                if(community.size()>=3){
                    flop1Texture.loadFromFile("Assets/Cards/"+community[0].getImageName()+".png");
                    flop2Texture.loadFromFile("Assets/Cards/"+community[1].getImageName()+".png");
                    flop3Texture.loadFromFile("Assets/Cards/"+community[2].getImageName()+".png");
                    if(community.size()==3){
                        tripleSound.play();
                    }
                }
                if(community.size()>=4){
                    turnTexture.loadFromFile("Assets/Cards/"+community[3].getImageName()+".png");
                    oneCardSound.play();
                }
                if(community.size()>=5){
                    riverTexture.loadFromFile("Assets/Cards/"+community[4].getImageName()+".png");
                }

            }else if(raiseButton.getGlobalBounds().contains(mousePos)){
                showRaiseMenu=true;
            }
        }
    }
}
void GameScreen::update(){
    if(!game.results().empty()){
        result=true;
        resultText.setString(game.results());
    }
    auto community=game.getCommunityCards();
    auto playerhand=game.getPlayerHand();
    auto dealerhand=game.getDealerHand();
    if(community.size()>=3){
        flop1Sprite.setTexture(flop1Texture);
        flop2Sprite.setTexture(flop2Texture);
        flop3Sprite.setTexture(flop3Texture);
    }
    if(community.size()>=4){
        turnSprite.setTexture(turnTexture);
    }
    if(community.size()>=5){
        riverSprite.setTexture(riverTexture);
    }
    welcomeText.setString(game.getUsername());
    
    if(result && dealerhand.size()>=2){
        dealer1Texture.loadFromFile("Assets/Cards/"+dealerhand[0].getImageName()+".png");
        dealer2Texture.loadFromFile("Assets/Cards/"+dealerhand[1].getImageName()+".png");
        dealer1Sprite.setTexture(dealer1Texture);
        dealer2Sprite.setTexture(dealer2Texture);
    }else{
        dealer1Sprite.setTexture(cardBackTexture);
        dealer2Sprite.setTexture(cardBackTexture);
    }
    balanceText.setString("Balance: "+std::to_string(game.getBalance()));
    RaiseAmountText.setString("Raise: "+std::to_string(int(raiseAmount)));

    if(playerhand.size()>=2){
        card1Texture.loadFromFile("Assets/Cards/"+playerhand[0].getImageName()+".png");
        card2Texture.loadFromFile("Assets/Cards/"+playerhand[1].getImageName()+".png");
        card1Sprite.setTexture(card1Texture);
        card2Sprite.setTexture(card2Texture);
    }

    if(playCardAfterButton && ButtonSound.getStatus()==sf::Sound::Stopped){
        cardSound.play();
        playCardAfterButton=false;
    }
}

void GameScreen::render(sf::RenderWindow& window){

    window.draw(table);
    window.draw(welcomeText);
    window.draw(balanceText);

    window.draw(foldButton);
    window.draw(callButton);
    window.draw(raiseButton);

    window.draw(foldText);
    window.draw(callText);
    window.draw(raiseText);

    auto community=game.getCommunityCards();

    if(community.size()>=3){
        window.draw(flop1Sprite);
        window.draw(flop2Sprite);
        window.draw(flop3Sprite);
    }
    if(community.size()>=4){
        window.draw(turnSprite);
    }
    if(community.size()>=5){
        window.draw(riverSprite);
    }

    window.draw(card1Sprite);
    window.draw(card2Sprite);

    window.draw(dealer1Sprite);
    window.draw(dealer2Sprite);

    if(result)
{
    window.draw(showResultMenu);

    window.draw(playAgainButton);
    window.draw(returnMenuButton);

    window.draw(resultText);
    window.draw(playAgainText);
    window.draw(menuText);
}
    
    if(showRaiseMenu)
{
    window.draw(raisePanel);

    window.draw(plus10Button);
    window.draw(plus50Button);
    window.draw(plus100Button);

    window.draw(confirmButton);
    window.draw(cancelButton);

    window.draw(RaiseAmountText);

    window.draw(Plus10Text);
    window.draw(Plus50Text);
    window.draw(Plus100Text);

    window.draw(confirmText);
    window.draw(cancelText);
}
}