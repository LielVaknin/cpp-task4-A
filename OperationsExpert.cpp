#include "OperationsExpert.hpp"

using namespace pandemic;
using namespace std;

Player& OperationsExpert::build() {
    this->board.board.at(currentCity).researchStation = true;
    return *this;
}

std::string OperationsExpert::role() {
    return type;
}
