//
// Created by Brandon Danis on 2016-11-24.
//

#ifndef CSI2372_PROJECT_PLAYERS_H
#define CSI2372_PROJECT_PLAYERS_H

#include <iostream>
#include <string>
#include <vector>
#include "cardFactory.h"
#include "chain.h"
#include "hand.h"


class Player {
    std::vector<Chain_Base> chains;
    std::string playerName;
    int numOfCoins;
    int numOfChains;
    int maxNumOfChains;
    Hand hand;
public:
    Player( std::string &);
    Player(std::istream&, CardFactory*);
    std::string getName();
    int getNumCoins();
    void addCardToHand(Card*);
    void createNewChain(Card *card);
    Player& operator+=(int);
    int getMaxNumChains();
    Hand* getHand();
    int getNumChains();
    Chain_Base& operator[](int i);
    void buyThirdChain();
    void printHand(std::ostream&, bool);
};


#endif //CSI2372_PROJECT_PLAYERS_H
