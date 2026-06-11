#pragma once
#include <string>

struct Card {
    int value;
    int suit;

    std::string getImageName() const;
};
