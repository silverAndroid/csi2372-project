//
// Created by silver_android on 29/11/16.
//

#ifndef CSI2372_PROJECT_TRADEAREA_H
#define CSI2372_PROJECT_TRADEAREA_H

#include <list>
#include "gemstones.h"
#include "cardFactory.h"

class TradeArea {
    std::list<Card *> tradeList;
public:
    TradeArea& operator+=(Card *);
    bool legal(Card *);
    Card *trade(string);
    int numCards();
    friend std::ostream& operator<<(std::ostream &, const TradeArea &);
    TradeArea() = default;
    TradeArea(std::istream &, CardFactory *);
    bool isEmpty();
};


#endif //CSI2372_PROJECT_TRADEAREA_H
