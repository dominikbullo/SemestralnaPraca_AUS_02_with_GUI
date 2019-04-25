#include "App.h"

using namespace std;


App::App(structures::SortedSequenceTable<int, VolebneKolo* > * volebneKola) :
	data(volebneKola)
{
}

App::~App()
{
}

std::string App::test()
{
	Area* area = new Area("testArea");
	Kraj * kraj = new Kraj("test");
	std::string returnValue = "";
	returnValue += area->getName() + "\r\n" + kraj->getName();
	delete area;
	delete kraj;
	return returnValue;
}
void App::testFilter()
{
}