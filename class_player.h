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
    std::string Name;
    std::array<int, 21> hand;
    int wallet = 0;
    int score_above_21 = 0;

    void set_name(std::string name);

    void display_hand();

    void clear_hand(void);

    void get_card(int number);

    int calculate_score();

    int place_bet(int bet);

    void increase_wallet(int amount);
};

#endif