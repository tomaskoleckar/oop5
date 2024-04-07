// StackMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CardStack.h"
#include "CardStackIterator.h"

int main()
{
    CardStack* deck = CardStack::createSevenToAceDeck();

    deck->Shuffle();

    CardStackIterator* iterator = deck->GetIterator();
    
    std::cout << deck->getLen() << std::endl;
    while (iterator->hasNext()) {
        Card* card = iterator->Next();
        if (card != nullptr) {
            std::cout << card->getNumber() << card->getSymbol() << "  ";
        }
    }
    std::cout << std::endl;
    
    delete deck;
    delete iterator;
}
