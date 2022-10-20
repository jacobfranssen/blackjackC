#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class player{
public:

    int b=4;

    void clear_hand(void){
        array<int, 21> a;
        for(int i=0; i<a.size();i++){
            a[i]=0;
        };
    };
};

class card_dek{
public:

};

int main() {

    player player1;
    player player2;
    
    char carddeck[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

    player1.clear_hand();
    player2.clear_hand();

    srand((unsigned int)time(NULL));
    int r=rand();

    cout << r << std::endl;

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
    for (i=0; i<5; i++)
    {
        printf("extracted card[%d]=%d\n", i, card[deck_cards+i]);
    }

    return 0;
}


