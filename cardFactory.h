//
// Created by silver_android on 23/11/16.
//

#ifndef CSI2372_PROJECT_CARDFACTORY_H
#define CSI2372_PROJECT_CARDFACTORY_H


#include "deck.h"
#include <random>

class Deck;

class CardFactory {
    static CardFactory *instance;
    std::random_device rd;
    std::default_random_engine engine = std::default_random_engine(rd());
	std::vector<Card *> cards;
	CardFactory();
public:
    static CardFactory *getFactory();
    Deck getDeck();
};


#endif //CSI2372_PROJECT_CARDFACTORY_H
