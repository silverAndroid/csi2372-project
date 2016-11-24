//
// Created by silver_android on 23/11/16.
//

#include "deck.h"

Card *Deck::draw() {
    Card *card = new Ruby();
    *card = *operator[](0);
    return card;
}

std::ostream &operator<<(std::ostream &output, const Deck &deck) {
    for (int i = 0; i < deck.size(); ++i) {
        output << *deck[i];
    }
    return output;
}

Deck::Deck(std::istream &, CardFactory *) {

}
