#include <iostream>
#include <string>
#include "player.h"
#include "table.h"
#include "cardFactory.h"

using std::cout;
using std::cin;
using std::endl;

void displayMessage(std::string message) {
	int length = message.size() + 18;
	string topLine = "";
	string middleLine = "";
	string messageLine = "";
	const string eightSpaces = "        ";
	std::transform(message.begin(), message.end(), message.begin(), ::toupper);

	for (size_t i = 0; i < length; i++)
	{
		topLine += "=";
	}

	for (size_t i = 0; i < length; i++)
	{
		bool isEqualSign = i == 0 || i == length - 1;
		middleLine += isEqualSign ? "=" : " ";
	}

	messageLine += "=";
	messageLine += eightSpaces;
	messageLine += message;
	messageLine += eightSpaces; 
	messageLine += "=";

	cout << endl;
	cout << topLine << endl;
	cout << middleLine << endl;
	cout << messageLine << endl;
	cout << middleLine << endl;
	cout << topLine << endl;
	cout << endl;
}

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

	if (loadLastGame) {
		//Table *gameTable = new Table(is, factory);
	}
	else {
		cout << "Creating new table" << endl;

		player1 = new Player(player1Name);
		player2 = new Player(player2Name);

		gameDeck = factory->getDeck();

		//handing starting cards to players
		for (int i = 0; i < 5; i++) {
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

	string winningName;

	//While there are still cards on the Deck
	while (!gameTable->win(winningName)) {

		//if pause save game to file and exit
		//TODO: Implement saving entire game

		//For each Player
		for (Player* currentPlayer : { player1,player2 }) {
			displayMessage(currentPlayer->getName() + "\'s turn");
			Hand *currentHand = currentPlayer->getHand();

			//Display Table
			//TODO: Display table
			cout << *gameTable << endl;

			//If Player has 3 coins and two chains and decides to buy extra chain
			if (currentPlayer->getNumCoins() > 2 && currentPlayer->getMaxNumChains() == 2) {
				//TODO: Offer to buy chain
				cout << "Would you like to buy a third chain? 'Y' for yes" << endl;
				cin >> response;

				//Add chain to player
				if (response == 'Y') {
					currentPlayer->buyThirdChain();
					cout << "You have purchased a third chain!" << endl;
				}
				response = 0;
			}

			//Player draws top card from Deck
			currentPlayer->addCardToHand(gameDeck.draw());

			//If TradeArea is not empty
			if (!gameTradeArea->isEmpty()) {
				//Add gemstone cards from the TradeArea to chains or discard them.
				for (int i = 0; i < currentPlayer->getNumChains(); ++i) {
					Chain_Base tempChain = (*currentPlayer)[i];
					auto tempType = tempChain.getCardType();

				}
			}

			//Play topmost card from Hand.
			bool cardPlayed = false;

			for (int k = 0; k < 2; ++k) {

				cout << "The top card in your hand is a " << currentHand->top()->getName() << " card" << endl;
				if (cardPlayed) {
					cout << "Would you like to play your top card? 'Y' for yes" << endl;
					cin >> response;
					if (response != 'Y') {
						response = 0;
						break;
					}
					response = 0;
					cardPlayed = false;
				}

				for (int i = 0; i < currentPlayer->getNumChains(); ++i) {
					Chain_Base *tempChain = &((*currentPlayer)[i]);
					auto tempType = tempChain->getCardType();
					auto cardType = currentHand->top()->getName();
					if (tempType == cardType) {
						cout << "Found a matching chain for " << cardType << endl;
						if (cardType == "Quartz") {
							*dynamic_cast<Chain<Quartz> *>(tempChain) += currentHand->play();
						}
						else if (cardType == "Hematite") {
							*dynamic_cast<Chain<Hematite> *>(tempChain) += currentHand->play();
						}
						else if (cardType == "Obsidian") {
							*dynamic_cast<Chain<Obsidian> *>(tempChain) += currentHand->play();
						}
						else if (cardType == "Malachite") {
							*dynamic_cast<Chain<Malachite> *>(tempChain) += currentHand->play();
						}
						else if (cardType == "Turquoise") {
							*dynamic_cast<Chain<Turquoise> *>(tempChain) += currentHand->play();
						}
						else if (cardType == "Ruby") {
							*dynamic_cast<Chain<Ruby> *>(tempChain) += currentHand->play();
						}
						else if (cardType == "Amethyst") {
							*dynamic_cast<Chain<Amethyst> *>(tempChain) += currentHand->play();
						}
						else if (cardType == "Emerald") {
							*dynamic_cast<Chain<Emerald> *>(tempChain) += currentHand->play();
						}
						cardPlayed = true;
						break;
					}
				}

				if (!cardPlayed) {
					if (currentPlayer->getMaxNumChains() == currentPlayer->getNumChains()) {
						int index = 0;
						cout
							<< "You have reached the maximum amount of chains allowed. Which chain would you like to remove? (Enter index)"
							<< endl;
						for (size_t i = 0; i < currentPlayer->getNumChains(); i++) {
							cout << "Chain " << (i + 1) << ": ";
							cout << currentPlayer->operator[](i) << endl;
						}
						cin >> index;
						int coinsAdded = currentPlayer->removeChain(index - 1);
						//If chain is ended, cards for chain are removed and player receives coin(s).
						cout << "Sold for " << coinsAdded << " coins" << endl;
					}
					currentPlayer->createNewChain(currentHand->play());
					cardPlayed = true;
				}

				//If player decides to
						//Play the now topmost card from Hand.

				//If chain is ended, cards for chain are removed and player receives coin(s).

			}

			//If player decides to
					//Show the player's full hand and player selects an arbitrary card
					//Discard the arbitrary card from the player's hand and place it on the discard pile.
			cout << "Would you like to see your hand? If you do, you will have to select a card and put it in the discard pile." << endl;
			cin >> response;

			if (response == 'Y') {
				cout << "Hand: " << *currentHand << endl;
				int index = 0;
				cout << "Please select a card to go into the discard pile (Enter index): ";
				cin >> index;
				Card *discardedCard = (*currentHand)[index - 1];
				*gameDiscardPile += discardedCard;
			}

			//Draw three cards from the deck and place cards in the trade area
			*gameTradeArea += gameDeck.draw();
			*gameTradeArea += gameDeck.draw();
			*gameTradeArea += gameDeck.draw();

			//while top card of discard pile matches an existing card in the trade area
			while (!gameDiscardPile->isEmpty() && gameTradeArea->legal(gameDiscardPile->top())) {
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

			while (!gameTradeArea->isEmpty()) {
				cout << "Trade Area: " << *gameTradeArea << std::endl;
				cout << "Would you like to add a card from the trade area to a chain? 'Y' for yes" << endl;
				cin >> response;
				if (response != 'Y') {
					response = 0;
					break;
				}
				response = 0;

				int index = 0;
				cout << "Which card would you like to add to the chain? (Enter index)" << endl;
				cin >> index;
				cardPlayed = false;
				Card *tradedCard = gameTradeArea->trade(index - 1);

				for (int i = 0; i < currentPlayer->getNumChains(); ++i) {
					Chain_Base *tempChain = &((*currentPlayer)[i]);
					auto tempType = tempChain->getCardType();
					auto cardType = tradedCard->getName();
					if (tempType == cardType) {
						cout << "Found a matching chain for " << cardType << endl;
						if (cardType == "Quartz") {
							*dynamic_cast<Chain<Quartz> *>(tempChain) += tradedCard;
						}
						else if (cardType == "Hematite") {
							*dynamic_cast<Chain<Hematite> *>(tempChain) += tradedCard;
						}
						else if (cardType == "Obsidian") {
							*dynamic_cast<Chain<Obsidian> *>(tempChain) += tradedCard;
						}
						else if (cardType == "Malachite") {
							*dynamic_cast<Chain<Malachite> *>(tempChain) += tradedCard;
						}
						else if (cardType == "Turquoise") {
							*dynamic_cast<Chain<Turquoise> *>(tempChain) += tradedCard;
						}
						else if (cardType == "Ruby") {
							*dynamic_cast<Chain<Ruby> *>(tempChain) += tradedCard;
						}
						else if (cardType == "Amethyst") {
							*dynamic_cast<Chain<Amethyst> *>(tempChain) += tradedCard;
						}
						else if (cardType == "Emerald") {
							*dynamic_cast<Chain<Emerald> *>(tempChain) += tradedCard;
						}
						cardPlayed = true;
						break;
					}
				}

				if (!cardPlayed) {
					if (currentPlayer->getMaxNumChains() == currentPlayer->getNumChains()) {
						index = 0;
						cout
							<< "You have reached the maximum amount of chains allowed. Which chain would you like to remove?"
							<< endl;
						for (size_t i = 0; i < currentPlayer->getNumChains(); i++) {
							cout << "Chain " << (i + 1) << ": ";
							cout << currentPlayer->operator[](i) << endl;
						}
						cin >> index;
						int coinsAdded = currentPlayer->removeChain(index - 1);
						//If chain is ended, cards for chain are removed and player receives coin(s).
						cout << "Sold for " << coinsAdded << " coins" << endl;
					}
					currentPlayer->createNewChain(tradedCard);
					cardPlayed = true;
				}
			}

			//Draw two cards from Deck and add the cards to the player's hand (at the back)
			currentPlayer->addCardToHand(gameDeck.draw());
			currentPlayer->addCardToHand(gameDeck.draw());
			cout << currentPlayer->getName() << "\'s turn has ended!" << endl;
		}
	}

	/////////////////
	/// GAME OVER ///
	/////////////////

	cout << winningName << " has won!" << endl;
	return 0;
}