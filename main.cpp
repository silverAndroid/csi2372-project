#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
#include "table.h"
#include "cardFactory.h"

Chain_Base *getChain(string cardType) ;

void displayMessage(std::string message) ;

using std::cout;
using std::cin;
using std::endl;

int main() {

	//TODO: Do some error validation

	//////////////////
	/// GAME SETUP ///
	//////////////////

	std::ifstream saveData("gameData.sav");
	bool loadLastGame = saveData.good();
	saveData.close();
	bool firstLoop = true;

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
		if (!firstLoop) {
			cout << "Would you like to save and exit the game? ";
			cin >> response;
			if (response == 'Y') {
				std::ofstream saveFile;
				saveFile.open("gameData.sav");
				saveFile << *gameTable;
				saveFile << "Deck: " << gameDeck;
				saveFile.close();
				return 0;
			}
		}

		firstLoop = false;

		//For each Player
		for (Player* currentPlayer : { player1,player2 }) {
			displayMessage(currentPlayer->getName() + "\'s turn");
			Hand *currentHand = currentPlayer->getHand();
			bool cardPlayed = false;

			//Display Table
			cout << *gameTable << endl;

			//If Player has 3 coins and two chains and decides to buy extra chain
			if (currentPlayer->getNumCoins() > 2 && currentPlayer->getMaxNumChains() == 2) {
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
			while (!gameTradeArea->isEmpty()) {
				//Add gemstone cards from the TradeArea to chains or discard them.
				cout << "Trade Area: " << *gameTradeArea << std::endl;
				cout << "Would you like to add a card from the trade area to a chain? Any remaining cards will be sent to the discard pile. 'Y' for yes" << endl;
				cin >> response;
				if (response != 'Y') {
					response = 0;
					break;
				}
				response = 0;

				cout << "Which card do you want to chain? (Enter index)" << endl;
				int index = 0;
				cin >> index; 
				cardPlayed = false;
				Card *tradedCard = gameTradeArea->trade(index - 1);

				for (int i = 0; i < currentPlayer->getNumChains(); ++i) {
					Chain_Base *tempChain = &((*currentPlayer)[i]);
					string tempType = tempChain->getCardType();
					string cardType = tradedCard->getName();
					if (tempType == cardType) {
                        tempChain = getChain(cardType);
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
						int coinsAdded = 0;
						Chain_Base *removedChain = currentPlayer->removeChain(index - 1, coinsAdded);
						//If chain is ended, cards for chain are removed and player receives coin(s).
						cout << "Sold for " << coinsAdded << " coins" << endl;
					}
					currentPlayer->createNewChain(tradedCard);
					cardPlayed = true;
				}
			}

			//Discarding all cards in trade area
			while (!gameTradeArea->isEmpty()) {
				*gameDiscardPile += gameTradeArea->trade(0);
			}

			//Play topmost card from Hand.
			cardPlayed = false;

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
					string tempType = tempChain->getCardType();
					string cardType = currentHand->top()->getName();
					if (tempType == cardType) {
						tempChain = getChain(cardType);
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
						int coinsAdded = 0;
						Chain_Base *removedChain = currentPlayer->removeChain(index - 1, coinsAdded);
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
				cout << "Which card do you want to discard? (Enter index) " << endl;
				cin >> index;
				Card *discardedCard = (*currentHand)[index - 1];
				*gameDiscardPile += discardedCard;
			}

			//Draw three cards from the deck and place cards in the trade area
			for (size_t i = 0; i < 3; i++)
			{
				*gameTradeArea += gameDeck.draw();
			}

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
					Chain_Base *tempChain = &(currentPlayer->operator[](i));
					string tempType = tempChain->getCardType();
					string cardType = tradedCard->getName();
					if (tempType == cardType) {
                        tempChain = getChain(cardType);
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
						int coinsAdded = 0;
						Chain_Base *removedChain = currentPlayer->removeChain(index - 1, coinsAdded);
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

Chain_Base *getChain(string cardType) {
	Chain_Base *tempChain = new Chain_Base();
	cout << "Found a matching chain for " << cardType << endl;
	if (cardType == "Quartz") {
		dynamic_cast<Chain<Quartz> *>(tempChain);
	}
	else if (cardType == "Hematite") {
		dynamic_cast<Chain<Hematite> *>(tempChain);
	}
	else if (cardType == "Obsidian") {
		dynamic_cast<Chain<Obsidian> *>(tempChain);
	}
	else if (cardType == "Malachite") {
		dynamic_cast<Chain<Malachite> *>(tempChain);
	}
	else if (cardType == "Turquoise") {
		dynamic_cast<Chain<Turquoise> *>(tempChain);
	}
	else if (cardType == "Ruby") {
		dynamic_cast<Chain<Ruby> *>(tempChain);
	}
	else if (cardType == "Amethyst") {
		dynamic_cast<Chain<Amethyst> *>(tempChain);
	}
	else if (cardType == "Emerald") {
		dynamic_cast<Chain<Emerald> *>(tempChain);
	} else {
        throw IllegalTypeException(cardType, "Quartz, Hematite, Obsidian, Malachite, Turquoise, Ruby, Amethyst, or Emerald");
    }
    return tempChain;
}

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