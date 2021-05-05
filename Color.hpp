#pragma once

namespace pandemic{
    enum Color {
        Blue,
        Yellow,
        Black,
        Red
    };

    inline std::string printColor(Color c){
        std::string color;
        switch (c) {
            case Blue:
                color = "Blue";
                break;
            case Yellow:
                color = "Yellow";
                break;
            case Black:
                color = "Black";
                break;
            case Red:
                color = "Red";
                break;
        }
        return color;
    }
}