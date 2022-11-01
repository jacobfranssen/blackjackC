#include <iostream>
#include "class_blackjack.h"
#include "class_carddeck.h"
#include "class_dealer.h"
#include "class_player.h"

void player::set_name(std::string name){
    Name = name;
}

void player::display_hand(){
    std::cout << "The hand of " << Name << " is:\t";
    for (int i = 0; i < 21; i++){
        if (hand[i] != 0){ // go through the hand of the player and show the non zero numbers (zero indicates an empty)
            std::cout << hand[i] << ", ";
        }
    }
    std::cout << std::endl;
}

void player::clear_hand(void){
    for (int i = 0; i < hand.size(); i++){
        hand[i] = 0;
        score_above_21 = 0;
    };
}

void player::get_card(int number){
    int i = 0;
    while (hand[i] != 0){ // find the first location in the hand that is zero
        i = i + 1;
    };
    hand[i] = number; // place the card at the first zero location
}

int player::calculate_score() {
    int index = 0; // this number indicates the place in the hand that is being evaluated
    for (int value: hand) { // loop through the hand
        if (value == 11) { // if an ace is located in the hand it could either be an 11 or a 1
            int score = 0; // score of the hand if an ace is counted as 11 is calculated here
            for (int value2: hand) { // calculate the score of the hand if ace would be 11
                score = score + value2;
            }
            if (score > 21) { // if the score of the hand turns out to be higher than 21, the ace turns into a 1
                hand[index] = 1;
            }
            index = index + 1; // move to the next index of the hand
        }
    }
    int score = 0;
    for (int value: hand) { // calculate the score of the hand again with the aces being the righ value
        score = score + value;
    }
    if (score > 21) {
        score_above_21 = 1;
    }
    return score;}

int player::place_bet(int bet){
    if (bet > wallet){
        std::cout << Name << "has not enough money, wallet runs negative" << std::endl;
    }
    wallet = wallet - bet;
    return bet;
}

void player::increase_wallet(int amount){
    wallet = wallet + amount;
}