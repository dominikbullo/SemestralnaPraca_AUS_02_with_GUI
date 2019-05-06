#include "App.h"

using namespace std;

App::App(structures::Array<VolebneKolo*> *data) : data(data)
{
	prveKolo = data->operator[](0);
	druheKolo = data->operator[](1);
}

App::~App()
{
	delete prveKolo;
	delete druheKolo;
	delete data;
}

Area* App::getArea(std::string nazov, int volebneKolo)
{
	// FIXME
	throw std::logic_error("Not finished yet");

	KriteriumNazov * kriteriumMeno = new KriteriumNazov();
	FilterHasName * filter = new FilterHasName();
	Area * tempArea = nullptr;
	//filter->setAlpha("Žilinský kraj");

	// TODO for cez tabuľku -> údaje -> kraje atď, ako parametre sem!
	filter->setAlpha(nazov);
	bool test = filter->evaluate(*this->getVolebneKolo(volebneKolo)->getKraje()->operator[]("Žilinský kraj"), *kriteriumMeno);

	return tempArea;
}