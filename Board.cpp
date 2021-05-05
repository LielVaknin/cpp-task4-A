#include "Board.hpp"
#include <string>

using namespace std;
using namespace pandemic;

bool Board::is_clean() {
    for (auto const &city : board) {
        if (city.second.diseaseLevel > 0)
            return false;
    }
    return true;
}

int &Board::operator[](City city) {
    return board.at(city).diseaseLevel;
}

ostream &pandemic::operator<<(ostream &os, const Board &b) {
    for (auto const &city : b.board) {
        os << "City name: " + pandemic::printCity(city.first) + " Disease level: " +
              to_string(city.second.diseaseLevel) +
              "  Research station: " + pandemic::Board::castToBoolValue(city.second.researchStation) + "\n";
    }
    os << "Discovered cures: Blue - " + pandemic::Board::castToBoolValue(b.discoveredCuresInColors.at(Blue)) +
          " Yellow - " +
          pandemic::Board::castToBoolValue(b.discoveredCuresInColors.at(Yellow)) + " Black - " +
          pandemic::Board::castToBoolValue(b.discoveredCuresInColors.at(Black)) + " Red - " +
          pandemic::Board::castToBoolValue(b.discoveredCuresInColors.at(Red)) + "\n";
    return os;
}

string Board::castToBoolValue(bool b) {
    if (!b) {
        return "false";
    } else
        return "true";
}

void Board::remove_cures() {
    for (auto const &color : discoveredCuresInColors) {
        discoveredCuresInColors.at(color.first) = false;
    }
}

void Board::remove_stations() {
    for (auto const &city : board) {
        board.at(city.first).researchStation = false;
    }
}



