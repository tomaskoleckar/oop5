#pragma once
#include <string>

class Card
{
public:
	Card(std::string number, std::string symbol);
	std::string getNumber() { return this->number; }
	std::string getSymbol() { return this->symbol; }
private:
	std::string number;
	std::string symbol;
};

