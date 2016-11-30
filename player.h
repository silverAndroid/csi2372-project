//
// Created by Brandon Danis on 2016-11-24.
//

#ifndef CSI2372_PROJECT_PLAYERS_H
#define CSI2372_PROJECT_PLAYERS_H
#include <string>

class Player {
    std::string playerName;
    int numOfCoins;
    int numOfChains;
    int maxNumOfChains;
public:
    Player( std::string &);
    std::string getName();
    int getNumCoins();
    Player& operator+=(int);
    int getMaxNumChains();
    int getNumChains();
    void buyThirdChain();
    void printHand(std::ostream&, bool);
};


#endif //CSI2372_PROJECT_PLAYERS_H
