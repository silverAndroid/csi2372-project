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

std::ostream &Deck::operator<<(Deck deck) {
    return <#initializer#>;
}
