#include "App.h"

using namespace std;

App::App(Nacitanie* loader) : loader(loader)
{
	krajeSorted = loader->getKraje();
	okresySorted = loader->getOkresy();
	obceSorted = loader->getObce();

	//obceUnsortedVolici1 = loader->getObceUnsortedVolici1();
	//obceUnsortedVolici2 = loader->getObceUnsortedVolici2();

	//obceUnsortedUcast1 = loader->getObceUnsortedUcast1();
	//obceUnsortedUcast2 = loader->getObceUnsortedUcast2();
}
App::~App()
{
}

structures::ArrayList<Area*>* App::getAreasNazov(std::string nazov)
{
	structures::ArrayList<Area*>* matches = new structures::ArrayList<Area*>();
	KriteriumNazov * kriterium = new KriteriumNazov();
	FilterHasName * filter = new FilterHasName();

	filter->setAlpha(nazov);

	Kraj* tempKraj;
	Okres* tempOkres;
	Obec* tempObec;

	if (this->krajeSorted->tryFind(nazov, tempKraj) && filter->evaluate(*tempKraj, *kriterium)) { matches->add(tempKraj); }
	if (this->okresySorted->tryFind(nazov, tempOkres) && filter->evaluate(*tempOkres, *kriterium)) { matches->add(tempOkres); }
	if (this->obceSorted->tryFind(nazov, tempObec) && filter->evaluate(*tempObec, *kriterium)) { matches->add(tempObec); }

	delete kriterium;
	delete filter;
	return matches;
}

structures::ArrayList<Area*>* App::getAreasVolici(int pocetOd, int pocetDo, int kolo)
{
	structures::ArrayList<Area*>* matches = new structures::ArrayList<Area*>();
	KriteriumVolici * kriterium = new KriteriumVolici(kolo);
	FilterVolici * filter = new FilterVolici();

	filter->setAlpha(pocetOd);
	filter->setBeta(pocetDo);

	for (auto area : *krajeSorted)
	{
		if (filter->evaluate(*area->accessData(), *kriterium))
		{
			matches->add(area->accessData());
		}
	}

	for (auto area : *okresySorted)
	{
		if (filter->evaluate(*area->accessData(), *kriterium))
		{
			matches->add(area->accessData());
		}
	}

	for (auto area : *obceSorted)
	{
		if (filter->evaluate(*area->accessData(), *kriterium))
		{
			matches->add(area->accessData());
		}
	}

	delete kriterium;
	delete filter;

	return matches;
}

structures::ArrayList<Area*>* App::getAreasUcast(double ucastOd, double ucastDo, int kolo)
{
	structures::ArrayList<Area*>* matches = new structures::ArrayList<Area*>();
	KriteriumUcast * kriterium = new KriteriumUcast(kolo);
	FilterUcast * filter = new FilterUcast();

	filter->setAlpha(ucastOd);
	filter->setBeta(ucastDo);

	for (auto area : *krajeSorted)
	{
		if (filter->evaluate(*area->accessData(), *kriterium))
		{
			matches->add(area->accessData());
		}
	}
	for (auto area : *okresySorted)
	{
		if (filter->evaluate(*area->accessData(), *kriterium))
		{
			matches->add(area->accessData());
		}
	}
	for (auto area : *obceSorted)
	{
		if (filter->evaluate(*area->accessData(), *kriterium))
		{
			matches->add(area->accessData());
		}
	}

	delete kriterium;
	delete filter;

	return matches;
}