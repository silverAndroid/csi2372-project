//
// Created by silver_android on 23/11/16.
//

#include "chain.h"
#include <typeinfo>

template <typename T>
Chain<T> &Chain<T>::operator+=(Card *card) {
    if (T t = dynamic_cast<T>(*card) == nullptr) {
        //TODO: Need to run test to make sure it works
        throw IllegalTypeException(card->getName(), typeid(T).name());
    } else {
        push_back(card);
    }
    return *this;
}

template <typename T>
int Chain<T>::sell() {
    Card card = operator[](0);
    return card.getCardsPerCoin((int) size());
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const Chain<T> &chain) {
    output << chain[0].getName() << "      ";
    for (int i = 0; i < chain.size(); ++i) {
        output << chain[i];
    }
    return output;
}

template <typename T>
Chain<T>::Chain(std::istream &, CardFactory *) {

}
