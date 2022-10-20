#include <iostream>
#include <array>
#include <string>
#include <fstream>
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
// hey wereld
class card_dek{
public:

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    player player1;
    player1.clear_hand();
    srand((unsigned int)time(NULL));

    int r=rand();
    cout << r << std::endl;

    const int CARDS = 52;
    int card[CARDS]; // the 'card' array represents all of the cards
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
        // r is the newly extracted card index
        int r = rand() % deck_cards;

        // the trick is here: we move the choosen card at the current deck
        // limit and decrease the deck size by one.
        // this is accomplished swapping card[r] with card[deck_cards-1]
        int temp = card[r];
        card[r] = card[deck_cards-1];
        card[deck_cards-1] = temp;

        deck_cards--;
    }
// now let't print out the random choosen cards
    for (i=0; i<5; i++)
    {
        printf("extracted card[%d]=%d\n", i, card[deck_cards+i]);
    }

    return 0;
}
=======

// THIS IS THE WAY
>>>>>>> 34a0a63d60ae0adb3261843db58aed4f25dbb4cb
