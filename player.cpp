//
// Created by Brandon Danis on 2016-11-24.
//

#include "player.h"

Player::Player( std::string& name ){
    maxNumOfChains = 2;
    numOfChains = 0;
    playerName = name;
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