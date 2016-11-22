//
// Created by silver_android on 21/11/16.
//

#ifndef CSI2372_PROJECT_DECK_H
#define CSI2372_PROJECT_DECK_H


#include <vector>
#include "card.h"

class Deck : std::vector<Card> {
public:
    Deck();
    Card* draw();
    std::ostream &operator<<(Deck deck);
};


#endif //CSI2372_PROJECT_DECK_H
