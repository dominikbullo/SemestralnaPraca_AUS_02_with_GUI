#pragma once
#include "Area.h"
class Key
{
public:
	Key(Area* area);
	Key(std::string nazov);
	Key(int pocetVolicov);
	Key(float ucast);

private:
	Area* area;
	const std::string nazov = "";
	const int pocetVolicov = -1;
	const float ucast = -1;
};

