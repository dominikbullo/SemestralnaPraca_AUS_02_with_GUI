#include "Area.h"


using namespace std;

Area::Area(std::string nazov) : nazov(nazov)
{
	prveKolo = new VolebneKolo(1);
	druheKolo = new VolebneKolo(2);
	arrayKol = new structures::Array<VolebneKolo*>(3);

	arrayKol->operator[](0) = nullptr; //aby sa index zhodoval s kolo, pre neskoršie h¾adanie
	arrayKol->operator[](1) = prveKolo;
	arrayKol->operator[](2) = druheKolo;
}

Area::~Area()
{
	delete prveKolo;
	delete druheKolo;
	delete arrayKol;
}

void Area::toString()
{
	cout << "This is a Area named " << nazov << endl;
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
