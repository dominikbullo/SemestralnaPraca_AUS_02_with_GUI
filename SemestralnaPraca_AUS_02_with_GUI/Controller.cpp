#include "Controller.h"

using namespace std;


Controller::Controller(structures::SortedSequenceTable<int, Kraj* > * kraje) :
	data(kraje)
{
}

Controller::~Controller()
{
}
