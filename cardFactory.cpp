//
// Created by silver_android on 23/11/16.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include "cardFactory.h"

CardFactory *CardFactory::instance;

CardFactory *CardFactory::getFactory() {
    if (instance == nullptr)
        instance = new CardFactory();
    return instance;
}

Deck CardFactory::getDeck() {
    std::vector<Card *> cards;
    std::ifstream fileReader("../default.txt");
    //TODO: Have to figure out how to shuffle while still using istream
    Card *card = new Ruby();
    while (fileReader >> card) {
        cards.push_back(card);
    }

    std::shuffle(cards.begin(), cards.end(), engine);

    return Deck(cards);
}
