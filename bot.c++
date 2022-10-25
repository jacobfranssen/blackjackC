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
