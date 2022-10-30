#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>

class carddeck{
    // This class represents the cards that will be used during the game.
public:
    int number_of_decks;// number of decks that will be played with
    int remaining_cards = 52; // minimal numer of cards is 1 deck = 52 cards. number will be overwritten in the function set_number_of_decks()
    std::vector<int> carddeck = {2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11}; // cards in a deck with their score in Blackjack
    std::vector<int> finaldeck {}; // cards that will be played with

    void set_number_of_decks(int number){// determine with how many decks will be played
        number_of_decks = number;
        remaining_cards = 52;
        carddeck = {2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11};
        finaldeck = {};
        for(int i = 0; i<number; i++){
            finaldeck.insert(finaldeck.end(),carddeck.begin(), carddeck.end());
        }
        remaining_cards = remaining_cards * number_of_decks;
    }

    int draw_card(){//function to randomly draw a card from the deck
        int temp = 0; //variable where the card will be stored

        if(remaining_cards > 0){// check if there are cards in the deck
            int position = rand() % remaining_cards;// randomly choose the position in the deck
            temp = finaldeck[position];        // find the card

            finaldeck[position] = finaldeck[remaining_cards-1];// put the card at the end of the deck on the position of the drawn card
            finaldeck[remaining_cards - 1] = temp; // put the drawn card at the end of the deck


            remaining_cards --;// number of cards decreases by 1
            finaldeck.resize(remaining_cards); //size of the deck decreases by 1
        }else {
            std::cout << "There are no cards left in the deck" << std::endl; // if there are no cards left give message
        }
        if(remaining_cards < 10){// if there are less than 10 cards make sure a new deck is generated of
            std::cout<<"Only "<<remaining_cards<<" were left in the dek, therefore we start with 1 deck of cards again"<<std::endl;
            set_number_of_decks(1);
        }

        return temp;// return the drawn card
    }
};

class dealer{ // class dealer
public:
    std:: string Name="Dealer"; //name of the dealer, by default Dealer
    std::array<int, 21> hand; // here the cards of the dealer will be stored max number of cards possible is 21 (21 aces)

    void display_second_card(){ // the dealer only shows its second card at the stard of the game
        std:: cout<< "The hand of the " << Name << " is:\t" ;
        std:: cout<<"?"<<", "; // first card of the dealer is hidden by ?
        for(int i=1;i<21;i++){ // go through the rest of the hand and only show the cards that are non zero (no card in the hand is indicated by a 0)
            if (hand[i]!= 0){
                std:: cout<<hand[i]<<", ";
            }
        }
        std::cout<<std::endl;
    };

    void display_full_hand(){ // show the cards in the hand of the dealer
        for(int i=0;i<21;i++){ // go through the hand of and show the cards that are non zero
            if (hand[i]!= 0){
                std:: cout<<hand[i]<<", ";
            }
        }
        std::cout<<std::endl;
    };

    void clear_hand(){ // clear the hand / set all values to 0
        for(int i=0; i<hand.size(); i++){
            hand[i]=0;
        };
    };

    void get_card(int number) { // put a card in the hand
        int i = 0;

        while (hand[i] != 0) { // find to location in the hand where no card has been placed yet
            i = i + 1;
        }
        hand[i] = number; // put the card in this location of the hand
    }

    int calculate_score(){// calculate the total score of the hand

        int index= 0;// this number indicates the place in the hand that is being evaluated
        for(int value:hand){// loop through the hand
            if(value==11){// if an ace is located in the hand it could either be an 11 or a 1
                int score= 0;// score of the hand if an ace is counted as 11 is calculated here
                for(int value2:hand){ // calculate the score of the hand if ace would be 11
                    score=score+value2;

                }
                if(score>21){ // if the score of the hand turns out to be higher than 21, the ace turns into a 1
                    hand[index]=1;
                }

            }
            index=index+1;// move to the next index of the hand

        }
        int score=0;
        for(int value:hand){// calculate the score of the hand again with the aces being the righ value
            score=score+value;
        }
        return score;
    }
};

class player{
public:

