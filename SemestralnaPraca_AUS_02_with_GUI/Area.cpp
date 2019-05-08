#include "Area.h"


using namespace std;

Area::Area(std::string nazov) : nazov(nazov)
{
	arrayKol = new structures::Array<VolebneKolo*>(3);

	/// Aby sa index zhodoval s kolom, pre neskoršie h¾adanie, na 0 pozicií budú sumárne hodnoty za obidve kolá
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
	return false;
}

void Obec::makeUniqueNazov()
{
	std::string uniqueNazov = this->getName() + " - " + this->nazovOkresu;
	this->setName(uniqueNazov);
}
void Area::calculateSumValuesForBothRounds()
{
	// TODO overenie, èi sú tam hodnoty
	setPocetVydanychObalok(getPocetVydanychObalok(1) + getPocetVydanychObalok(2), 0);
	setPocetOdovzdanychObalok(getPocetOdovzdanychObalok(1) + getPocetOdovzdanychObalok(2), 0);
	setPocetPlatnychHlasov(getPocetPlatnychHlasov(1) + getPocetPlatnychHlasov(2), 0);
	setPocetVolicov(getPocetVolicov(1) + getPocetVolicov(2), 0);
	setUcastVolicov(getUcastVolicov(1) + getUcastVolicov(2), 0);
}