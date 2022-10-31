#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>

class player
{
public:
    std::string Name; // Name of the player
    std::array<int, 21> hand; // Hand of the player where values will be stored. Max number of cards is 21 aces
    int wallet = 0; // money that the player posesses (not being used yet)
    int score_above_21 = 0; // if the player has a score higher than 21 it will be stored here
    
    void set_name(std::string name); // set the name of the player

    void display_hand(); // show the hand of the player

    void clear_hand(void); // set all values of the hand to 0

    void get_card(int number); // put a card in the hand of the player

    int calculate_score(); // calculate the total score of the hand

    int place_bet(int bet); // bet of the player

    void increase_wallet(int amount); // transfer money to the wallet of the player
};

#endif