    std::string Name="name"; // Name of the player
    std::array<int, 21> hand; // Hand of the player where values will be stored. Max number of cards is 21 aces
    int wallet = 0; // money that the player posesses (not being used yet)
    int score_above_21 = 0; // if the player has a score higher than 21 it will be stored here

    void set_name(std::string name){ // set the name of the player
        Name=name;
    };

    void display_hand(){ // show the hand of the player
        std:: cout<< "The hand of " << Name << " is:\t" ;
        for(int i=0;i<21;i++){
            if (hand[i]!= 0){// go through the hand of the player and show the non zero numbers (zero indicates an empty)
                std:: cout<<hand[i]<<", ";
            }
        }
        std::cout<<std::endl;
    };

    void clear_hand(void){ // set all values of the hand to 0
        score_above_21=0;
        for(int i=0; i<hand.size();i++){
            hand[i]=0;
        };
    };

    void get_card(int number){ // put a card in the hand of the player
        int i = 0;
        while (hand[i] != 0) { // find the first location in the hand that is zero
            i = i + 1;
        };
        hand[i] = number; // place the card at the first zero location
    };

    int calculate_score(){// calculate the total score of the hand
        int index= 0; // this number indicates the place in the hand that is being evaluated
        for(int value:hand){ // loop through the hand
            if(value==11){ // if an ace is located in the hand it could either be an 11 or a 1
                int score= 0; // score of the hand if an ace is counted as 11 is calculated here
                for(int value2:hand){ // calculate the score of the hand if ace would be 11
                    score=score+value2;

                }
                if(score>21){ // if the score of the hand turns out to be higher than 21, the ace turns into a 1
                    hand[index]=1;
                }

            }
            index=index+1; // move to the next index of the hand

        }
        int score=0;
        for(int value:hand){ // calculate the score of the hand again with the aces being the righ value
            score=score+value;
        }

        if(score > 21){
            score_above_21 = 1;
        }

        return score;
    }

    int place_bet(int bet){ // bet of the player
        if(bet>wallet){
            std::cout<< Name<<"has not enough money, wallet runs negative"<<std::endl;
        }
        wallet=wallet-bet;
        return bet;
    };

    void increase_wallet(int amount){ // transfer money to the wallet of the player
        wallet=wallet+amount;
    }

};

class Blackjack{ // class were all functions and variables nessecarry for the game are stored
public:
    int number_of_players=0; // don't think this will be used
    int Amount_of_Players;
    player *players = new player[Amount_of_Players];
    int Number_of_Decks;


    void set_number_of_players(int number){
        number_of_players = number;
    }

