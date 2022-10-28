#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>

class carddeck{
public:
    int number_of_decks;
    int remaining_cards = 52;
    std::vector<int> carddeck = {2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11};
    std::vector<int> finaldeck = {};

    void set_number_of_decks(int number){
        number_of_decks = number;
        for(int i = 0; i<number; i++){
            finaldeck.insert(finaldeck.end(),carddeck.begin(), carddeck.end());
        }
        remaining_cards = remaining_cards * number_of_decks;
    }    

    int draw_card(){
        int temp = 0;

        if(remaining_cards > 0){
            int position = rand() % remaining_cards;
            temp = finaldeck[position];         // drawn card

            finaldeck[position] = finaldeck[remaining_cards-1];
            finaldeck[remaining_cards - 1] = temp;

            //std::cout << temp << std::endl;
            remaining_cards --;
            finaldeck.resize(remaining_cards);
        }

            
        return temp;
    }
};

class dealer{
public:
    std:: string Name="Dealer";
    std::array<int, 21> hand;

    void display_second_card(){
        std:: cout<< "The hand of the " << Name << " is:\t" ;
        std:: cout<<"?"<<", ";
        for(int i=1;i<21;i++){
            if (hand[i]!= 0){
                std:: cout<<hand[i]<<", ";
            }
        }
        std::cout<<std::endl;
    };

    void display_full_hand(){
        for(int i=0;i<21;i++){
            if (hand[i]!= 0){
                std:: cout<<hand[i]<<", ";
            }
        }
        std::cout<<std::endl;
    };

    void clear_hand(){
        for(int i=0; i<hand.size(); i++){
            hand[i]=0;
        };
    };

    void get_card(int number) {
        int i = 0;

        while (hand[i] != 0) {
            i = i + 1;
        }
        hand[i] = number;
    }

    int calculate_score(){
        int index= 0;
        for(int value:hand){
            if(value==11){
                int score= 0;
                for(int value2:hand){
                    score=score+value2;

                }
                if(score>21){
                    hand[index]=1;
                }
                index=index+1;
            }


        }
        int score=0;
        for(int value:hand){
            score=score+value;
        }
        return score;
    }
};

class player{
public:
    std::string Name="name";
    std::array<int, 21> hand;

    int wallet = 0;

    int score_above_21 = 0; 

    void set_name(std::string name){
        Name=name;
    };

    void display_hand(){
        std:: cout<< "The hand of " << Name << " is:\t" ;
        for(int i=0;i<21;i++){
            if (hand[i]!= 0){
                std:: cout<<hand[i]<<", ";
            }
        }
        std::cout<<std::endl;
    };

    void clear_hand(void){

        for(int i=0; i<hand.size();i++){
            hand[i]=0;
        };
    };

    void get_card(int number){
        int i = 0;
        while (hand[i] != 0) {
            i = i + 1;
        };
        hand[i] = number;
    };

    int calculate_score(){
        //int score=0;
        int index= 0;
        for(int value:hand){
            if(value==11){
                int score= 0;
                for(int value2:hand){
                    score=score+value2;

                }
                if(score>21){
                    hand[index]=1;
                }
                index=index+1;
            }


        }
        int score=0;
        for(int value:hand){
            score=score+value;
        }

        if(score > 21){
            score_above_21 = 1;
        }

        return score;
    }

    int place_bet(int bet){
        if(bet>wallet){
            std::cout<< Name<<"has not enough money, wallet runs negative"<<std::endl;
        }
        wallet=wallet-bet;
        return bet;
    };

    void increase_wallet(int amount){
        wallet=wallet+amount;
    }

};

class Blackjack{
public:
    int number_of_players=0;

    void set_number_of_players(int number){
        number_of_players = number;
    }
};

int initialisation_amount_of_players(){
    int NumberOfPlayers = 0;
    int AmountOfCarddecks = 0;
    
    while(NumberOfPlayers <= 0 || NumberOfPlayers >= 10){
        std::cout << "How many players will be attending this game? Please insert a number between 1 and 10. Insert the amount here: " << std::endl;
        std::cin >> NumberOfPlayers;
        std::cout << std::endl;
    }

    return NumberOfPlayers;
}

int initialisation_number_of_decks(){
    int Number_of_Decks;

    while(Number_of_Decks <= 0 || Number_of_Decks >= 10){
        std::cout << "Please insert the number of decks here, a number between 1 and 10: " << std::endl;
        std::cin >> Number_of_Decks;
        std::cout << std::endl;
    }

    return Number_of_Decks;
}

