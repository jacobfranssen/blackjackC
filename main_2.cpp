#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>

class player{
public:
    std:: string Name;
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

class card_deck{
public:

std::array<int, 52> carddeck = {2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11};
    

};

class dealer{

};

class BlackJack{
public:
    int number_of_players;

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
    BlackJack game;
    game.set_number_of_players(Amount_of_Players);                                      //This function gets the amount of players from the user.
    std::vector<std::string> PlayerNames = {};                                          //This is the vector in which the name of the players will be stored.

    for(int i = 1; i <= Amount_of_Players; i++){                                        //This loop fills the vector with names.
        std::string Name = initialisation_names(i);
        PlayerNames.push_back(Name);                
    }

    int Number_of_Decks = initialisation_number_of_decks();                             //This line obtains the amount of decks that will be used. 

    for(int i = 0; i<Amount_of_Players; i++){
        player player1;

    }

    return 0;
}


