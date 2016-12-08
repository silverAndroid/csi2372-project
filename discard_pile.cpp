//
// Created by silver_android on 29/11/16.
//

#include "discard_pile.h"

DiscardPile::DiscardPile(std::istream &, CardFactory *) {

}

DiscardPile &DiscardPile::operator+=(Card *card) {
    discardVector.push_back(card); // TODO: Check if any side effects from using same memory location
    return *this;
}

Card *DiscardPile::pickUp() {
    Card *top = new Ruby();
    *top = *this->top();
    discardVector.pop_back();
    return top;
}

Card *DiscardPile::top() {
    Card *top = discardVector.back();
    return top;
}

void DiscardPile::print(std::ostream &output) {
    for (int i = 0; i < discardVector.size(); ++i) {
        output << *discardVector[i];
    }
}

std::ostream &operator<<(std::ostream &output, const DiscardPile &discardPile) {
    output << *discardPile.discardVector.back();
    return output;
}
