#include <iostream>
#include "class_blackjack.h"

Blackjack::initialisation_amount_of_players()
{
    int Number = 0;
    while (Number <= 0 || Number >= 10)
    {
        std::cout << "How many players will be attending this game? Please insert a number between 1 and 10. Insert the amount here: " << std::endl;
        std::cin >> Number;
        std::cout << std::endl;
    }
    Amount_of_Players = Number;
}

Blackjack::resize()
{
    players.resize(Amount_of_Players);
}

Blackjack::give_names()
{
    for (int i = 0; i < Amount_of_Players; i++)
    {
        std::string Name;
        std::cout << "Please insert the name of player number " << (i + 1) << " here: " << std::endl;
        std::cin >> Name;
        players[i].set_name(Name);
    }
}

Blackjack::initialisation_number_of_decks()
{
    while (Number_of_Decks <= 0 || Number_of_Decks >= 10)
    {
        std::cout << "Please insert the number of decks here, a number between 1 and 10: " << std::endl;
        std::cin >> Number_of_Decks;
        std::cout << std::endl;
    }
}

Blackjack::play()
{
    dealer Dealer;
    carddeck deck;
    deck.set_number_of_decks(Number_of_Decks);
    bool continue_game = 1;

    while (continue_game == 1)
    {

        Dealer.clear_hand(); // clearing the hand of the dealer at the start

        for (int j = 0; j < Amount_of_Players; j++)
        { // clearing the hand of every player at the start
            players[j].clear_hand();
        }

        for (int i = 0; i < 2; i++)
        {
            Dealer.get_card(deck.draw_card());
        }

        if (Dealer.calculate_score() == 21)
        {
            std::cout << "The dealer has BlackJack, the next round starts now." << std::endl;
        }
        else
        {
            Dealer.display_second_card();
        }

        for (int l = 0; l < 2; l++)
        {
            for (int k = 0; k < Amount_of_Players; k++)
            {
                players[k].get_card(deck.draw_card());
            }
        }

        for (int m = 0; m < Amount_of_Players; m++)
        {
            players[m].display_hand();

            if (players[m].calculate_score() == 21)
            {
                std::cout << "this player has blackjack!" << std::endl;
            }
        }

        for (int n = 0; n < Amount_of_Players; n++)
        {
            std::string choice = "Y";
            if (players[n].calculate_score() != 21)
            {
                std::cout << players[n].Name << ", do you want to draw another card? " << std::endl;
                std::cin >> choice;
            }
            else
            {
                choice = "N";
            }

            while (choice == "Y")
            {
                players[n].get_card(deck.draw_card());
                players[n].calculate_score();
                int score = players[n].calculate_score();
                if (players[n].score_above_21 == 0 && score != 21)
                {
                    std::cout << "The added value of your hand is now: " << score << std::endl;
                    std::cout << players[n].Name << ", do you want to draw another card? " << std::endl;
                    std::cin >> choice;
                }
                else if (score == 21)
                {
                    std::cout << "The added value of your hand is 21, you do not have to draw another card. " << std::endl;
                    std::cout << std::endl;
                    choice = "N";
                }
                else
                {
                    std::cout << "You unfortunately passed 21 and are therefor busted, the added value of your hand is " << score << std::endl;
                    std::cout << std::endl;
                    choice = "N";
                }
            }
        }

        while (Dealer.calculate_score() < 16)
        {
            Dealer.get_card(deck.draw_card());
        }

        if (Dealer.calculate_score() > 21)
        {
            Dealer.clear_hand();
            std::cout << std::endl;
            std::cout << "The dealer is busted, he exceeded 21." << std::endl;
        }

        for (int o = 0; o < Amount_of_Players; o++)
        {
            int score = players[o].calculate_score();
            int score_dealer = Dealer.calculate_score();
            if (players[o].score_above_21 == 0 && score >= score_dealer)
            {
                std::cout << players[o].Name << " congratulations you've beaten the dealer!" << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << players[o].Name << " You unfortunately lost, your score was: " << score << std::endl;
                std::cout << std::endl;
            }
        }

        int score_dealer = Dealer.calculate_score();
        std::cout << "this is the score of the dealer: " << score_dealer << std::endl;
        std::cout << std::endl;

        std::cout << "Do you want to continue the game, if yes type 1, if no type 0. " << std::endl;
        std::cin >> continue_game;
    }
}