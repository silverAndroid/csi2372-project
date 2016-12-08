//
// Created by silver_android on 23/11/16.
//

#ifndef CSI2372_PROJECT_CHAIN_H
#define CSI2372_PROJECT_CHAIN_H

#include <vector>
#include <typeinfo>
#include "gemstones.h"
#include "cardFactory.h"

class Chain_Base {

};

template <typename T>
class Chain : Chain_Base {
    std::vector<T*> cards;
public:
    Chain(std::istream &, CardFactory *) {

    }

    Chain() {

    }

    Chain &operator+=(Card *card) {
        T *t;
        if ((t = (T *) (dynamic_cast<T *>(card) == nullptr))) {
            //TODO: Need to run test to make sure it works and uses the right types
            throw IllegalTypeException(card->getName(), typeid(T).name());
        } else {
            cards.push_back(t);
        }
        return *this;
    }

    T getCardType() {
        return typeid(T).name();
    }

    int sell() {
        Card *card = cards[0];
        return card->getCardsPerCoin((int) cards.size());
    }

    friend std::ostream &operator<<(std::ostream &output, const Chain &chain);
};

template <typename T>
std::ostream &operator<<(std::ostream &output, const Chain<T> &chain) {
    output << chain.cards[0].getName();
    output << string("\t");
    for (int i = 0; i < chain.cards.size(); ++i) {
        output << chain.cards[i];
    }
    return output;
}


#endif //CSI2372_PROJECT_CHAIN_H
