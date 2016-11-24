//
// Created by silver_android on 23/11/16.
//

#ifndef CSI2372_PROJECT_DECK_H
#define CSI2372_PROJECT_DECK_H


#include <vector>
#include "gemstones.h"
#include "cardFactory.h"

class CardFactory;

class Deck : std::vector<Card> {
public:
    Deck(std::istream &, CardFactory *);
    Card *draw();
    friend std::ostream& operator<<(std::ostream &, const Deck &);
};


#endif //CSI2372_PROJECT_DECK_H
