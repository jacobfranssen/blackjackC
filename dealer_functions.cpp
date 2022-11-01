#include <iostream>
#include "class_blackjack.h"
#include "class_carddeck.h"
#include "class_dealer.h"
#include "class_player.h"

void dealer::display_second_card()
{
    std::cout << "The hand of the " << Name << " is:\t";
    std::cout << "?" // first card of the dealer is hidden by ?
              << ", ";
    for (int i = 1; i < 21; i++) // go through the rest of the hand and only show the cards that are non zero (no card in the hand is indicated by a 0)
    {
        if (hand[i] != 0)
        {
            std::cout << hand[i] << ", ";
        }
    }
    std::cout << std::endl;
}

void dealer::display_full_hand(){
    for (int i = 0; i < 21; i++) // go through the hand of and show the cards that are non zero
    {
        if (hand[i] != 0)
        {
            std::cout << hand[i] << ", ";
        }
    }
    std::cout << std::endl;
}

void dealer::clear_hand(){
    for (int i = 0; i < hand.size(); i++){
        hand[i] = 0;
    };
}

void dealer::get_card(int number){
    int i = 0;
    while (hand[i] != 0){ // find to location in the hand where no card has been placed yet
        i = i + 1;
    }
    hand[i] = number; // put the card in this location of the hand
}

int dealer::calculate_score()
{
    int index = 0; // this number indicates the place in the hand that is being evaluated
    for (int value : hand){ // loop through the hand
        if (value == 11){ // if an ace is located in the hand it could either be an 11 or a 1
            int score = 0; // score of the hand if an ace is counted as 11 is calculated here
            for (int value2 : hand){ // calculate the score of the hand if ace would be 11
                score = score + value2;
            }
            if (score > 21){ // if the score of the hand turns out to be higher than 21, the ace turns into a 1
                hand[index] = 1;
            }
        }
        index = index + 1; // move to the next index of the hand
    }
    int score = 0;
    for (int value : hand){ // calculate the score of the hand again with the aces being the righ value
        score = score + value;
    }
    return score;
}