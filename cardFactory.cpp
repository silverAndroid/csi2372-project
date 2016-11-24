//
// Created by silver_android on 23/11/16.
//

#include <iostream>
#include <fstream>
#include "cardFactory.h"

CardFactory *CardFactory::getFactory() {
    return nullptr;
}

Deck CardFactory::getDeck() {
    std::ifstream fileReader;
    fileReader.open("default.txt");
    // Have to figure out how to shuffle while still using istream
    return Deck(fileReader, this);
}
