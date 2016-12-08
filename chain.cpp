//
// Created by silver_android on 23/11/16.
//

#include "chain.h"
#include <typeinfo>

template <typename T>
Chain<T>::Chain(std::istream &, CardFactory *) {

}

template <typename T>
Chain<T>::Chain() {

}

template <typename T>
Chain<T> &Chain<T>::operator+=(Card *card) {
    T *t;
    if ((t = (T *) (dynamic_cast<T *>(card) == nullptr))) {
        //TODO: Need to run test to make sure it works and uses the right types
        throw IllegalTypeException(card->getName(), typeid(T).name());
    } else {
        cards.push_back(t);
    }
    return *this;
}

template <typename T>
T Chain::getCardType() {
    return typeid(T).name();
}

template <typename T>
int Chain<T>::sell() {
    Card *card = cards[0];
    return card->getCardsPerCoin((int) cards.size());
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const Chain<T> &chain) {
    output << chain.cards[0].getName();
    output << string("\t");
    for (int i = 0; i < chain.cards.size(); ++i) {
        output << chain.cards[i];
    }
    return output;
}
