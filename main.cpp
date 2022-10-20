#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>

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

class card_deck{
public:

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
    std::cout<< "score of "<< player2.Name<< " is "<< player2.calculate_score();













    std::array<int, 52> carddeck = {2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11};

    player1.clear_hand();
    player2.clear_hand();

    srand((unsigned int)time(NULL));
    int r=rand();

//    std::cout << r << std::endl;

    const int CARDS = 52;
    int card[CARDS];                        // the 'card' array represents all of the cards
    int i, deck_cards;
    // initialization
    for (i=0; i< CARDS; i++)
        card[i]=i;
    // 'deck_cards' is the limit of the deck, it separates the
    // cards still inside the deck from the extracted ones
    deck_cards = CARDS;

    // random extraction of five cards
    for (i=0; i<5; i++)
    {
        int r = rand() % deck_cards;        // r is the newly extracted card index

        int temp = card[r];                 // the trick is here: we move the choosen card at the current deck
        card[r] = card[deck_cards-1];       // limit and decrease the deck size by one.
        card[deck_cards-1] = temp;          // this is accomplished swapping card[r] with card[deck_cards-1]

        deck_cards--;
    }
    // now let't print out the random choosen cards
//    for (i=0; i<5; i++)
//    {
//        printf("extracted card[%d]=%d\n", i, card[deck_cards+i]);
//    }

    return 0;
}


