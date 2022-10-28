#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#pragma once

class dealer
{
public:
    std::string Name = "Dealer";
    std::array<int, 21> hand;

    void display_second_card();

    void display_full_hand();

    void clear_hand();

    void get_card(int number);

    int calculate_score();

};