//
// Created by Brandon Danis on 2016-12-01.
//

#include "table.h"

Table::Table(Player *player1, Player *player2, Deck *deck) {
    this->player1 = player1;
    this->player2 = player2;
    this->deck = deck;
}

Deck* Table::getDeck() {
    return deck;
}

/* constructor which accepts an std::istream and reconstruct the Table from file */
//Table::Table(std::istream &, CardFactory *) {
//
//}

/* prints the complete table with all content. Intended for serialization to file. */
void Table::print(std::ostream &) {

}