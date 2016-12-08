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

    //used in game loop
    char response;

    Table* gameTable;
    Deck gameDeck;
    CardFactory* factory = CardFactory::getFactory();
    Player* player1;
    Player* player2;
    TradeArea* gameTradeArea;
	DiscardPile *gameDiscardPile;

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

        gameTradeArea = new TradeArea();
		gameDiscardPile = new DiscardPile();

        gameTable = new Table(player1, player2, &gameDeck, gameTradeArea, gameDiscardPile);

    }

    /////////////////
    /// GAME LOOP ///
    /////////////////

    //While there are still cards on the Deck
    while(!gameDeck.isEmpty()){

        //if pause save game to file and exit
        //TODO: Implement saving entire game

        //For each Player
        for(Player* currentPlayer : {player1,player2}){

            //Display Table
            //TODO: Display table
			std::cout << *gameTable << std::endl;

            //If Player has 3 coins and two chains and decides to buy extra chain
            if(currentPlayer->getNumCoins() > 2 && currentPlayer->getMaxNumChains() == 2){
                //TODO: Offer to buy chain
                std::cout << "Would you like to buy a third chain? 'Y' for yes" << std::endl;
                std::cin >> response;

                //Add chain to player
                if(response == 'Y'){
                    currentPlayer->buyThirdChain();
                    std::cout << "You have purchased a third chain!" << std::endl;
                }

            }

            //Player draws top card from Deck
            currentPlayer->addCardToHand(gameDeck.draw());

            //If TradeArea is not empty
            if(!gameTradeArea->isEmpty()){
                //Add gemstone cards from the TradeArea to chains or discard them.
                for(int i=0; i<currentPlayer->getNumChains(); ++i){
                    Chain_Base tempChain = (*currentPlayer)[i];
                    auto tempType = tempChain.getCardType();



                }
            }

        }

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