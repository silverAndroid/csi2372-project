#include <iostream>
#include <string>
#include "player.h"
#include "table.h"
#include "cardFactory.h"

int main() {

    bool loadLastGame = false;

    Table* gameTable;
    Deck* gameDeck;
    CardFactory* factory = CardFactory::getFactory();

    if(loadLastGame){
        //Table *table = new Table(is, factory);
    }else{
        std::cout << "Creating new table" << std::endl;
        Table *table = new Table("Brandon", "Rushil", factory);
    }

    gameDeck = (*gameTable).getDeck();

    while(!(*gameDeck).isEmpty()){

    }


    return 0;
}