#pragma once
#include <string>
#include <vector>
struct LoginResponse{
    bool success;
    std::string username;
    double balance;
    int wins;
    int losses;
    double winrate;
};
struct LeaderboardEntry{
    std::string username;
    int value;
};

class Player;
class ApiService
{
    public:
    LoginResponse login(const std:: string& username, const std::string & password);
    void sendScore(const Player& player);
    std::string fetchLeaderboard(const std::string&type);
    bool registerUser(
        const std::string& username,
        const std::string& password
    );
    void updateProgress(const Player& player);
    std::vector<LeaderboardEntry> getLeaderboard(const std::string& type);
};