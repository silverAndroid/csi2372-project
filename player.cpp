//
// Created by Brandon Danis on 2016-11-24.
//

#include "player.h"

Player::Player( std::string& name ){
    maxNumOfChains = 2;
    numOfChains = 0;
    playerName = name;
    chains[0] = Chain_Base();
    chains[1] = Chain_Base();
}

Player::Player(std::istream&, CardFactory*) {

}

std::string Player::getName() {
    return playerName;
}

int Player::getNumCoins() {
    return numOfCoins;
}

Player& Player::operator+=(int x) {
    numOfCoins = numOfCoins + x;
    return *this;
}

int Player::getMaxNumChains() {
    return maxNumOfChains;
}

int Player::getNumChains() {
    return numOfChains;
}

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

Chain_Base& Player::operator[](int i) {
    return chains[i];
}

//void Player::printHand(std::ostream &output, bool b) {
//    if(b){
//        //output << hand.top();
//    }else{
//        output << hand;
//    }
//}
