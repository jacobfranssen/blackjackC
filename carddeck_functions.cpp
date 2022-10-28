#include <iostream>
#include "class_blackjack.h"
#include "class_carddeck.h"
#include "class_dealer.h"
#include "class_player.h"

void carddeck::set_number_of_decks(int number)
{
    number_of_decks = number;
    for (int i = 0; i < number; i++)
    {
        finaldeck.insert(finaldeck.end(), carddeck.begin(), carddeck.end());
    }
    remaining_cards = remaining_cards * number_of_decks;
}

int carddeck::draw_card()
{
    int temp = 0;

    if (remaining_cards > 0)
    {
        int position = rand() % remaining_cards;
        temp = finaldeck[position]; // drawn card

        finaldeck[position] = finaldeck[remaining_cards - 1];
        finaldeck[remaining_cards - 1] = temp;

        // std::cout << temp << std::endl;
        remaining_cards--;
        finaldeck.resize(remaining_cards);
    }
    return temp;
}