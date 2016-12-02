#include <iostream>
#include <string>
#include "player.h"
#include "deck.h"
#include "cardFactory.h"

int main() {

    bool loadLastGame = false;

    Player* player1;
    Player* player2;

    std::string player1Name("Brandon");
    std::string player2Name("Rushil");

    //#####################//
    //####### SETUP #######//
    //#####################//

    if(loadLastGame){
        //load players from last game
    }else{
        player1 = new Player(player1Name);
        player2 = new Player(player2Name);
    }

    //init deck
    //fill deck
    //draw 5 cards for each hand of each player

    return 0;
}