int main() {
    Blackjack game;
    dealer Dealer;
    int Amount_of_Players = initialisation_amount_of_players();
    game.set_number_of_players(Amount_of_Players);                                      //This function gets the amount of players from the user.
    
    std::vector<std::string> PlayerNames = {};                                          //This is the vector in which the name of the players will be stored.

    player *players = new player[Amount_of_Players];

    for(int i = 1; i <= Amount_of_Players; i++){                                        //This loop fills the vector with names.
        std::string Name;
        std::cout << "Please insert the name of player number " << i << " here: " << std::endl;
        std::cin >> Name;
        players[i-1].set_name(Name);
    }

    int Number_of_Decks = initialisation_number_of_decks();                             //This line obtains the amount of decks that will be used. 
    carddeck deck;
    deck.set_number_of_decks(Number_of_Decks);

    // THE GAME STARTS HERE!!
    bool continue_game = 1;
    while(continue_game == 1){
        int number_of_fails = 0;
        Dealer.clear_hand();                                                            // clearing the hand of the dealer at the start 

        for(int j = 0; j < game.number_of_players; j++){                                // clearing the hand of every player at the start
            players[j].clear_hand();
        }

        for(int i = 0; i<2; i++){
            Dealer.get_card(deck.draw_card());
        }

        int score_dealer = Dealer.calculate_score();

        if(score_dealer == 21){
            std::cout << "The dealer has BlackJack, the next round starts now." << std::endl;
        }
        else{
            Dealer.display_second_card();
        }

        for(int l = 0; l<2; l++){
            for(int k = 0; k < game.number_of_players; k++){
                players[k].get_card(deck.draw_card());
            }
        }

        for(int m = 0; m < game.number_of_players; m++){
            players[m].display_hand();

            if(players[m].calculate_score() == 21){
                std::cout << "This player has blackjack!" << std::endl;
            }
        }

        for(int n = 0; n < game.number_of_players; n++){
            std::string choice = "Y"; 
            int score = players[n].calculate_score();
            if(players[n].calculate_score() != 21){
                std::cout << std::endl;
                std::cout << players[n].Name << ", do you want to draw another card? " << std::endl;
                std::cin >> choice;

                while(!(choice == "Y" || choice == "N"))
                {
                    std::cout << players[n].Name << " you didn't type Y or N, would you like another card? Your current hand has the value: " << score << std::endl;
                    std::cin >> choice;
                }
            }
            else{
                choice = "N";
            }

            while(choice == "Y"){
                int drawn_card = deck.draw_card();
                std::cout << std::endl;
                std::cout << "You drew the card: " << drawn_card << std::endl;
                std::cout << std::endl;
                players[n].get_card(drawn_card);
                players[n].calculate_score();
                int score = players[n].calculate_score();
                if(players[n].score_above_21 == 0 && score != 21){
                    std::cout << "The added value of your hand is now: " << score << std::endl;
                    std::cout << players[n].Name << ", do you want to draw another card? " << std::endl;
                    std::cin >> choice;

                    while(!(choice == "Y" || choice == "N"))
                    {
                        std::cout << players[n].Name << " you didn't type Y or N, would you like another card? Your current hand has the value:  " << score << std::endl;
                        std::cin >> choice;
                    }
                }
                else if(score > 21){
                    int score = players[n].calculate_score();
                    std::cout << "You unfortunately passed 21 and are therefor busted, the added value of your hand is " << score << std::endl;
                    number_of_fails++;
                    choice = "N";
                }
                else{
                    choice = "N";
                }
            }
        }

        if(number_of_fails == game.number_of_players){
            std::cout << std::endl;
            std::cout << "Unfortunately every player exceeded 21, therefor this round is over." << std::endl;
            std::cout << std::endl;
            goto AllPlayersExceeded21;
        }

        std::cout << "The current hand of the dealer is: ";
        Dealer.display_full_hand();
        std::cout << std::endl;

        while(Dealer.calculate_score() < 16){
            int new_card_dealer = deck.draw_card();
            Dealer.get_card(new_card_dealer);
            std::cout << "The dealer draws the card: " << new_card_dealer << std::endl;
            std::cout << std::endl;
        }

        if(Dealer.calculate_score() > 21){
            Dealer.clear_hand();
            std::cout << "The dealer is busted, he exceeded 21." << std::endl;
        }

        score_dealer = Dealer.calculate_score();

        for(int o = 0; o < game.number_of_players; o++){
            int score = players[o].calculate_score();
            if(players[o].score_above_21 == 0 && score >= score_dealer){
                std::cout << players[o].Name << " congratulations you've beaten the dealer!" << std::endl;
                std::cout << std::endl;
            }
            else{
                std::cout << players[o].Name << " You unfortunately lost, your score was: " << score << std::endl;
                std::cout << std::endl;
            }
        }

        std::cout << "The hand of the dealer consists out of: ";
        Dealer.display_full_hand();
        std::cout << std::endl;
        std::cout << "this is the score of the dealer: " << score_dealer << std::endl;
        std::cout << std::endl;
        
        AllPlayersExceeded21: 

        std::cout << "do you want to continue the game, if yes type 1, if no type 0. " << std::endl;
        std::cin >> continue_game;
    }

    return 0;
}
