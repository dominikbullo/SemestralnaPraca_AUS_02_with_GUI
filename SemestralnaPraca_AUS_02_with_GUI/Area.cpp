#include "Area.h"

using namespace std;

Area::Area(std::string nazov) : nazov(nazov)
{
	arrayKol = new structures::Array<VolebneKolo*>(3);

	arrayKol->operator[](0) = new VolebneKolo(0);  // tu budu sumárne hodnoty za obidve kola 
	arrayKol->operator[](1) = new VolebneKolo(1);
	arrayKol->operator[](2) = new VolebneKolo(2);
}

Area::~Area()
{
	for (size_t i = 0; i < arrayKol->size(); i++)
	{
		delete arrayKol->operator[](i);
	}
	delete arrayKol;
}

bool Obec::isIn(Area& area) const
{
	return this->nazovOkresu == area.getName() || this->nazovKraja == area.getName();
}

void Obec::makeUniqueNazov()
{
	std::string uniqueNazov = this->getName() + " - " + this->nazovOkresu;
	this->setName(uniqueNazov);
}

void Area::calculateSumValuesForBothRounds()
{
	int kolo = 0;
	setPocetVydanychObalok(getPocetVydanychObalok(1) + getPocetVydanychObalok(2), kolo);
	setPocetOdovzdanychObalok(getPocetOdovzdanychObalok(1) + getPocetOdovzdanychObalok(2), kolo);
	setPocetPlatnychHlasov(getPocetPlatnychHlasov(1) + getPocetPlatnychHlasov(2), kolo);
	setPocetVolicov(getPocetVolicov(1) + getPocetVolicov(2), kolo);
	setUcastVolicov(getUcastVolicov(1) + getUcastVolicov(2), kolo);
}