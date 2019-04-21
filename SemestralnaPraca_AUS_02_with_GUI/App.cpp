#include "App.h"

using namespace std;


App::App(structures::SortedSequenceTable<int, Kraj* > * kraje) :
	data(kraje)
{
}

App::~App()
{
}
