//
// Created by silver_android on 29/11/16.
//

#include "discard_pile.h"

DiscardPile::DiscardPile(std::istream &, CardFactory *) {

}

DiscardPile &DiscardPile::operator+=(Card *card) {
    discardVector.push_back(card);
    return *this;
}

bool DiscardPile::isEmpty() {
	return discardVector.empty();
}

Card *DiscardPile::pickUp() {
	Card *top = this->top();
	if (top != nullptr)
		discardVector.pop_back();
	return top;
}

Card *DiscardPile::top() {
    Card *top = nullptr;
	if (!this->isEmpty())
		top = discardVector.back();
    return top;
}

void DiscardPile::print(std::ostream &output) {
    for (int i = 0; i < discardVector.size(); ++i) {
        output << *discardVector[i];
    }
}

std::ostream &operator<<(std::ostream &output, const DiscardPile &discardPile) {
	if (discardPile.discardVector.size() > 0)
		output << *(discardPile.discardVector.back());
    return output;
}
