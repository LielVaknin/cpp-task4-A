#pragma once

#include <string>
#include <utility>
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Medic: public Player{
        std::string type = "Medic";
    public:
        Medic(Board& b,City c): Player(b,c){}

        Player& treat(City c) override;
        Player& drive(City c) override;
        Player& fly_direct(City c) override;
        Player& fly_charter(City c) override;
        Player& fly_shuttle(City c) override;
        std::string role() override;
    };
}