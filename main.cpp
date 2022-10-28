#include <iostream>
#include <string>
#include <vector>
#include "class_player.h"
#include "class_carddeck.h"
#include "class_dealer.h"
#include "class_blackjack.h"

//g++ main.cpp blackjack_functions.cpp dealer_functions.cpp carddeck_functions.cpp player_functions.cpp

int main()
{
    Blackjack game;

    game.initialisation_amount_of_players(); // This function gets the amount of players from the user.

    game.resize();

    game.give_names();

    game.initialisation_number_of_decks(); // This line obtains the amount of decks that will be used.

    // THE GAME STARTS HERE!
    game.play();

    return 0;
}
