//
// Created by silver_android on 29/11/16.
//

#include "hand.h"

Hand::Hand() {

}

Hand::Hand(std::istream &, CardFactory *) {

}

Hand &Hand::operator+=(Card *card) {
    handQueue.push(card);
    return *this;
}

Card *Hand::play() {
    Card *card = new Ruby();
    *card = *top();
    handQueue.pop();
    return card;
}

Card *Hand::top() {
    Card *card = handQueue.front();
    return card;
}

Card *Hand::operator[](int index) {
    std::queue<Card *> temp;
    Card *card;
    for (int i = 0; i < handQueue.size(); ++i) {
        if (i == index)
            card = handQueue.front();
        else
            temp.push(handQueue.front());
        handQueue.pop();
    }
    for (int i = 0; i < temp.size(); ++i) {
        handQueue.push(temp.front());
        temp.pop();
    }
    return card;
}

std::ostream &operator<<(std::ostream &output, const Hand &hand) {
    // TODO: Must find better way to do this
    std::queue<Card *> temp;
    Hand nonConstHand = hand;
    for (int i = 0; i < hand.handQueue.size(); ++i) {
        Card *c = nonConstHand[i];
        output << *c;
        temp.push(c);
    }
    for (int i = 0; i < temp.size(); ++i) {
        nonConstHand.handQueue.push(temp.front());
        temp.pop();
    }
    return output;
}