    void initialisation_amount_of_players(){
        int NumberOfPlayers = 0;
        int AmountOfCarddecks = 0;

        while(NumberOfPlayers <= 0 || NumberOfPlayers >= 10){
            std::cout << "How many players will be attending this game? Please insert a number between 1 and 10. Insert the amount here: " << std::endl;
            std::cin >> NumberOfPlayers;
            std::cout << std::endl;
        }
        Amount_of_Players = NumberOfPlayers;


    }
    void give_names(){

        for(int i = 1; i <= Amount_of_Players; i++){                                        //This loop fills the vector with names.
            std::string Name;
            std::cout << "Please insert the name of player number " << i << " here: " << std::endl;
            std::cin >> Name;
            players[i-1].set_name(Name);
        }
    }
    void initialisation_number_of_decks(){


        while(Number_of_Decks <= 0 || Number_of_Decks >= 10){
            std::cout << "Please insert the number of decks here, a number between 1 and 10: " << std::endl;
            std::cin >> Number_of_Decks;
            std::cout << std::endl;
        }


    }
    std::string raise_question_user_extra_card(std::string Pos_answer_1,std::string Pos_answer_2,std::string player_name){
        std::string choice_player="--";
        std::string choice="-";

        while(!(choice_player==Pos_answer_1 or choice_player== Pos_answer_2)){
            std::cout << player_name << ", do you want to draw another card? Enter Yes or No " << std::endl;
            std::cin >> choice_player;
            if(choice_player=="Yes"){
                choice="Y";
            }
            else{
                choice="N";
            }

        }
        choice_player="--";
        return choice;
    }
    int players_in_game(){
        int n_players_in_game=number_of_players;
        for(int i = 0; i < number_of_players; i++){
            n_players_in_game=n_players_in_game-players[i].score_above_21;
        };
        return n_players_in_game;
    }
    void play(){
        dealer Dealer;
        carddeck deck;
        deck.set_number_of_decks(Number_of_Decks);
        int score;
        bool continue_game = true;
        while(continue_game == true){
            Dealer.clear_hand();                                                            // clearing the hand of the dealer at the start

            for(int j = 0; j < number_of_players; j++){                                // clearing the hand of every player at the start
                players[j].clear_hand();
            }

            for(int i = 0; i<2; i++){
                Dealer.get_card(deck.draw_card());
            }

            if(Dealer.calculate_score() == 21){
                std::cout << "The dealer has BlackJack, the next round starts now." << std::endl;
            }
            else{
                Dealer.display_second_card();
            }

            for(int l = 0; l<2; l++){
                for(int k = 0; k < number_of_players; k++){
                    players[k].get_card(deck.draw_card());
                }
            }

            for(int m = 0; m < number_of_players; m++){
                players[m].display_hand();

                if(players[m].calculate_score() == 21){
                    std::cout << "this player has blackjack!" << std::endl;
                }
            }

            for(int n = 0; n < number_of_players; n++){
                std::string choice = "--";
                std::string choice_player = "--";
                if(players[n].calculate_score() != 21) {
                    choice = raise_question_user_extra_card("Yes", "No", players[n].Name);
                }

                while(choice == "Y"){
                    players[n].get_card(deck.draw_card());
                    players[n].calculate_score();
                    score = players[n].calculate_score();
                    if(players[n].score_above_21 == 0){
                        std::cout << "The added value of your hand is now: " << score << std::endl;

                        choice = raise_question_user_extra_card("Yes", "No", players[n].Name);
                    }
                    else{
                        std::cout << "You unfortunately passed 21 and are therefor busted, the added value of your hand is " << score << std::endl;
                        choice = "N";
                    }
                }
            }

            if(players_in_game()>0) {
                while (Dealer.calculate_score() < 17) {
                    Dealer.get_card(deck.draw_card());
                }

                if (Dealer.calculate_score() > 21) {
                    Dealer.clear_hand();
                    std::cout << "The dealer is busted, he exceeded 21." << std::endl;
                }


                int score_dealer = Dealer.calculate_score();
                if (score_dealer > 0) {
                    std::cout << "This is the hand of the dealer: ";
                    Dealer.display_full_hand();
                    std::cout << "this results in the score of the dealer being: " << score_dealer << std::endl;

                    std::cout << std::endl;
                }
            }
            for(int o = 0; o < number_of_players; o++){
                score = players[o].calculate_score();
                int score_dealer = Dealer.calculate_score();
                if(players[o].score_above_21 == 0 && score >= score_dealer){
                    std::cout << players[o].Name << " congratulations you've beaten the dealer!" << std::endl;
                    std::cout << std::endl;
                }
                else{
                    std::cout << players[o].Name << " You unfortunately lost, your score was: " << score << std::endl;
                    std::cout << std::endl;
                }
            }


            std::string choice_player="--";
            while(!(choice_player=="Yes" or choice_player== "No")){
                std::cout << "do you want to continue the game, Enter Yes or No " << std::endl;
                std::cin >> choice_player;
                if(choice_player=="Yes"){
                    continue_game=true;
                }
                else{
                    continue_game=false;
                }

            }
            choice_player="--";

        }
    }
};





int main() {
    Blackjack game;

    //void initialise_players();
    game.initialisation_amount_of_players();
    game.set_number_of_players(game.Amount_of_Players);                                      //This function gets the amount of players from the user.

    game.give_names();




    game.initialisation_number_of_decks();                             //This line obtains the amount of decks that will be used.



    // THE GAME STARTS HERE!
    game.play();


    return 0;
}



