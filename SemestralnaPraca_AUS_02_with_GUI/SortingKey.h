#pragma once
#include "Area.h"
class SortingKey
{
public:
	SortingKey(Area* area);
private:
	const std::string nazov;
	const std::string nazovOkresu;
	const double value;
};

