#pragma once

#include <string>

namespace pandemic {
    enum City {
        Algiers,
        Atlanta,
        Baghdad,
        Bangkok,
        Beijing,
        Bogota,
        BuenosAires,
        Cairo,
        Chennai,
        Chicago,
        Delhi,
        Essen,
        HoChiMinhCity,
        HongKong,
        Istanbul,
        Jakarta,
        Johannesburg,
        Karachi,
        Khartoum,
        Kinshasa,
        Kolkata,
        Lagos,
        Lima,
        London,
        LosAngeles,
        Madrid,
        Manila,
        MexicoCity,
        Miami,
        Milan,
        Montreal,
        Moscow,
        Mumbai,
        NewYork,
        Osaka,
        Paris,
        Riyadh,
        SanFrancisco,
        Santiago,
        SaoPaulo,
        Seoul,
        Shanghai,
        StPetersburg,
        Sydney,
        Taipei,
        Tehran,
        Tokyo,
        Washington
    };

   inline std::string printCity(City c){
        std::string city;
        switch (c) {
            case Algiers :
                city = "Algiers";
                break;
            case Atlanta:
                city = "Atlanta";
                break;
            case Baghdad:
                city = "Baghdad";
                break;
            case Bangkok:
                city = "Bangkok";
                break;
            case Beijing:
                city = "Beijing";
                break;
            case Bogota:
                city = "Bogota";
                break;
            case BuenosAires:
                city = "BuenosAires";
                break;
            case Cairo:
                city = "Cairo";
                break;
            case Chennai:
                city = "Chennai";
                break;
            case Chicago:
                city = "Chicago";
                break;
            case Delhi:
                city = "Delhi";
                break;
            case Essen:
                city = "Essen";
                break;
            case HoChiMinhCity:
                city = "HoChiMinhCity";
                break;
            case HongKong:
                city = "HongKong";
                break;
            case Istanbul:
                city = "Istanbul";
                break;
            case Jakarta:
                city = "Jakarta";
                break;
            case Johannesburg:
                city = "Johannesburg";
                break;
            case Karachi:
                city = "Karachi";
                break;
            case Khartoum:
                city = "Khartoum";
                break;
            case Kinshasa:
                city = "Kinshasa";
                break;
            case Kolkata:
                city = "Kolkata";
                break;
            case Lagos:
                city = "Lagos";
                break;
            case Lima:
                city = "Lima";
                break;
            case London:
                city = "London";
                break;
            case LosAngeles:
                city = "LosAngeles";
                break;
            case Madrid:
                city = "Madrid";
                break;
            case Manila:
                city = "Manila";
                break;
            case MexicoCity:
                city = "MexicoCity";
                break;
            case Miami:
                city = "Miami";
                break;
            case Milan:
                city = "Milan";
                break;
            case Montreal:
                city = "Montreal";
                break;
            case Moscow:
                city = "Moscow";
                break;
            case Mumbai:
                city = "Mumbai";
                break;
            case NewYork:
                city = "NewYork";
                break;
            case Osaka:
                city = "Osaka";
                break;
            case Paris:
                city = "Paris:";
                break;
            case Riyadh:
                city = "Riyadh";
                break;
            case SanFrancisco:
                city = "SanFrancisco";
                break;
            case Santiago:
                city = "Santiago";
                break;
            case SaoPaulo:
                city = "SaoPaulo";
                break;
            case Seoul:
                city = "Seoul";
                break;
            case Shanghai:
                city = "Shanghai";
                break;
            case StPetersburg:
                city = "StPetersburg";
                break;
            case Sydney:
                city = "Sydney";
                break;
            case Taipei:
                city = "Taipei";
                break;
            case Tehran:
                city = "Tehran";
                break;
            case Tokyo:
                city = "Tokyo";
                break;
            case Washington:
                city = "Washington";
                break;
        }
        return city;
    }
}