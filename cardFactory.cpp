//
// Created by silver_android on 23/11/16.
//

#include <iostream>
#include "cardFactory.h"

CardFactory *CardFactory::getFactory() {
    return nullptr;
}

Deck CardFactory::getDeck() {
    return Deck(std::cin, nullptr);
}
