#include "Key.h"

//
//Key::Key(Area * area) :
//	nazov(area->getName()),
//	pocetVolicov(area->getPocetVolicov()),
//	ucast(area->getUcastVolicov())
//{
//}

Key::Key(std::string nazov) : nazov(nazov)
{

}

Key::Key(int pocetVolicov) : pocetVolicov(pocetVolicov)
{
}

Key::Key(float ucast) : ucast(ucast)
{
}
