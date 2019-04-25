#include "Area.h"

using namespace std;

Area::Area(std::string nazov)
{
	cout << "This is a Area named " << nazov << endl;
	this->name_ = nazov;
}

Area::~Area()
{
}