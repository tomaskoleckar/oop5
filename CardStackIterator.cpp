#include "CardStackIterator.h"

CardStackIterator::CardStackIterator(std::vector<Card*> data, int top)
{
	this->data = data;
	this->index = top;
}

bool CardStackIterator::hasNext()
{
	return index >= 0;
}

Card* CardStackIterator::Next()
{
	if (hasNext()) {
        return data[index--];
    } else {
        return nullptr;
    }
}
