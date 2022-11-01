#ifndef CLASS_BLACKJACK
#define CLASS_BLACKJACK

#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include <string>
#include "class_player.h"

// class were all functions and variables nessecarry for the game are stored

class Blackjack
{
public:
    int Amount_of_Players = 0;
    int Number_of_Decks;
    std::vector<player> players;

    void initialisation_amount_of_players();

    void resize();

    void give_names();

    void initialisation_number_of_decks();

    std::string raise_question_user_extra_card(std::string Pos_answer_1, std::string Pos_answer_2, std::string player_name);

    void play();
};

#endif
