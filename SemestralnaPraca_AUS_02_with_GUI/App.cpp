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
	throw std::logic_error("Not finished yet");

	KriteriumNazov * kriteriumMeno = new KriteriumNazov();
	FilterHasName * filter = new FilterHasName();
	Area * tempArea = nullptr;

	// TODO for cez tabuľku -> údaje -> kraje atď, ako parametre sem!
	filter->setAlpha(nazov);

	//filter->setAlpha("Žilinský kraj");
	//bool test = filter->evaluate(*this->getVolebneKolo(volebneKolo)->getKraje()->operator[]("Žilinský kraj"), *kriteriumMeno);

	return tempArea;
}

void App::test()
{
	//Obec * tmp = (*obce)[new Key("Žilinský kraj")];
}
