#pragma once

#include "Card.h"
#include <vector>
class CardStackIterator
{
public:
	CardStackIterator(std::vector<Card*> data /*DynamicArray* array*/, int top);
	bool hasNext();
	Card* Next();

private:
	std::vector<Card*> data;
	//DynamicArray* array;
	int index;
};

