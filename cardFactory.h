//
// Created by silver_android on 23/11/16.
//

#ifndef CSI2372_PROJECT_CARDFACTORY_H
#define CSI2372_PROJECT_CARDFACTORY_H


#include "deck.h"

class Deck;

class CardFactory {
static CardFactory *instance;
public:
    static CardFactory* getFactory();
    Deck getDeck();
};


#endif //CSI2372_PROJECT_CARDFACTORY_H
