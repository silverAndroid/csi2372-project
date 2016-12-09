//
// Created by silver_android on 29/11/16.
//

#include "trade_area.h"

TradeArea::TradeArea(std::istream &, CardFactory *) {

}

TradeArea &TradeArea::operator+=(Card *card) {
    tradeList.push_back(card); // TODO: Check for any side-effects from using same memory location
    return *this;
}

bool TradeArea::isEmpty() {
    return tradeList.empty();
}

bool TradeArea::legal(Card *card) {
	if (tradeList.size() > 0)
		return false;
    std::list<Card *>::const_iterator it = tradeList.begin();
    while (it != tradeList.end()) {
        Card *card1 = *it;
        if (card->getName() == card1->getName()) {
            return true;
        }
    }
    return false;
}

Card *TradeArea::trade(string cardName) {
    std::list<Card *>::const_iterator it = tradeList.begin();
    while (it != tradeList.end()) {
        Card *card = *it; // TODO: Check if any side effects from using same memory location
        if (cardName == card->getName()) {
            tradeList.remove(card);
            return card;
        }
    }
    return nullptr;
}

int TradeArea::numCards() {
    return (int) tradeList.size();
}

std::ostream &operator<<(std::ostream &output, const TradeArea &tradeArea) {
    std::list<Card *>::const_iterator it = tradeArea.tradeList.begin();
    while (it != tradeArea.tradeList.end()) {
        Card *card = *it;
        output << *card;
		it++;
    }
    return output;
}
