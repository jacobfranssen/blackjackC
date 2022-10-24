#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>

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

    void clear_hand(void){

        for(int i=0; i<hand.size();i++){
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

    void clear_hand(void){

        for(int i=0; i<hand.size();i++){
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

std::string read_table(){
    std::vector<int> a(9,0);
    std::ifstream filein{"test_text.txt"};
    if (!filein.is_open()) {
        std::cerr << "Error opening file";
        exit(-1);
    };
    filein>>a[5];
    std::cout<<a[5];
    return "even een test";
}
class Blackjack{
public:
    std::vector<player> players;
    int number_of_players=0;
    int players_with_name=0;
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

};


int main() {

    player player1;
    player player2;
    player2.clear_hand();
    player2.set_name("joop" );
    std::cout<< player2.Name<<std::endl;
    player2.get_card(11);
    player2.get_card(3);
    player2.get_card(11);
    player2.display_hand();
    std::cout<< "score of "<< player2.Name<< " is "<< player2.calculate_score()<<std::endl;

    dealer Dealer;
    Dealer.clear_hand();
    Dealer.get_card(4);
    Dealer.get_card(5);
    Dealer.display_second_card();
    Dealer.display_full_hand();

    bot Computer;
    Computer.set_strategy("Basic strategy");
    Computer.clear_hand();
    Computer.set_name("Henk");
    Computer.get_card(11);
    Computer.get_card(7);
    Computer.get_card(4);
    std::cout<<Computer.strategyA[2][4]<<std::endl; //first value row, second value column
    std::cout<<Computer.make_choice(8);


    Blackjack game;
    game.import_player(player1);
    game.import_player(player2);
    player player3;
    game.import_player(player3);
    game.give_names();


    return 0;
}


