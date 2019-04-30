#include "Area.h"

using namespace std;

Area::Area(std::string nazov) : name_(nazov)
{
	cout << "This is a Area named " << nazov << endl;
}

Area::~Area()
{
}


bool Obec::isIn(Area& area) const
{
	return false;
}
