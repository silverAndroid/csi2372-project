//
// Created by silver_android on 21/11/16.
//

#include <string>
#include <exception>
#include <stdexcept>

#ifndef CSI2372_PROJECT_CARD_H
#define CSI2372_PROJECT_CARD_H

using std::string;
using std::runtime_error;

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

class IllegalTypeException : public std::runtime_error {
private:
    string invalid;
    string proper;
public:
    IllegalTypeException(const string invalidType, const string properType);
    const char *what() const throw();
};

#endif //CSI2372_PROJECT_CARD_H
