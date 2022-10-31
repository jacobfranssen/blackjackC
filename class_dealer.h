#ifndef CLASS_DEALER
#define CLASS_DEALER

#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>

class dealer
{
public:
    std::string Name = "Dealer";        // name of the dealer, by default Dealer
    std::array<int, 21> hand;           // here the cards of the dealer will be stored max number of cards possible is 21 (21 aces)

    void display_second_card();         // the dealer only shows its second card at the stard of the game

    void display_full_hand();           // show the cards in the hand of the dealer

    void clear_hand();                  // clear the hand / set all values to 0

    void get_card(int number);          // put a card in the hand of the dealer

    int calculate_score();              // calculate the total score of the hand

};

#endif