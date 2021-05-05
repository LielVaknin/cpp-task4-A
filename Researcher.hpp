#pragma once

#include <string>
#include <utility>

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Researcher: public Player{
        std::string type = "Researcher";
    public:
        Researcher(Board& b,City c): Player(b,c){}

        Player& discover_cure(Color c) override;
        std::string role() override;
    };
}