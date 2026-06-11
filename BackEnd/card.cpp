#include "card.h"
#include <string>
using namespace std;

string Card::getImageName() const
{
    string suitStr;
    if(suit==1) suitStr= "spades";
    else if(suit==2) suitStr= "hearts";
    else if(suit==3) suitStr= "diamonds";
    else if(suit==4) suitStr= "clubs";

    string valueStr;
    if(value==1) valueStr="A";
    else if(value==11) valueStr="J";
    else if(value==12) valueStr="Q";
    else if(value==13) valueStr="K";
    else if(value<10){
        valueStr="0"+std::to_string(value);
    }else {
        valueStr=std::to_string(value);
    }
    return "card_"+suitStr+"_"+valueStr;
}