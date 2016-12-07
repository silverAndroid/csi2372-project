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
    handVector.push_back(card);
    return *this;
}

Card *Hand::play() {
    Card *card = new Ruby();
    *card = *top();
    handQueue.pop();
    handVector.pop_back();
    return card;
}

Card *Hand::top() {
    Card *card = handQueue.front();
    return card;
}

Card *Hand::operator[](int index) {
    Card *card = handVector[index];
    handVector.erase(handVector.begin() + index);
    handVector.shrink_to_fit(); // This releases the memory allocated by the vector, see http://www.acodersjourney.com/2016/11/6-tips-supercharge-cpp-11-vector-performance/
    handQueue = std::queue<Card *>(std::deque<Card *>(handVector.begin(), handVector.end()));
    return card;
}

std::ostream &operator<<(std::ostream &output, const Hand &hand) {
    for (int i = 0; i < hand.handVector.size(); ++i) {
        output << *hand.handVector[i];
    }
    return output;
}
