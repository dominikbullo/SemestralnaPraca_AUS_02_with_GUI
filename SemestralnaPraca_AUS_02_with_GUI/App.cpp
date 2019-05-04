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

std::string App::test()
{
	throw std::exception("not finished yet!");
	prveKolo->test();
	return std::to_string(prveKolo->getCisloKola()) + "teest";
}
void App::testFilter()
{
}