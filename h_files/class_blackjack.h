#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#pragma once


class Blackjack
{
public:
    int Amount_of_Players;
    player *players = new player[Amount_of_Players];
    int Number_of_Decks;

    void initialisation_amount_of_players();
    
    void give_names();

    void initialisation_number_of_decks();

    void play();
};
