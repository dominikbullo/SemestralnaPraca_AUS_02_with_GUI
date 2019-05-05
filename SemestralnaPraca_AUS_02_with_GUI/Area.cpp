#include "Area.h"

using namespace std;

Area::Area(std::string nazov) : nazov(nazov)
{
	//cout << "Created Area named " << nazov << endl;
}

Area::~Area()
{
}

void Area::toString()
{
	cout << "This is a Area named " << nazov << endl;
}

bool Obec::isIn(Area& area)
{
	return false;
}

void Obec::makeUniqueNazov()
{
	std::string uniqueNazov = this->getName() + "_" + this->nazovOkresu;
	this->setName(uniqueNazov);
}

void Obec::makeUniqueVolici()
{
	//std::string uniqueNazov = this->getName() + "_" + this->nazovOkresu;
	//this->setName(uniqueNazov);
}

void Obec::makeUniqueUcast()
{
	/*std::string uniqueNazov = this->getName() + "_" + this->nazovOkresu;
	this->setName(uniqueNazov);*/
}
