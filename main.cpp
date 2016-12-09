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
            Hand *currentHand = currentPlayer->getHand();

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
            if(!gameTradeArea->isEmpty()) {
                //Add gemstone cards from the TradeArea to chains or discard them.
                for (int i = 0; i < currentPlayer->getNumChains(); ++i) {
                    Chain_Base tempChain = (*currentPlayer)[i];
                    auto tempType = tempChain.getCardType();

                }
            }

            //Play topmost card from Hand.
            bool cardPlayed = false;

            for(int i=0; i<currentPlayer->getNumChains(); ++i){
                Chain_Base *tempChain = &((*currentPlayer)[i]);
                auto tempType = tempChain->getCardType();
                auto cardType = currentHand->top()->getName();
                if(tempType == cardType){
                    std::cout << "Found a matching chain for " << cardType << std::endl;
                    if(cardType == "Quartz"){
                        *dynamic_cast<Chain<Quartz>*>(tempChain) += currentHand->play();
                    }else if(cardType == "Hematite"){
                        *dynamic_cast<Chain<Hematite>*>(tempChain) += currentHand->play();
                    }else if(cardType == "Obsidian"){
                        *dynamic_cast<Chain<Obsidian>*>(tempChain) += currentHand->play();
                    }else if(cardType == "Malachite"){
                        *dynamic_cast<Chain<Malachite>*>(tempChain) += currentHand->play();
                    }else if(cardType == "Turquoise"){
                        *dynamic_cast<Chain<Turquoise>*>(tempChain) += currentHand->play();
                    }else if(cardType == "Ruby"){
                        *dynamic_cast<Chain<Ruby>*>(tempChain) += currentHand->play();
                    }else if(cardType == "Amethyst"){
                        *dynamic_cast<Chain<Amethyst>*>(tempChain) += currentHand->play();
                    }else if(cardType == "Emerald"){
                        *dynamic_cast<Chain<Emerald>*>(tempChain) += currentHand->play();
                    }
                    cardPlayed = true;
                    break;
                }
            }

            if(!cardPlayed){
                if(currentPlayer->getMaxNumChains() == currentPlayer->getNumChains()){
					int index = 0;
					std::cout << "You have reached the maximum amount of chains allowed. Which chain would you like to remove?";
					std::cin >> index;
					currentPlayer->removeChain(index);
                }
				currentPlayer->createNewChain(currentHand->play());
			}

            //If chain is ended, cards for chain are removed and player receives coin(s).

            //If player decides to
                    //Play the now topmost card from Hand.

            //If chain is ended, cards for chain are removed and player receives coin(s).

            //If player decides to
                    //Show the player's full hand and player selects an arbitrary card
                    //Discard the arbitrary card from the player's hand and place it on the discard pile.

            //Draw three cards from the deck and place cards in the trade area
            *gameTradeArea += gameDeck.draw();
            *gameTradeArea += gameDeck.draw();
            *gameTradeArea += gameDeck.draw();

            //while top card of discard pile matches an existing card in the trade area
            while(gameTradeArea->legal(gameDiscardPile->top())){
                //draw the top-most card from the discard pile and place it in the trade area
                *gameTradeArea += gameDiscardPile->pickUp();
            }

            //for all cards in the trade area
                //if player wants to chain the card
                    //chain the card
                    //If chain is ended
                        //cards for chain are removed and player receives coin(s).
                //else
                    //card remains in trade area for the next player.
            //end

            //Draw two cards from Deck and add the cards to the player's hand (at the back)
            currentPlayer->addCardToHand(gameDeck.draw());
            currentPlayer->addCardToHand(gameDeck.draw());

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