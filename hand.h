//
// Created by silver_android on 29/11/16.
//

#ifndef CSI2372_PROJECT_HAND_H
#define CSI2372_PROJECT_HAND_H


#include <vector>
#include <queue>
#include "gemstones.h"
#include "cardFactory.h"

class Hand {
public:
    Hand();
    Hand &operator+=(Card *);
    Card *play();
    Card *top();
    Card *operator[](int);
    friend std::ostream &operator<<(std::ostream &, const Hand &);
    Hand();
    Hand(std::istream &, CardFactory *);
    template<typename T>
    struct custom_vector : std::vector<T> {
        using base = std::vector<T> ;
        using base::vector;
        using typename base::value_type ;
        using base::empty ;
        using base::size ;
        using base::front ;
        using base::back ;
        using base::push_back ;
        void pop_front() {
            this->erase(this->begin());
        }
    };
private:
    std::queue<Card *, custom_vector<Card *>> handQueue;
};

#endif //CSI2372_PROJECT_HAND_H
