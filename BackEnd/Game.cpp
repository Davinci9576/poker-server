#include "Game.h"
#include <iostream>
#include "../API/API.h"

using namespace std;

Game::Game(Player& p) : player(p) {}

void Game::startRound() {
    player.clearHand();
    dealer.clearHand();
    communityCards.clear();

    deck.cardBuild();
    deck.shuffleDeck();
    dealHoleCards();
    player.ResetTotalBet();

}
void Game::nextStage(){
    if(communityCards.size()==0){
        dealFlop();
    }else if(communityCards.size()==3){
        dealTurn();
    }else if(communityCards.size()==4){
        dealRiver();
    }else if(communityCards.size()==5){
       showdown();
    }
}
std::string Game ::foldLost(){
    success="Dealer Won!";
    return success;
}
void Game ::refreshResult(){
    success="";
}
std::string Game::results(){
    return success;
}
void Game::showdown(){
    
    ApiService api;
    auto playerResult = HandEvaluator::evaluate(player.getHand(), communityCards);
    auto dealerResult = HandEvaluator::evaluate(dealer.getHand(), communityCards);

    int result = CompareHands(playerResult, dealerResult);

    player.subtractBalance();

    if (result > 0) {
        player.addBalance();
        player.addWins();
        api.updateProgress(player);
        success="You won!";
    } else if (result < 0) {
        player.addLosses();
        api.updateProgress(player);
        success="Dealer won!";
    } else {
        player.PerfectTie();
        api.updateProgress(player);
        success="Tie!";
    }
    player.GetWinrate();
}



int Game::CompareHands(const HandEvaluator::HandResult& a,
                       const HandEvaluator::HandResult& b) {

    if (a.rank > b.rank) return 1;
    if (b.rank > a.rank) return -1;

    for (size_t i = 0; i < a.values.size(); i++) {
        if (a.values[i] > b.values[i]) return 1;
        if (b.values[i] > a.values[i]) return -1;
    }

    return 0;
}

void Game::dealHoleCards() {
    for (int i = 0; i < 2; i++) {
        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());
    }
}

void Game::dealFlop() {
    for (int i = 0; i < 3; i++) {
        communityCards.push_back(deck.dealCard());
    }
}

void Game::dealTurn() {
    communityCards.push_back(deck.dealCard());
}

void Game::dealRiver() {
    communityCards.push_back(deck.dealCard());
}
void Game::Raise(double amount) {
    player.increaseBet(amount);
}

void Game::fold(){
    ApiService api;
    player.addLosses();
    api.updateProgress(player);
}

std::vector<Card> Game::getPlayerHand(){
    return player.getHand();
}
std::vector<Card> Game::getDealerHand(){
    return dealer.getHand();
}

double Game::getBalance(){
    return player.getBalance();
}

std::vector<Card> Game::getCommunityCards(){
    return communityCards;
}
std::string Game::getUsername(){
    return player.UsernameGive();
}