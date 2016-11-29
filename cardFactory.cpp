//
// Created by silver_android on 23/11/16.
//

#include <iostream>
#include <fstream>
#include "cardFactory.h"

CardFactory *CardFactory::getFactory() {
    if (instance == nullptr)
        instance = new CardFactory();
    return instance;
}

Deck CardFactory::getDeck() {
    std::ifstream fileReader;
    fileReader.open("default.txt");
    //TODO: Have to figure out how to shuffle while still using istream
    return Deck(fileReader, this);
}
