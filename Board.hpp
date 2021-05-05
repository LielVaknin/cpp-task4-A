#pragma once

#include <map>
#include <utility>
#include <vector>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    struct Parameters {
        std::vector<City> cityNeighbours;
        Color color;
        int diseaseLevel = 0;
        bool researchStation = false;
        explicit Parameters(std::vector<City> cityNeighbours, Color c) : cityNeighbours(std::move(cityNeighbours)), color(c){}
    };

    class Board{
    public:
        std::map<Color, bool> discoveredCuresInColors = {{Color::Blue, false}, {Color::Red, false}, {Color::Black, false}, {Color::Yellow, false}};
        std::map<City,struct Parameters> board = {
                {City::Algiers, Parameters({City::Madrid, City::Paris, City::Istanbul, City::Cairo}, Black)},
                {City::Atlanta, Parameters({City::Chicago, City::Miami , City::Washington}, Blue)},
                {City::Baghdad, Parameters({City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi}, Black)},
                {City::Bangkok, Parameters({City::Kolkata ,City::Chennai, City::Jakarta ,City::HoChiMinhCity, City::HongKong}, Red)},
                {City::Beijing, Parameters({City::Shanghai, City::Seoul}, Red)},
                {City::Bogota,  Parameters({City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}, Yellow)},
                {City::BuenosAires, Parameters({City::Bogota, City::SaoPaulo}, Yellow)},
                {City::Cairo,Parameters({City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}, Black)},
                {City::Chennai, Parameters({City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}, Black)},
                {City::Chicago, Parameters({City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}, Blue)},
                {City::Delhi, Parameters({City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata}, Black)},
                {City::Essen, Parameters({City::London, City::Paris, City::Milan, City::StPetersburg}, Blue)},
                {City::HoChiMinhCity, Parameters({City::Jakarta, City::Bangkok, City::HongKong, City::Manila}, Red)},
                {City::HongKong, Parameters({City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}, Red)},
                {City::Istanbul, Parameters({City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}, Black)},
                {City::Jakarta, Parameters({City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}, Red)},
                {City::Johannesburg, Parameters({City::Kinshasa, City::Khartoum}, Yellow)},
                {City::Karachi, Parameters({City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi}, Black)},
                {City::Khartoum, Parameters({City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}, Yellow)},
                {City::Kinshasa, Parameters({City::Lagos, City::Khartoum, City::Johannesburg}, Yellow)},
                {City::Kolkata, Parameters({City::Delhi, City::Chennai, City::Bangkok, City::HongKong}, Black)},
                {City::Lagos, Parameters({City::SaoPaulo, City::Khartoum, City::Kinshasa}, Yellow)},
                {City::Lima, Parameters({City::MexicoCity, City::Bogota, City::Santiago}, Yellow)},
                {City::London, Parameters({City::NewYork, City::Madrid, City::Essen, City::Paris}, Blue)},
                {City::LosAngeles, Parameters({City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney}, Yellow)},
                {City::Madrid, Parameters({City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers},Blue)},
                {City::Manila, Parameters({City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney}, Red)},
                {City::MexicoCity, Parameters({City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota}, Yellow)},
                {City::Miami, Parameters({City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}, Yellow)},
                {City::Milan, Parameters({City::Essen, City::Paris, City::Istanbul},Blue)},
                {City::Montreal, Parameters({City::Chicago, City::Washington, City::NewYork}, Blue)},
                {City::Moscow, Parameters({City::StPetersburg, City::Istanbul, City::Tehran}, Black)},
                {City::Mumbai, Parameters({City::Karachi, City::Delhi, City::Chennai}, Black)},
                {City::NewYork, Parameters({City::Montreal, City::Washington, City::London, City::Madrid}, Blue)},
                {City::Osaka, Parameters({City::Taipei, City::Tokyo}, Red)},
                {City::Paris, Parameters({City::Algiers, City::Essen, City::Madrid, City::Milan, City::London}, Blue)},
                {City::Riyadh, Parameters({City::Baghdad, City::Cairo, City::Karachi}, Black)},
                {City::SanFrancisco, Parameters({City::LosAngeles, City::Chicago, City::Tokyo, City::Manila},Blue)},
                {City::Santiago, Parameters({City::Lima}, Yellow)},
                {City::SaoPaulo, Parameters({City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}, Yellow)},
                {City::Seoul, Parameters({City::Beijing, City::Shanghai, City::Tokyo}, Red)},
                {City::Shanghai, Parameters({City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}, Red)},
                {City::StPetersburg, Parameters({City::Essen, City::Istanbul, City::Moscow}, Blue)},
                {City::Sydney, Parameters({City::Jakarta, City::Manila, City::LosAngeles}, Red)},
                {City::Taipei, Parameters({City::Shanghai, City::HongKong, City::Osaka, City::Manila}, Red)},
                {City::Tehran, Parameters({City::Baghdad, City::Moscow, City::Karachi, City::Delhi}, Black)},
                {City::Tokyo, Parameters({City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}, Red)},
                {City::Washington, Parameters({City::Atlanta, City::NewYork, City::Montreal, City::Miami}, Blue)}
        };

        bool is_clean();
        int& operator[](City city);
        friend std::ostream& operator<< (std::ostream& os, const Board& b);
        static std::string castToBoolValue(bool b);
        void remove_cures();
        void remove_stations();
    };
}