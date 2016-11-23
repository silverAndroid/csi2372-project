//
// Created by silver_android on 23/11/16.
//

#include "chain.h"

template <typename T>
Chain<T> &Chain<T>::operator+=(Card *) {
    return *this;
}

template <typename T>
int Chain<T>::sell() {
    return 0;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const Chain<T> &chain) {
    return output;
}
