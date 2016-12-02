#include <iostream>
#include <string>
#include "player.h"
#include "table.h"
#include "cardFactory.h"

int main() {

    bool loadLastGame = false;

    std::string player1Name("Brandon");
    std::string player2Name("Rushil");

    Table* gameTable;

    CardFactory* factory = CardFactory::getFactory();

    //#####################//
    //####### SETUP #######//
    //#####################//

    if(loadLastGame){
        //load players from last game
    }else{
        gameTable = new Table(player1Name, player2Name, factory);

    }



    return 0;
}