//
// Created by Brandon Danis on 2016-12-01.
//

#ifndef CSI2372_PROJECT_TABLE_H
#define CSI2372_PROJECT_TABLE_H

#include <iostream>
#include <string>
#include "cardFactory.h"
#include "player.h"
#include "discard_pile.h"
#include "trade_area.h"


class Table {
    Player* player1;
    Player* player2;
    TradeArea* tradeArea;
	DiscardPile *discardPile;
    Deck* deck;
public:
    Table(Player*, Player*, Deck*, TradeArea*, DiscardPile *);
    Table( std::istream&, CardFactory* );
    bool win( std::string& );
    Deck* getDeck();
    TradeArea* getTradeArea();
    void print(std::ostream&) const;
	friend std::ostream& operator<<(std::ostream &, const Table &);
};


#endif //CSI2372_PROJECT_TABLE_H
