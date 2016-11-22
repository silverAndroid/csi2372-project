//
// Created by silver_android on 21/11/16.
//

#include "deck.h"

Card *Deck::draw() {
    Card *card = new Ruby();
    *card = back();
    pop_back();
    return card;
}

Deck::Deck() {

}

friend std::ostream &Deck::operator<<(std::ostream &output, Deck &deck) {
    for (int i = 0; i < deck.size(); ++i) {
        output << deck[i];
    }
    return output;
}
