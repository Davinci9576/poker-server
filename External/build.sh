g++ *.cpp -lcurl -o game
./game.exe-UCRT/bash
.\game.exe powershell
node server.js
g++ sfml_test.cpp -o sfml_test.exe -lsfml-graphics -lsfml-window -lsfml-system
 ./sfml_test.exe
 g++ *.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system -lcurl


 g++ Source/main.cpp Core/Application.cpp Screens/MenuScreen.cpp Screens/ProfileScreen.cpp Screens/LeaderBoardScreen.cpp Screens/AuthScreen.cpp Screens/LoginScreen.cpp Screens/RegisterScreen.cpp BackEnd/Player.cpp BackEnd/card.cpp -o poker -lsfml-graphics -lsfml-window -lsfml-system
 g++ Source/main.cpp Core/Application.cpp Screens/MenuScreen.cpp Screens/ProfileScreen.cpp Screens/LeaderBoardScreen.cpp Screens/AuthScreen.cpp Screens/LoginScreen.cpp Screens/RegisterScreen.cpp BackEnd/Player.cpp BackEnd/card.cpp BackEnd/Deck.cpp BackEnd/Game.cpp BackEnd/HandEvaluator.cpp API/API.cpp -o poker -lsfml-graphics -lsfml-window -lsfml-system -lcurl

 g++ Source/*.cpp Core/*.cpp Screens/*.cpp BackEnd/*.cpp API/*.cpp -o poker -lsfml-graphics -lsfml-window -lsfml-system -lcurl
 g++ Source/*.cpp Core/*.cpp Screens/*.cpp BackEnd/*.cpp API/*.cpp -o poker -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lcurl