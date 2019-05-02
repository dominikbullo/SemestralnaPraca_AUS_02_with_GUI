#include "Area.h"

using namespace std;

Area::Area(std::string nazov) : nazov(nazov)
{
	cout << "This is a Area named " << nazov << endl;
}

Area::~Area()
{
}


bool Obec::isIn(Area& area) const
{
	return false;
}

void Obec::makeUniqueNazov()
{
	std::string uniqueNazov = this->getName() + "_" + this->nazovOkresu;
	this->setName(uniqueNazov);
}
