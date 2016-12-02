//
// Created by Brandon Danis on 2016-11-24.
//

#include "player.h"

// constructor that creates a Player with a given name
Player::Player( std::string& name ){
    maxNumOfChains = 2;
    numOfChains = 0;
    playerName = name;
    chains[0] = Chain_Base();
    chains[1] = Chain_Base();
}

// constructor which accepts an std::istream and reconstruct the Player from file.
Player::Player(std::istream&, CardFactory*) {

}

// get the name of the player
std::string Player::getName() {
    return playerName;
}

// get the number of coins currently held by the player
int Player::getNumCoins() {
    return numOfCoins;
}

// add a number of coins
Player& Player::operator+=(int x) {
    numOfCoins = numOfCoins + x;
    return *this;
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
    chains[2] = Chain_Base();
}

// returns the chain at position i.
Chain_Base& Player::operator[](int i) {
    return chains[i];
}

/* prints the top card of the player's hand (with
argument false) or all of the player's hand (with argument true) to the supplied std::ostream */
//void Player::printHand(std::ostream &output, bool b) {
//    if(b){
//        //output << hand.top();
//    }else{
//        output << hand;
//    }
//}
