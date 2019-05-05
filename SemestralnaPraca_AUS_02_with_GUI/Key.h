#pragma once
#include "Area.h"
class Key
{
public:
	Key(Area* area);
	Key(std::string nazov);
	Key(int pocetVolicov);
	Key(float ucast);

	void makeUniqueNazov();

private:
	std::string nazov = "";
	int pocetVolicov = -1;
	float ucast = -1;
};

