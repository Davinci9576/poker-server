#pragma once
#include <SFML/Graphics.hpp>
#include "../BackEnd/Game.h"
#include "../Core/AppState.h"
#include <SFML/Audio.hpp>

enum RoundState{
    PRE_FLOP,
    FLOP,
    TURN,
    RIVER,
    SHOWDOWN
};

class GameScreen{
    private:
    sf::Font font;
    sf::Text welcomeText;
    sf::Text balanceText;

    sf::Texture card1Texture;
    sf::Texture card2Texture;
    
    sf::Texture dealer1Texture;
    sf::Texture dealer2Texture;
    
    sf::Texture cardBackTexture;

    sf::Sprite card1Sprite;
    sf::Sprite card2Sprite;

    sf::Sprite dealer1Sprite;
    sf::Sprite dealer2Sprite;

    sf::RectangleShape table;

    sf::RectangleShape foldButton;
    sf::RectangleShape callButton;
    sf::RectangleShape raiseButton;

    sf::RectangleShape card1;
    sf::RectangleShape card2;

    sf::Text foldText;
    sf::Text callText;
    sf::Text raiseText;

    sf::Texture flop1Texture;
    sf::Texture flop2Texture;
    sf::Texture flop3Texture;
    sf::Texture turnTexture;
    sf::Texture riverTexture;

    sf::Sprite flop1Sprite;
    sf::Sprite flop2Sprite;
    sf::Sprite flop3Sprite;
    sf::Sprite turnSprite;
    sf::Sprite riverSprite;

    bool showRaiseMenu;
    sf::RectangleShape raisePanel;
    sf::RectangleShape showResultMenu;

    sf::RectangleShape plus10Button;
    sf::RectangleShape plus50Button;
    sf::RectangleShape plus100Button;

    sf::RectangleShape playAgainButton;
    sf::RectangleShape returnMenuButton;

    sf::RectangleShape confirmButton;
    sf::RectangleShape cancelButton;

    sf::Text RaiseAmountText;
    sf::Text Plus10Text;
    sf::Text Plus50Text;
    sf::Text Plus100Text;
    sf::Text confirmText;
    sf::Text cancelText;
    sf::Text resultText;

    sf::Text playAgainText;
    sf::Text menuText;

    sf::SoundBuffer buttonBuffer;
    sf::Sound ButtonSound;

    sf::SoundBuffer cardBuffer;
    sf::Sound cardSound;

    sf::SoundBuffer winBuffer;
    sf::Sound winSound;
    sf::SoundBuffer raiseBuffer;
    sf::Sound raiseSound;
    sf::SoundBuffer oneCardBuffer;
    sf::Sound oneCardSound;
    sf::SoundBuffer tripleCardBuffer;
    sf::Sound tripleSound;

    double raiseAmount;
    bool result=false;
    bool playCardAfterButton=false;

    RoundState currentState;
    Game& game;
    public:
    GameScreen(Game& game);

    void handleEvent(sf::Event& event, sf::RenderWindow& window, AppState& CurrentState);
        void update();
        void render(sf::RenderWindow& window);
        
};