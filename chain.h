//
// Created by silver_android on 23/11/16.
//

#ifndef CSI2372_PROJECT_CHAIN_H
#define CSI2372_PROJECT_CHAIN_H

#include <vector>
#include <typeinfo>
#include <regex>
#include "gemstones.h"
#include "cardFactory.h"

class Chain_Base {
public:
    virtual string getCardType() {
        return "Chain_Base"; // Can't make pure virtual or class will become abstract and defeat the purpose of this base class
    }

    virtual void print(std::ostream &output) const {
        output << "Chain_Base";
    }

    friend std::ostream &operator<<(std::ostream &, const Chain_Base &);
};

template<typename T>
class Chain : public Chain_Base {
    std::vector<T *> cards;
    bool numBeginning = true;
public:
    Chain(std::istream &, CardFactory *) {

    }

    Chain() {

    }

    Chain &operator+=(Card *card) {
        T *t = dynamic_cast<T *>(card);
        if (t == nullptr) {
            //TODO: Need to run test to make sure it works and uses the right types
            throw IllegalTypeException(card->getName(), typeid(T).name());
        } else {
            cards.push_back(t);
        }
        return *this;
    }

    string getCardType() {
        string className = typeid(T).name();
        const string remove = "class ";
        size_t start = className.find(remove);
        if (start == std::string::npos)
            return className;
        className.replace(start, remove.length(), "");
        std::regex regExpress("(^[\\d-]*)");
        std::regex_replace(className, regExpress, "");
        return className;
    }

    bool removeNumFromBeginning(char c) {
        if (isalpha(c)) {
            numBeginning = false;
        }
        return numBeginning;
    }

    int sell() {
        Card *card = cards[0];
        return card->getCardsPerCoin((int) cards.size());
    }

	void print(std::ostream &output) const {
		for (int i = 0; i < cards.size(); ++i) {
			Card *card = cards[i];
			output << card->getName();
			output << string("\t");
			output << *card;
		}
	}
};

inline std::ostream &operator<<(std::ostream &output, const Chain_Base &chainBase) {
    chainBase.print(output);
    return output;
}


#endif //CSI2372_PROJECT_CHAIN_H
