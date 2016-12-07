//
// Created by Brandon Danis on 2016-12-01.
//

#include "table.h"

Table::Table(string player1Name, string player2Name, CardFactory *cardFactory) {
    player1 = new Player(player1Name);
    player2 = new Player(player2Name);
    factory = cardFactory;

    deck = factory->getDeck();

    std::cout << "Deck: " << deck << std::endl;

    for(int i=0; i<5; ++i){
        player1->addCardToHand(deck.draw());
        player2->addCardToHand(deck.draw());
    }

}

Deck* Table::getDeck() {
    return &deck;
}

/* constructor which accepts an std::istream and reconstruct the Table from file */
//Table::Table(std::istream &, CardFactory *) {
//
//}

/* prints the complete table with all content. Intended for serialization to file. */
void Table::print(std::ostream &) {

}