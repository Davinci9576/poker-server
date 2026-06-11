#pragma once

#include "Deck.h"
#include "Player.h"
#include "HandEvaluator.h"
#include <vector>
#include <string>

class Game {
private:

    Deck deck;
    Player& player;
    Player dealer;
    std::vector<Card> communityCards;

    int CompareHands(const HandEvaluator::HandResult& a,
                     const HandEvaluator::HandResult& b);
public:
    int choice;
    void dealHoleCards();
    void dealFlop();
    void dealTurn();
    void dealRiver();
    void fold();
    void showdown();
    void Raise(double amount);
    void nextStage();
    std::vector<Card> getPlayerHand();
    std::vector<Card> getDealerHand();
    double getBalance();
    std::vector<Card> getCommunityCards();
    Game(Player& p);
    std::string getUsername();
    std::string success="";
    std::string results();
    std::string foldLost();
    void refreshResult();


    void startRound();
};