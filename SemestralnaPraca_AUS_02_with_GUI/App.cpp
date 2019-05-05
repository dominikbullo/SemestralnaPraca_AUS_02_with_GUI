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

Area* App::getArea(std::string nazov)
{
	CriterionName * kriteriumMeno = new CriterionName();
	//FilterHasName * filter = new FilterHasName();
	//filter->setAlpha(nazov);
	//filter->evaluate(nazov, *kriterium);
	return 0;
}