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
	throw std::exception("Not finished yet");

	CriterionName * kriteriumMeno = new CriterionName();
	FilterHasName * filter = new FilterHasName();
	Area * tempArea = nullptr;
	//filter->setAlpha("Žilinský kraj");

	// TODO for cez tabuľku -> údaje -> kraje atď, ako parametre sem!
	filter->setAlpha(nazov);
	bool test = filter->evaluate(*this->getVolebneKolo(volebneKolo)->getKraje()->operator[]("Žilinský kraj"), *kriteriumMeno);

	return tempArea;
}