//
// Created by silver_android on 29/11/16.
//

#ifndef CSI2372_PROJECT_HAND_H
#define CSI2372_PROJECT_HAND_H


#include <vector>
#include "gemstones.h"
#include "cardFactory.h"

class Hand {
    std::vector<Card *> handVector;
public:
    Hand &operator+=(Card *);
    Card *play();
    Card *top();
    Card *operator[](int);
    friend std::ostream& operator<<(std::ostream &, const Hand &);
    Hand(std::istream &, CardFactory *);
};


#endif //CSI2372_PROJECT_HAND_H
