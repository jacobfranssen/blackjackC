#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include <string>

class Blackjack
{
public:
    int Amount_of_Players = 4;
    int Number_of_Decks;

    game(){
        std::vector<std::string> players[Amount_of_Players];
    }

    void initialisation_amount_of_players();

    void resize();
    
    void give_names();

    void initialisation_number_of_decks();

    void play();
};

//constructor
//preset amount of players
//make players a vector
