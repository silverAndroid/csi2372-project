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
    Deck* deck;
public:
    Table(string player1Name, string player2Name, CardFactory* factory);
    Table( std::istream&, CardFactory* );
    bool win( std::string& );
    void print(std::ostream&);
    std::ostream& operator<<(std::ostream &, const Table &);
};


#endif //CSI2372_PROJECT_TABLE_H
