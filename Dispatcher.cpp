#include "Dispatcher.hpp"

using namespace pandemic;
using namespace std;

Player& Dispatcher::fly_direct(City c) {
    if (this->board.board.at(currentCity).researchStation) {
        currentCity = c;
    }else{
        if (!cards[c]) {
            throw invalid_argument{"illegal action: you do not have the card of " + pandemic::printCity(c)};
        }
        cards[c] = false;
        colorfulCards.at(this->board.board.at(c).color)--;
        currentCity = c;
    }
    return *this;
}

std::string Dispatcher::role() {
    return type;
}
