//
// Created by silver_android on 29/11/16.
//

#include "trade_area.h"

TradeArea::TradeArea(std::istream &, CardFactory *) {

}

TradeArea::TradeArea() {

}

TradeArea &TradeArea::operator+=(Card *card) {
    push_back(card); // TODO: Check for any side-effects from using same memory location
    return *this;
}

bool TradeArea::legal(Card *card) {
    std::list<Card *>::const_iterator it = begin();
    while (it != end()) {
        Card *card1 = *it;
        if (card->getName() == card1->getName()) {
            return true;
        }
    }
    return false;
}

Card *TradeArea::trade(string cardName) {
    std::list<Card *>::const_iterator it = begin();
    while (it != end()) {
        Card *card = *it; // TODO: Check if any side effects from using same memory location
        if (cardName == card->getName()) {
            remove(card);
            return card;
        }
    }
    return nullptr;
}

int TradeArea::numCards() {
    return (int) size();
}

std::ostream &operator<<(std::ostream &output, const TradeArea &tradeArea) {
    std::list<Card *>::const_iterator it = tradeArea.begin();
    while (it != tradeArea.end()) {
        Card *card = *it;
        output << *card;
    }
    return output;
}
