#pragma once
#include "../Screens/MenuScreen.h"
#include "../Screens/ProfileScreen.h"
#include "../Screens/LeaderboardScreen.h"
#include "../Screens/RegisterScreen.h"
#include "../Screens/AuthScreen.h"
#include "../Screens/LoginScreen.h"
#include "../Screens/LeaderboardScreen.h"
#include "../BackEnd/player.h"
#include "AppState.h"
#include "../Screens/GameScreen.h"
#include "../BackEnd/Game.h"
#include <SFML/Graphics.hpp>

class Application{
    private:
    sf::RenderWindow window;
    AppState currentState;
    Player player;
    MenuScreen menu;
    ProfileScreen profile;
    LeaderBoardScreen leaderboard;
    AuthScreen auth;
    RegisterScreen registration;
    LoginScreen login;
    Game gameLogic;
    GameScreen game;

    public:
    Application();
    void run();
};

