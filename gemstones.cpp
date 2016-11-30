//
// Created by silver_android on 21/11/16.
//

#include <iostream>
#include "gemstones.h"


int Quartz::getCardsPerCoin(int coins) {
    if (coins < 4)
        return 0;
    else if (coins < 6)
        return 1;
    else if (coins < 8)
        return 2;
    else if (coins < 10)
        return 3;
    return 4;
}

string Quartz::getName() {
    return "Quartz";
}

void Quartz::print(std::ostream &out) const {
    out << string("Q");
}

int Hematite::getCardsPerCoin(int coins) {
    if (coins < 3)
        return 0;
    else if (coins < 6)
        return 1;
    else if (coins < 8)
        return 2;
    else if (coins < 9)
        return 3;
    return 4;
}

string Hematite::getName() {
    return "Hematite";
}

void Hematite::print(std::ostream &out) const {
    out << string("H");
}

int Obsidian::getCardsPerCoin(int coins) {
    if (coins < 3)
        return 0;
    else if (coins < 5)
        return 1;
    else if (coins < 7)
        return 2;
    else if (coins < 8)
        return 3;
    return 4;
}

string Obsidian::getName() {
    return "Obsidian";
}

void Obsidian::print(std::ostream &out) const {
    out << string("O");
}

int Malachite::getCardsPerCoin(int coins) {
    if (coins < 3)
        return 0;
    else if (coins < 5)
        return 1;
    else if (coins < 6)
        return 2;
    else if (coins < 7)
        return 3;
    return 4;
}

string Malachite::getName() {
    return "Malachite";
}

void Malachite::print(std::ostream &out) const {
    out << string("M");
}

int Turquoise::getCardsPerCoin(int coins) {
    if (coins < 2)
        return 0;
    else if (coins < 4)
        return 1;
    else if (coins < 6)
        return 2;
    else if (coins < 7)
        return 3;
    return 4;
}

string Turquoise::getName() {
    return "Turquoise";
}

void Turquoise::print(std::ostream &out) const {
    out << string("T");
}

int Ruby::getCardsPerCoin(int coins) {
    if (coins < 2)
        return 0;
    else if (coins < 4)
        return 1;
    else if (coins < 5)
        return 2;
    else if (coins < 6)
        return 3;
    return 4;
}

string Ruby::getName() {
    return "Ruby";
}

void Ruby::print(std::ostream &out) const {
    out << string("R");
}

int Amethyst::getCardsPerCoin(int coins) {
    if (coins < 2)
        return 0;
    else if (coins < 3)
        return 1;
    else if (coins < 4)
        return 2;
    else if (coins < 5)
        return 3;
    return 4;
}

string Amethyst::getName() {
    return "Amethyst";
}

void Amethyst::print(std::ostream &out) const {
    out << string("A");
}

int Emerald::getCardsPerCoin(int coins) {
    if (coins < 2)
        return 0;
    else if (coins < 3)
        return 2;
    return 3;
}

string Emerald::getName() {
    return "Emerald";
}

void Emerald::print(std::ostream &out) const {
    out << string("E");
}

std::ostream& operator<<(std::ostream &output, const Card &card) {
    card.print(output);
    return output;
}

IllegalTypeException::IllegalTypeException(const string invalidType, const string properType) {
    std::cout << "Invalid type: " << invalidType << ", should be " << properType;
}