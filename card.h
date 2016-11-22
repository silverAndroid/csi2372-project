//
// Created by silver_android on 21/11/16.
//

#include <string>
#ifndef CSI2372_PROJECT_CARD_H
#define CSI2372_PROJECT_CARD_H

using std::string;

class Card {
protected:
    virtual int getCardsPerCoin(int coins) = 0;
    virtual string getName() = 0;
    virtual void print(std::ostream &out) = 0;
};

class Quartz : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out);
};

class Hematite : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out);
};

class Obsidian : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out);
};

class Malachite : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out);
};

class Turquoise : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out);
};

class Ruby : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out);
};

class Amethyst : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out);
};

class Emerald : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out);
};

#endif //CSI2372_PROJECT_CARD_H
