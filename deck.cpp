//
// Created by silver_android on 23/11/16.
//

#include "deck.h"

Card *Deck::draw() {
    // To prevent side-effects, allocated drawn card in new location
    Card *card = new Ruby();
    *card = *back();
    pop_back();
    return card;
}

std::ostream &operator<<(std::ostream &output, const Deck &deck) {
    for (int i = 0; i < deck.size(); ++i) {
        output << *deck[i];
    }
    return output;
}

bool Deck::isEmpty() {
    return this->size() == 0;
}

Deck::Deck(std::istream &, CardFactory *) {

}

Deck::Deck(std::vector<Card *> cards) : vector(cards) {

}
