#include <iostream>
#include "class_blackjack.h"
#include "class_carddeck.h"
#include "class_dealer.h"
#include "class_player.h"

void carddeck::set_number_of_decks(int number)
{
    finaldeck = {}; 
    number_of_decks = number;
    for (int i = 0; i < number; i++)
    {
        finaldeck.insert(finaldeck.end(), carddeck.begin(), carddeck.end());
    }
    remaining_cards = deck_size * number_of_decks;
}

int carddeck::draw_card()
{
    int temp = 0; // variable where the card will be stored

    if (remaining_cards > 0)
    {                                            // check if there are cards in the deck
        int position = rand() % remaining_cards; // randomly choose the position in the deck
        temp = finaldeck[position];              // find the card

        finaldeck[position] = finaldeck[remaining_cards - 1]; // put the card at the end of the deck on the position of the drawn card
        finaldeck[remaining_cards - 1] = temp;                // put the drawn card at the end of the deck

        remaining_cards--;                 // number of cards decreases by 1
        finaldeck.resize(remaining_cards); // size of the deck decreases by 1
    }
    else
    {
        std::cout << "There are no cards left in the deck" << std::endl; // if there are no cards left give message
    }

    if (remaining_cards < 10)
    { // if there are less than 10 cards make sure a new deck is generated of
        std::cout << "Only " << remaining_cards << " were left in the deck, therefore we start with 1 deck of cards again" << std::endl;
        set_number_of_decks(1);
    }

    return temp; // return the drawn card
}