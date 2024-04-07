#pragma once
#include <random>
#include "CardStackIterator.h"


class CardStack
{
public:
	CardStack(int size);
	static CardStack* createSevenToAceDeck();
	~CardStack();
	void Push(std::string number, std::string symbol);
	void Push(Card* card);
	Card* Pop();
	bool IsEmpty();
	void Shuffle();
	int getLen();
	CardStackIterator* GetIterator() { return new CardStackIterator(this->data, this->top); }

private:
	//DynamicArray* data;
	std::vector<Card*> data;
	int top;
};

