#include "Researcher.hpp"

using namespace pandemic;
using namespace std;

Player &Researcher::discover_cure(Color c) {
    if (colorfulCards.at(c) < 5) {
        throw invalid_argument{
                "illegal action: you only have " + to_string(colorfulCards.at(c)) + " " + printColor(c) + " cards remaining."};
    }
    if (!this->board.discoveredCuresInColors[c]) {
        int index = 0;
        int countsFiveCards = 0;
        for (auto const &city: this->board.board) {
            if (city.second.color == c && cards[index] && countsFiveCards < 5) {
                cards[index] = false;
                countsFiveCards++;
            }
            index++;
        }
        colorfulCards.at(c) -= 5;
        this->board.discoveredCuresInColors.at(c) = true;
    }
    return *this;
}

std::string Researcher::role() {
    return type;
}
