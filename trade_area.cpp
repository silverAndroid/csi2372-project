//
// Created by silver_android on 29/11/16.
//

#include "trade_area.h"

TradeArea::TradeArea(std::istream &, CardFactory *) {

}

TradeArea &TradeArea::operator+=(Card *card) {
    tradeList.push_back(card);
    return *this;
}

bool TradeArea::isEmpty() {
    return numCards() == 0;
}

bool TradeArea::legal(Card *card) {
	if (this->isEmpty())
		return false;
    std::list<Card *>::const_iterator it = tradeList.begin();
    while (it != tradeList.end()) {
        Card *card1 = *it;
        if (card->getName() == card1->getName()) {
            return true;
        }
		++it;
    }
    return false;
}

Card *TradeArea::trade(int index) {
	if (this->isEmpty())
		return nullptr;
	std::list<Card *>::const_iterator it = tradeList.begin();
	std::advance(it, index);
	Card *card = *it;
	tradeList.remove(card);
	return card;
}

Card *TradeArea::trade(string cardName) {
	if (this->isEmpty())
		return nullptr;
    std::list<Card *>::const_iterator it = tradeList.begin();
    while (it != tradeList.end()) {
        Card *card = *it;
        if (cardName == card->getName()) {
            tradeList.remove(card);
            return card;
        }
		++it;
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
