#ifndef CLASS_CARDDECK
#define CLASS_CARDDECK

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
    int temp = 0;
    std::vector<int> carddeck = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    std::vector<int> finaldeck = {};

    void set_number_of_decks(int number);

    int draw_card();

};

#endif
