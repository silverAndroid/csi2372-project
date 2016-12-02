//
// Created by Brandon Danis on 2016-12-01.
//

#include "table.h"

Table::Table(string player1Name, string player2Name, CardFactory *factory) {
    player1 = new Player(player1Name);
    player2 = new Player(player2Name);
    tradeArea = new TradeArea();
    deck = new Deck();
}

/* constructor which accepts an std::istream and reconstruct the Table from file */
//Table::Table(std::istream &, CardFactory *) {
//
//}

/* prints the complete table with all content. Intended for serialization to file. */
void Table::print(std::ostream &) {

}