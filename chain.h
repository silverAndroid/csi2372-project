//
// Created by silver_android on 23/11/16.
//

#ifndef CSI2372_PROJECT_CHAIN_H
#define CSI2372_PROJECT_CHAIN_H

#include <vector>
#include "gemstones.h"
#include "cardFactory.h"

template <typename T>
class Chain : std::vector<T> {
public:
    Chain(std::istream &, CardFactory *);
    Chain<T>&operator+=(Card *);
    int sell();
    friend std::ostream& operator<<(std::ostream &, const Chain<T> &);
};


#endif //CSI2372_PROJECT_CHAIN_H
