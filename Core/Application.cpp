#include "Application.h"
Application::Application():window(
    sf::VideoMode(1200, 900),
    "Texas Poker"
),
currentState(MENU),
player("Timo", "1234"),
profile(player),
gameLogic(player),
game(gameLogic)
{
}
void Application::run(){
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
            if(currentState==LOGIN){
                login.handleEvent(event, window, currentState, player, gameLogic);
            }
            if(currentState==REGISTER){
                registration.handleEvent(event, window, currentState);
            }
            if(currentState==GAME){
                game.handleEvent(event, window, currentState);
            }
        }
        switch(currentState){
            case MENU:
            menu.update(window, currentState);
            break;
            case PROFILE:
            profile.update(window, currentState);
            break;
            case LEADERBOARD:
            leaderboard.update(window, currentState);
            break;
            case AUTH:
            auth.update(window, currentState);
            break;
            case LOGIN:
            login.update();
            break;
            case REGISTER:
            registration.update();
            break;
            case GAME:
            game.update();
            break;
        }
        window.clear();
        switch(currentState){
            case MENU:
            menu.render(window);
            break;
            case PROFILE:
            profile.render(window);
            break;
            case LEADERBOARD:
            leaderboard.render(window);
            break;
            case AUTH:
            auth.render(window);
            break;
            case LOGIN:
            login.render(window);
            break;
            case REGISTER:
            registration.render(window);
            break;
            case GAME:
            game.render(window);
        }
        window.display();
    }
}