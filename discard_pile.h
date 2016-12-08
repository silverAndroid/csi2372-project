//
// Created by silver_android on 29/11/16.
//

#ifndef CSI2372_PROJECT_DISCARDPILE_H
#define CSI2372_PROJECT_DISCARDPILE_H


#include <vector>
#include "gemstones.h"
#include "cardFactory.h"

class DiscardPile {
    std::vector<Card *> discardVector;
public:
    DiscardPile&operator+=(Card *);
    Card *pickUp();
    Card *top();
    void print(std::ostream &);
    friend std::ostream& operator<<(std::ostream &, const DiscardPile &);
    DiscardPile() = default;
    DiscardPile(std::istream &, CardFactory *);
};


#endif //CSI2372_PROJECT_DISCARDPILE_H
