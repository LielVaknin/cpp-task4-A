#pragma once

#include <string>
#include <utility>
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Scientist : public Player{
        std::string type = "Scientist";
        int n;
    public:
        Scientist(Board& b,City c,int n): Player(b,c), n(n){}

        Player& discover_cure(Color c) override;
        std::string role() override;
    };
}