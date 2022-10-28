#include <iostream>
#include "class_player.h"

player::set_name(std::string name)
{
    Name = name;
}

player::display_hand()
{
    std::cout << "The hand of " << Name << " is:\t";
    for (int i = 0; i < 21; i++)
    {
        if (hand[i] != 0)
        {
            std::cout << hand[i] << ", ";
        }
    }
    std::cout << std::endl;
}

player::clear_hand(void)
{

    for (int i = 0; i < hand.size(); i++)
    {
        hand[i] = 0;
    };
}

player::get_card(int number)
{
    int i = 0;
    while (hand[i] != 0)
    {
        i = i + 1;
    };
    hand[i] = number;
}

player::calculate_score()
{
    // int score=0;
    int index = 0;
    for (int value : hand)
    {
        if (value == 11)
        {
            int score = 0;
            for (int value2 : hand)
            {
                score = score + value2;
            }
            if (score > 21)
            {
                hand[index] = 1;
            }
            index = index + 1;
        }
    }
    int score = 0;
    for (int value : hand)
    {
        score = score + value;
    }

    if (score > 21)
    {
        score_above_21 = 1;
    }

    return score;
}

player::place_bet(int bet)
{
    if (bet > wallet)
    {
        std::cout << Name << "has not enough money, wallet runs negative" << std::endl;
    }
    wallet = wallet - bet;
    return bet;
}

player::increase_wallet(int amount)
{
    wallet = wallet + amount;
}