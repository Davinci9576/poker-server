#include "player.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <curl/curl.h>
#include <string>
#include <sstream>
#include "Card.h"

using namespace std;

Player::Player(double startingBalance) {
    balance = startingBalance;
    wins = 0;
    losses = 0;
    winrate = 0;
    CurrentBet = 0;
    TotalBet = 50;
    username = "";
    pass = "";
}

Player::Player(string name, string password, double Balance) {
    username = name;
    pass = password;
    balance = Balance;
    wins = 0;
    losses = 0;
    winrate = 0;
    CurrentBet = 0;
    TotalBet = 50;
}

// ================== GAME LOGIC ==================
void Player::setter(const string& newusername, double newbalance, int newwins, int newlosses, double newwinrate, string newpass){
    username=newusername;
    balance=newbalance;
    wins=newwins;
    losses=newlosses;
    winrate=newwinrate;
    pass=newpass;
}
void Player::addCard(Card c) {
    hand.push_back(c);
}

void Player::PerfectTie() {
    balance += TotalBet;
}

void Player::clearHand() {
    hand.clear();
}

void Player:: DefaultBet(){
    balance-=50;
}
void Player::increaseBet(double extraBet) {
    CurrentBet += extraBet;
    balance -= extraBet;
    TotalBet += CurrentBet;
}

double Player::getBalance() const {
    return balance;
}
string Player::getUsername() const{
    return username;
}
int Player::getWins() const{
    return wins;
}
int Player::getLosses() const{
    return losses;
}
double Player::getWinrate() const{
    return winrate;
}

void Player::addBalance() {
    balance += (TotalBet * 2);
}

void Player::subtractBalance() {
    balance -= 50;
}

void Player::addWins() {
    wins++;
}

void Player::addLosses() {
    losses++;
}

void Player::GetWinrate() {
    if ((wins + losses) == 0) {
        winrate = 0;
    } else {
        winrate = ((double)wins / (wins + losses)) * 100;
    }
}

void Player::ResetCurrentBet() {
    CurrentBet = 0;
}

void Player::ResetTotalBet() {
    TotalBet = 50;
}
double Player::WinrateGive(){
    return winrate;
}
int Player:: WinsGive(){
    return wins;
}
int Player::LossesGive(){
    return losses;
}
string Player::UsernameGive(){
    return username;
}
double Player::BalanceGive(){
    return balance;
}


void Player::gameOver() {
    addLosses();
}

vector<Card> Player::getHand() {
    return hand;
}