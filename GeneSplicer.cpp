#include "GeneSplicer.hpp"

using namespace pandemic;
using namespace std;

Player &GeneSplicer::discover_cure(Color c) {
    if (!this->board.board.at(currentCity).researchStation) {
        throw invalid_argument{"there is no research station!, you can not discover cure"};
    }
    int cardsTakenInAllColors = 0;
    for (auto const &color: colorfulCards) { // Counts the number of cards taken in all colors
        cardsTakenInAllColors += color.second;
    }
    if (colorfulCards.at(c) < 5 && cardsTakenInAllColors < 5) {
        throw invalid_argument{
                "illegal action: you only have " + to_string(cardsTakenInAllColors) + " cards remaining."};
    } else {
        if (!this->board.discoveredCuresInColors[c]) {
            int index = 0;
            int countsFiveCards = 0;
            for (auto const &city: this->board.board) {
                if (cards[index] && countsFiveCards < 5) {
                    cards[index] = false;
                    countsFiveCards++;
                    colorfulCards.at(city.second.color) -= 1;
                }
                index++;
            }
            this->board.discoveredCuresInColors.at(c) = true;
        }
    }
    return *this;
}

std::string GeneSplicer::role() {
    return type;
}
