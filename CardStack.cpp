#include "CardStack.h"
#include <random>
#include <iostream>

CardStack::CardStack(int size)
{
	this->top = 0;

	//Dynamick� pole
	//this->data = new DynamicArray(size);

	this->data.reserve(size);

	
	
}

CardStack* CardStack::createSevenToAceDeck()
{
    CardStack* deck = new CardStack(32);
    
    std::string numbers = "789XJQKA";
	//std::string symbols = "HDCS"; 
	std::string symbols = "\u2665\u2666\u2663\u2660"; 
	for (size_t i = 0; i < numbers.size()/3; ++i) {
		for (size_t j = 0; j < symbols.size(); ++j) {
			std::string numberStr(1, numbers[i]); 
			std::string symbolStr(1, symbols[j]); 
			deck->Push(numberStr, symbolStr);
		}
	}

    
    return deck;
}

CardStack::~CardStack()
{
	//Dynamick� pole
	//delete this->data;

	//vector
	for (int i = 0; i < this->data.size(); i++)
	{
		delete this->data[i];
	}
}

bool CardStack::IsEmpty()
{
	return this->top == 0;
}

void CardStack::Push(std::string number, std::string symbol)
{
	Card* card = new Card(number, symbol);

	//Vector
	this->Push(card);

	//Dynamicke pole
	//this->data->Add(card);
}

void CardStack::Push(Card* card)
{
	this->top++;

	//Vector
	this->data.push_back(card);

	//Dynamicke pole
	//this->data->Add(card);
}

Card* CardStack::Pop()
{
	this->top--;
	Card* card = this->data[this->top];

	//vector
	this->data.pop_back();

	//Dynamicke pole
	//this->data->RemoveAt(this->top);

	return card;
}

void CardStack::Shuffle()
{
	std::random_device rd;
    std::mt19937 gen(rd());
    

    for (int i = data.size() - 1; i > 0; --i) {
        std::uniform_int_distribution<int> dist(0, i);
        int j = dist(gen);
        std::swap(data[i], data[j]);
    }
}

int CardStack::getLen()
{
    return data.size();
}
