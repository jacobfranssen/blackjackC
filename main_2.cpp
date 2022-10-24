#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>

class carddeck{
public:
    int number_of_decks;
    std::vector<int> carddeck = {2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11};
    std::vector<int> finaldeck = {};

    void set_number_of_decks(int number){
        number_of_decks = number;
        for(int i = 0; i<number; i++){
            finaldeck.insert(finaldeck.end(),carddeck.begin(), carddeck.end());
        }
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
    std:: string Name="name";
    std::array<int, 21> hand;
    int wallet =0;

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

// General functions that can be used in player, bot and dealer classes.
class Blackjack{
public:
    std::vector<player> players;
    int number_of_players=0;
    int players_with_name=0;
    int number_of_players;
    void set_number_players(int number){
        number_of_players=number;
    }
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

std::string initialisation_names(int i){

    std::string Name;
    std::cout << "Please type the name of player number " << i << " here: " << std::endl;
    std::cin >> Name;
    std::cout << std::endl;

    return Name;
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

    int Amount_of_Players = initialisation_amount_of_players();
    Blackjack game;
    game.set_number_of_players(Amount_of_Players);                                      //This function gets the amount of players from the user.
    std::vector<std::string> PlayerNames = {};                                          //This is the vector in which the name of the players will be stored.

    for(int i = 1; i <= Amount_of_Players; i++){                                        //This loop fills the vector with names.
        std::string Name = initialisation_names(i);
        PlayerNames.push_back(Name);                
    }

    int Number_of_Decks = initialisation_number_of_decks();                             //This line obtains the amount of decks that will be used. 
    carddeck deck;
    deck.set_number_of_decks(Number_of_Decks);
    std::cout << deck.finaldeck[80] << std::endl;

    for(int i = 0; i<Amount_of_Players; i++){
        player player1;

    }

    return 0;
}


