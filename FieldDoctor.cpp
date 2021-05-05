#include "FieldDoctor.hpp"

using namespace pandemic;
using namespace std;

Player &FieldDoctor::treat(City c) {
    if (this->board.board.at(c).diseaseLevel == 0) {
        throw invalid_argument{"illegal action: no more cubes remain in " + pandemic::printCity(c)};
    }
    vector<City> vec = this->board.board.at(this->currentCity).cityNeighbours;
    auto it = find(vec.begin(), vec.end(), c);
    if (it == vec.end() && c != currentCity) {
        throw invalid_argument{"illegal action: " + printCity(c) + " is not connected / equals to " + printCity(currentCity)};
    } else {
        if (this->board.discoveredCuresInColors.at(this->board.board.at(c).color)) {
            this->board.board.at(c).diseaseLevel = 0;
        } else {
            this->board.board.at(c).diseaseLevel--;
        }
    }
    return *this;
}

std::string FieldDoctor::role() {
    return type;
}
