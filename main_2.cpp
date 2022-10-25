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
        return score;
    }
};

class bot{
public:
    std:: string Name="name";
    std::array<int, 21> hand;
    int wallet =0;
    int strategyA[22][22];
    int strategydouble[22][22];
    int strategyother[22][22];
    std::string make_choice(int card_dealer){
        int choice_num;
        std::string choice;
        if (hand[2]==0){ //if the bot has 2 cards go to cases underneath
            if(hand[0]==hand[1]){ //if the bot has two similar cards:
                choice_num=strategydouble[hand[0]] [card_dealer];//first value row, second value column
            }else if(hand[0]=11){ //if bot has
                choice_num=strategyA[hand[1]][card_dealer];
            }else if(hand[1]=11){
                choice_num=strategyA[hand[0]][card_dealer];
            }else{
                choice_num=strategyother[hand[0]+hand[1]][card_dealer];
            }

        }else{
            choice_num=strategyother[this->calculate_score()][card_dealer];
        }
        switch (choice_num){
            case 0:
                choice="Hit";
                std::cerr << "Determining strategy went wrong. bot goes for stand as default";
                break;
            case 1:
                choice="Hit";
                break;
            case 2:
                choice="Double";
                break;
            case 3:
                choice="Stand";
                break;
            case 4:
                choice="Split";
                break;
        }
        
        return choice;
    }

    void set_strategy(std::string strategy){
        if(strategy=="Basic strategy") {
            std::ifstream fileinA{"basic_strategy_containing_A.txt"};
            std::ifstream fileinD{"basic_strategy_double_cards.txt"};
            std::ifstream fileinO{"basic_strategy_other.txt"};
            if (!fileinA.is_open()) {
                std::cerr << "Error opening basic_strategy_containing_A.txt";
                exit(-1);
            };

            if (!fileinD.is_open()) {
                std::cerr << "Error opening basic_strategy_double_cards.txt";
                exit(-1);
            };
            if (!fileinO.is_open()) {
                std::cerr << "Error opening basic_strategy_other.txt";
                exit(-1);
            };
            for(int j=0; j<23; j++) {
                for (int i = 0; i < 23; i++) {
                    fileinA >> strategyA[j][i];//first value row, second value column
                    fileinD >> strategydouble[j][i];
                    fileinO >> strategyother[j][i];
                }
            }

        }else{
            std::cerr << "Strategy not defined, choose Basic strategy";
            exit(-1);
        }
    }
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

    void clear_hand(){
        for(int i=0; i< hand.size(); i++){
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

        std::cout << "The added values of your cards is: " << score << std::endl;

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
    std::vector<player> players;
    int number_of_players=0;
    int players_with_name=0;

    void import_player(player player_n){
        players[number_of_players]=player_n;
        number_of_players+=1;
    };
    void give_names(){
        std::string name;
        for(int i=0;i<players.size();i++)
            std::cout<<"Enter the name of player"<<players_with_name+1<<std::endl;
        std::cin>>name;
        players[players_with_name].set_name(name);
        players_with_name+=1;
    }

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
    void initialise_players();
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

    // THE GAME STARTS HERE!
    bool continue_game = 1;
    while(continue_game == 1){
        Dealer.clear_hand();                                                            // clearing the hand of the dealer at the start 

        for(int j = 0; j < game.number_of_players; j++){                                // clearing the hand of every player at the start
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
            for(int k = 0; k < game.number_of_players; k++){
                players[k].get_card(deck.draw_card());
            }
        }

        for(int m = 0; m < game.number_of_players; m++){
            players[m].display_hand();

            if(players[m].calculate_score() == 21){
                std::cout << "this player has blackjack!" << std::endl;
            }
        }

        for(int n = 0; n < game.number_of_players; n++){
            std::string choice = "Y"; 
            std::cout << players[n].Name << ", do you want to draw another card? " << std::endl;
            std::cin >> choice;

            while(choice == "Y"){
                players[n].get_card(deck.draw_card());
                players[n].calculate_score();
                if(players[n].score_above_21 == 0){
                    std::cout << players[n].Name << ", do you want to draw another card? " << std::endl;
                    std::cin >> choice;
                }
                else{
                    int score = players[n].calculate_score();
                    std::cout << "You unfortunately passed 21 and are therefor busted, the added value of your hand is " << score << std::endl;
                    choice = "N";
                }
            }
        }

        for(int o = 0; o < game.number_of_players; o++){
            int score = players[o].calculate_score();
            int score_dealer = Dealer.calculate_score();
            if(players[o].score_above_21 == 0 && score > score_dealer){
                std::cout << players[o].Name << " congratulations you've beaten the dealer!" << std::endl;
            }
            else{
                std::cout << players[o].Name << " You messed it up!" << std::endl;
            }
        }

        int score_dealer = Dealer.calculate_score();
        std::cout << "this is the score of the dealer: " << score_dealer << std::endl;

        std::cout << "do you want to continue the game, if yes type 1, if no type 0. " << std::endl;
        std::cin >> continue_game;
    }

    return 0;
}



