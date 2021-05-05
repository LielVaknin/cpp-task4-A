#pragma once

#include <string>
#include <utility>
#include <array>
#include <vector>
#include <stdexcept>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

const int CARDS = 48;

namespace pandemic{
    class Player{

    protected:
        Board& board;
        City currentCity;
        bool cards[CARDS] = {false};
         std::map<pandemic::Color, int> colorfulCards{{Blue, 0}, {Yellow, 0}, {Black, 0}, {Red, 0}};

    public:
        Player(Board &b,City c): board(b),currentCity(c){}

        virtual Player& drive(City c);
        virtual Player& fly_direct(City c);
        virtual Player& fly_charter(City c);
        virtual Player& fly_shuttle(City c);
        virtual Player& build();
        virtual Player& discover_cure(Color c);
        virtual Player& treat(City c);
        virtual std::string role();
        Player& take_card(City c);
        void remove_cards();
    };
}