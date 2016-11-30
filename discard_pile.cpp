//
// Created by silver_android on 29/11/16.
//

#include "discard_pile.h"

DiscardPile::DiscardPile(std::istream &, CardFactory *) {

}

DiscardPile::DiscardPile() {

}

DiscardPile &DiscardPile::operator+=(Card *card) {
    push_back(card); // TODO: Check if any side effects from using same memory location
    return *this;
}

Card *DiscardPile::pickUp() {
    Card *top = new Ruby();
    *top = *this->top();
    pop_back();
    return top;
}

Card *DiscardPile::top() {
    Card *top = back();
    return top;
}

void DiscardPile::print(std::ostream &output) {
    for (int i = 0; i < size(); ++i) {
        output << *operator[]((unsigned long) i);
    }
}

std::ostream &operator<<(std::ostream &output, const DiscardPile &discardPile) {
    output << *discardPile.back();
    return output;
}
