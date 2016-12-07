#include <iostream>
#include <string>
#include "player.h"
#include "table.h"
#include "cardFactory.h"

int main() {

    //////////////////
    /// GAME SETUP ///
    //////////////////

    bool loadLastGame = false;

    std::string player1Name = "Brandon";
    std::string player2Name = "Rushil";

    Table* gameTable;
    Deck gameDeck;
    CardFactory* factory = CardFactory::getFactory();
    Player* player1;
    Player* player2;

    if(loadLastGame){
        //Table *gameTable = new Table(is, factory);
    }else{
        std::cout << "Creating new table" << std::endl;

        player1 = new Player(player1Name);
        player2 = new Player(player2Name);

        gameDeck = factory->getDeck();

        //handing starting cards to players
        for(int i=0; i<5; i++){
            player1->addCardToHand(gameDeck.draw());
            player2->addCardToHand(gameDeck.draw());
        }

        Table *gameTable = new Table(player1, player2, &gameDeck);

    }

    /////////////////
    /// GAME LOOP ///
    /////////////////

    while(!gameDeck.isEmpty()){


        


    }

    /////////////////
    /// GAME OVER ///
    /////////////////

    string winningName;
    if(gameTable->win(winningName)){
        std::cout << winningName << " has won!" << std::endl;
    }


    return 0;
}