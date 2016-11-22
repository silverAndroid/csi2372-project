//
// Created by silver_android on 21/11/16.
//

#ifndef CSI2372_PROJECT_CHAIN_H
#define CSI2372_PROJECT_CHAIN_H

#include <vector>
#include "card.h"

template <typename T> class Chain {
private:
    std::vector<T*> chain;
public:
    Chain(std::istream&, CardFactory*);
    Chain<T>&operator+=(Card*);
    int sell();
};


#endif //CSI2372_PROJECT_CHAIN_H
