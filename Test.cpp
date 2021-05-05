#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Scientist.hpp"
#include "Researcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include "GeneSplicer.hpp"
#include "FieldDoctor.hpp"

using namespace pandemic;
using namespace std;

TEST_CASE ("Test for all different players") {
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
    board[City::HongKong] = 3;      // put 3 red disease cubes in HongKong.
    board[City::HongKong] = 2;      // change number of disease cubes in HongKong to 2.
    board[City::LosAngeles] = 4;    // put 4 yellow disease cubes in LosAngeles.
    board[City::Milan] = 1; // put 1 blue disease cube in Milan.
    board[City::Madrid] = 1;       // put 1 blue disease cube in Madrid.
    board[City::Sydney] = 2;       // put 2 red disease cubes in Sydney.

    OperationsExpert operations_expert{board, City::HongKong}; // Red city
            CHECK(operations_expert.role() == "OperationsExpert");
    Dispatcher dispatcher{board, City::Bangkok}; // Red city
            CHECK(dispatcher.role() == "Dispatcher");
    Scientist scientist{board, City::Shanghai, 2}; // Red city
            CHECK(scientist.role() == "Scientist");
    Researcher researcher{board, City::Madrid}; // Blue city
            CHECK(researcher.role() == "Researcher");
    Medic medic{board, City::Milan}; // Blue city
            CHECK(medic.role() == "Medic");
    Virologist virologist{board, City::Miami}; // Yellow city
            CHECK(virologist.role() == "Virologist");
    GeneSplicer geneSplicer{board, City::Santiago}; // Yellow city
            CHECK(geneSplicer.role() == "GeneSplicer");
    FieldDoctor fieldDoctor{board, City::LosAngeles}; // Yellow city
            CHECK(fieldDoctor.role() == "FieldDoctor");

    operations_expert.take_card(Jakarta).take_card(HoChiMinhCity).take_card(Beijing); // Takes 3 red cards
    operations_expert.build(); // Builds research station in HongKong
            CHECK(board.board.at(HongKong).researchStation == true); // OperationsExpert can build a research station without the card of HongKong
    operations_expert.remove_cards();

    CHECK_THROWS(dispatcher.drive(LosAngeles)); // LosAngeles is not connected to Bangkok
    CHECK_NOTHROW(dispatcher.drive(HongKong)); // HongKong is connected to Bangkok, now dispatcher is in a city with a research station
    CHECK_NOTHROW(dispatcher.fly_direct(London)); // Dispatcher can perform a "fly direct" operation without the card of London

    CHECK_NOTHROW(operations_expert.drive(Shanghai)); // HongKong is connected to Shanghai
    operations_expert.build(); // Builds research station in Shanghai
    scientist.take_card(Seoul); // Takes 1 red card
    CHECK_THROWS(scientist.discover_cure(Red)); // Can not discover cure with 1 red card
    scientist.take_card(Tokyo); // Takes 1 more red card - now there are 2 red cards
    CHECK_NOTHROW(scientist.discover_cure(Red)); // Can discover cure with n=2 red cards
    scientist.remove_cards();

    researcher.take_card(Atlanta).take_card(Chicago).take_card(Essen).take_card(Milan).take_card(Montreal); // Takes 5 blue cards
    CHECK_NOTHROW(researcher.discover_cure(Blue)); // Can discover cure with 5 blue cards and without being in a city with a research station
    researcher.remove_cards();

    CHECK_NOTHROW(medic.treat(Milan));
    CHECK(board.board.at(Milan).diseaseLevel == 0); // There is a blue cure so diseaseLevel in Milan is 0 now
    board[City::Atlanta] = 3;
    board[City::Chicago] = 4;
    board[City::Essen] = 5;
    board[City::Milan] = 2;
    medic.take_card(Atlanta).take_card(Chicago).take_card(Essen).take_card(Milan).take_card(Montreal); // Takes 5 blue cards
    CHECK_NOTHROW(medic.drive(Essen));
    CHECK(board.board.at(Essen).diseaseLevel == 0); // There is a blue cure so diseaseLevel in Essen is 0 now
    CHECK_NOTHROW(medic.fly_direct(Chicago));
    CHECK(board.board.at(Chicago).diseaseLevel == 0); // There is a blue cure so diseaseLevel in Chicago is 0 now
    medic.take_card(Chicago);
    CHECK_NOTHROW(medic.fly_charter(Atlanta));
    CHECK(board.board.at(Atlanta).diseaseLevel == 0); // There is a blue cure so diseaseLevel in Atlanta is 0 now
    operations_expert.take_card(Milan).take_card(Atlanta);
    operations_expert.fly_direct(Milan);
    operations_expert.build();
    operations_expert.fly_direct(Atlanta);
    operations_expert.build();
    CHECK_NOTHROW(medic.fly_shuttle(Milan)); // There is a research station in Atlanta (current city) and in Milan
    CHECK(board.board.at(Milan).diseaseLevel == 0); // There is a blue cure so diseaseLevel in Milan is 0 now
    medic.remove_cards();
    operations_expert.remove_cards();

    virologist.take_card(Madrid);
    CHECK_NOTHROW(virologist.treat(Madrid)); // Can perform "treat" operation in any city in the world by throwing the card of this city
    virologist.remove_cards();

    geneSplicer.take_card(Mumbai).take_card(Chicago).take_card(Essen).take_card(MexicoCity).take_card(Montreal).take_card(Shanghai);
    CHECK_NOTHROW(geneSplicer.fly_direct(Shanghai)); // Fly to Shanghai - a city with a research station, by throwing the card of Shanghai
    CHECK_NOTHROW(geneSplicer.discover_cure(Red)); // Can discover cure with 5 cards of different colors (not only of the disease's color)
    CHECK(board.discoveredCuresInColors.at(Red) == true);
    geneSplicer.remove_cards();

    CHECK_THROWS(fieldDoctor.treat(London)); // London is not connected / equals to LosAngeles
    CHECK_NOTHROW(fieldDoctor.treat(Sydney)); // Sydney is connected to LosAngeles
    CHECK(board.board.at(Sydney).diseaseLevel == 0); // DiseaseLevel in Sydney is 0 now because there is a cure for red disease already
}

