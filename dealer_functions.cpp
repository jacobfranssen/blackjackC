#include <iostream>
#include "class_dealer.h"

dealer::display_second_card()
{
    std::cout << "The hand of the " << Name << " is:\t";
    std::cout << "?"
              << ", ";
    for (int i = 1; i < 21; i++)
    {
        if (hand[i] != 0)
        {
            std::cout << hand[i] << ", ";
        }
    }
    std::cout << std::endl;
}

dealer::display_full_hand()
{
    for (int i = 0; i < 21; i++)
    {
        if (hand[i] != 0)
        {
            std::cout << hand[i] << ", ";
        }
    }
    std::cout << std::endl;
}

dealer::clear_hand()
{
    for (int i = 0; i < hand.size(); i++)
    {
        hand[i] = 0;
    };
}

dealer::get_card(int number)
{
    int i = 0;

    while (hand[i] != 0)
    {
        i = i + 1;
    }
    hand[i] = number;
}

dealer::calculate_score()
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
    return score;
}