#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include "h_files\class_blackjack.h"
#include "h_files\class_carddeck.h"
#include "h_files\class_dealer.h"
#include "h_files\class_player.h"

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
