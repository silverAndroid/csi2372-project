//
// Created by Brandon Danis on 2016-11-24.
//

#include "player.h"

// constructor that creates a Player with a given name
Player::Player(const std::string& name ): playerName(name) {
    maxNumOfChains = 2;
    numOfChains = 0;
    numOfCoins = 0;
    chains.push_back(new Chain_Base());
    chains.push_back(new Chain_Base());
}

// constructor which accepts an std::istream and reconstruct the Player from file.
Player::Player(std::istream&, CardFactory*) {

}

// get the name of the player
std::string Player::getName() const {
    return playerName;
}

void Player::addCardToHand(Card *card) {
    hand += card;
}

// get the number of coins currently held by the player
int Player::getNumCoins() const {
    return numOfCoins;
}

void Player::createNewChain(Card *card) {
    if(numOfChains < maxNumOfChains){

        string cardType = card->getName();

        Chain_Base* newChain;

        if(cardType == "Quartz"){
            newChain = new Chain<Quartz>();
            *dynamic_cast<Chain<Quartz>*>(newChain) += card;
        }else if(cardType == "Hematite"){
            newChain = new Chain<Hematite>();
            *dynamic_cast<Chain<Hematite>*>(newChain) += card;
        }else if(cardType == "Obsidian"){
            newChain = new Chain<Obsidian>();
            *dynamic_cast<Chain<Obsidian>*>(newChain) += card;
        }else if(cardType == "Malachite"){
            newChain = new Chain<Malachite>();
            *dynamic_cast<Chain<Malachite>*>(newChain) += card;
        }else if(cardType == "Turquoise"){
            newChain = new Chain<Turquoise>();
            *dynamic_cast<Chain<Turquoise>*>(newChain) += card;
        }else if(cardType == "Ruby"){
            newChain = new Chain<Ruby>();
            *dynamic_cast<Chain<Ruby>*>(newChain) += card;
        }else if(cardType == "Amethyst"){
            newChain = new Chain<Amethyst>();
            *dynamic_cast<Chain<Amethyst>*>(newChain) += card;
        }else if(cardType == "Emerald"){
            newChain = new Chain<Emerald>();
            *dynamic_cast<Chain<Emerald>*>(newChain) += card;
        }

        chains[numOfChains++] = newChain;

        std::cout << "Creating new chain of type " << newChain->getCardType() << std::endl;

    }
}

void Player::removeChain(int index) {
	chains.erase(chains.begin() + index);
	chains.shrink_to_fit();
	--numOfChains;
}

// add a number of coins
Player& Player::operator+=(int x) {
    numOfCoins = numOfCoins + x;
    return *this;
}

Hand* Player::getHand() {
    return &hand;
}

// returns either 2 or 3.
int Player::getMaxNumChains() {
    return maxNumOfChains;
}

// returns the number of non-zero chains
int Player::getNumChains() {
    return numOfChains;
}

/*  adds an empty third chain to the player for two coins. The functions
reduces the coin count for the player by two. If the player does not have enough coins then an exception
NotEnoughCoins is thrown */
void Player::buyThirdChain(){
    if(numOfCoins < 2) {
        //throw exception
    }else if(maxNumOfChains == 3){
        std::cout << "Already have 3 chains. Can't buy another." << std::endl;
        return;
    }
    numOfCoins -= 2;
    maxNumOfChains++;
    chains.push_back(new Chain_Base());
}

// returns the chain at position i.
Chain_Base& Player::operator[](int i) {
    return *(chains[i]);
}

/* prints the top card of the player's hand (with
argument false) or all of the player's hand (with argument true) to the supplied std::ostream */
void Player::printHand(std::ostream &output, bool b) {
    if(b){
        output << *hand.top();
    }else{
        output << hand;
    }
}

std::ostream &operator<<(std::ostream &output, Player &player) {
	output << player.getName() << "\t" << player.getNumCoins() << " coins" << std::endl;
	for (size_t i = 0; i < player.chains.size(); i++)
	{
		//output << player.chains[i] << std::endl;
	}
	return output;
}
