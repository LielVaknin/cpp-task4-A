#pragma once

#include <string>
#include <utility>
#include <vector>
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class FieldDoctor: public Player{
        std::string type = "FieldDoctor";
    public:
        FieldDoctor(Board& b,City c): Player(b,c){}

        Player& treat(City c) override;
        std::string role() override;
    };
}