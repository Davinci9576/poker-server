#include "API.h"
#include "../BackEnd/player.h"
#include <curl/curl.h>
#include <string>
#include <iostream>
#include "../External/json.hpp"
using json = nlohmann::json;
using namespace std;

static size_t WriteCallback(
    void* contents,
    size_t size,
    size_t nmemb,
    std::string* output)
{
    output->append(
        (char*)contents,
        size * nmemb
    );

    return size * nmemb;
}
std::string ApiService::fetchLeaderboard(
    const std::string& type)
{
    CURL* curl = curl_easy_init();
    
    

    std::string response;

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        std::string url =
            "https://poker-backend-production-9635.up.railway.app/leaderboard" + type;

        curl_easy_setopt(
            curl,
            CURLOPT_URL,
            url.c_str()
        );

        curl_easy_setopt(
            curl,
            CURLOPT_WRITEFUNCTION,
            WriteCallback
        );

        curl_easy_setopt(
            curl,
            CURLOPT_WRITEDATA,
            &response
        );

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            std::cout
                << "ERROR: "
                << curl_easy_strerror(res)
                << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    return response;
}

std::vector<LeaderboardEntry> ApiService::getLeaderboard(const std::string& type){
    std::vector<LeaderboardEntry> players;
    std::string response=fetchLeaderboard(type);
    if(response.empty()){
        std::cout<<"Empty response!"<<std::endl;
        return players;
    }
    json data=json::parse(response);
    for(auto& player: data){
        LeaderboardEntry entry;
        entry.username=player["username"];
        entry.value=player["balance"];
        players.push_back(entry);
    }
    return players;
}

bool ApiService::registerUser(
    const std::string& username,
    const std::string& password)
{
    CURL* curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        std::string json =
            "{\"username\":\"" + username +
            "\",\"password\":\"" + password + "\"}";

        curl_easy_setopt(
            curl,
            CURLOPT_URL,
           "https://poker-backend-production-9635.up.railway.app/register"
        );

        curl_easy_setopt(
            curl,
            CURLOPT_POSTFIELDS,
            json.c_str()
        );

        struct curl_slist* headers = NULL;

        headers = curl_slist_append(
            headers,
            "Content-Type: application/json"
        );

        curl_easy_setopt(
            curl,
            CURLOPT_HTTPHEADER,
            headers
        );

        CURLcode res = curl_easy_perform(curl);

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);

        return (res == CURLE_OK);
    }

    return false;
}

LoginResponse ApiService::login(
    const std::string& username,
    const std::string& password)
{
    LoginResponse responseData;

    responseData.success = false;

    CURL* curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        std::string jsonData =
            "{\"username\":\"" + username +
            "\",\"password\":\"" + password + "\"}";

        std::string serverResponse;

        curl_easy_setopt(
            curl,
            CURLOPT_URL,
            "https://poker-backend-production-9635.up.railway.app/login"
        );

        curl_easy_setopt(
            curl,
            CURLOPT_POSTFIELDS,
            jsonData.c_str()
        );

        struct curl_slist* headers = NULL;

        headers = curl_slist_append(
            headers,
            "Content-Type: application/json"
        );

        curl_easy_setopt(
            curl,
            CURLOPT_HTTPHEADER,
            headers
        );

        // IMPORTANT PART
        curl_easy_setopt(
            curl,
            CURLOPT_WRITEFUNCTION,
            WriteCallback
        );

        curl_easy_setopt(
            curl,
            CURLOPT_WRITEDATA,
            &serverResponse
        );

        CURLcode res = curl_easy_perform(curl);

        if (res == CURLE_OK)
        {
            try
            {
                json responseJson =
                    json::parse(serverResponse);

                responseData.success =
                    responseJson["success"];

                if (responseData.success)
                {
                    responseData.username =
                        responseJson["username"];

                    responseData.balance =
                        responseJson["balance"];

                    responseData.wins =
                        responseJson["wins"];

                    responseData.losses =
                        responseJson["losses"];

                    responseData.winrate =
                        responseJson["winrate"];
                }
            }
            catch (...)
            {
                responseData.success = false;
            }
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    return responseData;
}
void ApiService::updateProgress(const Player& player)
{
    CURL* curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        string json =
            "{"
            "\"username\":\"" + player.getUsername() + "\","
            "\"balance\":" + to_string(player.getBalance()) + ","
            "\"wins\":" + to_string(player.getWins()) + ","
            "\"losses\":" + to_string(player.getLosses()) + ","
            "\"winrate\":" + to_string(player.getWinrate()) +
            "}";

        curl_easy_setopt(
            curl,
            CURLOPT_URL,
            "https://poker-backend-production-9635.up.railway.app/updateProgress"
        );

        curl_easy_setopt(
            curl,
            CURLOPT_POSTFIELDS,
            json.c_str()
        );

        struct curl_slist* headers = NULL;

        headers = curl_slist_append(
            headers,
            "Content-Type: application/json"
        );


        curl_easy_setopt(
            curl,
            CURLOPT_HTTPHEADER,
            headers
        );

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            cout << "Update failed!" << endl;
        }
        else
        {
            cout << "Progress updated!" << endl;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
}