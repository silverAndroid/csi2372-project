//
// Created by silver_android on 21/11/16.
//

#include <string>
#ifndef CSI2372_PROJECT_CARD_H
#define CSI2372_PROJECT_CARD_H

using std::string;

class Card {
public:
    virtual int getCardsPerCoin(int coins) = 0;
    virtual string getName() = 0;
    virtual void print(std::ostream &out) const = 0;
    friend std::ostream& operator<<(std::ostream &, const Card &);
};

class Quartz : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out) const;
};

class Hematite : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out) const;
};

class Obsidian : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out) const;
};

class Malachite : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out) const;
};

class Turquoise : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out) const;
};

class Ruby : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out) const;
};

class Amethyst : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out) const;
};

class Emerald : public Card {
public:
    int getCardsPerCoin(int coins);
    string getName();
    void print(std::ostream &out) const;
};

#endif //CSI2372_PROJECT_CARD_H
