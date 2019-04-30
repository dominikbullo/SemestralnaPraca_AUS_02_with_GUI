#include "App.h"

using namespace std;

App::App(structures::Array<VolebneKolo*> *data)
{
	prveKolo = data->operator[](0);
	druheKolo = data->operator[](1);
}

App::~App()
{
}

std::string App::test()
{
	return std::to_string(prveKolo->getCisloKola()) + "teest";
}
void App::testFilter()
{
}