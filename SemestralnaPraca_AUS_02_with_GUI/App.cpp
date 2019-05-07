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
structures::ArrayList<Area*>* App::getAreas(std::string nazov)
{
	// FIXME
	//throw std::logic_error("Not finished yet");
	// TODO treba deštruktory
	structures::ArrayList<Area*>* matches = new structures::ArrayList<Area*>();
	KriteriumNazov * kriteriumMeno = new KriteriumNazov();
	FilterHasName * filter = new FilterHasName();

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
			matches->add(tempKraj);
		}
	}
	if (this->okresySorted->tryFind(nazov, tempOkres))
	{
		if (filter->evaluate(*tempOkres, *kriteriumMeno))
		{
			matches->add(tempOkres);
		}
	}
	if (this->obceSorted->tryFind(nazov, tempObec))
	{
		if (filter->evaluate(*tempObec, *kriteriumMeno))
		{
			matches->add(tempObec);
		}
	}
	delete kriteriumMeno;
	delete filter;

	return matches;
}

void App::test()
{
	//Obec * tmp = (*obce)[new Key("Žilinský kraj")];
}
