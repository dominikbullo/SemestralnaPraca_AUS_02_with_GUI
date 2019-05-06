#include "App.h"

using namespace std;

App::App(Nacitanie* loader) : loader(loader)
{
	krajeSorted = loader->getKraje();
	okresySorted = loader->getOkresy();
	obceSorted = loader->getObce();
}

App::~App()
{
}

Area* App::getArea(std::string nazov)
{
	// FIXME
	//throw std::logic_error("Not finished yet");

	KriteriumNazov * kriteriumMeno = new KriteriumNazov();
	FilterHasName * filter = new FilterHasName();

	//Kraj * tempKraj = nullptr;
	//Kraj * tempKraj = nullptr;
	//Kraj * tempKraj = nullptr;

	Kraj* tempKraj = nullptr;
	Okres* tempOkres = nullptr;
	Obec* tempObec = nullptr;

	filter->setAlpha(nazov);

	//bool test = filter->evaluate(*this->getVolebneKolo(volebneKolo)->getKraje()->operator[]("Žilinský kraj"), *kriteriumMeno);
	//auto found = this->krajeSorted->tryFind(nazov, tempKraj);
	//auto found = this->okresySorted->tryFind(nazov, tempOkres);
	//auto found = this->obceSorted->tryFind(nazov, tempObec);

	if (this->krajeSorted->tryFind(nazov, tempKraj))
	{
		if (filter->evaluate(*tempKraj, *kriteriumMeno))
		{
			return tempKraj;
		}
	}
	if (this->okresySorted->tryFind(nazov, tempOkres))
	{
		if (filter->evaluate(*tempOkres, *kriteriumMeno))
		{
			return tempOkres;
		}
	}
	if (this->obceSorted->tryFind(nazov, tempObec))
	{
		if (filter->evaluate(*tempObec, *kriteriumMeno))
		{
			return tempObec;
		}
	}
	return nullptr;
}

void App::test()
{
	//Obec * tmp = (*obce)[new Key("Žilinský kraj")];
}
