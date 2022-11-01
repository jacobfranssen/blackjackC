#ifndef CLASS_CARDDECK
#define CLASS_CARDDECK

#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>

class carddeck{
                                            // This class represents the cards that will be used during the game.
public:
    int number_of_decks;                    // number of decks that will be played with
    int deck_size = 52;
    int remaining_cards;                    // minimal numer of cards is 1 deck = 52 cards. number will be overwritten in the function set_number_of_decks()
    int temp = 0;
    std::vector<int> carddeck = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
                                            // cards in a deck with their score in Blackjack
    std::vector<int> finaldeck;        // cards that will be played with

    void set_number_of_decks(int number);   // determine with how many decks will be played

    int draw_card();                        //function to randomly draw a card from the deck

};

#endif
