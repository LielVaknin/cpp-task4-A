#include "Virologist.hpp"
#include <stdexcept>

using namespace pandemic;
using namespace std;

Player& Virologist::treat(City c) {
    if (this->board.board.at(c).diseaseLevel == 0) {
        throw invalid_argument{"illegal action: no more cubes remain in " + pandemic::printCity(c)};
    }
    if (this->board.discoveredCuresInColors.at(this->board.board.at(c).color) && c == currentCity) {
        this->board.board.at(currentCity).diseaseLevel = 0;
    } else if(!this->board.discoveredCuresInColors.at(this->board.board.at(c).color) && c == currentCity){
        this->board.board.at(c).diseaseLevel--;
    }else if(this->board.discoveredCuresInColors.at(this->board.board.at(c).color) && c != currentCity && cards[c]){
        cards[c] = false;
        colorfulCards.at(this->board.board.at(c).color)--;
        this->board.board.at(currentCity).diseaseLevel = 0;
    } else if(!this->board.discoveredCuresInColors.at(this->board.board.at(c).color) && c != currentCity && cards[c]){
        cards[c] = false;
        colorfulCards.at(this->board.board.at(c).color)--;
        this->board.board.at(c).diseaseLevel--;
    }else{
        throw invalid_argument{"illegal action: you do not have the card of " + pandemic::printCity(c)};
    }
    return *this;
}

std::string Virologist::role() {
    return type;
}


