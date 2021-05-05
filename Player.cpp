#include "Player.hpp"

using namespace std;
using namespace pandemic;

Player &Player::drive(City c) {
    vector<City> vec = this->board.board.at(this->currentCity).cityNeighbours;
    auto it = find(vec.begin(), vec.end(), c);
    if (it == vec.end()) {
        throw invalid_argument{
                " illegal action: " + pandemic::printCity(c) + " is not connected to " + pandemic::printCity(currentCity)};
    }
    currentCity = c;
    return *this;
}

Player &Player::fly_direct(City c) {
    if (!cards[c]) {
        throw invalid_argument{"illegal action: you do not have the card of " + pandemic::printCity(c)};
    }
    cards[c] = false;
    colorfulCards.at(this->board.board.at(c).color)--;
    currentCity = c;
    return *this;
}

Player &Player::fly_charter(City c) {
    if (!cards[currentCity]) {
        throw invalid_argument{"illegal action: you do not have the " + pandemic::printCity(currentCity) +
                               " card (the card of the city you are in)."};
    }
    cards[currentCity] = false;
    colorfulCards.at(this->board.board.at(currentCity).color)--;
    currentCity = c;
    return *this;
}

Player &Player::fly_shuttle(City c) {
    if (!this->board.board.at(c).researchStation) {
        throw invalid_argument{"illegal action: there is no research station in " + pandemic::printCity(c)};
    }
    if (!this->board.board.at(currentCity).researchStation) {
        throw invalid_argument{"illegal action: there is no research station in " + pandemic::printCity(currentCity)};
    }
    if (this->board.board.at(currentCity).researchStation && this->board.board.at(c).researchStation) {
        currentCity = c;
    }
    return *this;
}

Player &Player::build() {
    if (!this->board.board.at(currentCity).researchStation && cards[currentCity]) {
        this->board.board.at(currentCity).researchStation = true;
        cards[currentCity] = false;
        colorfulCards.at(this->board.board.at(currentCity).color)--;
    }
    return *this;
}

Player &Player::discover_cure(Color c) {
    if (colorfulCards.at(c) < 5) {
        throw invalid_argument{
                "illegal action: you only have " + to_string(colorfulCards.at(c)) + " " + printColor(c) + " cards remaining."};
    }
    if (!this->board.board.at(currentCity).researchStation) {
        throw invalid_argument{"there is no research station!, you can not discover cure"};
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

Player &Player::treat(City c) {
    if (c != currentCity) {
        throw invalid_argument{"illegal action: you are not in " + pandemic::printCity(c)};
    }
    if (this->board.board.at(c).diseaseLevel == 0) {
        throw invalid_argument{"illegal action: no more cubes remain in " + pandemic::printCity(c)};
    }
    if (this->board.discoveredCuresInColors.at(this->board.board.at(c).color)) {
        this->board.board.at(currentCity).diseaseLevel = 0;
    } else {
        this->board.board.at(c).diseaseLevel--;
    }
    return *this;
}

std::string Player::role() {
    return " ";
}

Player &Player::take_card(City c) {
    if (!cards[c]) {
        cards[c] = true;
        colorfulCards.at(this->board.board.at(c).color)++;
    }
    return *this;
}

void Player::remove_cards() {
    for (auto const &card : cards) {
        cards[card] = false;
    }
    for (auto const &color: colorfulCards) {
        colorfulCards.at(color.first) = 0;
    }
}












