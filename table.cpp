//
// Created by Brandon Danis on 2016-12-01.
//

#include "table.h"

Table::Table(Player *player1, Player *player2, Deck *deck, TradeArea *trade, DiscardPile *discard) {
    this->player1 = player1;
    this->player2 = player2;
    this->deck = deck;
    this->tradeArea = trade;
	this->discardPile = discard;
}

Deck* Table::getDeck() {
    return deck;
}

TradeArea* Table::getTradeArea() {
    return tradeArea;
}

/* constructor which accepts an std::istream and reconstruct the Table from file */
//Table::Table(std::istream &, CardFactory *) {
//
//}

bool Table::win(std::string &winningName) {
    if(deck->isEmpty()){
        if(player1->getNumCoins() == player2->getNumCoins()){
            winningName = "Both players";
        }else if(player1->getNumCoins() > player2->getNumCoins()){
            winningName = player1->getName();
        }else{
            winningName = player2->getName();
        }
        return true;
    }
    return false;
}

/* prints the complete table with all content. Intended for serialization to file. */
void Table::print(std::ostream &output) const {
	output << *player1 << *player2 << *discardPile << *tradeArea;
}

std::ostream &operator<<(std::ostream &output, const Table &table) {
	table.print(output);
	return output;
}